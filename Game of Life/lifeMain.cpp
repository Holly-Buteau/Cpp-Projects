#include "gameOfLife.hpp"


int main()
{
	int choice; // choice of pattern
	int xCoord; // starting x coordinate
	int yCoord; // starting y coordinate
	cout << "Which starting shape would you like?" << endl;
	cout << "1: oscillator" << endl;
	cout << "2: glider" << endl;
	cout << "3: glider canon" << endl; 
	cin >> choice; 

	while (choice < 1 || choice > 3) //if user choice is invalid
	{
		cout << "Invalid Choice. Try Again" << endl;
		cin >> choice;
	}

	cout << "Please type in the starting x-coordinate between 90 and 110" << endl;
	cin >> xCoord;

	while (xCoord < 90 || xCoord > 110)//if user choice is invalid
	{
		cout << "Invalid Choice. Try Again" << endl;
		cin >> xCoord;
	}

	cout << "Please type in the starting y-coordinate between 80 and 120" << endl;
	cin >> yCoord;
	
	while (yCoord < 80 || yCoord > 120)//if user choice is invalid
	{
		cout << "Invalid Choice. Try Again" << endl;
		cin >> yCoord;
	}

	cout << "Your starting coordinate will appear as the nuumber 7." << endl; //makes starting coordinate visible
	cout << endl;

	GameofLife game(choice, xCoord, yCoord);

	game.arrayBuilder();
	game.pattern(choice, xCoord, yCoord);
	game.displayArray();

	return 0;
}
