/*********************************************************************
 ** Program Filename: Vampire.cpp
 ** Author: Holly Buteau
 ** Date: February 10. 2015
 ** Description: header file for Vampire class
 ** Input: none
 ** Output: none
*********************************************************************/

#include "Vampire.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

/*********************************************************************
 * ** Function: Vampire::Vampire
 * ** Description: default constructor for vampire
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: vampire default values are set
 * *********************************************************************/

Vampire::Vampire() : Creature()
{
        this->armor = 1;
        this->strength = 18;
        this->name = "Vampire";
	this->defeated = false; //not defeated
	this->score = 0;

}


/*********************************************************************
 * ** Function: Vampire::~Vampire
 * ** Description: destructor for vampire
 * ** Parameters: none
 * ** Pre-Conditions: delete is called
 * ** Post-Conditions: vampire is deleted
 * *********************************************************************/

Vampire::~Vampire()
{
	delete this;
}


/*********************************************************************
 * ** Function: heal
 * ** Description: restores health
 * ** Parameters: none
 * ** Pre-Conditions: heal is called in main
 * ** Post-Conditions: creature regains some health
 * *********************************************************************/


void Vampire::heal()
{
     int healthDifference;
     healthDifference = 18 - this->strength;
     this->strength = this->strength + (rand() % healthDifference + 1);

}

/*********************************************************************
 * ** Function: scoreIncrement
 * ** Description: increments score of creature
 * ** Parameters: none
 * ** Pre-Conditions: scoreIncrement is called in main
 * ** Post-Conditions: creature score increses by 1;
 * *********************************************************************/


void Vampire::scoreIncrement()
{
        this->score++;
}


/*********************************************************************
 ** Function: getName
 ** Description: returns name of creature
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns creature name
 *********************************************************************/

string Vampire::getName()
{
        //return "Vampire";
        return this->name;
}


/*********************************************************************
 ** Function: getArmor
 ** Description: returns armor value of a creature
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns armor value
 *********************************************************************/

int Vampire::getArmor()
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

int Vampire::getStrength()
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

bool Vampire::getDefeated()
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

void Vampire::setDefeated()
{
        this->defeated = true;
}

/*********************************************************************
 ** Function: setName
 ** Description: sets name to be passed string
 ** Parameters: string n
 ** Pre-Conditions: called in main
 ** Post-Conditions: assigns creature name
 *********************************************************************/


void Vampire::setName(string n)
{
	this->name = n;
}

/*********************************************************************
 ** Function: attack
 ** Description: rolls attack dice and adds total
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns creature attack roll
 *********************************************************************/

int Vampire::Attack()
{
	aRoll1 = (rand() % 12 + 1);
        return aRoll1;
}

/*********************************************************************
 ** Function: Defense
 ** Description: rolls defense dice and adds total
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns creature defense roll
 *********************************************************************/

int Vampire::Defense()
{
        dRoll1 = (rand() % 6 + 1);
        return dRoll1;
}

/*********************************************************************
 ** Function: Battle
 ** Description: completes the entire battle for two creatures
 ** Parameters: pointer to the creature that will fight
 ** Pre-Conditions: called in main after use picks two creatures to fight
 ** Post-Conditions: determines the winner of the battle and prints statement
 *********************************************************************/

void Vampire::Battle(Creature *c1)
{	//displays the starting health for both creatures
	cout << this->getName() << " starting health is: " << this->getStrength() << endl;
        cout << c1->getName() << " starting health is: " << c1->getStrength() << endl;
	cout << endl;

        while (this->getDefeated() == false && c1->getDefeated() == false) //checking that both creatures are still alive

        {       int attack1 = this->Attack();
                int attack2 = c1->Attack();
                int defense1 = this->Defense();
                int defense2 = c1->Defense();


                cout << this->getName() << " attacks for: " << attack1 << endl;
                cout << this->getName() << " defends for: " << defense1 << endl;
		cout << endl;

                cout << c1->getName() << " attacks for: " << attack2 << endl;
                cout << c1->getName() << " defends for: " << defense2 << endl;
		cout << endl;


                  if (this->getName() == "Medusa" && attack1 == 12) //if Medusa is fighting, this will account for her Glare ability

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


                if (this->getDefeated() == false && c1->getDefeated() == false)  //this is going to call damage methods

                {
                        this->damage(attack2, defense1); //damage will accept the opponents attack roll and creatures defense roll

                        c1->damage(attack1, defense2);

                        cout << "Stength remaining for: " << this->getName() << " is: " << this->getStrength() << endl; //displays remaining strength

                        cout << "Stength remaining for: " << c1->getName() << " is: " << c1->getStrength() << endl;
			cout << endl;
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

void Vampire::damage(int aTotal, int dTotal)
{	//there's a 50% chance the vampire with charm the enemy	
	int charm = (rand() % 6 + 1);
	//if he succeeds, he will take no damamge
	if (charm > 3)
		{ cout << "The enemy is charmed! Vampire takes no damage!";
		  cout << endl;
		}
	else
	{			
        	if (aTotal > dTotal + armor)
                	this->strength = strength - (aTotal - dTotal - armor);
        	if (strength <= 0)
                	defeated = true;
	}
}


