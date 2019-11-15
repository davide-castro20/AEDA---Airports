#include "DeleteFunctions.h"
#include "Menus.h"
#include "ChangeFunctions.h"

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

	if (currentAirport->employees.size() == 0) {
		cout << "No employees on this airport!\n";
		return;
	}
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "|Whose data do you want to change?(0 to cancel)\n" << endl;
			for (size_t i = 1; i < currentAirport->employees.size() + 1; i++)
				cout << i << ") " << currentAirport->employees.at(i - 1)->getType() << ":" << currentAirport->employees.at(i - 1)->getName() << "." << endl;
			cin >> changeSelection;
			if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->employees.size())
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
		cin.clear();
		if (changeSelection == 0)
			return;
		changeSelection--;
		
		cin.clear();
		cin.ignore(100, '\n');
		do
		{
			if (currentAirport->employees.at(changeSelection)->getType() == "Pilot") {
				cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "|What do you want to change?\n1) Name\n2) Category\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 2)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "|There was a problem with your selection, please try again.\n";
					badInput = true;
				}
				else
				{	cin.clear();
					cin.ignore(100, '\n');
					badInput = false;
					if (selectionToChange == 1) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What name would you like to change to? \n";
							getline(cin, name);
							if (cin.eof()) {
								cin.clear();
								return;
							}
							if (!noAccent(name) || cin.fail() || (name.find_first_of("0123456789") != std::string::npos) || name=="" || islower(name.at(0)))
							{
								cin.clear();
								//cin.ignore(100, '\n');
								badInput = true;
								cout << "!Invalid name! Please insert name again \n";
							}
							else
							{
								badInput = false;
							}
							
						} while (badInput);
						currentAirport->employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the category you want to change to?\n";
							cin.clear();
							cin.ignore(100, '\n');
							getline(cin, category);
						} while (!currentAirport->employees.at(changeSelection)->setCategory(category));
					}
				}
			}
			else if (currentAirport->employees.at(changeSelection)->getType() == "Flight Crew") {
				cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "|What do you want to change?\n1) Name\n2) Category\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 2)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "|There was a problem with your selection, please try again.\n";
					badInput = true;
				}
				else
				{
					badInput = false;
					cin.clear();
					cin.ignore(100, '\n');
					if (selectionToChange == 1) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "!What name would you like to change to? \n";
							getline(cin, name);
							if (cin.eof()) {
								cin.clear();
								return;
							}
							if (!noAccent(name) || cin.fail() || (name.find_first_of("0123456789") != std::string::npos) || name == "" || islower(name.at(0)))
							{
								cin.clear();
								//cin.ignore(100, '\n');

								badInput = true;
								cout << "!Invalid name! Please insert name again \n";
							}
							else
							{
								badInput = false;
							}
						} while (badInput);
						currentAirport->employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the category you want to change to?\n";
							getline(cin, category);
						} while (!currentAirport->employees.at(changeSelection)->setCategory(category));
					}
				}
			}
			else if (currentAirport->employees.at(changeSelection)->getType() == "Admin") {
			cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "|What do you want to change?\n1) Name\n2) Department\n3) Function\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 3)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "|There was a problem with your selection, please try again.\n" ;
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
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What name would you like to change to? \n";
							getline(cin, name);
							if (cin.eof()) {
								cin.clear();
								return;
							}
							if (!noAccent(name) || cin.fail() || (name.find_first_of("0123456789") != std::string::npos) || name == "" || islower(name.at(0)))
							{
								cin.clear();
								//cin.ignore(100, '\n');
								badInput = true;
								cout << "|Invalid name! Please insert name again \n";
							}
							else
							{
								badInput = false;
							}
						} while (badInput);
						currentAirport->employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the department you want to change to?\n";
							getline(cin, department);
						} while (!currentAirport->employees.at(changeSelection)->setDepartment(department));
					}
					if (selectionToChange == 3) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the function you want to change to?\n";
							getline(cin, function);
						} while (!currentAirport->employees.at(changeSelection)->setDepartment(function));
					}

				}
			}
			else if (currentAirport->employees.at(changeSelection)->getType() == "Base Crew") {
			cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "|What do you want to change?\n1) Name\n2) Category\n3) Schedule\n0) Back\n";
				cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 3)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "|There was a problem with your selection, please try again.\n";
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
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What name would you like to change to? \n";
							getline(cin, name);
							if (cin.eof()) {
								cin.clear();
								return;
							}
							if (!noAccent(name) || cin.fail() || (name.find_first_of("0123456789") != std::string::npos) || name == "" || islower(name.at(0)))
							{
								cin.clear();
								badInput = true;
								cout << "!Invalid name! Please insert name again \n";
							}
							else
							{
								badInput = false;
							}
						} while (badInput);
						currentAirport->employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the category you want to change to?\n";
							getline(cin, category);
						} while (!currentAirport->employees.at(changeSelection)->setCategory(category));
					}
					if (selectionToChange == 3) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the schedule you want to change to?(Ex: 10:30 (enter) 18:30)\n";
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
		completedChange = true;
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
	if (currentAirport->planes.size() == 0) {
		cout << "No planes on this airport!\n";
			return;
	}
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "|Which plane data do you want to change?(0 to cancel)" << endl;
			for (size_t i = 1; i < currentAirport->planes.size() + 1; i++)
				cout << i << ") " << currentAirport->planes.at(i - 1)->getType() << " with a capacity of "<< currentAirport->planes.at(i - 1)->getCapacity() <<" spots."<< endl;
			cin >> changeSelection;
			if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->planes.size())
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
		cin.clear();
		if (changeSelection == 0)
			return;
		changeSelection--;

		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "|What do you want to change?\n1) Type\n2) Capacity\n0) Back\n";
			cin >> selectionToChange;
				if (cin.fail() || selectionToChange < 0 || selectionToChange > 2)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "|There was a problem with your selection, please try again.\n" ;
					badInput = true;
				}
				else
				{
					badInput = false;
					cin.ignore(100, '\n');
					if (selectionToChange == 1) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the type you want to change to?\n";
							getline(cin, type);
						} while (!currentAirport->planes.at(changeSelection)->setType(type));
					}
					if (selectionToChange == 2) {
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the capacity you want to change to?\n";
							getline(cin, capacity);
							capac = stoi(capacity);
						} while (!currentAirport->planes.at(changeSelection)->setCapacity(capac));
					}
				}
			}while (badInput);
			completedChange = true;
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
	vector<Employee*>auxil;
	bool badInput = true;
	bool wrongInput = true;
	unsigned int changeSelection,selectionToChange,employeeSelection, newEmployeeSelection;
	string confirm;
	bool completedChange = false;
	bool changed = false;

	if (currentAirport->flights.size() == 0) {
		cout << "No flights scheduled on this airport!\n";
		return;
	}
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "|Which flight data do you want to change?(0 to cancel)\n" << endl;
	do {
		do
		{
			for (size_t i = 1; i < currentAirport->flights.size() + 1; i++)
				cout << i << ") " << currentAirport->flights.at(i - 1)->getDestination() << " which departs at: " << currentAirport->flights.at(i - 1)->getPredictedSchedule().getDepartureDate() << endl;
			cin >> changeSelection;
			if (cin.fail() || changeSelection < 0 || changeSelection > currentAirport->flights.size())
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
		cin.clear();
		if (changeSelection == 0)
			return;
		changeSelection--;

		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "|What do you want to change?\n1) Schedule\n2) Crew\n0) Back\n";
			cin >> selectionToChange;
			if (cin.fail() || selectionToChange < 0 || selectionToChange > 2)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "|There was a problem with your selection, please try again.\n";
				badInput = true;

			}
			else
			{
				cin.ignore(100, '\n');
				badInput = false;
				if (selectionToChange == 1) {
					do
					{
						cout << "-----------------------------------------------------------------------------------------------------\n";
						cout << "|What is the date you want to change to?(Ex: 10/8/2000 (enter) 11/8/2000)\n";
						getline(cin, aux);
						startDate = new Date(aux);
						getline(cin, aux);
						endDate = new Date(aux);
						cout << "-----------------------------------------------------------------------------------------------------\n";
						cout << "|What is the time schedule you want to change to?(Ex: 10:30 (enter) 8:30)\n";
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

						auxil.clear();
						auxil = currentAirport->flights.at(changeSelection)->getEmployees();
						cout << "-----------------------------------------------------------------------------------------------------\n";
						cout << "|What is the crew member you want to change ?\n";
						for (unsigned int i = 1; i <= currentAirport->flights.at(changeSelection)->getEmployees().size(); i++)
							cout << i << ") " << currentAirport->flights.at(changeSelection)->getEmployees().at(i - 1)->getType() << ":" << currentAirport->flights.at(changeSelection)->getEmployees().at(i - 1)->getName() << "." << endl;
						cin >> employeeSelection;
						employeeSelection--;
						auxil.erase(auxil.begin() + employeeSelection);
						if (cin.fail() || employeeSelection < 0 || employeeSelection > currentAirport->flights.at(changeSelection)->getEmployees().size() + 1)
						{
							cin.clear();
							cin.ignore(100, '\n');
							badInput = true;
						}
						else
						{
							badInput = false;
							do {
								vector<Employee*> freeEmp;
								freeEmp.clear();
								if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getType() == "Pilot") {
									cout << "-----------------------------------------------------------------------------------------------------\n";
									cout << "Select new pilot \n";
									for (unsigned int j = 1; j <= currentAirport->employees.size(); j++) {
										if (currentAirport->employees.at(j - 1)->getType() == "Pilot" && currentAirport->employees.at(j - 1)->isFree(&currentAirport->flights.at(changeSelection)->getPredictedSchedule()) && currentAirport->employees.at(j - 1) != currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection) && notInFlight(currentAirport->employees.at(j - 1), currentAirport->flights.at(changeSelection)))
											freeEmp.push_back(currentAirport->employees.at(j - 1));
									}
									if (freeEmp.size() < 2) {
										cout << "|Not enough free employees at the moment!" << endl;
										return;
									}
									for(size_t i = 0;i<freeEmp.size();i++)
										cout << i << ") " << freeEmp.at(i - 1)->getType() << ":" << freeEmp.at(i - 1)->getName() << "." << endl;
									cin >> newEmployeeSelection;
									newEmployeeSelection--;
									if (cin.fail() || newEmployeeSelection < 0 || newEmployeeSelection > 2)
									{
										cin.clear();
										cin.ignore(100, '\n');
										wrongInput = true;
									}
									else
									{
										wrongInput = false;
										freeEmp.at(newEmployeeSelection)->addFlight(currentAirport->flights.at(changeSelection));
										auxil.push_back(freeEmp.at(newEmployeeSelection));
										for (size_t i = 0; i < currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getFlights().size(); i++)
											if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getFlights().at(i)->getId() == currentAirport->flights.at(changeSelection)->getId())
												currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->deleteFlight(currentAirport->flights.at(changeSelection)->getId());
	
									}
								}
								else if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getType() == "Flight Crew") {
									cout << "-----------------------------------------------------------------------------------------------------\n";
									cout << "|Select new Flight Crew \n";
									for (unsigned int j = 1; j <= currentAirport->employees.size(); j++) {
										if (currentAirport->employees.at(j - 1)->getType() == "Flight Crew" && currentAirport->employees.at(j - 1)->isFree(&currentAirport->flights.at(changeSelection)->getPredictedSchedule()) && currentAirport->employees.at(j - 1) != currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection) && notInFlight(currentAirport->employees.at(j - 1), currentAirport->flights.at(changeSelection)))
											freeEmp.push_back(currentAirport->employees.at(j - 1));
									}
									if (freeEmp.size() < 2) {
										cout << "|Not enough free employees at the moment!" << endl;
										return;
									}
									for (size_t i = 0; i < freeEmp.size(); i++)
										cout << i << ") " << freeEmp.at(i - 1)->getType() << ":" << freeEmp.at(i - 1)->getName() << "." << endl;
									cin >> newEmployeeSelection;
									newEmployeeSelection--;
									if (cin.fail() || newEmployeeSelection < 0 || newEmployeeSelection > 2)
									{
										cin.clear();
										cin.ignore(100, '\n');
										wrongInput = true;
									}
									else
									{
										wrongInput = false;
										freeEmp.at(newEmployeeSelection)->addFlight(currentAirport->flights.at(changeSelection));
										auxil.push_back(freeEmp.at(newEmployeeSelection));
										for (size_t i = 0; i < currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getFlights().size(); i++)
											if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getFlights().at(i)->getId() == currentAirport->flights.at(changeSelection)->getId())
												currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->deleteFlight(currentAirport->flights.at(changeSelection)->getId());

									}
								}
							} while (wrongInput);
						} 
					} while (currentAirport->flights.at(changeSelection)->setCrew(auxil));
				}
			}
		} while (badInput);

		completedChange = true;
	} while (!completedChange);
}

