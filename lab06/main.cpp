/**********************************
Jason Davis
July 27, 2016
CS 161
Lab 6: Reading Text Files
Sources: Textbook, Course Documents, and Internet Research
**********************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	// Variable declarations
	string filePath, inFileName;
	double inFileNum1, inFileNum2;
	ifstream inFile;

	// Prompt user to input file path and store in variable
	cout << "Please enter the data file path: ";
	getline(cin, filePath);

	// Open file called above by user
	inFile.open(filePath.c_str());

	// Check if file is open, if open terminate
	if (!inFile.is_open()) {
		cout << "\nError - could not open: " << filePath << "\n\n";
		system("pause");
		exit(1);
	}

	// Output header for input file data
	cout << "\n" << "The file contents are: " << "\n\n";

	// While loop to parse text file data, store in appropriate variables
	// and output data to console
	while (inFile >> inFileName >> inFileNum1 >> inFileNum2) {
		cout << inFileName << " " << inFileNum1 << " " << inFileNum2;
		cout << "\n\n";
	}

	// Close the file
	inFile.close();

	// Pause console for output review
	system("pause");
}