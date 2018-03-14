/**
 * \file
 * This file contains the implementation of Airport
 */

#include "Airport.h"
#include "Airplane.h"
#include "Gate.h"
#include "Runway.h"
#include "../DesignByContract.h"

using namespace std;

//Add Airplane
bool Airport::addAirplane(Airplane* airplane) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");

    this->_airplanesOnAirport.push_back(airplane);

    return true;
}
//Add Runway
bool Airport::addRunway(Runway* runway) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    this->_runways.push_back(runway);

    return true;
}
//Add Gate
bool Airport::addGate(Gate* gate) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    this->_gates.push_back(gate);

    return true;
}

//Remove Airplane
bool Airport::removeAirplane(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");

    int counter = 0;
    for(unsigned int i = 0; i < this->_airplanesOnAirport.size(); i++) {
        if (this->_airplanesOnAirport[i]->getId() == id) break;
        counter++;
    }

    this->_airplanesOnAirport.erase(this->_airplanesOnAirport.begin() + counter);

    return true;
}
//Remove Runway
bool Airport::removeRunway(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    int counter = 0;
    for(unsigned int i = 0; i < this->_runways.size(); i++) {
        if (this->_runways[i]->getId() == id) break;
        counter++;
    }

    this->_runways.erase(this->_runways.begin() + counter);
    
    return true;
}
//Remove Gate
bool Airport::removeGate(const int id) {
    REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
    
    int counter = 0;
    for (unsigned int i = 0; i < this->_gates.size(); i++) {
        if (this->_gates[i]->getId() == id) break;
        counter++;
    }

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
    return _airplanesOnAirport;
}

std::vector<Runway*>* Airport::getRunways() {
    return &_runways;
}
