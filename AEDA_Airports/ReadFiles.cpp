#include "ReadFiles.h"


using namespace std;

Company readAirports(string airports_file)
{
	Airport *airport;
	Company company;
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
			switch(counter)
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
				planes = readPlanes(linha);
				break;
			case 5:
				flights = readFlights(linha);
				break;
			case 6:
				employees = readEmployees(linha);
				Local local(country, city, longit, latit);
				airport = new Airport(planes, flights, employees, local);
				company->airports.push_back(airport);
				counter = -1;
				break;
			}
			counter++;
		}
	}
	else
		cout << "Error opening airport file.\n";
	airport_data.close();
	return company;
}

vector<Plane*> readPlanes(string planes_file)
{
	
	ifstream planes_data;
	vector<string> aux;
	vector<Plane*> planes;
	string linha;
	string type;
	int capacity; 
	Plane *plane;
	vector<Flight*> flights;
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
				flights = readFlights(linha);
				plane = new Plane(type, capacity, flights);
				planes.push_back(plane);
				counter = -1;
				break;
			}
			counter++;
		}
	}
	else
		cout << "Error opening plane file.\n";
	planes_data.close();
	return planes;
}

/*
vector<TravelPack> readPacks(string travelPacks_file)
{
	vector<TravelPack> resultado;
	ifstream travelPacks_data;
	travelPacks_data.open(travelPacks_file);
	TravelPack pack;
	vector<string> aux, auxDates, auxArrival;
	string linha;
	int counter = 0;
	if (travelPacks_data.is_open())
	{
		getline(travelPacks_data, linha);
		while (getline(travelPacks_data, linha))
		{
			switch (counter)
			{
			case 0:
				pack.setId(linha);
				break;
			case 1:
				pack.setDestination(linha);
				break;
			case 2:
				pack.setDepartureDate(linha);
				break;
			case 3:
				pack.setArrivalDate(linha);
				break;
			case 4:
				pack.setCost(linha);
				break;
			case 5:
				pack.setMaxSeats(linha);
				break;
			case 6:
				pack.setSoldSeats(linha);
				break;
			case 7:
				resultado.push_back(pack);
				counter = -1;
				break;
			}
			counter++;
			aux.clear();
			auxDates.clear();
			auxArrival.clear();
		}
	}
	else
	{
		cout << "There was an error finding the file for the travel packs data base.\n";
	}
	if (counter == 7)
		resultado.push_back(pack);
	travelPacks_data.close();
	return resultado;
}
*/