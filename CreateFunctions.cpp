#include "CreateFunctions.h"
#include "Utils.h"
#include "Company.h"
#include "Menus.h"
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
			birthDate = new Date(read);
		}

	} while (badInput);


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Category(A,B,C): \n";
	do
	{
		cin >> category;
		if (cin.eof()) {
			cin.clear();
			return;
		}
		cin.ignore(100, '\n');
		if (cin.fail() || ((category != "A") && (category != "B") && (category != "C")))
		{
			cin.clear();
			//cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid category! Please insert pilot's category again (A, B or C)\n";
		}
		else
		{
			badInput = false;
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
	Employee *newPilot = new Pilot(name, birthDate, category, planes, flights);
	for (size_t i = 0; i < currentAirport->employees.size(); i++)
	{
		if (*currentAirport->employees.at(i) == *newPilot)
		{
			cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
			return;
		}
	}
	currentAirport->employees.push_back(newPilot);
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
			birthDate = new Date(read);
		}

	} while (badInput);


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

	
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Flights: \n";
	do {
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
			if (cin.eof()) {
				cin.clear();
				return;
			}
			if (!(read.find_first_of(",") == string::npos)) {
				decompose(read, flightIdsString, ',');
				for (size_t i = 0; i < flightIdsString.size(); i++)
					flightIds.push_back(stoi(flightIdsString.at(i)));
			}
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
				if (count != flightIds.size())
				{
					cout << "One of more of those flights ID's don't exist!" << endl;
					badInput = true;
					break;
				}
				if (full)
				{
					cout << "One of more of those flights have a full Flight crew!" << endl;
					badInput = true;
					break;
				}
			}

			if (!badInput)
			{
				flights = convertIdToFlight(flightIds, currentAirport->flights);
				Employee *newFlightCrew = new FlightCrew(name, birthDate, category, flights);
				for (size_t i = 0; i < currentAirport->employees.size(); i++)
				{
					if (currentAirport->employees.at(i) == newFlightCrew)
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

				currentAirport->employees.push_back(newFlightCrew);
				cout << string(100, '-') << endl << "New Flight Crew member successfuly created!" << endl;
			}
		}

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
			birthDate = new Date(read);
		}

	} while (badInput);


	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Department: \n";
	do
	{

		getline(cin, department);
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (cin.fail() || (department.find_first_of("0123456789") != std::string::npos) || department == "")
		{
			cin.clear();
			//cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid department! Please insert again \n";
		}
		else
		{
			badInput = false;
		}
	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Function: \n";
	do
	{

		getline(cin, function);
		if (cin.eof())
			return;
		if (cin.fail() || (function.find_first_of("0123456789") != std::string::npos) || function == "")
		{
			cin.clear();
			//cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid function! Please insert again \n";
		}
		else
		{
			badInput = false;
		}
	} while (badInput);
	

	

	if(!badInput) {
		Employee* newAdmin = new Admin(name, birthDate, department, function);
		for (size_t i = 0; i < currentAirport->employees.size(); i++)
		{
			if (currentAirport->employees.at(i) == newAdmin)
			{
				cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
				return;
			}
		}
		currentAirport->employees.push_back(newAdmin);
		cout << string(100, '-') << endl << "New Administration member successfuly created!" << endl;
	}
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
			birthDate = new Date(read);
		}

	} while (badInput);

	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "Category: \n";
	do
	{
		cin >> category;
		cin.ignore(100, '\n');
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
			Employee* newBaseCrew = new BaseCrew(name, birthDate, category, sched);
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i) == newBaseCrew)
				{
					cout << "The employee " << name << ", with birth date " << birthDate << ", is already in the system" << endl;
					return;
				}
			}
			currentAirport->employees.push_back(newBaseCrew);
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
	do {
		getline(cin, destination);
		if (cin.eof()) {
			cin.clear();
			return;
		}
		if (cin.fail() || (destination.find_first_of("0123456789") != std::string::npos) || destination == "")
		{
			cin.clear();
			//cin.ignore(100, '\n');
			cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid destination! Please insert name again \n";
		}
		else
		{
			badInput = false;
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
				cout << "Invalid date! Please insert birth date again \n";
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
			for(size_t i = 0; i < currentAirport->employees.size(); i++)
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
					cout << "Merdou" << endl;
					currentAirport->flights.push_back(newFlight);
					return;
				}
				if (confirm == "n" || confirm == "N")
				{
					return;
				}
			}
			for (size_t j = 1; j < freeEmp.size() + 1; j++)
				cout << j << ") Name: " << freeEmp.at(j - 1)->getName() << "; Category: " << freeEmp.at(j - 1)->getCategory() << endl;
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
			for (size_t i = 0; i < currentAirport->employees.size(); i++)
			{
				if (currentAirport->employees.at(i)->getType() == "Flight Crew" && currentAirport->employees.at(i)->isFree(predictedSchedule))
				{
					freeEmp.push_back(currentAirport->employees.at(i));
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
			for (size_t j = 1; j < freeEmp.size() + 1; j++)
				cout << j << ") Name: " << freeEmp.at(j-1)->getName() << "; Category: " << freeEmp.at(j - 1)->getCategory() << endl;

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
			crew.at(i)->addFlight(newFlight);
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
		cin >> capacity;
		if (cin.eof())
			return;
		if (cin.fail() || capacity < 0 || capacity > 550)
		{
			cin.clear();
			cin.ignore(100, '\n');
			//cout << "-----------------------------------------------------------------------------------------------------\n";
			badInput = true;
			cout << "Invalid capacity! Please insert the plane's capacity again (must be less tha 550)\n";
		}
		else
		{
			badInput = false;
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
			getline(cin, country);
			if (cin.eof())
				return;
			if (!noAccent(country) || cin.fail() || (country.find_first_of("0123456789") != std::string::npos) || country == "" || islower(country.at(0)))
			{
				cin.clear();
				//cin.ignore(100, '\n');
				cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid Country! Please insert country again \n";
			}
			else
			{
				badInput = false;
			}
		} while (badInput);

		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "City: \n";
		do
		{
			getline(cin, city);
			if (cin.eof())
				return;
			if (!noAccent(city) || cin.fail() || (city.find_first_of("0123456789") != std::string::npos) || city == "" || islower(city.at(0)))
			{
				cin.clear();
				//cin.ignore(100, '\n');
				cout << "-----------------------------------------------------------------------------------------------------\n";
				badInput = true;
				cout << "Invalid City! Please insert City again \n";
			}
			else
			{
				badInput = false;
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
			string plane = country + "_Planes.txt";
			string flight = country + "_Flights.txt";
			string employee = country + "_Employees.txt";
			vector <Flight*> flights = {};
			vector <Employee*> employees = {};
			vector <Plane*> planes = {};
			local = new Local(country, city, stof(lon), stof(lat));
			airport = new Airport(planes, flights, employees, *local, plane, employee, flight);
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
			birthDate = new Date(read);
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
		if (noAccent(salary) || cin.fail() || salary == "" || stod(salary)<0)
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
		}
	} while (badInput);

	Manager manager;
	if (!badInput) {
		manager.name = name;
		manager.birthDate = *birthDate;
		manager.salary = stod(salary);
		if (currentAirport->manager.name != "") {
			cout << "Manager already exists, please delete him first to add a new one!\n";
			return;
		}
		currentAirport->setManager(manager);
		cout << string(100, '-') << endl << "New manager successfuly created!" << endl;
	}
}
