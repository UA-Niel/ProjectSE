/**
 * \file
 * This file contains the implementation of Airplane
 */

#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"
#include "../DesignByContract.h"

//Depart
bool Airplane::depart() {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return true;
}
//Land
bool Airplane::land(Runway* runway) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    
    //Plane land
    runway->getAirplanesOnRunway().push_back(this);

    return true;
}
//Taxi
bool Airplane::taxi(Gate* gate) {
    return false;
}
//Approach
bool Airplane::approach(Airport* ap) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    
    //Airplane approaches at 10,000ft
    _height = 10000;

    //While airplane is higher than 10,000ft
    while (_height > 1000) {
        //Airplane descends 1000ft
        _height -= 1000;
    }

    //Airplane lands on free runway
    //Check for free runway
    Runway* freeRunway = checkFreeRunway(ap);

    //Let plane land on the free runway
    this->land(freeRunway);

    return true;
}

//Returns a free runway]
//:param Airport* ap: Our airport
Runway* Airplane::checkFreeRunway(Airport* ap) {
    for (unsigned int i = 0; i < ap->getRunways()->size(); i++) {
        if (ap->getRunway(i)->getAirplanesOnRunway().size() == 0) {
            return ap->getRunway(i);
        }
    }
    return NULL;
}

//Accessors and mutators
void Airplane::setId(const int id) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    _airplaneId = id;
}
void Airplane::setNumber(const std::string& number) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    _number = number;
}
void Airplane::setCallsign(const std::string& callsign) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    _callsign = callsign;
}
void Airplane::setModel(const std::string& model) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    _model = model;
}
void Airplane::setStatus(const int status) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    _status = status;
}

int Airplane::getId() const{
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return _airplaneId;
}
std::string Airplane::getNumber() const{
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return _number;
}
std::string Airplane::getCallsign() const{
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return _callsign;
}
std::string Airplane::getModel() const{
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return _model;
}
int Airplane::getStatus() const{
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return _status;
}

bool Airplane::properlyInitialized() const {
    return _initCheck == this;
}

//Constructors
Airplane::Airplane(int airplaneId, const string &callsign, const string &_model, int status)
        : _airplaneId(airplaneId), _callsign(callsign), _model(_model), _status(status){
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}
Airplane::Airplane() {
    _airplaneId = -1;
    _status = -1;
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}
