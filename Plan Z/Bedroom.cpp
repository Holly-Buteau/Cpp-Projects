/*********************************************************************
** Program Filename: Bedroom.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: source file for bedrooom class
** Input: none
** Output: none
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Bedroom.hpp"
#include "Space.hpp"
#include "Bathroom.hpp"
#include "Attic.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
using namespace std;


/*********************************************************************
** Function: Bedroom
** Description: default constructor
** Parameters: none
** Pre-Conditions: ohject created
** Post-Conditions: default values set
*********************************************************************/

Bedroom::Bedroom()
{	
	this->dark = false;
	this->visited = false; //room has not been visited
	this->seeGun = false; //user can't take the gun until they've seen it
	this->chairMoved = false; //user can't leave room until chair is moved
	this->gunTaken = false; 
	this->seeChair = false; //user can't move chair until they see the chair
	this->seeRoom = false;
}
/*********************************************************************
** Function: ~Bedroom
** Description: desctructor
** Parameters: none
** Pre-Conditions: delete called
** Post-Conditions: deleted
*********************************************************************/

Bedroom::~Bedroom()
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

void Bedroom:: getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5)
{
	this->ptr1 = p1;
	this->ptr2 = p2;
	this->ptr3 = p3;
	this->ptr4 = p4;
	this->ptr5 = p5;
	
} 

/*********************************************************************
** Function: Inventory
** Description: the room's inventory
** Parameters: Item pointer
** Pre-Conditions: called in main
** Post-Conditions: passed item is placed in room inventory
*********************************************************************/

void Bedroom::Inventory(Item* item)
{
	bedroomItems.push_back(item);
}

/*********************************************************************
** Function: getVisited
** Description: returns whether room was visited
** Parameters: none
** Pre-Conditions: called in Player Class
** Post-Conditions: return boolean
*********************************************************************/

bool Bedroom::getVisited()
{
	return this->visited;
}

/*********************************************************************
** Function: Start
** Description: reads the starting text for the room
** Parameters: none
** Pre-Conditions: called in main or Player class
** Post-Conditions: outputs the text for the room
*********************************************************************/

void Bedroom::Start()
{
	if (this->visited == false) // if player hasn't been here before, show this
	{
	cout << "********************************************************" << endl;
	cout << "                     ROOM: BEDROOM" << endl; 
	cout << "********************************************************" << endl;
	cout << endl;
	cout << "You wake up to an empty house. Your head aches terribly and you are extremely disoriented." << endl;
	cout << "You take a moment to listen and you hear nothing....absolutely nothing." << endl;
	cout << "As you jump out of bed, you trip over your backpack laying on the ground." << endl;
	cout << "You pick it up thinking that it may come in handy later." << endl;
	this->visited = true;//sets visited to true


	}
	
	else // if the user has already been here, there's no need to show the same expository text again
	{	cout << "********************************************************" << endl;
        	cout << "                     ROOM: BEDROOM" << endl;
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

void Bedroom::Look()
{
 		
	this->seeChair = true;	
	int lookChoice;
	if (this->seeRoom == false)
	{cout << "You look around the room and see a window and a closet." << endl;
	cout << "Oddly enough, there's a chair propped up against the door seemingly to serve as a lock." << endl;
	cout << endl;
	seeRoom = true;
	}
	
	cout << "Where would you like to look?" << endl;	
	cout << "1. Window " << endl;
	cout << "2. Closet" << endl;
	cin >> lookChoice;
	cout << endl;
	if (lookChoice == 1)
	{	
		cout << "Outside you see people off in the distance...they are moving awkwardly...almost shambling." << endl;
		cout << "Below the window, you see a bike." << endl;

	}

	else if (lookChoice == 2)
	{	if (gunTaken == false)
		{
		cout << "Inside the closet are your clothes, some hanging and some haphazardly strewn on the floor." << endl;
		cout << "At the bottom of the floor is a gun case...you might need this later." << endl; 
		}
		
		else //if the gun has been taken, the user will not see it again
		cout << "Inside the closet are your clothes, some hanging and some haphazardly strewn on the floor." << endl;
	
		seeGun = true;
	}
	
	else
	{	
		cout << "Not a valid choice. Pick again." << endl;
		Look();
	}
}	

/*********************************************************************
** Function: Use
** Description: gives the player to options to use *This is the special function
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: player can use items
*********************************************************************/

void Bedroom::Use()
{
	int useChoice;
	if (chairMoved == true) // the only thing to use in this room is the chair
        {	
                cout << "There is nothing else to use in this room." << endl;
 
        }
	if (seeChair == false)
	{	
		cout << "You don't see anything to use." << endl;
	}

	if (chairMoved == false && seeChair == true)
	{
		
	cout << "What will you use?" << endl;
	cout << "1. the chair" << endl;
	cin >> useChoice;
	
	if (useChoice == 1)
	{	cout << endl;
		chairMoved = true;
		cout << "You have moved the chair away from the door. You can leave now." << endl;

	}
	
	else
	{		
		cout << "Not a valid choice.";
						
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

Space* Bedroom::Leave()
{
	int leaveChoice;
	if (chairMoved == true)
	{
		 
        
                cout << "Where would you like to go?" << endl;
                cout << "1. Bathroom" << endl;
                cout << "2. Attic" << endl;
                cout << "3. Kitchen" << endl;
                cout << "4. Living Room" << endl;
		cin >> leaveChoice;
        	
		if (leaveChoice == 1)
                	return ptr2;
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
	
	else
	{	
		cout << "You can't leave! There's a chair blocking the door!" << endl; //player will not be allowed to leave unless they use the chair
                
                return NULL;
        }

}

/*********************************************************************
** Function: Take
** Description: allows player to take items from room and place in inventory
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: returns pointer to item
*********************************************************************/

Item* Bedroom::Take()
{
	int takeChoice;

	if (seeGun == false)
	{
		cout << "You don't see anything to take." << endl;	
		return NULL;
	}
	
	else
	{	if  (gunTaken == true)
		{	
			cout << "There is nothing more to take in this room." << endl;
			return NULL;
		}
		else
		{
		cout << "What will you take?" << endl;
		cout << "1. the gun" << endl; 
		cin >> takeChoice;
		}
		if(takeChoice == 1)
		{	gunTaken = true;
			return bedroomItems[0];
		}			
		
	}	
}




