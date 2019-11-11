#include "Utils.h"
#include "Menus.h"
#include <iomanip>
#include "ShowFunctions.h"


using namespace std;


void showAirportData(Airport * airport)
{
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << setfill('-') << setw(49) << airport->local.getCity()
		<< " Airport" << setw(42) << setfill('-') << '|' << endl;
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Location " << '|' << left << setw(48) << ' ' + airport->local.getCity()
		+ ", " + airport->local.getCountry() << '|' << endl;
	cout << '|' << string(49, ' ') << '|' << setw(48) << left << to_string(airport->local.getLatit()) + " N "
		+ to_string(airport->local.getLon()) + " W " << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->planes.size() << left << setw(49) << " Planes" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->employees.size() << left << setw(49) << " Employees" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->flights.size() << left << setw(49) << " possible flights" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
}


void showPersonData(Employee* emp)
{

}
