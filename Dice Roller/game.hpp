/*********************************************************************
 * ** Program Filename: game.hpp
 * ** Author: Holly Buteau
 * ** Date: January 24, 2016
 * ** Description: header file for the game class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/


#ifndef GAME_HPP
#define GAME_HPP
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Game
{
private:
	int numRounds;
	int score1;
	int score2;
	int dieType1;
	int dieType2;
	int numSides1;
	int numSides2;
	int numChoice1;
	int numChoice2;

public:
	void getSides();
	void getRounds();
	void getDieType();
	void getRoll(int numRolled);
	void scoreCalculator();
	void winner();

};
#endif
