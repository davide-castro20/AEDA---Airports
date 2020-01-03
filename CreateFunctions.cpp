#include "CreateFunctions.h"
#include "Utils.h"
#include "Company.h"
#include "Menus.h"
#include "Maintenance.h"
#include "Airport.h"

extern Airport *currentAirport;
extern Company *comp;

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
			if (cin.eof()) {
				cin.clear();
				return;
			}
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
			createFlightCrew();
			break;
		case 3:
			createAdmin();
			break;
		case 4:
			createBaseCrew();
			break;
		case 0:
			break;
		}
		do
		{
			cout << string(100, '-') << endl;
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
			if (cin.eof()) {
				cin.clear();
				return;
			}

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
	vector<string> flightIdsString;
	vector<Plane*> planes;
	vector<Flight*> flights = {};
	
	badInput = false;


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
	do
	{
		badInput = false;
		try {
			name = readName();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidName na)
		{
			cout << "Name " << na.getName() << " is invalid!. Please insert name again \n";
			badInput = true;
		}
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "BirthDate (dd/mm/yyyy): \n";
	do
	{
		badInput = false;
		try
		{
			birthDate = readDate();
			
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidBirthDate da)
		{
			cout << "Date " << da.getBirthDate() << " is invalid! Please insert birth date again\n";
			badInput = true;
		}

	} while (badInput);


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Category(A,B,C): \n";
	do
	{
		badInput = false;
		try
		{
			category = readCategory();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidCategory cat)
		{
			cout << "Invalid category " << cat.getCategory() << "! Please insert pilot's category again (A, B or C)\n";
			badInput = true;
		}

	} while (badInput);


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Plane Types this pilot can fly(A,B,C): \n";
	do
	{
		planeTypes.clear();
		getline(cin, read);
		if (cin.eof()) {
			cin.clear();
			return;
		}
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
			if (!(read.find_first_of(",") == string::npos))
				decompose(read, planeTypes, ',');
			else
			{
				trim(read);
				planeTypes.push_back(read);
			}
			for (size_t i = 0; i < planeTypes.size(); i++)
			{
				if ((planeTypes.at(i) != "A") && (planeTypes.at(i) != "B") && (planeTypes.at(i) != "C")) {
					badInput = true;
					break;
				}
			}
		}
		if(badInput)
			cout << "Invalid plane types! Please insert again \n";
		else
		{
			planes = convertCatToPlane(planeTypes, currentAirport->planes);
		}
	} while (badInput);

	//cout << "-----------------------------------------------------------------------------------------------------\n";
	//cout << "Flights: \n";
	//do {
	//	//cin.ignore(100, '\n');
	//	getline(cin, read);
	//	if (cin.eof())
	//		return;
	//	if (cin.fail() || read.empty())
	//	{
	//		cin.clear();
	//		//cin.ignore(100, '\n');
	//		//cout << "-----------------------------------------------------------------------------------------------------\n";
	//		badInput = true;
	//	}
	//	else
	//	{
	//		badInput = false;
	//		if (!(read.find_first_of(",") == string::npos)) {
	//			decompose(read, flightIdsString, ',');
	//			for (size_t i = 0; i < flightIdsString.size(); i++)
	//				flightIds.push_back(stoi(flightIdsString.at(i)));
	//		}
	//		else {
	//			trim(read);
	//			flightIds.push_back(stoi(read));
	//		}
	//		bool full = false;
	//		for (size_t i = 0; i < flightIds.size(); i++)
	//		{
	//			int count = 0;
	//			
	//			for (size_t j = 0; j < currentAirport->flights.size(); j++)
	//			{
	//				if (flightIds.at(i) == currentAirport->flights.at(j)->getId())
	//				{
	//					count++;
	//					int pilotCount = 0;
	//					for (size_t k = 0; k < currentAirport->flights.at(j)->getEmployees().size(); k++)
	//					{
	//						if (currentAirport->flights.at(j)->getEmployees().at(k)->getType() == "Pilot")
	//							pilotCount++;
	//					}
	//					if (pilotCount == 2)
	//						full = true;
	//				}
	//			}
	//			if (count == 0)
	//			{
	//				cout << "One or more of those flights ID's don't exist!" << endl;
	//				badInput = true;
	//				break;
	//			}
	//			if (full)
	//			{
	//				cout << "One or more of those flights have a full Pilot crew!" << endl;
	//				badInput = true;
	//				break;
	//			}
	//		}
	//		
	//		if (!badInput)
	//		{
	//			flights = convertIdToFlight(flightIds, currentAirport->flights);
	//			for (size_t i = 0; i < flights.size(); i++)
	//			{
	//				int catCount = 0;
	//				for (size_t j = 0; j < planeTypes.size(); j++)
	//				{
	//					if(planeTypes.at(j) == flights.at(i)->getPlane()->getType())
	//						catCount++;
	//				}
	//				if (catCount == 0)
	//				{
	//					cout << "This Pilot does not have the required plane types for one or more flights!" << endl;
	//					badInput = true;
	//					break;
	//				}
	//			}
	Employee *newPilot = new Pilot(name, birthDate, category, planes, flights, currentAirport->getLocal().getCity(), true);
	/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
	{
		if (*currentAirport->employees.at(i) == *newPilot)
		{
			cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
			return;
		}
	}*/
	for (auto i : comp->getEmployees())
	{
		if (*i == *newPilot)
		{
			cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
			return;
		}
	}
	comp->getEmployees().insert(newPilot);
	//currentAirport->employees.push_back(newPilot);
	cout << string(100, '-') << endl << "New Pilot successfuly created!" << endl;
		//		cout << string(100, '-') << endl << "New Pilot successfuly created!" << endl;
		//	}
		//}

	//} while (badInput);
}

