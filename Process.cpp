#include <iostream>
#include <fstream>
#include <string>
#include "Symbol.h"
#include "QuickSort.h"

using namespace std;
Symbol** process()
{
	fstream f;
	f.open("problem1.txt", ios::in);
	if (f.bad() != 0)
	{
		try
		{

			throw exception("trouble with file");
		}
		catch (const exception & err)
		{
			cout << "Experiencing trouble with opening the 'reading' file";
			return(nullptr);
		}
	}
	string to_encode;
	getline(f, to_encode);
	f.close();
	Symbol** symbols = new Symbol*[to_encode.size()];
	int unique_symbols = 0;
	for (int i = 0; i < to_encode.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < unique_symbols; j++)
		{
			if (to_encode[i] == symbols[j]->value)
			{
				symbols[j]->frequancy++;
				found = true;
			}
		}
		if (!found)
		{
			symbols[unique_symbols] = new Symbol(to_encode[i]);
			unique_symbols++;
		}
	}
	Symbol** Symbols = new Symbol*[unique_symbols];
	QuickSort(symbols, 0, unique_symbols - 1);
	for (int i = 0; i < unique_symbols; i++)
	{
		Symbols[i] = symbols[i];
	}
	Symbol* root = BuildingTree(symbols, unique_symbols);
	MakingCodes(root);
	output(Symbols, to_encode, unique_symbols);
	return (Symbols);
}