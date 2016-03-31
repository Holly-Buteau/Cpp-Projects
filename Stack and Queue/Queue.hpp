
/*********************************************************************
** Program Filename: Queue.hpp
** Author: Holly Buteau
** Date: February 14, 2016
** Description: header file for queue class
** Input: none
** Output: none
*********************************************************************/


#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <stdlib.h>
#include "QueueNode.hpp"
using namespace std;

class Queue
{
private:
	QueueNode *head;
	QueueNode *tail;

public:
	Queue();
	void add(int num);
	int remove();
	void displayQueue();
};
#endif










































