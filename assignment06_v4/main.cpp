#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int SUM_ARR_SZ = 100;

struct namesAndSums
{
	//    unsigned int checksum[SUM_ARR_SZ];
	vector<unsigned int> checksum;
	string fileNames[SUM_ARR_SZ];

};

int main() {

	string fileName;
	char keyInput;
	int i = 0;
	unsigned int sum = 0;

	ifstream inFile;
	string filePath;

	namesAndSums collectionInfo;

	while (keyInput != 'Q' || keyInput != 'q') {

		//Open the specified file in binary mode
		cout << "Please select: " << endl;
		cout << "A) Compute checksum of specified file\n"
			"B) Verify integrity of specified file\n"
			"Q) Quit" << endl;
		cin >> keyInput;

		if (keyInput == 'A' || keyInput == 'a') {
			cout << "Specify the file path: ";
			cin >> filePath;
			//find last back slash and store from it to end of file name
			size_t lastSlash = filePath.find_last_of("/\\");
			fileName = filePath.substr(lastSlash + 1);

			//insert fileName into fileNames array
			collectionInfo.fileNames->append(fileName);

			inFile.open(filePath.c_str(), ios::binary);

			//get file size
			inFile.seekg(0, ios_base::end);
			int fileLength = inFile.tellg();
			inFile.seekg(0, ios_base::beg);
			char charArr[100000];

			//read file into array
			inFile.read(charArr, fileLength);
			inFile.close();

			//accumulate sum of elements in charArr
			while (i < fileLength) {
				sum += charArr[i];
				i++;
			}

			//store sum in checksum
			collectionInfo.checksum.push_back(sum);
			cout << "file checksum  = " << collectionInfo.checksum[0] << endl;

			cout << endl;
		}

		if (keyInput == 'B' || keyInput == 'b') {
			cout << "Specify the file path: ";
			cin >> filePath;
			//find last back slash and store from it to end of file name
			size_t lastSlash = filePath.find_last_of("/\\");
			fileName = filePath.substr(lastSlash + 1);

			if (collectionInfo.fileNames->find(fileName)) {
				//check for matching checksum and report on integrity of file;
			}
			else {
				cout << "The checksum has not been computed on the file: " << fileName << endl;
			}
		}

		if (keyInput == 'Q' || keyInput == 'q') {
			break;
		}
	}
	return 0;
}