#include "ReadFiles.h"
#include "Company.h"
#include "Utils.h"

using namespace std;

class Flight;

vector<Flight*> readFlights(string flights_file)
{
	ifstream flights_data;
	flights_data.open(flights_file);
	string linha;
	string date, date2;
	Flight *flight;
	Date *DepartureDate;
	Date *ArrivalDate;
	Time *DepartureTime;
	Time *ArrivalTime;
	FlightSched *flightSched;
	string destino;
	vector <Flight*> flights;
	int id;
	vector <Employee*> employees = {};
	unsigned int DepartureHour, DepartureMinute, ArrivalHour, ArrivalMinute;
	int counter = 0;

	if (flights_data.is_open())
	{
		while (getline(flights_data, linha))
		{
			switch (counter)
			{
			case 0:
				id = stoi(linha);
				break;
			case 1:
				date = linha;
				break;
			case 2:
				date2 = linha;
			case 3:
				DepartureHour = stoi(linha);
				break;
			case 4:
				DepartureMinute = stoi(linha);
				break;
			case 5:
				ArrivalHour = stoi(linha);
				break;
			case 6:
				ArrivalMinute = stoi(linha);
				break;
			case 7:
				destino = linha;
				DepartureDate = new Date(date);
				
				ArrivalDate = new Date(date2);
				DepartureTime = new Time(DepartureHour, DepartureMinute);
				ArrivalTime = new Time(ArrivalHour, ArrivalMinute);
				flightSched = new FlightSched(DepartureDate, DepartureTime, ArrivalDate, ArrivalTime);
				flight = new Flight(flightSched, destino, employees, NULL, id);
				flights.push_back(flight);
				counter = -1;
				getline(flights_data, linha);
				break;
			}
			counter++;
		}
	}
	else
	{
		cout << flights_file << endl;
		cout << "Error opening flight file.\n";
	}
	
	flights_data.close();
	return flights;
}



vector<Plane*> readPlanes(string planes_file, const vector<Flight*> &flights)
{

	ifstream planes_data;
	vector<string> aux;
	vector<Plane*> planes;
	string linha;
	string type;
	int capacity;
	Plane *plane;
	vector<int> flightIds;
	vector<string> flightIdsString;
	vector<Flight*> flightsAux;
	int counter = 0;
	planes_data.open(planes_file);
	if (planes_data.is_open())
	{
		while (getline(planes_data, linha))
		{
			switch (counter)
			{
			case 0:
				type = linha;
				break;
			case 1:
				capacity = stoi(linha);
				break;
			case 2:
				decompose(linha, flightIdsString, ',');
				for (size_t i = 0; i < flightIdsString.size(); i++)
					flightIds.push_back(stoi(flightIdsString.at(i)));
				flightsAux = convertIdToFlight(flightIds, flights);
				plane = new Plane(type, capacity, flightsAux);
				for (size_t i = 0; i < flightsAux.size(); i++)
				{
					flightsAux.at(i)->setPlane(plane);
				}
				planes.push_back(plane);
				counter = -1;
				getline(planes_data, linha);
				break;
			}
			counter++;
			flightIds.clear();
			flightIdsString.clear();
		}
	}
	else
		cout << "Error opening plane file.\n";
	planes_data.close();
	return planes;
}


vector<Employee*> readEmployees(string employees_file, const vector<Flight*> &flights, const vector<Plane*> &planes)
{
	ifstream employees_data;
	vector<string> aux;
	string linha;
	string type;
	string name;
	string date;
	string category;
	string department;
	string function;
	Time *startTime;
	Time *endTime;
	Schedule *schedule;
	Employee *employee;
	vector<Employee*> employees;
	unsigned int startHour, startMinute, endHour, endMinute;
	vector<string> planeTypes;
	vector<Plane*> planesAux;
	vector<int> flightIds;
	vector<string> flightIdsString;
	Date *birthDate;
	vector<Flight*> flightsAux;
	int counter = 0;
	employees_data.open(employees_file);
	if (employees_data.is_open())
	{
		while (getline(employees_data, linha))
		{
			type = linha;
			if (type == "Pilot")
			{
				getline(employees_data, linha);
				name = linha;
				getline(employees_data, linha);
				date = linha;
				getline(employees_data, linha);
				category = linha;
				getline(employees_data, linha);
				decompose(linha, planeTypes, ',');
				planesAux = convertCatToPlane(planeTypes, planes);
				getline(employees_data, linha);
				decompose(linha, flightIdsString, ',');
				for (size_t i = 0; i < flightIdsString.size(); i++)
					flightIds.push_back(stoi(flightIdsString.at(i)));
				flightsAux = convertIdToFlight(flightIds, flights);
				birthDate = new Date(date);
				employee = new Pilot(name, birthDate, category, planesAux, flightsAux);
				employees.push_back(employee);

				getline(employees_data, linha);
				flightIds.clear();
				flightIdsString.clear();
			}
			else if (type == "Flight Crew")
			{
				getline(employees_data, linha);
				name = linha;
				getline(employees_data, linha);
				date = linha;
				getline(employees_data, linha);
				category = linha;
				getline(employees_data, linha);
				decompose(linha, flightIdsString, ',');
				for (size_t i = 0; i < flightIdsString.size(); i++)
					flightIds.push_back(stoi(flightIdsString.at(i)));
				flightsAux = convertIdToFlight(flightIds, flights);

				birthDate = new Date(date);
				employee = new FlightCrew(name, birthDate, category, flightsAux);
				employees.push_back(employee);

				getline(employees_data, linha);
				flightIds.clear();
				flightIdsString.clear();
			}
			else if (type == "Admin")
			{
				getline(employees_data, linha);
				name = linha;
				getline(employees_data, linha);
				date = linha;
				getline(employees_data, linha);
				department = linha;
				getline(employees_data, linha);
				function = linha;

				birthDate = new Date(date);
				employee = new Admin(name, birthDate, department, function);
				employees.push_back(employee);

				getline(employees_data, linha);

			}
			else if (type == "Base Crew")
			{
				getline(employees_data, linha);
				name = linha;
				getline(employees_data, linha);
				date = linha;
				getline(employees_data, linha);
				category = linha;
				getline(employees_data, linha);
				startHour = stoi(linha);
				getline(employees_data, linha);
				startMinute = stoi(linha);
				getline(employees_data, linha);
				endHour = stoi(linha);
				getline(employees_data, linha);
				endMinute = stoi(linha);

				birthDate = new Date(date);
				startTime = new Time(startHour, startMinute);
				endTime = new Time(endHour, endMinute);
				schedule = new Schedule(startTime, endTime);
				employee = new BaseCrew(name, birthDate, category, schedule);
				employees.push_back(employee);

				getline(employees_data, linha);
			}
		}
	}
	else
		cout << "Error opening employees file.\n";
	employees_data.close();
	return employees;
}