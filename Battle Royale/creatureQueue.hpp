/*********************************************************************
 * ** Program Filename: CreatureQueue.hpp
 * ** Author: Holly Buteau
 * ** Date: February 28. 2016
 * ** Description: header file for CreatureQueue class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/


#ifndef CREATUREQUEUE_HPP
#define CREATUREQUEUE_HPP

#include <iostream>
#include <stdlib.h>
#include "Creature.hpp"
using namespace std;

class CreatureQueue
{
protected:
     	
struct CreatureNode

{

        CreatureNode *next;

        Creature *critter;

};
		
	CreatureNode *tail;
	CreatureNode *head;
        


public:

	CreatureQueue();
	~CreatureQueue();
	void add(Creature *thing);
	void addBack(Creature *thing);
	void remove();
	void displayQueue();
	bool isEmpty();
	Creature* getFirst();
};
#endif