void addToFlight()
{
	unsigned int addSel;
	bool badInput;
	vector<Flight*> incompleteFlights;
	for (size_t k = 0; k < currentAirport->flights.size(); k++)
	{
		if (currentAirport->flights.at(k)->getEmployees().size() < 4 || currentAirport->flights.at(k)->getPlane() == NULL)
			incompleteFlights.push_back(currentAirport->flights.at(k));
	}

	if (incompleteFlights.size() == 0) {
		cout << "No incomplete flights on this airport!\n";
		return;
	}
	do {
		
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Add to which incomplete flight?\n\n";
			for (size_t i = 1; i < incompleteFlights.size() + 1; i++)
				cout << i << ") " << incompleteFlights.at(i - 1)->getDestination() << " which departs at: " << incompleteFlights.at(i - 1)->getPredictedSchedule().getDepartureDate() << endl;
			cout << endl << "0)Return to last menu.\n\n";
			cin >> addSel;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || addSel < 0 || addSel > currentAirport->flights.size())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid flight, please insert again.\n\n";
				badInput = true;
			}
			else
			{
				badInput = false;
			}


		} while (badInput);
		cin.ignore(100, '\n');
		if (addSel == 0)
			return;

		Flight *flight = incompleteFlights.at(addSel - 1);

		do
		{
			cout << string(100, '-') << endl;
			cout << "What data to add?\n\n" << "1)A Pilot.\n" << "2)A flight crew member.\n" << "3)A plane.\n" << "0)Return to last menu\n";
			cin >> addSel;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || addSel < 0 || addSel > 3)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid input. Please insert option again.\n";
				badInput = true;
			}
			else
			{
				badInput = false;
			}


		} while (badInput);

		switch (addSel)
		{
		case 0:
			addSel = 1;
		case 1:
			addPilot(flight);
			addSel = 0;
			break;
		case 2:
			addFlightCrew(flight);
			addSel = 0;
			break;
		case 3:
			addPlane(flight);
			addSel = 0;
			break;
		}
	} while (addSel != 0);
}

