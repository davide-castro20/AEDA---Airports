#include "Utils.h"
#include "Menus.h"
#include <iomanip>
#include "ShowFunctions.h"


using namespace std;

extern Airport* currentAirport;


void showAirportData(Airport * airport)
{
	cout << '|' << string(98,'-') << '|' << endl;
	cout << '|' << setfill('-') << right << setw(49) << airport->local.getCity()
		<< left << " Airport" << right << setw(42) << '|' << endl;
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Location " << '|' << left << setw(48) << ' ' + airport->local.getCity()
		+ ", " + airport->local.getCountry() << '|' << endl;
	cout << '|' << string(49, ' ') << '|' << setw(48) << left << to_string(airport->local.getLatit()) + " N "
		+ to_string(airport->local.getLon()) + " W " << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->planes.size() << left << setw(49) << " Planes" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->employees.size() << left << setw(49) << " Employees" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->flights.size() << left << setw(49) << " possible flights" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
}


void showPersonMenu()
{
	bool badInput = false;
	int showSelect;
	string type;

	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "Which person to show?\n" << "1)Pilots.\n" << "2)Flight Crew members.\n" << "3)Administration members.\n" << "4)Base Crew members\n" << "5)Show by name\n" << "0)Return to the last menu.\n";
			cin >> showSelect;
			if (cin.fail() || showSelect <= -1 || showSelect > 5)
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

		switch (showSelect)
		{
		case 0:
			return;
		case 1:
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Pilot")
					showPerson(currentAirport->employees.at(i));
			}
			break;
		case 2:
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Flight Crew")
					showPerson(currentAirport->employees.at(i));
			}
			break;
		case 3:
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Admin")
					showPerson(currentAirport->employees.at(i));
			}
			break;
		case 4:
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Base Crew")
					showPerson(currentAirport->employees.at(i));
			}
			break;
		case 5:
			showByName();
			break;
		}

	} while (showSelect != 0);
}

void showPerson(Employee* emp)
{
	string type = emp->getType();
	double salary = emp->calcSalary();
	cout << '|' << string(98, '-') << '|' << endl;
	if (type == "Pilot")
	{
	
		string flights;
		size_t size = emp->getFlights().size();
		if (size > 0)
		{
			for (size_t i = 0; i < size; i++)
			{
				if (i < (size - 1))
					flights += to_string(emp->getFlights().at(i)->getId()) + ", ";
				else
					flights += to_string(emp->getFlights().at(i)->getId());
			}
		}
		else
			flights = "None";
		
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Name " << '|' << left << setw(77) << ' ' + emp->getName() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Birth Date " << "| " << left << setw(76) << emp->getDate().getDate() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Category " << "| " << left << setw(76) << emp->getCategory() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Salary " << "| " << left << setw(76) << salary << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Plane types " << "| " << left << setw(76) << emp->getPlaneTypes() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Flights " << "| " << left << setw(76) << flights << '|' << endl;
	}
	else if (type == "Flight Crew")
	{
		emp->calcSalary();

		string flights;
		size_t size = emp->getFlights().size();
		if (size > 0)
		{
			for (size_t i = 0; i < size; i++)
			{
				if (i < (size - 1))
					flights += to_string(emp->getFlights().at(i)->getId()) + ", ";
				else
					flights += to_string(emp->getFlights().at(i)->getId());
			}
		}
		else
			flights = "None";
	
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Name " << '|' << left << setw(77) << ' ' + emp->getName() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Birth Date " << "| " << left << setw(76) << emp->getDate().getDate() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Category " << "| " << left << setw(76) << emp->getCategory() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Salary " << "| " << left << setw(76) << salary << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Flights " << "| " << left << setw(76) << flights << '|' << endl;
	}
	else if (type == "Admin")
	{
		emp->calcSalary();

		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Name " << '|' << left << setw(77) << ' ' + emp->getName() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Birth Date " << "| " << left << setw(76) << emp->getDate().getDate() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Salary " << "| " << left << setw(76) << salary << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Department " << "| " << left << setw(76) << emp->getDepartment() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Function " << "| " << left << setw(76) << emp->getFunction() << '|' << endl;
	}
	else if (type == "Base Crew")
	{
		emp->calcSalary();

		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Name " << '|' << left << setw(77) << ' ' + emp->getName() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Birth Date " << "| " << left << setw(76) << emp->getDate().getDate() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Category " << "| " << left << setw(76) << emp->getCategory() << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Salary " << "| " << left << setw(76) << salary << '|' << endl;
		cout << '|' << string(98, '-') << '|' << endl;
		cout << '|' << right << setfill(' ') << setw(20) << "Schedule " << "| " << left << setw(76) << emp->getSchedule()->getSched() << '|' << endl;
	}
}

