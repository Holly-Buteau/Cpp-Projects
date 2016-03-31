#include "gameOfLife.hpp"

/*********************************************************************
 * ** Program Filename: gameOfLife.cpp
 * ** Author: Holly Buteau
 * ** Date: January 14, 2016
 * ** Description: everchanging game displaying "life" and "death" of cells
 * ** Input: starting x and y coordinates, choice of pattern
 * ** Output: displays a changing pattern of cells
 * *********************************************************************/

int lifeArray[200][200]; //the current array that will be displayed
int futureArray[200][200]; //the array that accepts changes and 
			//modifies the display


/*********************************************************************
 * ** Function: GameofLife constructor
 * ** Description: Constructor that makes private variables accessible 
 * ** Parameters: 3 ints: player choice, starting x
 * ** coordinate and starting y coordinate
 * ** Pre-Conditions: none
 * ** Post-Conditions: private variables are accessible 
 * *********************************************************************/

GameofLife::GameofLife(int c, int x, int y)
{
	setChoice(c);
	setXCoord(x);
	setYCoord(y);
}

/*********************************************************************
 * ** Function: setChoice
 * ** Description: sets choice to int c
 * ** Parameters: int of player's choice
 * ** Pre-Conditions: player makes a choice
 * ** Post-Conditions: choice is now accessible 
 * *********************************************************************/

void GameofLife::setChoice(int c)
{
	choice = c;
}

/*********************************************************************
 * ** Function: setXCoord
 * ** Description: sets xCoord to int x
 * ** Parameters: int of starting x coordinate
 * ** Pre-Conditions: player decides starting x coordinate
 * ** Post-Conditions: xCoord is now accessible
 * *********************************************************************/
void GameofLife::setXCoord(int x)
{
	xCoord = x;
}

/*********************************************************************
 * ** Function: setYCoord
 * ** Description: sets yCoord to int y
 * ** Parameters: int of starting y coordinate
 * ** Pre-Conditions: player decides starting y coordinate
 * ** Post-Conditions: yCoord is now accessible
 * *********************************************************************/

void GameofLife::setYCoord(int y)
{
	yCoord = y;
}

/*********************************************************************
 * ** Function: arrayBuilder
 * ** Description: creates a 30 x 50 array of 1s
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: array is now created to manipulate
 * *********************************************************************/

void GameofLife::arrayBuilder()
{

	for (int x = 0; x < 200; x++) //x-1 and y-1 is so the edged
				      // of the array do not read
				      // their boundaries 
	{	
		for (int y = 0; y < 200; y++)
		{
			lifeArray[x][y] = 1;
		}	
	} 
}

/*********************************************************************
 * ** Function: pattern
 * ** Description: creates the chosen pattern to send to the array
 * ** Parameters: 3 ints: player choice, starting x coordinate and starting y
 * coordinate
 * ** Pre-Conditions: player has made all choices regarding game
 * ** Post-Conditions: pattern is now ready to manipulate
 * *********************************************************************/

