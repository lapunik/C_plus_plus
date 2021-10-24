#include "DiceClass.h"
#include "time.h"

DiceClass::DiceClass() : DiceClass(6)
{
	countEdge = 6;
}

DiceClass::DiceClass(int CountEdge)
{
	countEdge = CountEdge;
}

int DiceClass::Throw()
{
	srand(time(NULL)); // inicializace random seed

	return rand() % countEdge + 1;
}
