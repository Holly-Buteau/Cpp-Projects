/*********************************************************************
 * ** Program Filename: LoadedDie.hpp
 * ** Author:Holly Buteau
 * ** Date:January 24, 2016
 * ** Description: header file for the loaded die class
 * ** Input:none
 * ** Output:none
 * *********************************************************************/


#ifndef LOADED_HPP
#define LOADED_HPP
#include <iostream>
#include <stdlib.h>
#include <time.h>


class LoadedDie : public Die
{
public:
	int loadedRoll();
	LoadedDie(int numSides);
	LoadedDie();
	
};
#endif
