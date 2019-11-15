#include "Save.h"


extern Company *comp;


void saveAirports() {
	ofstream newAirportsFile;
	string s = "Airports.txt";
	newAirportsFile.open("newAirports.txt");
	if (comp->getAirports().size() != 0) {
	for (size_t i = 0; i < comp->getAirports().size() - 1; i++) {
		newAirportsFile << comp->getAirports().at(i)->getLocal().getCountry() << endl;
		newAirportsFile << comp->getAirports().at(i)->getLocal().getCity() << endl;
		newAirportsFile << comp->getAirports().at(i)->getLocal().getLatit() << endl;
		newAirportsFile << comp->getAirports().at(i)->getLocal().getLon() << endl;
		newAirportsFile << comp->getAirports().at(i)->flightTxt << endl;
		newAirportsFile << comp->getAirports().at(i)->planesTxt << endl;
		newAirportsFile << comp->getAirports().at(i)->employeeTxt << endl;
		newAirportsFile << comp->getAirports().at(i)->manager.name << endl;
		newAirportsFile << comp->getAirports().at(i)->manager.birthDate.getDate() << endl;
		newAirportsFile << comp->getAirports().at(i)->manager.salary << endl;
		newAirportsFile << "::::::::::\n";
	}
		size_t size = comp->getAirports().size()- 1;
		newAirportsFile << comp->getAirports().at(size)->getLocal().getCountry() << endl;
		newAirportsFile << comp->getAirports().at(size)->getLocal().getCity() << endl;
		newAirportsFile << comp->getAirports().at(size)->getLocal().getLatit() << endl;
		newAirportsFile << comp->getAirports().at(size)->getLocal().getLon() << endl;
		newAirportsFile << comp->getAirports().at(size)->flightTxt << endl;
		newAirportsFile << comp->getAirports().at(size)->planesTxt << endl;
		newAirportsFile << comp->getAirports().at(size)->employeeTxt << endl;
		newAirportsFile << comp->getAirports().at(size)->manager.name << endl;
		newAirportsFile << comp->getAirports().at(size)->manager.birthDate.getDate() << endl;
		newAirportsFile << comp->getAirports().at(size)->manager.salary << endl;
	}
	const char* fileName = s.c_str();
	newAirportsFile.close();
	//remove(fileName);
	//rename("newAirports.txt", fileName);

}

void SaveFlights() {
	ofstream newFlightsFile;
	if (comp->getAirports().size() == 0)
		return;
	for (size_t i = 0; i < comp->getAirports().size(); i++) {
		newFlightsFile.open("newFlights.txt");
		if (comp->getAirports().at(i)->flights.size() != 0){
		for (size_t j = 0; j < comp->getAirports().at(i)->flights.size()-1; j++) {
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getId() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getPredictedSchedule().getDepartureDate() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getPredictedSchedule().getArrivalDate() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getPredictedSchedule().getStartHour().getHours() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getPredictedSchedule().getStartHour().getMinutes() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getPredictedSchedule().getEndHour().getHours() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getPredictedSchedule().getEndHour().getMinutes() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(j)->getDestination() << endl;
			newFlightsFile << ":::::::::::\n";
		}
			size_t size = comp->getAirports().at(i)->flights.size() - 1;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getId() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getPredictedSchedule().getDepartureDate() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getPredictedSchedule().getArrivalDate() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getPredictedSchedule().getStartHour().getHours() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getPredictedSchedule().getStartHour().getMinutes() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getPredictedSchedule().getEndHour().getHours() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getPredictedSchedule().getEndHour().getMinutes() << endl;
			newFlightsFile << comp->getAirports().at(i)->flights.at(size)->getDestination() << endl;
		}
		const char* fileName = comp->getAirports().at(i)->flightTxt.c_str();
		newFlightsFile.close();
		//remove(fileName);
		//rename("newFlights.txt", fileName);
	}
}

