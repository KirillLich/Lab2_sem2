#include <iostream>
#include "based_struct\DynamicArray.h"
#include "based_struct\LinkedList.h"
#include "sequence_based\LinkedListSequence.h"
#include "sequence_based\ArraySequence.h"
#include "tests/DynamicArrayTests.h"
#include <exception>
#include <typeinfo>
#include <iostream>
//using namespace std;

void printArr(ArraySequence<int> arr)
{
	for (size_t i = 0; i < arr.GetLenght(); i++)
	{
		std::cout << arr.Get(i) << " ";
	}
}

int main()
{
	DynamicArrayTester test;
	return 0;
}