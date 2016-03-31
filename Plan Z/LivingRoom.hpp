/*********************************************************************
** Program Filename: LivingRoom.hpp
** Author: Holly Buteau
** Date: March 12, 2016
** Description: header file for livingroom class
** Input: none
** Output: none
*********************************************************************/

#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Space.hpp"
#include "Item.hpp"
using namespace std;

class LivingRoom : public Space
{
private:
        vector<Item*> livingroomItems;//vector of kitchen items
	bool seeRemote;
	bool seePoker;
	bool pokerTaken;
	bool tvUsed;
public:
        LivingRoom();
        ~LivingRoom();
	virtual void getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5);//takes as an argument pointers to different rooms
	virtual void Use();
	virtual void Start();
	virtual Item* Take();
        virtual Space* Leave();//returns the pointer to the space chosen to move to
	virtual void Look();
        virtual void Inventory(Item* item);//places an item pointer into inventory
	virtual bool getVisited();

};
#endif

