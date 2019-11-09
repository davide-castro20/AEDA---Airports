#include "CreateFunctions.h"
#include "Utils.h"
#include "Menus.h"

extern Airport *currentAirport;

using namespace std;

void createPerson()
{
	 int createSel;
	bool badInput;
	do {
		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "Which data to create?\n" << "1)A Pilot.\n" << "2)A Flight Crew member.\n" << "3)An Administration member.\n" << "4)A Base Crew member\n" << "0)Return to the last menu.\n";
			cin >> createSel;
			if (cin.eof())
				return;
			if (cin.fail() || createSel < 0 || createSel > 4)
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
		cin.ignore(1000, '\n');
		if (createSel == 0)
			return;
		switch (createSel)
		{
		case 1:
			createPilot();
			break;
		case 2:
			//createFlightCrew();
			break;
		case 3:
			//createAdmin();
			break;
		case 4:
			//createBaseCrew();
			break;
		case 0:
			break;
		}
		do
		{
			cout << "1)Create another person.\n" << "0)Return to the last menu.\n";
			cin >> createSel;
			if (cin.fail() || createSel < 0 || createSel > 1)
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
	} while (createSel != 0);
}

void createPilot()
{
	bool badInput = true;
	string name;
	Date *birthDate = NULL;
	string read;
	string category;
	vector<string> planeTypes;
	vector<int> flightIds;
	vector<Plane*> planes;
	vector<Flight*> flights;
	
	badInput = false;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
	do 
	{
		
		getline(cin, name);
		if (cin.fail() || (name.find_first_of("0123456789") != std::string::npos))
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

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "BirthDate (dd/mm/yyyy): \n";
	do
	{
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
			birthDate = new Date(read);
		}
		if (cin.eof())
			return;

	} while (badInput);


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

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Plane Types: \n";
	do
	{
		cin.ignore();
		getline(cin, read);
		if (cin.fail() || read.empty())
		{
			cin.clear();
			//cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
		}
		else
		{
			badInput = false;

			if (cin.eof())
				return;
			if (!(read.find_first_of(",") == string::npos))
				decompose(read, planeTypes, ',');
			else
			{
				trim(read);
				planeTypes.push_back(read);
			}
			for (size_t i = 0; i < planeTypes.size(); i++)
			{
				if ((planeTypes.at(i) != "A") && (planeTypes.at(i) != "B") && (planeTypes.at(i) != "C"))
					badInput = true;
			}
		}
		if(badInput)
			cout << "Invalid plane types! Please insert again \n";
		else
		{
			planes = convertCatToPlane(planeTypes, currentAirport->planes);
		}
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Flights: \n";
	do {
		getline(cin, read);
		if (cin.fail() || read.empty())
		{
			cin.clear();
			//cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
		}
		else
		{
			badInput = false;
			if (cin.eof())
				return;
			if (!(read.find_first_of(",") == string::npos))
				decomposeInt(read, flightIds, ',');
			else {
				trim(read);
				flightIds.push_back(stoi(read));
			}
			bool full = false;
			for (size_t i = 0; i < flightIds.size(); i++)
			{
				int count = 0;
				
				for (size_t j = 0; j < currentAirport->flights.size(); j++)
				{
					if (flightIds.at(i) == currentAirport->flights.at(j)->getId())
					{
						count++;
						int pilotCount = 0;
						for (size_t k = 0; k < currentAirport->flights.at(j)->getEmployees().size(); k++)
						{
							if (currentAirport->flights.at(j)->getEmployees().at(k)->getType() == "Pilot")
								pilotCount++;
						}
						if (pilotCount == 2)
							full = true;
					}
				}
				if (count == 0)
				{
					cout << "One of more of those flights ID's don't exist!" << endl;
					badInput = true;
					break;
				}
				if (full)
				{
					cout << "One of more of those flights have a full Pilot crew!" << endl;
					badInput = true;
					break;
				}
			}
			
			if (!badInput)
			{
				flights = convertIdToFlight(flightIds, currentAirport->flights);
				for (size_t i = 0; i < flights.size(); i++)
				{
					int catCount = 0;
					for (size_t j = 0; j < planeTypes.size(); j++)
					{
						if(planeTypes.at(j) == flights.at(i)->getPlane()->getType())
							catCount++;
					}
					if (catCount == 0)
					{
						cout << "This Pilot does not have the required plane types for one or more flights!" << endl;
						badInput = true;
						break;
					}
				}
			}
			else
			{
				Employee *newPilot = new Pilot(name, birthDate, category, planes, flights);
				currentAirport->employees.push_back(newPilot);
			}
		}

	} while (badInput);

}
