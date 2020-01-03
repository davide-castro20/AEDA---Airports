#include "Save.h"
#include <set>


extern Company *comp;


void saveAirports() {
	ofstream newAirportsFile;
	string s = "Airports.txt";
	newAirportsFile.open("newAirports.txt");
	if (comp->getAirports().size() != 0) 
	for (auto i : comp->getAirports()) {
		newAirportsFile << i->getLocal().getCountry() << endl;
		newAirportsFile << i->getLocal().getCity() << endl;
		newAirportsFile << i->getLocal().getLatit() << endl;
		newAirportsFile << i->getLocal().getLon() << endl;
		newAirportsFile << i->flightTxt << endl;
		newAirportsFile << i->planesTxt << endl;
		newAirportsFile << i->employeeTxt << endl;
		newAirportsFile << i->manager.name << endl;
		newAirportsFile << i->manager.birthDate->getDate() << endl;
		newAirportsFile << i->manager.salary << endl;
		newAirportsFile << "::::::::::\n";
	}
		
	const char* fileName = s.c_str();
	newAirportsFile.close();
	remove(fileName);
	rename("newAirports.txt", fileName);

}

void SaveFlights() {
	ofstream newFlightsFile;
	
	if (comp->getAirports().size() == 0)
		return;
	for (auto i : comp->getAirports()) {
		newFlightsFile.open("newFlights.txt");
		if (i->flights.size() != 0) {
			for (size_t j = 0; j < i->flights.size() - 1; j++) {
				newFlightsFile << i->flights.at(j)->getId() << endl;
				newFlightsFile << i->flights.at(j)->getPredictedSchedule().getDepartureDate() << endl;
				newFlightsFile << i->flights.at(j)->getPredictedSchedule().getArrivalDate() << endl;
				newFlightsFile << i->flights.at(j)->getPredictedSchedule().getStartHour().getHours() << endl;
				newFlightsFile << i->flights.at(j)->getPredictedSchedule().getStartHour().getMinutes() << endl;
				newFlightsFile << i->flights.at(j)->getPredictedSchedule().getEndHour().getHours() << endl;
				newFlightsFile << i->flights.at(j)->getPredictedSchedule().getEndHour().getMinutes() << endl;
				newFlightsFile << i->flights.at(j)->getDestination() << endl;
				newFlightsFile << ":::::::::::\n";
			}
			size_t size = i->flights.size() - 1;
			newFlightsFile << i->flights.at(size)->getId() << endl;
			newFlightsFile << i->flights.at(size)->getPredictedSchedule().getDepartureDate() << endl;
			newFlightsFile << i->flights.at(size)->getPredictedSchedule().getArrivalDate() << endl;
			newFlightsFile << i->flights.at(size)->getPredictedSchedule().getStartHour().getHours() << endl;
			newFlightsFile << i->flights.at(size)->getPredictedSchedule().getStartHour().getMinutes() << endl;
			newFlightsFile << i->flights.at(size)->getPredictedSchedule().getEndHour().getHours() << endl;
			newFlightsFile << i->flights.at(size)->getPredictedSchedule().getEndHour().getMinutes() << endl;
			newFlightsFile << i->flights.at(size)->getDestination() << endl;
		}
		const char* fileName = i->flightTxt.c_str();
		newFlightsFile.close();
		remove(fileName);
		rename("newFlights.txt", fileName);
	}
	
}

