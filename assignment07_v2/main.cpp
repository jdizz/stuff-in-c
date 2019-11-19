#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

// Function prototypes
int loadData(string);
void showAll(int count);
void showMenu(int);
int showBooksByAuthur(int);
int showBooksByTitle(int);

// Global variable declarations
string bookTitle[1000];
string bookAuthor[1000];

void main() {

	string pathname = "";
	int count = 0;
	int i = 0;

	cout << "Welcome to Jason Davis's Library Database\n\n";
	cout << "Please enter the name of the database file: ";
	getline(cin, pathname);
	cout << "\n";

	int numOfBooks = loadData(pathname);
	showMenu(numOfBooks);

	system("pause");
}

int loadData(string pathname) {

	// Declare variables
	ifstream inFile;
	string title, author;
	string line;
	int count = 0, lineCounter = 1;

	// open file using pathname variable
	inFile.open(pathname.c_str());
	string fileName = "C:/library.txt";
	inFile.open(fileName.c_str());

	/* FILE * pFile;
	fopen_s(&pFile, "C:\\library.txt", "r");

	if (pFile == NULL) {
	cout << "\n" << "Cannot open the input file.\n\n";
	system("pause");
	} */

	/* if (inFile.fail())
	{
	cout << "\n" << "Cannot open the input file.\n\n";
	system("pause");
	} */

	if (!inFile.is_open())
	{
		cout << "\n" << "Cannot open the input file.\n\n";
		system("pause");
	}

	// inFile >> bookTitle[count] >> bookAuthor[count];

	// else read data into parallel arrays..and count
	//for (int count = 0; count <= 50; count++)
	//cin >> bookAuthor[count] >> bookTitle[count];
	//inFile >> bookTitle[count];
	//and count
	//then return count of number of books read into array
	
	while (getline(inFile, line))
	{
		// First line in the pair of lines
		if (lineCounter == 1) {
			// Line is for the title of the book
			bookTitle[count] = line;
			// Going to the next line now
			lineCounter++;
		}
		// Second line in the pair of lines
		else if (lineCounter == 2) {
			// Line is for the author of the book
			bookAuthor[count] = line;
			// Go to the next line, which is the first line in the next pair of lines
			lineCounter = 1;
			// Another book has been fully stored into the arrays
			count++;
		}
		/* getline(inFile, author);
		bookTitle[count] = title;
		bookAuthor[count] = author;
		in.File.ignore('\n'); */
	}
	/* count++;
	inFile >> bookTitle[count]
	>> bookAuthor[count]; */

	inFile.close();
	inFile.clear(std::ios_base::goodbit);

	return count;
}

// Function to provide number of books stored in database
// ie value returned by function loadData()
// Read number of records in parallel array and display
void showAll(int count) {

	for (int i = 0; i < count; i++)
	{
		cout << bookTitle[i] << "\n";
		cout << bookAuthor[i] << "\n";
	}
}

// Function to show user menu
void showMenu(int count) {

	char selection;

	cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All: ";
	cin >> selection;
	selection = toupper(selection);

	switch (selection)
	{
		case ('Q') :
		{
			exit(0);
			break;
		}
		case ('A') :
		{
			// Display all records that contain designate text 
			// SOMEWHERE in the author field
			// Call showBooksByAuthor function
			showBooksByAuthur(count);
			break;
		}
		case ('T') : {
			// Display all records that contain designate text 
			// SOMEWHERE in the title field
			// Search by title -> Call showBooksByTitle function to 
			showBooksByTitle(count);
			break;
		}
		case ('S') : {
			// Display all records in database using showAll function
			showAll(count);
			break;
		}
	}
}

int showBooksByAuthur(int count)
{
	// Case insensitive. 
	// Function should display all books whose author field contains 
	// the string passed in the parameter called name.
	// It returnds the number of books displayed. 
	//Count specifies the number of books in the database.

	string name;

	cout << "Author's Name: ";
	cin.ignore();
	getline(cin, name);

	// List/Output to console the number of books written by author
	int x = 0;
	for (int i = 0; i < count; i++)
	{
		if (bookAuthor[i].find(name))
		{
			cout << bookTitle[i];
			cout << "(" << bookAuthor[i] << ")" << "\n";
			x++;

			cout << x << "records found." << "\n";
		}
		// if author not found
		else
		{
			cout << "0 records found.\n\n";
		}
	}

	return count;
}

int showBooksByTitle(int count)
{
	// Case insensitive
	// Display all books whose title field contains the string passed in 
	// the parameter called title. 
	// It returnds the number of books displayed. 
	// Count specifies the number of books in the database.

	string title;

	cout << "Title: ";
	cin.ignore();
	getline(cin, title);

	//return book titles found
	int x = 0;
	for (int i = 0; i < count; i++)
	{
		if (bookTitle[i].find(title))
		{
			cout << bookTitle[i];
			x++;

			cout << x << "records found." << "\n";
		}

		// else not found
		else
		{
			cout << "0 records found.\n\n";
		}

	}

	return count;
}