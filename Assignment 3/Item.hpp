/*********************************************************************
 * ** Program Filename: Item.hpp
 * ** Author: Holly Buteau
 * ** Date: January 31, 2016
 * ** Description: header file for item class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;


class Item
{

private:
	string itemName;
	string unit;
	int numToBuy;
	double unitPrice;

public:
	Item();
	Item(string, string, int, double);
	void setItemName(string n);
	void setUnit(string u);
	void setUnitPrice(double p);
	void setNumToBuy(int q);
	string getItemName();
	string getUnit();
	double getUnitPrice();
	int getNumToBuy();
	bool operator == (const Item &) const;
	//Item returnItem(int i);

};


#endif
