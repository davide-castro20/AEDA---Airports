#include "Utils.h"
#include "Menus.h"
#include "Company.h"

Company *comp;

int main()
{
	comp = new Company("Airports.txt");
	mainMenu();
	return 0;
}