/***************************************************
Jason Davis
CS161
Assignment 3: BC Ferries
July 05, 2016
***************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Named constants for passengers
double adultPrice = 13.00, child5_11Price = 6.50, passengerFuelCharge = 1.25;

//Named constants for vehicles and oversized vehicles
double vehicleCost = 43.00, vehicleFuelCharge = 4.15, vehicleXtraLenthCharge = 2.15;
double osVehicle = 69.00, osVehicleFuelCharge = 10.40, osXtraLengthCharge = 3.45;

int main()
{
	// Variable declaration
	int adults = 0, children5_11 = 0, vehicleLength = 0;
	char driving, vehicleHeight;
	double adultFare, childrenFare, PassengerFuelSurcharge, totalPassengerFare, totalFuelSurcharge, totalPassengerAmount;
	double fareWithVehicle, fareWithVehicleXtraLength, fareOSVehicle, fareOSVehicleXtraLength, totalFuelCharge, totalOSFuelCharge;

	cout << fixed << showpoint << setprecision(2);

	// User introduction dialog
	cout << "Welcome to Jason Davis' Fare Calculator\n\n";

	// User prompts requesting input required for fare calculations
	cout << "How many adults (age 12 or over) are in your party? ";
	cin >> adults;
	cout << "\n";
	cout << "How many children (age 5 to 11) are in your party? ";
	cin >> children5_11;
	cout << "\n";
	cout << "Are you driving a vehicle onto the ferry? (y/n): ";
	cin >> driving;
	cout << "\n";

	// Fare Calulcations for Passengers with No Vehicles
	adultFare = adultPrice * adults;
	childrenFare = child5_11Price * children5_11;
	totalPassengerFare = adultFare + childrenFare;
	PassengerFuelSurcharge = ((adults + children5_11) * passengerFuelCharge);
	totalPassengerAmount = totalPassengerFare + PassengerFuelSurcharge;

	//Fare Calculations for Passengers with Vehicles
	fareWithVehicle = totalPassengerFare + vehicleCost;
	fareWithVehicleXtraLength = totalPassengerFare + vehicleCost + ((vehicleLength - 20)* vehicleXtraLenthCharge);
	fareOSVehicle = totalPassengerFare + osVehicle + osXtraLengthCharge;
	fareOSVehicleXtraLength = totalPassengerFare + osVehicle + ((vehicleLength - 20) * osXtraLengthCharge);
	totalFuelCharge = PassengerFuelSurcharge + vehicleFuelCharge;
	totalOSFuelCharge = PassengerFuelSurcharge + osVehicleFuelCharge;

	if (driving == 'n' || driving == 'N')
	{
		cout << "Your fare is $ " << totalPassengerFare;
		cout << " plus a fuel surcharge of $ " << PassengerFuelSurcharge;
		cout << "\n\n";
		cout << "The total amount payable is $ " << totalPassengerAmount;
		cout << "\n\n";
	}

	if (driving == 'y' || driving == 'Y')
	{
		cout << "What is the length of the vehicle in feet? ";
		cin >> vehicleLength;
		cout << "\n";
		cout << "Is the vehicle over 7 feet high? (y/n): ";
		cin >> vehicleHeight;
		cout << "\n";
	
		else if (vehicleHeight == 'n' && vehicleLength <= 20 || vehicleHeight == 'N' && vehicleLength <= 20)
		{
			cout << "Your fare is $ " << fareWithVehicle
				<< " plus a fuel surcharge of $" << totalFuelCharge
				<< "\n\n"
				<< "The total amount payable is $" << fareWithVehicle + totalFuelCharge
				<< "\n\n";
		}

		else if (vehicleHeight == 'n' && vehicleLength > 20 || vehicleHeight == 'N' && vehicleLength > 20)
		{
			cout << "Your fare is $ " << fareWithVehicleXtraLength
				<< " plus a fuel surcharge of $" << totalFuelCharge
				<< "\n\n"
				<< "The total amount payable is $" << fareWithVehicleXtraLength + totalFuelCharge
				<< "\n\n";
		}

		else if (vehicleHeight == 'y' && vehicleLength <= 20 || vehicleHeight == 'Y' && vehicleLength <= 20)
		{
			cout << "Your fare is $ " << fareOSVehicle
				<< " plus a fuel surcharge of $" << totalOSFuelCharge
				<< "\n"
				<< "The total amount payable is $" << fareOSVehicle + totalOSFuelCharge
				<< "\n\n";
		}

		else if (vehicleHeight == 'y' && vehicleLength > 20 || vehicleHeight == 'Y' && vehicleLength > 20)
		{
			cout << "Your fare is $ " << fareOSVehicleXtraLength
				<< "\n"
				<< " plus a fuel surcharge of $" << totalOSFuelCharge
				<< "\n\n"
				<< "The total amount payable is $" << fareOSVehicleXtraLength + totalOSFuelCharge
				<< "\n\n";
		}

		// Outputs thank you message to customer
		cout << "Thank you for using Jason Davis' Fare Calculator. Enjoy your trip.\n\n";

	}
	// Pause console for output review
	system("pause");
}