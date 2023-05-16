#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdexcept>
#include <iostream>

template<class T>
class LinkedList
{
	typedef struct Node
	{
		Node* next, * previous;
		T item;
	}node;

	node* first, * last;
	size_t lenght;

public:
	LinkedList(T* items, int count)
	{
		if (count <= 0)
		{
			std::cerr << "Invalid count: count must be > 0\n";
			throw std::invalid_argument("InvalidCount");
		}
		node* ptr = new node;
		first = ptr;
		ptr->item = items[0];
		ptr->previous = nullptr;
		for (size_t i = 1; i < count; i++)
		{
			ptr->next = new node;
			ptr->next->previous = ptr;
			ptr = ptr->next;
			ptr->item = items[i];
		}
		ptr->next = nullptr;
		last = ptr;
		lenght = count;
	}
	LinkedList()
	{
		first = nullptr;
		last = nullptr;
		lenght = 0;
	}
	LinkedList(const LinkedList<T>& list)
	{
		lenght = list.lenght; 
		node* ptr = list.first;
		node* ConstructPtr = new node;
		first = ConstructPtr;
		ConstructPtr->item = ptr->item;
		ptr = ptr->next;
		ConstructPtr->previous = nullptr;
		for (size_t i = 1; i < lenght; i++)
		{
			ConstructPtr->next = new node;
			ConstructPtr->next->previous = ConstructPtr;
			ConstructPtr = ConstructPtr->next;
			ConstructPtr->item = ptr->item;
			ptr = ptr->next;
		}
		ConstructPtr->next = nullptr;
		last = ConstructPtr;
	}

	~LinkedList()
	{
		if(first!=nullptr)
		{
			node* tail = last;
			node* previousTail = tail->previous;
			while (tail != nullptr)
			{
				previousTail = tail->previous;
				delete tail;
				tail = previousTail;
			}
			first = nullptr;
			last = nullptr;
		}
	}

	size_t GetLenght()
	{
		return lenght;
	}
	T GetFirst()
	{
		return first->item;
	}
	T GetLast()
	{
		return last->item;
	}
	T Get(int index)
	{
		if (index<0)
		{
			std::cerr << "Invalid index: index out of range\n";
			throw std::out_of_range("IndexOutOfRange");
		}
		if (first == nullptr)
		{
			std::cerr << "Invalid list: list is empty\n";
			throw std::length_error("EmptyList");
		}
		node* ptr = first;
		for (size_t i = 0; i < index; i++)
		{
			ptr = ptr->next;
			if (ptr == nullptr)
			{
				std::cerr << "Invalid index: index out of range\n";
				throw std::out_of_range("IndexOutOfRange");
			}
		}
		return ptr->item;
	}
	LinkedList<T> GetSubList(int startIndex, int endIndex)
	{
		if(startIndex<0||startIndex>lenght||endIndex<0||endIndex>lenght)
		{
			std::cerr << "Invalid index: index out of range\n";
			throw std::out_of_range("IndexOutOfRange");
		}
		T* itemsArray = new T[endIndex - startIndex + 1];
		
		node* ptr = first;
		for (size_t i = 0; i < startIndex; i++)
		{
			ptr = ptr->next;
		}
		for (size_t i = startIndex; i <= endIndex; i++)
		{
			itemsArray[i - startIndex] = ptr->item;
			ptr = ptr->next;
		}
		LinkedList listOut(itemsArray, endIndex - startIndex + 1);
		delete[] itemsArray;
		return listOut;
	}

	void Append(T Item)
	{
		node* ptr = new node;
		ptr->item = Item;
		ptr->previous = last;
		ptr->next = nullptr;
		last->next = ptr;
		last = ptr;
		lenght++;
	}
	void Prepend(T Item)
	{
		node* ptr = new node;
		ptr->item = Item;
		ptr->previous = nullptr;
		ptr->next = first;
		first->previous = ptr;
		first = ptr;
		lenght++;
	}
	void InsertAt(T Item, int Index)
	{
		if (Index < 0 || lenght <= Index)
		{
			std::cerr << "Invalid index: index out of range\n";
			throw std::out_of_range("IndexOutOfRange");
		}
		if (Index == 0)this->Prepend(Item);
		else if (Index == lenght - 1)this->Append(Item);
		else
		{
			node* ptr = first;
			for (size_t i = 0; i < Index; i++)
			{
				ptr = ptr->next;
			}
			node* insertionNode = new node;
			insertionNode->item = Item;
			insertionNode->next = ptr;
			insertionNode->previous = ptr->previous;
			ptr->previous->next = insertionNode;
			ptr->previous = insertionNode;
		}
		lenght++;
	}
	LinkedList<T> Concat(const LinkedList<T> secondList)
	{
		LinkedList<T> listOut(*this),listHelp(secondList);
		listOut.last->next = listHelp.first;
		listHelp.first->previous = listOut.last;
		listOut.last = listHelp.last;
		listHelp.first = nullptr;
		listHelp.last = nullptr;
		listOut.lenght += listHelp.lenght;
		return listOut;
	}
};
#endif