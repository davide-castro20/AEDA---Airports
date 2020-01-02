#pragma once


/**
@brief Shows the expenses of an airport's employees
*/
void showEmployeeExpenses();
/**
@brief Shows the expenses of an airport's employees and planes between two dates
*/
void datesExpenses();
/**
@brief Shows the expenses of an airport's planes
*/
void showPlanesExpenses();
/**
@brief Shows an airport's data
*/
void showAirportData(Airport * airport);
/**
@brief Menu to select how the employee's data will be shown
*/
void showPersonMenu();
/**
@brief Showas an employees' data
*/
void showPerson(Employee* emp);
/**
@brief Shows the employees data after filtering by name
*/
void showByName();
/**
@brief Menu to select how the flight's data will be shown
*/
void showFlightMenu();
/**
@brief Shows a flight's data
*/
void showFlight(Flight* flight);
/**
@brief Shows flight's that happen between two dates
*/
void showFlightsDates();
/**
@brief Menu to select how the planes' data will eb shown
*/
void showPlaneMenu();
/**
@brief Shows a planes' data
*/
void showPlane(Plane* plane);
/**
@brief Shows planes after filtering by category
*/
void showPlaneByCat();
/**
@brief Shows a person in the company by name chosen by user
*/
void showByNameCompany();
/**
@brief Menu to select people in the company to show
*/
void showPersonMenuCompany();

