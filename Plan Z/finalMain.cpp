/*********************************************************************
** Program Filename: fileMain.cpp
** Author: Holly Buteau
** Date: March 13, 2016
** Description: main for Plan Z
** Input: none
** Output: none
*********************************************************************/

#include "Space.hpp"
#include "Item.hpp"
#include "Bedroom.hpp"
#include "Attic.hpp"
#include "Bathroom.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Player.hpp"
#include <string>
using namespace std;

int main()
{
	int choice;
	cout << "**********************************************************************" << endl;
	cout << "                              PLAN Z" << endl;
	cout << "**********************************************************************" << endl;

	cout << "What would you like to do?" << endl;
	cout << "1. Play the game" << endl;
	cout << "2. View the cheat sheet" << endl;
	cout << "3. Credits" << endl;
	cout << "4. Quit" << endl;
	cin >> choice;

	if (choice == 1)
	{Player p1;
	Space *bedroom;
	Space *bathroom;
	Space *attic;
	Space *kitchen;
	Space *livingroom;
	Item *gun;
	Item *medicine;
	Item *radio;
	Item *food;
	Item *poker;
	food = new Item;
	poker = new Item;
	gun = new Item;
	medicine = new Item;
	radio = new Item;
	food->setName("food");
	poker->setName("poker");
	radio->setName("radio");
	gun->setName("gun");
	medicine->setName("medicine");
	bedroom = new Bedroom;
	bathroom = new Bathroom;
	attic = new Attic;
	kitchen = new Kitchen;
	livingroom = new LivingRoom;
	bedroom->Inventory(gun);
	attic->Inventory(radio);
	bathroom->Inventory(medicine);
	kitchen->Inventory(food);
	livingroom->Inventory(poker);
	kitchen->getPointers(bedroom, bathroom, attic, kitchen, livingroom);
	livingroom->getPointers(bedroom, bathroom, attic, kitchen, livingroom);
	bedroom->getPointers(bedroom, bathroom, attic, kitchen, livingroom);
	bathroom->getPointers(bedroom, bathroom, attic, kitchen, livingroom);
	attic->getPointers(bedroom, bathroom, attic, kitchen, livingroom);
	p1.setLocation(bedroom);
	p1.Menu();
	
	delete bedroom;
	delete bathroom;
	delete attic;
	delete livingroom;
	delete kitchen;
	delete poker;
	delete radio;
	delete food;
	delete gun;
	delete medicine;
	}

	if (choice == 2)
	{	int choice2;
		cout << "The goal of the game is to gather the following items:" << endl;
		cout << "A gun" << endl;
		cout << "A First Aid Kit" << endl;
		cout << "Food" << endl;
		cout << "A Radio" << endl;
		cout << "A Fireplace Poker" << endl;
		cout << endl;
		cout << "Here is the quickest way to complete the game:" << endl;
		cout << endl;
		cout << "Bedroom:" << endl;
		cout << "Look - Closet" << endl;
		cout << "Take - the gun" << endl;	
		cout << "Use - the chair" << endl;
		cout << "Leave" << endl;
		cout << endl;
		cout << "Bathroom:" << endl;
		cout << "Use - the lightswitch" << endl;
		cout << "Look - Medicine Cabinet" << endl;
                cout << "Take - the first aid kit" << endl;
                cout << "Leave" << endl;
		cout << endl;
		cout << "Attic:" << endl;
                cout << "Use - the lightswitch" << endl;
                cout << "Look - Radio" << endl;
		cout << "Use - the radio" << endl;
		cout << "Take - the radio" << endl;
                cout << "Leave" << endl;
		cout << endl;
		cout << "Kitchen:" << endl;
                cout << "Look - Refrigerator" << endl;
		cout << "Look - Pantry" << endl;
		cout << "Use - the list" << endl;
                cout << "Take - the nonperishable food" << endl;
                cout << "Leave" << endl;
                cout << endl;
		cout << "Living Room:" << endl;
                cout << "Look - TV" << endl;
		cout << "Look - the fireplace" << endl;
                cout << "Take - the poker" << endl;
                cout << "Use - the remote" << endl;
                cout << "Leave" << endl;
		cout << "DO NOT LIGHT A FIRE: THIS IS AUTOMATIC DEATH" << endl;
		cout << endl;
		cout << "Press 1 to return to main menu." << endl;
                cin >> choice2;
		main();
	}
	
					
	
	if (choice == 3)
	{	int choice3;
		cout << "Plan Z : a game by Holly Buteau" << endl;
		cout << endl;
		cout << "Press 1 to return to main menu." << endl;
		cin >> choice3;
		main();
	}

return 0;
} 
