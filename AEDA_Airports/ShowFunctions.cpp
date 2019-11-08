#include "Utils.h"
#include "Menus.h"
#include "ShowFunctions.h"

extern Airport* currentAirport;

using namespace std;

void showPersonData()
{
	cout << "-----------------------------------------------------------------------------------------------------\n";

}

void showAirportData()
{
	cout << '.' << string(98, '_') << '.' << endl;
	cout << '|' << string(98, ' ') << '|' << endl;
	cout << '|' << setfill('-') << setw(49) << currentAirport->local.getCity()
		<< "'s Airport" << setw(40) << setfill('-') << '|' << endl;
	cout << '|' << string(98,'_') << '|' << endl;
	cout << '|' << string(49,' ') << '|' << string(48,' ') << '|' << endl;
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
	cout << '|' << string(98, '_') << '|' << endl;
}

//void showAirports(Company &company)
//{
//	for(size_t i = 0; i < company.)
//}

