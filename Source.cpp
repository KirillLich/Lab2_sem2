#include <iostream>
#include "based_struct\DynamicArray.h"
#include "based_struct\LinkedList.h"
#include "sequence_based/LinkedListSequence.h"
#include "sequence_based/ArraySequence.h"
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
	/*DynamicArray<int> arr(5);
	for (size_t i = 0; i < 5; i++)
	{
		arr.Set(i, i);
	}
	for (size_t i = 0; i < 5; i++)
	{
		try { std::cout << arr.Get(i); }
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
			std::cout << "Type: " << typeid(e).name() << std::endl;
		}
	}
	arr.Resize(6); 
	for (size_t i = 0; i < 6; i++)
	{
		try { std::cout << arr.Get(i); }
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
			std::cout << "Type: " << typeid(e).name() << std::endl;
		}
	}
	return 0;*/
	int arr[3] = { 1,2,3 };
	ArraySequence<int> arrS(arr, 3);
	arrS.Append(3);
	arrS.Prepend(-1);
	arrS.InsertAt(10, 1);
	printArr(arrS);
	return 0;
}