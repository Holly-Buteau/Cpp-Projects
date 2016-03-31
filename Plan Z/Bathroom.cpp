/*********************************************************************
** Program Filename: Bathroom.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: source file for bathrooom class
** Input: none
** Output: none
*********************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include "Bathroom.hpp"
#include "Space.hpp"
#include "Bedroom.hpp"
#include "Item.hpp"
using namespace std;


/*********************************************************************
** Function: Bathroom
** Description: default constructor
** Parameters: none
** Pre-Conditions: ohject created
** Post-Conditions: default values set
*********************************************************************/

Bathroom::Bathroom()
{
        this->dark = true;
        this->visited = false;
	this->seeMedicine = false;
	this->lightsOn = false;
	this->medTaken = false;
	this->seeRoom = false;
}	

/*********************************************************************
** Function: ~Bathroom
** Description: desctructor
** Parameters: none
** Pre-Conditions: delete called
** Post-Conditions: deleted
*********************************************************************/

Bathroom::~Bathroom()
{
        delete this;
}

/*********************************************************************
** Function: getPointers
** Description: sets inherited pointers to passed pointers
** Parameters: 5 space pointers
** Pre-Conditions: called in main
** Post-Conditions: pointers are set to each room
*********************************************************************/

void Bathroom::getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5)
{
	this->ptr1 = p1;
        this->ptr2 = p2;
	this->ptr3 = p3;
        this->ptr4 = p4;
        this->ptr5 = p5;

}

/*********************************************************************
** Function: getVisited
** Description: returns whether room was visited
** Parameters: none
** Pre-Conditions: called in Player Class
** Post-Conditions: return boolean
*********************************************************************/

bool Bathroom::getVisited()
{
        return this->visited;
}

/*********************************************************************
** Function: Inventory
** Description: the room's inventory
** Parameters: Item pointer
** Pre-Conditions: called in main
** Post-Conditions: passed item is placed in room inventory
*********************************************************************/

void Bathroom::Inventory(Item* item)
{
        bathroomItems.push_back(item);
}

/*********************************************************************
** Function: Start
** Description: reads the starting text for the room
** Parameters: none
** Pre-Conditions: called in main or Player class
** Post-Conditions: outputs the text for the room
*********************************************************************/

void  Bathroom::Start()
{
	
 	if (this->visited == false)      // if player hasn't been here before, show this
        {
	cout << "********************************************************" << endl;
        cout << "                     ROOM: BATHROOM" << endl;
        cout << "********************************************************" << endl;
        cout << endl;
        cout << "As you walk into the bathroom, it is dark. The lights are off." << endl;
	this->visited = true; //sets visited to true

	}

        else // if the user has already been here, there's no need to show the same expository text again
        {
		cout << "********************************************************" << endl;
        	cout << "                     ROOM: BATHROOM" << endl;
       	 	cout << "********************************************************" << endl;
        	cout << endl;

	         cout << "Everything looks the same as when you last came in here." << endl;
	}
        
}

/*********************************************************************
** Function: Look
** Description: gives player the options to look at
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: outputs what the player sees
*********************************************************************/


void Bathroom::Look()
{
        int lookChoice;
	if (lightsOn == false)
	{
		cout << "You can't see anything! The lights are off!" << endl;
	}
        
	if (lightsOn == true && seeRoom == false) 
	{	cout << "You look around the room and see a medicine cabinet, a bathtub, drawers, and a closet." << endl;
		seeRoom = true;
	}

	if (lightsOn == true)
	{
	cout << endl;	
        cout << "Where would you like to look?" << endl;
        cout << "1. Medicine Cabinet " << endl;
        cout << "2. Closet" << endl;
	cout << "3. Bathtub" << endl;
	cout << "4. Drawers" << endl;
	cin >> lookChoice;
	cout << endl;
	

        if (lookChoice == 1)
        {	if (medTaken == false)
                {cout << "Inside of the medicine cabinet, you find basic first aid supplies." << endl;
        	seeMedicine = true; 
		}
		else //if the medicine has been taken, the user will not see it again

		cout << "It's empty." << endl;

        }

        else if (lookChoice == 2)
        {	
                cout << "Inside the closet are fresh towels and a laundry hamper." << endl;
                cout << "Inside the hamper are dirty clothes. Blech! How long have they been sitting here??" << endl;

        }

        else if (lookChoice == 3)
	{
		cout << "In the bathtub you see...nothing special. It's just a bathtub." << endl;
	}
	else if (lookChoice == 4)
	{
		cout << "You dig through the drawers and find toothpaste, a hairbrush, and deodorant." << endl;

	}
	
	else
        {       cout << "Not a valid choice. Pick again." << endl;

        }
	}	
}
/*********************************************************************
** Function: Use
** Description: gives the player to options to use *This is the special function
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: player can use items
*********************************************************************/

void Bathroom::Use()
{
        int useChoice;

	if (lightsOn == true) // the only thing to use in this room is the light

                cout << "There is nothing else to use in this room." << endl;
	else 
	{
        cout << "What will you use?" << endl;
        cout << "1. the lightswitch" << endl;
	cin >> useChoice;
	
        if (useChoice == 1)
        {	cout << endl;
	       lightsOn = true;
                cout << "Finally, a little light. It's a bathroom!" << endl;
        }

        else
        {
                cout << "Not a valid choice. Pick again.";

        }
	}
}

/*********************************************************************
** Function: Leave
** Description: allows the player to choose where to go next
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: player leaves the room
*********************************************************************/

Space* Bathroom::Leave()
{
	if (lightsOn == false) // player can't leave unless the light is on
	{	cout << "I can't find the door, the light is off." << endl;
		return NULL;
	}
	
	else	
	{int leaveChoice;	
	cout << "Where would you like to go?" << endl;
        cout << "1. Bedroom" << endl;
        cout << "2. Attic" << endl;
        cout << "3. Kitchen" << endl;
        cout << "4. Living Room" << endl;
        cin >> leaveChoice;
	
	if (leaveChoice == 1)
         	return ptr1;
	else if (leaveChoice == 2)
                return ptr3;
        else if (leaveChoice == 3)
                return ptr4;
        else if (leaveChoice == 4)
                return ptr5;
 	
        else
        {	cout << "Not a valid choice. Pick again." << endl;
		return NULL;	
	}
	}
}

/*********************************************************************
** Function: Take
** Description: allows player to take items from room and place in inventory
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: returns pointer to item
*********************************************************************/

Item* Bathroom::Take()
{
        int takeChoice;

        if (seeMedicine == false)
        {       cout << "You don't see anything to take." << endl;
		return NULL;
                
        }

        else
        {       
		if  (medTaken == true)
                {       cout << "There is nothing more to take in this room." << endl;
                        return NULL;
                }

		else
		{cout << "What will you take?" << endl;
                cout << "1. the first aid kit" << endl;
                cin >> takeChoice;	
		}
		
		if(takeChoice == 1)
                {       medTaken = true;
                        return bathroomItems[0];
                }

        }

}


