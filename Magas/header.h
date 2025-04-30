#pragma once

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
	int positionC = 0;
};

struct order
{
	vector<string> productsN;
	vector<int> productsC;
	vector<int> productsP;
	int sum = 0;
};

void Tab(int rows, int column);
void STab();
void Menu(string& Language, string& name, magas& M, bool& first, order& O);
void Catalog(string& Language, string& name, magas& M, bool& first, order& O);
void language(string& Language, string& name, magas& M, bool& first, order& O);