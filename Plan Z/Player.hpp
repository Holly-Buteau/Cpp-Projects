/*********************************************************************
** Program Filename: Player.hpp
** Author: Holly Buteau
** Date: March 12, 2016
** Description: header file for player class
** Input: none
** Output: none
*********************************************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string> 
#include <iostream>
#include <vector>
#include "Space.hpp"
#include "Item.hpp"
using namespace std;

class Player
{
private:
	vector<Item*> inventory; //player's inventory
	Space* currentLocation; //players current location
	int steps; //steps to determine time
public:
	Player();
	void checkInventory();
	void Menu();
	void setLocation(Space *room);	
};
#endif	
