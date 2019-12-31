#include "Utils.h"
#include "Menus.h"
#include <iomanip>
#include "ShowFunctions.h"


using namespace std;

extern Airport* currentAirport;

extern Company* comp;

void datesExpenses()
{
	unsigned int month1, month2, year1, year2;
	bool badInput=true;
	double pilotExp = 0, baseCrewExp = 0, flightCrewExp = 0, adminExp = 0, planesExp = 0;
	do {
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Which month do you want to start the verification for the total expenses?\n";
			cin >> month1;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || month1 <= 0 || month1 > 12)
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
		cin.ignore(100, '\n');
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Which year do you want to start the verification for the total expenses?\n";
			cin >> year1;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || year1 <= 0)
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
		cin.ignore(100, '\n');
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Which month do you want to end the verification for the total expenses?\n";
			cin >> month2;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || month2 <= 0 || month2 > 12)
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
		cin.ignore(100, '\n');
		do
		{
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << "Which year do you want to end the verification for the total expenses?\n";
			cin >> year2;
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || year2 <= 0)
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
		cin.ignore(100, '\n');
		int nMonths = month2 - month1 + (year2 - year1) * 12 + 1;
		if (nMonths > 0) {
			badInput = false;
			for (size_t i = 0; i < currentAirport->planes.size(); i++)
			{
				planesExp += inBetween(currentAirport->planes.at(i), month1, month2, year1, year2);
			}
			string type;
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				type = currentAirport->employees.at(i)->getType();
				if (type == "Pilot")
					pilotExp += inBetween(currentAirport->employees.at(i), month1, month2, year1, year2);
				else if (type == "Flight Crew")
					flightCrewExp += inBetween(currentAirport->employees.at(i), month1, month2, year1, year2);
				else if (type == "Base Crew")
					baseCrewExp += currentAirport->employees.at(i)->calcSalary()*nMonths;
				else if (type == "Admin")
					adminExp += currentAirport->employees.at(i)->calcSalary()*nMonths;
			}

			cout << '.' << string(98, '-') << '.' << endl;
			cout << '|' << setfill('-') << right << setw(49) << currentAirport->local.getCity() << left << " Airport" << right << setw(42) << '|' << endl;
			cout << '|' << setfill('-') << setw(99) << '|' << endl;
			cout << '|' << right << setfill(' ') << setw(49) << "Total Expenses Between The Selected Dates " << '|' << left << setw(48) << ' ' + to_string(pilotExp + flightCrewExp + baseCrewExp + adminExp + planesExp) << '|' << endl;
			cout << '|' << right << setfill(' ') << setw(49) << "From which " << '|' << left << setw(48) << " " + to_string(pilotExp) + " are from pilots" << '|' << endl;
			cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(flightCrewExp) + " are from flight crew members" << '|' << endl;
			cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(baseCrewExp) + " are from base crew members" << '|' << endl;
			cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(adminExp) + " are from admins" << '|' << endl;
			cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(planesExp) + " are from planes" << '|' << endl;
		}
		else
		{
			cout << "Invalid dates, please try again.\n";
			badInput = true;
		}
	}while (badInput);
}

void showPlanesExpenses()
{
	double a = 0, b = 0, c = 0;
	for (size_t i = 0; i < currentAirport->planes.size(); i++)
	{
		if (currentAirport->planes.at(i)->getType() == "A")
			a += currentAirport->planes.at(i)->calcExp();
		if (currentAirport->planes.at(i)->getType() == "B")
			b += currentAirport->planes.at(i)->calcExp();
		if (currentAirport->planes.at(i)->getType() == "C")
			c += currentAirport->planes.at(i)->calcExp();
	}
	cout << '.' << string(98, '-') << '.' << endl;
	cout << '|' << setfill('-') << right << setw(49) << currentAirport->local.getCity() << left << " Airport" << right << setw(42) << '|' << endl;
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Total Plane Expenses :" << '|' << left << setw(48) << ' ' + to_string(a+b+c) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "From which :" << '|' << left << setw(48) << " " + to_string(a) + " are from planes of type \"A\"" << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(b) + " are from planes of type \"B\"" << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(c) + " are from planes of type \"C\"" << '|' << endl;
}

