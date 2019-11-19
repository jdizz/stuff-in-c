/********************************************************
Jason Davis
August 01, 2016
CS 161: Data Integrity
Assignment 6:
Sources: Textboot, Class Documents, and Internet Research
********************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Function protypes
char userMenu();
void create();
unsigned int calculate(char&, char[]);
void verifyChecksum();

const int arraySize = 100;

void main() {
	
	// Variable declarations
	char userSelection;
	userSelection = userMenu();

	// while loop for user selection switch
	while (userSelection != 'Q') {
		switch (userSelection) {
		case 'A': 
			create();
			break;
		case 'B': 
			verifyChecksum();
			break;
		default: 
			cout << "\nUnable to open input file.\n";
			break;
		}
		userSelection = userMenu();
	}
	cout << "\n";
	system("pause");
}

// User menu function
char userMenu() {
	char userSelection;
	cout << "Please select:\n";
	cout << "A) Add checksum to specified file\n";
	cout << "B) Verify integrity of specified file\n";
	cout << "Q) Quit\n\n";
	cin >> userSelection;
	return toupper(userSelection);
}

// User dialog to prompt for, thenstore..
// filename in array and calculate file checksum
unsigned int calculate(char& last, char fileNames[])
{
	char ch;
	ifstream inFile;
	int checksum = 0;
	
	cout << "\nSpecify the file path: ";
	cin >> fileNames;

	inFile.open(fileNames);

	// Error handling on bad user input
	if (inFile.fail()) {
		cout << "The file " << fileNames << " could not be found or opened.\n";
		inFile.clear(std::ios_base::goodbit);
		//return 1;
		exit;
	}

	inFile.get(ch);

	// While loop iterating through input file to calculate checksum
	while (inFile) {
		checksum += ch;
		if (ch != '\n')
			last = ch;
		inFile.get(ch);
	}

	// Close file, clear, and return checksum
	inFile.close();
	inFile.clear(std::ios_base::goodbit);
	return checksum;
}

 // Function to 
void create()
{
	unsigned int checksum = 0;
	int check;
	char ch, filename[arraySize];
	checksum = calculate(ch, filename);
	ofstream outFile;

	outFile.open(filename, fstream::app);
	
	checksum = ~checksum;
	checksum = checksum & 0x000000FF;
	check = ++checksum;
	
	cout << "File checksum= " << check << "\n\n";
	
	outFile << (char)check << "\n";

	outFile.close();
	outFile.clear(std::ios_base::goodbit);
}

// Function to verify file checksum
void verifyChecksum()
{
	unsigned int checksum;
	char ch, filename[arraySize];

	checksum = calculate(ch,filename);
	checksum = '\n';
	checksum = ~checksum;
	++checksum;
	checksum = checksum & 0x000000FF;

	cout << "File checksum = " << checksum << "\n\n";
	
	if (checksum == 0)
		cout << "The file integrity check has passed successfully.\n";
	else
		cout << "The file integrity check has failed\n";
}