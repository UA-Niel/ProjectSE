//Header file for airport functions

#ifndef AIRPORTFUNCTIONS_H
#define AIRPORTFUNCTIONS_H

#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"

#include "Log.hpp"
#define OUTPUT Log()

//Let all airplanes land
void makeAllLand(Airport* p);

//Let all airplanes pullup
void makeAllTakeoff(Airport* p);

#endif //AIRPORTFUNCTIONS_H
