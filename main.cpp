/**
 * \file
 * This is the main file of the project
 */

#include <iostream>
#include <fstream>
#include "headers/Airplane.h"
#include "headers/Airport.h"
#include "headers/IO/Reader.h"
#include "headers/Simulator.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cerr << "No argument for input file given";
        return -1;
    }
    const char* str = argv[1]; 
    Airport* p = loadAirportFromFile(str);

    ofstream outputFile("output2.txt");
    ofstream commOut("CommOutput.txt");
    AirportExporter exporter(p, outputFile);
    ApTime time(23, 55);
    ATC atc("Antwerp Tower");

    exporter.startOutput();

    Simulator sim(exporter, p, &time, &atc);

    for(int i = 0; i<70; i++) {
        sim.doSimulation(commOut);
    }
    exporter.stopOutput();
    outputFile.close();
    commOut.close();


    for(unsigned int i = 0; i<p->getAirplanes().size(); i++) delete p->getAirplanes()[i];
    for(unsigned int i = 0; i<p->getAllGates().size(); i++) delete p->getAllGates()[i];
    for(unsigned int i = 0; i<p->getNrOfRunways(); i++) delete p->getRunways()[i];
    delete p;

    cout << "DONE!" << endl;
    return 0;
}
