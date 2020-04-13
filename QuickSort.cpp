#include <iostream>
#include <fstream>
#include <string>
#include "Symbol.h"

using namespace std;
void QuickSort(Symbol* array[], int left, int right)
{
	Symbol* point = array[left];
	int left_end = left;
	int right_end = right;
	while (left < right)
	{
		while ((array[right]->frequancy <= point->frequancy) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			array[left] = array[right];
			left++;
		}
		while ((array[left]->frequancy >= point->frequancy) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			array[right] = array[left];
			right--;
		}
	}
	array[left] = point;
	int Point = left;
	left = left_end;
	right = right_end;
	if (left < Point) { QuickSort(array, left, Point - 1); }
	if (right > Point) { QuickSort(array, Point + 1, right); }
}