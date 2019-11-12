#include "DeleteFunctions.h"
#include "Menus.h"
#include "ShowFunctions.h"

extern Airport *currentAirport;

void deletePersonData()
{
	bool badInput = true;
	unsigned int delSelection;
	string confirm;
	bool completedDel=false;
	
	do {
		
		do
		{
			completedDel = false;
			badInput = true;
			cout << "Whose data do you want to delete?(0 to cancel)\n" << endl;
			for (size_t i = 1; i < currentAirport->employees.size() + 1; i++)
				cout << i << ") " << currentAirport->employees.at(i - 1)-> getType() << ":" << currentAirport->employees.at(i - 1)->getName() << "." << endl;
			cin >> delSelection;
			if (cin.fail() || delSelection < 0 || delSelection > currentAirport->employees.size() + 1)
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
			if (cin.eof())
				return;
		} while (badInput);

		cin.clear();
		cin.ignore(100, '\n');

		if (delSelection == 0)
			return;

		delSelection--;
		do
		{
			showPerson(currentAirport->employees.at(delSelection));
			cout << "---------------------------------------------------------------------------------------------------\n";
			cout << "Are you sure you want to delete the following employee?(y/n)\n";
			cin >> confirm;
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N" || confirm == "0"))
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
			}
			else
			{
				if (cin.eof())
					return;
				else
				{
					badInput = false;
				}
			}
			if (confirm == "y" || confirm == "Y")
			{
				unsigned int pilotToSwap;
				if (currentAirport->employees.at(delSelection)->getType() == "Pilot")
				{
					vector<Employee*> freeEmp;
					for (size_t i = 0; i < currentAirport->employees.at(delSelection)->getFlights().size(); i++) {
						freeEmp.clear();
						for (size_t j = 0; j < currentAirport->employees.size(); j++)
						{
							if (currentAirport->employees.at(j)->isFree(&currentAirport->employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule()) && j != delSelection && currentAirport->employees.at(j)->getType() == "Pilot") {
								freeEmp.push_back(currentAirport->employees.at(j));
							}
						}
						if (freeEmp.size() > 0) {
							do {
								cout << "Please select another pilot to do the flight: " << currentAirport->employees.at(delSelection)->getFlights().at(i)->getDestination() << " which departs at " << currentAirport->employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule().getDepartureDate() << endl;
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
							freeEmp.at(pilotToSwap-1)->addFlight(currentAirport->employees.at(delSelection)->getFlights().at(i));
							currentAirport->employees.at(delSelection)->getFlights().at(i)->deleteCrew(currentAirport->employees.at(delSelection));
							currentAirport->employees.at(delSelection)->getFlights().at(i)->setCrewMemb(freeEmp.at(pilotToSwap-1));
						}
						else {
							cout << "There are no free pilots for this flight.\n";
						}
					}
				}
				else if (currentAirport->employees.at(delSelection)->getType() == "Flight Crew")
				{
					vector<Employee*> freeEmp;
					for (size_t i = 0; i < currentAirport->employees.at(delSelection)->getFlights().size(); i++) {
						freeEmp.clear();
						for (size_t j = 0; j < currentAirport->employees.size(); j++)
						{
							if (currentAirport->employees.at(j)->isFree(&currentAirport->employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule()) && j != delSelection && currentAirport->employees.at(j)->getType() == "Flight Crew") {
								freeEmp.push_back(currentAirport->employees.at(j));
							}
						}
						if (freeEmp.size() > 0) {
							do {
								cout << "Please select another flight crew to do the flight: " << currentAirport->employees.at(delSelection)->getFlights().at(i)->getDestination() << " which departs at " << currentAirport->employees.at(delSelection)->getFlights().at(i)->getPredictedSchedule().getDepartureDate() << endl;
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
							freeEmp.at(pilotToSwap - 1)->addFlight(currentAirport->employees.at(delSelection)->getFlights().at(i));
							currentAirport->employees.at(delSelection)->getFlights().at(i)->deleteCrew(currentAirport->employees.at(delSelection));
							currentAirport->employees.at(delSelection)->getFlights().at(i)->setCrewMemb(freeEmp.at(pilotToSwap - 1));
						}
						else {
							cout << "There are no free flight crew members for this flight.\n";
						}
					}
				}
				currentAirport->employees.erase(currentAirport->employees.begin() + delSelection);
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
			if (cin.eof())
				return;
		} while (badInput);
		cin.clear();
		cin.ignore(100, '\n');
		if (delSelection == 0)
			return;
		delSelection--;
		do
		{
			cout << "Are you sure you want to delete the following plane?(y/n)\n";
			//showPlane(currentAirport->planes.at(delSelection));
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
				if (cin.eof())
					return;
				else
				{
					badInput = false;
				}
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
	cout << "Which flight data do you want to delete?(0 to cancel)\n" << endl;
	do {
		do
		{
			for (size_t i = 1; i < currentAirport->flights.size() + 1; i++)
				cout << i << ") " << currentAirport->flights.at(i - 1)->getDestination() << " which departs at: " << currentAirport->flights.at(i-1)->getPredictedSchedule().getDepartureDate() << endl;
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
			if (cin.eof())
				return;
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
			if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
			{
				cin.clear();
				cin.ignore(100, '\n');
				badInput = true;
			}
			else
			{
				if (cin.eof())
					return;
				else
				{
					badInput = false;
				}
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
				for (size_t i = 0; i < currentAirport->employees.size(); i++)
				{
					for (size_t j = 0; j < currentAirport->employees.at(i)->getFlights().size(); j++)
						if (currentAirport->employees.at(i)->getFlights().at(j)->getId() == currentAirport->flights.at(delSelection)->getId())
						{
							currentAirport->employees.at(i)->deleteFlight(currentAirport->flights.at(delSelection)->getId());
							break;
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