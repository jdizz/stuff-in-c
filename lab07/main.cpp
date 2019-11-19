/****************************************
Jason Davis
August 3, 2016
CS 161
Lab 7: Math Functions
Sources: Textbook and Class Documents
****************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main() {
	// Declare variables
	long numberOne = 0;
	long numberTwo = 0;
	long result = 0;

	// Prompt user for two numbers, store in double variables
	cout << "Please enter two numbers: ";
	cin >> numberOne >> numberTwo;
	cout << "\n";

	// Call pow function using user inputs
	// Output results to console
	cout << "The result of " << numberOne << " ^ " << numberTwo
		 << " is " << fixed << setprecision(0) << pow(numberOne, numberTwo) << "\n\n";

	// Pause console for output review
	system("pause");
}