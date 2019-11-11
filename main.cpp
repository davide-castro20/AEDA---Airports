#include "Utils.h"
#include "Menus.h"
#include "Company.h"

Company *comp;
extern Airport* currentAirport;

int main()
{
	comp = new Company("Airports.txt");
	//for(int i = 0;i< comp->getAirports().at(0)->employees.size();i++)
	//cout << comp->getAirports().at(0)->employees.at(i)->getFlights().size() << endl;
    companyMenu();
	return 0;
}