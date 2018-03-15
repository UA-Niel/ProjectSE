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

#include "classes/Log.hpp"
#define OUTPUT Log()

using namespace std;

int main(int argc, char* argv[]) {
    const char* str = "inputs/airport1.xml";
    Airport* p = loadAirportFromFile(str);
 
    //Start simulation
    //1) Let airplane land
    bool airplaneAboveThousandFeet = false;

    //Airplane approaches at 10,000ft
    //Set starting height all planes
    for (int i = 0; i < p->getAllAirplanes().size(); i++) {
        p->getAllAirplanes()[i]->setHeight(10000);
    }
    
    do {
        //Let all airplanes descend one by one
        for (int i = 0; i < p->getAllAirplanes().size(); i++) {
            Airplane* plane = p->getAllAirplanes()[i];
            

            //Get this plane's status
            Airplane::Status status = plane->getStatus();
            if (status == Airplane::Status::UNKNOWN || 
            status == Airplane::Status::APPROACHING ||
            status == Airplane::Status::LANDING ) {
                //Let approach more
                plane->approach(p);
            }
            
        }

        airplaneAboveThousandFeet = false;
        //Check if there still is an airplane above thousand feet
        for (int i = 0; i < p->getAllAirplanes().size(); i++) {
            Airplane* plane = p->getAllAirplanes()[i];
            
            if (plane->getHeight() > 1000) airplaneAboveThousandFeet = true;
        }
    } while (airplaneAboveThousandFeet);


    toCout.stopOutput();
    toTxt.stopOutput();
    outputFile.close();
    /*ofstream file("testOutput/BasicOutputTestsTemplate3.txt");
    vector<Runway*>runways;
    vector<Gate*>gates;
    Airport ap(runways, gates, 0, "myAirport", "MAP", "this is my Airport");
    Airplane plane(1,"my callsign", "my model", 0, "my number");
//    plane.setNumber("abc123");
    ap.addAirplane(&plane);
    AirportExporter airportExporter(&ap, file);
    airportExporter.startOutput();
    airportExporter.outputPlaneDetails();
    file.close();

    file.close();*/
    return 0;
}
