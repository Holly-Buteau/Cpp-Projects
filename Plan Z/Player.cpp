/*********************************************************************
** Program Filename: Player.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: source file for player class
** Input: none
** Output: none
*********************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
#include "Space.hpp"
#include "Item.hpp"

using namespace std;

/*********************************************************************
** Function: Player
** Description: default constructor
** Parameters: none
** Pre-Conditions: ohject created
** Post-Conditions: default values set
*********************************************************************/

Player::Player()
{

	this->steps = 35;

}

/*********************************************************************
** Function: setLocation
** Description: sets inherited pointer to current location
** Parameters:  space pointer
** Pre-Conditions: called in main
** Post-Conditions: location is set
*********************************************************************/

void Player::setLocation(Space *room)
{
	currentLocation = room;
}

/*********************************************************************
** Function: Menu
** Description: gives players options on what to do in each room,
calls the room' methods
** Parameters: none
** Pre-Conditions: called in main
** Post-Conditions: player has options
*********************************************************************/

void Player::Menu()
{
	
        int choice;
	if (inventory.size() == 5)
	{	cout << endl;
		cout << "You manage to leave the house with everything Cameron told you to grab." << endl;
		cout << "You grab the bike that was laying outside of your bedroom window." << endl;
		cout << "You head toward TJ's house, hopefully to have a pint and wait for all this to blow over." << endl;
		cout << "YOU WIN!" << endl;
		cout << endl;
		exit(EXIT_SUCCESS);
	}
	if (currentLocation->getVisited() == false)
		currentLocation->Start();
	cout << endl;
	if (steps == 0)
        {       cout << "Game Over: The zombies have found you. You have died." << endl;
		exit(EXIT_SUCCESS);
	}	
	else
	{ 
		if (steps <= 30)
		{ 
		cout << "The zombies will soon find your location. You should hurry. Number of steps left: " << steps << endl;
		cout << endl;
		}
	
	
        cout << "What do you want to do?" << endl;
        cout << "1. Look " << endl;
        cout << "2. Use " <<endl;
        cout << "3. Take" << endl;
        cout << "4. Leave" << endl;
	cout << "5. Check Inventory" << endl;
        cin >> choice;
	cout << endl;
        if (choice == 1)
        {	steps--;
	      	currentLocation->Look();
		Menu();
	}
        else if (choice == 2)
        {	steps--;
		currentLocation->Use();
		Menu();
	}
        else if (choice == 3)
        {	steps--;
		Item *take;
		take = currentLocation->Take();
		if (take != NULL)
		{inventory.push_back(take);
	         Menu();
		}
		else
		Menu();
	}
        else if (choice == 4)
        {	steps--;
		Space *move;
		move = currentLocation->Leave();       
		if (move != NULL)
		{
		currentLocation = move;
		currentLocation->Start();
		Menu();
		}
		else
		Menu();
	}
	else if (choice == 5)
	{		
		checkInventory();
		Menu();
	}
        else
        {       cout << "Not a valid choice. Pick again." << endl;
                Menu();
        }
	
	}	
}

/*********************************************************************
** Function: checkInventory
** Description: displays player inventory
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: inventory is displayed
*********************************************************************/

void Player::checkInventory()
{
	
	if (inventory.size() == 0)
		cout << "Your inventory is empty!" << endl;
	
	else
	cout << "Inventory:" << endl;
	for (int i = 0; i < inventory.size(); i++)
	{ 
	       	cout << inventory[i]->getName() << endl;
	}
}	
