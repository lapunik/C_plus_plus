#ifndef __LIST__
#define __LIST__

#include <iostream>

//	List (Seznam)
//
//		Popis:
//
//			Seznam obsahuje pole, které roste na dvojnásobek své velikosti pokud je zcela plné a naopak 
//			snižuje svoji velikost na polovinu, pokud je prvkù v poli ménì než polovina kapacity pole.
//
//		Èasová nároènost:
//
//			Najdi prvek:							O(n)
//			Pøidej prvek na konec:					O(1)
//			Pøidej prvek na zaèátek:				O(n)
//			Smaž prvek:								O(n)
//			Uprav prvek na indexu:					O(1)
//

template<typename T>
class List
{

	private:

		int initial_size = 4;
		T* pole;

	public:

		int size = 0;
		int full_size;
		List();
		List(int initial_size);
		List(T* arr, int arr_size);
		bool Add(T value);
		bool Insert(T value);
		T ReturnAt(int index);
		bool RemoveAt(int index);
		bool Clear();
		bool EditAt(int index, T new_value);
		int FindIndex(T value);
		T* ToArray();
};


template<typename T>
List<T>::List()
{
	full_size = initial_size;
	pole = new T[full_size];
}

template<typename T>
List<T>::List(int initialSize)
{
	initial_size = initialSize;
	full_size = initial_size;
	pole = new T[full_size];
}

template<typename T>
List<T>::List(T* arr, int arr_size)
{
	full_size = initial_size;
	pole = new T[full_size];

	for (int i = 0; i < arr_size; i++) 
	{
		Add(arr[i]);
	}
}

template<typename T>
bool List<T>::Add(T value)
{

	if (size == full_size)
	{
		T* zaloha = new T[full_size];

		for (int i = 0; i < full_size; i++)
		{
			zaloha[i] = pole[i];
		}

		delete[] pole;

		pole = new T[2 * full_size];

		for (int i = 0; i < full_size; i++)
		{
			pole[i] = zaloha[i];
		}

		delete[] zaloha;

		full_size = 2 * full_size;
	}

	pole[size] = value;

	size++;

	return true;
}

template<typename T>
bool List<T>::Insert(T value)
{

	if (size == full_size)
	{
		T* zaloha = new T[full_size];

		for (int i = 0; i < full_size; i++)
		{
			zaloha[i] = pole[i];
		}

		delete[] pole;

		pole = new T[2 * full_size];

		for (int i = 0; i < full_size; i++)
		{
			pole[i] = zaloha[i];
		}

		delete[] zaloha;

		full_size = 2 * full_size;
	}

	for (int i = size; i > 0; i--)
	{
		pole[i] = pole[i - 1];
	}

	pole[0] = value;

	size++;

	return true;
}

template<typename T>
T List<T>::ReturnAt(int index)
{
	return pole[index];
}

template<typename T>
bool List<T>::RemoveAt(int index)
{
	if (!(index < full_size))
		return false;

	for (int i = index; i < size - 1; i++)
	{
		pole[i] = pole[i + 1];
	}

	size--;

	if (size == full_size / 2)
	{

		T* zaloha = new T[size];

		for (int i = 0; i < size; i++)
		{
			zaloha[i] = pole[i];
		}

		delete[] pole;

		pole = new T[size];

		for (int i = 0; i < size; i++)
		{
			pole[i] = zaloha[i];
		}

		delete[] zaloha;

		full_size = size;

	}

	return true;
}

template<typename T>
bool List<T>::Clear()
{
	size = 0;
	full_size = initial_size;
	delete pole;
	pole = new T[full_size];
	return true;
}

template<typename T>
bool List<T>::EditAt(int index, T new_value)
{
	pole[index] = new_value;
	return true;
}

template<typename T>
int List<T>::FindIndex(T value)
{
	for (int i = 0; i < size; i++)
	{
		T a = pole[i];

		if (pole[i] == value)
		{
			return i;
		}
	}

	return -1;
}

template<typename T>
T* List<T>::ToArray()
{
	return pole;
}

#endif