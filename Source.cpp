// * Purpose : To code a program that will display a menu for plane seats

#include "planeClass.h"
int main() {

	int mainPage;
	//Part of the constructor
	assemble();

	seat seatchart[numRows][numColumns];
	//Declaration of variable of type plane
	plane myplane(seatchart);
	//Switch statements thar allows user to interact with the code
	do {
		Menu(mainPage);
		switch (mainPage) {
		case 1: myplane.DisplaySeats(seatchart);
			break;
		case 2: myplane.ReserveSeats(seatchart);
			break;
		case 3: myplane.CancelReservation(seatchart);
			break;
		case 4: myplane.SaveChartToFile(seatchart);
			break;
		case 5: myplane.Statistics(seatchart);
			break;
		case 6: Help();
			break;
		case 7:
			break;
		default: break;
		};
	} while (mainPage != (7));

	cout << "Thank you";

	return 0;

}
