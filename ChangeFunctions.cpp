#include "DeleteFunctions.h"
#include "Menus.h"

extern Airport *currentAirport;

void changePersonData()
{
	unsigned int changeSelection,selectionToChange;
	string confirm;
	string name;
	string category;
	string aux;
	vector <int> startTime;
	vector <int> endTime;
	Time *startSchedule;
	string department;
	string function;
	Schedule *schedule;
	Time *endSchedule;
	bool completedChange = false;
	cout << "Whose data do you want to change?(0 to cancel)\n" << endl;
	do {
		do
		{
			for (size_t i = 1; i < currentAirport->employees.size() + 1; i++)
				cout << i << ") " << currentAirport->employees.at(i - 1)->getType() << ":" << currentAirport->employees.at(i - 1)->getName() << "." << endl;
			cin >> changeSelection;
			if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->employees.size() + 1)
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
		cin.clear(100, '\n');
		if (changeSelection == 0)
			return;
		changeSelection--;
		cout << string(100, '\n');
		
		do
		{
			if (currentAirport->employees.at(changeSelection)->getType() == "Pilot") {
				cout << "What do you want to change?\n1) Name\n2) Category\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 3)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << string(100, '\n');
					cout << "There was a problem with your selection, please try again." << string(2, '\n');
					badInput = true;
				}
				else
				{
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "What is the name you want to change to?\n";
							getline(cin, name);
						} while (currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the category you want to change to?\n";
							getline(cin, category);
						} while (currentAirport->employees.at(changeSelection)->setCategory(category));
					}
				}
			}
			else if (currentAirport->employees.at(changeSelection)->getType() == "Flight Crew") {
				cout << "What do you want to change?\n1) Name\n2) Category\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 3)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << string(100, '\n');
					cout << "There was a problem with your selection, please try again." << string(2, '\n');
					badInput = true;
				}
				else
				{
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "What is the name you want to change to?\n";
							getline(cin, name);
						} while (currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the category you want to change to?\n";
							getline(cin, category);
						} while (currentAirport->employees.at(changeSelection)->setCategory(category));
					}
				}
			}
			else if (currentAirport->employees.at(changeSelection)->getType() == "Admin") {
				cout << "What do you want to change?\n1) Name\n2) Department\n3) Function\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 4)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << string(100, '\n');
					cout << "There was a problem with your selection, please try again." << string(2, '\n');
					badInput = true;
				}
				else
				{
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "What is the name you want to change to?\n";
							getline(cin, name);
						} while (currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the department you want to change to?\n";
							getline(cin, department);
						} while (currentAirport->employees.at(changeSelection)->setDepartment(department));
					}
					if (selectionToChange == 3) {
						do
						{
							cout << "What is the function you want to change to?\n";
							getline(cin, function);
						} while (currentAirport->employees.at(changeSelection)->setDepartment(function));
					}

				}
			}
			else if (currentAirport->employees.at(changeSelection)->getType() == "Base Crew") {
				cout << "What do you want to change?\n1) Name\n2) Category\n3) Schedule\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 4)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << string(100, '\n');
					cout << "There was a problem with your selection, please try again." << string(2, '\n');
					badInput = true;
				}
				else
				{
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "What is the name you want to change to?\n";
							getline(cin, name);
						} while (currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the category you want to change to?\n";
							getline(cin, category);
						} while (currentAirport->employees.at(changeSelection)->setCategory(category));
					}
					if (selectionToChange == 3) {
						do
						{
							cout << "What is the schedule you want to change to?(Ex: 10:30 (enter) 18:30)\n";
							getline(cin, aux);
							decomposeInt(aux, startTime, ':');
							getline(cin, aux);
							decomposeInt(aux, endTime, ':');
							startSchedule = new Time(startTime[0], startTime[1]);
							endSchedule = new Time(endTime[0], endTime[1]);
							schedule = new Schedule(startSchedule, endSchedule);
							
						} while (currentAirport->employees.at(changeSelection)->setSchedule(schedule));
					}
				}
			}
		} while (badInput);
		do
		{
			cout << "Are you sure you want to change the following employee?(y/n)\n";
			//currentAirport->employees.at(changeSelection)->showEmp();
			cin >> confirm;
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
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
			if (confirm == "y" || confirm == "Y")
			{
				badInput = false;
				completedChange = true;
			}
			if (confirm == "n" || confirm == "N")
			{
				badInput = false;
				completedChange = false;
			}

		} while (badInput);
	} while (!completedChange);
}

/*
void deletePlaneData()
{
	int delSelection;
	string confirm;
	bool completedDel = false;
	cout << "Which plane data do you want to delete?(0 to cancel)\n" << endl;
	do {
		do
		{
			for (size_t i = 1; i < currentAirport->planes.size() + 1; i++)
				cout << i << ") " << currentAirport->planes.at(i - 1)->getType() << "." << endl;
			cin >> delSelection;
			if (cin.fail() || delSelection < 0 || delSelection > currentAirport->planes.size() + 1)
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
		cin.clear(100, 'n');
		if (delSelection == 0)
			return;
		delSelection--;
		do
		{
			cout << "Are you sure you want to delete the following plane?(y/n)\n";
			//currentAirport->planes.at(delSelection)->showPlane();
			cin >> confirm;
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
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
			if (confirm == "y" || confirm == "Y")
			{
				currentAirport->planes.erase(currentAirport->planes.begin() + delSelection);
				badInput = false;
				completedDel = true;
			}
			if (confirm == "n" || confirm == "N")
			{
				badInput = false;
				completedDel = false;
			}

		} while (badInput);
	} while (!completedDel);
}

void deleteFlightData()
{
	int delSelection;
	string confirm;
	bool completedDel = false;
	cout << "Which flight data do you want to delete?(0 to cancel)\n" << endl;
	do {
		do
		{
			for (size_t i = 1; i < currentAirport->flights.size() + 1; i++)
				cout << i << ") " << currentAirport->flights.at(i - 1)->getDestination() << "which departs at: " << currentAirport->flights.at(i - 1)->getPredictedSchedule().getDepartureDate() << endl;
			cin >> delSelection;
			if (cin.fail() || delSelection < 0 || delSelection > currentAirport->flights.size() + 1)
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
		cin.clear(100, 'n');
		if (delSelection == 0)
			return;
		delSelection--;
		do
		{
			cout << "Are you sure you want to delete the following flight?(y/n)\n";
			//currentAirport->flights.at(delSelection).showFlight();
			cin >> confirm;
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
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
			if (confirm == "y" || confirm == "Y")
			{
				currentAirport->flights.erase(currentAirport->flights.begin() + delSelection);
				badInput = false;
				completedDel = true;
			}
			if (confirm == "n" || confirm == "N")
			{
				badInput = false;
				completedDel = false;
			}

		} while (badInput);
	} while (!completedDel);
}
*/