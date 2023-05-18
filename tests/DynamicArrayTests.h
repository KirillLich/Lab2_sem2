#ifndef DYNAMIC_ARRAY_TESTS
#define DYNAMIC_ARRAY_TESTS
#include "../based_struct/DynamicArray.h"
#include <assert.h>
#include <iostream>

class DynamicArrayTester
{
	const int NumberOfTests = 11;
	int NumberOfPassedTests = 0;

	void TestConstructorDynamicArrayFromArray_1_5_3_4()
	{
		int* array = new int[4];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		DynamicArray<int> arrayD(array, 4);
		delete[] array;

		assert(arrayD.GetSize() == 4);
		assert(arrayD.Get(0) == 1);
		assert(arrayD.Get(1) == 5);

		NumberOfPassedTests++;
	}
	void TestConstructorEmptyDynamicArrayWithSize_10()
	{
		DynamicArray<int> arrayD(10);
		assert(arrayD.GetSize() == 10);
		try
		{
			arrayD.Get(2);
			assert(!"is not empty");
		}
		catch (std::exception& e)
		{
			std::string s = e.what();
			assert(s == "IndexOutOfRange");
		}

		NumberOfPassedTests++;
	}
	void TestCopyConstructorDynamicArray_CopyOf_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		DynamicArray<int> arrayD(array, 5);
		delete[] array;

		DynamicArray<int> arrayDCopy(arrayD);
		assert(arrayDCopy.GetSize() == arrayD.GetSize());
		for (size_t i = 0; i < 5; i++)
		{
			assert(arrayD.Get(i) == arrayDCopy.Get(i));
		}
		NumberOfPassedTests++;
	}
	void TestAllConstructorsDynamicArray()
	{
		this->TestConstructorDynamicArrayFromArray_1_5_3_4();
		this->TestConstructorEmptyDynamicArrayWithSize_10();
		this->TestCopyConstructorDynamicArray_CopyOf_1_5_6_3_9();
	}

	void TestGetByIndexDynamicArray_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		DynamicArray<int> arrayD(array, 5);
		delete[] array;

		assert(arrayD.Get(0) == 1);
		assert(arrayD.Get(1) == 5);
		assert(arrayD.Get(2) == 6);
		assert(arrayD.Get(3) == 3);
		assert(arrayD.Get(4) == 9);

		NumberOfPassedTests++;
	}
	void TestGetSizeDynamicArraySizeOf15()
	{
		DynamicArray<int> arrayD(15);

		assert(arrayD.GetSize() == 15);
		
		NumberOfPassedTests++;
	}
	void TestAllDecompositionsDynamicArray()
	{
		this->TestGetByIndexDynamicArray_1_5_6_3_9();
		this->TestGetSizeDynamicArraySizeOf15();
	}

	void TestSetInEmptyDynamicArray()
	{
		DynamicArray<int> arrayD(5);
		arrayD.Set(1, 10);

		assert(arrayD.Get(1) == 10);

		NumberOfPassedTests++;
	}
	void TestSetInDynamicArray_1_2_3()
	{
		int* array = new int[3];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;

		DynamicArray<int> arrayD(array, 5);
		delete[] array;

		arrayD.Set(1, 10);

		assert(arrayD.Get(1) == 10);

		NumberOfPassedTests++;
	}
	void TestAllSetsInDynamicArray()
	{
		this->TestSetInDynamicArray_1_2_3();
		this->TestSetInEmptyDynamicArray();
	}

	void TestResizeEmptyDynamicArraySizeFrom_5_To_23()
	{
		DynamicArray<int> arrayD(5);
		arrayD.Resize(23);

		assert(arrayD.GetSize() == 23);
		NumberOfPassedTests++;
	}
	void TestResizeEmptyDynamicArraySizeFrom_5_To_2()
	{
		DynamicArray<int> arrayD(5);
		arrayD.Resize(2);

		assert(arrayD.GetSize() == 2);

		NumberOfPassedTests++;
	}
	void TestAllResizeEmptyDynamicArray()
	{
		this->TestResizeEmptyDynamicArraySizeFrom_5_To_2();
		this->TestResizeEmptyDynamicArraySizeFrom_5_To_23();
	}
	void TestResizeDynamicArray_1_4_5_6_ToSize_7()
	{
		int* array = new int[4];
		array[0] = 1;
		array[1] = 4;
		array[2] = 5;
		array[3] = 6;

		DynamicArray<int> arrayD(array, 4);
		delete[] array;

		arrayD.Resize(7);
		assert(arrayD.Get(0) == 1);
		assert(arrayD.Get(1) == 4);
		assert(arrayD.Get(2) == 5);
		assert(arrayD.Get(3) == 6);

		for (size_t i = 4; i < 7; i++)
		{
			try
			{
				arrayD.Get(i);
				assert(!"is not empty");
			}
			catch (std::exception& e)
			{
				std::string s = e.what();
				assert(s == "IndexOutOfRange");
			}
		}

		NumberOfPassedTests++;
	}
	void TestResizeDynamicArray_1_4_5_6_ToSize_2()
	{
		int* array = new int[4];
		array[0] = 1;
		array[1] = 4;
		array[2] = 5;
		array[3] = 6;

		DynamicArray<int> arrayD(array, 4);
		delete[] array;

		arrayD.Resize(2);
		assert(arrayD.Get(0) == 1);
		assert(arrayD.Get(1) == 4);

		try
		{
			arrayD.Get(2);
			assert(!"is not empty");
		}
		catch (std::exception& e)
		{
			std::string s = e.what();
			assert(s == "IndexOutOfRange");
		}

		NumberOfPassedTests++;
	}
	void TestAllResizeNotEmptyDynamicArray()
	{
		this->TestResizeDynamicArray_1_4_5_6_ToSize_2();
		this->TestResizeDynamicArray_1_4_5_6_ToSize_7();
	}
	void TestAllResizeDynamicArray()
	{
		this->TestAllResizeEmptyDynamicArray();
		this->TestAllResizeNotEmptyDynamicArray();
	}

public:
	DynamicArrayTester()
	{
		std::cout << "Dynamic array tests started\n";
		this->TestAllConstructorsDynamicArray();
		std::cout << "Constructor tests passed\n";
		this->TestAllDecompositionsDynamicArray();
		std::cout << "Decomposition tests passed\n";
		this->TestAllResizeDynamicArray();
		std::cout << "Resize tests passsed\n";
		this->TestAllSetsInDynamicArray();
		std::cout << "Sets tests passed\n";

		assert(NumberOfPassedTests == NumberOfTests);

		std::cout << "Dynamic Array Tests passed!\tNumber of passed tests: " << NumberOfPassedTests << "\n";
	}
	DynamicArrayTester(int& PassedTests)
	{
		this->TestAllConstructorsDynamicArray();
		this->TestAllDecompositionsDynamicArray();
		this->TestAllResizeDynamicArray();
		this->TestAllSetsInDynamicArray();

		assert(NumberOfPassedTests == NumberOfTests);
		PassedTests = NumberOfPassedTests;
	}
};

#endif