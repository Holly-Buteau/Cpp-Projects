/*********************************************************************
 ** Program Filename: HarryPotter.cpp
 ** Author: Holly Buteau
 ** Date: February 10. 2015
 ** Description: source file for HarryPotter class
 ** Input: none
 ** Output: none
*********************************************************************/

#include "HarryPotter.hpp"
#include "Creature.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

/*********************************************************************
 * ** Function: HarryPotter::HarryPotter
 * ** Description: default constructor for Harry Potter
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: Harry Potter default values are set
 * *********************************************************************/

HarryPotter::HarryPotter() : Creature()
{
        this->armor = 0;
        this->strength =10;
        this->name = "Harry Potter";
	this->defeated = false;
	this->score = 0;
}


/*********************************************************************
 *** Function: HarryPotter::~HarryPotter
 *** Description: destructor for HarryPotter
 *** Parameters: none
 *** Pre-Conditions: delete is called
 *** Post-Conditions: HarryPotter is deleted
 **********************************************************************/


HarryPotter::~HarryPotter()
{
	delete this;
}


/*********************************************************************
 * ** Function: HarryPotter::heal
 * ** Description: restores health
 * ** Parameters: none
 * ** Pre-Conditions: heal is called in main
 * ** Post-Conditions: harrypotter regains some health
 * *********************************************************************/


void HarryPotter::heal()
{
     int healthDifference;
     healthDifference = 10 - this->strength;
     if (healthDifference > 0)
	this->strength = this->strength + (rand() % healthDifference + 1);

}


/*********************************************************************
 * ** Function: HarryPotter::scoreIncrement
 * ** Description: increments score of creature
 * ** Parameters: none
 * ** Pre-Conditions: scoreIncrement is called in main
 * ** Post-Conditions: creature score increses by 1;
 * *********************************************************************/



void HarryPotter::scoreIncrement()
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

string HarryPotter::getName()
{
        //return "Harry Potter";
        return this->name;
}

/*********************************************************************
 ** Function: getArmor
 ** Description: returns armor value of a creature
 ** Parameters: none
 ** Pre-Conditions: called in another method
 ** Post-Conditions: returns armor value
 *********************************************************************/
int HarryPotter::getArmor()
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

int HarryPotter::getStrength()
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

bool HarryPotter::getDefeated()
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

void HarryPotter::setDefeated()
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


void HarryPotter::setName(string n)
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
int HarryPotter::Attack()
{
        aRoll1 = (rand() % 6 + 1); //Harry Potter rolls 2 dice so total will be the sum of both rolls

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

int HarryPotter::Defense()
{
        dRoll1 = (rand() % 6 + 1); //Harry Potter rolls 2 dice so total will be the sum of both rolls

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

void HarryPotter::Battle(Creature *c1)
{
	 //displays the starting health for both creatures
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

void HarryPotter::damage(int aTotal, int dTotal)
{	//because Harry can ressurect once per game, this boolean makes sure he only does it once
	bool ressurected = false;

        if (aTotal > dTotal + armor)
                this->strength = strength - (aTotal - dTotal - armor);
        //if he dies and hasn't resurrected, he gets more healh and comes back
	if (strength <= 0 && resurrected == false)
        {       cout << "Harry Potter has healed! He now was 20 health!" << endl;
		strength = 20;
		resurrected = true;
	}
	//if he dies and has already resurrected, he is defeated	
	if (strength <= 0 && resurrected == true)
		defeated = true;

	


}

