#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

// Function prototypes
int loadData(string);
void showAll();
//void showMenu();
//int showBooksByAuthur(string&);
//int showBooksByTitle(string&);

// Global variable declarations
const int array_Size = 1000;
string bookTitle[array_Size] = {""};
string bookAuthor[array_Size] = {""};

void main() {

	string pathname = "";

	cout << "Welcome to Jason Davis's Library Database\n\n";
	cout << "Please enter the name of the database file: ";
	getline(cin,pathname);

	loadData(pathname);
	showAll();

	system("pause");

	}

	int loadData(string pathname) {

	// Declare variables
	ifstream inFile;
	string title, author;
	int count = 0;

	// open file using pathname variable
	inFile.open(pathname.c_str());

	if (!inFile) 
		{
		cout << "\n" << "Cannot open the input file.\n\n";
		return 1;
		}

	while (inFile)
		{
		   // else read data into parallel arrays..and count

			//inFile >> bookTitle[count] >> bookAuthor[];
			//and count
			//then return count of number of books read into array
			while (getline(inFile,title))
			{
				getline(inFile, author);
				bookTitle[count] = title;
				bookAuthor[count] = author;
				count++;
			}

			inFile.close();
			inFile.clear(std::ios_base::goodbit);
			return count;
		}

}

// Function to provide number of books stored in database
// ie value returned by function loadData()
// Read number of records in parallel array and display
void showAll() {
	int count = 0;
	cout << count << "records loaded successfully." << "\n\n";
}

/*// Function to show user menu
void showMenu() {
	
	int selection;
	string i;

	cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All: ";
	cin >> selection;
	selection = toupper(selection);
	
	switch (selection) 
	{
		case ('Q') : 
		{
			exit;
			break;
		}
		case ('A') : 
		{
			// Display all records that contain designate text 
			// SOMEWHERE in the author field
			// Call showBooksByAuthor function
			showBooksByAuthur(i);
			break;
		}
		case ('T') : {
			// Display all records that contain designate text 
			// SOMEWHERE in the title field
			// Search by title -> Call showBooksByTitle function to 
			break;
		}
		case ('S') : {
			// Display all records in database using showAll function
			showAll();
			break;
		}
		//default: {}
	}
}*/

/*int showBooksByAuthur(int count, string name) 
{
	// Case insensitive. 
	// Function should display all books whose author field contains 
	// the string passed in the parameter called name.
	// It returnds the number of books displayed. Count specifies the number of books in the database.
}*/

/*int showBooksByTitle(int count, string title)
{
	// Case insensitive
	// Display all books whose title field contains the string passed in the parameter called title. 
	// It returnds the number of books displayed. 
	// Count specifies the number of books in the database.
}*/

// loop through array for (int i = 0; i < array_Size; i++) {