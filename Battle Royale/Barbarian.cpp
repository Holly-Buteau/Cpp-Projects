/*********************************************************************
 *  ** Program Filename: Barbarian.cpp
 *  ** Author: Holly Buteau
 *  ** Date: February 10. 2015
 *  ** Description: source file for Barbarian class
 *  ** Input: none
 *  ** Output: none
 *********************************************************************/



#include "Barbarian.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

/*********************************************************************
 * ** Function: Barbarian::Barbarian
 * ** Description: default constructor for Barbarian
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: Barbarian default values are set
 * *********************************************************************/


Barbarian::Barbarian() : Creature()
{
	this->armor = 0;
	this->strength =12;
	this->name = "Barbarian";
	this->defeated = false;
	this->score = 0;
}

/*********************************************************************
 * ** Function: Barbarian::~Barbarian
 * ** Description: destructor for Barbariam
 * ** Parameters: none
 * ** Pre-Conditions: delete is called
 * ** Post-Conditions: barbarian is deleted
 * *********************************************************************/


Barbarian::~Barbarian()
{
	delete this;
}

/*********************************************************************
 * ** Function: Barbarian::heal
 * ** Description: restores barbarian health
 * ** Parameters: none
 * ** Pre-Conditions: heal is called in main
 * ** Post-Conditions: barbariam regains some health
 * *********************************************************************/


void Barbarian::heal()
{
     int healthDifference;
     healthDifference = 12 - this->strength;
     this->strength = this->strength + (rand() % healthDifference + 1);
}

/*********************************************************************
 * ** Function: Barbarian::scoreIncrement
 * ** Description: increments score of creature
 * ** Parameters: none
 * ** Pre-Conditions: scoreIncrement is called in main
 * ** Post-Conditions: creature score increses by 1;
 * *********************************************************************/

void Barbarian::scoreIncrement()
{
        this->score++;
}


/*********************************************************************
 ** Function: setName
 ** Description: sets name to be passed string
 ** Parameters: string n
 ** Pre-Conditions: called in main
 ** Post-Conditions: assigns creature name
 *********************************************************************/


void Barbarian::setName(string n)
{
        this->name = n;
}

/*********************************************************************
 ** Function: getName
 ** Description: returns name of creature
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns creature name
 *********************************************************************/


string Barbarian::getName()
{
	return this->name;
}

/*********************************************************************
 ** Function: getArmor
 ** Description: returns armor value of a creature
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns armor value
 *********************************************************************/

int Barbarian::getArmor()
{
	return armor;
}

/*********************************************************************
 ** Function: getStrength
 ** Description: returns strength of creature
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns creature srength
 *********************************************************************/


int Barbarian::getStrength()
{
	return strength;
}

/*********************************************************************
 ** Function: getDefeated
 ** Description: returns bool of whether creature is defeated or not
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns bool of whether creature is defeated or not
  *********************************************************************/


bool Barbarian::getDefeated()
{
	return defeated;
}


/*********************************************************************
 ** Function: setDefeated
 ** Description: sets defeated conditional to true
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: sets defeated conditional to true
 *********************************************************************/

void Barbarian::setDefeated()
{
	this->defeated = true;
}

/*********************************************************************
 ** Function: attack
 ** Description: rolls attack dice and adds total
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns creature attack roll
 *********************************************************************/


int Barbarian::Attack()
{
	aRoll1 = (rand() % 6 + 1); //rolls 2 dice so total will be the sum of both rolls
	aRoll2 = (rand() % 6 + 1);
	aTotal = aRoll1 + aRoll2;
	
	return aTotal;
}

/*********************************************************************
 ** Function: Defense
 ** Description: rolls defense dice and adds total
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns creature defense roll
 *********************************************************************/

int Barbarian::Defense()
{
	dRoll1 = (rand() % 6 + 1); //rolls 2 dice so total will be the sum of both rolls

	dRoll2 = (rand() % 6 + 1);
	dTotal = dRoll1 + dRoll2;

	return dTotal;
}

/*********************************************************************
 ** Function: Battle
 ** Description: completes the entire battle for two creatures
 ** Parameters: pointer to the creature that will fight
 ** Pre-Conditions: called in main after use picks two creatures to fight
 ** Post-Conditions: determines the winner of the battle and prints statement
 *********************************************************************/


void Barbarian::Battle(Creature *c1)
{	  //displays the starting health for both creatures

	cout << this->getName() << " starting health is: " << this->getStrength() << endl;
        cout << c1->getName() << " starting health is: " << c1->getStrength() << endl;
	cout << endl;
	while (this->getDefeated() == false && c1->getDefeated() == false) //checking that both creatures are still alive
	{	int attack1 = this->Attack();
		int attack2 = c1->Attack();
		int defense1 = this->Defense();
		int defense2 = c1->Defense();
		
			
		cout << this->getName() << " attacks for: " << attack1 << endl;
		cout << this->getName() << " defends for: " << defense1 << endl;
		cout << endl;
		cout << c1->getName() << " attacks for: " << attack2 << endl;
		cout << c1->getName() << " defends for: " << defense2 << endl;
		cout << endl;
		  if (this->getName() == "Medusa" && attack1 == 12)  //if Medusa is fighting, this will account for her Glare ability

                {
                        c1->setDefeated();
                        cout << c1->getName() << " is turned to stone!" << endl;
			break;
                }

                if (c1->getName() == "Medusa" && attack2 == 12) //if Medusa is fighting, this will account for her Glare ability

                {
                        this->setDefeated();
                        cout << this->getName() << " is turned to stone!" << endl;
			break;

                }


		if (this->getDefeated() == false && c1->getDefeated() == false) //this is going to call damage methods

		{
			this->damage(attack2, defense1); //damage will accept the opponents attack roll and creatures defense roll

			c1->damage(attack1, defense2);
		
			cout << "Stength remaining for: " << this->getName() << " is: " << this->getStrength() << endl; ////displays remaining strength

			cout << "Stength remaining for: " << c1->getName() << " is: " << c1->getStrength() << endl;
		}
	}

	if (this->getDefeated() == false && c1->getDefeated() == true) //declaring winner

		cout << this->getName() << " is the winner!" << endl;
	
	else if (c1->getDefeated() == false && this->getDefeated() == true)
		cout << c1->getName() << " is the winner!" << endl;
	
	else if (c1->getDefeated() == true && this->getDefeated() == true)
		cout << "A tie! Both creatures have been defeated!" << endl;

		
}

/*********************************************************************
 ** Function: damage
 ** Description: calculates damage, declares creature is defeated if strength is 0 or less
 ** Parameters: opponent's attack roll, creature's defense roll
 ** Pre-Conditions: called during battle after attack and defense rolls are made
 ** Post-Conditions:  calculates damage, declares creature is defeated if strength is 0 or less
 *********************************************************************/


void Barbarian::damage(int aTotal, int dTotal)
{	
	if (aTotal > dTotal + armor)
		this->strength = strength - (aTotal - dTotal - armor);
	if (strength <= 0)
		defeated = true;
}
