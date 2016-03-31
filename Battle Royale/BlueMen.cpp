/*********************************************************************
 ** Program Filename: BlueMen.cpp
 ** Author: Holly Buteau
 ** Date: February 10. 2015
 ** Description: source file for BlueMen class
 ** Input: none
 ** Output: none
*********************************************************************/

#include "BlueMen.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

/*********************************************************************
 * ** Function: BlueMen::BlueMen
 * ** Description: default constructor for BlueMen
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: BlueMen default values are set
 * *********************************************************************/


BlueMen::BlueMen() : Creature()
{
        this->armor = 3;
        this->strength = 12;
        this->name = "Blue Men";
	this->defeated = false; //they are not defeated
	this->score = 0;

}

/*********************************************************************
 * ** Function: BlueMen::~BlueMen
 * ** Description: destructor for BlueMen
 * ** Parameters: none
 * ** Pre-Conditions: delete is called
 * ** Post-Conditions: BlueMen is deleted
 * *********************************************************************/


BlueMen::~BlueMen()
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


void BlueMen::heal()
{
     int healthDifference;
     healthDifference = 12 - this->strength;
     
     if (healthDifference > 0)
	this->strength = this->strength + (rand() % healthDifference + 1);

}

/*********************************************************************
 * ** Function: scoreIncrement
 * ** Description: increments score of creature
 * ** Parameters: none
 * ** Pre-Conditions: scoreIncrement is called in main
 * ** Post-Conditions: creature score increses by 1;
 * *********************************************************************/


void BlueMen::scoreIncrement()
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

string BlueMen::getName()
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

int BlueMen::getArmor()
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


int BlueMen::getStrength()
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

bool BlueMen::getDefeated()
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

void BlueMen::setDefeated()
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


void BlueMen::setName(string n)
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

int BlueMen::Attack()
{
        aRoll1 = (rand() % 10 + 1); //blue men roll 3 dice so total will be the sum of all rolls
	aRoll2 = (rand() % 10 + 1);
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

int BlueMen::Defense()
{	
        dRoll1 = (rand() % 6 + 1);
	dRoll2 = (rand() % 6 + 1);
 	dRoll3 = (rand() % 6 + 1);
	//as the blue men grow weaker, they lose defense dice	
	if (this->strength > 8)
		dTotal = dRoll1 + dRoll2 + dRoll3;
	
	if (this->strength <= 8 && strength > 4)
	{	 dTotal = dRoll1 + dRoll2;
		 cout << "The Blue Men are becoming weaker!" << endl;
	}
	
	if (this->strength <= 4)
        {       dTotal = dRoll1;  
		cout << "The Blue Men are incredibly weak!" << endl;
	}
	
	
        return dTotal;
}

/*********************************************************************
 ** Function: Battle
 ** Description: completes the entire battle for two creatures
 ** Parameters: pointer to the creature that will fight
 ** Pre-Conditions: called in main after use picks two creatures to fight
 ** Post-Conditions: determines the winner of the battle and prints statement
 *********************************************************************/

void BlueMen::Battle(Creature *c1)
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


                if (this->getDefeated() == false && c1->getDefeated() == false) //this is going to call damage methods

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

void BlueMen::damage(int aTotal, int dTotal)
{	if (aTotal > dTotal + armor)
        	this->strength = strength - (aTotal - dTotal - armor);
	
		
        if (strength <= 0)
                defeated = true;
}
                                                                                                             

