#include "Company.h"
#include "ReadFiles.h"
#include <set>

using namespace std;


Company::Company()
{
	airports = {};
}

Company::Company(string airports_file, string maintenance_file)
{
	
	Airport *airport;
	int counter = 0;
	vector<string> aux;
	string linha, planestxt, employeetxt, flightstxt, old_employees = "OldEmployees.txt";
	string country, city;
	float longit, latit;
	vector<Plane*> planes;
	vector<Flight*> flights;
	vector<Flight*> auxFlight;
	vector<Employee*> employees;
	Manager manager;

	string name;
	int hours;
	int nMaints;
	
	ifstream maintenance_data;
	maintenance_data.open(maintenance_file);

	if (maintenance_data.is_open())
	{
		while (getline(maintenance_data, linha))
		{
			switch (counter)
			{
			case 0:
				name = linha;
				break;
			case 1:
				hours = stoi(linha);
				break;
			case 2:
				nMaints = stoi(linha);
				counter = -1;
				Maintenance m(hours, nMaints, name);
				this->maintenanceCompanies.push(m);
				getline(maintenance_data, linha);
				break;
			}
			counter++;
		}
	}
	else
		cout << "Error opening maintenace file.\n";
	maintenance_data.close();

	ifstream airport_data;
	airport_data.open(airports_file);
	counter = 0;
	if (airport_data.is_open())
	{
		while (getline(airport_data, linha))
		{
			switch (counter)
			{
			case 0:
				country = linha;
				break;
			case 1:
				city = linha;
				break;
			case 2:
				latit = stof(linha);
				break;
			case 3:
				longit = stof(linha);
				break;
			case 4:
				flights = readFlights(linha);
				flightstxt = linha;
				break;
			case 5:
				planes = readPlanes(linha,flights);
				planestxt = linha;
				break;
			case 6:
				employees = readEmployees(linha, this->employees, flights, planes, city);
				employeetxt = linha;
				readOldEmployees(old_employees, this->employees, city);
				break;
			case 7:
				manager.name = linha;
				break;
			case 8:
				manager.birthDate = new Date(linha);
				break;
			case 9:

				manager.salary = stod(linha);
				Local local(country, city, longit, latit);
				auxFlight = addEmployeeToFlight(flights, employees);
				airport = new Airport(planes, auxFlight, local, planestxt, employeetxt, flightstxt);
				airport->setManager(manager);
				airports.insert(airport);
				counter = -1;
				getline(airport_data, linha);
				break;
			}
			counter++;
		}
	}
	else
		cout << "Error opening airport file.\n";
	airport_data.close();
}

void Company::addAirport(Airport * newAirport)
{
	airports.insert(newAirport);
}

AIRPORT_SET Company::getAirports() const
{
	return airports;
}

bool AirportPtrCmp::operator()(const Airport* lhs, const Airport* rhs) const 
{ 
	return lhs->operator<(*rhs); 
}

tabHEmployees Company::getEmployees() const
{
	return employees;
}

void Company::deleteAirport(int index) {
	for (auto i : this->airports)
	{
		if (index == 0)
		{
			this->airports.erase(i);
			return;
		}
		index--;
	}
}

void Company::addMaintenanceCompany(Maintenance maintenaceCompany) {
	this->maintenanceCompanies.push(maintenaceCompany);
}

priority_queue<Maintenance> Company::getMaintenaceCompanies() {
	return this->maintenanceCompanies;
}

void Company::clearMaintenance() {
	while (!this->maintenanceCompanies.empty()) {
		this->maintenanceCompanies.pop();
	}
}

void Company::sortAirports()
{
	AIRPORT_SET aux;
	for (auto i : this->airports) {
		aux.insert(i);
	}
	for (auto i : aux)
	{
		i->numStops = 0;
		for (auto j : aux)
		{
			if (i->getLocal().getCity() != j->getLocal().getCity())
			{
				for (auto k : j->flights)
				{
					
					if (k->getDestination() == i->getLocal().getCity()) 
						i->numStops++;
						
				}
			}
		}
	}
	this->airports = aux;
}

int employeeHash::operator()(const Employee * emp) const
{
	int v = 0;
	for(char j : emp->getName())
	{
		v += j;
	}
	v += emp->getDate().getYear() + emp->getDate().getMonth() + emp->getDate().getDay();
	return v;
}

bool employeeHash::operator()(const Employee * emp1, const Employee * emp2) const
{
	return emp1->getName() == emp2->getName() && emp1->getDate() == emp2->getDate();
}
