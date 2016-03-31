
/*********************************************************************
** Program Filename: Stack.cpp
** Author: Holly Buteau
** Date: February 14, 2016
** Description: source file for stack class
** Input: none
** Output: none
*********************************************************************/



#include "Stack.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

/*********************************************************************
** Function: Stack
** Description: default constuctor for stack class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: head of stack is initailized to NULL
*********************************************************************/

Stack::Stack()
{
	head = NULL; //initialse head to NULL
}

/*********************************************************************
** Function: ~Stack
** Description: destructor of stack
** Parameters: none
** Pre-Conditions: delete called on stack
** Post-Conditions: stack deleted
*********************************************************************/

Stack::~Stack()
{
	StackNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		StackNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*********************************************************************
** Function: add
** Description: adds numbers into stack
** Parameters: an integer from the user
** Pre-Conditions: add called by user, integer chosen
** Post-Conditions: integer added to stack
*********************************************************************/

void Stack::add(int num)
{
	StackNode *nodePtr = head;
	
	head = new StackNode(num, head); //assigning the beginning of the 
					//stack to be the new number
}

/*********************************************************************
** Function: remove 
** Description: removes items from stack
** Parameters: none
** Pre-Conditions: remove called in main
** Post-Conditions: top item removed in stack
*********************************************************************/

int Stack::remove()
{
	StackNode *temp;


	if (head == NULL) // if nothing is in stack
		cout << "No item in stack!" << endl;

	else
	{
		temp = head;
		head = head->next;
		cout << "Taking " << temp->value << " from the list" << endl;
		delete temp;

	}

	return 0;
}

/*********************************************************************
** Function: displayStack
** Description: displays the contents of stack
** Parameters: none
** Pre-Conditions: called in main
** Post-Conditions: prints to the screen the values in stack
*********************************************************************/

void Stack::displayStack()
{
	StackNode *nodePtr = head;
	if (nodePtr == NULL)
		cout << "Stack is empty." << endl;
	
	while (nodePtr != NULL)
	{
		cout << nodePtr->value;
		nodePtr = nodePtr->next;
	}
	
}

