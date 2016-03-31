/*********************************************************************
** Program Filename: Item.hpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: header file for item class
** Input: none
** Output: none
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string> 
#include <iostream>
using namespace std;

class Item
{
private:
	string name;
	
public:
	
	Item();
	~Item();
	void setName(string n);
	string getName();

};
#endif
