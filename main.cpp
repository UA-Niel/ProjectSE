/**
 * \file
 * This is the main file of the project
 */

#include <iostream>
#include <string>

#include "classes/Airplane.h"
#include "classes/Airport.h"
#include "classes/Runway.h"

#include "parsers/Reader.h"

using namespace std;

int main(int argc, char* argv[]) {
    Airport* p = loadAirportFromFile("inputs/airport1.xml");
    cout << p->getId() << endl;

    return 0;
}
