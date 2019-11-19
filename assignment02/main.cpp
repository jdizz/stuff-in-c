/**********************************************
Name: Jason Davis
Date: 07/03/2016
Assignment #2
Course: CS161
Sources: Class documents and textbook
**********************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//Declare fixed value (const), int, and double variables used in program.
	const double dollarToEuro = 0.6938;
	const double ouncesToKiloRate = 0.02835;
	const int ouncesInPound = 16;
	int pounds;
	int ounces;
	double price;
	double pricePerPound;
	double totalWeight;
	double totalWeightInKilos;
	double priceInEuros;
	double eurosPerKilo;

	cout << fixed;				 //Sets output stream to fixed point notation.
	cout << setprecision(2);	//Sets output stream to display only two decimal points.

	//User dialog and input utilizing int and double variables.
	cout << "Welcome to Jason Davis' Conversion Program!\n\n";
	cout << "What is the weight of your item in pounds and ounces?\n\n";
	cout << "Pounds: ";
		cin >> pounds;
	cout << "Ounces: ";
		cin >> ounces;
	cout << "\n";
	cout << "What is the price in dollars and cents: $";
		cin >> price;
	cout << "\n";

	//Calculations needed to convert user input into output of price/pound and euro/kilo.
	totalWeight = (pounds * ouncesInPound) + ounces;
	totalWeightInKilos = totalWeight * ouncesToKiloRate;
	pricePerPound = price / (totalWeight / ouncesInPound);
	priceInEuros = price * dollarToEuro;
	eurosPerKilo = priceInEuros / totalWeightInKilos;
	
	//Output the conversion results to user.
	cout << "The price of this item is $" << pricePerPound << " per pound.\n\n";
	cout << "This is equivalent to " <<  eurosPerKilo << " Euros per kilo.\n\n";
	cout << "Thank you for using Jason Davis' Conversion program!\n\n";

	//Keep the console open for output review.
	system("pause");



}

