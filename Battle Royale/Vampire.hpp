/*********************************************************************
 * ** Program Filename: Vampire.hpp
 * ** Author: Holly Buteau
 * ** Date: February 10. 2015
 * ** Description: header file for Vampire class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/


#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include <string>
#include "Creature.hpp"
using namespace std;

class Vampire : public Creature
{
public:
        Vampire();
	~Vampire();
        virtual int Attack();
        virtual int Defense();
        virtual void  Battle(Creature *c1);
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


