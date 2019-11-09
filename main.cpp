#include "Utils.h"
#include "Menus.h"
#include "Company.h"

Company *comp;
extern Airport* currentAirport;

int main()
{
	comp = new Company("Airports.txt");
	currentAirport = comp->getAirports().at(0);
    selectAirportMenu();
	return 0;
}