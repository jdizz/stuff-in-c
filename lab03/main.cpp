/*
Name: Jason Davis
Date: July 06, 2016
Course: CS161
Professor: G.Gross
Assignment: Lab 3
Name: Math Operators
Sources: Textbook
*/

#include <iostream>

using namespace std;

int main()
{
	// Declare int variables for age, ageinDays, and DaysInYear for program operation
	int age;
	int ageinDays;
	const int daysInYear = 365;

	// Prints dialog instructing user to enter age below
	cout << "Please enter your age in years and I will compute the approximate number of days you have been alive?\n\n";

	// Prompts for user input and assigns input to int variable 'age'
	cout << "Age: ";
	cin >> age;
	cout << "\n";

	// Calculation of user's age in days
	ageinDays = age * daysInYear;

	// Outputs user's age in days
	cout << "Number of days : ";
	cout << ageinDays;
	cout << "\n\n";

	// Prevents console window from closing automatically.
	system("pause");

}