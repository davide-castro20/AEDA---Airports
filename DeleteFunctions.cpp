#include "DeleteFunctions.h"
#include "Menus.h"
#include "ShowFunctions.h"
#include "Company.h"

extern Airport *currentAirport;
extern Company* comp;

void deletePersonData()
{
	bool badInput = true;
	unsigned int delSelection;
	string confirm;
	bool completedDel=false;
	vector<Employee*> employees;
	for (auto i : comp->getEmployees())
	{
		if (i->getAirport() == currentAirport->getLocal().getCity())
			employees.push_back(i);
	}
	if (employees.size() == 0) {
		cout << "No employees on this airport!\n";
		return;
	}
	do {
		for (auto i : comp->getEmployees())
		{
			if (i->getAirport() == currentAirport->getLocal().getCity())
				employees.push_back(i);
		}
		do
		{
			completedDel = false;
			badInput = true;
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Whose data do you want to delete?(0 to cancel)\n" << endl;
			for (size_t i = 1; i < employees.size() + 1; i++)
				cout << i << ") " << employees.at(i - 1)-> getType() << ":" << employees.at(i - 1)->getName() << "." << endl;
			cin >> delSelection;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || delSelection < 0 || delSelection > employees.size() + 1)
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
		cin.ignore(100, '\n');

		if (delSelection == 0)
			return;

		delSelection--;
		do
		{
			showPerson(employees.at(delSelection));
			cout << "---------------------------------------------------------------------------------------------------\n";
			cout << "Are you sure you want to delete the following employee?(y/n)\n";
			cin >> confirm;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N" || confirm == "0"))
			{
				cin.clear();
				cin.ignore(100, '\n');
				badInput = true;
			}
			else
			{
					badInput = false;
				
			}
			if (confirm == "y" || confirm == "Y")
			{
				unsigned int pilotToSwap;
				if (employees.at(delSelection)->getType() == "Pilot")
				{
					vector<Employee*> freeEmp;
					for (size_t i = 0; i < employees.at(delSelection)->getFlights().size(); i++) {
						freeEmp.clear();
						for (size_t j = 0; j < employees.size(); j++)
						{
							if (employees.at(j)->isFree(&employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule()) && j != delSelection && employees.at(j)->getType() == "Pilot") {
								freeEmp.push_back(employees.at(j));
							}
						}
						if (freeEmp.size() > 0) {
							do {
								cout << "Please select another pilot to do the flight: " << employees.at(delSelection)->getFlights().at(i)->getDestination() << " which departs at " << employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule().getDepartureDate() << endl;
								for (size_t k = 1; k < freeEmp.size() + 1; k++)
									cout << k << ") " << freeEmp.at(k-1)->getName() <<  endl;
								cin >> pilotToSwap;
								if (cin.fail() || pilotToSwap <= 0 || pilotToSwap > freeEmp.size() + 1)
								{
									cin.clear();
									cout << "Invalid pilot! Please choose one the free pilots shown\n";
									badInput = true;
								}
								else
									badInput = false;
							} while (badInput);
							freeEmp.at(pilotToSwap-1)->addFlight(employees.at(delSelection)->getFlights().at(i));
							employees.at(delSelection)->getFlights().at(i)->setCrewMemb(freeEmp.at(pilotToSwap-1));
						}
						else {
							cout << "There are no free pilots for this flight.\n";
						}
						employees.at(delSelection)->getFlights().at(i)->deleteCrew(employees.at(delSelection));
					}
				}
				else if (employees.at(delSelection)->getType() == "Flight Crew")
				{
					vector<Employee*> freeEmp;
					for (size_t i = 0; i < employees.at(delSelection)->getFlights().size(); i++) {
						freeEmp.clear();
						for (size_t j = 0; j < employees.size(); j++)
						{
							if (employees.at(j)->isFree(&employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule()) && j != delSelection && employees.at(j)->getType() == "Flight Crew") {
								freeEmp.push_back(employees.at(j));
							}
						}
						if (freeEmp.size() > 0) {
							do {
								cout << "Please select another flight crew to do the flight: " << employees.at(delSelection)->getFlights().at(i)->getDestination() << " which departs at " << employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule().getDepartureDate() << endl;
								for (size_t k = 1; k < freeEmp.size() + 1; k++)
									cout << k << ") " << freeEmp.at(k - 1)->getName() << endl;
								cin >> pilotToSwap;
								if (cin.fail() || pilotToSwap <= 0 || pilotToSwap > freeEmp.size() + 1)
								{
									cin.clear();
									cout << "Invalid flight crew! Please choose one the free flight crew shown\n";
									badInput = true;
								}
								else
									badInput = false;
							} while (badInput);
							freeEmp.at(pilotToSwap - 1)->addFlight(employees.at(delSelection)->getFlights().at(i));
							employees.at(delSelection)->getFlights().at(i)->deleteCrew(employees.at(delSelection));
							employees.at(delSelection)->getFlights().at(i)->setCrewMemb(freeEmp.at(pilotToSwap - 1));
						}
						else {
							cout << "There are no free flight crew members for this flight.\n";
						}
					}
				}
				employees.at(delSelection)->setEmployed(false);
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

void deletePlaneData()
{
	bool badInput = true;
	unsigned int delSelection;
	string confirm;
	bool completedDel = false;
	if (currentAirport->planes.size() == 0) {
		cout << "No planes on this airport!\n";
		return;
	}

	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Which plane data do you want to delete?(0 to cancel)\n" << endl;
			for (size_t i = 1; i < currentAirport->planes.size() + 1; i++)
				cout << i << ") Type: " << currentAirport->planes.at(i - 1)->getType() << ", Capacity: "
				<< currentAirport->planes.at(i-1)->getCapacity() << endl;
			cin >> delSelection;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || delSelection < 0 || delSelection > currentAirport->planes.size() + 1)
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
		cin.ignore(100, '\n');
		if (delSelection == 0)
			return;
		delSelection--;
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Are you sure you want to delete the following plane?(y/n)\n";
			//showPlane(currentAirport->planes.at(delSelection));
			cin >> confirm;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
			{
				cin.clear();
				cin.ignore(100, '\n');
				badInput = true;
			}
			else
			{
					badInput = false;
			}
			if (confirm == "y" || confirm == "Y")
			{
				vector<Plane*> freePlanes;
				unsigned int planeToSwap;
				for (size_t i = 0; i < currentAirport->planes.at(delSelection)->getFlights().size(); i++) {
					freePlanes.clear();
					for (size_t j = 0; j < currentAirport->planes.size(); j++)
					{
						if (currentAirport->planes.at(j)->isFree(&currentAirport->planes.at(delSelection)->getFlights().at(i)->getPredictedSchedule()) && j!=delSelection)
							freePlanes.push_back(currentAirport->planes.at(j));
					}
					if (freePlanes.size() > 0) {
						do {
							cout << "Please select another plane to do the flight: " << currentAirport->planes.at(delSelection)->getFlights().at(i)->getDestination() << " which departs at " << currentAirport->planes.at(delSelection)->getFlights().at(i)->getPredictedSchedule().getDepartureDate() << endl;
							for (size_t k = 1; k < freePlanes.size() + 1; k++)
								cout << k << ") Type: " << freePlanes.at(k - 1)->getType() << "; Capacity: " << freePlanes.at(k - 1)->getCapacity() << endl;
							cin >> planeToSwap;
							if (cin.fail() || planeToSwap <= 0 || planeToSwap > freePlanes.size() + 1)
							{
								cin.clear();
								cout << "Invalid plane! Please choose one the free planes shown\n";
								badInput = true;
							}
							else
								badInput = false;
						} while (badInput);
						currentAirport->planes.at(planeToSwap)->addFlight(currentAirport->planes.at(delSelection)->getFlights().at(i));
						currentAirport->planes.at(delSelection)->getFlights().at(i)->setPlane(currentAirport->planes.at(planeToSwap));
					}
					else {
						cout << "There are no free planes for this flight.\n";
					}
				}
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
	bool badInput = true;
	unsigned int delSelection;
	string confirm;
	bool completedDel = false;
	if (currentAirport->flights.size() == 0) {
		cout << "No flights scheduled on this airport!\n";
		return;
	}
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Which flight data do you want to delete?(0 to cancel)\n" << endl;
			for (size_t i = 1; i < currentAirport->flights.size() + 1; i++)
				cout << i << ") " << currentAirport->flights.at(i - 1)->getDestination() << " which departs at: " << currentAirport->flights.at(i-1)->getPredictedSchedule().getDepartureDate() << endl;
			cout << "0) Back\n";
			cin >> delSelection;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || delSelection < 0 || delSelection > currentAirport->flights.size() + 1)
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
		cin.ignore(100, '\n');
		if (delSelection == 0)
			return;
		delSelection--;
		do
		{
			showFlight(currentAirport->flights.at(delSelection));
			cout << "---------------------------------------------------------------------------------------------------\n";
			cout << "Are you sure you want to delete the following flight?(y/n)\n";
			cin >> confirm;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
			{
				cin.clear();
				cin.ignore(100, '\n');
				badInput = true;
			}
			else
			{
					badInput = false;
				
			}
			if (confirm == "y" || confirm == "Y")
			{
				for (size_t i = 0; i < currentAirport->planes.size(); i++)
				{
					for (size_t j = 0; j < currentAirport->planes.at(i)->getFlights().size(); j++)
						if (currentAirport->planes.at(i)->getFlights().at(j)->getId() == currentAirport->flights.at(delSelection)->getId())
						{
							currentAirport->planes.at(i)->deleteFlight(currentAirport->flights.at(delSelection)->getId());
							break;
						}
				}
				/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
				{
					for (size_t j = 0; j < currentAirport->employees.at(i)->getFlights().size(); j++)
						if (currentAirport->employees.at(i)->getFlights().at(j)->getId() == currentAirport->flights.at(delSelection)->getId())
						{
							currentAirport->employees.at(i)->deleteFlight(currentAirport->flights.at(delSelection)->getId());
							break;
						}
				}*/
				for (auto i : comp->getEmployees())
				{
					if (i->getAirport() == currentAirport->getLocal().getCity())
					{
						for (size_t j = 0; j < (i)->getFlights().size(); j++)
							if ((i)->getFlights().at(j)->getId() == currentAirport->flights.at(delSelection)->getId())
							{
								(i)->deleteFlight(currentAirport->flights.at(delSelection)->getId());
								break;
							}
					}
				}
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

void deleteAirportData() {
	unsigned int delSelection, counter=0;
	string confirm;
	bool completedChange = false;
	bool badInput = true;
	const char* fileName;
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			if (comp->getAirports().size() == 0) {
				cout << "No airports.\n";
				return;
			}
			for (auto i : comp->getAirports()) {
				counter++;
				cout << counter << ") " << i->getLocal().getCity() << ", " << i->getLocal().getCountry() << endl;
			}
			cout << "0) Back\n";
			cin >> delSelection;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || delSelection < 0 || delSelection > comp->getAirports().size())
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
		cin.ignore(100, '\n');
		if (delSelection == 0)
			return;
		delSelection--;
		do
		{
			cout << "Are you sure you want to delete the following airport? This will forever delete this airports files(y/n)\n";
			//showPlane(currentAirport->planes.at(delSelection));
			cin >> confirm;
			if (cin.eof()) {
				cin.clear();
				return;
			}
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
				int copyDel = delSelection;
				for (auto iter : comp->getAirports())
				{
					if (delSelection == 0) {
						badInput = false;
						completedChange = true;
						/*fileName = iter->employeeTxt.c_str();
						remove(fileName);
						fileName = iter->flightTxt.c_str();
						remove(fileName);
						fileName = iter->planesTxt.c_str();
						remove(fileName);*/
						comp->deleteAirport(copyDel);
						break;
					}
					delSelection--;
				}
			}
			if (confirm == "n" || confirm == "N")
			{
				badInput = false;
				completedChange = false;
			}

		} while (badInput);
	} while (!completedChange);
}

void deleteManager() {
	string confirm;
	bool badInput = true;
	Manager manager;
	string name = "";
	Date *birthDate = new Date(0, 0, 0);
	double salary = 0;
	do
	{
		cout << "Are you sure you want to delete manager? This will forever delete this airports files(y/n)\n";
		cin >> confirm;
		if (cin.eof()) {
			cin.clear();
			return;
		}
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
			manager.name = name;
			manager.birthDate = birthDate;
			manager.salary = salary;
			currentAirport->setManager(manager);
		}
		if (confirm == "n" || confirm == "N")
		{
			badInput = false;
			return;
		}

	} while (badInput);
}

void deleteMaintenence()
{
	if (comp->getMaintenaceCompanies().empty())
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "No companies available to delete.\n";
		return;
	}
	int counter = 0, selection;
	bool badInput = false;

	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Which maintenance company do you want to delete?\n";
		priority_queue<Maintenance> aux = comp->getMaintenaceCompanies();
		while (!aux.empty())
		{
			counter++;
			cout << counter << ") " << aux.top().getName() << " available in " << aux.top().getHours() << " hours." << endl;
			aux.pop();
		}
		cin >> selection;
		counter = 0;
		if (cin.fail() || selection < 1 || (size_t)selection > comp->getMaintenaceCompanies().size())
		{
			cin.clear();
			//cin.ignore(100, '\n');
			badInput = true;
		}
		else
			badInput = false;
	} while (badInput);
	priority_queue<Maintenance> aux = comp->getMaintenaceCompanies();
	comp->clearMaintenance();
	while (!aux.empty())
	{
		counter++;
		if (counter != selection)
			comp->addMaintenanceCompany(aux.top());
		aux.pop();

	}

}