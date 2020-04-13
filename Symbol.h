#pragma once
#include <string.h>
class Symbol
{
public:
	char value;
	int frequancy;
	std::string code;
	Symbol* left_son;
	Symbol* right_son;
	Symbol(char value = 0, Symbol* left_son = nullptr, Symbol* right_son = nullptr)
	{
		this->value = value;
		this->frequancy = 1;
		this->left_son = left_son;
		this->right_son = right_son;
	}
};
