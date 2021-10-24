#ifndef __DICECLASS__
#define __DICECLASS__

#include <iostream>

class DiceClass
{
public:

	int countEdge;

	DiceClass();
	DiceClass(int CountEdge);
	int Throw();
	
};

#endif