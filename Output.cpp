#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
#include "Symbol.h"
#include "Coding+Decoding.h"

using namespace std;

void output(Symbol** symbols, string to_encode, int number_of_symbols)
{
	float decoded_weight = to_encode.length()*8;
	int coded_weight = 0;
	int k = 0;
	string coded = coding(symbols, to_encode, coded_weight, number_of_symbols);
	cout << "Given string: " << to_encode;
	cout << endl << "Encoded string: " << coded;
	cout << endl << "Decoded string: " << decoding(symbols, coded);
	cout << endl << "The weight of decoded string: " << decoded_weight << " bits" << endl << "The weight of encoded string: " << coded_weight << " bits" << endl << "Compression ratio: " << decoded_weight / coded_weight;
	cout << endl << "The table of frequances and codes: ";
	cout << endl << setw(7) << left << "Symbol" << setw(10) << left << "Frequancy" << "Code";
	for (int i = 0; i < number_of_symbols; i++)
	{
		if (symbols[i]->value!= ' ') cout << endl << setw(7) << left << symbols[i]->value;
		else cout << endl << setw(7) << left << "' '";
		cout << setw(10) << left << symbols[i]->frequancy << symbols[i]->code;
	}
}