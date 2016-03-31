/*********************************************************************
 * ** Program Filename: LoadedDie.cpp
 * ** Author: Holly Buteau
 * ** Date: January 24, 2016
 * ** Description: LoadedDie sorce file
 * ** Input: number of sides on the die
 * ** Output: loaded die roll
 * *********************************************************************/




#include "game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


/*********************************************************************
 * ** Function: constructor
 * ** Description: constructor for loaded die
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: numSides = n
 * *********************************************************************/

LoadedDie::LoadedDie(int n)
{
	numSides = n;
}


/*********************************************************************
 * ** Function: default constructor
 * ** Description: default constructor for loaded die 
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: default num sides is 4
 * *********************************************************************/

LoadedDie::LoadedDie()
{
	numSides = 4;
}

/*********************************************************************
 * ** Function: loadedRoll
 * ** Description: rolls unfairly
 * ** Parameters: none
 * ** Pre-Conditions: die type, numSides are chosen
 * ** Post-Conditions: returns a loaded roll
 * *********************************************************************/


int LoadedDie::loadedRoll()
{
	int roll = (rand() % numSides + 1);
	
        //checks for a low roll
	if (roll >= numSides / 2)
	{
		return roll;
	}

	else
	{
		return numSides;
	}
}
