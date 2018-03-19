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
 *
 * **Preconditions:**
 * - REQUIRE(p != NULL, "Airport cannot be NULL");
 * - REQUIRE(exporter != NULL, "Exporter cannot be NULL");
 * - REQUIRE(p->properlyInitialized(), "Airport p is not initialized correctly");
 * - REQUIRE(exporter->properlyInitalized(), "Exporter is not initialized correctly");
 *
 * **Postcondtions:**
 * - ENSURE(departingPlanes.empty(), "There are still planes departing");
 */
void makeAllTakeoff(Airport* p, AirportExporter* exporter);

/**
 * \brief Clears the runway containing plane
 * @param p Pointer to the airport
 * @param plane Pointer to the plane
 *
 * **Preconditions:**
 * - REQUIRE(p->properlyInitialized(), "Airport p is not initialized correctly");
 * - REQUIRE(plane->properlyInitialized(), "Airplane plane is not initialized correctly");
 */
void clearRunwayWithPlane(Airport* p,  Airplane* plane);

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
