#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <cstdlib>

using namespace std;

struct magas
{
	vector<string> productsN;
	vector<bool> productsA;
	vector<int> productsC;
	vector<int> productsP;
	int positionC=0;
};

struct order
{
	vector<string> productsN;
	vector<int> productsC;
	vector<int> productsP;
	int sum=0;
};

void Tab(int rows, int column);
void STab();
void Menu(string& Language, string& name, magas& M, bool& first,order& O);
void Catalog(string& Language, string& name, magas& M, bool& first, order& O);
void language(string& Language, string& name, magas& M, bool& first, order& O);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	magas M;
	order O;
	string name,Language = "ua";
	bool first = true;
	STab();
	language(Language,name,M,first,O);
	system("cls");
	if(Language == "ua")
	{
		cout << "Вітаємо у магазині \"Кекс-шоп\"";
		Sleep(2000);
		system("cls");
		Tab(0, 1);
		cout << "Введіть Ваше ім'я" << endl;
		cin >> name;
		system("cls");
		STab();
	}
	else if (Language == "en")
	{
		cout << "Вітаємо у магазині \"Кекс-шоп\"";
		Sleep(2000);
		system("cls");
		Tab(0, 1);
		cout << "Введіть Ваше ім'я" << endl;
		cin >> name;
		system("cls");
		STab();
	}
	first = false;
	Menu(Language,name,M,first,O);
}

void Menu(string& Language, string& name, magas& M, bool& first, order& O)
{
	system("cls");
	if(Language == "ua")
	{
		cout << "Вітаємо " << name << endl;
		cout << "Оберіть опцію:" << endl;
		cout << "1.Каталог" << endl;
		cout << "2.Вибрати мову" << endl;
		cout << "3.Вийти" << endl;
	}
	else if (Language == "en")
	{

	}
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == '1')
			{
				Catalog(Language, name, M, first,O);
			}
			else if (ch == '2')
			{
				language(Language, name, M, first,O);
			}
			else if (ch == '3')
			{
				system("cls");
				exit(0);
			}
			else
				Menu(Language, name, M, first,O);
		}
	}
}

void Catalog(string& Language, string& name, magas& M, bool& first, order& O)
{
	system("cls");
	if(M.productsN.empty())
	{
		ifstream magaz("list.txt");
		string line;
		if (magaz.is_open())
		{
			while (getline(magaz, line))
			{
				size_t pos = line.find('=');
				size_t pos1 = line.find('=',pos+1);
				if (pos != string::npos)
				{
					string productsname = line.substr(0, pos);
					M.productsN.push_back(productsname);
					string count = line.substr(pos + 1,pos1);
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
			cout << i+1 << ".Товар - " << M.productsN.at(i) << endl;
			cout << "Кількість - " << M.productsC.at(i) << endl;
			cout << "Ціна - " << M.productsP.at(i) << endl;
			cout << "Наявність - ";
			if (M.productsA.at(i))
				cout << "Так" << endl;
			else
				cout << " Hi" << endl;
			cout << "---------------------" << endl;
		}
	}
	while (true)
	{
		if (_kbhit())
		{
			int count=0;
			char ch = _getch();
			int key = ch - '0'; 
			if (ch == VK_ESCAPE)
			{
				Menu(Language, name, M, first,O);
			}
			else if (key >= 1 && key <= M.positionC)
			{
				system("cls");
				int index = key - 1; 
				if(M.productsA.at(index) == true)
				{
					cout << M.productsN.at(index) << endl;
					cout << "Введіть кількість товару: ";
					cin >> count;
					M.productsC.at(index) -= count;
					O.productsN.push_back(M.productsN.at(index));
					O.productsC.push_back(count);
					O.productsP.push_back(M.productsP.at(index));
					O.sum += (M.productsP.at(index) * count);
					cout << "Ви замовили " << count << " " << M.productsN.at(index) << endl;
					cout << "На " << (M.productsP.at(index) * count) << " гривень по " << M.productsP.at(index) << " за одну штуку" << endl;
					cout << "Загальна сума " << O.sum << " гривень" << endl;
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
						Order << "Замовлення " << name << endl;
						for (int i = 0; i < O.productsC.size(); i++)
						{
							Order << O.productsN.at(i) << " = " << O.productsC.at(i) << "шт" << " по " << O.productsP.at(i) << " гривень сума = " << (O.productsC.at(i) * O.productsP.at(i)) << " гривень" << endl;
						}
						Order << "---------------------" << endl;
						Order << "Загальна сума - " << O.sum << " гривень" << endl;
					}
				}
				else if (M.productsA.at(index) == false)
				{
					cout << M.productsN.at(index) << " немає в наявності";
					Sleep(2000);
				}
				Catalog(Language, name, M, first,O);
			}
		}
	}
}

void language(string& Language, string& name, magas& M, bool& first, order& O)
{
	system("cls");
	Tab(10, 47);
	cout << "Choose a language Виберіть мову" << endl;
	Tab(1, 47);
	cout << "Press \"1\" to UA";
	Tab(1, 47);
	cout << "Press \"2\" to EN";
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == '1')
			{
				Language = "ua";
				if (first == false)
				{
					Menu(Language, name, M, first,O);
				}
				else if(first == true)
				{
					break;
				}
			}
			else if (ch == '2')
			{
				Language = "en";
				if (first == false)
				{
					Menu(Language, name, M, first,O);
				}
				else if(first == true)
				{
					break;
				}
			}
		}
	}
	
}

void Tab(int rows, int column)
{
	for (int i = 0; i <= rows; i++)
	{
		if (i < rows)
			cout << " " << endl;
		if (i == rows)
			cout << " ";
	}
	for (int j = 0; j <= column; j++)
	{
		cout << " ";
	}
}

void STab()
{
	for (int i = 0; i <= 10; i++)
	{
		cout << " " << endl;
	}
	for (int j = 0; j <= 40; j++)
	{
		cout << " ";
	}
}