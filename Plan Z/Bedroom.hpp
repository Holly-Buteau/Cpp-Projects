/*********************************************************************
** Program Filename: Bedroom.hpp
** Author: Holly Buteau
** Date: March 12, 2016
** Description: header file for bedroom class
** Input: none
** Output: none
*********************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include <iostream>
#include <string> 
#include <vector>
#include "Space.hpp"
#include "Item.hpp"

using namespace std;

class Bedroom : public Space 
{
private:
	vector<Item*> bedroomItems; //vector of bedroom items
	bool seeGun;
	bool chairMoved;
	bool gunTaken;
	bool seeChair;
	bool seeRoom;
public:
	Bedroom();
	~Bedroom();
	virtual void getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5); //takes as an argument pointers to different rooms
	virtual void Use();
	virtual void Start();
	virtual Item* Take();
	virtual Space* Leave(); //returns the pointer to the space chosen to move to
	virtual void Look();
	virtual void Inventory(Item* item); //places an item pointer into inventory
	virtual bool getVisited();

};
#endif
