#include <iostream>
#include <fstream>
#include <string>
#include "Symbol.h"

using namespace std;

Symbol* BuildingTree(Symbol** symbols, int right)
{
	Symbol* new_parent = new Symbol;
	new_parent->frequancy = symbols[right - 1]->frequancy + symbols[right - 2]->frequancy;
	new_parent->code[0] = 0;
	new_parent->left_son = symbols[right - 1];
	new_parent->right_son = symbols[right - 2];
	if (right == 2)
	{
		return new_parent;
	}
	else
	{
		for (int i = 0; i<right; i++)
			if (new_parent->frequancy > symbols[i]->frequancy)
			{
				for (int j = right - 1; j > i; j--)
					symbols[j] = symbols[j - 1];
				symbols[i] = new_parent;
				break;
			}
	}
	return  BuildingTree(symbols, right-1);
}