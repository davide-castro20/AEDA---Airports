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
	string linha;
	string country, city;
	float longit, latit;
	vector<Plane*> planes;
	vector<Flight*> flights;
	vector<Employee*> employees;

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
				longit = stof(linha);
				break;
			case 3:
				latit = stof(linha);
				break;
			case 4:
				flights = readFlights(linha);
				break;
			case 5:
				planes = readPlanes(linha,flights);
				break;
			case 6:
				employees = readEmployees(linha,flights,planes);
				Local local(country, city, longit, latit);
				airport = new Airport(planes, flights, employees, local);
				airports.push_back(airport);
				counter = -1;
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