void showByName()
{
	bool badInput = false;
	string name;
	Date* birthDate = NULL;
	vector<Employee*> emps;
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
	do
	{
		cin.ignore(100, '\n');
		getline(cin, name);
		if (!noAccent(name) || cin.fail() || (name.find_first_of("0123456789") != std::string::npos) || name == "" || islower(name.at(0)))
		{
			cin.clear();
			//cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid name! Please insert name again \n";
		}
		else
		{
			badInput = false;
		}
		if (cin.eof())
			return;
	} while (badInput);

	if (currentAirport->employees.size() > 0)
	{
		for (size_t i = 0; i < currentAirport->employees.size(); i++)
		{
			if (currentAirport->employees.at(i)->getName() == name)
				emps.push_back(currentAirport->employees.at(i));
		}
		if (emps.size() == 1)
			showPerson(emps.at(0));
		else if (emps.size() == 0)
			cout << "There are no employees named " << name << " on this airport!\n";
		else
		{
			cout << "There are " << emps.size() << " employees named " << name << '!' << endl;
			for (size_t j = 0; j < emps.size(); j++)
				showPerson(emps.at(j));
		}
			
	}
	else
		cout << "There are currently no employees on this airport!\n";

}

void showFlightMenu()
{
	bool badInput = false;
	int showSelect;
	string type;

	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "Which flights to show?\n" << "1)All flights.\n" << "2)Flights within two dates.\n" /*<< "3)Flights ready to start.\n"*/ << "0)Return to the last menu.\n";
			cin >> showSelect;
			if (cin.fail() || showSelect <= -1 || showSelect > /*3*/ 2)
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

		switch (showSelect)
		{
		case 0:
			return;
		case 1:
			if (currentAirport->flights.size() > 0)
			{
				for (size_t i = 0; i < currentAirport->flights.size(); i++)
				{
					showFlight(currentAirport->flights.at(i));
				}
			}
			else
				cout << "No flights scheduled on this airport!\n";
			break;
		case 2:
			showFlightsDates();
			break;
		/*case 3:
			
			break;*/
		}
	} while (showSelect != 0);
}

void showFlight(Flight* flight)
{
	string plane;
	string pilots;
	string crew;
	size_t size1 = flight->getPilots().size();
	size_t size2 = flight->getCrew().size();
	string ready = "This flight is ready.";
	
	if (flight->getPlane() == NULL)
		plane = "No plane assigned to this flight yet.";
	else
		plane = "Type: " + flight->getPlane()->getType() + ", Capacity: " + to_string(flight->getPlane()->getCapacity());

	if ((size1 + size2 != 4) || (flight->getPlane() == NULL))
		ready = "This flight is NOT ready (plane or employees missing).";

	if (size1 == 0)
		pilots = "No pilots assigned to this flight yet.";
	else
	{
		for (size_t i = 0; i < size1; i++)
		{
			if (i < size1 - 1)
				pilots += flight->getPilots().at(i)->getName() + ", ";
			else
				pilots += flight->getPilots().at(i)->getName();
		}
	}
	if (size2 == 0)
		crew = "No crew assigned to this flight yet.";
	else
	{
		for (size_t i = 0; i < size2; i++)
		{
			if (i < size2 - 1)
				crew += flight->getCrew().at(i)->getName() + ", ";
			else
				crew += flight->getCrew().at(i)->getName();
		}
	}
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Id " << "| " << left << setw(76) << flight->getId() << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Destination " << '|' << left << setw(77) << ' ' + flight->getDestination() << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Schedule " << "| " << left << setw(76) << flight->getPredictedSchedule().getSched() << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Pilots " << "| " << left << setw(76) << pilots << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Flight Crew " << "| " << left << setw(76) << crew << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Plane " << "| " << left << setw(76) << plane << '|' << endl;

}

