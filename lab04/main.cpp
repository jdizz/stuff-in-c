/*******************
Jason Davis
July 13, 2016
CS 161
Lab 4: If/Else Control Structures
Sources: Textbook, C++ Documentation
*********************/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Delcare char and string variables used in program
	char likeMovies;
	string movie;
	
	// Prompt user for input required for if logic block
	cout << "Do you like watching movies? (Y/N): ";
	cin >> likeMovies;
	likeMovies = toupper(likeMovies);
	cout << "\n";

	// If...else logic. If user likes movies, output user input prompt 
	// and capture to string variable 'movie'.
	if (likeMovies == 'Y') {
		
		cin.ignore(); // Ignores new line stream to capture full user string input
		cout << "What is your favorite movie? ";
		getline(cin,movie); // Captures entire user input string from stream

		// Outputs response to user using 'movie' string variable
		cout << "\n" << "I don't like that movie, " << movie << "\n\n";
	}

	//  Else user does not like movies, then end the program
	else {
		return 0;
	}

	// Pause console for output review
	system("pause");
}