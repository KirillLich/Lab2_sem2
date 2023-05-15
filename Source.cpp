#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include <exception>
#include <typeinfo>
#include <iostream>
//using namespace std;

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
	LinkedList<int> list(arr, 3);
	LinkedList<int>doubledList = list.Concat(list);
	/*list.Append(5);
	list.Prepend(-1);
	list.InsertAt(10, 2);*/
	return 0;
}