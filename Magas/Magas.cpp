#include "header.h"

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
		cout << "³���� � ������� \"����-���\"";
		Sleep(2000);
		system("cls");
		Tab(0, 1);
		cout << "������ ���� ��'�" << endl;
		cin >> name;
		system("cls");
		STab();
	}
	else if (Language == "en")
	{
		cout << "Welcome to the \"����-���\"";
		Sleep(2000);
		system("cls");
		Tab(0, 1);
		cout << "Enter firstname" << endl;
		cin >> name;
		system("cls");
		STab();
	}
	first = false;
	Menu(Language,name,M,first,O);
}