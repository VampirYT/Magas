#include "header.h"

void Menu(string& Language, string& name, magas& M, bool& first, order& O)
{
	system("cls");
	if (Language == "ua")
	{
		cout << "³���� " << name << endl;
		cout << "������ �����:" << endl;
		cout << "1.�������" << endl;
		cout << "2.������� ����" << endl;
		cout << "3.�����" << endl;
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
				Catalog(Language, name, M, first, O);
			}
			else if (ch == '2')
			{
				language(Language, name, M, first, O);
			}
			else if (ch == '3')
			{
				system("cls");
				exit(0);
			}
			else
				Menu(Language, name, M, first, O);
		}
	}
}