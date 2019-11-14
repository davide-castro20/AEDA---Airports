#include "Utils.h"
#include "Menus.h"
#include "Airport.h"
#include "DeleteFunctions.h"
#include "CreateFunctions.h"
#include "ChangeFunctions.h"
#include "Company.h"
#include "Save.h"
#include "ShowFunctions.h"

Airport *currentAirport;

extern Company* comp;

using namespace std;

void showDataMenu()
{
	bool badInput = true;
	int ShowSelect;
	int cont = 0;
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Which data to read?\n" << "1)A Person.\n" << "2)A Flight.\n" << "3)A Plane.\n" << "0)Return to the last menu.\n";
			cin >> ShowSelect;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || ShowSelect <= -1 || ShowSelect > 3)
			{
				cin.clear();
				cin.ignore(100, '\n');
				badInput = true;
			}
			else
			{
				badInput = false;
			}

		} while (badInput);
		cin.ignore(1000, '\n');
		switch (ShowSelect)
		{
		case 1:
			showPersonMenu();
			break;
		case 2:
			showFlightMenu();
			break;
		case 3:
			showPlaneMenu();
			break;
		case 0:
			break;
		}
	} while (ShowSelect != 0);
}

void createDataMenu()
{
	bool badInput = true;
	int Selection;
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "What data do you want to create: \n1)A New Person.\n2)A New Flight.\n3)A New Plane.\n0)Return to main menu.\n";
			cin >> Selection;
			if (cin.fail() || Selection < 0 || Selection > 3)
			{
				cin.clear();
				cin.ignore(100, '\n');
				badInput = true;
			}
			else
			{
				badInput = false;
			}
		} while (badInput);
		switch (Selection)
		{
		case 0:
			break;
		case 1:
			createPerson();
			break;
		case 2:
			createFlight();
			break;
		case 3:
			createPlane();
			break;
		}
	} while (Selection != 0);
}

void changeDataMenu()
{
	bool badInput = true;
	int selection;
	do
	{
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "What do you want to change?\n1)A Person.\n2)A Flight.\n3)A Plane.\n4)Add an employee or plane to a flight.\n0)Return to main menu.\n";
			cin >> selection;
			if (cin.fail() || selection < 0 || selection > 4)
			{
				cin.clear();
				cin.ignore(100, '\n');
				badInput = true;
			}
			else
			{
				badInput = false;
			}
		} while (badInput);
		switch (selection)
		{
		case 1:
			changePersonData();
			break;
		case 2:
			changeFlightData();
			break;
		case 3:
			changePlaneData();
			break;
		case 4:
			addToFlight();
		case 0:
			break;
		}
	} while (selection != 0);
}

void deleteDataMenu()
{
	bool badInput = true;
	int toDelSelection = 0;
	do
	{
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "What do you want to delete?\n1)A Person.\n2)A Flight.\n3)A Plane\n0)Return to main menu.\n";
			cin >> toDelSelection;
			if (cin.fail() || toDelSelection < 0 || toDelSelection>3)
			{
				toDelSelection = true;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else
			{
				badInput = false;
			}
		} while (badInput);
		switch (toDelSelection)
		{
		case 1:
			deletePersonData();
			break;
		case 2:
			deleteFlightData();
			break;
		case 3:
			deletePlaneData();
			break;
		case 0:
			break;
		}
	} while (toDelSelection != 0);
}

void expensesMenu()
{
	int sel;
	bool badInput = false;
	do 
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Would you like to see the planes or employees expenses?\n1)Planes.\n2)Employees.\n3)See all in between two dates.\n0)Exit.\n";
		cin >> sel;
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (cin.fail() || sel > 3 || sel < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			badInput = true;
		}
		else
		{
			if (sel == 0)
				return;
			else if (sel == 1)
			{
				showPlanesExpenses();
				return;
			}
			else if (sel == 2)
			{
				showEmployeeExpenses();
				return;
			}
			else if (sel == 3)
			{
				datesExpenses();
				return;
			}
		}
	} while (badInput);
}

void mainMenu() {
	bool badInput = true;
	int select;
	do
	{
		badInput = false;
		cout << "---------------------------------------------------------------------------------------------------\n";
		cout << "What do you want to do: " << endl << "1)Read Data." << endl << "2)Create data." << endl << "3)Change Data" << endl << "4)Delete data." << endl << "5)This company expenses." << endl << "0)Return to company Menu\n";
		cin >> select;
		if (cin.fail() || select > 5 || select < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			badInput = true;
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (select)
			{
			case 0:
				return;
				break;
			case 1:
				showDataMenu();
				break;
			case 2:
				createDataMenu();
				break;
			case 3:
				changeDataMenu();
				break;
			case 4:
				deleteDataMenu();
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			case 5:
				expensesMenu();
				break;
			}
		}
	} while (badInput || (select != 0));
	
}

void selectAirportMenu()
{
	bool badInput = true;
	unsigned int select;
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Which airport do you want to see the data of: \n";
		for (size_t i = 0; i < comp->getAirports().size(); i++)
			cout << i + 1 << ")" << comp->getAirports().at(i)->getLocal().getCity() << ", " << comp->getAirports().at(i)->getLocal().getCountry() << endl;
		cout << endl;
		cout << "0)Back\n";
		cin >> select;
		if (cin.fail() || select >= comp->getAirports().size() + 1 || select < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			badInput = true;
		}
		else
			badInput = false;
	} while (badInput);
	if (select == 0)
		return;
	currentAirport = comp->getAirports().at(select - 1);
	mainMenu();
}

void companyMenu()
{
	cin.sync();
	int sel;
	bool badInput = false;
	cout << '.' << string(98, '_') << '.' << endl
		<< '|' << string(98, ' ') << '|' << endl
		<< '|' << string(39, '-') << "WELCOME to our company" << string(37, '-') << '|' << endl
		<< '|' << string(98, ' ') << '|' << endl
		<< '|' << string(98, '_') << '|' << endl << endl;
	do {
		do
		{
			cout << string(100, '-') << endl;
			cout << "What would you like to do? \n";
			cout << "1)Select a airport to inspect.\n2)See airports specification.\n3)Create a new airport.\n4)Delete Airport Data.\n0)Close Program." << endl;
			cin >> sel;
			if (cin.fail() || sel < 0 || sel>4)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				badInput = true;
			}
			else { badInput = false; };
		} while (badInput);
		switch (sel) {
		case 0:
			SaveFlights();
			SaveEmployees();
			SavePlanes();
			saveAirports();
			return;
		case 1:
			selectAirportMenu();
			break;
		case 2:
			for (size_t i = 0; i < comp->getAirports().size(); i++)
				showAirportData(comp->getAirports().at(i));
			break;
		case 3:
			createAirport();
			break;
		case 4: 
			deleteAirportData();
		}
	} while (sel != 0);
}

