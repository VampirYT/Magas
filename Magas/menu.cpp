#include "header.h"

void Menu(string& Language, string& name, magas& M, bool& first, order& O)
{
	system("cls");
	if (Language == "ua")
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