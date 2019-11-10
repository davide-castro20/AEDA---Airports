#include "Utils.h"
#include "Menus.h"
#include "Company.h"

Company *comp;
extern Airport* currentAirport;

int main()
{
	comp = new Company("Airports.txt");
	cout << comp->getAirports().at(0)->flights.at(0)->getEmployees().size() << endl;
    selectAirportMenu();
	return 0;
}