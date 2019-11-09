#include "CreateFunctions.h"
#include "Utils.h"
#include "Menus.h"

extern Airport *currentAirport;

using namespace std;

void createPerson()
{
	unsigned int createSel;
	bool badInput;
	do {
		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "Which data to create?\n" << "1)A Pilot.\n" << "2)A Flight Crew member.\n" << "3)An Administration member.\n" << "4)A Base Crew member\n" << "0)Return to the last menu.\n";
			cin >> createSel;
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
			if (cin.eof())
				return;

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
	string name;
	string read;
	string category;
	vector<int> planeIds;
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
			cin.ignore(100, '\n');
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


	cout << "BirthDate (dd/mm/yyyy): \n";
	do
	{
		getline(cin, read);
  		if ((cin.fail() || !existingDate(read)) && !cin.eof())
		{
			cin.clear();
			cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid date! Please insert birth date again \n";
		}
		else
		{
			badInput = false;
			Date *birthDate = new Date(read);
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
		getline(cin, read);

		//if(cin.fail() || read.empty())
	} while (1);


}
