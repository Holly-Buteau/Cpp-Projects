/*********************************************************************
** Program Filename: Stack.hpp
** Author: Holly Buteau
** Date: February 14, 2016
** Description: header file for stack class
** Input: none
** Output: none
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack
{
private:
	// I went ahead and created the struct here for ease of use
	struct StackNode
	{
		int value; //value to be inputted
		StackNode *next; //pointer to next item
		StackNode(int value1, StackNode *next1 = NULL)
		{
			value = value1;
			next = next1;
			
		};
		
	};

	StackNode *head; //beginning of stack
	
	

public:
	Stack();
	~Stack();
	void add(int num);
	int remove();
	void displayStack();

};
#endif
