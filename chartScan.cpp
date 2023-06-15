#include "planeClass.h"

void assemble() {
	ofstream outFile;
	ifstream inFile;
	outFile.open("chartIn.txt");

	char temp[numColumns], allCols[]{ 'A', 'B','C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < numColumns; i++) {
		temp[i] = allCols[i];
	}
	//Makes sure rows and columns are in bounds
	for (int i = 1; i <= numRows; i++) {
		if (i > 1000) {
			cout << "Reached Row Limit." << endl;
			return;
		}
		outFile << i << " ";
		for (int j = 0; j < numColumns; j++) {
			if (j > 25) {
				break;
			}
			outFile << allCols[j] << " ";
		}
		outFile << endl;
	}
	outFile.close();
}
