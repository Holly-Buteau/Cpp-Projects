/*********************************************************************
 * ** Program Filename: Item.cpp
 * ** Author: Holly Buteau
 * ** Date: January 31, 2016
 * ** Description: source file for item class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/



#include "Item.hpp"
#include "List.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

/*********************************************************************
 * ** Function: operator ==
 * ** Description: allows objects to be compared to each other
 * ** Parameters: referenced object
 * ** Pre-Conditions: item created by user
 * ** Post-Conditions: returns if item already exists
 * *********************************************************************/

bool Item::operator == (const Item &item) const
{
	return (this -> itemName == item.itemName && this -> unit == item.unit);
	//will return true or false depending on if item exists already
}

/*********************************************************************
 * ** Function: Item
 * ** Description: default constructor
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/

Item::Item()
{
	setItemName("");
	setUnit("");
	setUnitPrice(0.0);
	setNumToBuy(0);
}

/*********************************************************************
 * ** Function: Item
 * ** Description: constructor for item objects
 * ** Parameters: name of item, name of unit, qunatity, and price 
 * ** Pre-Conditions: none
 * ** Post-Conditions: variables are accessible
 * *********************************************************************/

Item::Item(string n, string u, int q,  double p)
{
	setItemName(n);
	setUnit(u);
	setUnitPrice(p);
	setNumToBuy(q);
}

/*********************************************************************
 * ** Function: setItemName
 * ** Description: sets item name to n
 * ** Parameters: a string for item name 
 * ** Pre-Conditions: name is given by user
 * ** Post-Conditions: itemName = n
 * *********************************************************************/

void Item::setItemName(string n)
{
	itemName = n;
}


/*********************************************************************
 * ** Function: setUnit
 * ** Description: sets unit to u
 * ** Parameters: a string for unit
 * ** Pre-Conditions: unit is given by user
 * ** Post-Conditions: unit = u
 ** *********************************************************************/



void Item::setUnit(string u)
{
	unit = u;
}


/*********************************************************************
 * ** Function: setUnitPrice
 * ** Description: sets unit price  to p
 * ** Parameters: a double for unit price
 * ** Pre-Conditions: unit price is given by user
 * ** Post-Conditions: unitPrice = p
 ** *********************************************************************/


void Item::setUnitPrice(double p)
{
	unitPrice = p;
}


/*********************************************************************
 * ** Function: setNumtoBuy
 * ** Description: sets number to buy  to q
 * ** Parameters: an int for quantity
 * ** Pre-Conditions: quantity is given by user
 * ** Post-Conditions: numToBuy = q
 *********************************************************************/

void Item::setNumToBuy(int q)
{
	numToBuy = q;
}

/*********************************************************************
 * ** Function: getItemName
 * ** Description: returns item name to method
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: item is given to method
 * *********************************************************************/

string Item::getItemName()
{
	return itemName;
}

/*********************************************************************
 * ** Function: getUnit
 * ** Description: returns unit to method
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: unit is given to method
 * *********************************************************************/

string Item::getUnit()
{
	return unit;
}

/*********************************************************************
 * ** Function: getUnitPrice
 * ** Description: returns unit price to method
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: uinit price is given to method
 * *********************************************************************/

double Item::getUnitPrice()
{
	return unitPrice;
}

/*********************************************************************
 * ** Function: getNumToBuy
 * ** Description: returns the quantity to method
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: quantity is given to method
 * *********************************************************************/

int Item::getNumToBuy()
{
	return numToBuy;
}
