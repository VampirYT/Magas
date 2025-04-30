#include "header.h"

void language(string& Language, string& name, magas& M, bool& first, order& O)
{
	system("cls");
	Tab(10, 47);
	cout << "Choose a language ¬ибер≥ть мову" << endl;
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
					Menu(Language, name, M, first, O);
				}
				else if (first == true)
				{
					break;
				}
			}
			else if (ch == '2')
			{
				Language = "en";
				if (first == false)
				{
					Menu(Language, name, M, first, O);
				}
				else if (first == true)
				{
					break;
				}
			}
		}
	}

}