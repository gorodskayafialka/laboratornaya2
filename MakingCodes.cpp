#include <iostream>
#include <fstream>
#include <string>
#include "Symbol.h"

using namespace std;

void MakingCodes(Symbol* current) 
{
	if (current->left_son != nullptr)
	{
		current->left_son->code = current->code + "0";
		MakingCodes(current->left_son);
	}
	if (current->right_son != nullptr)
	{
		current->right_son->code = current->code + "1";
		MakingCodes(current->right_son);
	}
}