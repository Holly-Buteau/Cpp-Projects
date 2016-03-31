/*********************************************************************
** Program Filename: Kitchen.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: source file for kitchen class
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
** Function: Kitchen
** Description: default constructor
** Parameters: none
** Pre-Conditions: ohject created
** Post-Conditions: default values set
*********************************************************************/

Kitchen::Kitchen()
{
        this->dark = false;
        this->visited = false;
	this->seeNote = false;
	this->seeList = false;
	this->seeGoods = false;
	this->useList = false;
	this->foodTaken = false;
}

/*********************************************************************
** Function: ~Kitchen
** Description: desctructor
** Parameters: none
** Pre-Conditions: delete called
** Post-Conditions: deleted
*********************************************************************/

Kitchen::~Kitchen()
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

void Kitchen:: getPointers(Space *p1, Space *p2, Space *p3, Space *p4, Space *p5)
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

void Kitchen::Inventory(Item* item)
{
	kitchenItems.push_back(item);
 
}

/*********************************************************************
** Function: getVisited
** Description: returns whether room was visited
** Parameters: none
** Pre-Conditions: called in Player Class
** Post-Conditions: return boolean
*********************************************************************/

bool Kitchen::getVisited()
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

void  Kitchen::Start()
{
        if (this->visited == false) // if player hasn't been here before, show this
        {cout << "********************************************************" << endl;
   	cout << "                     ROOM: KITCHEN" << endl;
        cout << "********************************************************" << endl;
        cout << endl;
        cout << "You walk into the kitchen. Pots and pans are still on the stove. Mail is scattered around the table." << endl;
	cout << "You see the refrigerator with several magnets and notes attached to it." << endl;
	cout << "The pantry and cabinet doors are flung open as if someone was grabbing things in a hurry." << endl;
	this->visited = true; //sets visited to true

	}


        else // if the user has already been here, there's no need to show the same expository text again
        {	cout << "********************************************************" << endl;
        	cout << "                     ROOM: KITCHEN" << endl;
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

void Kitchen::Look()
{
        int lookChoice;
        
        cout << "Where would you like to look?" << endl;
        cout << "1. Refrigerator " << endl;
        cout << "2. Table" << endl;
        cout << "3. Cabinet" << endl;
        cout << "4. Pantry" << endl;
	cout << "5. Stove" << endl;
        cin >> lookChoice;
	cout << endl;
        if (lookChoice == 1)
        {
                cout << "On the refrigerator are magnets for local pizza places, a picture of you and your roommate Cameron, a note, and some kind of checklist." << endl;
                seeList = true;
		seeNote = true;
                
        }

        else if (lookChoice == 2)
        {
                cout << "On the table you see an assortment of bills, your cell phone, and a newspaper." << endl;
                cout << "The headline on the paper screams in bold font: APOCALYPSE NOW?" << endl;
		cout << "That's a really odd headline, the media is getting out of hand with sensationalist news." << endl;
		
        }

        else if (lookChoice == 3)
        {
                cout << "Inside the cabinets are dishes and cups. Nothing much else." << endl;
                
        }

        else if (lookChoice == 4)
        {	if (foodTaken == false)
                {cout << "The pantry is filled with nonperishable canned goods. They look like they are still good." << endl;
		seeGoods = true;
                }
		else //if the food has been taken, the user will not see it again
			cout << "It's empty." << endl;
        }
	
	else if (lookChoice == 5)
	{
		cout << "As you approach the stove, you are assulted by a terrible smell. Gross! Rotten food." << endl;
		
	}

        else
        {       cout << "Not a valid choice. Pick again." << endl;
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

void Kitchen::Use()
{
        int useChoice;

        
	if (seeNote == true && seeList == true)
	{
	cout << "What will you use?" << endl;
        cout << "1. the note" << endl;
	cout << "2. the checklist" << endl;
	cin >> useChoice;
	cout << endl;
	if (useChoice != 1 && useChoice != 2)
		cout << "Not a valid choice. Pick again.";

        if (useChoice == 1)
        {
                cout << "The note looks like it was written by Cameron judging by the chicken scratch handwriting." << endl;
		cout << "It looks like he wrote this in a hurry." << endl;
		cout << "Taylor," << endl;
		cout << "I'm sorry...they brought you home from the hospital....everything happened so fast..." << endl;
		cout << "I couldn't wake you...I'm so sorry.....I have to go get my mom...make sure that Katie is safe.." << endl;
		cout << "Get out! Get out as soon as you can...they're coming....leave...I left a list. Try to grab everything." << endl;
		cout << "That should keep you alive for awhile. If you make it through this, meet me at TJ's house." << endl;
		cout << "God....I tried to wake you....be safe man.....I hope I see you soon..." << endl;
		cout << " - C " << endl; 
                
        }
	
	if (useChoice == 2)
	{
		cout << "This is what you'll need. Be safe out there. Remember, meet me at TJ's house!." << endl;
		cout << "1. Food - nonperishable." << endl;
		cout << "2. Gun - try not to shoot. The noise attracts...them." << endl;
		cout << "3. First Aid Kit." << endl;
		cout << "4. Melee Weapon - no noise means no Zeds." << endl;
		cout << "5. Radio - to keep up with the news." << endl;
		useList = true;	
	}
	
                  
        
	}

	if (seeNote == false && seeList == false)
	
		cout << "You don't see anything to use." << endl;
}

/*********************************************************************
** Function: Leave
** Description: allows the player to choose where to go next
** Parameters: none
** Pre-Conditions: called in player class
** Post-Conditions: player leaves the room
*********************************************************************/

Space* Kitchen::Leave()
{
	int leaveChoice;
        if (useList == true)
        {


                cout << "Where would you like to go?" << endl;
                cout << "1. Bedroom" << endl;
                cout << "2. Bathroom" << endl;
                cout << "3. Attic" << endl;
                cout << "4. Living Room" << endl;
                cin >> leaveChoice;

                if (leaveChoice == 1)
                        return ptr1;
                else if (leaveChoice == 2)
                        return ptr2;
                else if (leaveChoice == 3)
                        return ptr3;
                else if (leaveChoice == 4)
                        return ptr5;


                else
        	{	cout << "Not a valid choice. Pick again." << endl;
			return NULL;
		}
         }

        else
        {
                cout << "You shouldn't leave yet, it looks like there's something important on the refrigerator." << endl; //player will not be allowed to leave unless they use the list

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

Item* Kitchen::Take()
{
        int takeChoice;

        if (seeGoods == false)
        {       cout << "You don't see anything to take." << endl;
		return NULL;
	}
                
        

	else
        {       if  (foodTaken == true)
                {       cout << "There is nothing more to take in this room." << endl;
                        return NULL;
                }

 	       else
        	{       cout << "What will you take?" << endl;
                	cout << "1. the nonperishable food" << endl;
                	cin >> takeChoice;
        		if(takeChoice == 1)
                	{       foodTaken = true;
                        	return kitchenItems[0];
                	}

		}


	}	
}
