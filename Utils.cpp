#include "Utils.h"


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

bool checkBetweenDates(string date1, string date2, Date date)
{
	int date1day, date1month, date1year, date2day, date2month, date2year;
	istringstream iSdate1(date1), iSdate2(date2);
	char s;
	iSdate1 >> date1year >> s >> date1month >> s >> date1day;
	iSdate2 >> date2year >> s >> date2month >> s >> date2day;
	int entryDate = (date.getYear() * 10000) + (date.getMonth() * 100) + date.getDay();
	int startDate = (date1year * 10000) + (date1month * 100) + date1day;
	int endDate = (date2year * 10000) + (date2month * 100) + date2year;

	if (entryDate >= startDate && entryDate <= endDate)
		return true;
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