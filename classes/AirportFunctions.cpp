//Implementation file for AirportFunctions

#include "AirportFunctions.h"

void makeAllLand(Airport* p) {
    Runway* freeRunway = nullptr;
 
    //Start simulation
    //1) Let airplane land
    bool airplaneAboveThousandFeet = false;

    //Airplane approaches at 10,000ft
    //Set starting height all planes
    for (int i = 0; i < p->getAllAirplanes().size(); i++) {
        p->getAllAirplanes()[i]->setHeight(10000);
    }
    
    do {
        bool airplaneIsInLandingProcedure = true;

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
            } else airplaneIsInLandingProcedure = false;
            
        }

        //If this plane in this iteration doesn't need
        //the landing procedure -> continue to next plane
        if (!airplaneIsInLandingProcedure) continue;

        airplaneAboveThousandFeet = false;
        //Check if there still is an airplane above thousand feet
        for (int i = 0; i < p->getAllAirplanes().size(); i++) {
            Airplane* plane = p->getAllAirplanes()[i];
            
            if (plane->getHeight() > 1000) {
                airplaneAboveThousandFeet = true;
            } else {
                //Plane is below 1000ft,

                //Get free runway
                freeRunway = plane->checkFreeRunway(p);
                
                //Only start procedure when free runway available
                if (freeRunway != NULL) {
                    //Landing procedure started
                    plane->setStatus(Airplane::Status::LANDING);
                    
                    OUTPUT << plane->getCallsign() << " is landing at " << p->getName() << " on runway " << freeRunway->getName(); 
                    if (plane->land(freeRunway)) {
                        OUTPUT << plane->getCallsign() << " has landed at " << p->getName() << " on runway " << freeRunway->getName(); 
                        
                        //Get free gate
                        Gate* gate = plane->checkFreeGate(p);
                        
                        //Only taxi to gate, if there is free gate
                        if (gate != NULL) {
                            //Plane landed, let it taxi
                            if (plane->taxi(gate)) {
                                //Plane taxid, so runway is back free
                                freeRunway->clearRunway();

                                OUTPUT << plane->getCallsign() << " is taxing to gate " << gate->getId();
                            
                                //Check if plane is standing correctly
                                if (plane->getStatus() == Airplane::Status::STANDING) {
                                    OUTPUT << plane->getCallsign() << " is standing at gate " << gate->getId();
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
