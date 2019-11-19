/*******************************************************************
Jason Davis
July 14, 2016
CS 161: Assignment 7: Library Database
Sources: Textbook, Class Documents, Internet Research, and Tutoring
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

// Global variable declarations
const int array_Size = 1000;
string bookTitle[array_Size];
string bookAuthor[array_Size];

// Function prototypes
int loadData(string pathname);
void showAll(int count);
void showBooksByAuthur(int count, string name);
void showBooksByTitle(int count, string name);
void showMenu(int count);

int main()
{
	// Console introduction and input file prompt to user
	string pathname = "";
	cout << "Welcome to Jason Davis's Library Database\n\n";
	cout << "Please enter the name of the database file: ";
	getline(cin, pathname);
	cout << "\n";

	// Call function to load data from input file path
	int numOfBooks = loadData(pathname);

	// Call function to show menu
	showMenu(numOfBooks);

	// pause console
	system("pause");

	return 0;
}

// Function to load data from input file
int loadData(string pathname) {
	
	ifstream inFile;
	string line;
	int count = 0, lineCounter = 0;

	// Open input file
	inFile.open(pathname.c_str());
	
	// Input file error handling
	if (!inFile.is_open()) 
	{
		cout << "\n" << "Cannot open the file.\n\n";
		system("pause");
	}

	else
	{
		// While loop to load data into parallel arrays
		while (getline(inFile, line))
		{
			// If/else logic to load input file into arrays and count
			if (lineCounter % 2 == 0)
			{
				bookTitle[count] = line;
			}

			else
			{
				bookAuthor[count] = line;
				count += 1;
			}

			lineCounter += 1;
		}

		// Close file and clear stream
		inFile.close();
		inFile.clear(std::ios_base::goodbit);
	}

	// Output number of records loaded from input file
	cout << count << " records loaded successfully" << "\n\n";
	return count;
}

// Function to show all array elements
void showAll(int count) 
{
	// For loop to output all array elements
	for (int i = 0; i < count; i++)
		cout << bookTitle[i] << "  (" << bookAuthor[i] << ")" << "\n";
}

// Function to search by author name and display results
void showBooksByAuthur(int count, string name)
{
	int found = 0;

	// for loop to count number search results
	for (int i = 0; i < count; i++) 
	{
		// If logic to find author name and output results
		if (bookAuthor[i].find(name) != std::string::npos) 
		{
			cout << bookTitle[i] << "  (" << bookAuthor[i] << " )" << "\n";
			found += 1;
		}
	}
	// Output number of records found
	cout << " " << found << " records found." << endl;
}

// Function to search by title and display results
void showBooksByTitle(int count, string name)
{
	int found = 0;

	// for loop to count number search results
	for (int i = 0; i < count; i++) 
	{
		// If logic to find book title and output results
		if (bookTitle[i].find(name) != std::string::npos) 
		{

			cout << bookTitle[i] << "  (" << bookAuthor[i] << ")" << endl;
			found += 1;
		}
	}
	// Output number of results found
	cout << " " << found << " records found." << "\n\n";
}

// Function to show user input menu
void showMenu(int count)
{
	char selection;
	string author, title;

	// While loop to output user selection menu
	while (true) 
	{

		cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All: ";
		cin >> selection;
		selection = toupper(selection);

		if (selection == 'Q'){
			break;
		}

		else if (selection == 'A'){
			cout << "\n" << "Author's Name:  ";
			cin.ignore();
			getline(cin, author);
			showBooksByAuthur(count, author);
		}

		else if (selection == 'T'){
			cout << "\n"<< "Title: ";
			cin.ignore();
			getline(cin, title);
			showBooksByTitle(count, title);
		}

		else if (selection == 'S')
			showAll(count);

		else
			cout << "Invalid Selection" << "\n\n";
	}
}