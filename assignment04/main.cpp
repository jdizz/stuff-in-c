/***********************************
Jason Davis
July 17, 2016
CS161
Assignment 4: Advertising Survey
Sources: Textbook, Class Documents, Class Mates, Internet Research
************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {

	// Declare input/output file stream objects
	ifstream inFile;

	// Declare input file variables
	string inFileName;
	string subjectName = "";
	int subjectAge = 0;
	string seenAd = "";
	int score = 0;
	string line = "";

	// Declare variables for average calculations
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	double under18YAverage = 0.0, under18NAverage = 0.0, over18YAverage = 0.0, over18NAverage = 0.0;
	double under18YSum = 0.0, under18NSum = 0.0, over18YSum = 0.0, over18NSum = 0.0;
	double allAverage = 0.0;

	// Formatting output to fixed point and show two decimal places
	cout << fixed << showpoint << setprecision(2);

	// Prompt user to enter full the full file path to the file they want to open
	cout << "Please enter the full pathname "
		 << "to the file you would like to open: ";
	getline(cin,inFileName);
	cout << endl;

	//Associate declared file stream operators with I/O sources to open files
	inFile.open(inFileName.c_str());
	
	// If file does not exist, 
	// program outputs error message and exits
	if ( ! inFile.is_open())
		{
			cout << "Error - could not open: " << inFileName << endl;
			system("pause");
		}

	// Close and reopen file and stream
	inFile.close();
	inFile.open(inFileName.c_str());

	// While loop adding objects to stream variables
	while (inFile >> subjectName >> seenAd >> subjectAge >> score)
	{
		// Echo text file contents and count lines
		cout << subjectName << " " << seenAd << " " << subjectAge << " " << score;
		cout << "\n";
		count5++;

		// If/Else logic and counters to make average calculations
		if (subjectAge < 18)
		{
			if (seenAd == "Y") 
			{
				under18YSum = score + under18YSum;
				count1++;
				under18YAverage = under18YSum / count3;
			}

			else 
			{
				under18NSum = score + under18NSum;
				count2++;
				under18NAverage = under18NSum / count2;
			}
		}

			else 
		{
			if (seenAd == "Y") 
			{
				over18YSum = score + over18YSum;
				count3++;
				over18YAverage = over18YSum / count3;
			}

			else 
			{
				over18NSum = score + over18NSum;
				count4++;
				over18NAverage = over18NSum / count4;
			}
		}

	}

	// Calculate average score for all subjects 
	allAverage = (under18NSum + under18YSum + over18NSum + over18YSum) / count5;
	
	// Output average calculations
	cout << "\n\nAverage score for subjects under 18 who have not seen the ad: " << under18NAverage << "\n";
	cout << "Average score for subjects under 18 who have seen the ad: " << under18YAverage << "\n";
	cout << "Average score for subjects 18 and over who have not seen the ad: " << over18YAverage << "\n";
	cout << "Average score for subjects 18 and over who have seen the ad: " << over18NAverage << "\n";
	cout << "Average score for all subjects: " << allAverage << "\n\n";

	// Clear input file stream
	inFile.clear(std::ios_base::goodbit);
	inFile.seekg(0);
	
	// Close input file stream
	inFile.close();

	// Pause console for output review and program termination
	system("pause");
}