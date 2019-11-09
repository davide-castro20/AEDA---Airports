#include "Utils.h"
#include "Menus.h"
#include "Company.h"

Company *comp;

int main()
{
	comp = new Company("Airports.txt");
	selectAirportMenu();
	return 0;
}