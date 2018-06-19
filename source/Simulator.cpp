/**
 * \file Contains the implementation of the Simulator class
 */


#include "../headers/Simulator.h"
#include "../headers/Exceptions.h"
#include "../headers/utils.h"
#include "../headers/ATC.h"
#include "../headers/ApTime.h"
#include <cstdlib>
#include <fstream>

using namespace std;


AirportExporter& Simulator::getExporter() const {
    REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
    return _exporter;
}

Airport* Simulator::getAirport() const {
    REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
    return _airport;
}

void Simulator::setAirport(Airport* airport) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
    REQUIRE(airport->properlyInitialized(), "Airport is not initalized correctly");
    Simulator::_airport = airport;
}

ATC* Simulator::getAtc() const {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    return _atc;
}

void Simulator::setAtc(ATC* atc) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    REQUIRE(atc->properlyInitialized(), "ATC is not initialized correctly");
    Simulator::_atc = atc;
    ENSURE(getAtc()->getCallsign() == atc->getCallsign(), "Error setting new ATC for Simulator");
}


bool Simulator::properlyInitalized() const {
    return this == _initCheck;
}

Simulator::Simulator(AirportExporter &exporter, Airport *airport, ApTime* time, ATC* atc) : _exporter(exporter), _airport(airport),
                                                                                            _atc(atc), _time(time) {
    REQUIRE(airport->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(exporter.properlyInitialized(), "AirportExporter is not initalized correctly");
    REQUIRE(atc->properlyInitialized(), "ATC is not initialized correctly");
    _initCheck = this;
    ENSURE(this->properlyInitalized(), "Simulator is not initalized correctly");
}

void Simulator::doSimulation(ofstream& output, int ticks) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");

    for(int simulationTick = 0; simulationTick<ticks;simulationTick++)
        for(unsigned int i = 0; i<_airport->getAirplanes().size(); i++){
            Airplane* plane = _airport->getAirplanes()[i];
            Airplane::Status status = plane->getStatus();

            string message;

            plane->downFuelLevel();

            if(status == Airplane::APPROACHING){
                doSimulationApproach(plane, output);
            }
            else if(status == Airplane::LANDING){
                doSimulationLanding(plane, output);
            }
            else if(status == Airplane::LANDED){
                doSimulationLanded(plane, output);
            }
            else if(status == Airplane::TAXIING_TO_GATE){
                doSimulationTaxiing(plane, output);
            }
            else if(status == Airplane::AT_GATE){
                doSimulationAtGate(plane, output);
            }
            else if(status == Airplane::STANDING){
                doSimulationStanding(plane, output);

            }
            else if(status == Airplane::DEPARTING){
                doSimulationDeparting(plane, output);
            }
            else if(status == Airplane::IN_AIR){
                continue;
            }
            else{
                throw SimulatorException("Unknown status of airplane " + plane->getCallsign());
            }
        }
}


void Simulator::doSimulationApproach(Airplane *plane, ofstream& comm) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane plane is not initialized correctly");
    REQUIRE(plane->getStatus() == Airplane::APPROACHING, "Airplane should be APPROACHING");
    string message;

    //Planes are on the radar from within 10000ft.
    plane->setHeight(10000);

    //Communication output:

    string msg = _atc->getCallsign() + ", " + plane->getCallsign() + ", arriving at " + _airport->getName() + ".";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;


    if(!_atc->landingInitial()){
        msg = plane->getCallsign() +
              ", hold south on the one eighty radial, expect further clearance at <time>";
        comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
        msg = "Holding south on the one eighty radial, " + plane->getCallsign();
        comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
        (*_time)++;;
        return;
    }


    msg = plane->getCallsign() + ", radar contact, descend and maintain five thousand feet, squawk " + ATC::intToNato(0);
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;;
    msg = "Descend and maintain five thousand feet, squawking " + ATC::intToNato(0) + ", " + plane->getCallsign();
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;


    //Output starting height
    message = plane->getCallsign() + " is approaching " + _airport->getCallsign() + " at "
              + ToString(plane->getHeight()) + "ft.";
    _exporter.outputString(message);

    //Give plane new status LANDING
    plane->setStatus(Airplane::LANDING);

    ENSURE(plane->getStatus() == Airplane::LANDING, "Airplane status should be set to LANDING");
    ENSURE(plane->getHeight() == 10000, "Height of the airplane should be 10000");

}

