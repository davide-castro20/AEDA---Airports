#include "DeleteFunctions.h"
#include "Menus.h"
#include "ChangeFunctions.h"

extern Airport *currentAirport;
extern Company *comp;

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
	vector<Employee*> employees;

	/*if (currentAirport->employees.size() == 0) {
		cout << "No employees on this airport!\n";
		return;
	}*/
	for (auto i : comp->getEmployees())
	{
				if (i->getAirport() == currentAirport->getLocal().getCity())
					employees.push_back(i);
	}
	if(employees.size() == 0)
	{
		cout << "No employees on this airport!\n";
		return;
	}
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "|Whose data do you want to change?(0 to cancel)\n" << endl;
			
			for (size_t i = 1; i < employees.size() + 1; i++)
				cout << i << ") " << employees.at(i - 1)->getType() << ":" << employees.at(i - 1)->getName() << "." << endl;
			cin >> changeSelection;
			if (cin.fail() || changeSelection < 0 || changeSelection > employees.size())
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
		
		comp->getEmployees().erase(employees.at(changeSelection));

		cin.clear();
		cin.ignore(100, '\n');
		do
		{
			if (employees.at(changeSelection)->getType() == "Pilot") {
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
						employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						Pilot* pilot = dynamic_cast<Pilot*>(employees.at(changeSelection));
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the category you want to change to?\n";
							cin.clear();
							cin.ignore(100, '\n');
							getline(cin, category);
							if (cin.eof())
							{
								cin.clear();
								return;
							}
						} while (!pilot->setCategory(category));
					}
				}
			}
			else if (employees.at(changeSelection)->getType() == "Flight Crew") {
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
						employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						FlightCrew* crew = dynamic_cast<FlightCrew*>(employees.at(changeSelection));
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the category you want to change to?\n";
							getline(cin, category);
						} while (!crew->setCategory(category));
					}
				}
			}
			else if (employees.at(changeSelection)->getType() == "Admin") {
			cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "|What do you want to change?\n1) Name\n2) Department\n3) Function\n0) Back\n";
				cin >> selectionToChange;
				if (cin.eof())
				{
					cin.clear();
					return;
				}
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
						employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						Admin* admin = dynamic_cast<Admin*>(employees.at(changeSelection));
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the department you want to change to?\n";
							getline(cin, department);
						} while (!admin->setDepartment(department));
					}
					if (selectionToChange == 3) {
						Admin* admin = dynamic_cast<Admin*>(employees.at(changeSelection));
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the function you want to change to?\n";
							getline(cin, function);
						} while (!admin->setFunction(function));
					}

				}
			}
			else if (employees.at(changeSelection)->getType() == "Base Crew") {
			cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "|What do you want to change?\n1) Name\n2) Category\n3) Schedule\n0) Back\n";
				cin >> selectionToChange;
				if (cin.eof())
				{
					cin.clear();
					return;
				}
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
						employees.at(changeSelection)->setName(name);
					}
					if (selectionToChange == 2) {
						BaseCrew* crew = dynamic_cast<BaseCrew*>(employees.at(changeSelection));
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the category you want to change to?\n";
							getline(cin, category);
							if (cin.eof())
							{
								cin.clear();
								return;
							}
						} while (!crew->setCategory(category));
					}
					if (selectionToChange == 3) {
						BaseCrew* crew = dynamic_cast<BaseCrew*>(employees.at(changeSelection));
						do
						{
							cout << "-----------------------------------------------------------------------------------------------------\n";
							cout << "|What is the schedule you want to change to?(Ex: 10:30 (enter) 18:30)\n";
							getline(cin, aux);
							if (cin.eof())
							{
								cin.clear();
								return;
							}
							decomposeInt(aux, startTime, ':');
							getline(cin, aux);
							if (cin.eof())
							{
								cin.clear();
								return;
							}
							decomposeInt(aux, endTime, ':');
							startSchedule = new Time(startTime[0], startTime[1]);
							endSchedule = new Time(endTime[0], endTime[1]);
							schedule = new Schedule(startSchedule, endSchedule);
							
						} while (!crew->setSchedule(schedule));
					}
				}
			}
		} while (badInput);
		comp->getEmployees().insert(employees.at(changeSelection));
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
			if (cin.eof())
			{
				cin.clear();
				return;
			}
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
			if (cin.eof())
			{
				cin.clear();
				return;
			}
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
				cin.ignore(100, '\n');
				if (selectionToChange == 1) {
					do
					{
						cout << "-----------------------------------------------------------------------------------------------------\n";
						cout << "|What is the type you want to change to?\n";
						getline(cin, type);
						if (cin.eof())
						{
							cin.clear();
							return;
						}
					} while (!currentAirport->planes.at(changeSelection)->setType(type));
				}
				if (selectionToChange == 2) {
					do
					{
						cout << "-----------------------------------------------------------------------------------------------------\n";
						cout << "|What is the capacity you want to change to?\n";
						getline(cin, capacity);
						if (cin.eof())
						{
							cin.clear();
							return;
						}
						capac = stoi(capacity);
					} while (!currentAirport->planes.at(changeSelection)->setCapacity(capac));
				}
			}
		} while (badInput);
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
	vector<Employee*> employees;
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
			if (cin.eof())
			{
				cin.clear();
				return;
			}
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
			if (cin.eof())
			{
				cin.clear();
				return;
			}
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
						if (cin.eof())
						{
							cin.clear();
							return;
						}
						startDate = new Date(aux);
						getline(cin, aux);
						if (cin.eof())
						{
							cin.clear();
							return;
						}
						endDate = new Date(aux);
						cout << "-----------------------------------------------------------------------------------------------------\n";
						cout << "|What is the time schedule you want to change to?(Ex: 10:30 (enter) 8:30)\n";
						getline(cin, aux);
						if (cin.eof())
						{
							cin.clear();
							return;
						}
						decomposeInt(aux, startTime, ':');
						getline(cin, aux);
						if (cin.eof())
						{
							cin.clear();
							return;
						}
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
						if (cin.eof())
						{
							cin.clear();
							return;
						}
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
							for (auto m : comp->getEmployees())
							{
								if (m->getAirport() == currentAirport->getLocal().getCity())
									employees.push_back(m);
							}
							do {
								vector<Employee*> freeEmp;
								freeEmp.clear();
								if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getType() == "Pilot") {
									cout << "-----------------------------------------------------------------------------------------------------\n";
									cout << "Select new pilot \n";

									for (unsigned int j = 1; j <= employees.size(); j++) {

										if (employees.at(j - 1)->getType() == "Pilot") {
											Pilot* pilot = dynamic_cast<Pilot*>(employees.at(j - 1));
											if (pilot->isFree(&currentAirport->flights.at(changeSelection)->getPredictedSchedule())
												&& employees.at(j - 1) != currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)
												&& notInFlight(employees.at(j - 1), currentAirport->flights.at(changeSelection)))
											{
												Pilot* pilot = dynamic_cast<Pilot*>(employees.at(j - 1));
												for (size_t l = 0; l < pilot->getPlanes().size(); l++)
												{
													if (pilot->getPlanes().at(l) == currentAirport->flights.at(changeSelection)->getPlane())
													{
														freeEmp.push_back(employees.at(j - 1));
														break;
													}
												}
											}
										}
									}
									if (freeEmp.size() < 1) {
										cout << "|Not enough free employees at the moment!" << endl;
										return;
									}
									for(size_t i = 1; i<freeEmp.size()+ 1 ;i++)
										cout << i << ") " << freeEmp.at(i - 1)->getType() << ":" << freeEmp.at(i - 1)->getName() << "." << endl;
									cin >> newEmployeeSelection;
									if (cin.eof())
									{
										cin.clear();
										return;
									}
									newEmployeeSelection--;
									if (cin.fail() || newEmployeeSelection < 0 || newEmployeeSelection > freeEmp.size())
									{
										cin.clear();
										cin.ignore(100, '\n');
										wrongInput = true;
									}
									else
									{
										wrongInput = false;
										badInput = false;
										Pilot* pilot2 = dynamic_cast<Pilot*>(freeEmp.at(newEmployeeSelection));
										pilot2->addFlight(currentAirport->flights.at(changeSelection));
										auxil.push_back(freeEmp.at(newEmployeeSelection));
										Pilot * pilot = dynamic_cast<Pilot*>(currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection));
										for (size_t i = 0; i < pilot->getFlights().size(); i++)
											if (pilot->getFlights().at(i)->getId() == currentAirport->flights.at(changeSelection)->getId())
												pilot->deleteFlight(currentAirport->flights.at(changeSelection)->getId());
	
									}
								}
								else if (currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection)->getType() == "Flight Crew") {
									cout << "-----------------------------------------------------------------------------------------------------\n";
									cout << "|Select new Flight Crew \n";
									for (unsigned int j = 1; j <= employees.size(); j++) {
										if (employees.at(j - 1)->getType() == "Flight Crew") {
											FlightCrew* crew = dynamic_cast<FlightCrew*>(employees.at(j - 1));
											if (crew->isFree(&currentAirport->flights.at(changeSelection)->getPredictedSchedule()) && employees.at(j - 1) != currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection) && notInFlight(employees.at(j - 1), currentAirport->flights.at(changeSelection)))
												freeEmp.push_back(employees.at(j - 1));
										}
									}
									if (freeEmp.size() < 1) {
										cout << "|Not enough free employees at the moment!" << endl;
										return;
									}
									for (size_t i = 1; i < freeEmp.size()+1; i++)
										cout << i << ") " << freeEmp.at(i - 1)->getType() << ":" << freeEmp.at(i - 1)->getName() << "." << endl;
									cin >> newEmployeeSelection;
									if (cin.eof())
									{
										cin.clear();
										return;
									}
									newEmployeeSelection--;
									if (cin.fail() || newEmployeeSelection < 0 || newEmployeeSelection > freeEmp.size())
									{
										cin.clear();
										cin.ignore(100, '\n');
										wrongInput = true;
									}
									else
									{
										wrongInput = false;
										badInput = false;
										FlightCrew* crew2 = dynamic_cast<FlightCrew*>(freeEmp.at(newEmployeeSelection));
										crew2->addFlight(currentAirport->flights.at(changeSelection));
										auxil.push_back(freeEmp.at(newEmployeeSelection));
										FlightCrew* crew = dynamic_cast<FlightCrew*>(currentAirport->flights.at(changeSelection)->getEmployees().at(employeeSelection));
										for (size_t i = 0; i < crew->getFlights().size(); i++)
											if (crew->getFlights().at(i)->getId() == currentAirport->flights.at(changeSelection)->getId())
												crew->deleteFlight(currentAirport->flights.at(changeSelection)->getId());

									}
								}
							} while (wrongInput);
						} 
					} while (!currentAirport->flights.at(changeSelection)->setCrew(auxil));
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
	bool badInput = false;
	unsigned int addSel;
	vector<Employee*> oldCrew;
	vector<Employee*> freePilots;
	if (flight->getPilots().size() == 2)
	{
		cout << "There are already two pilots on this flight!\n\n";
		return;
	}
	
	/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
	{
		if (currentAirport->employees.at(i)->isFree(&flight->getPredictedSchedule()) && currentAirport->employees.at(i)->getType() == "Pilot")
		{
			for (size_t l = 0; l < currentAirport->employees.at(i)->getPlanes().size(); l++)
			{
				if (currentAirport->employees.at(i)->getPlanes().at(l) == flight->getPlane()) {
					freePilots.push_back(currentAirport->employees.at(i));
					break;
				}
			}
		}
	}*/
	for (auto i : comp->getEmployees())
	{
		if ((i)->getType() == "Pilot")
		{
			Pilot* pilot = dynamic_cast<Pilot*>(i);
			if (pilot->isFree(&flight->getPredictedSchedule()))
			{
				for (size_t l = 0; l < pilot->getPlanes().size(); l++)
				{
					if (pilot->getPlanes().at(l) == flight->getPlane()) {
						freePilots.push_back(i);
							break;
					}
				}
			}
		}
	}
	if (freePilots.size() == 0)
	{
		cout << "There are no available pilots for this flight.\n\n";
		return;
	}
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Which pilot to add?\n\n";
		for (size_t k = 1; k < freePilots.size() + 1; k++)
			cout << k << ") Name: " << freePilots.at(k - 1)->getName() << "; Birth Date: " << freePilots.at(k - 1)->getDate() << endl;
		cout << endl << "0)Return to last menu.\n\n";
		cin >> addSel;
		cin.ignore(100, '\n');
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (cin.fail() || addSel < 0 || addSel > freePilots.size())
		{
			cin.clear();
			cout << "Invalid pilot, please insert again.\n\n";
			badInput = true;
		}
		else
		{
			badInput = false;
			oldCrew = flight->getEmployees();
			Pilot* pilot = dynamic_cast<Pilot*>(freePilots.at(addSel - 1));
			pilot->addFlight(flight);
			oldCrew.push_back(freePilots.at(addSel - 1));
			flight->setCrew(oldCrew);
			cout << "Pilot successfuly added to the flight!\n\n";
		}

	} while (badInput);

}

