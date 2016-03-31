/*********************************************************************
 * ** Program Filename: Holly Buteau
 * ** Author: Holly Buteau
 * ** Date: January 31, 2016
 * ** Description: source file for lab4
 * ** Input: none
 * ** Output: user decides
 * *********************************************************************/

#include "lab4.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


/*********************************************************************
 * ** Function: getString
 * ** Description: gets user strings
 * ** Parameters: none
 * ** Pre-Conditions: chosen from menu
 * ** Post-Conditions: sends the string to reverseString
 * *********************************************************************/

void getString()
{
        string userString;
        cout << "Please type in the string that is to be reversed " << endl;
        cin.clear();
        cin.ignore();
        getline(cin, userString);

        stringReverse(userString);
}

/*********************************************************************
 * ** Function: stringReverse
 * ** Description: reverses string
 * ** Parameters: string
 * ** Pre-Conditions: user has typed in a string
 * ** Post-Conditions: string has been reversed
 * *********************************************************************/

void stringReverse(string input)
{
        int stringLength = input.length();

        if (stringLength == 1)
                cout << input << endl;

        if (stringLength > 1)
        {
                cout << input.substr(input.length() - 1, 1);
                input.erase(input.end() - 1);
                stringReverse(input);

        }

        menu();
}

/*********************************************************************
 * ** Function: fillArray
 * ** Description: gets user input and fills the array
 * ** Parameters: none
 * ** Pre-Conditions: user chooses from menu
 * ** Post-Conditions: array is filled  
 * *********************************************************************/

void fillArray()
{
        int numberCount = 0;
        int userArray[100];
        int userInput;



        for (int x = 0; x < 100; x++)
        {   cout << "Please enter numbers for the array " << endl;
            cout << "press 0 when you are done" << endl;
            scanf("%d" , &userInput);


                if (userInput == 0)
                {
                        cout << "Array sum is: " << arraySum(userArray, numberCount) << endl;
                        break;

                }
		
		 if (userInput != 0)
                {
                        userArray[x] = userInput;
                        numberCount++;

                }

        }

}

/*********************************************************************
 * ** Function: arraySum
 * ** Description: sums the elements of the array
 * ** Parameters: an array and its size
 * ** Pre-Conditions: user has filled the array
 * ** Post-Conditions: array sum is returned
 * *********************************************************************/

int arraySum(int userArray[], int numElements)
{


        if (numElements <= 0)
        {
                return 0;

        }

        else
        {
                return userArray[0] + arraySum(userArray + 1, numElements - 1);

        }



}

/*********************************************************************
 * ** Function: getNum
 * ** Description: gets the integer to be calculated
 * ** Parameters: none
 * ** Pre-Conditions: user chooses from menu
 * ** Post-Conditions: number is taken in to be triangulated
 * *********************************************************************/

void getNum()
{
        int userNum;

        cout << "Please enter the integer " << endl;
        cout << "and I will calculate the triangular number" << endl;
        cin >> userNum;

        cout << "Triangular number is:  " << triangularNumber(userNum) << endl;
}

/*********************************************************************
 * ** Function: triangularNumber
 * ** Description: calculates the triangular number of an int
 * ** Parameters: an integer
 * ** Pre-Conditions: user has inputted an integer
 * ** Post-Conditions: triangular sum of integer is returned
 * *********************************************************************/

int triangularNumber(int num)
{ 
        if (num >= 1 )
                return (num + triangularNumber(num - 1));

        else
                return 0;
}

/*********************************************************************
 * ** Function: menu
 * ** Description: gives user choices for methods
 * ** Parameters: none
 * ** Pre-Conditions: called from main
 * ** Post-Conditions: sends user to selected method
 * *********************************************************************/

void menu()
{
        int choice;

        cout << "What would you like to do?" << endl;
        cout << "1. Reverse a string" << endl;
        cout << "2. Calculate the sum of an array" << endl;
        cout << "3. Determine the triangle number of an integer" << endl;
        cout << "4. Quit the program" << endl;

        scanf ("%d", &choice);

        if (choice == 1)
        {
                getString();
        }

        else if (choice == 2)
        {
                fillArray();
        }

	 else if (choice == 3)
        {
                getNum();

        }


}

        