void showFlightsDates()
{
	bool badInput = false;
	Date* date1 = NULL;
	Date* date2 = NULL;
	string read;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "First Date (dd/mm/yyyy): \n";
	do
	{
		cin.ignore(100, '\n');
		getline(cin, read);
		if ((cin.fail() || !existingDate(read)) && !cin.eof())
		{
			cin.clear();
			//cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid date! Please insert birth date again \n";
		}
		else
		{
			badInput = false;
			date1 = new Date(read);
		}
		if (cin.eof())
			return;

	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Second Date (dd/mm/yyyy): \n";
	do
	{
		getline(cin, read);
		if (cin.eof())
			return;
		if (cin.fail() || !existingDate(read))
		{
			cin.clear();
			//cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid date! Please insert birth date again \n";
		}
		else
		{
			badInput = false;
			date2 = new Date(read);
			if (*date2 < *date1)
			{
				cout << "Invalid date! Second date must be after the first. \n";
				badInput = true;
			}
		}
		

	} while (badInput);

	int count = 0;
	for (size_t i = 0; i < currentAirport->flights.size(); i++)
	{
		if (checkBetweenDates(*date1, *date2, currentAirport->flights.at(i)->getPredictedSchedule().getArrivalDate())
			&& checkBetweenDates(*date1, *date2, currentAirport->flights.at(i)->getPredictedSchedule().getDepartureDate()))
		{
			showFlight(currentAirport->flights.at(i));
			count++;
		}
	}
	if (count == 0)
		cout << "No flights scheduled between the two dates! \n";

}

void showPlaneMenu()
{
	bool badInput = false;
	int showSelect;
	string type;

	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "Which planes to show?\n" << "1)All planes.\n" << "2)Planes by category.\n" << "0)Return to the last menu.\n";
			cin >> showSelect;
			if (cin.fail() || showSelect <= -1 || showSelect > 2)
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

		switch (showSelect)
		{
		case 0:
			return;
		case 1:
			for (size_t i = 0; i < currentAirport->planes.size(); i++)
			{
				showPlane(currentAirport->planes.at(i));
			}
			break;
		case 2:
			showPlaneByCat();
			break;
		}
	} while (showSelect != 0);
}

void showPlane(Plane* plane)
{

	string flights;
	size_t size = plane->getFlights().size();
	if (size > 0)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (i < (size - 1))
				flights += to_string(plane->getFlights().at(i)->getId()) + ", ";
			else
				flights += to_string(plane->getFlights().at(i)->getId());
		}
	}
	else
		flights = "No flights assined to this plane yet.";

	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Category " << '|' << left << setw(77) << ' ' + plane->getType() << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Capacity " << "| " << left << setw(76) << plane->getCapacity() << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(20) << "Flights " << "| " << left << setw(76) << flights << '|' << endl;
}

void showPlaneByCat()
{
	string category;
	bool badInput = false;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Category: \n";
	do
	{
		cin >> category;
		if (cin.fail() || ((category != "A") && (category != "B") && (category != "C")))
		{
			cin.clear();
			cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid category! Please insert pilot's category again (A, B or C)\n";
		}
		else
		{
			badInput = false;
		}
		if (cin.eof())
			return;

	} while (badInput);
	
	if (currentAirport->planes.size() > 0)
	{
		for (size_t i = 0; i < currentAirport->planes.size(); i++)
		{
			if (currentAirport->planes.at(i)->getType() == category)
				showPlane(currentAirport->planes.at(i));
		}
	}
	else
		cout << "There are no planes of this category in this airport!\n";
}