#include <iostream>
#include <fstream>
#include <string>
#include "Symbol.h"

using namespace std;

string coding(Symbol** symbols, string to_encode, int& coded_weight, int number_of_symbols)
{
	string coded;
	for (int i = 0; i < to_encode.length(); i++)
	{
		for (int j = 0; j < number_of_symbols; j++)
		{
			if (symbols[j]->value == to_encode[i])
			{
				coded = coded + symbols[j]->code + " ";
				coded_weight = coded_weight + symbols[j]->code.length();
			}
		}
	}
	return coded;
}

string decoding(Symbol** symbols, string coded)
{
	string decoded;
	string code;
	for (int i = 0; i < coded.length(); i++)
	{
		if ((coded[i]== ' ')||(i==coded.length()-1))
		{
			for (int j = 0; j < coded.length(); j++)
			{
				if (symbols[j]->code == code)
				{
					decoded = decoded + symbols[j]->value;
					code.clear();
					break;
				}
			}
		}
		else
			code = code + coded[i];
	}
	return decoded;
}