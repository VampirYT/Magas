#include "header.h"

void Catalog(string& Language, string& name, magas& M, bool& first, order& O)
{
	system("cls");
	if (M.productsN.empty())
	{
		ifstream magaz("list.txt");
		string line;
		if (magaz.is_open())
		{
			while (getline(magaz, line))
			{
				size_t pos = line.find('=');
				size_t pos1 = line.find('=', pos + 1);
				if (pos != string::npos)
				{
					string productsname = line.substr(0, pos);
					M.productsN.push_back(productsname);
					string count = line.substr(pos + 1, pos1);
					int Count = stoi(count);
					M.productsC.push_back(Count);
					string price = line.substr(pos1 + 1);
					int Price = stoi(price);
					M.productsP.push_back(Price);
					if (Count <= 0)
					{
						M.productsA.push_back(false);
					}
					else if (Count >= 1)
					{
						M.productsA.push_back(true);
					}
					M.positionC++;
				}
			}
			magaz.close();
		}
		else
		{
			cout << "File open failed";
		}
	}

	if (!M.productsN.empty())
	{
		for (int i = 0; i < M.productsN.size(); i++)
		{
			cout << i + 1 << ".����� - " << M.productsN.at(i) << endl;
			cout << "ʳ������ - " << M.productsC.at(i) << endl;
			cout << "ֳ�� - " << M.productsP.at(i) << endl;
			cout << "�������� - ";
			if (M.productsA.at(i))
				cout << "���" << endl;
			else
				cout << " Hi" << endl;
			cout << "---------------------" << endl;
		}
	}
	while (true)
	{
		if (_kbhit())
		{
			int count = 0;
			char ch = _getch();
			int key = ch - '0';
			if (ch == VK_ESCAPE)
			{
				Menu(Language, name, M, first, O);
			}
			else if (key >= 1 && key <= M.positionC)
			{
				system("cls");
				int index = key - 1;
				if (M.productsA.at(index) == true)
				{
					cout << M.productsN.at(index) << endl;
					cout << "������ ������� ������: ";
					cin >> count;
					M.productsC.at(index) -= count;
					O.productsN.push_back(M.productsN.at(index));
					O.productsC.push_back(count);
					O.productsP.push_back(M.productsP.at(index));
					O.sum += (M.productsP.at(index) * count);
					cout << "�� �������� " << count << " " << M.productsN.at(index) << endl;
					cout << "�� " << (M.productsP.at(index) * count) << " ������� �� " << M.productsP.at(index) << " �� ���� �����" << endl;
					cout << "�������� ���� " << O.sum << " �������" << endl;
					Sleep(4000);
					ofstream List("list.txt");
					if (List.is_open())
					{
						for (int i = 0; i < M.positionC; i++)
						{
							List << M.productsN.at(i) << "=" << M.productsC.at(i) << "=" << M.productsP.at(i) << endl;
						}
					}
					ofstream Order((name + ".txt"));
					if (!Order.is_open())
					{
						cout << "File open failed";
					}
					else
					{
						Order << "���������� " << name << endl;
						for (int i = 0; i < O.productsC.size(); i++)
						{
							Order << O.productsN.at(i) << " = " << O.productsC.at(i) << "��" << " �� " << O.productsP.at(i) << " ������� ���� = " << (O.productsC.at(i) * O.productsP.at(i)) << " �������" << endl;
						}
						Order << "---------------------" << endl;
						Order << "�������� ���� - " << O.sum << " �������" << endl;
					}
				}
				else if (M.productsA.at(index) == false)
				{
					cout << M.productsN.at(index) << " ���� � ��������";
					Sleep(2000);
				}
				Catalog(Language, name, M, first, O);
			}
		}
	}
}