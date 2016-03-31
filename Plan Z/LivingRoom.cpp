/*********************************************************************
** Program Filename: LivingRoom.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: source file for livingroom class
** Input: none
** Output: none
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "LivingRoom.hpp"
#include "Space.hpp"
using namespace std;

/*********************************************************************
** Function: LivingRoom
** Description: default constructor
** Parameters: none
** Pre-Conditions: ohject created
** Post-Conditions: default values set
*********************************************************************/

LivingRoom::LivingRoom()
{
        this->dark = false;
        this->visited = false;
	this->seePoker = false;
	this->seeRemote =false;
	this->pokerTaken = false;
	this->tvUsed = false;
}

/*********************************************************************
** Function: ~LivingRoom
** Description: desctructor
** Parameters: none
** Pre-Conditions: delete called
** Post-Conditions: deleted
*********************************************************************/

LivingRoom::~LivingRoom()
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

void LivingRoom:: getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5)
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

void LivingRoom::Inventory(Item* item)
{
        livingroomItems.push_back(item);
}

/*********************************************************************
** Function: getVisited
** Description: returns whether room was visited
** Parameters: none
** Pre-Conditions: called in Player Class
** Post-Conditions: return boolean
*********************************************************************/

bool LivingRoom::getVisited()
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

void  LivingRoom::Start()
{
	
        if (this->visited == false) // if player hasn't been here before, show this
        {
	cout << "********************************************************" << endl;
        cout << "                     ROOM: LIVING ROOM" << endl;
        cout << "********************************************************" << endl;
        cout << endl;
        cout << "As you walk into the living room you see a tv mounted on the wall above a fireplace, a coffee table, and chairs arranged around it." << endl;
	cout << "There are posters arranged around the room, some are movies and others are bands. None of this has been professionally decorated." << endl;
	this->visited = true;//sets visited to true

	}
	

        else// if the user has already been here, there's no need to show the same expository text again
	{
	    	cout << "********************************************************" << endl;
        	cout << "                     ROOM: LIVING ROOM" << endl;
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

void LivingRoom::Look()
{
        int lookChoice;
        
        cout << "Where would you like to look?" << endl;
        cout << "1. Posters on the wall " << endl;
        cout << "2. Fireplace" << endl;
        cout << "3. TV " << endl;
        cout << "4. Coffee Table" << endl;
        cin >> lookChoice;
	cout << endl;
        if (lookChoice == 1)
        {
                cout << "You see 3 posters on the wall:  Shaun of the Dead, Pulp Fiction, and a concert poster for some guy named Jonathan Coulton ." << endl;
                
        }

        else if (lookChoice == 2)
        {
                cout << "The fireplace looks like it gets used in the winter. Soot lines the bottom tiles." << endl;
                if (pokerTaken == false) //if the poker has been taken, the user will not see it again
		{cout << "Next to the fireplace is a firepoker. It looks heavy and sharp." << endl;
		seePoker = true;
                }
        }

        else if (lookChoice == 3)
        {
                cout << "The tv is a decent sized flat screen. A remote sits on the mantle nearby." << endl;
		seeRemote = true;
                
        }
        else if (lookChoice == 4)
        {
                cout << "The coffee table looks like it has seen better days. Obviously you don't use coasters." << endl;
        }

        else
        {       cout << "Not a valid choice. Pick again." << endl;
                        
        }
}

/*********************************************************************
** Function: Use
** Description: gives the player to options to use *This is the special function
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: player can use items
*********************************************************************/

void LivingRoom::Use()
{
	//if the user uses the fireplace, they automatically lose
        int useChoice;
	if (seeRemote == true && seePoker == true)
        {cout << "What will you use?" << endl;
        cout << "1. the remote" << endl;
	cout << "2. the fireplace" << endl;
	cin >> useChoice;
 	cout << endl;       
	if (useChoice != 1 || useChoice != 2)
		cout << "Not a valid choice. Pick again." << endl;

	if (useChoice == 1)
        {
                cout << "When you turn on the tv, it seems as if every channel is broadcasting the news." << endl;
		cout << "A panicked newcaster is attempting to deliver information. " << endl;
		cout << "'...I repeat, lock all your doors. Do not attempt contact with an infected.'" << endl;
		cout << "'If you have been bitten, please isolate yourself. If a loved one has been bitten, isolate them immediately.'" << endl;
		cout << "'Do not, I repeated DO NOT attempt to go to the hospital...all emergency services have been suspended.'" << endl;
		cout << "As the newscaster relayed all this information, you could hear a steady banging coming from the newsroom." << endl;
		cout << "Suddenly, you hear a door smash open and the camera operator swivels to reveal....you don't understand what you're seeing." << endl;
		cout << "Are those....decaying bodies?? Surely this is some April Fool's Day stunt." << endl;
		cout << "As you are thinking this, one of the creatures bites into the anchorwoman and you see another shamble toward the camera before everything cuts out." << endl;
		cout << "All you're getting now is the emergency broadcast signal....so weird." << endl;
                tvUsed = true;
        }
	
	if (useChoice == 2)
	{	cout << endl;
		cout << "You light the fire and lay back on the couch." << endl;
		cout << "As you are reminiscing about last winter, you hear a pounding at the door and windows." << endl;
		cout << "You jolt up and glance at the window in time to see one of the infected breaking it open and crawling inside." << endl;
		cout << "As it lurches toward you, you are struck with realization that the fire was a terrible idea.... " << endl;
		cout << "You've broadcasted your location to every one of those things nearby." << endl;
		cout << "As the thing bites down on you, your last thought is to wonder....what the hell happened here?" << endl;
		cout << "YOU HAVE DIED. GAME OVER." << endl;
		exit(EXIT_SUCCESS);
	
	}
	
     
        }
	
	
	if (seeRemote == true && seePoker == false)
	{
		cout << "What will you use?" << endl;
        	cout << "1. the remote" << endl; 
		cin >> useChoice;
		
        if (useChoice == 1)
        {
                cout << "When you turn on the tv, it seems as if every channel is broadcasting the news." << endl;
                cout << "A panicked newcaster is attempting to deliver information. " << endl;
                cout << "'...I repeat, lock all your doors. Do not attempt contact with an infected.'" << endl;
                cout << "'If you have been bitten, please isolate yourself. If a loved one has been bitten, isolate them immediately.'" << endl;
                cout << "'Do not, I repeated DO NOT attempt to go to the hospital...all emergency services have been suspended.'" << endl;
                cout << "As the newscaster relayed all this information, you could hear a steady banging coming from the newsroom." << endl;
                cout << "Suddenly, you hear a door smash open and the camera operator swivels to reveal....you don't understand what you're seeing." << endl;
                cout << "Are those....decaying bodies?? Surely this is some April Fool's Day stunt." << endl;
                cout << "As you are thinking this, one of the creatures bites into the anchorwoman and you see another shamble toward the camera before everything cuts out." << endl;
                cout << "All you're getting now is the emergency broadcast signal....so weird." << endl;
                
        }
	else
        {
                cout << "Not a valid choice. Pick again.";
        }
        }

	if (seeRemote == false && seePoker == true)
	{cout << "What will you use?" << endl;
        cout << "1. the fireplace" << endl;
        cin >> useChoice;
	cout << endl;
	if (useChoice == 1)
        {
                cout << "You light the fire and lay back on the couch." << endl;
                cout << "As you are reminiscing about last winter, you hear a pounding at the door and windows." << endl;
                cout << "You jolt up and glance at the window in time to see one of the infected breaking it open and crawling inside." << endl;
                cout << "As it lurches toward you, you are struck with realization that the fire was a terrible idea.... " << endl;
                cout << "You've broadcasted your location to every one of those things nearby." << endl;
                cout << "As the thing bites down on you, your last thought is to wonder....what the hell happened here?" << endl;
                cout << "YOU HAVE DIED. GAME OVER." << endl;
		exit(EXIT_SUCCESS);
        }

        else
        {
                cout << "Not a valid choice. Pick again.";
                
        }
        }
	
	if (seeRemote == false && seePoker == false)
	{
		cout << "You don't see anything to use." << endl;
		
	}

}

/*********************************************************************
** Function: Leave
** Description: allows the player to choose where to go next
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: player leaves the room
*********************************************************************/

Space* LivingRoom::Leave()
{
        int leaveChoice;
        if (tvUsed == true)
        {


                cout << "Where would you like to go?" << endl;
                cout << "1. Bedroom" << endl;
                cout << "2. Bathroom" << endl;
                cout << "3. Attic" << endl;
                cout << "4. Kitchen" << endl;
                cin >> leaveChoice;
		cout << endl;
                if (leaveChoice == 1)
                        return ptr1;
                else if (leaveChoice == 2)
                        return ptr2;
                else if (leaveChoice == 3)
                        return ptr3;
                else if (leaveChoice == 4)
                        return ptr4;


                else
         	{
		    	cout << "Not a valid choice. Pick again." << endl;
			return NULL;
		}
         }

        else
        {
                cout << "You shouldn't leave yet, there might be something on TV to explain what's going on." << endl; //player will not be allowed to leave unless they use the remote

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

Item* LivingRoom::Take()

{
        int takeChoice;

        if (seePoker == false)
        {       cout << "You don't see anything to take." << endl;
		return NULL;
                
        }

        else
        {       
		 if  (pokerTaken == true)
                {       cout << "There is nothing more to take in this room." << endl;
                        return NULL;
                }

		cout << "What will you take?" << endl;
                cout << "1. the fireplace poker" << endl;
                cin >> takeChoice;
		 if(takeChoice == 1)
                {       pokerTaken = true;
                        return livingroomItems[0];
                }

        }

}



