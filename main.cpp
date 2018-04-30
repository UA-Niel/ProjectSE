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
    /*if (argc <= 1) {
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

    Simulator sim(exporter, *p, time, atc);

    for(int i = 0; i<70; i++) {
        sim.doSimulation(commOut);
    }
    exporter.stopOutput();
    outputFile.close();
    commOut.close();


    for(unsigned int i = 0; i<p->getAirplanes().size(); i++) delete p->getAirplanes()[i];
    for(unsigned int i = 0; i<p->getAllGates().size(); i++) delete p->getAllGates()[i];
    for(unsigned int i = 0; i<p->getNrOfRunways(); i++) delete p->getRunways()[i];
    delete p;*/


    ofstream myFile("SimulatorDepartingTemplate2.txt");
    ofstream commFile("");
    Airplane plane;
    plane.setHeight(5000);
    plane.setCallsign("plane");
    plane.setStatus(Airplane::DEPARTING);
    Airport ap;
    Runway r;
    r.setName("runway");
    r.addAirplane(&plane);
    ap.addRunway(&r);
    ap.setName("airport");
    ApTime time(12,00);
    ATC atc("atc");

    AirportExporter exporter(myFile);
    exporter.startOutput();

    Simulator sim(exporter, &ap, &time, &atc);
    sim.doSimulationDeparting(&plane, commFile);

    myFile.close();
    commFile.close();

    cout << "DONE!";
    return 0;
}
