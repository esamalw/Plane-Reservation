#include "planeClass.h"

int Menu(int& userSelection) {
	cout << "------------------------Menu----------------------------" << endl;
	cout << "1. Display Seat Chart" << endl;
	cout << "2. Reserve Seat" << endl;
	cout << "3. Cancel Reservation" << endl;
	cout << "4. Save Seat Chart to File" << endl;
	cout << "5. Statistics" << endl;
	cout << "6. Help" << endl;
	cout << "7. Quit" << endl;
	cout << "--------------------------------------------------------" << endl;

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
		cout << "Please Enter Your Choice(1 - 7) : ";
		cin >> userSelection;
	} while (cin.fail());
	return userSelection;
}
