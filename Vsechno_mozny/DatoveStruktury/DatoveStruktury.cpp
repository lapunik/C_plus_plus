#include <iostream>
#include "List.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "BST.h"

using namespace std;

int main()
{
	// List

	/*

	List<int>* int_list = new List<int>();


	int_list->Add(5);
	int_list->Add(6);
	int_list->Add(1);
	int_list->Add(12);
	int_list->Add(21);
	int_list->Add(9);
	int_list->Add(4);
	int_list->Add(9);
	int_list->Add(3);
	int_list->Add(8);

	cout << "Seznam s velikosti: " << int_list->size << "/" << int_list->full_size << endl;

	for (int i = 0; i < int_list->size; i++)
	{
		cout << int_list->ReturnAt(i) << endl;
	}

	int_list->RemoveAt(2);
	int_list->RemoveAt(2);
	int_list->RemoveAt(2);

	cout << "Smazany seznam s velikosti: " << int_list->size << "/" << int_list->full_size << endl;

	for (int i = 0; i < int_list->size; i++)
	{
		cout << int_list->ReturnAt(i) << endl;
	}

	int_list->EditAt(2, 10);
	int_list->EditAt(3, 10);
	int_list->EditAt(4, 10);

	cout << "Pozmeneny seznam s velikosti: " << int_list->size << "/" << int_list->full_size << endl;

	for (int i = 0; i < int_list->size; i++)
	{
		cout << int_list->ReturnAt(i) << endl;
	}

	int_list->Insert(3);
	int_list->Insert(2);
	int_list->Insert(1);

	cout << "Seznam s pridanimi prvky na zacatek s velikosti: " << int_list->size << "/" << int_list->full_size << endl;

	for (int i = 0; i < int_list->size; i++)
	{
		cout << int_list->ReturnAt(i) << endl;
	}

	cout << "Index na kterem se nachazi hodnota 6: " << int_list->FindIndex(6) << endl;
	cout << "Vracena hodnota, pokud se snazime hledat hodnotu v seznamu, ktera se tam nenachazi: " << int_list->FindIndex(99) << endl;

	delete int_list;
	int_list = NULL;

	int* o = new int[10];

	for (int i = 0; i < 10; i++)
	{
		o[i] = i;
	}

	List<int>* int_list = new List<int>(o, 10);

	cout << "Seznam vytvořený přímo na základě pole: " << int_list->size << "/" << int_list->full_size << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << int_list->ReturnAt(i) << endl;
	}

	delete int_list;
	int_list = NULL;

	List<double>* double_list = new List<double>();

	double_list->Add(1.2);
	double_list->Add(2.8);
	double_list->Add(4.7);

	double_list->RemoveAt(35);

	cout << "Desetinne pole s velikosti: " << double_list->size << "/" << double_list->full_size << endl;

	for (int i = 0; i < double_list->size; i++)
	{
		cout << double_list->ReturnAt(i) << endl;
	}

	double_list->Clear();

	cout << "Desetinne pole smazane: " << double_list->size << "/" << double_list->full_size << endl;

	for (int i = 0; i < double_list->size; i++)
	{
		cout << double_list->ReturnAt(i) << endl;
	}

	double_list->Add(1.2);
	double_list->Add(2.8);
	double_list->Add(4.7);

	cout << "Desetinne pole s velikosti: " << double_list->size << "/" << double_list->full_size << endl;

	for (int i = 0; i < double_list->size; i++)
	{
		cout << double_list->ReturnAt(i) << endl;
	}

	cout << "Prvni prvek predchayejiciho pole: " << double_list->ToArray()[0] << endl;

	delete double_list;
	double_list = NULL;

	*/

	// Linked List

	/*
	LinkedList<int>* linked_list = new LinkedList<int>();

	linked_list->Add(6);
	linked_list->Add(12);
	linked_list->Add(3);
	linked_list->Add(5);

	cout << "Vypis seznamu: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	linked_list->Insert(2);
	linked_list->Insert(1);

	cout << "Vypis seznamu s doplnenymi prvky na zacatek: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	linked_list->RemoveAt(0);
	linked_list->RemoveAt(linked_list->size-1);

	cout << "Vypis promazaneho seznamu: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	linked_list->Add(5);
	linked_list->Insert(1);

	cout << "Vypis obnoveneho seznamu: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	linked_list->Clear();

	cout << "Vypis smazaneho seznamu: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	linked_list->Add(1);
	linked_list->Add(2);
	linked_list->Add(3);

	cout << "Vypis seznamu: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	linked_list->EditAt(0,4);
	linked_list->EditAt(1,5);
	linked_list->EditAt(2,6);

	cout << "Vypis upraveneho seznamu: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	cout << "Prvek s hodnotou 4 je na pozici: " << linked_list->FindIndex(4) << endl;
	cout << "Prvek s hodnotou 5 je na pozici: " << linked_list->FindIndex(5) << endl;
	cout << "Prvek s hodnotou 6 je na pozici: " << linked_list->FindIndex(6) << endl;
	cout << "Prvek s hodnotou 7 je na pozici: " << linked_list->FindIndex(7) << endl;

	cout << "Vypis seznamu jako pole: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ToArray()[i] << endl;
	}

	linked_list->Clear();

	for (int i = 0; i < 10; i++)
	{
		linked_list->Add(i);
	}

	linked_list->Insert(5,99);

	cout << "Vypis seznamu s doplnenym prvkem nekam do seznamu: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	int* o = new int[10];

	for (int i = 0; i < 10; i++)
	{
		o[i] = i;
	}

	linked_list = new LinkedList<int>(o,10);

	cout << "Seznam vytvoreny primo na zaklade pole: " << endl;

	for (int i = 0; i < linked_list->size; i++)
	{
		cout << linked_list->ReturnAt(i) << endl;
	}

	delete linked_list;
	linked_list = NULL;

	*/

	// Queue

	/*
	Queue<int>* int_queue = new Queue<int>();

	int_queue->Enqueue(6);
	int_queue->Enqueue(14);
	int_queue->Enqueue(3);
	int_queue->Enqueue(9);
	int_queue->Enqueue(2);

	cout << "Fronta: " << int_queue->Peek() << " s velikosti: " << int_queue->size << endl;

	while (int_queue->size > 0)
	{
		cout << int_queue->Dequeue() << endl;
	}

	delete int_queue;
	int_queue = NULL;

	int* pole = new int[5];
	pole[0] = 6;
	pole[1] = 14;
	pole[2] = 3;
	pole[3] = 9;
	pole[4] = 2;

	int_queue = new Queue<int>(pole, 5, true);

	cout << "Fronta vytvorena z pole a invertovana: " << int_queue->Peek() << " s velikosti: " << int_queue->size << endl;

	while (int_queue->size > 0)
	{
		cout << int_queue->Dequeue() << endl;
	}

	int_queue->Clear();

	cout << "Smazana fronta (velikost): " << int_queue->size << endl;

	int_queue->Enqueue(6);
	int_queue->Enqueue(14);
	int_queue->Enqueue(3);
	int_queue->Enqueue(9);
	int_queue->Enqueue(2);

	cout << "Obnovena fronta: " << int_queue->Peek() << " s velikosti: " << int_queue->size << endl;

	while (int_queue->size > 0)
	{
		cout << int_queue->Dequeue() << endl;
	}

	int_queue->Enqueue(6);
	int_queue->Enqueue(14);
	int_queue->Enqueue(3);
	int_queue->Enqueue(9);
	int_queue->Enqueue(2);

	cout << "Prvek s hodnotou 9 se nachazi na indexu: " << int_queue->FindIndex(9) << endl;

	cout << "Vypis fronty jako pole: " << endl;

	for (int i = 0; i < int_queue->size; i++)
	{
		cout << int_queue->ToArray()[i] << endl;
	}

	delete int_queue;
	int_queue = NULL;
	*/

	// Stack	

	/*
	Stack<int>* int_stack = new Stack<int>();

	int_stack->Push(5);
	int_stack->Push(14);
	int_stack->Push(3);
	int_stack->Push(9);
	int_stack->Push(1);

	cout << "Zasobnik, kde na rade je: " << int_stack->Peek() << " s velikosti: " << int_stack->size << endl;

	while (int_stack->size > 0)
	{
		cout << int_stack->Pop() << endl;
	}

	delete int_stack;
	int_stack = NULL;

	int* pole = new int[5];
	pole[0] = 6;
	pole[1] = 14;
	pole[2] = 3;
	pole[3] = 9;
	pole[4] = 2;

	int_stack = new Stack<int>(pole, 5, false);

	cout << "Fronta vytvorena z pole, kde na rade je: " << int_stack->Peek() << " s velikosti: " << int_stack->size << endl;

	while (int_stack->size > 0)
	{
		cout << int_stack->Pop() << endl;
	}



	int_stack->Clear();

	cout << "Smazana fronta (velikost): " << int_stack->size << endl;

	int_stack->Push(6);
	int_stack->Push(14);
	int_stack->Push(3);
	int_stack->Push(9);
	int_stack->Push(2);

	cout << "Obnovena fronta, kde na rade je: " << int_stack->Peek() << " s velikosti: " << int_stack->size << endl;

	while (int_stack->size > 0)
	{
		cout << int_stack->Pop() << endl;
	}

	

	int_stack->Push(6);
	int_stack->Push(14);
	int_stack->Push(3);
	int_stack->Push(9);
	int_stack->Push(2);

	cout << "Prvek s hodnotou 9 se nachazi na indexu: " << int_stack->FindIndex(9) << endl;

	cout << "Vypis fronty jako pole: " << endl;

	for (int i = 0; i < int_stack->size; i++)
	{
		cout << int_stack->ToArray()[i] << endl;
	}

	delete int_stack;
	int_stack = NULL;
	*/

	// Binary Search Tree

	BST<int>* int_BST = new BST<int>();

}