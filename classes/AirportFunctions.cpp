///**
// * \file
// * This file contains declarations for airport functions
// */
//
//#include "AirportFunctions.h"
//#include "../utils.h"
//
//void makeAllLand(Airport* p, AirportExporter* exporter) {
//    Runway* freeRunway = NULL;
//    //Start simulation
//    //1) Let airplane land
//    bool airplaneAboveThousandFeet = false;
//
//    //Airplane approaches at 10,000ft
//    //Set starting height all planes
//    for (unsigned int i = 0; i < p->getAirplanes().size(); i++) {
//        p->getAirplanes()[i]->setHeight(10000);
//    }
//
//    do {
//        bool airplaneIsInLandingProcedure = true;
//
//        //Let all airplanes descend one by one
//        for (unsigned int i = 0; i < p->getAirplanes().size(); i++) {
//            Airplane* plane = p->getAirplanes()[i];
//
//
//            //Get this plane's status
//            Airplane::Status status = plane->getStatus();
//            if (status == Airplane::UNKNOWN ||
//            status == Airplane::APPROACHING ||
//            status == Airplane::LANDING ) {
//                //Let approach more
//                plane->approach(p, exporter);
//            } else airplaneIsInLandingProcedure = false;
//
//        }
//
//        //If this plane in this iteration doesn't need
//        //the landing procedure -> continue to next plane
//        if (!airplaneIsInLandingProcedure) continue;
//
//        airplaneAboveThousandFeet = false;
//        //Check if there still is an airplane above thousand feet
//        for (unsigned int i = 0; i < p->getAirplanes().size(); i++) {
//            Airplane* plane = p->getAirplanes()[i];
//
//            if (plane->getHeight() > 1000) {
//                airplaneAboveThousandFeet = true;
//            } else {
//                //Plane is below 1000ft,
//
//                //Get free runway
//                freeRunway = plane->checkFreeRunway(p);
//
//                //Only start procedure when free runway available
//                if (freeRunway != NULL) {
//                    //Landing procedure started
//                    plane->setStatus(Airplane::LANDING);
//
//                    //Output
//                    string message = plane->getCallsign() + " is landing at " + p->getName() + " on runway " +
//                            freeRunway->getName();
//                    exporter->outputString(message);
//
//                    if (plane->land(freeRunway)) {
//                        message =  plane->getCallsign() + " has landed at " + p->getName() + " on runway "
//                                   + freeRunway->getName();
//                        exporter->outputString(message);
//
//                        //Get free gate
//                        Gate* gate = plane->checkFreeGate(p);
//
//                        //Only taxi to gate, if there is free gate
//                        if (gate != NULL) {
//                            //Plane landed, let it taxi
//                            if (plane->taxi(gate)) {
//                                //Plane taxied, so runway is back free
//                                freeRunway->clearRunway();
//
//                                message = plane->getCallsign() + " is taxing to gate " + ToString(gate->getId());
//                                exporter->outputString(message);
//
//                                //Check if plane is standing correctly
//                                if (plane->getStatus() == Airplane::STANDING) {
//
//                                    message = plane->getCallsign() + " is standing at gate " + ToString(gate->getId());
//                                    exporter->outputString(message);
//
//                                    //Plane just landed, do gate actions
//                                    doGateActions(gate, plane, p, exporter);
//                                }
//                            }
//                        }
//                    }
//                } else {
//                    //No free runway, go up 500ft.
//                    plane->setHeight(plane->getHeight() + 500);
//                }
//            }
//
//        }
//    } while (airplaneAboveThousandFeet);
//}
//
////do technical control of plane
//bool technicalControl(Airplane* plane) {
//    return true;
//}
//
//bool doGateActions(Gate* gate, Airplane* plane, Airport* p, AirportExporter* exporter) {
//    Airplane::Status status = plane->getStatus();
//
//    if (status == Airplane::STANDING) {
//        //Let passengers exit
//        int amountOfPassengers = plane->getAmountOfPassengers();
//        plane->setAmountOfPassengers(0);
//
//        string message = ToString(amountOfPassengers) + " exited " + plane->getCallsign() + " at gate "
//                                            + ToString(gate->getId()) + " of " + p->getCallsign();
//        exporter->outputString(message);
//
//        //Do technical control
//        if (!technicalControl(plane)) {
//            //Handle plane error stuff
//        }
//
//        message = plane->getCallsign() + " has been checked for techical malfunctions";
//        exporter->outputString(message);
//
//    }
//    if (status == Airplane::DEPARTING) {
//        //Refil fuel
//        plane->setFuelState(Airplane::FULL);
//        string message = plane->getCallsign() + " has been refueled";
//        exporter->outputString(message);
//
//        //Let passengers board
//        int amountToBoard = 5;
//        plane->setAmountOfPassengers(amountToBoard);
//
//        message = ToString(amountToBoard) + " passengers boarded " + plane->getCallsign()
//                + " at gate " + ToString(gate->getId()) + " of " + p->getName();
//        exporter->outputString(message);
//    }
//    return true;
//}
//
//void makeAllTakeoff(Airport* p, AirportExporter* exporter){
//    REQUIRE(p != NULL, "Airport cannot be NULL");
//    REQUIRE(exporter != NULL, "Exporter cannot be NULL");
//    REQUIRE(p->properlyInitialized(), "Airport p is not initialized correctly");
//    REQUIRE(exporter->properlyInitalized(), "Exporter is not initialized correctly");
//
//    vector<Airplane*> departingPlanes;
//    for(unsigned int i = 0; i<p->getAirplanes().size(); i++){
//        Airplane* plane = p->getAirplanes()[i];
//        if(plane->getStatus() != Airplane::DEPARTING) continue;
//        if(plane->getFuelState() != Airplane::FULL) continue;
//        departingPlanes.push_back(plane);
//
//    }
//    if(departingPlanes.empty()) return;
//    bool allDeparted = false;
//
//    while(!allDeparted){
//        if(departingPlanes.empty()) allDeparted = true;
//        int size = departingPlanes.size();
//        for(int i = 0; i<size; i++){
//            Airplane* plane = departingPlanes[i];
//            //Runway* freeRunway = plane->checkFreeRunway(p);
//
//
//
//            plane->ascend();
//            string message = plane->getCallsign() + " ascended to " + ToString(plane->getHeight());
//            exporter->outputString(message);
//
//
//
//            if(plane->departed()){
//
//                //clearRunwayWithPlane(p, plane);
//
//                message = plane->getCallsign() + " left " + p->getCallsign();
//                exporter->outputString(message);
//                departingPlanes.erase(departingPlanes.begin() + i);
//                plane->setStatus(Airplane::IN_AIR);
//            }
//        }
//    }
//
//    ENSURE(departingPlanes.empty(), "There are still planes departing");
//}
//
//void clearRunwayWithPlane(Airport* p,  Airplane* plane){
//    REQUIRE(p->properlyInitialized(), "Airport p is not initialized correctly");
//    REQUIRE(plane->properlyInitialized(), "Airplane plane is not initialized correctly");
//    for(unsigned int i = 0; i<p->getRunways().size(); i++){
//        Runway* runway = p->getRunways()[i];
//        if(runway->getAirplanesOnRunway()[0]->getId() == plane->getId()){
//            runway->clearRunway();
//            return;
//        }
//    }
//}