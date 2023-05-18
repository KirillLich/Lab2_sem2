#ifndef LINKED_LIST_SEQUENCE_TEST
#define LINKED_LIST_SEQUENCE_TEST
#include "../sequence_based/LinkedListSequence.h"
#include "LinkedListTests.h"

class LinkedListSequenceTester
{
	LinkedListTester* tester;
	int NumberOfTests = 3 + 5 + 5 + 2;
	int NumberOfPassedTests = 0;

	void TestConstructorLinkedListFromArray_1_5_3_4()
	{
		int* array = new int[4];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		LinkedListSequence<int> listD(array, 4);
		delete[] array;

		assert(listD.GetLenght() == 4);
		assert(listD.Get(0) == 1);
		assert(listD.Get(1) == 5);

		NumberOfPassedTests++;
	}
	void TestConstructorEmptyLinkedList()
	{
		LinkedListSequence<int> listD;
		assert(listD.GetLenght() == 0);
		try
		{
			listD.Get(2);
			assert(!"is not empty");
		}
		catch (std::exception& e)
		{
			std::string s = e.what();
			assert(s == "EmptyList");
		}

		NumberOfPassedTests++;
	}
	void TestCopyConstructorLinkedList_CopyOf_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		LinkedListSequence<int> listDCopy(listD);
		assert(listDCopy.GetLenght() == listD.GetLenght());
		for (size_t i = 0; i < 5; i++)
		{
			assert(listD.Get(i) == listDCopy.Get(i));
		}
		NumberOfPassedTests++;
	}
	void TestAllConstructorsLinkedList()
	{
		this->TestConstructorLinkedListFromArray_1_5_3_4();
		this->TestConstructorEmptyLinkedList();
		this->TestCopyConstructorLinkedList_CopyOf_1_5_6_3_9();
	}

	void TestGetByIndexLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		assert(listD.Get(0) == 1);
		assert(listD.Get(1) == 5);
		assert(listD.Get(2) == 6);
		assert(listD.Get(3) == 3);
		assert(listD.Get(4) == 9);

		NumberOfPassedTests++;
	}
	void TestGetSizeLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		assert(listD.GetLenght() == 5);

		NumberOfPassedTests++;
	}
	void TestGetFirstLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		assert(listD.GetFirst() == 1);
		NumberOfPassedTests++;
	}
	void TestGetLastLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		assert(listD.GetLast() == 9);
		NumberOfPassedTests++;
	}
	void TestGetSubList_1_5_6_3_9From_1To_3()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		Sequence<int>* listDSub = listD.GetSubSequence(1, 3);

		assert(listDSub->GetLenght() == 3);
		assert(listDSub->Get(0) == listD.Get(1));
		assert(listDSub->Get(1) == listD.Get(2));
		assert(listDSub->Get(2) == listD.Get(3));
		NumberOfPassedTests++;
	}
	void TestAllDecompositionsLinkedList()
	{
		this->TestGetByIndexLinkedList_1_5_6_3_9();
		this->TestGetSizeLinkedList_1_5_6_3_9();
		this->TestGetFirstLinkedList_1_5_6_3_9();
		this->TestGetLastLinkedList_1_5_6_3_9();
		this->TestGetSubList_1_5_6_3_9From_1To_3();
	}

	void TestAppendEmptyLinkedList()
	{
		LinkedListSequence<int> listD;
		listD.Append(10);

		assert(listD.Get(0) == 10);

		NumberOfPassedTests++;
	}
	void TestAppendLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		listD.Append(10);
		assert(listD.GetLenght() == 6);
		assert(listD.Get(5) == 10);

		NumberOfPassedTests++;
	}
	void TestPrependEmptyLinkedList()
	{
		LinkedListSequence<int> listD;
		listD.Prepend(10);

		assert(listD.Get(0) == 10);

		NumberOfPassedTests++;
	}
	void TestPrependLinkedList_1_5_6_3_9()
	{
		int* array = new int[5];
		array[0] = 1;
		array[1] = 5;
		array[2] = 6;
		array[3] = 3;
		array[4] = 9;

		LinkedListSequence<int> listD(array, 5);
		delete[] array;

		listD.Prepend(10);
		assert(listD.GetLenght() == 6);
		assert(listD.GetFirst() == 10);

		NumberOfPassedTests++;
	}
	void TestInsert_10LinkedList_1_2_3To2()
	{
		int* array = new int[3];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;

		LinkedListSequence<int> listD(array, 3);
		delete[] array;

		listD.InsertAt(10, 2);

		assert(listD.GetLenght() == 4);
		assert(listD.Get(0) == 1);
		assert(listD.Get(1) == 2);
		assert(listD.Get(2) == 10);
		assert(listD.Get(3) == 3);

		NumberOfPassedTests++;
	}
	void TestAllSetsInLinkedList()
	{
		this->TestAppendEmptyLinkedList();
		this->TestAppendLinkedList_1_5_6_3_9();
		this->TestPrependEmptyLinkedList();
		this->TestPrependLinkedList_1_5_6_3_9();
		this->TestInsert_10LinkedList_1_2_3To2();
	}

	void TestConcatLinkedList_1_2_3_AndEmpty()
	{
		int* array = new int[3];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;

		LinkedListSequence<int> listD(array, 3);
		delete[] array;

		LinkedListSequence<int> listDEmpty;
		Sequence<int>* listDConcat = listD.Concat(&listDEmpty);

		assert(listDConcat->GetLenght() == listD.GetLenght());
		assert(listDConcat->Get(0) == listD.Get(0));
		assert(listDConcat->Get(1) == listD.Get(1));
		assert(listDConcat->Get(2) == listD.Get(2));
		NumberOfPassedTests++;
	}
	void TestConcatLinkedList_1_2_3_And_4_5_6_7()
	{
		int* array = new int[3];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;

		LinkedListSequence<int> listD1(array, 3);
		delete[] array;

		array = new int[4];
		array[0] = 4;
		array[1] = 5;
		array[2] = 6;
		array[3] = 7;

		LinkedListSequence<int> listD2(array, 4);
		delete[] array;

		Sequence<int>* listDConcat = listD1.Concat(&listD2);

		assert(listDConcat->GetLenght() == 7);
		assert(listDConcat->Get(0) == 1);
		assert(listDConcat->Get(1) == 2);
		assert(listDConcat->Get(2) == 3);
		assert(listDConcat->Get(3) == 4);
		assert(listDConcat->Get(4) == 5);
		assert(listDConcat->Get(5) == 6);
		assert(listDConcat->Get(6) == 7);
		NumberOfPassedTests++;
	}
	void TestAllConcatLinkedList()
	{
		this->TestConcatLinkedList_1_2_3_AndEmpty();
		this->TestConcatLinkedList_1_2_3_And_4_5_6_7();
	}
	
public:
	LinkedListSequenceTester()
	{
		int n;
		tester = new LinkedListTester(n);
		NumberOfTests += n;
		NumberOfPassedTests += n;

		this->TestAllConstructorsLinkedList();
		this->TestAllDecompositionsLinkedList();
		this->TestAllSetsInLinkedList();
		this->TestAllConcatLinkedList();

		std::cout << "Linked List Sequence Tests passed!\n";
		assert(NumberOfPassedTests == NumberOfTests);
	}
};

#endif