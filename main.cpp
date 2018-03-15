/**
 * \file
 * This is the main file of the project
 */

#include <iostream>
#include <string>
#include <fstream>

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
    std::cout << "Runway Size: " << p->getRunways()->size() << std::endl;


//    Airport* ap = new Airport();
//    Airplane* airp = new Airplane(3, "Mooi vliegtuigje", "Heel mooi", 7);
//    airp->setNumber("Airbus27");
//    ap->setName("Freeks vliegparadijs");
//    ap->setCallsign("LOLOLOLO");
//    ap->setIATA("FVP");
//    ap->setId(7);
//    ap->addAirplane(airp);

    ofstream file("testOutput/BasicOutputTestsTemplate3.txt");
    vector<Runway*>runways;
    vector<Gate*>gates;
    Airport ap(runways, gates, 0, "myAirport", "MAP", "this is my Airport");
    Airplane plane(1,"my callsign", "my model", 0);
    plane.setNumber("abc123");
    Airplane plane2(2,"my callsign2", "my model2", 0);
    plane2.setNumber("abc123 2");
    Airplane plane3(3,"my callsign3", "my model3", 0);
    plane3.setNumber("abc123 3");
    ap.addAirplane(&plane); ap.addAirplane(&plane2); ap.addAirplane(&plane3);
    AirportExporter airportExporter(&ap, file);
    airportExporter.startOutput();
    airportExporter.outputPlaneDetails();
    file.close();


    return 0;
}
