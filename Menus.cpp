#include "Utils.h"
#include "Menus.h"
#include "Airport.h"

Airport* currentAirport;

using namespace std;


void readDataMenu()
{
	int ShowSelect;
	int cont = 0;
	bool badInput;
	cout << "-----------------------------------------------------------------------------------------------------\n";
	do
	{
		cout << "Which data to read?\n" << "1)A Person.\n" << "2)A Flight.\n" << "3)A Plane.\n" << "4)An Airport\n" << "0)Return to the last menu.\n";
		cin >> ShowSelect;
		if (cin.fail() || ShowSelect <= -1 || ShowSelect > 4)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
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
		showPersonData();
		break;
	case 2:
		showFlightData();
		break;
	case 3:
		showPlaneData();
		break;
	case 4:
		showAirpotData();
		break;
	case 0:
		break;
	}
}

void createDataMenu()
{
	int Selection;
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "What data do you want to create: \n1)A New Person.\n2)A New Flight.\n3)A New Plane.\n4)A New Airport.\n0)Return to main menu.\n";
		cin >> Selection;
		if (cin.fail() || Selection < 0 || Selection > 4)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
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
		createPersonData();
		break;
	case 2:
		createFlightsData();
		break;
	case 3:
		createPlaneData();
		break;
	case 4:
		createAirportData();
		break;
	}
}

void changeDataMenu()
{
	int selection;
	cout << "-----------------------------------------------------------------------------------------------------\n";
	do
	{
		cout << "What do you want to change?\n1)A Person.\n2)A Flight.\n3)A Plane.\n4)A Airport.\n0)Return to main menu.\n";
		cin >> selection;
		if (cin.fail() || selection < 0 || selection > 4)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
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
		changeClientsData();
		break;
	case 2:
		changeFlightData();
		break;
	case 3:
		changeFlightData();
		break;
	case 4:
		changeAirportData();
		break;
	case 0:
		break;
	}
}

void DeleteDataMenu()
{
	int toDelSelection = 0;
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "What do you want to delete?\n1)A Person.\n2)A Flight.\n3)A Plane4)An Airport\n0)Return to main menu.\n";
		cin >> toDelSelection;
		if (cin.fail() || toDelSelection < 0 || toDelSelection>4)
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
		deleteClientData();
		break;
	case 2:
		deleteFlightData();
		break;
	case 3:
		deletePlaneData();
		break;
	case 4:
		deleteAirportData();
		break;
	case 0:
		break;
	}
}

void mainMenu() {
	int test = 0;
	int select;
	while (test==0)
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "What do you want to do: " << endl << "1)Read Data." << endl << "2)Create data." << endl << "3)Change Data" << endl << "4)Delete data." << endl << "0)Close Program\n";
		cin >> select;
		if (cin.fail() || select > 4 || select < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			cin.ignore(1000, '\n');
			switch (select)
			{
			case 0:
				cout << "Saving changed data...\n";
				savePersonData();
				saveFlightData();
				savePlaneData();
				saveAirportData();
				test = 1;
				cout << "Completed saving data.\n";
				break;
			case 1:
				readDataMenu();
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
	}
	
}