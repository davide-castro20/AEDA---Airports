#include "DeleteFunctions.h"
#include "Menus.h"

extern Airport *currentAirport;

void changePersonData()
{
	bool badInput = true;
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
		cin.clear();
		cin.ignore(100, '\n');
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
							cin.clear();
							cin.ignore(100, '\n');
							getline(cin, name);
						} while (!currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the category you want to change to?\n";
							cin.clear();
							cin.ignore(100, '\n');
							getline(cin, category);
						} while (!currentAirport->employees.at(changeSelection)->setCategory(category));
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
					cin.clear();
					cin.ignore(100, '\n');
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "What is the name you want to change to?\n";
							getline(cin, name);
						} while (!currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the category you want to change to?\n";
							getline(cin, category);
						} while (!currentAirport->employees.at(changeSelection)->setCategory(category));
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
					cin.clear();
					cin.ignore(100, '\n');
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "What is the name you want to change to?\n";
							getline(cin, name);
						} while (!currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the department you want to change to?\n";
							getline(cin, department);
						} while (!currentAirport->employees.at(changeSelection)->setDepartment(department));
					}
					if (selectionToChange == 3) {
						do
						{
							cout << "What is the function you want to change to?\n";
							getline(cin, function);
						} while (!currentAirport->employees.at(changeSelection)->setDepartment(function));
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
					cin.clear();
					cin.ignore(100, '\n');
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "What is the name you want to change to?\n";
							getline(cin, name);
						} while (!currentAirport->employees.at(changeSelection)->setName(name));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the category you want to change to?\n";
							getline(cin, category);
						} while (!currentAirport->employees.at(changeSelection)->setCategory(category));
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
							
						} while (!currentAirport->employees.at(changeSelection)->setSchedule(schedule));
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


void changePlaneData()
{
	bool badInput=true;
	unsigned int changeSelection,selectionToChange;
	string confirm;
	string capacity;
	int capac;
	string type;
	bool completedChange = false;
	cout << "Which plane data do you want to change?(0 to cancel)\n" << endl;
	do {
		do
		{
			for (size_t i = 1; i < currentAirport->planes.size() + 1; i++)
				cout << i << ") " << currentAirport->planes.at(i - 1)->getType() << "." << endl;
			cin >> changeSelection;
			if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->planes.size() + 1)
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

		do
		{
			cout << "What do you want to change?\n1) Type\n2) Capacity\n0) Back\n";
			cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 2)
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
							cout << "What is the type you want to change to?\n";
							getline(cin, type);
						} while (currentAirport->planes.at(changeSelection)->setType(type));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "What is the capacity you want to change to?\n";
							getline(cin, capacity);
							capac = stoi(capacity);
						} while (currentAirport->planes.at(changeSelection)->setCapacity(capac));
					}
				}
			}while (badInput);
		do
		{
			cout << "Are you sure you want to change the following plane?(y/n)\n";
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


void changeFlightData()
{
	vector <int> startTime;
	vector <int> endTime;
	string aux;
	Time *startSchedule;
	FlightSched *schedule;
	Time *endSchedule;
	Date *startDate;
	Date *endDate;
	bool badInput = true;
	bool wrongInput = true;
	unsigned int changeSelection,selectionToChange,employeeSelection, newEmployeeSelection;
	string confirm;
	bool completedChange = false;
	bool changed = false;
	cout << "Which flight data do you want to change?(0 to cancel)\n" << endl;
	do {
		do
		{
			for (size_t i = 1; i < currentAirport->flights.size() + 1; i++)
				cout << i << ") " << currentAirport->flights.at(i - 1)->getDestination() << "which departs at: " << currentAirport->flights.at(i - 1)->getPredictedSchedule().getDepartureDate() << endl;
			cin >> changeSelection;
			if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->flights.size() + 1)
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

		do
		{
			cout << "What do you want to change?\n1) Schedule\n2) Crew\n0) Back\n";
			cin >> selectionToChange;
			if (cin.fail() || selectionToChange < 0 || selectionToChange > 2)
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
						cout << "What is the date you want to change to?(Ex: 10/8/2000 (enter) 10/8/2000)\n";
						getline(cin, aux);
						startDate = new Date(aux);
						getline(cin, aux);
						endDate = new Date(aux);
						cout << "What is the time schedule you want to change to?(Ex: 10:30 (enter) 18:30)\n";
						getline(cin, aux);
						decomposeInt(aux, startTime, ':');
						getline(cin, aux);
						decomposeInt(aux, endTime, ':');
						startSchedule = new Time(startTime[0], startTime[1]);
						endSchedule = new Time(endTime[0], endTime[1]);
						schedule = new FlightSched(startDate, startSchedule, endDate, endSchedule);

					} while (currentAirport->flights.at(changeSelection)->setPredictedSchedule(schedule));
				}
				if (selectionToChange == 2) {
					do
					{
						cout << "What is the crew member you want to change ?\n";
						for (unsigned int i = 1; i <= currentAirport->flights.at(changeSelection)->getEmployees().size(); i++)
							cout << i << ") " << currentAirport->flights.at(changeSelection)->getEmployees().at(i - 1)->getType() << ":" << currentAirport->flights.at(changeSelection)->getEmployees().at(i - 1)->getName() << "." << endl;
						cin >> employeeSelection;
						employeeSelection--;
						if (cin.fail() || employeeSelection < 0 || employeeSelection > currentAirport->flights.at(changeSelection)->getEmployees().size() + 1)
						{
							cin.clear();
							cin.ignore(100, '\n');
							cout << "-----------------------------------------------------------------------------------------------------\n";
							badInput = true;
						}
						else
						{
							badInput = false;
							do {
								if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getType() == "Pilot") {
									cout << "Select new pilot \n";
									for (unsigned int j = 1; j <= currentAirport->employees.size(); j++) {
										if (currentAirport->employees.at(j - 1)->getType() == "Pilot")
											cout << j << ") " << currentAirport->employees.at(j - 1)->getType() << ":" << currentAirport->employees.at(j - 1)->getName() << "." << endl;
									}
									cin >> newEmployeeSelection;
									newEmployeeSelection--;
									if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->employees.size() + 1)
									{
										cin.clear();
										cin.ignore(100, '\n');
										cout << "-----------------------------------------------------------------------------------------------------\n";
										wrongInput = true;
									}
									else
									{
										wrongInput = false;
										currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection) = currentAirport->employees.at(newEmployeeSelection);
										/*BOOL IS FREE*/
									}
								}
								else if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getType() == "Flight Crew") {
									cout << "Select new flight crew member \n";
									for (unsigned int j = 1; j <= currentAirport->employees.size(); j++) {
										if (currentAirport->employees.at(j - 1)->getType() == "Flight Crew")
											cout << j << ") " << currentAirport->employees.at(j - 1)->getType() << ":" << currentAirport->employees.at(j - 1)->getName() << "." << endl;
									}
									cin >> newEmployeeSelection;
									newEmployeeSelection--;
									if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->employees.size() + 1)
									{
										cin.clear();
										cin.ignore(100, '\n');
										cout << "-----------------------------------------------------------------------------------------------------\n";
										wrongInput = true;
									}
									else
									{
										wrongInput = false;
										currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection) = currentAirport->employees.at(newEmployeeSelection);
										/*BOOL IS FREE*/
									}
								}
							} while (wrongInput);
						} 
					} while (currentAirport->flights.at(changeSelection)->setCrew(currentAirport->flights.at(changeSelection)->getEmployees()));
				}
			}
		} while (badInput);

		do
		{
			cout << "Are you sure you want to change the following flight?(y/n)\n";
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
