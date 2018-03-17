/**
 * \file
 * This file contains the implementation of Airplane
 */

#include <string>
#include "Airport.h"
#include "../utils.h"


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
    this->setStatus(Airplane::LANDED);

    ENSURE(this->getStatus() == LANDED, "Expected the status to be LANDED");

    return true;
}
//Taxi to gate
bool Airplane::taxi(Gate* gate) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initalized correctly");
    REQUIRE(this->getStatus() == LANDED, "The status of the Airplane has to be LANDED before it can taxi");
    this->setStatus(Airplane::TAXING);

    //Let plane go to gate
    gate->setPlaneAtGate(this);
   
    this->setStatus(Airplane::STANDING);

    ENSURE(this->getStatus() == STANDING, "Expected the status to be STANDING");

    return true;
}
//Approach
bool Airplane::approach(Airport* ap, AirportExporter* exporter) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
   
    if (this->getStatus() != Airplane::LANDING) {
        this->setStatus(Airplane::APPROACHING);

        //Output
        string message = getCallsign() + " is approaching " + ap->getCallsign() + " at " + ToString(_height) +"ft.";
        exporter->outputString(message);
    }
    

    //While airplane is higher than 10,000ft
    if (this->getHeight() > 1000) {
        //Airplane descends 1000ft
        this->setHeight(this->getHeight() - 1000);

        //Output
        string message = getCallsign() + " descended to " + ToString(_height) + "ft.";
        exporter->outputString(message);
    
        this->setStatus(Airplane::LANDING);
        
        return true;
    }


/*
    //Airplane lands on free runway
    //Check for free runway
    Runway* freeRunway = checkFreeRunway(ap);

    //Let plane land on the free runway
    this->land(freeRunway);

    this->setStatus(Airplane::Status::LANDED);
*/
    return true;
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
void Airplane::setFuelState(const Airplane::FuelState& state) {
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
Airplane::Airplane(int airplaneId, const string &callsign, const string &_model, Airplane::Status& status, const std::string& number)
        : _airplaneId(airplaneId), _callsign(callsign), _model(_model), _status(status), _number(number){
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}
Airplane::Airplane() {
    _airplaneId = -1;
    _status = Airplane::UNKNOWN;
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}
