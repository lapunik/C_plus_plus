#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>

//	Linked list (Spojový seznam)
//
//		Popis:
//
//			Spojový seznam nealokuje pole o urèité velikosti, nýbrž jednotlivé prvky v seznamu pøidává
//			spoleènì s ukazatelem na následující a pøedchozí prvek v seznamu.	 
//
//		Èasová nároènost:
//
//			Najdi prvek:							O(n)
//			Pøidej prvek na zaèátek èi na konec:	O(1) 
//			Pøidej prvek kamkoliv					O(n)
//			Smaž prvek na zaèáteku nebo na koneci:	O(1)
//			Smaž prvek kdekoliv:					O(n)
//			Uprav prvek na indexu:					O(n)

template<typename T>
class LinkedList
{
	template<typename T>
	struct Item {

		T item;
		Item* previous_item;
		Item* next_item;

	};

	private:
	
		Item<T>* first_item;
		Item<T>* last_item;
		Item<T>* NextItem(Item<T>* I);
		Item<T>* PreviousItem(Item<T>* I);
		Item<T>* ReturnItem(int index);
		void AddFirstItem(T value);		

	public:

		int size = 0;
		LinkedList();
		LinkedList(T firstItem);
		LinkedList(T* arr, int arr_size);
		bool Add(T value);
		bool Insert(T value);  
		bool Insert(int index,T value);
		T ReturnAt(int index);
		bool RemoveAt(int index);
		bool Clear();
		bool EditAt(int index, T new_value);
	    int FindIndex(T value);
		T* ToArray();

};

template<typename T>
LinkedList<T>::LinkedList()
{
	size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T firstItem)
{
	AddFirstItem(firstItem);
	size++;
}

template<typename T>
LinkedList<T>::LinkedList(T* arr,int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		Add(arr[i]);
	}
}

template<typename T>
bool LinkedList<T>::Add(T value)
{
	if (size == 0) 
	{
		AddFirstItem(value);
	}
	else
	{
		last_item->next_item = new Item<T>;
		last_item->next_item->item = value;
		last_item->next_item->next_item = NULL;
		last_item->next_item->previous_item = last_item;

		last_item = last_item->next_item;
	}
	size++;
	return true;
}

template<typename T>
bool LinkedList<T>::Insert(T value)
{
	if (size == 0)
	{
		AddFirstItem(value);
	}
	else
	{
		first_item->previous_item = new Item<T>;
		first_item->previous_item->item = value;
		first_item->previous_item->previous_item = NULL;
		first_item->previous_item->next_item = first_item;

		first_item = first_item->previous_item;
	}
	size++;
	return true;
}

template<typename T>
bool LinkedList<T>::Insert(int index,T value)
{
	if (size == 0)
	{
		AddFirstItem(value);
	}
	else
	{
		if(index == 0) 
		{
			Insert(value);
		}
		else if (index >= size)
		{
			Add(value);
		}
		else
		{
			Item<T>* it = ReturnItem(index);

			Item<T>* new_it = new Item<T>;
			new_it->item = value;
			new_it->next_item = it;
			new_it->previous_item = it->previous_item;

			it->previous_item->next_item = new_it;
			it->previous_item = new_it;
		}
	}
	size++;
	return true;
}

template<typename T>
T LinkedList<T>::ReturnAt(int index)
{
	Item<T>* it = ReturnItem(index);

	return it->item;
}

template<typename T>
bool LinkedList<T>::RemoveAt(int index)
{

	Item<T>* it = ReturnItem(index);

	if (index == 0)
	{
		it->next_item->previous_item = NULL;
		first_item = it->next_item;

	}
	else if (index == size - 1)
	{
		it->previous_item->next_item = NULL;
		last_item = it->previous_item;
	}
	else
	{
		it->next_item->previous_item = it->previous_item;
		it->previous_item->next_item = it->next_item;
	}
		
	delete it;
	it = NULL;

	size--;
	
	return true;
}

template<typename T>
bool LinkedList<T>::Clear()
{
	Item<T>* it = first_item;

	for (int i = 0; i < size-1; i++)
	{
		it = it->next_item;
		delete it->previous_item;
		it->previous_item = NULL;
	}

	delete it;
	it = NULL;

	size = 0;
	
	return true;
}

template<typename T>
bool LinkedList<T>::EditAt(int index, T new_value)
{

	Item<T>* it = ReturnItem(index);

	it->item = new_value;

	return true;
}

template<typename T>
int LinkedList<T>::FindIndex(T value)
{
	Item<T>* it = first_item;

	for (int i = 0; i < size; i++) 
	{
		if (it->item == value)
		{
			return i;
		}

		it = NextItem(it);
	}

	return -1;
}

template<typename T>
T * LinkedList<T>::ToArray()
{
	T* pole = new T[size];

	Item<T>* it = first_item;

	for (int i = 0; i < size; i++) 
	{	
		pole[i] = it->item;

		it = NextItem(it);
	}

	return pole;
}

// private funkcions

template<typename T>
LinkedList<T>::Item<T>* LinkedList<T>::NextItem(Item<T>* I)
{
	return I->next_item;
}

template<typename T>
LinkedList<T>::Item<T>* LinkedList<T>::PreviousItem(Item<T>* I)
{
	return I->previous_item;
}

template<typename T>
void LinkedList<T>::AddFirstItem(T value)
{

	first_item = new Item<T>;
	first_item->item = value;
	first_item->next_item = NULL;
	first_item->previous_item= NULL;

	last_item = first_item;

}

template<typename T>
LinkedList<T>::Item<T>* LinkedList<T>::ReturnItem(int index)
{
	if (size <= index)
	{
		// chyba
	}

	Item<T>* it;

	// K prvku se vždy snažíme dojít kratší cestou, tudíž pokud je prvek v druhé polovinì seznamu, pùjdeme od posledního. A pokud je v první polovinì, tak pùjdeme od prvku prvního.
	if (index < (size / 2))  
	{
		it = first_item;
		for (int i = 0; i < index; i++)
		{
			it = NextItem(it);
		}
	}
	else
	{
		it = last_item;
		for (int i = 0; i < size - index - 1; i++)
		{
			it = PreviousItem(it);
		}
	}
	return it;
}

#endif