/**
 * \file
 * This file contains the implementation of Airport
 */

#include <cstdlib>
#include "Airport.h"
#include "Airplane.h"
#include "Gate.h"
#include "Runway.h"
#include "../DesignByContract.h"
#include "../utils.h"

using namespace std;

//Add Airplane
bool Airport::addAirplane(Airplane* airplane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(airplane->properlyInitialized(), "Airplane 'airplane' is not initalized correctly");
    this->_airplanesOnAirport.push_back(airplane);
    return true;
}
//Add Runway
bool Airport::addRunway(Runway* runway) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(runway->properlyInitialized(), "Runway 'runway' is not initalized correctly");
    this->_runways.push_back(runway);
    return true;
}
//Add Gate
bool Airport::addGate(Gate* gate) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(gate->properlyInitialized(), "Gate 'gate' is not initalized correctly");
    
    this->_gates.push_back(gate);

    return true;
}

//Remove Airplane
bool Airport::removeAirplane(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");

    int counter = 0;
    bool found = false;
    for(unsigned int i = 0; i < this->_airplanesOnAirport.size(); i++) {
        if (this->_airplanesOnAirport[i]->getId() == id){
            found = true;
            break;
        }
        counter++;
    }
    if(!found) return false;

    this->_airplanesOnAirport.erase(this->_airplanesOnAirport.begin() + counter);

    return true;
}

//Get all gates
std::vector<Gate*> Airport::getAllGates() {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return this->_gates;
}

//Remove Runway
bool Airport::removeRunway(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    int counter = 0;
    bool found = false;
    for(unsigned int i = 0; i < this->_runways.size(); i++) {
        if (this->_runways[i]->getId() == id){
            found = true;
            break;
        }
        counter++;
    }
    if(!found)
        return false;
    this->_runways.erase(this->_runways.begin() + counter);
    
    return true;
}
//Remove Gate
bool Airport::removeGate(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    int counter = 0;
    bool found = false;
    for (unsigned int i = 0; i < this->_gates.size(); i++) {
        if (this->_gates[i]->getId() == id){
            found = true;
            break;
        }
        counter++;
    }

    if(!found)
        return false;

    this->_gates.erase(this->_gates.begin() + counter);
    
    return true;
}

//Get Airplane&
Airplane* Airport::getAirplane(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
   

    for(unsigned int i = 0; i < this->_airplanesOnAirport.size(); i++) {
        if (this->_airplanesOnAirport[i]->getId() == id) return this->_airplanesOnAirport[i];
    }

    return NULL;
}
//Get Runway&
Runway* Airport::getRunway(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    for(unsigned int i = 0; i < this->_runways.size(); i++) {
        if (this->_runways[i]->getId() == id) return this->_runways[i];
    }
    return NULL;
}
//Get Gate&
Gate* Airport::getGate(const int id)  {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    for(unsigned int i = 0; i < this->_gates.size(); i++) {
        if (this->_gates[i]->getId() == id) return this->_gates[i];
    }
    return NULL;
}

//Setters:
void Airport::setId(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    _airportId = id;
}
void Airport::setName(const std::string name) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    _name = name;
}
void Airport::setIATA(const std::string IATA) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    _IATA = IATA;
}
void Airport::setCallsign(const std::string callsign) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    _callsign = callsign;
}

//Getters:
int Airport::getId() const{
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _airportId;
}
const std::string &Airport::getName() const{
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _name;
}
const std::string &Airport::getIATA() const{
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _IATA;
}
const std::string &Airport::getCallsign() const{
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _callsign;
}

//Constructors
Airport::Airport(){
    _airportId = -1;
    _callsign = "";
    _name = "";
    _IATA = "";
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airport is not initialized correctly");
}
Airport::Airport(const vector<Runway*> _runways, const vector<Gate*> _gates, int _airportId, const string &_name,
                 const string &_IATA, const string &_callsign) : _runways(_runways), _gates(_gates),
                                                                 _airportId(_airportId), _name(_name), _IATA(_IATA),
                                                                 _callsign(_callsign) {
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airport is not initialized correctly");
}

bool Airport::properlyInitialized() const {
    return _initCheck == this;
}

unsigned int Airport::getNrOfGates() const {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    return _gates.size();
}

unsigned int Airport::getNrOfRunways() const {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    return _runways.size();
}

const vector<Airplane *> &Airport::getAirplanes() const {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    return _airplanesOnAirport;
}

std::vector<Runway*>& Airport::getRunways() {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    return _runways;
}

Airport::~Airport() {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    for(unsigned int i = 0; i<getAirplanes().size(); i++) delete getAirplanes()[i];
    for(unsigned int i = 0; i<getAllGates().size(); i++) delete getAllGates()[i];
    for(unsigned int i = 0; i<getNrOfRunways(); i++) delete getRunways()[i];
}

void Airport::doSimulation(AirportExporter *exporter) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(exporter != NULL, "Exporter not found, is it initalized correctly?");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    for(unsigned int i = 0; i<_airplanesOnAirport.size(); i++){
        Airplane* plane = _airplanesOnAirport[i];
        Airplane::Status status = plane->getStatus();

        string message;

        if(status == Airplane::APPROACHING){
            doSimulationApproach(exporter, plane);
        }
        else if(status == Airplane::LANDING){
            doSimulationLanding(exporter, plane);
        }
        else if(status == Airplane::LANDED){
            doSimulationLanded(exporter, plane);
        }
        else if(status == Airplane::TAXIING_TO_GATE){
            doSimulationTaxiing(exporter, plane);
        }
        else if(status == Airplane::AT_GATE){
           doSimulationAtGate(exporter, plane);
        }
        else if(status == Airplane::STANDING){
            doSimulationStanding(exporter, plane);

        }
        else if(status == Airplane::DEPARTING){
            doSimulationDeparting(exporter, plane);
        }
        else if(status == Airplane::IN_AIR){
            continue;
        }
        else{
            cerr << "Unexpected Status of airplane" << plane->getCallsign();
            exit(-1);
        }

    }
}

