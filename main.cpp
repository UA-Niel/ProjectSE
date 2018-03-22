/**
 * \file
 * This is the main file of the project
 */

#include <iostream>
#include <fstream>
#include "classes/Airplane.h"
#include "classes/Airport.h"
#include "parsers/Reader.h"
#include "classes/Log.hpp"
#define OUTPUT Log()

using namespace std;

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        OUTPUT << "No argument for input file given";
        return -1;
    }
    const char* str = argv[1]; 
    Airport* p = loadAirportFromFile(str);

    ofstream outputFile("output.txt");
    AirportExporter exporter(p, outputFile);

    exporter.startOutput();

    for(int i = 0; i<70; i++) {
        p->doSimulation(&exporter);
    }

    exporter.stopOutput();
    outputFile.close();


    for(unsigned int i = 0; i<p->getAirplanes().size(); i++) delete p->getAirplanes()[i];
    for(unsigned int i = 0; i<p->getAllGates().size(); i++) delete p->getAllGates()[i];
    for(unsigned int i = 0; i<p->getNrOfRunways(); i++) delete p->getRunways()[i];
    delete p;
    cout << "DONE!";
    return 0;
}