void createFlightCrew()
{
	bool badInput = false;
	string name;
	Date *birthDate = NULL;
	string read;
	string category;
	vector<int> flightIds;
	vector<Flight*> flights;
	vector<string> flightIdsString;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
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


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "BirthDate (dd/mm/yyyy): \n";
	do
	{
		badInput = false;
		try
		{
			birthDate = readDate();

		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidBirthDate da)
		{
			cout << "Date " << da.getBirthDate() << " is invalid! Please insert birth date again\n";
			badInput = true;
		}

	} while (badInput);



	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Category: \n";
	do
	{
		badInput = false;
		try
		{
			category = readCategory();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidCategory cat)
		{
			cout << "Invalid category " << cat.getCategory() << "! Please insert pilot's category again (A, B or C)\n";
			badInput = true;
		}

	} while (badInput);
	
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Flights: \n";
	bool badInput2 = false;
	do
	{
		badInput2 = false;
		badInput = false;
		do {
			badInput2 = false;
			try
			{
				flightIds = readFlights();
			}
			catch (Exit ex)
			{
				cout << ex.getMsg() << endl;
				return;
			}
			catch (InvalidFlights fl)
			{
				badInput2 = true;
				cout << "Invalid flights! Please insert again.\n";
			}
		} while (badInput2);


		bool full = false;
		int count = 0;
		for (size_t i = 0; i < flightIds.size(); i++)
		{

			for (size_t j = 0; j < currentAirport->flights.size(); j++)
			{
				if (flightIds.at(i) == currentAirport->flights.at(j)->getId())
				{
					count++;
					int crewCount = 0;
					for (size_t k = 0; k < currentAirport->flights.at(j)->getEmployees().size(); k++)
					{
						if (currentAirport->flights.at(j)->getEmployees().at(k)->getType() == "Flight Crew")
							crewCount++;
					}
					if (crewCount == 2)
						full = true;
				}
			}

		}
		if (count != flightIds.size())
		{
			cout << "One of more of those flights ID's don't exist!" << endl;
			badInput = true;
		}
		if (full)
		{
			cout << "One of more of those flights have a full Flight crew!" << endl;
			badInput = true;
		}
		if (badInput)
		{
			bool badInput2 = false;
			string confirm;
			cout << "Do you want to create this employee with no flights?" << endl;
			do {
				badInput2 = false;
				cin >> confirm;
				if (cin.eof())
					return;
				cin.ignore(100, '\n');
				if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
				{
					cin.clear();
					//cout << "-----------------------------------------------------------------------------------------------------\n";
					badInput2 = true;
				}
				else
				{
					badInput2 = false;

				}
			} while (badInput2);
			if (confirm == "y" || confirm == "Y")
			{
				Employee *newFlightCrew = new FlightCrew(name, birthDate, category, flights, currentAirport->getLocal().getCity(), true);
				/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
				{
					if (currentAirport->employees.at(i) == newFlightCrew)
					{
						cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
						return;
					}
				}*/
				for (auto i : comp->getEmployees())
				{
					if (*i == *newFlightCrew)
					{
						cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
						return;
					}
				}
				comp->getEmployees().insert(newFlightCrew);
				//currentAirport->employees.push_back(newFlightCrew);
				cout << string(100, '-') << endl << "New Flight Crew member successfuly created!" << endl;
				return;
			}
			else if (confirm == "n" || confirm == "N")
			{
				badInput2 = false;
			}
		}
		else
		{

			flights = convertIdToFlight(flightIds, currentAirport->flights);
			Employee *newFlightCrew = new FlightCrew(name, birthDate, category, flights, currentAirport->getLocal().getCity(), true);
			/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i) == newFlightCrew)
				{
					cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
					return;
				}
			}*/
			for (auto i : comp->getEmployees())
			{
				if (*i == *newFlightCrew)
				{
					cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
					return;
				}
			}

			for (size_t j = 0; j < flights.size(); j++)
			{
				vector<Employee*> crew = flights.at(j)->getEmployees();
				crew.push_back(newFlightCrew);
				flights.at(j)->setCrew(crew);
			}
			comp->getEmployees().insert(newFlightCrew);
			//currentAirport->employees.push_back(newFlightCrew);
			cout << string(100, '-') << endl << "New Flight Crew member successfuly created!" << endl;
		}
		//getline(cin, read);
		//if (cin.eof()) {
		//	cin.clear();
		//	return;
		//}
		//if (cin.fail() || read.empty() || (read.find_first_not_of("0123456789, ") != string::npos))
		//{
		//	cin.clear();
		//	//cin.ignore(100, '\n');
		//	//cout << "-----------------------------------------------------------------------------------------------------\n";
		//	cout << "Invalid Flights! Please insert again.\n";
		//	badInput = true;
		//}
		//else
		//{
		//	badInput = false;
		//	bool badInput2 = false;
		//	do
		//	{
		//		badInput2 = false;
		//		if (cin.eof()) {
		//			cin.clear();
		//			return;
		//		}
		//		if (!(read.find_first_of(",") == string::npos)) {
		//			decompose(read, flightIdsString, ',');
		//			for (size_t i = 0; i < flightIdsString.size(); i++)
		//				flightIds.push_back(stoi(flightIdsString.at(i)));
		//		}
		//		else {
		//			trim(read);
		//			flightIds.push_back(stoi(read));
		//		}
		//		bool full = false;
		//		int count = 0;
	} while (badInput);
}


