#include "header.h"

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