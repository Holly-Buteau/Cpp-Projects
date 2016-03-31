/*********************************************************************
** Program Filename: Space.hpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: header file for space class
** Input: none
** Output: none
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string> 
#include <iostream>
#include "Item.hpp"
using namespace std;

class Space
{
protected:
	bool dark;
	bool visited;
	Space *ptr1;
	Space *ptr2;
	Space *ptr3;
	Space *ptr4;
	Space *ptr5;
	
public:
	Space();
	virtual void getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5) = 0;
	virtual void Use() = 0;
	virtual Item* Take() = 0;
	virtual void Look() = 0;
	virtual void Start() = 0;
	virtual Space* Leave() = 0;
	virtual void Inventory(Item *item) = 0;
	virtual bool getVisited() = 0;
};
#endif
