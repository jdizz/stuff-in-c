#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int main() {

	// Declare variables
	string filePath = "";
	ifstream inFile;
	const int arrSize = 1000;
	char charArr[arrSize] = {'\0'};
	int fileLength;
	int i = 0;
	
	// Prompt user for file path
	cout << "Please enter a file path: ";
	getline(cin,filePath);
	cout << "\n" << "The file contents are: " << "\n\n";

	// Open file in binary mode
	inFile.open(filePath.c_str(), ios::binary);

	// Get file size
	inFile.seekg(0, ios_base::end);
	fileLength = inFile.tellg();
	inFile.seekg(0, ios_base::beg);

	// Read file contents into char array, then close file
	inFile.read(charArr, fileLength);
	inFile.close();

	// While loop to iterate through array...
	// and output contents to console
	while (charArr[i] != '\0') {
		cout << charArr[i];
		i++;
	}

	// Pause console for review
	cout << "\n\n";
	system("pause");
}