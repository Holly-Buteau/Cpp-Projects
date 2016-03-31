#include "Creature.hpp"
#include "creatureQueue.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include <stdlib.h>
#include <time.h>
#include <string>
void driver()
{
 	Creature *thing1;
        //Creature *thing2;
	//Creature *memAccess;
	CreatureQueue player1;	
	CreatureQueue player2;
	CreatureQueue losers;
	int player1score = 0;
	int player2score = 0;
        int choice1;
        //int choice2;
	int numCreatures;
	int player1losses = 0;
	int player2losses = 0;
	string creatureName;

	cout << "How many creatures will fight?" << endl;
	cin >> numCreatures;
	cin.clear();
	cin.ignore(1000, '\n');

	for (int x = 1; x < 3; x++)
	{
		for (int y = 1; y < numCreatures + 1; y++)
		{
        		cout << "Player " << x << " creature " << y << endl;
        		cout << "1. Barbarian" << endl;
        		cout << "2. Medusa" << endl;
        		cout << "3. Vampire" << endl;
        		cout << "4. Blue Men" <<endl;
        		cout << "5. Harry Potter" << endl;
        		cin >> choice1; 
			cin.clear();
        		cin.ignore(1000, '\n');

			cout << "Enter creature " << y << " name" << endl;
			getline(cin, creatureName);
			//cin >> creatureName;
		
	
        		if (choice1 == 1)
                	{	
				thing1 = new Barbarian;
				thing1->setName(creatureName);
				//memAccess = &thing1;
			
				if (x == 1)
					player1.add(thing1);
				else 
					player2.add(thing1);				
			}

		        if (choice1 == 2)
		        {	thing1 = new Medusa;
				thing1->setName(creatureName);
				//memAccess = &thing1;

				if (x == 1)
                                        player1.add(thing1);
                                else
                                        player2.add(thing1);

			}	

		        if (choice1 == 3)
                	{	thing1 = new Vampire;
				thing1->setName(creatureName);
				//memAccess = &thing1;

				if (x == 1)
                                        player1.add(thing1);
                                else
                                        player2.add(thing1);

			}

		        if (choice1 == 4)
                	{	thing1 = new BlueMen;
				thing1->setName(creatureName);
				// memAccess = &thing1;

				if (x == 1)
                                        player1.add(thing1);
                                else
                                        player2.add(thing1);

			}
		
		        if (choice1 == 5)
                	{	thing1 = new HarryPotter;
				thing1->setName(creatureName);
			//	 memAccess = &thing1;

				if (x == 1)
                                        player1.add(thing1);
                                else
                                        player2.add(thing1);

			}
		}
	}

/*cout << "Player 1 queue" << endl; 
player1.displayQueue();
cout << "Player 2 queue" << endl; 
player2.displayQueue();	        
*/
while(player1losses < numCreatures && player2losses < numCreatures)
{ 
cout << "***************************************************************************" << endl;
cout << "Fighting creature for player 1: " << player1.getFirst()->getName() << endl;
cout << "Fighting creature for player 2: " << player2.getFirst()->getName() << endl;
cout << "***************************************************************************" << endl;
       
player1.getFirst()->Battle(player2.getFirst());

if (player1.getFirst()->getDefeated() == false && player2.getFirst()->getDefeated() == true)
{	player1.getFirst()->heal();
	player1.getFirst()->scoreIncrement();	
	player1.add(player1.getFirst());
	losers.add(player2.getFirst());
	player1.remove();
        player2.remove();
	player1score++;
	player2losses++;
}


else if (player2.getFirst()->getDefeated() == false && player1.getFirst()->getDefeated() == true)
{       player2.getFirst()->heal();
	player2.getFirst()->scoreIncrement();
	player2.add(player2.getFirst());
        losers.add(player1.getFirst());
        player1.remove();
        player2.remove();
	player2score++;
	player1losses++;
}

else if (player2.getFirst()->getDefeated() == true && player1.getFirst()->getDefeated() == true)
{
	losers.add(player1.getFirst());
	losers.add(player2.getFirst());

        player1.remove();
        player2.remove();
	player1losses++;
	player2losses++;

}



cout << "Player 1 score: " << player1score << endl;
cout << "Player 2 score: " << player2score << endl;
/*if (player1losses == numCreatures)
	player1.isEmpty() = true;

if (player2losses == numCreatures)
        player2.isEmpty() = true;

*/
//cout << "Player 1: " << player1.isEmpty()  << endl;
//cout << "Player 2: " << player2.isEmpty()  << endl;
 

/*cout << "Player 1 queue" << endl;
player1.displayQueue();
cout << "Player 2 queue" << endl;
player2.displayQueue();
cout << "Losers: " << endl;
losers.displayQueue();
*/
}


if(player1score > player2score)
	cout << "Player 1 wins with a score of: " << player1score << " versus Player 2's score of: " << player2score << endl;


if(player1score < player2score)
        cout << "Player 2 wins with a score of: " << player2score << " versus Player 1's score of: " << player1score << endl;

if(player1score == player2score)
	cout << "A tie!" << endl;


cout << "Losers: " << endl;
losers.displayQueue();


//cout << "This is a test to see what happens after the while loop." << endl;

//cout << "Yup, it works." << endl;
}

int main()
{	srand(time(0));
	//CreatureQueue player1;
	//CreatureQueue player2;
	//CreatureQueue losers;	
	driver();	
	//player1.displayQueue();
	//player2.displayQueue();
//
return 0;
}

