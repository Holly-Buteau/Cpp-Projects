/*********************************************************************
** Program Filename: Attic.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: source file for attic class
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
** Function: Attic
** Description: default constructor
** Parameters: none
** Pre-Conditions: ohject created
** Post-Conditions: default values set
*********************************************************************/

Attic::Attic()
{
        this->dark = true;
        this->visited = false; //room has not been visited
	this->lightsOn = false; //user can't leave room until the light is on
	this->seeRadio = false;//user can't take the radio until they've seen it
	this->radioTaken = false;
	this->seeRoom = false;
}

/*********************************************************************
** Function: ~Attic
** Description: desctructor
** Parameters: none
** Pre-Conditions: delete called
** Post-Conditions: deleted
*********************************************************************/

Attic::~Attic()
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


void Attic:: getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5)
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

void Attic::Inventory(Item* item)
{
       atticItems.push_back(item);

}

/*********************************************************************
** Function: getVisited
** Description: returns whether room was visited
** Parameters: none
** Pre-Conditions: called in Player Class
** Post-Conditions: return boolean
*********************************************************************/

bool Attic::getVisited()
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

void  Attic::Start()
{
 	if (this->visited == false) // if player hasn't been here before, show this
        {cout << "********************************************************" << endl;
        cout << "                     ROOM: ATTIC" << endl;
        cout << "********************************************************" << endl;
        cout << endl;
        cout << "You pull down the attic door. As you climb the ladder, you realize it is dark. The lights are off." << endl;
	cout << "You can also hear the faint noise of music...what is making that noise?" << endl;
	this->visited = true; //sets visited to true

	}

        else // if the user has already been here, there's no need to show the same expository text again
        {
		cout << "********************************************************" << endl;
        	cout << "                     ROOM: ATTIC" << endl;
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

void Attic::Look()
{
        int lookChoice;
        if (lightsOn == false)
        {
                cout << "You can't see anything! The lights are off!" << endl;
  
        }
	
        if (lightsOn == true && seeRoom == false)
        {cout << "You look around the attic. There's not much up here. You see some boxes stacked in a corner." << endl;
	cout << "You also see the the source of the music. A small radio is propped up near the boxes playing the oldies station." << endl;
	seeRoom = true;
	cout << endl;
	}
	if (lightsOn == true && radioTaken == false)
        {cout << "Where would you like to look?" << endl;
        cout << "1. Boxes " << endl;
        cout << "2. Radio" << endl;
        cin >> lookChoice;
	cout << endl;
        if (lookChoice == 1)
        {
                cout << "Inside of the boxes you find old clothes, a couple of movies you haven't watched in forever, and book titled 'World War Z'. It probably belongs to Cameron." << endl;
               
        }

        else if (lookChoice == 2)
        {
                cout << "You pick the radio up as it starts playing 'Take On Me'. You think the music might attract some of those...things you saw outside." << endl;
		seeRadio = true;
        }

        else
        {       cout << "Not a valid choice. Pick again." << endl;	
		cout << endl;
 		Look();               
        }
        }

	if (lightsOn == true && radioTaken == true) //if the radio has been taken, the user will not see it again
	 {	cout << "Where would you like to look?" << endl;
        	cout << "1. Boxes " << endl;
		cin >> lookChoice;
	if (lookChoice == 1)
        {
                cout << "Inside of the boxes you find old clothes, a couple of movies you haven't watched in forever, and book titled 'World War Z'. It probably belongs to Cameron." << endl;

        }
	else
        {       cout << "Not a valid choice. Pick again." << endl;
        	cout << endl; 
	       Look();
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

void Attic::Use()
{
        int useChoice;

	if (seeRadio == false && lightsOn == true)
        {       cout << "You don't see anything to use." << endl;

        }	

	if (lightsOn == false)
        {cout << "What will you use?" << endl;
        cout << "1. the lightswitch" << endl;
	cin >> useChoice;

        if (useChoice == 1)
        {	cout << endl;
                lightsOn = true;
                cout << "Finally, a little light." << endl;
 
        }

        else
        {
                cout << "Not a valid choice. Pick again.";
 
	}
	}	
	if (seeRadio == true)
	{
		cout << "What will you use?" << endl;
        	cout << "1. the radio" << endl;
		cin >> useChoice;
	
	if (useChoice == 1)
        {	cout << endl;
                cout << "You turn the radio off and feel a little better now that the house is quiet." << endl;
        	useRadio = true;        
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

Space* Attic::Leave()
{
	if (useRadio == false)
	{
		cout << "You shouldn't let the noise continue. It could attract unwanted visitors." << endl; //player will not be allowed to leave unless they use the radio

		return NULL;	
	}
	else
	{int leaveChoice;
    	cout << "Where would you like to go?" << endl;
        cout << "1. Bedroom" << endl;
        cout << "2. Bathroom" << endl;
        cout << "3. Kitchen" << endl;
        cout << "4. Living Room" << endl;
        cin >> leaveChoice;

         if (leaveChoice == 1)
         	return ptr1;
	 else if (leaveChoice == 2)
		return ptr2;
	 else if (leaveChoice == 3)
		return ptr4;
	 else if (leaveChoice == 4)
		return ptr5;

         else
         {     	cout << "Not a valid choice. Pick again." << endl;
         
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

Item* Attic::Take()
{
        int takeChoice;

        if (seeRadio == false)
        {       cout << "You don't see anything to take." << endl;
		return NULL;	
	}
                
        
	
	else
	{
		if  (radioTaken == true)
                {       
			cout << "There is nothing more to take in this room." << endl;
                        return NULL;
                }

        	else
        	{      
			cout << "What will you take?" << endl;
                	cout << "1. the radio" << endl;
                	cin >> takeChoice;
        	
			if(takeChoice == 1)
        		{       radioTaken = true;
                		return atticItems[0];
                
        		}	
		}	
	}	
}