Runway *Airport::getRunwayWithPlane(Airplane *plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initalized correctly");
    for(unsigned int i = 0; i<getRunways().size(); i++){
        Runway* runway = getRunways()[i];
        if(runway->getAirplanesOnRunway()[0]->getId() == plane->getId()){
            return runway;
        }
    }
    return NULL;
}

Gate *Airport::getFreeGate() {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    for(unsigned int i = 0; i<getAllGates().size(); i++){
        Gate* gate = getAllGates()[i];
        if(gate->getPlaneAtGate() == NULL) return gate;
    }
    return NULL;
}

Gate *Airport::getGateWithPlane(Airplane *plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    for(unsigned int i = 0; i<getAllGates().size(); i++){
        Gate* gate = getAllGates()[i];
        if(gate->getPlaneAtGate() == NULL) continue;
        if(gate->getPlaneAtGate()->getId() == plane->getId()) return gate;
    }
    return NULL;
}

void Airport::doSimulationApproach(AirportExporter *exporter, Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    string message;
    //First check for free runway in the airport
    Runway* freeRunway = plane->checkFreeRunway(this);
    if(freeRunway == NULL) return;

    //If runway found, add plane to runway
    freeRunway->addAirplane(plane);

    //Planes are on the radar from within 10000ft.
    plane->setHeight(10000);

    //Output starting height
    message = plane->getCallsign() + " is approaching " + this->getCallsign() + " at "
              + ToString(plane->getHeight()) + "ft.";
    exporter->outputString(message);

    //Give plane new status LANDING
    plane->setStatus(Airplane::LANDING);
}

void Airport::doSimulationLanding(AirportExporter *exporter, Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    string message;
    if(plane->getHeight() <= 0){
        plane->setStatus(Airplane::LANDED);
    }else{
        //let plane approach more
        plane->approach();
        //give output feedback
        message = plane->getCallsign() + " descended to " + ToString(plane->getHeight()) + "ft.";
        exporter->outputString(message);
    }
}

void Airport::doSimulationLanded(AirportExporter *exporter, Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    string message;
    //Search for runway with plane assigned to
    Runway* currentRunway = getRunwayWithPlane(plane);

    message = plane->getCallsign() + " landed at Runway " + currentRunway->getName();
    exporter->outputString(message);

    //Look for free gate, if none found continue
    Gate* freeGate = getFreeGate();
    if(freeGate == NULL) return;

    //Clear the runway if the plane is moving to the gate
    currentRunway->clearRunway();
    plane->setStatus(Airplane::TAXIING_TO_GATE);
    freeGate->setPlaneAtGate(plane);
}

void Airport::doSimulationTaxiing(AirportExporter *exporter, Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    string message;
    Gate* currentGate = getGateWithPlane(plane);
    message = plane->getCallsign() + " is taxiing to Gate " + ToString(currentGate->getId())
              + " of " + getName();
    exporter->outputString(message);

    plane->setStatus(Airplane::AT_GATE);
}

void Airport::doSimulationAtGate(AirportExporter *exporter, Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    string message;
    Gate* currentGate = getGateWithPlane(plane);
    //exit
    message = ToString(plane->getAmountOfPassengers()) + " passengers exited "
              + plane->getCallsign() + " at Gate " + ToString(currentGate->getId())
              + " of " + getName();
    exporter->outputString(message);
    //technical checkup
    message = plane->getCallsign() + " has been checked for technical issues";
    exporter->outputString(message);
    //refueling
    plane->setFuelState(Airplane::FULL);
    message = plane->getCallsign() + " has been refueled";
    exporter->outputString(message);
    //boarding
    message = ToString(plane->getAmountOfPassengers()) + " passengers have boarded " + plane->getCallsign()
              + " at Gate " + ToString(currentGate->getId()) + " of " + getName();
    exporter->outputString(message);
    plane->setStatus(Airplane::STANDING);

}

void Airport::doSimulationStanding(AirportExporter *exporter, Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    string message;
    Gate* currentGate = getGateWithPlane(plane);

    //Initially a plane can be standing at a gate, so when NULL is encountered assign first free gate
    if(currentGate == NULL){
        currentGate = getFreeGate();
        if(currentGate == NULL) return;
    }

    message = plane->getCallsign() + " is standing at Gate " + ToString(currentGate->getId())
              + " of " + getName();
    exporter->outputString(message);

    Runway* freeRunway = plane->checkFreeRunway(this);
    if(freeRunway == NULL) return;

    //clear current Gate and assign plane to runway
    currentGate->clearGate();

    freeRunway->addAirplane(plane);

    message = plane->getCallsign() + " is taxiing to Runway " + freeRunway->getName() + " of " +getName();
    exporter->outputString(message);

    plane->setStatus(Airplane::DEPARTING);
}

void Airport::doSimulationDeparting(AirportExporter *exporter, Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initalized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    REQUIRE(exporter->properlyInitalized(), "Exporter is not initalized correctly");
    string message;
    Runway* currentRunway = getRunwayWithPlane(plane);

    if(plane->getHeight() > 10000){

        message = plane->getCallsign() + " left " + getName() + " at Runway " + currentRunway->getName();
        exporter->outputString(message);

        currentRunway->clearRunway();
        plane->setStatus(Airplane::IN_AIR);

    }else{
        plane->ascend();
        message = plane->getCallsign() + " ascended to " + ToString(plane->getHeight()) + "ft.";
        exporter->outputString(message);
    }
}

