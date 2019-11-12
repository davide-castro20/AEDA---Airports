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
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Which data to read?\n" << "1)A Person.\n" << "2)A Flight.\n" << "3)A Plane.\n" << "0)Return to the last menu.\n";
		cin >> ShowSelect;
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
		//showFlightData();
		break;
	case 3:
		//showPlaneData();
		break;
	case 0:
		break;
	}
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
			cout << "What do you want to change?\n1)A Person.\n2)A Flight.\n3)A Plane.\n0)Return to main menu.\n";
			cin >> selection;
			if (cin.fail() || selection < 0 || selection > 3)
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

void mainMenu() {
	bool badInput = true;
	int select;
	do
	{
		badInput = false;
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "What do you want to do: " << endl << "1)Read Data." << endl << "2)Create data." << endl << "3)Change Data" << endl << "4)Delete data." << endl << "0)Return to company Menu\n";
		cin >> select;
		if (cin.fail() || select > 4 || select < 0)
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
				//savePersonData();
				//saveFlightData();
				//savePlaneData();
				//saveAirportData();
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
			cout << i + 1 << ")" << comp->getAirports().at(i)->getLocal().getCountry() << ", " << comp->getAirports().at(i)->getLocal().getCity();
		cout << endl;
		cin >> select;
		if (cin.fail() || select > comp->getAirports().size() + 1 || select <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
			badInput = false;
	} while (badInput);
	currentAirport = comp->getAirports().at(select - 1);
	mainMenu();
}

void companyMenu()
{
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
			cout << "1)Select a airport to inspect.\n2)See airports specification.\n0)Close Program." << endl;
			cin >> sel;
			if (cin.fail() || sel < 0 || sel>2)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				badInput = true;
			}
		} while (badInput);
		switch (sel) {
		case 0:
			SaveFlights();
			SaveEmployees();
			SavePlanes();
			return;
		case 1:
			selectAirportMenu();
			break;
		case 2:
			for (size_t i = 0; i < comp->getAirports().size(); i++)
				showAirportData(comp->getAirports().at(i));
		}
	} while (sel != 0);
}

