
/*********************************************************************
** Program Filename: Queue.cpp
** Author: Holly Buteau
** Date: February 14, 2016
** Description: source file for queue class
** Input: none
** Output: none
*********************************************************************/


#include "Queue.hpp"
#include <stdlib.h>
using namespace std;


/*********************************************************************
** Function: Queue
** Description: default constuctor for queue class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: head and tail of queue are initailized to NULL
*********************************************************************/

Queue::Queue()
{
	head = NULL;
	tail = NULL;
}


/*********************************************************************
** Function: add
** Description: adds numbers into queue
** Parameters: an integer from the user
** Pre-Conditions: add called by user, integer chosen
** Post-Conditions: integer added to queue
*********************************************************************/


void Queue::add(int num)
{
	QueueNode *nodePtr;
	nodePtr = new QueueNode;
	nodePtr->value = num;
	nodePtr->next = NULL;
	if (head == NULL)
	{
		head = nodePtr;//if there is nothing in queue, int goes to the
			      // beginning
		
	}

	else
	{
		tail->next = nodePtr; //othweise, it goes to the end
	}
	tail = nodePtr;
}

/*********************************************************************
** Function: remove
** Description: removes items from queue
** Parameters: none
** Pre-Conditions: remove called in main
** Post-Conditions: top item removed in queue
*********************************************************************/

int Queue::remove()
{
	QueueNode *temp;

	if (head == NULL)
		cout << "No item in queue!" << endl;  // if nothing is in queue


	else
	{
		temp = head;
		head = head->next;
		cout << "Taking " << temp->value << " from the queue" << endl;
		delete temp;

	}

	return 0;
}

/*********************************************************************
** Function: displayQueue
** Description: displays the contents of Queue
** Parameters: none
** Pre-Conditions: called in main
** Post-Conditions: prints to the screen the values in Queue
*********************************************************************/


void Queue::displayQueue()
{
	QueueNode *nodePtr = new QueueNode;
	nodePtr = head;
	
	if (head == NULL)
		cout << "Queue is empty" << endl;
	else 
	{
		while(nodePtr != NULL)
		{
			cout << nodePtr->value;
			nodePtr = nodePtr->next;
		}
	}

}