void addPilot(Flight* flight)
{
	if (flight->getPilots().size() == 2)
	{
		cout << "There are already two pilots on this flight!\n\n";
		return;
	}


}

void addFlightCrew(Flight* flight)
{
	if (flight->getCrew().size() == 2)
	{
		cout << "There are already two flight crew members on this flight!\n\n";
		return;
	}
}

void addPlane(Flight* flight)
{
	if (flight->getPlane() != NULL)
	{
		cout << "There is already a plane to this flight!\n\n";
		return;
	}

	bool badInput = false;
	unsigned int addSel;

	vector<Plane*> freePlanes;

	for (size_t i = 0; i < currentAirport->planes.size(); i++)
	{
		if (currentAirport->planes.at(i)->isFree(&flight->getPredictedSchedule()))
			freePlanes.push_back(currentAirport->planes.at(i));
	}
	if (freePlanes.size() == 0)
	{
		cout << "There are no available planes for this flight.\n\n";
		return;
	}
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Which plane to add?\n\n";
		for (size_t k = 1; k < freePlanes.size() + 1; k++)
			cout << k << ") Type: " << freePlanes.at(k - 1)->getType() << "; Capacity: " << freePlanes.at(k - 1)->getCapacity() << endl;
		cout << endl << "0)Return to last menu.\n\n";
		cin >> addSel;
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (cin.fail() || addSel < 0 || addSel > freePlanes.size())
		{
			cin.clear();
			cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Invalid plane, please insert again.\n\n";
			badInput = true;
		}
		else
		{
			badInput = false;
			flight->setPlane(freePlanes.at(addSel - 1));
			cout << "Plane successfuly added to the flight!\n\n";
		}

	} while (badInput);
}



void changeManagerSalary() {
	string salary;
	bool badInput = true;
	string name = currentAirport->manager.name;
	Date birthDate = currentAirport->manager.birthDate;
	Manager manager;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Salary: \n";
	do
	{

		getline(cin, salary);
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (noAccent(salary) || cin.fail() || salary == "" || stod(salary) < 0)
		{
			cin.clear();
			//cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid salary! Please insert again \n";
		}
		else
		{
			badInput = false;
			manager.name = name;
			manager.birthDate = birthDate;
			manager.salary = stod(salary);
			currentAirport->setManager(manager);
		}
	} while (badInput);
}