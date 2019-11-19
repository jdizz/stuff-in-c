/**************************************
Jason Davis
July 18, 2016
CS 161
Lab 5: If/else Control Structures and Precision
Sources: Texbook, Internet resources
**************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() 
{
	// Declare variables
	float inputNumber = 0;
	int levelOfPrecision = 0;

	// Prompt user to input floating point number, store in varialbe
	cout << "Please enter a floating point number: ";
	cin >> inputNumber;
	cout << "\n";

	// Prompt user to input level of decimal precision wanted, store in variable
	cout << "Do you want to print with 1 or 4 digits of precision (Enter 1 or 4): ";
	cin >> levelOfPrecision;
	cout << "\n";

	// If/Else logic based on user's input...
	// Then output inputNumber with user specified level of precision (1 or 4)
	if (levelOfPrecision == 1) {
		cout << fixed << setprecision(1) << inputNumber;
		cout << "\n\n";
	}

	else if (levelOfPrecision == 4) {
		cout << fixed << setprecision(4) << inputNumber;
		cout << "\n\n";
	}

	// If inputNumber does not equal 1 or 4
	// Output error message below
	else {
		cout << "That is not a valid choice!";
		cout << "\n\n";
	}

	// Pause console for output review
	system("pause");

}