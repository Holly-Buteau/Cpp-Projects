/*********************************************************************
 * ** Program Filename: List.cpp
 * ** Author: Holly Buteau
 * ** Date: January 31, 2016
 * ** Description: source file for List class
 * ** Input: user's choice
 * ** Output: list and prices
 * *********************************************************************/


#include "List.hpp"
#include "Item.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

/*********************************************************************
 * ** Function: List
 * ** Description: default constructor
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/

List::List()
{
	itemArray = new Item*[4];
	arraySize = 3; //to account for indexes 
	numValues = 4; 
	arrayEnd = 0; //to keep track of the last value in the array
	counter = 0; //keeps track of total values in the array
}


/*********************************************************************
 * ** Function: ~List
 * ** Description: destructor
 * ** Parameters: none
 * ** Pre-Conditions: call for delete
 * ** Post-Conditions: itemArray is deleted
 * *********************************************************************/

List::~List()
{
	delete [] itemArray;
	arraySize = 0;
}

/*********************************************************************
 * ** Function: menu
 * ** Description: menu of choice for reader
 * ** Parameters: none
 * ** Pre-Conditions: call to menu from main
 * ** Post-Conditions: calls appropriate methods
 * *********************************************************************/

void List:: menu()
{
          int userChoice;
 
          cout << "What would you like to do?" << endl;
          cout << "1: Add an item" << endl;
          cout << "2: Remove an item" << endl;
          cout << "3: Print the shopping list" << endl;
          cout << "4: Quit" << endl;
          cin >> userChoice;
 
          if (userChoice == 1)
                  getItems();
	  if (userChoice == 2)
	 	removeItem();
          if (userChoice == 3)
                 displayArray();
 }

/*********************************************************************
 * ** Function: getItems
 * ** Description: fills the array with items for the list
 * ** Parameters: none
 * ** Pre-Conditions: user choses to add items
 * ** Post-Conditions: items sent to addItems
 * *********************************************************************/

void List::getItems()
{	List list;
	check = false; //boolean for checking if item already exists
		
	cout << "Please enter Item name. ";
	cin.clear();
	cin.ignore();
	getline(cin, itemName);

	cout << "Please enter Item unit, ";
	cin.clear();
	getline(cin, unit);

	cout << "Please enter the number you want to buy. ";
	cin >> numToBuy;

	cout << "Please enter the unit price. ";
	cin >> unitPrice;

	Item *nItem = new Item(itemName, unit, numToBuy, unitPrice); //new item
	
	
	for (int j = 0; j < counter; j++)
	{
		if (*nItem == *itemArray[j]) //if it is already in list
			{
				cout << "Item already in list" << endl;	
				check = true;
				break;
			}
 	}
		
	if (check == false) // if not in list
	{	addItems(nItem);
		nItem = NULL;
	}

menu();
	

}

/*********************************************************************
 * ** Function: addItems
 * ** Description: adds items to the array
 * ** Parameters: pointer to items
 * ** Pre-Conditions: items were created by user
 * ** Post-Conditions: items are palced in array
 * *********************************************************************/

void List::addItems(Item *item)
{

	if (counter < arraySize) // testing to see if array is full
	{
		itemArray[counter] = item;
		counter++;
	}

	else
	{
		arraySize = (arraySize * 2); //creating new array
		Item **newArray; 
		newArray = new Item*[arraySize];
		for (int count = 0; count < counter; count++) //copying old array into new array
			newArray[count] = itemArray[count]; 
		
		delete[] itemArray; //deleting old array
		itemArray = NULL; //old array is empty
		itemArray = newArray; //so we can continue using the call to itemArray
		itemArray[counter] = item;
		counter++;
		newArray = NULL;
	}

	

}

/*********************************************************************
 * ** Function: displayArray
 * ** Description: displays items and prices for user
 * ** Parameters: none
 * ** Pre-Conditions: array has been filled and prices calculated
 * ** Post-Conditions: displays array and prices for user
 * *********************************************************************/

void List::displayArray()
{
        for (int x = 0; x < counter; x++)
	{	
        cout << "Item is: " << itemArray[x]->getItemName() << endl;
	cout << endl;
	cout << "Unit is: " << itemArray[x]->getUnit() << endl;
	cout << endl;
	cout << "Unit Price is: " << itemArray[x]->getUnitPrice() << endl;
	cout << endl;
	cout << "Number to Buy is: " << itemArray[x]->getNumToBuy() << endl;
	cout << endl;
	cout << "Extended Price is: " << (itemArray[x] -> getNumToBuy() * itemArray[x] -> getUnitPrice()) << endl;
	cout << endl; 
}
	cout << "Total cost is: " << calculateTotal() << endl;
	
menu();
}

/*********************************************************************
 * ** Function: removeItem
 * ** Description: allows user to remove item from array
 * ** Parameters: none
 * ** Pre-Conditions: array is filled, user chooses what to remove
 * ** Post-Conditions: item is removed
 * *********************************************************************/


void List::removeItem()
{	int itemRemove;
	//I found it easier to just ask for the index
	cout << "Name the index of the item you want to remove" << endl;	
	cin >> itemRemove;
	for (int i = itemRemove; i < counter; i++)
		itemArray[i] = itemArray[i + 1]; //shifts all items in aray
	
	itemArray[counter] = NULL; //last item is NULL to prevent repeats
	arraySize--;
	counter--;
menu();
}

/*********************************************************************
 * ** Function: calculateTotal
 * ** Description: calculates the total price of the list
 * ** Parameters: none
 * ** Pre-Conditions: array filled
 * ** Post-Conditions: price is returned to be displayed
 * *********************************************************************/

double List::calculateTotal()
{	double total = 0;
	double extendedPrice = 0;
	
	for (int x = 0; x < counter; x++)
	{
	extendedPrice = (itemArray[x] -> getNumToBuy() * itemArray[x] -> getUnitPrice()); 
	total = total + extendedPrice;
	} 

	return total;

}



		
		
