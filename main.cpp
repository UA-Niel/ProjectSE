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
#include "classes/AirportExporter.h"

using namespace std;

int main(int argc, char* argv[]) {
    const char* str = "inputs/airport1.xml";
    Airport* p = loadAirportFromFile(str);
    cout << "Hello world!" << endl;
    cout << p->getName() << endl;

//    Airport* ap = new Airport();
//    Airplane* airp = new Airplane(3, "Mooi vliegtuigje", "Heel mooi", 7);
//    airp->setNumber("Airbus27");
//    ap->setName("Freeks vliegparadijs");
//    ap->setCallsign("LOLOLOLO");
//    ap->setIATA("FVP");
//    ap->setId(7);
//    ap->addAirplane(airp);
//
//    AirportExporter airportExporter(ap);
//    airportExporter.startOutput();
//    airportExporter.outputBasicInfo(cout);


    return 0;
}
