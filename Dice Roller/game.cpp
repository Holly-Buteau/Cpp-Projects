/*********************************************************************
 * ** Program Filename: game.cpp
 * ** Author: Holly Buteau
 * ** Date: January 24, 2016
 * ** Description: source file for the game class
 * ** Input: die type, number of sides on die 
 * ** Output: winner of game
 * *********************************************************************/



#include "game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*********************************************************************
 * ** Function: get rounds
 * ** Description: gets number of rounds from player
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: number of rounds taken in
 * *********************************************************************/


void Game::getRounds()
{
	cout << "How many rounds do you want to play?" << endl;
	cin >> numRounds;
}

/*********************************************************************
 * ** Function: getdietype
 * ** Description: gets the type of die (loaded or not)
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: type of die taken in
 * *********************************************************************/

void Game::getDieType()
{
	Die player1(numSides1);
	Die player2(numSides2);
	LoadedDie Lplayer1(numSides1);
	LoadedDie Lplayer2(numSides2);


	cout << "What type of die for player 1? " << endl;
	cout << "1: Regular Die " << endl;
	cout << "2: Loaded Die " << endl;
	cin >> dieType1;

        //validates user input
	if (dieType1 < 1 || dieType1 > 2)
	{
		cout << "Invalid choice, please choose again.";
		getDieType();
	}

	cout << "What type of die for player 2? " << endl;
	cout << "1: Regular Die " << endl;
	cout << "2: Loaded Die " << endl;
	cin >> dieType2;
        //validates user input
	if (dieType2 < 1 || dieType2 > 2)
	{
		cout << "Invalid choice, please choose again.";
		getDieType();
	}

	
}


/*********************************************************************
 * ** Function: getSides
 * ** Description: gets number of sides on the die
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: number of sides taken in
 * *********************************************************************/

void Game::getSides()
{           
	cout << "How many sides on the die for player 1? " << endl;
	cout << "1: 4 sides" << endl;
	cout << "2: 6 sides" << endl;
	cout << "3: 8 sides" << endl;
	cout << "4: 10 sides" << endl;
	cout << "5: 12 sides" << endl;
	cout << "6: 20 sides" << endl;
	cin >> numChoice1;

	if (numChoice1 == 1)
		numSides1 = 4;
	if (numChoice1 == 2)
		numSides1 = 6;
	if (numChoice1 == 3)
		numSides1 = 8;
	if (numChoice1 == 4)
		numSides1 = 10;
	if (numChoice1 == 5)
		numSides1 = 12;
	if (numChoice1 == 6)
		numSides1 = 20;


	cout << "How many sides on the die for player 2? " << endl;
	cout << "1: 4 sides" << endl;
	cout << "2: 6 sides" << endl;
	cout << "3: 8 sides" << endl;
	cout << "4: 10 sides" << endl;
	cout << "5: 12 sides" << endl;
	cout << "6: 20 sides" << endl;
	cin >> numChoice2;

	if (numChoice2 == 1)
		numSides2 = 4;
	if (numChoice2 == 2)
		numSides2 = 6;
	if (numChoice2 == 3)
		numSides2 = 8;
	if (numChoice2 == 4)
		numSides2 = 10;
	if (numChoice2 == 5)
		numSides2 = 12;
	if (numChoice2== 6)
		numSides2 = 20;
}


/*********************************************************************
 * ** Function: scoreCalculator
 * ** Description: calcualtes the score
 * ** Parameters: none
 * ** Pre-Conditions: die type and number of sides
 * ** Post-Conditions: score is calculated
 * *********************************************************************/

void Game::scoreCalculator()
{
	Die player1(numSides1);
	Die player2(numSides2);
	LoadedDie Lplayer1(numSides1);
	LoadedDie Lplayer2(numSides2);
	score1 = 0;
	score2 = 0;
	int p1Roll = player1.roll();
	int p2Roll = player2.roll();
	int p1count; //temporarily holds roll for comparison
	int p2count; //temporarily holds roll for comparison

	
	
	
	cout << "Player 1 die type is " << numSides1 << endl;


	cout << "Player 2 die type is " << numSides2 << endl;

	for (int x = 0; x < numRounds; x++)
	{
		if (dieType1 == 1)
		{
			p1count = player1.roll();
			cout << "Player 1 rolled: " << p1count << endl;
			
		}

		

		if (dieType1 == 2)
		{
			p1count = Lplayer1.loadedRoll();
			cout << "Player 1 rolled: " << p1count << endl;
			
		}

		if (dieType2 == 1)
		{
			p2count = player2.roll();
			cout << "Player 2 rolled: " << p2count << endl;
			
		}

               

		if (dieType2 == 2)
		{
			p2count = Lplayer2.loadedRoll();
			cout << "Player 2 rolled: " << p2count << endl;
		}


		if (p1count > p2count)
			score1++;

		if (p2count > p1count)
			score2++;
			
		
	}




	cout << "Score 1: " << score1 << endl;
	cout << "Score 2: " << score2 << endl;

	//outputs if player uses loaded die
	if (dieType1 == 2)
		cout << "Player 1 used a loaded die!" << endl;
	



	if (dieType2 == 2)
		cout << "Player 2 used a loaded die!" << endl;


}


/*********************************************************************
 * ** Function: winner
 * ** Description: outputs the Winner
 * ** Parameters: none
 * ** Pre-Conditions: score is calculated
 * ** Post-Conditions: winner is outputted
 * *********************************************************************/


void Game::winner()
{
	if (score1 > score2)
		cout << "Player 1 wins!";

	if (score1 < score2)
		cout << "Player 2 wins!";

	if (score1 == score2)
		cout << "A Tie!";
}
