#include <stdio.h>

/*
static void get_ptr_II(int*& ptr)
{
	ptr = malloc(sizeof(int));
	*ptr = 5;
	printf("Adresa hodnoty: 0x%p\nAdresa adresy: 0x%p\nHodnota: %d\n\n", (uintptr_t)ptr, (uintptr_t)&ptr, *ptr);

}
*/

static void get_ptr(int** ptr)
{
	*ptr = malloc(sizeof(int));
	**ptr = 5;
	printf("Adresa hodnoty: 0x%p\nAdresa adresy: 0x%p\nHodnota: %d\n\n", (uintptr_t)*ptr, (uintptr_t)ptr, **ptr);
}

static void get_ptr_DOES_NOT_WORK(int* ptr) 
{
	ptr = malloc(sizeof(int));
	*ptr = 5;
	printf("Adresa hodnoty: 0x%p\nAdresa adresy: 0x%p\nHodnota: %d\n\n", (uintptr_t)ptr, (uintptr_t)&ptr, *ptr);
}

static void get_ptr_new(int** ptr_new) 
{
	get_ptr(ptr_new);
}

int main() 
{
	int* main_ptr = NULL;

	printf("Adresa hodnoty: 0x%p\nAdresa adresy: 0x%p\nHodnota: bez hodnoty\n\n", (uintptr_t)main_ptr, (uintptr_t)&main_ptr);

	//get_ptr(&main_ptr);
	//get_ptr(main_ptr);
	//get_ptr_DOES_NOT_WORK(main_ptr);
	//get_ptr_new(&main_ptr);

	printf("Adresa hodnoty: 0x%p\nAdresa adresy: 0x%p\nHodnota: %d\n\n", (uintptr_t)main_ptr, (uintptr_t)&main_ptr, *main_ptr);

	return 0;
}
