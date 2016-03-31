/*********************************************************************
 ** Program Filename: Medusa.cpp
 ** Author: Holly Buteau
 ** Date: February 10. 2015
 ** Description: header file for Medusa class
 ** Input: none
 ** Output: none
*********************************************************************/
#include "Medusa.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;


/*********************************************************************
 * ** Function: Medusa::Medusa
 * ** Description: default constructor for medusa
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: medusa default values are set
 * *********************************************************************/


Medusa::Medusa() : Creature()
{
        this->armor = 3;
        this->strength = 8;
        this->name = "Medusa";
	this->defeated = false;
	this->score = 0;
}

/*********************************************************************
 * ** Function: Medusa::~Medusa
 * ** Description: destructor for Medusa
 * ** Parameters: none
 * ** Pre-Conditions: delete is called
 * ** Post-Conditions: Medusa is deleted
 * *********************************************************************/

Medusa::~Medusa()
{
	delete this;
}


/*********************************************************************
 * ** Function: Medusa::heal
 * ** Description: restores  health
 * ** Parameters: none
 * ** Pre-Conditions: heal is called in main
 * ** Post-Conditions: creature regains some health
 * *********************************************************************/


void Medusa::heal()
{
     int healthDifference;
     healthDifference = 8 - this->strength;
     this->strength = this->strength + (rand() % healthDifference + 1);

}

/*********************************************************************
 * ** Function: Medusa::scoreIncrement
 * ** Description: increments score of creature
 * ** Parameters: none
 * ** Pre-Conditions: scoreIncrement is called in main
 * ** Post-Conditions: creature score increses by 1;
 * *********************************************************************/


void Medusa::scoreIncrement()
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

string Medusa::getName()
{
  //return "Medusa";
  return this->name;
}

/*********************************************************************
 ** Function: getArmor
 ** Description: returns armor value of a creature
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns armor value
 *********************************************************************/

int Medusa::getArmor()
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


int Medusa::getStrength()
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

bool Medusa::getDefeated()
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

void Medusa::setDefeated()
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


void Medusa::setName(string n)
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

int Medusa::Attack()
{
        aRoll1 = (rand() % 6 + 1); //medusa rolls 2 dice so total will be the sum of both rolls
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

int Medusa::Defense()
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

void Medusa::Battle(Creature *c1)
{	//displays the starting health for both creatures
	cout << this->getName() << " starting health is: " << this->getStrength() << endl;
        cout << c1->getName() << " starting health is: " << c1->getStrength() << endl;
	cout << endl;
	
        while(this->getDefeated() == false && c1->getDefeated() == false) //checking that both creatures are still alive
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


		  if (this->getDefeated() == false && c1->getDefeated() == false) //this is going to call damage methods

                {

                	this->damage(attack2, defense1); //damage will accept the opponents attack roll and creatures defense roll

			c1->damage(attack1, defense2);

                	cout << "Stength remaining for: " << this->getName() << " is: " << this->getStrength() << endl; //displays remaining strength

                	cout << "Stength remaining for: " << c1->getName() << " is: " << c1->getStrength() << endl;
		        cout << endl;

		}
		

        }

 	if (this->getDefeated() == false && c1->getDefeated() == true)  //declaring winner
                cout << this->getName() << " is the winner!" << endl;

        else if (c1->getDefeated() == false && this->getDefeated() == true)
                cout << c1->getName() << " is the winner!" << endl;

        else if (c1->getDefeated() == true && this->getDefeated() == true)
                cout << "A tie! Both creatures have died!" << endl;
	

}


/*********************************************************************
 ** Function: damage
 ** Description: calculates damage, declares creature is defeated if strength is 0 or less
 ** Parameters: opponent's attack roll, creature's defense roll
 ** Pre-Conditions: called during battle after attack and defense rolls are made
 ** Post-Conditions:  calculates damage, declares creature is defeated if strength is 0 or less
 *********************************************************************/

void Medusa::damage(int aTotal, int dTotal)
{
	if (aTotal > dTotal + armor)
		this->strength = strength - (aTotal - dTotal - armor);
        if (strength <= 0)
                defeated = true;


}

 

     

       