void createAdmin()
{
	bool badInput = false;
	string name;
	Date *birthDate = NULL;
	string read;
	string department;
	string function;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
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

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "BirthDate (dd/mm/yyyy): \n";
	do
	{
		badInput = false;
		try
		{
			birthDate = readDate();

		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidBirthDate da)
		{
			cout << "Date " << da.getBirthDate() << " is invalid! Please insert birth date again\n";
			badInput = true;
		}

	} while (badInput);


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Department: \n";
	do
	{
		badInput = false;
		try
		{
			department = readDepFunc();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidName fu)
		{
			cout << "Invalid department " << fu.getName() << "!. Please insert again\n";
			badInput = true;
		}
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Function: \n";
	do
	{
		badInput = false;
		try
		{
			function = readDepFunc();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidName fu)
		{
			cout << "Invalid function " << fu.getName() << "!. Please insert again\n";
			badInput = true;
		}
	} while (badInput);
	
	Employee* newAdmin = new Admin(name, birthDate, department, function, currentAirport->getLocal().getCity(), true);
	/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
	{
		if (currentAirport->employees.at(i) == newAdmin)
		{
			cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
			return;
		}
	}*/
	for (auto i : comp->getEmployees())
	{
		if (*i == *newAdmin)
		{
			cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
			return;
		}
	}
	comp->getEmployees().insert(newAdmin);
	//currentAirport->employees.push_back(newAdmin);
	cout << string(100, '-') << endl << "New Administration member successfuly created!" << endl;
	
}

void createBaseCrew()
{
	bool badInput = false;
	string name;
	Date *birthDate = NULL;
	string read;
	string category;
	Time *start = NULL;
	Time *end = NULL;
	unsigned int hour;
	unsigned int minute;
	Schedule *sched = NULL;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
	do
	{
		try {
			name = readName();
			badInput = false;
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidName na)
		{
			cout << "Name " << na.getName() << " is invalid!. Please insert name again \n";
			badInput = true;
		}
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "BirthDate (dd/mm/yyyy): \n";
	do
	{
		badInput = false;
		try
		{
			birthDate = readDate();

		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidBirthDate da)
		{
			cout << "Date " << da.getBirthDate() << " is invalid! Please insert birth date again\n";
			badInput = true;
		}

	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Category: \n";
	do
	{
		badInput = false;
		try
		{
			category = readCategory();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidCategory cat)
		{
			cout << "Invalid category " << cat.getCategory() << "! Please insert pilot's category again (A, B or C)\n";
			badInput = true;
		}
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Schedule: \n";
	do
	{
		do
		{
			cout << "Starting time (hh:mm):\n";
			getline(cin, read);
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || (read.find_first_of(':') == string::npos))
			{
				cin.clear();
				cin.ignore(100, '\n');
				//cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid time! Please insert again\n";
			}
			else
			{
				char sep;
				istringstream startTime(read);
				startTime >> hour;
				startTime >> sep;
				startTime >> minute;
				start = new Time(hour, minute);
				if (!start->isValid())
				{
					badInput = true;
					cout << "Invalid time! Please insert again\n";
				}
			}
		} while (badInput);

		do
		{
			cout << "Ending time (hh:mm):\n";
			getline(cin, read);
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (cin.fail() || (read.find_first_of(':') == string::npos))
			{
				cin.clear();
				cin.ignore(100, '\n');
				//cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid time! Please insert again\n";
			}
			else
			{
				char sep;
				istringstream endTime(read);
				endTime >> hour;
				endTime >> sep;
				endTime >> minute;
				end = new Time(hour, minute);
				if (!end->isValid())
				{
					badInput = true;
					cout << "Invalid time! Please insert again\n";
				}
			}

		} while (badInput);

		if (!badInput)
		{
			sched = new Schedule(start, end);
			Employee* newBaseCrew = new BaseCrew(name, birthDate, category, sched, currentAirport->getLocal().getCity(), true);
			/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i) == newBaseCrew)
				{
					cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
					return;
				}
			}*/
			for (auto i : comp->getEmployees())
			{
				if (*i == *newBaseCrew)
				{
					cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
					return;
				}
			}
			comp->getEmployees().insert(newBaseCrew);
			//currentAirport->employees.push_back(newBaseCrew);
			cout << string(100, '-') << endl << "New Base Crew member successfuly created!" << endl;
		}

	} while (badInput);
	
}