void SaveEmployees() {
	ofstream newEmployeesFile;
	if (comp->getEmployees().size() == 0)
		return;
	for (auto i : comp->getAirports()) {

		newEmployeesFile.open("newEmployees.txt");

		for (auto x: comp->getEmployees()) {
			if ((x)->getAirport() == i->getLocal().getCity())
			{
				if ((x)->getType() == "Pilot" && (x)->getEmployed() == true) {
					string flights = "";
					Pilot* pilot = dynamic_cast<Pilot*>(x);
				
					
					if (pilot->getFlights().size()!=0) {
						for (auto f : pilot->getFlights()) {
							flights += to_string(f->getId());
							flights += ",";
						}
						flights.pop_back();
					}

					newEmployeesFile << pilot->getType() << endl;
					newEmployeesFile << pilot->getName() << endl;
					newEmployeesFile << pilot->getDate() << endl;
					newEmployeesFile << pilot->getCategory() << endl;
					newEmployeesFile << pilot->getPlaneTypes() << endl;
					newEmployeesFile << flights << endl;
					newEmployeesFile << "::::::::::\n";
				}
				else if ((x)->getType() == "Flight Crew" && (x)->getEmployed() == true) {
					string flights = "";
					FlightCrew* crew = dynamic_cast<FlightCrew*>(x);
					if (crew->getFlights().size() != 0) {
						for (auto f : crew->getFlights())
							flights += to_string(f->getId()) + ",";
						flights.pop_back();
					}
					newEmployeesFile << crew->getType() << endl;
					newEmployeesFile << crew->getName() << endl;
					newEmployeesFile << crew->getDate() << endl;
					newEmployeesFile << crew->getCategory() << endl;
					newEmployeesFile << flights << endl;
					newEmployeesFile << "::::::::::\n";
				}
				else if ((x)->getType() == "Admin" && (x)->getEmployed() == true) {
					Admin* admin = dynamic_cast<Admin*>(x);
					newEmployeesFile << admin->getType() << endl;
					newEmployeesFile << admin->getName() << endl;
					newEmployeesFile << admin->getDate() << endl;
					newEmployeesFile << admin->getDepartment() << endl;
					newEmployeesFile << admin->getFunction() << endl;
					newEmployeesFile << "::::::::::\n";
				}
				else if ((x)->getType() == "Base Crew" && (x)->getEmployed() == true) {
					BaseCrew* crew = dynamic_cast<BaseCrew*>(x);
					newEmployeesFile << crew->getType() << endl;
					newEmployeesFile << crew->getName() << endl;
					newEmployeesFile << crew->getDate() << endl;
					newEmployeesFile << crew->getCategory() << endl;
					newEmployeesFile << crew->getSchedule()->getStartHour().getHours() << endl;
					newEmployeesFile << crew->getSchedule()->getStartHour().getMinutes() << endl;
					newEmployeesFile << crew->getSchedule()->getEndHour().getHours() << endl;
					newEmployeesFile << crew->getSchedule()->getEndHour().getMinutes() << endl;
					newEmployeesFile << "::::::::::\n";
				}
			}
		}
		const char* fileName = i->employeeTxt.c_str();
		newEmployeesFile.close();
		remove(fileName);
		rename("newEmployees.txt", fileName);
	}
}

void SaveOldEmployees() {
	ofstream newEmployeesFile;
	if (comp->getEmployees().size() == 0)
		return;
	newEmployeesFile.open("newEmployees.txt");
	for (auto x : comp->getEmployees()) {
		
		
		if ((x)->getType() == "Pilot" && (x)->getEmployed() == false) {
			string flights = ""; 
			Pilot* pilot = dynamic_cast<Pilot*>(x);
			newEmployeesFile << pilot->getType() << endl;
			newEmployeesFile << pilot->getName() << endl;
			newEmployeesFile << pilot->getDate() << endl;
			newEmployeesFile << pilot->getCategory() << endl;
			newEmployeesFile << pilot->getPlaneTypes() << endl;
			newEmployeesFile << flights << endl;
			newEmployeesFile << "::::::::::\n";
		}
		else if (x->getType() == "Flight Crew" && (x)->getEmployed() == false) {
			string flights = "";
			FlightCrew* crew = dynamic_cast<FlightCrew*>(x);
			newEmployeesFile << crew->getType() << endl;
			newEmployeesFile << crew->getName() << endl;
			newEmployeesFile << crew->getDate() << endl;
			newEmployeesFile << crew->getCategory() << endl;
			newEmployeesFile << flights << endl;
			newEmployeesFile << "::::::::::\n";
		}
		else if ((x)->getType() == "Admin" && (x)->getEmployed() == false) {
			Admin* admin = dynamic_cast<Admin*>(x);
			newEmployeesFile << admin->getType() << endl;
			newEmployeesFile << admin->getName() << endl;
			newEmployeesFile << admin->getDate() << endl;
			newEmployeesFile << admin->getDepartment() << endl;
			newEmployeesFile << admin->getFunction() << endl;
			newEmployeesFile << "::::::::::\n";
		}
		else if ((x)->getType() == "Base Crew" && (x)->getEmployed() == false) {
			BaseCrew* crew = dynamic_cast<BaseCrew*>(x);
			newEmployeesFile << crew->getType() << endl;
			newEmployeesFile << crew->getName() << endl;
			newEmployeesFile << crew->getDate() << endl;
			newEmployeesFile << crew->getCategory() << endl;
			newEmployeesFile << crew->getSchedule()->getStartHour().getHours() << endl;
			newEmployeesFile << crew->getSchedule()->getStartHour().getMinutes() << endl;
			newEmployeesFile << crew->getSchedule()->getEndHour().getHours() << endl;
			newEmployeesFile << crew->getSchedule()->getEndHour().getMinutes() << endl;
			newEmployeesFile << "::::::::::\n";
		}
	}
		
	string old_employees = "OldEmployees.txt";
	const char* fileName = old_employees.c_str();
	newEmployeesFile.close();
	remove(fileName);
	rename("newEmployees.txt", fileName);
	
}




