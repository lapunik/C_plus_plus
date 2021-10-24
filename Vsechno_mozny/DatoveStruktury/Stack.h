#ifndef __STACK__
#define __STACK__

#include <iostream>

//	Stack (Zásobník)
//
//		Popis:
//
//			Zásobník je vytvoøen spojovým seznamem.
//
//		Èasová nároènost:
//
//			Najdi prvek:							O(n)
//			Pøidej prvek:							O(1) 
//			Odeber prvek:							O(1)
//			Zjisti vrchol							O(1)
//			Vyprázdni frontu:						O(n)
//

template<typename T>
class Stack
{

	template<typename T> 
	struct Item {

		T item;
		Item* next_item;

	};

private:

	Item<T>* first_item;
	void AddFirstItem(T value);

public:

	int size = 0;
	Stack();
	Stack(T firstItem);
	Stack(T* arr, int arr_size, bool invert);
	bool Push(T value);
	T Peek();
	T Pop();
	bool Clear();
	int FindIndex(T value);
	T* ToArray();

};

#endif

template<typename T>
Stack<T>::Stack()
{
	size = 0;
}

template<typename T>
Stack<T>::Stack(T firstItem)
{
	AddFirstItem(firstItem);
	size = 1;
}

template<typename T>
Stack<T>::Stack(T * arr, int arr_size, bool invert)
{
	if (invert)
	{
		for (int i = arr_size; i > 0; i--)
		{
			Push(arr[i - 1]);
		}
	}
	else
	{
		for (int i = 0; i < arr_size; i++)
		{
			Push(arr[i]);
		}
	}
}

template<typename T>
bool Stack<T>::Push(T value)
{
	if (size == 0)
	{
		AddFirstItem(value);
	}
	else
	{

		Item<T>* it = new Item<T>;
		it->item = value;
		it->next_item = first_item;

		first_item = it;
	}
	size++;
	return true;
}

template<typename T>
T Stack<T>::Peek()
{
	if (size < 1)
	{
		//chyba
	}

	return first_item->item;
}

template<typename T>
T Stack<T>::Pop()
{
	if (size < 1)
	{
		//chyba
	}

	T it = first_item->item;

	first_item = first_item->next_item;

	size--;

	return it;
}

template<typename T>
bool Stack<T>::Clear()
{
	Item<T>* it = first_item;
	Item<T>* it2;

	for (int i = 0; i < size - 1; i++)
	{
		it2 = it->next_item;

		delete it;
		it = NULL;

		it = it2;
	}

	delete it;
	it = NULL;

	size = 0;

	return true;
}

template<typename T>
int Stack<T>::FindIndex(T value)
{
	Item<T>* it = first_item;

	for (int i = 0; i < size; i++)
	{
		if (it->item == value)
		{
			return i;
		}

		it = it->next_item;
	}

	return -1;
}

template<typename T>
T* Stack<T>::ToArray()
{
	T* pole = new T[size];

	Item<T>* it = first_item;

	for (int i = 0; i < size; i++)
	{
		pole[i] = it->item;

		it = it->next_item;
	}

	return pole;
}

// private functions

template<typename T>
void Stack<T>::AddFirstItem(T value)
{

	first_item = new Item<T>;
	first_item->item = value;
	first_item->next_item = NULL;

}