void showEmployeeExpenses()
{
	double  pilots=0, base=0, flight=0, admin=0;
	for (size_t i = 0; i < currentAirport->employees.size(); i++)
	{
		if (currentAirport->employees.at(i)->getType() == "Pilot")
			pilots += currentAirport->employees.at(i)->calcSalary();
		else if (currentAirport->employees.at(i)->getType() == "Flight Crew")
			flight += currentAirport->employees.at(i)->calcSalary();
		else if (currentAirport->employees.at(i)->getType() == "Base Crew")
			base += currentAirport->employees.at(i)->calcSalary();
		else if (currentAirport->employees.at(i)->getType() == "Admin")
			admin += currentAirport->employees.at(i)->calcSalary();
	}
	cout << '.' << string(98, '-') << '.' << endl;
	cout << '|' << setfill('-') << right << setw(49) << currentAirport->local.getCity() << left << " Airport" << right << setw(42) << '|' << endl;
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Total Employee Expenses " << '|' << left << setw(48) << ' ' + to_string(pilots+flight+base+admin) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "From which " << '|' << left << setw(48) << " " + to_string(pilots) + " are from pilots" << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(flight) + " are from flight crew members" << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(base) + " are from base crew members" << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(50) << '|' << left << setw(48) << " " + to_string(admin) + " are from admins" << '|' << endl;
}

void showAirportData(Airport * airport)
{
	double total = 0;
	for (size_t i = 0; i < airport->employees.size(); i++)
		total += airport->employees.at(i)->calcSalary();
	for (size_t i = 0; i < airport->planes.size(); i++)
		total += airport->planes.at(i)->calcExp();

	cout << '|' << string(98,'-') << '|' << endl;
	cout << '|' << setfill('-') << right << setw(49) << airport->local.getCity()
		<< left << " Airport" << right << setw(42) << '|' << endl;
	cout << '|' << setfill('-') << setw(99) << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Location " << '|' << left << setw(48) << ' ' + airport->local.getCity()
		+ ", " + airport->local.getCountry() << '|' << endl;
	cout << '|' << string(49, ' ') << '|' << setw(48) << left << ' ' + to_string(airport->local.getLatit()) + " N "
		+ to_string(airport->local.getLon()) + " W " << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->planes.size() << left << setw(49) << " Planes" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->employees.size() << left << setw(49) << " Employees" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << airport->flights.size() << left << setw(49) << " possible flights" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << setfill(' ') << right << setw(49) << total << left << setw(49) << " euros in total expenses" << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Manager's Name " << '|' << left << setw(48) << " " + airport->manager.name << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Manager's Birth Date " << '|' << left << setw(48) << " " + airport->manager.birthDate->getDate() << '|' << endl;
	cout << '|' << string(98, '-') << '|' << endl;
	cout << '|' << right << setfill(' ') << setw(49) << "Manager's Salary " << '|' << left << setw(48) << " " + to_string(airport->manager.salary) << '|' << endl;

	
}

