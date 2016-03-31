/*********************************************************************
** Program Filename: Bathroom.hpp
** Author: Holly Buteau
** Date: March 12, 2016
** Description: header file for bathroom class
** Input: none
** Output: none
*********************************************************************/


#ifndef BATHROOM_HPP
#define BATHROOM_HPP

#include <iostream>
#include <string> 
#include "Space.hpp"
#include "Item.hpp"

#include <vector>
using namespace std;

class Bathroom : public Space
{
private:
	vector<Item*> bathroomItems; //vector of bedroom items
	bool seeMedicine;
	bool lightsOn;
	bool medTaken;
	bool seeRoom;
public:
	Bathroom();
	~Bathroom();
	virtual void getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5);//takes as an argument pointers to different rooms
	virtual void Use();
        virtual void  Start();
	virtual void Inventory(Item* item);
	virtual void Look();
	virtual Item* Take(); //places an item pointer into inventory
	virtual Space* Leave();//returns the pointer to the space chosen to move to
	virtual bool getVisited();
};
#endif
