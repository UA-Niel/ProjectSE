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
    Airport* nationalAirport = loadAirportFromFile(str);
    ofstream outputFile("testOutput/outputTemplate4.txt");

    Airport airport;

    airport.setName("myAirport");
    airport.setId(12);
    airport.setIATA("MAP");
    airport.setCallsign("this is my Airport");

    AirportExporter toTxt(&airport, outputFile);
    AirportExporter toCout(nationalAirport, cout);

    toTxt.startOutput();
    toCout.startOutput();


    toTxt.outputAirportDetails();



    /*ofstream file("testOutput/BasicOutputTestsTemplate3.txt");
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

    file.close();*/

    toCout.stopOutput();
    toTxt.stopOutput();
    outputFile.close();
    return 0;
}
