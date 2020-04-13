#pragma once
void QuickSort(Symbol* array[], int left, int right);

Symbol* BuildingTree(Symbol** symbols, int right);

void MakingCodes(Symbol* current);

void output(Symbol** symbols, std::string to_encode, int number_of_symbols);

