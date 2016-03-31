/*********************************************************************
 * ** Program Filename: Die.cpp
 * ** Author: Holly Buteau
 * ** Date:January 24, 2016
 * ** Description: source file for die class
 * ** Input: number of sides 
 * ** Output: roll for a regular die
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
 * ** Description: constructor for die
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: numbSides = n
 * *********************************************************************/

Die::Die(int n)
{
	numSides = n; 
}

/*********************************************************************
 * ** Function: default constructor
 * ** Description: default constructor for die
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: default numSides is 4
 * *********************************************************************/

Die::Die()
{
	numSides = 4;
}

/*********************************************************************
 * ** Function: roll
 * ** Description: rolls normally
 * ** Parameters: none
 * ** Pre-Conditions: die type and num sides chosen
 * ** Post-Conditions: a roll is made
 * *********************************************************************/

int Die::roll()
{
	return (rand() % numSides + 1);
}