void SaveEmployees() {
	ofstream newEmployeesFile;
	if (comp->getAirports().size() == 0)
		return;
	for (size_t i = 0; i < comp->getAirports().size(); i++) {
		newEmployeesFile.open("newEmployees.txt");
		if(comp->getAirports().at(i)->employees.size() != 0) {
		for (size_t j = 0; j < comp->getAirports().at(i)->employees.size() - 1; j++) {
			if (comp->getAirports().at(i)->employees.at(j)->getType() == "Pilot") {
				string flights = "";
				size_t size = comp->getAirports().at(i)->employees.at(j)->getFlights().size();
				if (size > 0)
				{
					for (size_t k = 0; k < size; k++)
					{
						if (k < (size - 1))
							flights += to_string(comp->getAirports().at(i)->employees.at(j)->getFlights().at(k)->getId()) + ", ";
						else
							flights += to_string(comp->getAirports().at(i)->employees.at(j)->getFlights().at(k)->getId());
					}
				}
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getCategory() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getPlaneTypes() << endl;
				newEmployeesFile << flights << endl;
				newEmployeesFile << "::::::::::\n";
			}
			else if (comp->getAirports().at(i)->employees.at(j)->getType() == "Flight Crew") {
				string flights = "";
				size_t size = comp->getAirports().at(i)->employees.at(j)->getFlights().size();
				if (size > 0)
				{
					for (size_t k = 0; k < size; k++)
					{
						if (k < (size - 1))
							flights += to_string(comp->getAirports().at(i)->employees.at(j)->getFlights().at(k)->getId()) + ", ";
						else
							flights += to_string(comp->getAirports().at(i)->employees.at(j)->getFlights().at(k)->getId());
					}
				}
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getCategory() << endl;
				newEmployeesFile << flights<< endl;
				newEmployeesFile << "::::::::::\n";
			}
			else if (comp->getAirports().at(i)->employees.at(j)->getType() == "Admin") {
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getDepartment() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getFunction() << endl;
				newEmployeesFile << "::::::::::\n";
			}
			else if (comp->getAirports().at(i)->employees.at(j)->getType() == "Base Crew") {
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getCategory() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getSchedule()->getStartHour().getHours() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getSchedule()->getStartHour().getMinutes() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getSchedule()->getEndHour().getHours() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(j)->getSchedule()->getEndHour().getMinutes() << endl;
				newEmployeesFile << "::::::::::\n";
			}
		}
			size_t EmpSize = comp->getAirports().at(i)->employees.size() - 1;
			if (comp->getAirports().at(i)->employees.at(EmpSize)->getType() == "Pilot") {
				string flights = "";
				size_t size = comp->getAirports().at(i)->employees.at(EmpSize)->getFlights().size();
				if (size > 0)
				{
					for (size_t i = 0; i < size; i++)
					{
						if (i < (size - 1))
							flights += to_string(comp->getAirports().at(i)->employees.at(EmpSize)->getFlights().at(i)->getId()) + ", ";
						else
							flights += to_string(comp->getAirports().at(i)->employees.at(EmpSize)->getFlights().at(i)->getId());
					}
				}
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getCategory() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getPlaneTypes() << endl;
				newEmployeesFile << flights << endl;
			}
			else if (comp->getAirports().at(i)->employees.at(EmpSize)->getType() == "Flight Crew") {
				string flights = "";
				size_t size = comp->getAirports().at(i)->employees.at(EmpSize)->getFlights().size();
				if (size > 0)
				{
					for (size_t i = 0; i < size; i++)
					{
						if (i < (size - 1))
							flights += to_string(comp->getAirports().at(i)->employees.at(EmpSize)->getFlights().at(i)->getId()) + ", ";
						else
							flights += to_string(comp->getAirports().at(i)->employees.at(EmpSize)->getFlights().at(i)->getId());
					}
				}
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getCategory() << endl;
				newEmployeesFile << flights << endl;
			}
			else if (comp->getAirports().at(i)->employees.at(EmpSize)->getType() == "Admin") {
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getDepartment() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getFunction() << endl;
			}
			else if (comp->getAirports().at(i)->employees.at(EmpSize)->getType() == "Base Crew") {
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getType() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getName() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getDate() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getCategory() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getSchedule()->getStartHour().getHours() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getSchedule()->getStartHour().getMinutes() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getSchedule()->getEndHour().getHours() << endl;
				newEmployeesFile << comp->getAirports().at(i)->employees.at(EmpSize)->getSchedule()->getEndHour().getMinutes() << endl;
			}
		}
		const char* fileName = comp->getAirports().at(i)->employeeTxt.c_str();
		newEmployeesFile.close();
		//remove(fileName);
		//rename("newEmployees.txt", fileName);
	}
}

void SavePlanes() {
	ofstream newPlanesFile;
	for (size_t i = 0; i < comp->getAirports().size(); i++) {
		newPlanesFile.open("newPlanes.txt");
		if (comp->getAirports().at(i)->planes.size() != 0) {
			for (size_t j = 0; j < comp->getAirports().at(i)->planes.size() - 1; j++) {
				string flights = "";
				size_t size = comp->getAirports().at(i)->planes.at(j)->getFlights().size();
				if (size > 0)
				{
					for (size_t k = 0; k < size; k++)
					{
						if (k < (size - 1))
							flights += to_string(comp->getAirports().at(i)->planes.at(j)->getFlights().at(k)->getId()) + ", ";
						else
							flights += to_string(comp->getAirports().at(i)->planes.at(j)->getFlights().at(k)->getId());
					}
				}
				newPlanesFile << comp->getAirports().at(i)->planes.at(j)->getType() << endl;
				newPlanesFile << comp->getAirports().at(i)->planes.at(j)->getCapacity() << endl;
				newPlanesFile << flights << endl;
				newPlanesFile << ":::::::::::\n";
			}
			size_t PlaneSize = comp->getAirports().at(i)->planes.size() - 1;
			string flights = "";
			size_t size = comp->getAirports().at(i)->planes.at(PlaneSize)->getFlights().size();
			if (size > 0)
			{
				for (size_t i = 0; i < size; i++)
				{
					if (i < (size - 1))
						flights += to_string(comp->getAirports().at(i)->planes.at(PlaneSize)->getFlights().at(i)->getId()) + ", ";
					else
						flights += to_string(comp->getAirports().at(i)->planes.at(PlaneSize)->getFlights().at(i)->getId());
				}
			}
			newPlanesFile << comp->getAirports().at(i)->planes.at(PlaneSize)->getType() << endl;
			newPlanesFile << comp->getAirports().at(i)->planes.at(PlaneSize)->getCapacity() << endl;
			newPlanesFile << flights << endl;
		}
		const char* fileName = comp->getAirports().at(i)->planesTxt.c_str();
		newPlanesFile.close();
		//remove(fileName);
		//rename("newPlanes.txt", fileName);
	}
}