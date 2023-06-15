#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


//Constant Variables
const int numRows = 15;
const int numColumns = 4;
const char allCols[]{ 'A', 'B','C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };



int Menu(int&);

void assemble(); //Creates seat chart (chartIn.txt)
void Help();

class seat {
private:
	//seat attributes
	bool reserved = false; //Tells whether seat if filled
	int row; //row attribute
	char column; //column attribute
public:
	void setR(int row);
	void setC(int row);
	void setReserved(bool);
	int getR();
	char getC();
	bool getReserved();
};

class plane {

private:


	seat seatchart[numRows][numColumns];
public:
	// Methods
	plane(seat seatchart[numRows][numColumns]);  //Uses chartScan.cpp data
	void DisplaySeats(seat seatchart[numRows][numColumns]);
	void ReserveSeats(seat seatchart[numRows][numColumns]);
	void CancelReservation(seat seatchart[numRows][numColumns]);
	void Statistics(seat seatchart[numRows][numColumns]);
	void SaveChartToFile(seat seatchart[numRows][numColumns]);


};

#endif
