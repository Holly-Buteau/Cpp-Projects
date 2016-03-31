/*********************************************************************
 * ** Program Filename: CreatureQueue.cpp
 * ** Author: Holly Buteau
 * ** Date: February 28. 2015
 * ** Description: source file for CreatureQueue class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/

#include "creatureQueue.hpp"
#include <stdlib.h>
using namespace std;




/*********************************************************************
 * ** Function: CreatureQueue::CreatureQueue
 * ** Description: default constructor for CreatureQueue
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: CreatureQueue default values are set
 * *********************************************************************/

CreatureQueue::CreatureQueue()
{
        this->head = NULL;
        this->tail = NULL;
}

/*********************************************************************
 * ** Function: CreatureQueue::~CreatureQueue
 * ** Description: destructor for CreatureQueue
 * ** Parameters: none
 * ** Pre-Conditions: delete is called
 * ** Post-Conditions: QueueNode is deleted
 * *********************************************************************/



CreatureQueue::~CreatureQueue()
{	
	CreatureNode *ptr;
	ptr = this->head;

	while(ptr)
	{
		CreatureNode *temp;
		temp = ptr;
		ptr = ptr->next;
		delete temp;
		//this->head = NULL;
		//this->temp = NULL;	
	}	
}

/*********************************************************************
 * ** Function: CreatureQueue::isEmpty
 * ** Description: checks to see if queue is empty, returns boolean
 * ** Parameters: none
 * ** Pre-Conditions: called in main
 * ** Post-Conditions: returns boolean
 * *********************************************************************/


bool CreatureQueue::isEmpty()
{
	if (this->head == NULL)
		return true;
	
	else
		return false;
		
}

/*********************************************************************
 * ** Function: CreatureQueue::add
 * ** Description: adds values into queue
 * ** Parameters: pointer to creature object
 * ** Pre-Conditions: called in main
 * ** Post-Conditions: creature pointer is added to queue
 * *********************************************************************/



void CreatureQueue::add(Creature *thing)
{
        CreatureNode *nodePtr;
        nodePtr = new CreatureNode;
        nodePtr->critter = thing;
        nodePtr->next = NULL;
        if (this->head == NULL)
        {
		  this->head = nodePtr;

	}

        else
        {
                this->tail->next = nodePtr; 

	}

	this->tail = nodePtr;
}

/*********************************************************************
 * ** Function: CreatureQueue::displayQueue
 * ** Description: displays the queue
 * ** Parameters: none
 * ** Pre-Conditions: called in main
 * ** Post-Conditions: queue is displayed
 * *********************************************************************/


void CreatureQueue::displayQueue()
{
        CreatureNode *nodePtr; //= new CreatureNode;
        nodePtr = this->head;

        if (isEmpty() == true)
                cout << "Queue is empty" << endl;
        else
        {
                while(nodePtr != NULL)
                {
                        cout << nodePtr->critter->getName() << endl;
                        nodePtr = nodePtr->next;
                }
        }

}

/*********************************************************************
 * ** Function: CreatureQueue::remove
 * ** Description: removes values from queue
 * ** Parameters: none
 * ** Pre-Conditions: called in main
 * ** Post-Conditions: creature pointer is deleted from queue
 * *********************************************************************/


void CreatureQueue::remove()
{
        CreatureNode *temp;

        if (this->head == NULL)
                cout << "No item in queue!" << endl;  // if nothing is in queue

	
	else if (this->head->next == NULL)
	{	delete this->head;
		this->head = NULL;
		//this->head = NULL;
	}

        else
        {
                temp = this->head;
                this->head = this->head->next;
                delete temp;
		
        }

        //return 0;
}

/*********************************************************************
 * ** Function: CreatureQueue::getFirst
 * ** Description: returns the first thing in queue
 * ** Parameters: none
 * ** Pre-Conditions: called in main
 * ** Post-Conditions: first object in queue is returned
 * *********************************************************************/


Creature* CreatureQueue::getFirst()
{	
		
	return this->head->critter;

}          
