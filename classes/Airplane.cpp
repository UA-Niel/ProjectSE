/**
 * \file
 * This file contains the implementation of Airplane
 */

#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"
#include "../DesignByContract.h"
#include "AirportExporter.h"

#include "Log.hpp"
#define OUTPUT Log()

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
    this->setStatus(Airplane::Status::LANDED);

    return true;
}
//Taxi
bool Airplane::taxi(Gate* gate) {
    this->setStatus(Airplane::Status::TAXING);

    //Let plane go to gate
    gate->setPlaneAtGate(this);
   
    this->setStatus(Airplane::Status::AT_GATE);

    return false;
}
//Approach
bool Airplane::approach(Airport* ap) {
    REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
   
    if (this->getStatus() != Airplane::Status::LANDING) {
        this->setStatus(Airplane::Status::APPROACHING);
        //Outputting
        OUTPUT << this->getCallsign() << " is approaching" << ap->getCallsign() << " at " << _height << "ft";  
    }
    

    //While airplane is higher than 10,000ft
    if (this->getHeight() > 1000) {
        //Airplane descends 1000ft
        this->setHeight(this->getHeight() - 1000);

        //Outputting
        OUTPUT << this->getCallsign() << " descended to " << _height << "ft.";
    
        this->setStatus(Airplane::Status::LANDING);
        
        return true;
    }


    //Airplane lands on free runway
    //Check for free runway
    Runway* freeRunway = checkFreeRunway(ap);

    //Let plane land on the free runway
    this->land(freeRunway);

    this->setStatus(Airplane::Status::LANDED);

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
    this->_height = height;
}
int Airplane::getHeight() {
    return this->_height;
}

bool Airplane::properlyInitialized() const {
    return _initCheck == this;
}

//Constructors
Airplane::Airplane(int airplaneId, const string &callsign, const string &_model, Airplane::Status& status, const std::string& number/*, AirportExporter* exporter*/)
        : _airplaneId(airplaneId), _callsign(callsign), _model(_model), _status(status), _number(number) /*,_exporter(exporter)*/ {
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}
Airplane::Airplane(/*AirportExporter* exporter*/) {
    _airplaneId = -1;
    _status = Airplane::Status::UNKNOWN; 
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
}
