#include "Company.h"
#include "ReadFiles.h"

using namespace std;


Company::Company()
{
	airports = {};
}

Company::Company(string airports_file)
{
	Airport *airport;
	int counter = 0;
	vector<string> aux;
	string linha, planestxt, employeetxt, flightstxt;
	string country, city;
	float longit, latit;
	vector<Plane*> planes;
	vector<Flight*> flights;
	vector<Flight*> auxFlight;
	vector<Employee*> employees;
	Manager manager;

	ifstream airport_data;
	airport_data.open(airports_file);

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
				employees = readEmployees(linha,flights,planes);
				employeetxt = linha;
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
				airport = new Airport(planes, auxFlight, employees, local, planestxt, employeetxt, flightstxt);
				airport->setManager(manager);
				airports.push_back(airport);
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
	airports.push_back(newAirport);
}

vector<Airport*> Company::getAirports() const
{
	return airports;
}

void Company::deleteAirport(int index) {
	airports.erase(airports.begin()+index);
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