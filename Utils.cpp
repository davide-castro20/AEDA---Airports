#include "Utils.h"

extern Airport* currentAirport;
extern Company* comp;

double inBetween(Employee* obj, int month1, int month2, int year1, int year2)
{
	double total = 0;
	int nMonths = month2 - month1 + (year2 - year1) * 12;
	if (nMonths < 0)
		return 0;
	vector<Flight*> flights = {}, copyFlights = obj->getFlights();
	Date date1(1, month1, year1);
	Date date2(days(year2, month2), month2, year2);
	for (size_t i = 0; i < obj->getFlights().size(); i++)
		if (checkBetweenDates(date1, date2, obj->getFlights().at(i)->getPredictedSchedule().getDepartureDate()))
			flights.push_back(obj->getFlights().at(i));
	obj->setFlights(flights);
	total = obj->calcSalary();
	obj->setFlights(copyFlights);

	if (nMonths > 0) {
		if (obj->getType() == "Flight Crew")
			total += 800 * (nMonths - 1);
		else if (obj->getType() == "Pilot")
			total += 1000 * (nMonths - 1);
	}
	return total;
}

string readName()
{
	string name;
	getline(cin, name);
	if (cin.eof()) {
		cin.clear();
		throw Exit();
	}
	if ( name == "" || !noAccent(name) || cin.fail() || (name.find_first_of("0123456789") != std::string::npos) || islower(name.at(0)) )
	{
		cin.clear();
		//cin.ignore(100, '\n');
		cout << "-----------------------------------------------------------------------------------------------------\n";
		throw InvalidName(name);
		//cout << "Invalid name! Please insert name again \n";
	}
	return name;
}

Date* readDate()
{
	Date* date = NULL;
	string read;
	getline(cin, read);
	if (cin.eof()) {
		cin.clear();
		throw Exit();
	}
	if ((cin.fail() || !existingDate(read)) && !cin.eof())
	{
		cin.clear();
		//cin.ignore(100, '\n');
		//cout << "-----------------------------------------------------------------------------------------------------\n";
		throw InvalidBirthDate(read);
	}
	else
	{
		date = new Date(read);
	}
	return date;
}

string readCategory()
{
	string category;
	cin >> category;
	if (cin.eof()) {
		cin.clear();
		throw Exit();
	}
	cin.ignore(100, '\n');
	if (cin.fail() || ((category != "A") && (category != "B") && (category != "C")))
	{
		cin.clear();
		throw InvalidCategory(category);
	}
	return category;
}

string readDepFunc()
{
	string function;
	cin >> function;
	if (cin.eof()) {
		cin.clear();
		throw Exit();
	}
	cin.ignore(100, '\n');
	if (cin.fail() || (function.find_first_of("0123456789") != std::string::npos) || function == "")
	{
		cin.clear();
		//cin.ignore(100, '\n');
		//cout << "-----------------------------------------------------------------------------------------------------\n";
		throw InvalidName(function);
	}
	return function;
}

vector<int> readFlights()
{
	vector<int> flightIds = {};
	vector<string> flightIdsString;
	string read;
	getline(cin, read);
	if (cin.eof()) {
		cin.clear();
		throw Exit();
	}
	if (cin.fail() || read.empty() || (read.find_first_not_of("0123456789, ") != string::npos))
	{
		cin.clear();
		throw InvalidFlights(read);
	}
	else
	{
		if (!(read.find_first_of(",") == string::npos)) {
			decompose(read, flightIdsString, ',');
			for (size_t i = 0; i < flightIdsString.size(); i++)
				flightIds.push_back(stoi(flightIdsString.at(i)));
		}
		else {
			trim(read);
			flightIds.push_back(stoi(read));
		}
	}
	return flightIds;
}

int readCapacity()
{
	int capacity;
	cin >> capacity;
	cin.ignore(100, '\n');
	if (cin.eof())
	{
		cin.clear();
		throw Exit();
	}
	if (cin.fail() || capacity < 0 || capacity > 550)
	{
		cin.clear();
		throw capacityError(capacity);
	}
	return capacity;
}

double inBetween(Plane* obj, int month1, int month2,int year1,int year2)
{
	double total = 0;
	int nMonths = month2 - month1 + (year2 - year1) * 12;
	vector<Flight*> flights = {}, copyFlights=obj->getFlights();
	Date date1(1, month1, year1);
	Date date2(days(year2, month2), month2, year2);
	for (size_t i = 0; i < obj->getFlights().size(); i++)
		if (checkBetweenDates(date1,date2,obj->getFlights().at(i)->getPredictedSchedule().getDepartureDate()))
			flights.push_back(obj->getFlights().at(i));
	obj->setFlights(flights);
	total = obj->calcExp();
	obj->setFlights(copyFlights);
	if (nMonths > 0) {
		if (obj->getType() == "A")
			total += 500.0 * (nMonths - 1);
		else if (obj->getType() == "B")
			total += 750.0 * (nMonths - 1);
		else if (obj->getType() == "C")
			total += 1000.0 * (nMonths - 1);
	}
	return total;
}

bool leapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 4 == 0 && year % 400 == 0)
		return true;
	return false;
}

int days(int year, int month)
{
	int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && leapYear(year))
		return 29;
	else
		return d[month - 1];
}

