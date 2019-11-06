#include "ReadFiles.h"
#include "Company.h"

using namespace std;

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