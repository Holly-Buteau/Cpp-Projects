/*********************************************************************
 * ** Program Filename: HarryPotter.cpp
 * ** Author: Holly Buteau
 * ** Date: February 10. 2015
 * ** Description: header file for Harry Potter class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
using namespace std;

class HarryPotter : public Creature
{
public:
        HarryPotter();
	~HarryPotter();
        virtual int Attack();
        virtual int Defense();
        virtual void Battle(Creature *c1);
        virtual string getName();
	virtual int getArmor();
        virtual int getStrength();
        virtual bool getDefeated();
        virtual void damage(int aTotal, int dTotal);
        virtual void setDefeated();	
	virtual void setName(string n);
	virtual void heal();
	virtual void scoreIncrement();
};
#endif