//----FLIGHT-----

void createFlight()
{
	bool badInput = false;
	unsigned int number, number2;
	FlightSched *predictedSchedule = NULL;
	string destination;
	string read;
	vector<Employee*> crew;
	Plane* plane = NULL;
	Time *start = NULL;
	Time *end = NULL;
	unsigned int hour;
	unsigned int minute;
	Date* startD = NULL;
	Date* endD = NULL;
	vector<Plane*> freePlanes;
	vector<Employee*> freeEmp;
	

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Destination: \n";
	do
	{
		badInput = false;
		try {
			destination = readName();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidName na)
		{
			cout << "Destination " << na.getName() << " is invalid!. Please the destination name again \n";
			badInput = true;
		}
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Schedule: \n";
	
		
		cout << "| Start date (dd/mm/yyyy): \n";
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
				cout << "Invalid date! Please insert date again \n";
			}
			else
			{
				badInput = false;
				startD = new Date(read);
			}
			

		} while (badInput);

		cout << "| Starting time (hh:mm):\n";
		do
		{
			getline(cin, read);
			if (cin.eof())
				return;
			if (cin.fail() || (read.find_first_of(':') == string::npos))
			{
				cin.clear();
				//cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid time! Please insert again\n";
			}
			else
			{
				char sep;
				istringstream startTime(read);
				startTime >> hour;
				startTime >> sep;
				startTime >> minute;
				start = new Time(hour, minute);
				if (!start->isValid())
				{
					badInput = true;
					cout << "Invalid time! Please insert again\n";
				}
				else
					badInput = false;
			}

			
		} while (badInput);

		cout << "|----------------------------------------------------------------------------------------------------\n";
		cout << "| End Date (dd/mm/yyyy): \n";
		do
		{
			getline(cin, read);
			if (cin.eof())
				return;
			if ((cin.fail() || !existingDate(read)) && !cin.eof())
			{
				cin.clear();
				//cin.ignore(100, '\n');
				//cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid date! Please insert date again \n";
			}
			else
			{
				endD = new Date(read);
				if (*startD <= *endD)
				{
					if ((endD->getDay() - startD->getDay() > 1) || (endD->getMonth() != startD->getMonth()) || (endD->getYear() != startD->getYear()))
					{
						badInput = true;
						cout << "A flight cannot be longer than a day! Please insert a new date \n";
					}
					else
						badInput = false;
				}
				else {
					badInput = true;
					cout << "The arrival date cannot be earlier than the departure date. \n";
				}
			}
		} while (badInput);

		do
		{
			cout << "| Ending time (hh:mm):\n";
			getline(cin, read);
			if (cin.eof())
				return;
			if (cin.fail() || (read.find_first_of(':') == string::npos))
			{
				cin.clear();
				//cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid time! Please insert again\n";
			}
			else
			{
				char sep;
				istringstream endTime(read);
				endTime >> hour;
				endTime >> sep;
				endTime >> minute;
				end = new Time(hour, minute);
				if (!end->isValid())
				{
					badInput = true;
					cout << "Invalid time! Please insert again\n";
					continue;
				}
				if (startD->getDay() == endD->getDay())
				{
					if (*end < *start)
					{
						
						badInput = true;
						cout << "End time cannot be earlier than start! \n";
						continue;
					}
				}
				badInput = false;
				predictedSchedule = new FlightSched(startD, start, endD, end);
			}

			
		} while (badInput);

		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << "Plane: \n";
		for(size_t i = 0; i < currentAirport->planes.size(); i++)
		{
			if (currentAirport->planes.at(i)->isFree(predictedSchedule))
				freePlanes.push_back(currentAirport->planes.at(i));
		}
		if (freePlanes.size() < 1)
		{
			string confirm;
			cout << "Not enough free planes at the moment!" << endl;
			cout << "Do you want to create this flight with an empty crew and plane for now?" << endl;
			do {
				cin >> confirm;
				cin.ignore(100, '\n');
				if (cin.eof())
					return;
				if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
				{
					cin.clear();	
					cout << "-----------------------------------------------------------------------------------------------------\n";
					badInput = true;
				}
				else
				{
						badInput = false;
				}
			} while (badInput);
			if (confirm == "y" || confirm == "Y")
			{
				crew.clear();
				Flight* newFlight = new Flight(predictedSchedule, destination, crew, plane, -2);
				currentAirport->flights.push_back(newFlight);
				return;
			}
			if (confirm == "n" || confirm == "N")
			{
				return;
			}
		}
		unsigned int planeSel;
		bool doAgain = false;
		do {
			for (size_t i = 1; i < freePlanes.size() + 1; i++)
				cout << i << ") Type: " << freePlanes.at(i - 1)->getType() << "; Capacity: "<< freePlanes.at(i-1)->getCapacity() << endl;

			cout << endl << "Choose one of the free planes above.\n0)Create flight with empty plane." << endl;
			cin >> planeSel;
			cin.ignore(100, '\n');
			if (cin.eof())
				return;
			if (cin.fail() || planeSel < 0 || planeSel > currentAirport->planes.size() + 1)
			{
				cin.clear();
				cout << "Invalid plane! Please choose one the free planes shown\n";
				badInput = true;
			}
			else if (planeSel >= 1)
			{
				badInput = false;
				plane = freePlanes.at(planeSel - 1);
			}
			else if (planeSel == 0)
			{
				cout << "Do you want to create this flight with an empty plane for now?" << endl;
				string confirm;
				do {
					cin >> confirm;
					cin.ignore(100, '\n');
					if (cin.eof())
							return;
					if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
					{
						cin.clear();
						cout << "-----------------------------------------------------------------------------------------------------\n";
						badInput = true;
					}
					else
					{
						if (confirm == "y" || confirm == "Y")
						{
							doAgain = false;
							badInput = false;
						}
						else if (confirm == "n" || confirm == "N")
						{
							doAgain = true;
							badInput = false;
						}
					}
				} while (badInput);
			}
		} while (badInput || doAgain);

		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << "Crew: \n";

		do {
			
			cout << "| Pilots:\n";
			/*for(size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Pilot" && currentAirport->employees.at(i)->isFree(predictedSchedule))
				{
					for (size_t k = 0; k < currentAirport->employees.at(i)->getPlanes().size(); k++)
					{
						if (currentAirport->employees.at(i)->getPlanes().at(k) == plane)
						{
							freeEmp.push_back(currentAirport->employees.at(i));
							break;
						}
					}				
				}
			}*/
			for (auto i : comp->getEmployees())
			{
				if (i->getType() == "Pilot" && i->getAirport() == currentAirport->getLocal().getCity())
				{
					Pilot* pilot = dynamic_cast<Pilot*>(i);
					if (pilot->isFree(predictedSchedule)) {
						for (size_t k = 0; k < pilot->getPlanes().size(); k++)
						{
							if (pilot->getPlanes().at(k) == plane)
							{
								freeEmp.push_back(i);
								break;
							}
						}
					}
				}
			}
			

			if (freeEmp.size() < 2)
			{
				string confirm;
				cout << "Not enough free pilots at the moment!" << endl;
				cout << "Do you want to create this flight with an empty crew for now?" << endl;
				do {
					cin >> confirm;
					cin.ignore(100, '\n');
					if (cin.eof())
						return;
					if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
					{
						cin.clear();
						cout << "-----------------------------------------------------------------------------------------------------\n";
						badInput = true;
					}
					else
					{
							badInput = false;
					}
				} while (badInput);
				if (confirm == "y" || confirm == "Y")
				{
					crew.clear();
					Flight* newFlight = new Flight(predictedSchedule, destination, crew, plane, -2);
					if(plane != NULL)
						plane->addFlight(newFlight);
					currentAirport->flights.push_back(newFlight);
					return;
				}
				if (confirm == "n" || confirm == "N")
				{
					return;
				}
			}
			for (size_t j = 1; j < freeEmp.size() + 1; j++) {
				Pilot* pilot = dynamic_cast<Pilot*>(freeEmp.at(j - 1));
				cout << j << ") Name: " << pilot->getName() << "; Category: " << pilot->getCategory() << endl;
			}
			do
			{
				cout << endl << "Choose 2 of the free pilots above (first, second)" << endl;
				getline(cin, read);
				if (cin.eof())
					return;
				if (cin.fail() || read.empty() || read.find_first_of(',') == string::npos)
				{
					cin.clear();
					cout << "Invalid pilots! Please choose two of the free pilots shown\n";
					badInput = true;
				}
				else
				{
					badInput = false;
					if (read.find_first_not_of("123456789, ") == string::npos)
					{
						istringstream pil(read);
						char sep;
						pil >> number;
						pil >> sep;
						pil >> number2;
						if (pil.rdbuf()->in_avail() == 0) {
							if (number > 0 && number < freeEmp.size() + 1 && number2 > 0 && number2 < freeEmp.size() + 1 && number != number2)
							{
								crew.push_back(freeEmp.at(number - 1));
								crew.push_back(freeEmp.at(number2 - 1));
								cout << "Pilots added successfuly to the flight crew." << endl << endl;
							}
							else
							{
								badInput = true;
								cout << "Invalid pilots! Please choose two of the free pilots shown\n";
							}
						}
						else
						{
							badInput = true;
							cout << "Invalid piots! Please choose two of the free pilots shown\n";
						}
					}
					else
					{
						badInput = true;
						cout << "Invalid pilots! Please choose two of the free pilots shown\n";
					}
				}
			} while (badInput);
			
		} while (badInput);


		do {
			freeEmp.clear();
			cout << "| Flight Crew:\n";
			/*for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Flight Crew" && currentAirport->employees.at(i)->isFree(predictedSchedule))
				{
					freeEmp.push_back(currentAirport->employees.at(i));
				}
			}*/
			for (auto i : comp->getEmployees())
			{
				if (i->getType() == "Flight Crew" && i->getAirport() == currentAirport->getLocal().getCity())
				{
					FlightCrew* crew = dynamic_cast<FlightCrew*>(i);
					if (crew->isFree(predictedSchedule)) {
						freeEmp.push_back(i);
						break;
					}
				}
			}
			if (freeEmp.size() < 2)
			{
				string confirm;
				cout << "Not enough free employees at the moment!" << endl;
				cout << "Do you want to create this flight with an empty crew for now?" << endl;
				do {
					cin >> confirm;
					if (cin.eof())
						return;
					if (cin.fail() || !(confirm == "y" || confirm == "Y" || confirm == "n" || confirm == "N"))
					{
						cin.clear();
						cin.ignore(100, '\n');
						cout << "-----------------------------------------------------------------------------------------------------\n";
						badInput = true;
					}
					else
					{
							cin.ignore(100, '\n');
							badInput = false;
				
					}
				} while (badInput);
				if (confirm == "y" || confirm == "Y")
				{
					crew.clear();
					Flight* newFlight = new Flight(predictedSchedule, destination, crew, plane, -2);
					if(plane != NULL)
						plane->addFlight(newFlight);
					currentAirport->flights.push_back(newFlight);
					return;
				}
				if (confirm == "n" || confirm == "N")
				{
					return;
				}
				
			}
			for (size_t j = 1; j < freeEmp.size() + 1; j++) {
				FlightCrew* crew = dynamic_cast<FlightCrew*>(freeEmp.at(j - 1));
				cout << j << ") Name: " << crew->getName() << "; Category: " << crew->getCategory() << endl;
			}

			cout << endl << "Choose 2 of the free employees above (first, second)" << endl;
			getline(cin, read);
			if (cin.eof())
				return;
			if (cin.fail() || read.empty() || read.find_first_of(',') == string::npos)
			{
				cin.clear();
				cout << "Invalid employees! Please choose two of the free employees shown\n";
				badInput = true;
			}
			else
			{
				badInput = false;
				if (read.find_first_not_of("123456789, ") == string::npos)
				{
					istringstream fli(read);
					char sep;
					fli >> number;
					fli >> sep;
					fli >> number2;
					if (fli.rdbuf()->in_avail() == 0) {
						if (number > 0 && number < freeEmp.size() + 1 && number2 > 0 && number2 < freeEmp.size() + 1 && number != number2)
						{
							crew.push_back(freeEmp.at(number-1));
							crew.push_back(freeEmp.at(number2-1));
							cout << "Employees added successfuly to the flight crew." << endl << endl;
						}
						else
						{
							badInput = true;
							cout << "Invalid employees! Please choose two of the free employees shown\n";
						}
					}
					else
					{
						badInput = true;
						cout << "Invalid employes! Please choose two of the free employees shown\n";
					}
				}
				else
				{
					badInput = true;
					cout << "Invalid employes! Please choose two of the free employees shown\n";
				}
			}

		} while (badInput);

		Flight* newFlight = new Flight(predictedSchedule, destination, crew, plane, -2);
		if(plane != NULL)
			plane->addFlight(newFlight);
		currentAirport->flights.push_back(newFlight);
		for (size_t i = 0; i < crew.size(); i++)
		{
			if (crew.at(i)->getType() == "Pilot") {
				Pilot* pilot = dynamic_cast<Pilot*>(crew.at(i));
				pilot->addFlight(newFlight);
			}
			else if (crew.at(i)->getType() == "Flight Crew") {
				FlightCrew* crew2 = dynamic_cast<FlightCrew*>(crew.at(i));
				crew2->addFlight(newFlight);
			}
		}
		cout << endl << "Flight successfuly created!" << endl;
		
}

