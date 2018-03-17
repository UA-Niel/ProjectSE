//Implementation file for AirportFunctions

#include "AirportFunctions.h"
#include "../utils.h"

void makeAllLand(Airport* p, AirportExporter* exporter) {
    Runway* freeRunway = NULL;
    //Start simulation
    //1) Let airplane land
    bool airplaneAboveThousandFeet = false;

    //Airplane approaches at 10,000ft
    //Set starting height all planes
    for (unsigned int i = 0; i < p->getAirplanes().size(); i++) {
        p->getAirplanes()[i]->setHeight(10000);
    }
    
    do {
        bool airplaneIsInLandingProcedure = true;

        //Let all airplanes descend one by one
        for (unsigned int i = 0; i < p->getAirplanes().size(); i++) {
            Airplane* plane = p->getAirplanes()[i];
            

            //Get this plane's status
            Airplane::Status status = plane->getStatus();
            if (status == Airplane::UNKNOWN ||
            status == Airplane::APPROACHING ||
            status == Airplane::LANDING ) {
                //Let approach more
                plane->approach(p, exporter);
            } else airplaneIsInLandingProcedure = false;
            
        }

        //If this plane in this iteration doesn't need
        //the landing procedure -> continue to next plane
        if (!airplaneIsInLandingProcedure) continue;

        airplaneAboveThousandFeet = false;
        //Check if there still is an airplane above thousand feet
        for (unsigned int i = 0; i < p->getAirplanes().size(); i++) {
            Airplane* plane = p->getAirplanes()[i];
            
            if (plane->getHeight() > 1000) {
                airplaneAboveThousandFeet = true;
            } else {
                //Plane is below 1000ft,

                //Get free runway
                freeRunway = plane->checkFreeRunway(p);
                
                //Only start procedure when free runway available
                if (freeRunway != NULL) {
                    //Landing procedure started
                    plane->setStatus(Airplane::LANDING);

                    //Output
                    string message = plane->getCallsign() + " is landing at " + p->getName() + " on runway " +
                            freeRunway->getName();
                    exporter->outputString(message);

                    if (plane->land(freeRunway)) {
                        message =  plane->getCallsign() + " has landed at " + p->getName() + " on runway "
                                   + freeRunway->getName();
                        exporter->outputString(message);
                        
                        //Get free gate
                        Gate* gate = plane->checkFreeGate(p);

                        //Only taxi to gate, if there is free gate
                        if (gate != NULL) {
                            //Plane landed, let it taxi
                            if (plane->taxi(gate)) {
                                //Plane taxied, so runway is back free
                                freeRunway->clearRunway();

                                message = plane->getCallsign() + " is taxing to gate " + ToString(gate->getId());
                                exporter->outputString(message);
                            
                                //Check if plane is standing correctly
                                if (plane->getStatus() == Airplane::STANDING) {

                                    message = plane->getCallsign() + " is standing at gate " + ToString(gate->getId());
                                    exporter->outputString(message);

                                    //Plane just landed, do gate actions
                                    doGateActions(gate, plane, p, exporter);
                                }
                            }
                        }
                    }
                } else {
                    //No free runway, go up 500ft.
                    plane->setHeight(plane->getHeight() + 500);
                }
            }
            
        }
    } while (airplaneAboveThousandFeet);
}

//Make all airplanes takeoff
void makeAllTakeoff () {
    
}

//do technical control of plane
bool technicalControl(Airplane* plane) {
    return true;
}

bool doGateActions(Gate* gate, Airplane* plane, Airport* p, AirportExporter* exporter) {
    Airplane::Status status = plane->getStatus();

    if (status == Airplane::STANDING) {
        //Let passengers exit
        int amountOfPassengers = plane->getAmountOfPassengers();
        plane->setAmountOfPassengers(0);

        string message = ToString(amountOfPassengers) + " exited " + plane->getCallsign() + " at gate "
                                            + ToString(gate->getId()) + " of " + p->getCallsign();
        exporter->outputString(message);

        //Do technical control
        if (!technicalControl(plane)) {
            //Handle plane error stuff
        }

        message = plane->getCallsign() + " has been checked for techical malfunctions";
        exporter->outputString(message);

    }
    if (status == Airplane::DEPARTING) {
        //Refil fuel
        plane->setFuelState(Airplane::FULL);
        string message = plane->getCallsign() + " has been refueled";
        exporter->outputString(message);

        //Let passengers board
        int amountToBoard = 5;
        plane->setAmountOfPassengers(amountToBoard);

        message = ToString(amountToBoard) + " passengers boarded " + plane->getCallsign()
                + " at gate " + ToString(gate->getId()) + " of " + p->getName();
        exporter->outputString(message);
    }
    return true;
} 

