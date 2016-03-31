/*********************************************************************
** Program Filename: Item.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: source file for item class
** Input: none
** Output: none
*********************************************************************/


#include "Item.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include <string>
using namespace std;

/*********************************************************************
 * ** Function: Item
 * ** Description: default constructor
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: default values set
 * *********************************************************************/

Item::Item()
{

	this->name = "";
}

/*********************************************************************
 * ** Function: ~Item
 * ** Description: destructor 
 * ** Parameters: none
 * ** Pre-Conditions: delete called
 * ** Post-Conditions: deleted
 * *********************************************************************/

Item::~Item()
{
	delete this;
}

/*********************************************************************
 * ** Function: getName
 * ** Description: returns name
 * ** Parameters: none
 * ** Pre-Conditions: called in player class
 * ** Post-Conditions: item name is returned
 * *********************************************************************/


string Item::getName()
{
	return this->name;

}

/*********************************************************************
 * ** Function: setName
 * ** Description: sets name for item
 * ** Parameters: string
 * ** Pre-Conditions: called in main
 * ** Post-Conditions: sets name to passed string
 * *********************************************************************/

void Item::setName(string n)
{

	this->name = n;
}
