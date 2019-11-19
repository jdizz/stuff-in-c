/***************************************************
Jason Davis
CS161
Assignment 3: BC Ferries
July 05, 2016
***************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//declare variables
	double adultPrice = 13.00;
	double adultFuelSurcharge = 1.25;
	double child5_11 = 6.50;
	double childUnder5 = 0;
	double vehicle = 43.00;
	double oversizeVehicle = 69;
	//double fare;
	//double totalDue;
	bool driving ;

	// User dialog
	cout << "Welcome to Jason Davis' Fare Calculator\n\n";

	// User Input required for fare calculation and output
	cout << "How many adults (age 12 or over) are in your party? ";
	cin >> adultPrice;
	cout << "How many children (age 5 to 11) are in your party? ";
	cin >> child5_11;
	cout << "Are you driving a vehicle onto the ferry? (y/n): \n\n";
	cin >> driving;
	cout << "What is the length of the vehicle in feet? (y/n): \n\n";
	cin;
	cout << "Is the vehicle over 7 feet high? (y/n): \n\n ";
	cin;

	// If/Else
	// Calculations


	// Fare Output to User
	cout << "Your fare is \n\n"; //fare;
	cout << "The total amount payable is $ \n\n"; //totalDue;
	

	// End of program
	cout << "Thank you for using Jason Davis' Fare Calculator\n\n";
	
	// Pause console for output review
	system("pause");
}