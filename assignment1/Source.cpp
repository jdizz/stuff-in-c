/**********************************************
Name: Jason
Date: 06/21/2016
Homework: 123
Sources: None
**********************************************/

#include <iostream>
#include <string>

using namespace std;

void main()
{
	// Declare variables
	string movie;
	string actor;

	// Prompt user and collect input
	cout << "What is your favorite movie?" << endl;
	cin >> movie;

	// Respond to users input
	cout << "Your favorite movie is: " << movie << endl;

	// Ask user what actor is in movie
	cout << "What actor is in your favorite movie?\n";
	cin >> actor;

	//Confirm actor
	cout << "The actor you picked is: " << actor << "\n\n";

	// Keep the console open
	system("pause");
}