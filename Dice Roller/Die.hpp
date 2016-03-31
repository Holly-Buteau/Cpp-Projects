/*********************************************************************
 * ** Program Filename: Die.hpp
 * ** Author: Holly Buteau
 * ** Date:January 24, 2016
 * ** Description: header file for die class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/


#ifndef DIE_HPP
#define DIE__HPP
#include <iostream>
#include <stdlib.h>
#include <time.h>


class Die
{
private:
	int numRolled;

protected:
	int numSides;

public:
	int roll();
	int loadedRoll();
	Die(int numSides);
	Die();

};
#endif