void createPlane()
{
	string type;
	int capacity;
	bool badInput = false;

	cout << string(100, '-') << endl;
	cout << "Category: " << endl;
	do
	{
		cin >> type;
		if (cin.eof())
			return;
		if (cin.fail() || ((type != "A") && (type != "B") && (type != "C")))
		{
			cin.clear();
			cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid category! Please insert plane's category again (A, B or C)\n";
		}
		else
		{
			badInput = false;
		}

	} while (badInput);

	cout << string(100, '-') << endl;
	cout << "Capacity: " << endl;
	do
	{
		badInput = false;
		try
		{
			capacity = readCapacity();
		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (capacityError ca)
		{
			cout << ca << endl;
			badInput = true;
		}

	} while (badInput);

	vector<Flight*> flights = {};
	Plane* newPlane = new Plane(type, capacity, flights);
	currentAirport->planes.push_back(newPlane);
	cout << string(100, '-') << endl;
	cout << "New plane successfuly created!" << endl;
}

void createAirport() {
		bool badInput = false;
		string country;
		string city;
		string lat;
		string lon;
		Local *local;
		Airport *airport = NULL;

		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Country: \n";
		cin.ignore(100, '\n');
		do
		{
			badInput = false;
			try
			{
				country = readName();
			}
			catch (Exit ex)
			{
				cout << ex.getMsg() << endl;
				return;
			}
			catch (InvalidName na)
			{
				cout << "Country " << na.getName() << " is invalid! Please insert country again.\n";
				badInput = true;
			}
		} while (badInput);

		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "City: \n";
		do
		{
			badInput = false;
			try
			{
				city = readName();
				if (alreadyExists(city)) {
					cout << "City already exists! Insert city again please!\n";
					badInput = true;
				}

			}
			catch (Exit ex)
			{
				cout << ex.getMsg() << endl;
				return;
			}
			catch (InvalidName na)
			{
				cout << "City " << na.getName() << " is invalid! Please insert city again.\n";
				badInput = true;
			}
		} while (badInput);

		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Latitude: \n";
		do
		{

			getline(cin, lat);
			if (cin.eof())
				return;
			if (cin.fail() || (lat.find_first_of("abcdefghijklmnopqrstuvxywzABCDEFGHIJKLMNOPQRSTUVXWYZ") != std::string::npos) || lat == ""||stoi(lat)>90 || stoi(lat)<(-90))
			{
				cin.clear();
				//cin.ignore(100, '\n');
				cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid latitude! Please insert latitude again \n";
			}
			else
			{
				badInput = false;
			}
		} while (badInput);

		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "Longitude: \n";
		do
		{

			getline(cin, lon);
			if (cin.eof())
				return;
			if (cin.fail() || (lon.find_first_of("abcdefghijklmnopqrstuvxywzABCDEFGHIJKLMNOPQRSTUVXWYZ") != std::string::npos) || lon == "" || stoi(lon)>180 || stoi(lon)<(-180))
			{
				cin.clear();
				//cin.ignore(100, '\n');
				cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid longitude! Please insert longitude again \n";
			}
			else
			{
				badInput = false;
			}
		} while (badInput);

		if (!badInput) {
			string plane = city + "_Planes.txt";
			string flight = city + "_Flights.txt";
			string employee = city + "_Employees.txt";
			vector <Flight*> flights = {};
			vector <Employee*> employees = {};
			vector <Plane*> planes = {};
			local = new Local(country, city, stof(lon), stof(lat));
			airport = new Airport(planes, flights, *local, plane, employee, flight);
		}
		comp->addAirport(airport);
		cout << string(100, '-') << endl << "New Airport successfuly created!" << endl;
}


void createManager() {
	bool badInput = false;
	string name;
	Date *birthDate = NULL;
	string read;
	string salary;

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
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

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "BirthDate (dd/mm/yyyy): \n";
	do
	{
		badInput = false;
		try
		{
			birthDate = readDate();

		}
		catch (Exit ex)
		{
			cout << ex.getMsg() << endl;
			return;
		}
		catch (InvalidBirthDate da)
		{
			cout << "Date " << da.getBirthDate() << " is invalid! Please insert birth date again\n";
			badInput = true;
		}

	} while (badInput);


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Salary: \n";
	do
	{

		getline(cin, salary);
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (!noAccent(salary) || cin.fail() || salary == "" || stod(salary) < 0)
		{
			cin.clear();
			//cin.ignore(100, '\n');
			
			badInput = true;
			cout << "Invalid salary! Please insert again \n";
		}
		else
		{
			badInput = false;
		}
	} while (badInput);

	Manager manager;
	if (!badInput) {
		manager.name = name;
		manager.birthDate = birthDate;
		manager.salary = stod(salary);
		if (currentAirport->manager.name != "") {
			cout << "Manager already exists, please delete him first to add a new one!\n";
			return;
		}
		currentAirport->setManager(manager);
		cout << string(100, '-') << endl << "New manager successfuly created!" << endl;
	}
}

void createMaintence() {
	string name;
	bool badInput = false;
	cin.ignore(100,'\n');
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Name: \n";
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
	int hours = rand() % 15;
	Maintenance maint(hours, 0, name);
	comp->addMaintenanceCompany(maint);
}

void hireOldEmp()
{
	int createSel;
	bool badInput;
	do {
		cout << "-----------------------------------------------------------------------------------------------------\n";
		do
		{
			cout << "Which type of employee do you want to hire again?\n" << "1)A Pilot.\n" << "2)A Flight Crew member.\n" << "3)An Administration member.\n" << "4)A Base Crew member\n" << "0)Return to the last menu.\n";
			cin >> createSel;
			if (cin.eof()) {
				cin.clear();
				return;
			}
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
			hireOldPilot();
			break;
		case 2:
			hireOldFlightCrew();
			break;
		case 3:
			hireOldAdmin();
			break;
		case 4:
			hireOldBase();
			break;
		case 0:
			break;
		}
		do
		{
			cout << string(100, '-') << endl;
			cout << "1)Hire another person.\n" << "0)Return to the last menu.\n";
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
			if (cin.eof()) {
				cin.clear();
				return;
			}

		} while (badInput);
	} while (createSel != 0);
}

void hireOldPilot()
{
	bool badInput = true;
	unsigned int delSelection;
	vector<Employee*> pilots;

	do
	{
		pilots.clear();
		for (auto i : comp->getEmployees())
		{
			if (i->getType() == "Pilot" && i->getEmployed() == false)
			{
				pilots.push_back(i);
			}
		}
		if (pilots.size() == 0) {
			cout << "No former pilots in the system\n";
			return;
		}
		cout << "Which former pilot do you want to hire?(0 to cancel)\n" << endl;
		for (size_t i = 1; i < pilots.size() + 1; i++)
			cout << i << ") " << pilots.at(i - 1)->getName() << "(" << pilots.at(i - 1)->getDate() << ")." << endl;
		cin >> delSelection;
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (cin.fail() || delSelection < 0 || delSelection > pilots.size() + 1)
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

	pilots.at(delSelection)->setAirport(currentAirport->getLocal().getCity());
	pilots.at(delSelection)->setEmployed(true);
	
	cout << string(100, '-') << endl << "Former pilot successfuly hired!" << endl;
}

void hireOldFlightCrew()
{
	bool badInput = true;
	vector<Employee*> employees;

	unsigned int delSelection;

	do
	{
		employees.clear();
		for (auto i : comp->getEmployees())
		{
			if (i->getType() == "Flight Crew" && i->getEmployed() == false)
			{
				employees.push_back(i);
			}
		}
		if (employees.size() == 0) {
			cout << "No former flight crew members in the system\n";
			return;
		}
		cout << "Which former flight crew member do you want to hire?(0 to cancel)\n" << endl;
		for (size_t i = 1; i < employees.size() + 1; i++)
			cout << i << ") " << employees.at(i - 1)->getName() << "(" << employees.at(i - 1)->getDate() << ")." << endl;
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

	employees.at(delSelection)->setAirport(currentAirport->getLocal().getCity());
	employees.at(delSelection)->setEmployed(true);

	cout << string(100, '-') << endl << "Former flight crew member successfuly hired!" << endl;
}

void hireOldAdmin()
{
	bool badInput = true;
	vector<Employee*> employees;

	unsigned int delSelection;

	do
	{
		employees.clear();
		for (auto i : comp->getEmployees())
		{
			if (i->getType() == "Admin" && i->getEmployed() == false)
			{
				employees.push_back(i);
			}
		}
		if (employees.size() == 0) {
			cout << "No former administration members in the system\n";
			return;
		}
		cout << "Which former administration member do you want to hire?(0 to cancel)\n" << endl;
		for (size_t i = 1; i < employees.size() + 1; i++)
			cout << i << ") " << employees.at(i - 1)->getName() << "(" << employees.at(i - 1)->getDate() << ")." << endl;
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

	employees.at(delSelection)->setAirport(currentAirport->getLocal().getCity());
	employees.at(delSelection)->setEmployed(true);

	cout << string(100, '-') << endl << "Former administration member successfuly hired!" << endl;
}

void hireOldBase()
{
	bool badInput = true;
	vector<Employee*> employees;

	unsigned int delSelection;

	do
	{
		employees.clear();
		for (auto i : comp->getEmployees())
		{
			if (i->getType() == "Base Crew" && i->getEmployed() == false)
			{
				employees.push_back(i);
			}
		}
		if (employees.size() == 0) {
			cout << "No former base crew members in the system\n";
			return;
		}
		cout << "Which former base crew member do you want to hire?(0 to cancel)\n" << endl;
		for (size_t i = 1; i < employees.size() + 1; i++)
			cout << i << ") " << employees.at(i - 1)->getName() << "(" << employees.at(i - 1)->getDate() << ")." << endl;
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

	employees.at(delSelection)->setAirport(currentAirport->getLocal().getCity());
	employees.at(delSelection)->setEmployed(true);

	cout << string(100, '-') << endl << "Former base crew member successfuly hired!" << endl;
}
