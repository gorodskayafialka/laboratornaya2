#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
#include "pch.h"
#include "CppUnitTest.h"
#include "../Symbol.h"
#include "../QuickSort.cpp"
#include "../Coding+Decoding.cpp"
#include "../BuildingTree.cpp"
#include "../MakingCodes.cpp"
#include "../Output.cpp"
#include "../Process.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Codingtests
{
	TEST_CLASS(Codingtests)
	{
	public:

		TEST_METHOD(Test1)
		{
			string to_encode = "test";
			Symbol** symbols = new Symbol * [to_encode.size()];
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
			Symbol** Symbols = new Symbol * [unique_symbols];
			QuickSort(symbols, 0, unique_symbols - 1);
			for (int i = 0; i < unique_symbols; i++)
			{
				Symbols[i] = symbols[i];
			}
			Symbol* root = BuildingTree(symbols, unique_symbols);
			MakingCodes(root);
			int coded_weight = 0;
			string code = coding(Symbols, to_encode, coded_weight, unique_symbols);
			string decoded = decoding(Symbols, code);
			string code_ = "1 01 00 1 ";
			Assert::AreEqual(to_encode, decoded);
			Assert::AreEqual(Symbols[0]->value, 't');
			Assert::AreEqual(Symbols[0]->frequancy, 2);
			Assert::AreEqual(Symbols[1]->value, 'e');
			Assert::AreEqual(Symbols[1]->frequancy, 1);
			Assert::AreEqual(Symbols[2]->value, 's');
			Assert::AreEqual(Symbols[2]->frequancy, 1);
			Assert::AreEqual(code, code_);
		}

	TEST_METHOD(Test2)
	{
		try 
		{ 
			process(); 
		}
		catch (std::exception e)
		{
			Assert::AreEqual("trouble with file", e.what());
		}
	}
};
};


