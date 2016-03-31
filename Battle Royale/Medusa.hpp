/*********************************************************************
 * ** Program Filename: Medusa.hpp
 * ** Author: Holly Buteau
 * ** Date: February 10. 2015
 * ** Description: header file for Medusa class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/




#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
#include <string>
#include "Creature.hpp"
using namespace std;

class Medusa : public Creature
{
public:
        Medusa();
	~Medusa();
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


