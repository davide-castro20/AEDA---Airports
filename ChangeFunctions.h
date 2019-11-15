#pragma once

#include "Utils.h"

/**
@brief Updates data of a person
*/

void changePersonData();

/**
@brief Updates data of a plane
*/
void changePlaneData();

/**
@brief Updates data of a flight
*/
void changeFlightData();


/**
@brief Add something a to a flight menu
*/
void addToFlight();

/**
@brief Updates data of a flight by adding a pilot to it
*/
void addPilot(Flight *flight);


/**
@brief Updates data of a flight by adding a flight crew to it
*/
void addFlightCrew(Flight * flight);

/**
@brief Updates data of a flight by adding a plane to it
*/
void addPlane(Flight * flight);
//ADD TO UML
void changeManagerSalary();