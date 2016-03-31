/*********************************************************************
 * ** Program Filename: Creature.cpp
 * ** Author: Holly Buteau
 * ** Date: February 10, 2016
 * ** Description: source file for creature class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include <iostream>
#include <string>
using namespace std;

/*********************************************************************
 * ** Function: Creature::Creature
 * ** Description: default constructor for creatures
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: default values are set
 * *********************************************************************/


Creature::Creature()
{	
	string name = "";
	int armor = 0;
	int strength = 0;
	bool defeated = false;
	int score = 0;	
}


