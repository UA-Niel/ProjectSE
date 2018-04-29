/**
 * \file
 * This file contains the implementation of Airport
 */

#include <cstdlib>
#include "../headers/Airport.h"
#include "../headers/Airplane.h"
#include "../headers/Gate.h"
#include "../headers/Runway.h"
#include "../headers/DesignByContract.h"
#include "../headers/utils.h"

using namespace std;

//Add Airplane
bool Airport::addAirplane(Airplane* airplane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(airplane->properlyInitialized(), "Airplane 'airplane' is not initialized correctly");
    unsigned int amountOfPlanesOld = _airplanesOnAirport.size();
    this->_airplanesOnAirport.push_back(airplane);
    ENSURE(amountOfPlanesOld == _airplanesOnAirport.size()-1, "Problem adding airplane to airport");
    return true;
}
//Add Runway
bool Airport::addRunway(Runway* runway) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(runway->properlyInitialized(), "Runway 'runway' is not initialized correctly");
    unsigned int amountOfRunwaysOld = _runways.size();
    this->_runways.push_back(runway);
    ENSURE(amountOfRunwaysOld == _runways.size()-1, "Problem adding runway");
    return true;
}
//Add Gate
bool Airport::addGate(Gate* gate) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(gate->properlyInitialized(), "Gate 'gate' is not initialized correctly");
    unsigned int amountOfGatesOld = _gates.size();
    this->_gates.push_back(gate);
    ENSURE(amountOfGatesOld == _gates.size()-1, "Problem adding gate");
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
    ENSURE(_airportId == id, "Failed to assign Airport ID");
}
void Airport::setName(const std::string name) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    _name = name;
    ENSURE(_name == name, "Failed to assign Airport name");
}
void Airport::setIATA(const std::string IATA) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    _IATA = IATA;
    ENSURE(_IATA == IATA, "Failed to assign IATA of the airport");
}
void Airport::setCallsign(const std::string callsign) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    _callsign = callsign;
    ENSURE(_callsign == callsign, "Failed to assign callsign of the airport")
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
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _gates.size();
}

unsigned int Airport::getNrOfRunways() const {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _runways.size();
}

const vector<Airplane *> &Airport::getAirplanes() const {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _airplanesOnAirport;
}

std::vector<Runway*>& Airport::getRunways() {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return _runways;
}

Airport::~Airport() {
}

Runway *Airport::getRunwayWithPlane(Airplane *plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    for(unsigned int i = 0; i<getRunways().size(); i++){
        Runway* runway = getRunways()[i];
        if(runway->getAirplanesOnRunway()[0]->getId() == plane->getId()){
            return runway;
        }
    }
    return NULL;
}

Gate *Airport::getFreeGate() {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    for(unsigned int i = 0; i<getAllGates().size(); i++){
        Gate* gate = getAllGates()[i];
        if(gate->getPlaneAtGate() == NULL) return gate;
    }
    return NULL;
}

Gate *Airport::getGateWithPlane(Airplane *plane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    REQUIRE(plane->properlyInitialized(), "Airplane 'plane' is not initialized correctly");
    for(unsigned int i = 0; i<getAllGates().size(); i++){
        Gate* gate = getAllGates()[i];
        if(gate->getPlaneAtGate() == NULL) continue;
        if(gate->getPlaneAtGate()->getId() == plane->getId()) return gate;
    }
    return NULL;
}

bool Airport::operator==(Airport &airport) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    return airport.getCallsign() == _callsign &&
            airport.getNrOfRunways() == this->getNrOfRunways() &&
            airport.getName() == _name &&
            airport.getId() == _airportId &&
            airport.getIATA() == _IATA;
}
