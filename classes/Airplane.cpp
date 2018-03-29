/**
 * \file
 * This file contains the implementation of Airplane
 */

#include <string>
#include "Airport.h"
#include "../utils.h"


//Approach
void Airplane::approach(int amountOfFeet) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    REQUIRE(this->getStatus() == LANDING, "Airplane must be in LANDING status before it can approach");
    REQUIRE(amountOfFeet > 0, "You can only approach by a positive amount of feet");
    _height -= amountOfFeet;
}

//Returns a free runway
//:param Airport* ap: Our airport
Runway* Airplane::checkFreeRunway(Airport* ap) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initalized correctly");
    for (unsigned int i = 0; i < ap->getRunways().size(); i++) {
        if (ap->getRunway(i)->getAirplanesOnRunway().empty()) {
            return ap->getRunway(i);
        }
    }
    return NULL;
}

//Returns a free gate
//:param Airport* ap: Our airport
Gate* Airplane::checkFreeGate(Airport* ap) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initalized correctly")
    for (unsigned int i = 0; i < ap->getAllGates().size(); i++) {
        if (ap->getAllGates()[i]->getPlaneAtGate() == NULL) {
            return ap->getAllGates()[i];
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
void Airplane::setStatus(const Airplane::Status status) {
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
Airplane::Status Airplane::getStatus() const{
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return _status;
}

void Airplane::setHeight(const int height) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    this->_height = height;
}
int Airplane::getHeight() {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return this->_height;
}

void Airplane::setAmountOfPassengers(const int amount) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    this->_amountOfPassengers = amount;
}
int Airplane::getAmountOfPassengers() {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return this->_amountOfPassengers;
}
void Airplane::setFuelState(const Airplane::FuelState state) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    this->_fuelState = state;
}
Airplane::FuelState& Airplane::getFuelState() {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    return this->_fuelState;
}


bool Airplane::properlyInitialized() const {
    return _initCheck == this;
}

//Constructors
Airplane::Airplane(int airplaneId, const string &callsign, const string &_model, Airplane::Status status, const std::string& number)
        : _airplaneId(airplaneId), _callsign(callsign), _model(_model), _status(status), _number(number){

    _initCheck = this;
    _height = 0;
    _amountOfPassengers = 0;
    _fuelState = FULL;
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}
Airplane::Airplane() {
    _airplaneId = -1;
    _status = Airplane::UNKNOWN;
    _initCheck = this;
    _height = 0;
    _amountOfPassengers = 0;
    _fuelState = FULL;
    _callsign = "";
    _model = "";
    _number = "";
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}

void Airplane::ascend(unsigned int amountOfFeet) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initalized correctly");
    _height += amountOfFeet;
}