void Simulator::doSimulationLanding(Airplane *plane, ofstream& comm) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane is not initalized correctly");
    REQUIRE(plane->getStatus() == Airplane::LANDING, "Airplane should be in LANDING status");

    string message;
    if(plane->getHeight() <= 0){
        plane->setStatus(Airplane::LANDED);
    }else{
        if (plane->getHeight() == 10000) {
           std::string msg = plane->getCallsign() + ", request to descend to 5000ft";
           comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
            msg = "Descend permitted " + plane->getCallsign();
            comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
                (*_time)++;;
                return;
        }

        if(plane->getHeight() == 5000){
            string msg;
            if(!_atc->landingAt5000()) {
                msg = plane->getCallsign() +
                             ", hold south on the one eighty radial, expect further clearance at <time>";
                comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
                msg = "Holding south on the one eighty radial, " + plane->getCallsign();
                comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
                (*_time)++;;
                return;
            }

            msg = plane->getCallsign() + ", descend and maintain three thousand feet.";
            comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
            (*_time)++;;
            msg = "Descend and maintain three thousand feet, " + plane->getCallsign() + ".";
            comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
            (*_time)++;;
        }

        if(plane->getHeight() == 3000){
            string msg;
            if(!_atc->landingAt3000(plane)){
                msg = plane->getCallsign() +
                      ", hold south on the one eighty radial, expect further clearance at <time>";
                comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
                msg = "Holding south on the one eighty radial, " + plane->getCallsign();
                comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
                (*_time)++;;
                return;
            }
            Runway* freeRunway = _airport->getRunwayWithPlane(plane);
            msg = plane->getCallsign() + ", cleared ILS approach runway, " + freeRunway->getName() + ".";
            comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
            (*_time)++;;
            msg = "Cleared ILS approach runway " + freeRunway->getName() + ", " + plane->getCallsign();
            comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
            (*_time)++;;
        }

        //let plane approach more
        plane->approach();
        (*_time) += plane->timeCheckChangeAlt();
        //give output feedback
        message = plane->getCallsign() + " descended to " + ToString(plane->getHeight()) + "ft.";
        _exporter.outputString(message);
    }

    ENSURE(plane->getStatus() == Airplane::LANDED || plane->getStatus() == Airplane::LANDING, "Unexpected status of airplane")

}

void Simulator::doSimulationLanded(Airplane *plane, ofstream& comm) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly")
    REQUIRE(plane->getStatus() == Airplane::LANDED, "Airplane must be in LANDED state");

    string message;
    //Search for runway with plane assigned to
    Runway* currentRunway = _airport->getRunwayWithPlane(plane);

    (*_time) += plane->timeCheckLanding();

    message = plane->getCallsign() + " landed at Runway " + currentRunway->getName();
    _exporter.outputString(message);


    string msg = _atc->getCallsign() + ", " + plane->getCallsign() + ", runway " + currentRunway->getName() + " vacated.";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;

    if(!_atc->landingEnd(plane)) {
        ENSURE(plane->getStatus() == Airplane::LANDED, "Status of airplane should still be LANDED if there are no free Gates");
        return;
    }
    Gate* freeGate = _airport->getGateWithPlane(plane);
    msg = "taxi to gate " + ATC::intToNato(freeGate->getId());
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;;


    plane->setStatus(Airplane::TAXIING_TO_GATE);

    ENSURE(plane->getStatus() == Airplane::TAXIING_TO_GATE, "Expected status to be TAXIING TO GATE");
}

void Simulator::doSimulationTaxiing(Airplane *plane, ofstream& comm) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
    REQUIRE(plane->getStatus() == Airplane::TAXIING_TO_GATE, "Status of airplane has to be TAXIING TO GATE");

    string message;
    Gate* currentGate = _airport->getGateWithPlane(plane);
    message = plane->getCallsign() + " is taxiing to Gate " + ToString(currentGate->getId())
              + " of " + _airport->getName();
    _exporter.outputString(message);

    (*_time) += plane->timeCheckTaxiing();

    plane->setStatus(Airplane::AT_GATE);

    ENSURE(plane->getStatus() == Airplane::AT_GATE, "Status of airplane should be AT GATE");
}

