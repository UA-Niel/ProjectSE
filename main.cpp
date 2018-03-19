/**
 * \file
 * This is the main file of the project
 */

#include <iostream>
#include <fstream>
#include "classes/Airplane.h"
#include "classes/Airport.h"
#include "parsers/Reader.h"
#include "classes/AirportFunctions.h"

using namespace std;

int main(int argc, char* argv[]) {
    const char* str = "inputs/airport1.xml";
    Airport* p = loadAirportFromFile(str);

    ofstream outputFile("output.txt");
    AirportExporter exporter(p, outputFile);

    p->getAirplanes()[0]->setStatus(Airplane::DEPARTING);

    exporter.startOutput();
    //Let all airplanes land
    makeAllTakeoff(p, &exporter);

    exporter.stopOutput();
    outputFile.close();

    delete p;
    cout << "DONE!";
    return 0;
}
