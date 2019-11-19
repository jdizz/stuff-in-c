/**********************************************
Name: Jason Davis
Date: 06/26/2016
Assignment #1: Horoscope
Sources: textbook
**********************************************/

//Header file
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Declare string variables for recording student name and subject studied.
	string dialogName;
	string subject;

	//Output introduction to horoscope.
	cout << "Welcome to Jason Davis' Crystal Ball!\n\n";

	//Output prompting for name
	cout << "What is your name, please? ";
	//Record user input to 'dialogName' string variable.
	cin >> dialogName;
	cout << '\n';

	//Output response to user utilizing recorded 'dialogName' string variable
	cout << "Hello, " << dialogName
		 << ". My name is Jason\n\n";

	//Output prompting for subject studied
	cout << "What subject are you studying? ";
	//Record user input to 'subject' string variable
	cin >> subject;
	cout << '\n';

	//Output with horoscope prediction utilizing recorded 'dialogName' string variable
	cout << "Well, " << dialogName 
		 << ", Jason's crystal ball says you will do very well in " << subject 
		 << " this term.\n\n";

	//Output offering good luck to student
	cout << "Good luck!\n\n";
	
	// Keep the console open
	system("pause");
}