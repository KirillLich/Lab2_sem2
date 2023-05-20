#include <iostream>
#include "based_struct\DynamicArray.h"
#include "based_struct\LinkedList.h"
#include "sequence_based\LinkedListSequence.h"
#include "sequence_based\ArraySequence.h"
#include "tests/DynamicArrayTests.h"
#include "tests/LinkedListTests.h"
#include "tests/LinkedListSequenceTest.h"
#include "tests/ArraySequenceTest.h"
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
	DynamicArrayTester testArray;
	LinkedListTester testList;
	LinkedListSequenceTester testListS;
	ArraySequenceTester testArrayS;

	int* array = new int[4];
	array[0] = 1;
	array[1] = 5;
	array[2] = 3;
	array[3] = 4;

	ArraySequence<int> listD(array, 4);
	delete[] array; 
	return 0;
}