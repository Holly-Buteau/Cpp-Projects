/*********************************************************************
 * ** Program Filename: Creature.hpp
 * ** Author: Holly Buteau
 * ** Date: February 10. 2016
 * ** Description: header file for creature class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/


#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string> 
#include <iostream>
using namespace std;

class Creature
{
protected:
	string name; 
	int armor;
	int strength;
	bool resurrected;
	int aRoll1;//attack roll
	int aRoll2; // additional attack roll since some creatures roll 2 dice.
	int dRoll1; // defense roll
	int dRoll2; //addition al defense roll for creatures rolling 2 dice
	int dRoll3;// 3rd defense roll for blue men
	int aTotal; //total for attack
	int dTotal; // total for defense
	bool defeated;
	int score;	//boolean to set if creatures are defeated
	
public:
	Creature();
	virtual void Battle(Creature *c1) = 0; //battle between 2 creatures
	virtual int Attack() = 0; // attack roll
	virtual int Defense() = 0; // defense roll
	virtual string getName() = 0;
	virtual int getArmor() = 0;
	virtual int getStrength() = 0;
	virtual bool getDefeated() = 0;
	virtual void damage(int aTotal, int dTotal) = 0; //calculates damage
	virtual void setDefeated() = 0;
	virtual void setName(string n) = 0;  
	virtual void heal() = 0;
	virtual void scoreIncrement() = 0;
};
#endif
