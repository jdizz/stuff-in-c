/***************************************************
Jason Davis
CS161
Assignment 3: BC Ferries
July 05, 2016
Sources: Class documents, textbook, and Thinking in C++, Eckel
***************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Named price constants for ferry passengers.
double const adultPrice = 13.00, child5_11Price = 6.50, passengerFuelCharge = 1.25;

// Named price constants for vehicles and oversize vehicles.
double const vehicleCost = 43.00, vehicleFuelCharge = 4.15, vehicleXtraLenthCharge = 2.15;
double const osVehicle = 69.00, osVehicleFuelCharge = 10.40, osXtraLengthCharge = 3.45;

int main()
{
	// Declaring int, char, double Variables Used Throughout Program.
	int adults = 0, children5_11 = 0, vehicleLength = 0;
	char driving, vehicleHeight;
	double adultFare, childrenFare, PassengerFuelSurcharge, totalPassengerFare, totalPassengerAmount;
	double fareWithVehicle, fareWithVehicleXtraLength, fareOSVehicle, fareOSVehicleXtraLength, totalFuelCharge, totalOSFuelCharge;

	// Sets Output Stream To Fixed Point Notation
	// And Sets Output Stream to display two decimal places
	cout << fixed << showpoint << setprecision(2);

	// Outputs Customer Introduction
	cout << "Welcome to Jason Davis' Fare Calculator\n\n";

	// Output Prompts for Customer Input Required For Fare Calculations
	cout << "How many adults (age 12 or over) are in your party? ";
	cin >> adults;
	cout << "\n";
	cout << "How many children (age 5 to 11) are in your party? ";
	cin >> children5_11;
	cout << "\n";
	cout << "Are you driving a vehicle onto the ferry? (y/n): ";
	cin >> driving;
	cout << "\n";

	// Fare Calulcations For Passengers With No Vehicles
	adultFare = adultPrice * adults;
	childrenFare = child5_11Price * children5_11;
	totalPassengerFare = adultFare + childrenFare;
	PassengerFuelSurcharge = ((adults + children5_11) * passengerFuelCharge);
	totalPassengerAmount = totalPassengerFare + PassengerFuelSurcharge;

	//Fare Calculations For Passengers With Vehicles
	fareWithVehicle = totalPassengerFare + vehicleCost;
	totalFuelCharge = PassengerFuelSurcharge + vehicleFuelCharge;
	totalOSFuelCharge = PassengerFuelSurcharge + osVehicleFuelCharge;

	// Switch Logic For Outputing Fare, Fuel Surcharge, And Total To Customer
	switch (driving)
	{
		// If Customer Vehichle = n or N, then Output Appropriate Fare Calculations, Fuel Surcharge, Total
	case 'n':
	case 'N':
	   cout << "Your fare is $" << totalPassengerFare
			<< " plus a fuel surcharge of $ " << PassengerFuelSurcharge
			<< "\n\n"
			<< "The total amount payable is $ " << totalPassengerAmount
			<< "\n\n";
		break;

		// If Customer Vehicle = y or Y, then Output Appropriate Fare Calculations, Fuel Surcharge, Total Given Customer Input of Vehciele Characteristics
	case 'y':
	case 'Y':
		
		// Customer Input for Vehicle Length and Width If Logic
		cout << "What is the length of the vehicle in feet? ";
		cin >> vehicleLength;
		cout << "\n";
		cout << "Is the vehicle over 7 feet high? (y/n): ";
		cin >> vehicleHeight;
		cout << "\n";
		
		// If vehicleHeight Under 7 And vehicleLength Less Than Or Equal To 20
		// Then Output Fare Calculations, Fuel Surcharge, Total
		if ((vehicleHeight == 'n' && vehicleLength <= 20) || (vehicleHeight == 'N' && vehicleLength <= 20))
		{
			cout << "Your fare is $" << fareWithVehicle
				<< " plus a fuel surcharge of $" << totalFuelCharge
				<< "\n\n"
				<< "The total amount payable is $" << fareWithVehicle + totalFuelCharge
				<< "\n\n";
		}
		
		// If vehicleHeight Under 7 And vehicleLength Greater Than 20
		// Then Output Fare Calculations, Fuel Surcharge, Total
		if ((vehicleHeight == 'n' && vehicleLength > 20) || (vehicleHeight == 'N' && vehicleLength > 20))
		{
			fareWithVehicleXtraLength = totalPassengerFare + vehicleCost + ((vehicleLength - 20) * vehicleXtraLenthCharge);
			
			cout << "Your fare is $" << fareWithVehicleXtraLength
				<< " plus a fuel surcharge of $" << totalFuelCharge
				<< "\n\n"
				<< "The total amount payable is $" << fareWithVehicleXtraLength + totalFuelCharge
				<< "\n\n";
		}

		// If vehicleHeight Over 7 And vehicleLength Less Than Or Equal To 20
		// Then Output Fare Calculations, Fuel Surcharge, Total
		if ((vehicleHeight == 'y' && vehicleLength <= 20) || (vehicleHeight == 'Y' && vehicleLength <= 20))
		{
			fareOSVehicle = totalPassengerFare + osVehicle + osXtraLengthCharge;
			cout << "Your fare is $" << fareOSVehicle
				<< " plus a fuel surcharge of $" << totalOSFuelCharge
				<< "\n\n"
				<< "The total amount payable is $" << fareOSVehicle + totalOSFuelCharge
				<< "\n\n";
		}

		// If vehicleHeight Over 7 And vehicleLength Greater Than 20
		// Then Output Fare Calculations, Fuel Surcharge, Total
		if ((vehicleHeight == 'y' && vehicleLength > 20) || (vehicleHeight == 'Y' && vehicleLength > 20))
		{
			fareOSVehicleXtraLength = totalPassengerFare + osVehicle + ((vehicleLength - 20) * osXtraLengthCharge);
			cout << "Your fare is $" << fareOSVehicleXtraLength
				<< " plus a fuel surcharge of $" << totalOSFuelCharge
				<< "\n\n"
				<< "The total amount payable is $" << fareOSVehicleXtraLength + totalOSFuelCharge
				<< "\n\n";
			break;
	// If customer input outside of scope above, output message
	default:
		cout << "We're sorry, we can not accomodate your party\n\n";
		}
	}
		// Outputs thank you message to customer
		cout << "Thank you for using Jason Davis' Fare Calculator\n\n";
		// Pause console for output review																																																																																																													
		system("pause");
}