std::vector<Flight*> convertIdToFlight(const std::vector<int> &flightIds, const std::vector<Flight*> &flights)
{
	std::vector<Flight*> flightsConv;
	for (size_t i = 0; i < flightIds.size(); i++)
	{
		for (size_t j = 0; j < flights.size(); j++)
		{
			if (flightIds.at(i) == flights.at(j)->getId())
			{
				flightsConv.push_back(flights.at(j));
				break;
			}
		}
	}
	return flightsConv;
}

std::vector<Plane*> convertCatToPlane(const std::vector<string> &planeTypes, const std::vector<Plane*> &planes)
{
	std::vector<Plane*> planesConv;
	for (size_t i = 0; i < planeTypes.size(); i++)
	{
		for (size_t j = 0; j < planes.size(); j++)
		{
			if (planeTypes.at(i) == planes.at(j)->getType())
			{
				planesConv.push_back(planes.at(j));
				break;
			}
		}
	}
	return planesConv;
}

void trimLeft(string &s)
{
	s.erase(0, s.find_first_not_of(" "));
}


void trimRight(string &s)
{
	s.erase(s.find_last_not_of(" ") + 1);
}

void trim(string &s)
{
	trimLeft(s);
	trimRight(s);
}

void decompose(string s, vector<string> &elements, char sep)
{
	size_t pos = s.find(sep);
	while (pos != string::npos)
	{
		string elem = s.substr(0, pos);
		trim(elem);
		elements.push_back(elem);
		s.erase(0, pos + 1);
		pos = s.find(sep);
	}
	trim(s);
	elements.push_back(s);
}


void decomposeInt(std::string line, std::vector<int>& vect, char sep)
{
	istringstream iS(line);
	vector<int> elems;
	string elem;
	while (getline(iS, elem, sep))
	{
		trim(elem);
		if (elem != "" && elem.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos)
			elems.push_back(stoi(elem));
	}
	vect = elems;
}


bool existingDate(string &dt)
{
	istringstream iS(dt);
	int year, month, day, maxDays;
	char delimiter; // Slash
	iS >> day;
	iS >> delimiter;
	if (delimiter != '/')
		return false;
	iS >> month;
	iS >> delimiter;
	if (delimiter != '/')
		return false;
	iS >> year;
	if (year >= 0 && (month >= 1 && month <= 12))
	{
		maxDays = days(year, month);
		if (day >= 1 && day <= maxDays)
			return true;
	}
	return false;
}

bool endLaterThenBeg(string &endD, string &begD)
{
	istringstream iS(endD);
	int endYear, endMonth, endDay;
	char delimiter; // Slash
	iS >> endYear;
	iS >> delimiter;
	iS >> endMonth;
	iS >> delimiter;
	iS >> endDay;

	iS.clear();
	iS.str(begD);
	int begYear, begMonth, begDay;
	iS >> begYear;
	iS >> delimiter;
	iS >> begMonth;
	iS >> delimiter;
	iS >> begDay;

	if (endYear < begYear)
		return true;
	else if (endMonth < begMonth && endMonth == begYear)
		return true;
	else if (endDay <= begDay && endMonth == begMonth && endYear == begYear)
		return true;
	return false;
}

bool checkBetweenDates(Date date1, Date date2, Date date)
{
	if (date <= date2)
	{
		if (date1 <= date)
			return true;
		else
			return false;
	}
	else
		return false;	
}

bool checkInt2(string s)
{
	bool confirm = true;
	for (const auto &c : s)
	{
		if (!isdigit(c))
		{
			confirm = false;
			break;
		}
	}
	return confirm;
}

int checkInt(string sentence)
{
	string n;
	while (true)
	{
		cout << sentence;
		cin >> n;
		if (cin.eof())
			return -1;
		if (checkInt2(n))
			return stoi(n);
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, try again.\n";
		}
	}
}

//bool checkCats(const string &cats, vector<char> )
//{
//	istringstream iS(cats);
//	vector<s
//	char delimiter; // Slash
//	iS >> year;
//	iS >> delimiter;
//	if (delimiter != '/')
//		return true;
//	iS >> month;
//	iS >> delimiter;
//	if (delimiter != '/')
//		return true;
//	iS >> day;
//	if (year >= 0 && (month >= 1 && month <= 12))
//	{
//		maxDays = days(year, month);
//		if (day >= 1 && day <= maxDays)
//			return false;
//	}
//	return true;
//}

vector <Flight*> addEmployeeToFlight(vector<Flight*>flights,vector<Employee*> employees){
	vector <Flight*> FlightsConv;
	vector<Employee*> aux;
	for (size_t i = 0; i < flights.size(); i++) {
		for (size_t j = 0; j < employees.size(); j++) {
			for (size_t k = 0; k < employees.at(j)->getFlights().size(); k++) {
				if (flights.at(i)->getId() == employees.at(j)->getFlights().at(k)->getId()) {
					aux.push_back(employees.at(j));
					break;
				}
			}
		}
		flights.at(i)->setCrew(aux);
		FlightsConv.push_back(flights.at(i));
		aux.clear();
	}
	return FlightsConv;
}

bool notInFlight(Employee *employee, Flight* flight) {
	for (size_t i = 0; i < flight->getEmployees().size(); i++) {
		if (flight->getEmployees().at(i) == employee)
			return false;
	}
	return true;
}


bool noAccent(string name) {
	for (size_t i = 0; i < name.size(); i++)
		if (int(name.at(i)) < -1 || int(name.at(i)) > 255)
			return false;
	return true;
}


bool alreadyExists(string city) {
	for (size_t i = 0; i < comp->getAirports().size();i++)
		if (comp->getAirports().at(i)->getLocal().getCity() == city)
			return true;
	return false;
}