void SavePlanes() {
	ofstream newPlanesFile;
	for (auto i : comp->getAirports()) {
		newPlanesFile.open("newPlanes.txt");
		if (i->planes.size() != 0) {
			for (size_t j = 0; j < i->planes.size() - 1; j++) {
				string flights = "";
				size_t size = i->planes.at(j)->getFlights().size();
				if (size > 0)
				{
					for (size_t k = 0; k < size; k++)
					{
						if (k < (size - 1))
							flights += to_string(i->planes.at(j)->getFlights().at(k)->getId()) + ", ";
						else
							flights += to_string(i->planes.at(j)->getFlights().at(k)->getId());
					}
				}
				newPlanesFile << i->planes.at(j)->getType() << endl;
				newPlanesFile << i->planes.at(j)->getCapacity() << endl;
				newPlanesFile << flights << endl;
				newPlanesFile << ":::::::::::\n";
			}
			size_t PlaneSize = i->planes.size() - 1;
			string flights = "";
			size_t size = i->planes.at(PlaneSize)->getFlights().size();
			if (size > 0)
			{
				for (size_t j = 0; j < size; j++)
				{
					if (j < (size - 1))
						flights += to_string(i->planes.at(PlaneSize)->getFlights().at(j)->getId()) + ", ";
					else
						flights += to_string(i->planes.at(PlaneSize)->getFlights().at(j)->getId());
				}
			}
			newPlanesFile << i->planes.at(PlaneSize)->getType() << endl;
			newPlanesFile << i->planes.at(PlaneSize)->getCapacity() << endl;
			newPlanesFile << flights << endl;
		}
		const char* fileName = i->planesTxt.c_str();
		newPlanesFile.close();
		remove(fileName);
		rename("newPlanes.txt", fileName);
	}
}

void saveMaintenance() {
	ofstream newMaintenanceFile;
	string s = "Maintenance.txt";
	newMaintenanceFile.open("newMaintenance.txt");
	priority_queue<Maintenance> aux = comp->getMaintenaceCompanies();

	if (!comp->getMaintenaceCompanies().empty())
	{
		newMaintenanceFile << aux.top().getName() << endl;
		newMaintenanceFile << aux.top().getHours() << endl;
		newMaintenanceFile << aux.top().getMaintenances() << endl;
		aux.pop();

		while (!aux.empty())
		{
			newMaintenanceFile << "::::::::::\n";
			newMaintenanceFile << aux.top().getName() << endl;
			newMaintenanceFile << aux.top().getHours() << endl;
			newMaintenanceFile << aux.top().getMaintenances() << endl;
			aux.pop();

		}
	}
	const char* fileName = s.c_str();
	newMaintenanceFile.close();
	remove(fileName);
	rename("newMaintenance.txt", fileName);

}