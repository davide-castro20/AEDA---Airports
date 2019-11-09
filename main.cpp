#include "Utils.h"
#include "Menus.h"
#include "Company.h"

Company *comp;
extern Airport* currentAirport;

int main()
{
	comp = new Company("Airports.txt");
    selectAirportMenu();
	return 0;
}