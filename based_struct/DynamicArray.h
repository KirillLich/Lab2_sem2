#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include <stdexcept>
#include <iostream>

template<class T>
class DynamicArray
{
	size_t lenght = 0;
	T* arr = nullptr;
	bool* flags = nullptr;

public:
	DynamicArray(T* items, size_t count)
	{
		arr = new T[count];
		flags = new bool[count];
		lenght = count;
		for (size_t i = 0; i < lenght; i++)
		{
			arr[i] = items[i];
			flags[i] = true;
		}
	};

	DynamicArray(size_t size) 
	{
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
		lenght = size;
		flags = new bool[size];
		for (size_t i = 0; i < size; i++)
		{
			flags[i] = false;
		}
	};

	~DynamicArray()
	{
		delete[] arr;
	};

	T Get(int index)
	{
		if (index < 0 || index >= lenght)
		{
			std::cerr << "Index is out of range. Index must be in [0, " << lenght << "] interval.\n";
			throw std::out_of_range("IndexOutOfRange");
		}
		if (!flags[index])
		{
			std::cerr << "There is no data by this index\n";
			throw std::out_of_range("IndexOutOfRange");
		}
		return arr[index];
	};
	
	size_t GetSize()
	{
		return lenght;
	};

	void Set(size_t index, T item)
	{
		if (index < 0 || index >= lenght)
		{
			std::cerr << "Index is out of range. Index must be in [0, " << lenght << "] interval.\n";
			throw std::out_of_range("IndexOutOfRange");
			return;
		}
		arr[index] = item;
		flags[index] = true;
	};

	void Resize(size_t NewSize)
	{
		T* newArr = new T[NewSize];
		bool* newFlags = new bool[NewSize];
		for (int i = 0; i < lenght && i < NewSize; i++)
		{
			newArr[i] = arr[i];
			newFlags[i] = flags[i];
		}
		if(NewSize>lenght)
		for (int i = 0; i < NewSize-lenght; i++)
		{
			newFlags[lenght + i] = false;
		}
		lenght = NewSize;
		delete[] arr;
		delete[] flags;
		arr = newArr;
		flags = newFlags;
	};
	
	DynamicArray(const DynamicArray<T>& oldArray)
	{
		oldArray.lenght;
		lenght = oldArray.lenght;
		arr = new T[lenght];
		flags = new bool[lenght];
		for (size_t i = 0; i < lenght; i++)
		{
			if (oldArray.flags[i])
			{
				arr[i] = oldArray.arr[i];
				flags[i] = true;
			}
		}
	};
};

#endif