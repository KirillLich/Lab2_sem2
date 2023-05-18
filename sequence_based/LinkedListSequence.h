#ifndef LINKED_LIST_SEQUENCE
#define LINKED_LIST_SEQUENCE
#include "..\based_struct\Sequence.h"
#include "..\based_struct\LinkedList.h"

template<class T>
class LinkedListSequence :public Sequence<T>
{
	LinkedList<T>* list;
public:
	LinkedListSequence(T* Items, int count)
	{
		this->SetName("LinkedList");
		list = new LinkedList<T>(Items, count);
	}
	LinkedListSequence()
	{
		this->SetName("LinkedList");
		list = nullptr;
	}
	LinkedListSequence(const LinkedListSequence<T>& List)
	{
		this->SetName("LinkedList");
		list = new LinkedList<T>(*List.list);
	}
	~LinkedListSequence()
	{
		delete[] list;
	}

	T Get(int Index)
	{
		return list->Get(Index);
	}
	T GetFirst()
	{
		return list->GetFirst();
	}
	T GetLast()
	{
		return list->GetLast();
	}
	Sequence<T>* GetSubSequence(int startIndex, int endIndex)
	{
		LinkedListSequence<T>* listS = new LinkedListSequence<T>;
		listS->list = new LinkedList<T>;
		*(listS->list) = this->list->GetSubList(startIndex, endIndex);
		return listS;
	}
	size_t GetLenght()
	{
		return list->GetLenght();
	}

	void Append(T Item)
	{
		list->Append(Item);
	}
	void Prepend(T Item)
	{
		list->Prepend(Item);
	}
	void InsertAt(T Item, int Index)
	{
		list->InsertAt(Item, Index);
	}
	Sequence<T>* Concat(LinkedListSequence<T>* List)
	{
		LinkedListSequence<T>* listS = new LinkedListSequence<T>;
		listS->list = this->list->Concat(List->list);
		return listS;
	}
};

#endif 