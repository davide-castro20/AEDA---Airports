#include "DeleteFunctions.h"
#include "Menus.h"

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
			cout << "Are you sure you want to delete the following employee?(y/n)\n";
			//currentAirport->employees.at(delSelection)->showEmp();
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
				if (cin.eof())
					return;
				else
				{
					badInput = false;
				}
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
				if (cin.eof())
					return;
				else
				{
					badInput = false;
				}
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