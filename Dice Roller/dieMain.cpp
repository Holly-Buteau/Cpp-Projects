/*********************************************************************
 * ** Program Filename: dieMain.cpp
 * ** Author: Holly Buteau
 * ** Date: January 24, 2016
 * ** Description: main file for game
 * ** Input: none 
 * ** Output: none
 * *********************************************************************/



#include "game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(0));
	Game game;
	game.getRounds();
	game.getSides();
	game.getDieType();
	game.scoreCalculator();
	game.winner();


	return 0;
}