void showPersonMenu()
{
	bool badInput = false;
	int showSelect;
	string type;
	int counter;
	if (currentAirport->employees.size() == 0)
	{
		cout << "There are no persons on this aiport yet!\n";
		return;
	}

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
			counter = 0;
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Pilot") {
					counter++;
					showPerson(currentAirport->employees.at(i));
				}
			}
			if (counter == 0) {
				cout << "No pilots on this airport"<<endl;
			}
			break;
		case 2:
			counter = 0;
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Flight Crew") {
					counter++;
					showPerson(currentAirport->employees.at(i));
				}
			}
			if (counter == 0) {
				cout << "No flight crew members on this airport" << endl;
			}
			break;
		case 3:
			counter = 0;
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Admin") {
					counter++;
					showPerson(currentAirport->employees.at(i));
				}
			}
			if (counter == 0) {
				cout << "No administrators on this airport" << endl;
			}
			break;
		case 4:
			counter = 0;
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Base Crew") {
					counter++;
					showPerson(currentAirport->employees.at(i));
				}
			}
			if (counter == 0) {
				cout << "No base crew members on this airport" << endl;
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
		cout << '|' << right << setfill(' ') << setw(20) << "Airport " << '|' << left << setw(77) << ' ' + emp->getAirport() << '|' << endl;
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
		cout << '|' << right << setfill(' ') << setw(20) << "Airport " << '|' << left << setw(77) << ' ' + emp->getAirport() << '|' << endl;
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
		cout << '|' << right << setfill(' ') << setw(20) << "Airport " << '|' << left << setw(77) << ' ' + emp->getAirport() << '|' << endl;
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
		cout << '|' << right << setfill(' ') << setw(20) << "Airport " << '|' << left << setw(77) << ' ' + emp->getAirport() << '|' << endl;
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
	cin.ignore(100, '\n');
	do
	{
		try {
			name = readName();
			badInput = false;
		}
		catch (Exit ex)
		{
			ex.getMsg();
			return;
		}
		catch (InvalidName na)
		{
			cout << "Name " << na.getName() << " is invalid!. Please insert name again \n";
			badInput = true;
		}
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
	string ready = "This flight is ready";
	
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
	cout << '|' << string(98, '-') << '|' << endl;
	int s1 = 30 - ready.size() / 2;
	int s2 = 68 - ready.size() / 2;
	cout << '|' << string(s1, ' ') << ready << string(s2, ' ') << '|' << endl;

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
		if (cin.eof()) {
			cin.clear();
			return;
		}
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
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Second Date (dd/mm/yyyy): \n";
	do
	{
		getline(cin, read);
		if (cin.eof()) {
			cin.clear();
			return;
		}
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
	if (currentAirport->planes.size() == 0) {
		cout << "No planes in this airport!\n";
		return;
	}
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
		if (cin.eof()) {
			cin.clear();
			return;
		}
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

void showByNameCompany()
{
	bool badInput = false;
	string name;
	Date* birthDate = NULL;
	vector<Employee*> emps;
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
	cin.ignore(100, '\n');
	do
	{
		try {
			name = readName();
			badInput = false;
		}
		catch (Exit ex)
		{
			ex.getMsg();
			return;
		}
		catch (InvalidName na)
		{
			cout << "Name " << na.getName() << " is invalid!. Please insert name again \n";
			badInput = true;
		}
	} while (badInput);

	if (comp->getEmployees().size() > 0)
	{
		for (auto x = comp->getEmployees().begin(); x != comp->getEmployees().end(); x++)
		{
			if ((*x)->getName() == name)
				emps.push_back(*x);
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

void showPersonMenuCompany()
{
	bool badInput = false;
	int showSelect, showSelect1;
	string type;
	int counter;
	vector <Employee*> emps;
	if (comp->getEmployees().size() == 0)
	{
		cout << "There are no persons on the company yet!\n";
		return;
	}

	do
	{
		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "Which persons to show?\n" << "1)Pilots.\n" << "2)Flight Crew members.\n" << "3)Administration members.\n" << "4)Base Crew members\n" << "5)Show by name\n" << "0)Return to the last menu.\n";
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

		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "1)Not employed.\n" << "2)Employed.\n" << "0)Return to the last menu.\n";
			cin >> showSelect1;
			if (cin.fail() || showSelect1 <= -1 || showSelect1 > 2)
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
		if (showSelect1 == 0)
			return;

		switch (showSelect)
		{

		case 0:
			return;
		case 1:
			counter = 0;
			for (auto x : comp->getEmployees())
			{
				if (x->getType() == "Pilot" && x->getEmployed() == showSelect1 - 1) {
					counter++;
					emps.push_back(x);
				}
			}
			sort(emps.begin(), emps.end(), rule);
			for (auto x : emps) {
				showPerson(x);
			}
			if (counter == 0) {
				cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "No results!" << endl;
			}
			break;
		case 2:
			counter = 0;
			for (auto x : comp->getEmployees())
			{
				if (x->getType() == "Flight Crew" && x->getEmployed() == showSelect1 - 1) {
					counter++;
					emps.push_back(x);
				}
			}
			sort(emps.begin(), emps.end(), rule);
			for (auto x : emps) {
				showPerson(x);
			}
			if (counter == 0) {
				cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "No results!" << endl;
			}
			break;
		case 3:
			counter = 0;
			for (auto x : comp->getEmployees())
			{
				if (x->getType() == "Admin" && x->getEmployed() == showSelect1 - 1) {
					counter++;
					emps.push_back(x);
				}
			}
			sort(emps.begin(), emps.end(), rule);
			for (auto x : emps) {
				showPerson(x);
			}
			if (counter == 0) {
				cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "No results!" << endl;
			}
			break;
		case 4:
			counter = 0;
			for (auto x : comp->getEmployees())
			{
				if (x->getType() == "Base Crew" && x->getEmployed() == showSelect1 - 1) {
					counter++;
					emps.push_back(x);
				}
			}
			sort(emps.begin(), emps.end(), rule);
			for (auto x : emps) {
				showPerson(x);
			}
			if (counter == 0) {
				cout << "-----------------------------------------------------------------------------------------------------\n";
				cout << "No results!" << endl;
			}
			break;
		case 5:
			showByNameCompany();
			break;
		}

	} while (showSelect != 0);
}