void addFlightCrew(Flight* flight)
{
	unsigned int addSel;
	bool badInput = false;
	vector<Employee*> freeFlightCrew;
	vector<Employee*> oldCrew;
	if (flight->getCrew().size() == 2)
	{
		cout << "There are already two flight crew members on this flight!\n\n";
		return;
	}
	/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
	{
		if (currentAirport->employees.at(i)->isFree(&flight->getPredictedSchedule()) && currentAirport->employees.at(i)->getType() == "Flight Crew")
			freeFlightCrew.push_back(currentAirport->employees.at(i));
	}*/
	for (auto i : comp->getEmployees())
	{
		if (i->getType() == "Flight Crew" && i->getAirport() == currentAirport->getLocal().getCity()) {
			FlightCrew* crew = dynamic_cast<FlightCrew*>(i);
			if(crew->isFree(&flight->getPredictedSchedule()))
				freeFlightCrew.push_back(i);
		}
	}
	if (freeFlightCrew.size() == 0)
	{
		cout << "There are no available flight crew members for this flight.\n\n";
		return;
	}
	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Which flight crew member to add?\n\n";
		for (size_t k = 1; k < freeFlightCrew.size() + 1; k++)
			cout << k << ") Name: " << freeFlightCrew.at(k - 1)->getName() << "; Birth Date: " << freeFlightCrew.at(k - 1)->getDate() << endl;
		cout << endl << "0)Return to last menu.\n\n";
		cin >> addSel;
		cin.ignore(100, '\n');
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (cin.fail() || addSel < 0 || addSel > freeFlightCrew.size())
		{
			cin.clear();
			cout << "Invalid flight crew member, please insert again.\n\n";
			badInput = true;
		}
		else
		{
			badInput = false;
			oldCrew = flight->getEmployees();
			FlightCrew* crew = dynamic_cast<FlightCrew*>(freeFlightCrew.at(addSel - 1));
			crew->addFlight(flight);
			oldCrew.push_back(freeFlightCrew.at(addSel - 1));
			flight->setCrew(oldCrew);
			cout << "Flight crew member successfuly added to the flight!\n\n";
		}

	} while (badInput);
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
			freePlanes.at(addSel - 1)->addFlight(flight);
			cout << "Plane successfuly added to the flight!\n\n";
		}

	} while (badInput);
}



void changeManagerSalary() {
	string salary;
	bool badInput = true;
	string name = currentAirport->manager.name;
	Date birthDate = *currentAirport->manager.birthDate;
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
			manager.birthDate = &birthDate;
			manager.salary = stod(salary);
			currentAirport->setManager(manager);
		}
	} while (badInput);
}