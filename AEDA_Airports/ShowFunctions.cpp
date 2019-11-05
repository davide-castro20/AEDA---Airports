#include "Utils.h"
#include "Menus.h"
#include <iomanip>
#include "ShowFunctions.h"

extern Airport* currentAirport;

using namespace std;

void showPersonData()
{
	cout << "-----------------------------------------------------------------------------------------------------\n";

}

void showAirportData()
{
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << setfill('-') << setw(49) << currentAirport->local.getCity()
		<< " Airport" << setw(42) << setfill('-') << '|' << endl;
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Location " << '|' << left << setw(48) << ' ' + currentAirport->local.getCity()
		+ ", " + currentAirport->local.getCountry() << '|' << endl;
	cout << '|' << string(49, ' ') << '|' << setw(48) << left << to_string(currentAirport->local.getLatit()) + " N "
		+ to_string(currentAirport->local.getLon()) + " W " << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << currentAirport->planes.size() << left << setw(49) << " Planes" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << currentAirport->employees.size() << left << setw(49) << " Employees" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << currentAirport->flights.size() << left << setw(49) << " possible flights" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
}