void Simulator::doSimulationAtGate(Airplane *plane, ofstream& comm) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
    REQUIRE(plane->getStatus() == Airplane::AT_GATE, "Status of airplane should be AT GATE");

    if(!_atc->departureOfGate())
        return;

    string message;
    Gate* currentGate = _airport->getGateWithPlane(plane);
    //exit
    message = ToString(plane->getAmountOfPassengers()) + " passengers exited "
              + plane->getCallsign() + " at Gate " + ToString(currentGate->getId())
              + " of " + _airport->getName();
    _exporter.outputString(message);

    (*_time) += plane->timeCheckExiting();

    //technical checkup
    message = plane->getCallsign() + " has been checked for technical issues";
    _exporter.outputString(message);

    (*_time) += plane->timeCheckTechnicalCheck();

    //refueling
    plane->setFuelState(Airplane::FULL);
    message = plane->getCallsign() + " has been refueled";
    _exporter.outputString(message);


    //boarding
    message = ToString(plane->getAmountOfPassengers()) + " passengers have boarded " + plane->getCallsign()
              + " at Gate " + ToString(currentGate->getId()) + " of " + _airport->getName();
    _exporter.outputString(message);
    (*_time) += plane->timeCheckBoarding();

    string msg = _atc->getCallsign() + ", " + plane->getCallsign() + ", " +
                 " requesting IFR clearancy to destination, <destination>.";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;
    msg = plane->getCallsign() + ", " + _atc->getCallsign() + ", cleared to <destination>, maintain "
                                                             "five thousand, expect flight level "
                                                             "one one zero - ten minutes after departure"
                                                             ", squawk zero";
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;;
    msg = "Cleared to <destination>, initial altitude five thousand, expecting "
          "one zero zero in ten, squawking zero, " + plane->getCallsign();
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;

    msg = _atc->getCallsign() + ", " + plane->getCallsign() +
            " at gate " + ATC::intToNato(currentGate->getId()) + ", requesting pushback";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;
    msg = plane->getCallsign() + ", " + _atc->getCallsign()
            + ", pushback approved.";
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;
    msg = "Pushback approved, " + plane->getCallsign() + ".";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;

    (*_time)+= plane->timeCheckPushBack();

    plane->setStatus(Airplane::STANDING);

    ENSURE(plane->getFuelState() == Airplane::FULL, "Fuel state has to be FULL");
    ENSURE(plane->getStatus() == Airplane::STANDING, "Airplane state has to be STANDING");

}

void Simulator::doSimulationStanding(Airplane *plane, ofstream& comm) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
    REQUIRE(plane->getStatus() == Airplane::STANDING, "Status of airplane should be STANDING");

    string message;
    Gate* currentGate = _airport->getGateWithPlane(plane);


    string msg = plane->getCallsign() + " is ready to taxi";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;
    msg = "taxi to runway";
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;;


    //Initially a plane can be standing at a gate, so when NULL is encountered assign first free gate
    if(currentGate == NULL){
        currentGate = _airport->getFreeGate();
        if(currentGate == NULL) return;
    }

    message = plane->getCallsign() + " is standing at Gate " + ATC::intToNato(currentGate->getId())
              + " of " + _airport->getName();
    _exporter.outputString(message);

    if(!_atc->departureWaitingAtRunway(plane)){
        return;
    }

    Runway* freeRunway = _airport->getRunwayWithPlane(plane);

    message = plane->getCallsign() + " is taxiing to Runway " + freeRunway->getName() + " of " + _airport->getName();
    _exporter.outputString(message);

    msg = _atc->getCallsign() + ", " + plane->getCallsign() + ", holding short at " + freeRunway->getName()
            + ".";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;
    msg = plane->getCallsign() + ", hold position.";
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;;
    msg = "Holding position, " + plane->getCallsign() + ".";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;
    msg = _atc->getCallsign() + ", " + plane->getCallsign() + ", holding short at " + freeRunway->getName()
            + ".";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;
    msg = plane->getCallsign() + ", runway " + freeRunway->getName() + " cleared for take-off.";
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;;
    msg = "Runway " + freeRunway->getName() + " cleared for take-off.";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;;
    msg = plane->getCallsign() + ", runway " + freeRunway->getName() + " cleared for take-off.";
    comm << _atc->atcMessage(_time, _atc->getCallsign(), msg);
    (*_time)++;;
    msg = "Runway " + freeRunway->getName() + " cleared for take-off.";
    comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    (*_time)++;

    plane->setStatus(Airplane::DEPARTING);
    (*_time)+= plane->timeCheckTakeOff();

    ENSURE(plane->getStatus() == Airplane::DEPARTING, "Airplane status should be DEPARTING");
    ENSURE(currentGate->getPlaneAtGate() == NULL, "Gate should be empty");
    ENSURE(!freeRunway->getAirplanesOnRunway().empty(), "The free runway should contain at least one plane");

}

