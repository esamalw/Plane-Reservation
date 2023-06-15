#include "planeClass.h"

//Help funcion
void Help()
{
	cout << "1. Display Seat Chart" << endl;
	cout << "Displays the chart of seats available, and if a seat is marked with \"X\", it is a reseved seat. " << endl;
	cout << "2. Reserve Seat" << endl;
	cout << "Promts the user to reserve a seat (e.g., 3A, 10D, etc.). Reserved seats are marked with a \"#\"." << endl;
	cout << "3. Cancel Reservation" << endl;
	cout << "Promts the user to enter a seat number (e.g., 3A, 10D, etc.) to cancel a seat reservation. Reserved seats are marked with a \"#\"." << endl;
	cout << "4. Save Seat Chart to File" << endl;
	cout << "Promts the usser to enter a name for the seat chart file. Filename ends with \".txt\"" << endl;
	cout << "5. Statistics" << endl;
	cout << "Displays available seats, number of seats available, percentage of seats reserved, and displays list of windowand aisle seats" << endl;
	cout << "6. Help" << endl;
	cout << "Displays a detailed message on how to use each of the menu options in the program." << endl;
	cout << "7. Quit" << endl;
	cout << "The program displays a thank you message and terminates." << endl;
}
