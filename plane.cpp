#include "planeClass.h"

//plane constructor
plane::plane(seat seatchart[numRows][numColumns]) {
	int tempR = 0;
	bool tempReserved = 0;
	char tempC;
	ifstream infile;
	int col, row;
	//Makes sure code doesn't break rows and columns are greater than max.
	if ((numRows > 1000) && (numColumns > 26))
	{
		col = 26;
		row = 1000;
	}
	else if (numRows > 1000)
	{
		col = numColumns;
		row = 1000;
	}
	else if (numColumns > 26)
	{
		col = 26;
		row = numRows;
	}
	else {
		col = numColumns;
		row = numRows;
	}

	infile.open("chartIn.txt");
	for (int i = 0; i < row; i++)
	{

		int x;
		infile >> x; //Pulls data from chartIn.txt.
		for (int j = 0; j < col; j++) {

			seatchart[i][j].setR(x);
			infile >> tempC;
			seatchart[i][j].setC(tempC); //loop stores contents from file to seatchart.
		}

	}
	infile.close();


}
//Method to Display seats
void plane::DisplaySeats(seat seatchart[numRows][numColumns]) {
	int tempR;
	bool tempReserved;
	char tempC;

	//Makes sure code doesn't break rows and columns are greater than max.
	//Extra Credit
	int col, row;
	if ((numRows > 1000) && (numColumns > 26))
	{
		col = 26;
		row = 1000;
	}
	else if (numRows > 1000)
	{
		col = numColumns;
		row = 1000;
	}
	else if (numColumns > 26)
	{
		col = 26;
		row = numRows;
	}
	else {
		col = numColumns;
		row = numRows;
	}

	for (int i = 0; i < row; i++)
	{
		int j = 0;
		cout << i + 1 << " ";
		for (j; j < col; j++) {

			cout << seatchart[i][j].getC() << " ";
		}
		cout << endl;
	}
}
//Method for Reserve Seats
void plane::ReserveSeats(seat seatchart[numRows][numColumns]) {

	int tempR;
	bool tempReserved;
	char tempC;
	istringstream tempCin;
	string allSeatSelection;
	int col, row, reserveRow;
	char b, defense;
	//Makes sure code doesn't break rows and columns are greater than max.
	if ((numRows > 1000) && (numColumns > 26))
	{
		col = 26;
		row = 1000;
	}
	else if (numRows > 1000)
	{
		col = numColumns;
		row = 1000;
	}
	else if (numColumns > 26)
	{
		col = 26;
		row = numRows;
	}
	else {
		col = numColumns;
		row = numRows;
	}

	if (numColumns > 26) {
		defense = 'Z';
	}
	else {
		defense = allCols[col - 1];
	}
	bool isFilled = 1;
	// do while reserves seats
	do
	{
		isFilled = 1;
		tempCin.clear();
		if (tempCin.fail()) {
			tempCin.clear();
			tempCin.ignore();
		}
		cout << "Please enter a seat to reserve (ex. 3A)" << endl;
		cin >> allSeatSelection;

		tempCin.str(allSeatSelection);
		tempCin >> reserveRow;
		tempCin >> b;
		b = toupper(b);
		if ((reserveRow > row) || (reserveRow < 0)) {
			cout << "Must be a valid seat" << endl;
			isFilled = false;
		}
		if ((b > defense) || (defense < 'A')) {
			cout << "Must be a valid seat" << endl;
			isFilled = false;
		}
	} while ((tempCin.fail()) || (!isFilled));


	int tempIndex = 0;
	for (int i = 0; i < numColumns; i++) {

		if (seatchart[reserveRow - 1][i].getC() == b) {
			tempIndex = i;

		}
	}
	seatchart[reserveRow - 1][tempIndex].setR(true);
	seatchart[reserveRow - 1][tempIndex].setC('X');

	for (int i = 0; i < numRows; i++)
	{
		int j = 0;
		for (j; j < numColumns; j++) {

			if (seatchart[reserveRow - 1][tempIndex].getReserved() == true) {
				tempIndex++;
			}
		}
	}
	cout << "Reserved Seat: " << reserveRow << b << endl;
}
//Method for Canceling a seat
void plane::CancelReservation(seat seatchart[numRows][numColumns]) {
	int tempR;
	bool tempReserved;
	char tempC;
	istringstream tempCin;
	string allSeatSelection;
	int col, row, reserveRow;
	char b, defense;
	//Makes sure code doesn't break rows and columns are greater than max.
	if ((numRows > 1000) && (numColumns > 26))
	{
		col = 26;
		row = 1000;
	}
	else if (numRows > 1000)
	{
		col = numColumns;
		row = 1000;
	}
	else if (numColumns > 26)
	{
		col = 26;
		row = numRows;
	}
	else {
		col = numColumns;
		row = numRows;
	}


	if (numColumns > 26) {
		defense = 'Z';
	}
	else {
		defense = allCols[col - 1];
	}
	bool isFilled = 1;
	do
	{
		//allows user to cancel seats that were reserved
		isFilled = 1;
		tempCin.clear();
		if (tempCin.fail()) {
			tempCin.clear();
			tempCin.ignore();
		}
		cout << "Enter a seat that you would like to cancel? (ex.3A)." << endl;
		cin >> allSeatSelection;

		tempCin.str(allSeatSelection);
		tempCin >> reserveRow;
		tempCin >> b;
		b = toupper(b);
		if ((reserveRow > row) || (reserveRow < 0)) {
			cout << "Must be a valid seat." << endl;
			isFilled = false;
		}
		if ((b > defense) || (defense < 'A')) {
			cout << "Must be a valid seat." << endl;
			isFilled = false;
		}
	} while ((tempCin.fail()) || (!isFilled));



	int tempIndex = 0;
	for (int i = 0; i < numColumns; i++)
	{

		if (seatchart[reserveRow - 1][i].getC() == 'X')
		{
			tempIndex = i;

		}
	}

	if (seatchart[reserveRow - 1][tempIndex].getC() == 'X')
	{
		seatchart[reserveRow - 1][tempIndex].setC(b);
		seatchart[reserveRow - 1][tempIndex].setReserved(false);
		cout << "Seat removed." << endl;
	}
	else
	{
		cout << "Seat has not already been reserved." << endl;
	}

}
//Method for saving the seat chart to a file
void plane::SaveChartToFile(seat seatchart[numRows][numColumns]) {
	int tempR;
	bool tempReserved;
	char tempC;
	int col, row;
	//Makes sure code doesn't break rows and columns are greater than max.
	if ((numRows > 1000) && (numColumns > 26))
	{
		col = 26;
		row = 1000;
	}
	else if (numRows > 1000)
	{
		col = numColumns;
		row = 1000;
	}
	else if (numColumns > 26)
	{
		col = 26;
		row = numRows;
	}
	else {
		col = numColumns;
		row = numRows;
	}
	//saves seat chart to a file the user names
	ofstream outFile;
	string fileName;
	cout << "Please type in file name with \".txt\" at the end: ";
	cin.ignore();
	getline(cin, fileName);
	for (int i = 0; i < fileName.size(); i++) {
		if (fileName.at(i) == ' ') {
			fileName.at(i) = '_';
		}
	}

	if ((fileName.substr(fileName.size() - 4, 4) != ".txt"))
		fileName += ".txt";
	outFile.open(fileName);



	for (int i = 0; i < row; i++) {

		outFile << i + 1 << " ";
		for (int j = 0; j < col; j++) {

			outFile << seatchart[i][j].getC() << " ";
		}
		outFile << endl;
	}
	outFile.close();
	cout << "Done!" << endl;

}
//Method for statistics
void plane::Statistics(seat seatchart[numRows][numColumns]) {
	int tempR;
	bool tempReserved;
	char tempC;
	int col, row, reservedSeat = 0, numAisleSeats = 0, numWindowSeats = 0;
	float temp;

	//Makes sure code doesn't break rows and columns are greater than max.
	if ((numRows > 1000) && (numColumns > 26))
	{
		col = 26;
		row = 1000;
	}
	else if (numRows > 1000)
	{
		col = numColumns;
		row = 1000;
	}
	else if (numColumns > 26)
	{
		col = 26;
		row = numRows;
	}
	else
	{
		col = numColumns;
		row = numRows;
	}
	const int totalSeat = row * col; //Multiplies rows and columns to give total seats
	temp = totalSeat;
	seat tester[1000], //prevents stack from getting infected
		WindowSeat[2 * numRows], AisleSeat[(numRows * numColumns) - (2 * numRows)];
	//Keeps array within range
	for (int i = 0; i < numRows; i++)
	{
		int count = i + 1;
		for (int j = 0; j < numColumns; j++)
		{
			if ((j == 0) || (j == col - 1))
			{
				if (seatchart[i][j].getReserved() == false)
				{
					//counts number of window seats available
					numWindowSeats++;
				}
			}
			else
			{
				if (seatchart[i][j].getReserved() == false)
				{
					//counts number of aisle seats available
					numAisleSeats++;
				}


			}

		}

	}

	int work = 0, index = 0;
	//Stores list of aisle seats
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			if ((j > 0) && (j < col - 1))
			{
				if (seatchart[i][j].getReserved() == false)
				{

					AisleSeat[work].setC(seatchart[i][j].getC());
					AisleSeat[work].setR(seatchart[i][j].getR());
					//AisleSeat[work].row = seatchart[i][j].reserved;
					work++;
				}
			}

		}

	}
	//stores list of window seats
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			if ((j == 0) || (j == col - 1))
			{
				if (seatchart[i][j].getReserved() == false)
				{


					WindowSeat[index].setC(seatchart[i][j].getC());
					WindowSeat[index].setR(seatchart[i][j].getR());
					//WindowSeat[index].reserved = seatchart[i][j].reserved;
					index++;
				}
			}
		}



	}
	//counts amount of reserved seats
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (seatchart[i][j].getC() == '#')
			{
				reservedSeat++;
			}
		}
	}



	cout << "There are " << totalSeat - reservedSeat << " seats availiable" << endl;
	cout << setprecision(3) << reservedSeat / temp * 100 << '%' << " of seats are reserved." << endl;
	cout << "Remaining aisle seats available " << endl;
	for (int i = 0; i < work; i++)
	{
		cout << AisleSeat[i].getR() << AisleSeat[i].getC() << ", ";
	}

	cout << endl << "The following are the remaining avaliable window seats" << endl;
	for (int i = 0; i < index; i++)

	{
		cout << WindowSeat[i].getR() << WindowSeat[i].getC() << ", ";
	}
	cout << endl;
}