void GameofLife::pattern(int choice, int xCoord, int yCoord)
{ //the number 7 will designate the starting point to the user

	if (choice == 1)
	{	// oscillator pattern
		lifeArray[xCoord][yCoord] = 7;  
		lifeArray[xCoord + 1][yCoord]= 0;
		lifeArray[xCoord - 1][yCoord] = 0;
	}

	if (choice == 2)
	{       //glider pattern
		lifeArray[xCoord][yCoord] = 7;
		lifeArray[xCoord - 1][yCoord] = 0;
		lifeArray[xCoord - 2][yCoord - 1] = 0;
		lifeArray[xCoord][yCoord - 1] = 0;
		lifeArray[xCoord][yCoord - 2] = 0;

	}

	if (choice == 3)
	{       //glider canon pattern
		lifeArray[xCoord][yCoord] = 7;
		lifeArray[xCoord + 1][yCoord] = 0;
		lifeArray[xCoord + 1][yCoord + 1] = 0;
		lifeArray[xCoord][yCoord + 1] = 0;
		lifeArray[xCoord - 1][yCoord - 10] = 0; 
		lifeArray[xCoord - 2][yCoord - 10] = 0;
		lifeArray[xCoord + 3][yCoord - 10] = 0;
		lifeArray[xCoord + 4][yCoord - 10] = 0;
		lifeArray[xCoord - 1][yCoord - 10] = 0;
		lifeArray[xCoord + 3][yCoord - 12] = 0;
		lifeArray[xCoord - 1][yCoord - 12] = 0;
		lifeArray[xCoord][yCoord - 13] = 0;
		lifeArray[xCoord + 1][yCoord - 13] = 0;
		lifeArray[xCoord + 2][yCoord - 13] = 0;
		lifeArray[xCoord][yCoord - 14] = 0;
		lifeArray[xCoord + 1][yCoord - 14] = 0;
		lifeArray[xCoord + 2][yCoord - 14] = 0;
		lifeArray[xCoord + 3][yCoord - 17] = 0;
		lifeArray[xCoord + 3][yCoord - 18] = 0;
		lifeArray[xCoord + 4][yCoord - 18] = 0;
		lifeArray[xCoord + 2][yCoord - 18] = 0;
		lifeArray[xCoord + 1][yCoord - 19] = 0;
		lifeArray[xCoord][yCoord - 21] = 0;
		lifeArray[xCoord][yCoord - 22] = 0;
		lifeArray[xCoord + 1][yCoord - 23] = 0;
		lifeArray[xCoord + 2][yCoord - 24] = 0;
		lifeArray[xCoord + 3][yCoord - 24] = 0;
		lifeArray[xCoord + 4][yCoord - 24] = 0;
		lifeArray[xCoord + 5][yCoord - 23] = 0;
		lifeArray[xCoord + 6][yCoord - 22] = 0;
		lifeArray[xCoord + 6][yCoord - 21] = 0;
		lifeArray[xCoord + 5][yCoord - 19] = 0;
		lifeArray[xCoord + 3][yCoord - 20] = 0;
		lifeArray[xCoord + 3][yCoord - 33] = 0;
		lifeArray[xCoord + 2][yCoord - 33] = 0;
		lifeArray[xCoord + 2][yCoord - 34] = 0;
		lifeArray[xCoord + 3][yCoord - 34] = 0;
	}
}

/*********************************************************************
 * ** Function: reproduction
 * ** Description: executes the rules of Game of Life.
 * ** Parameters: none
 * ** Pre-Conditions: player has made all choices regarding game, array is
 * built, and pattern has been built.
 * ** Post-Conditions: displays the game and all of it's changes
 * *********************************************************************/
void GameofLife::reproduction()
{
	for (int x = 0; x < 200; x++)
	{
		for (int y = 0; y < 200; y++)
		{

			int count = 0;
			if (lifeArray[x][y - 1] != 1) /*this is cycling through all*/
				count++;	     /*8 neighbors to check for*/
			if (lifeArray[x - 1][y - 1] != 1) /*live and dead cells*/
				count++;
			if (lifeArray[x + 1][y - 1] != 1)
				count++;
		    	if (lifeArray[x - 1][y] != 1)
				count++;
			if (lifeArray[x + 1][y] != 1)
				count++;
			if (lifeArray[x - 1][y + 1] != 1)
				count++;
			if (lifeArray[x][y + 1] != 1)
				count++;
			if (lifeArray[x + 1][y + 1] != 1)
				count++;
			
			futureArray[x][y] = lifeArray[x][y];
			
			if (lifeArray[x][y] == 1) // if cell is dead and it has
			{			 //// 3 live neighbors, it is now alive
				if (count == 3)
				{
					futureArray[x][y] = 0;
				}
			}
	
			if (lifeArray[x][y] != 1) // if a cell is alive and 
						 //// it has 1 or fewer neighbors it dies
			{
				if (count <= 1)
				{
					
					futureArray[x][y] = 1;
				}
				if (count > 3)// if a cell is 
					     //alive and it has more than
					     // 3 neighbors, it dies
				{
					futureArray[x][y] = 1;
				}
			}
		}
		
	} 
	
	for (int x = 0; x < 200; x++)// copy futureArray to lifeArray
	{		
		for (int y = 0; y < 200; y++)
			lifeArray[x][y] = futureArray[x][y];
	}
  	

}

/*********************************************************************
 * ** Function: displayArray
 * ** Description: displays the new array to the user
 * ** Parameters: none
 * ** Pre-Conditions: all changes have been made to cells
 * ** Post-Conditions: array is now viewable to user
 * *********************************************************************/


void GameofLife::displayArray()
{
	for (int x = 90; x < 110; x++)
	{
		for (int y = 80; y < 120; y++)
		{

			cout << lifeArray[x][y];

		}
		cout << endl;
	}
	sleep(1);
	system("clear");
	

	int z;
	z = 0;
	while (z < 50)
	{
		reproduction();
		
		
		for (int x = 90; x < 110; x++)
		{
			for (int y = 80; y < 120; y++)
			{

				cout << lifeArray[x + 1][y + 1];
				
			}
			cout << endl;
		}
		sleep(1); 
		system("clear");
		
		cout << endl;
		z++;
	}
}		
