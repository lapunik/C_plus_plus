#ifndef __QUEUE__
#define __QUEUE__

#include <iostream>

//	Queue (Fronta)
//
//		Popis:
//
//			Fronta je vytvoøena spojovým seznamem.
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
class Queue
{

	template<typename T>
	struct Item {

		T item;
		Item* next_item;

	};

	private:
			
		Item<T>* first_item;
		Item<T>* last_item;
		void AddFirstItem(T value);

	public:

		int size = 0;
		Queue();
		Queue(T firstItem);
		Queue(T* arr, int arr_size,bool invert);
		bool Enqueue(T value);
		T Peek();
		T Dequeue();
		bool Clear();
		int FindIndex(T value);
		T* ToArray();

};

#endif

template<typename T>
Queue<T>::Queue()
{
	size = 0;
}

template<typename T>
Queue<T>::Queue(T firstItem)
{
	AddFirstItem(firstItem);
	size = 1;
}

template<typename T>
Queue<T>::Queue(T * arr, int arr_size, bool invert)
{
	if (invert) 
	{
		for (int i = arr_size; i > 0; i--)
		{
			Enqueue(arr[i-1]);
		}
	}
	else
	{
		for (int i = 0; i < arr_size; i++)
		{
			Enqueue(arr[i]);
		}
	}
}

template<typename T>
bool Queue<T>::Enqueue(T value)
{
	if (size == 0)
	{
		AddFirstItem(value);
	}
	else
	{

		Item<T>* it = new Item<T>;
		it->item = value;
		it->next_item = NULL;

		first_item->next_item = it;
		first_item = it;

	}
	size++;
	return true;
}

template<typename T>
T Queue<T>::Peek()
{
	if (size < 1) 
	{
		//chyba
	}

	return last_item->item;
}

template<typename T>
T Queue<T>::Dequeue()
{
	if (size < 1)
	{
		//chyba
	}

	T it = last_item->item;

	last_item = last_item->next_item;

	size--;

	return it;
}

template<typename T>
bool Queue<T>::Clear()
{
	Item<T>* it = last_item; 
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
int Queue<T>::FindIndex(T value)
{
	Item<T>* it = last_item;

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
T* Queue<T>::ToArray()
{
	T* pole = new T[size];

	Item<T>* it = last_item;

	for (int i = 0; i < size; i++)
	{
		pole[i] = it->item;

		it = it->next_item;
	}

	return pole;
}

// private functions

template<typename T>
void Queue<T>::AddFirstItem(T value)
{

	first_item = new Item<T>;
	first_item->item = value;
	first_item->next_item = NULL;

	last_item = first_item;

}

