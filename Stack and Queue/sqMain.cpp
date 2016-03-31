#include "Stack.hpp"
#include "Queue.hpp"

#include <iostream>
using namespace std;

void stackMenu()
{	int stackChoice = 0;
	int stackNum = 0;

	Stack sTrial;
	
	do
	{
	 cout << endl;
	 cout << "What would you like to do with Stack?" << endl;
         cout << "1: Add a number" << endl;
         cout << "2: Remove the top number from the Stack" << endl;
         cout << "3: Display the Stack;" << endl;
         cout << "4: Quit" << endl;
         cin >> stackChoice;

	  if (stackChoice == 1)
        {
                cout << "What integer would you like to add?" << endl;
                cin >> stackNum;
                sTrial.add(stackNum);
               
        }

        if (stackChoice == 2)
        {       sTrial.remove();
               
        }

        if (stackChoice == 3)
        {       sTrial.displayStack();
               

        }
	
	
        } while(stackChoice != 4); 
	
}

void queueMenu()
{	int queueChoice = 0;
	int queueNum = 0;
 	Queue qTrial;
	
	do
	{
	cout << endl;
	cout << "What would you like to do with Queue?" << endl;
        cout << "1: Add a number" << endl;
        cout << "2: Remove the top number from the Queue" << endl;
        cout << "3: Display the Queue" << endl;
        cout << "4: Quit" << endl;
        cin >> queueChoice;
	
	 
        if (queueChoice == 1)
        {
                cout << "What integer would you like to add?" << endl;
                cin >> queueNum;
                qTrial.add(queueNum);
                 

        }

        if (queueChoice == 2)
        {       qTrial.remove();
                
        }
        if (queueChoice == 3)
        {       qTrial.displayQueue();
                
        }
	
	
	} while(queueChoice != 4);
}
int main()
{
	int choice;
	
	cout << "Would you like to work with: " << endl;
	cout << "1: Stack" << endl;
	cout << "2: Queue" << endl;
	cin >> choice;

	if (choice == 1)
		stackMenu();

	if (choice == 2)
		queueMenu();

	

	return 0;

}	