void Simulator::doSimulationDeparting(Airplane *plane, ofstream& comm) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
    REQUIRE(plane->getStatus() == Airplane::DEPARTING, "Airplane status should be DEPARTING");

    string message;
    Runway* currentRunway = _airport->getRunwayWithPlane(plane);

    if(plane->getHeight() >= 5000){

        message = plane->getCallsign() + " left " + _airport->getName() + " at Runway " + currentRunway->getName();
        _exporter.outputString(message);

        currentRunway->clearRunway();
        plane->setStatus(Airplane::IN_AIR);
        ENSURE(plane->getStatus() == Airplane::IN_AIR, "Status should be IN AIR if departed");

    }else{
        plane->ascend();
        message = plane->getCallsign() + " ascended to " + ToString(plane->getHeight()) + "ft.";
        _exporter.outputString(message);
        ENSURE(plane->getStatus() == Airplane::DEPARTING, "Status should be Departing if plane has not left yet");
    }
}

ApTime* Simulator::getTime() const {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    return _time;
}

void Simulator::setTime(ApTime* time) {
    REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
    _time = time;
    ENSURE(getTime() == time, "Error setting new time for the Simulator");
}

void Simulator::doSimulationFuelEmergency(Airplane* plane, ofstream& comm) {
   if (plane->getHeight() >= 3000) {
        ENSURE(plane->getHeight() >= 3000, "Height should be above 3000");
        ENSURE(plane->getFuelLevel() <= 0, "Fuel should be below 0");
        //Contact luchtverkeersleider                                              
        std::string msg = "Mayday mayday mayday" + _atc->getCallsign() + ", " + plane->getCallsign() + "request immediate landing, " + ToString(plane->getAmountOfPassengers()) + " persons on board.";
        comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
        //Clear runway
        std::vector<Runway*> runways = this->getAirport()->getRunways();
        Runway* emergencyRunway;
        for (unsigned int i = 0; i < runways.size(); i++) {
            if (runways[i]->getAirplanesOnRunway().size() == 0) {
                emergencyRunway = runways[i];
                break;
            } 
        }
        if (emergencyRunway == NULL && runways.size() > 0) {
            runways[0]->clearRunway();
            emergencyRunway = runways[0];
        } else {return;}

        //Land vliegtuig
        this->doSimulationLanding(plane, comm);
        //Passagiers uitstappen
        this->doSimulationTaxiing(plane, comm);
        //Technische controler     
        //Tanken
        this->doSimulationAtGate(plane, comm);
        this->doSimulationStanding(plane, comm);

        //ATC message 
        msg =  _atc->getCallsign() + "roger mayday, " + "squawk seven seven zero zero , cleared ILS landing runway " + emergencyRunway->getName();
        comm << _atc->atcMessage(_time, plane->getCallsign(), msg);

        return;      
   } else {
        ENSURE(plane->getHeight() < 3000, "Height should be below 3000");
        ENSURE(plane->getFuelLevel() <= 0, "Fuel should be below 0");
        
        std::string msg = "Mayday mayday mayday" + _atc->getCallsign() + ", " + plane->getCallsign() + "we are landing now!!! " + ToString(plane->getAmountOfPassengers()) + " persons on board.";
        comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
        
        //ATC message 
        msg =  _atc->getCallsign() + "roger mayday, " + "squawk seven seven zero zero , hulp is sent ";
        comm << _atc->atcMessage(_time, plane->getCallsign(), msg);
    
    return;
   }                                                                         
   return;                                                                    
}
