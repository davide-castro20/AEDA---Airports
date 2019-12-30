#include "Utils.h"
#include "Menus.h"
#include "Airport.h"
#include "DeleteFunctions.h"
#include "CreateFunctions.h"
#include "ChangeFunctions.h"
#include "Company.h"
#include "Save.h"
#include "ShowFunctions.h"
#include <cmath>
#include "Maintenance.h"

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


void doMaintenance() {
	if (comp->getMaintenaceCompanies().empty())
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "No companies available to perform maintenance.\n";
		return;
	}
	priority_queue<Maintenance> aux;
	priority_queue<Maintenance> second = comp->getMaintenaceCompanies();
	comp->clearMaintenance();
	Maintenance auxM;
	auxM = second.top();
	second.pop();
	Maintenance toPush(rand() % 9 + 15, auxM.getMaintenances() + 1, auxM.getName());
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Company " << toPush.getName() << " did maintenance on your planes and will be available in " << toPush.getHours() << " hours\n";
	aux.push(toPush);
	while (!second.empty()) {
		auxM = second.top();
		second.pop();
		int hours = auxM.getHours();
		if (hours - 3 < 0) {
			hours = 0;
		}
		else {
			hours -= 3;
		}
		Maintenance toPush(hours, auxM.getMaintenances(), auxM.getName());
		aux.push(toPush);
	}
	while (!aux.empty()) {
		comp->addMaintenanceCompany(aux.top());
		aux.pop();
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
			cout << "What data do you want to create: \n1)A New Person.\n2)A New Flight.\n3)A New Plane.\n4)A new manager\n0)Return to main menu.\n";
			cin >> Selection;
			cin.ignore(100, '\n');
			if (cin.fail() || Selection < 0 || Selection > 4)
			{
				cin.clear();
				//cin.ignore(100, '\n');
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
		case 4:
			createManager();
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
			cout << "What do you want to update?\n1)A Person.\n2)A Flight.\n3)A Plane.\n4)Add an employee or plane to a flight.\n5)Manager's salary.\n0)Return to main menu.\n";
			cin >> selection;
			cin.ignore(100, '\n');
			if (cin.fail() || selection < 0 || selection > 5)
			{
				cin.clear();
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
			break;
		case 5:
			changeManagerSalary();
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
			cout << "What do you want to delete?\n1)A Person.\n2)A Flight.\n3)A Plane\n4)Delete manager\n0)Return to main menu.\n";
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
			deletePersonData();
			break;
		case 2:
			deleteFlightData();
			break;
		case 3:
			deletePlaneData();
			break;
		case 4: 
			deleteManager();
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
		cout << "What do you want to do: " << endl << "1)Read Data." << endl << "2)Create data." << endl << "3)Change Data" << endl << "4)Delete data." << endl << "5)This airport's expenses." << endl << "6)Do maintenance" << endl<< "0)Return to company Menu\n";
		cin >> select;
		if (cin.fail() || select > 6 || select < 0)
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
			case 6:
				doMaintenance();
				break;
			}
		}
	} while (badInput || (select != 0));
	
	
}

void selectAirportMenu()
{
	bool badInput = true;
	int counter = 0;
	unsigned int select;
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Which airport do you want to see the data of: \n";
		for (auto i : comp->getAirports())
		{
			++counter;
			cout << counter << ")" << i->getLocal().getCity() << ", " << i->getLocal().getCountry() << endl;
		}
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
	select--;
	for (auto i : comp->getAirports()) {
		if(select==0)
			currentAirport = i;
		select--;
	}
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
			cout << "1)Select a airport to inspect.\n2)See airports specification.\n3)Show Employees.\n4)Create a new airport.\n5)Delete Airport Data.\n6)Create Maintenance company.\n7)Delete Maintenance company. \n0)Close Program." << endl;
			cin >> sel;
			if (cin.fail() || sel < 0 || sel > 7)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				badInput = true;
			}
			else { badInput = false; };
		} while (badInput);
		switch (sel) {
		case 0:
			/*
			SaveFlights();
			SaveEmployees();
			SaveOldEmployees();
			SavePlanes();
			saveAirports();
			saveMaintenance();
			*/
			return;
		case 1:
			selectAirportMenu();
			break;
		case 2:
			for (auto i : comp->getAirports())
				showAirportData(i);
			break;
		case 3:
			showPersonMenuCompany();
			break;
		case 4:
			createAirport();
			break;
		case 5: 
			deleteAirportData();
			break;
		case 6:
			createMaintence();
			break;
		case 7:
			deleteMaintenence();
			break;
		}
	} while (sel != 0);
	
}