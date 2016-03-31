/*********************************************************************
** Program Filename: List.hpp
** Author: Holly Buteau
** Date: January 31, 2016
** Description: header file for List class
** Input: none
** Output: none
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;


class List
{
private:
	int counter;
	string itemName;
	string unit;
	int numToBuy;
	double unitPrice;
	double total;
	int arraySize;
	int arrayEnd;
	int numValues;
	Item **itemArray;
	bool check;
public:
	List();
	~List();
	void getItems();
	double calculateTotal();
	void displayList();
	void addItems(Item *item);
	void displayArray();
	void menu();
	void removeItem();
	

};
#endif

