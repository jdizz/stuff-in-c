/********************************************************
Jason Davis
August 01, 2016
CS 161: Data Integrity
Assignment 6: 
Sources: Textboot, Class Documents, and Internet Research
********************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void main() {

	// Decalre variables
	bool finished = false;
	char selection;
	int checksum = 0;
	ifstream inputFile;
	ofstream outFile;
	string inFileFileName;
	string filePath = "";
	const int SUM_ARR_SZ = 100;
	unsigned int checkSums[SUM_ARR_SZ];
	string fileNames[SUM_ARR_SZ];
	char charArr[SUM_ARR_SZ]; 

	while (! finished) {
		// User action selection
		cout << "Please select: " << "\n\n";
		cout << "  A) Compute checksum of specified file" << "\n";
		cout << "  B) Verify integrity of specified file" << "\n";
		cout << "  Q) Quit" << "\n\n";
		cin >> selection;
		cout << "\n";

		// Switch to act on user selection
		switch (selection) {
			case 'A':
				cout << "Specify the file path: " << "\n";
				getline(cin, filePath);
				
				//After that, you can read the entire file contents into your char array in one statement like this:
				// Open file
				inputFile.open(filePath.c_str(),ios::binary);
				inputFile.open("C:\temp\encrypted.txt"); // For debugging, remove when complete

				// Check if file opened
				if (!inputFile.is_open()) {
					cout << "Unable to open input file." << "\n";
					system("pause");
				}

				//To get the file size, use the seekg and tellg operators like this:
			//	inFile.seekg(0, ios_base::end);
				//int fileLen = inFile.tellg();
				//inFile.seekg(0, ios_base::beg);

				//inFile.read(charArr, fileLen);

				// Close file
				//inFile.close();
				//inFile.clear(std::ios_base::goodbit); //for re-opening files

				// Loop to read file into char array
				//for (int i = 0; i > 0; i++) {
				
				//	checksum += charArr[0];
				
				cout << "File checksum = " << checksum;
				
			/*case 'B':
				cout << "Specficy the file path: ";
				getline(cin, filePath);

				inputFile.open(filePath.c_str(), ios::binary);
				inputFile.open("C:\temp\encrypted.txt"); // For debugging, remove when complete

				// Check if file opened
				if (!inputFile.is_open()) {
					cout << "Unable to open input file." << "\n";
					system("pause");
				}
				
				//for loop

				cout << "\n" << "File checksum = " << checksum << "\n";
				
				//if loop ("checksum equals original checksum");

				cout << "The file integrity check has passed successfully (checksum = 0)." << "\n";
				
				//if loop ("checksum does not equal checksum");
				cout << "The file integrity check has failed "
					 << "(previous checksum = x, new checksum = y" << "\n";
					 */
			// User selection to quit program
			case 'Q':
				finished = true;
				break;
		}
		
		cout << "Please try again." << "\n\n";
		system("pause");
		break;
	}
	
	// Pause console for output review
	//cout << "\n\n";
	//system("pause");
}

