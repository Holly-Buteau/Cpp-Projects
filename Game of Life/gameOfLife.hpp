/********************************************************************
** Program Filename: gameOfLife.hpp
** Author: Holly Buteau
** Date: January 14, 2016
** Description: everchanging game displaying "life" and "death" of cells
** Input: starting x and y coordinates, choice of pattern
** Output: displays a changing pattern of cells
*********************************************************************/

#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


class GameofLife
{

private:
	int choice;
	int xCoord;
	int yCoord;
	
public:
	void reproduction();
	void setChoice(int c);
	void setXCoord(int x);
	void setYCoord(int y);
	void arrayBuilder();
	void pattern(int choice, int xCoord, int yCoord);
	void displayArray();
	GameofLife(int choice, int xCoord, int yCoord);

};


#endif
