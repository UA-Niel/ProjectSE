/**
 * \file
 * This file contains the declaration for some airport functions
 */

#ifndef AIRPORTFUNCTIONS_H
#define AIRPORTFUNCTIONS_H

#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"

/**
 * \brief lets all airplanes of the airport land
 * @param p Pointer to airport
 * @param exporter Pointer to exporter
 */
void makeAllLand(Airport* p, AirportExporter* exporter);

/**
 * \brief Lets all airplanes on the airport take off
 * @param p Pointer to airport
 * @param exporter Poitner to exporter
 */
void makeAllTakeoff(Airport* p, AirportExporter* exporter);

//Function to do gate functions,
//Refilling fuel, letting passengers exit,
//make ready to depart,...
//Return true on success (techincal control okay, fuel okay,...)
/**
 * \brief Function to do gate functions
 *
 * Refilling fuel, letting passengers exit, make ready for departure
 * Returns true on success (technical control okay, fuel okay...)
 *
 * @param gate Current gate
 * @param plane Current airplane at gate
 * @param p Pointer to airport
 * @param exporter Pointer to exporter
 * @return True if success
 */
bool doGateActions(Gate* gate, Airplane* plane, Airport* p, AirportExporter* exporter);

#endif //AIRPORTFUNCTIONS_H
