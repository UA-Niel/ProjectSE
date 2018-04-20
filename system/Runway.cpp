/**
 * \file
 * This file contains the implementation of Runway
 */

#include "../headers/Runway.h"
#include "../headers/DesignByContract.h"

//Add airplane
bool Runway::addAirplane(Airplane* airplane) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    _airplanesOnRunway.push_back(airplane);
    return true;
}

//Clear runway
bool Runway::clearRunway() {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    REQUIRE(!_airplanesOnRunway.empty(), "There are no Airplanes at the runway");
    _airplanesOnRunway.clear();
    
    return true;
}

//Return airplanes
std::vector<Airplane*>& Runway::getAirplanesOnRunway() {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly")
    return _airplanesOnRunway;
}

//Accessors and mutators
void Runway::setId(const int id) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly")
    _runwayId = id;
}

void Runway::setName(const std::string& name) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly")
    _name = name;
}

void Runway::setAirport(const int id) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly")
    _myAirport = id;
}

int Runway::getId() const{
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    return _runwayId;
}

std::string Runway::getName() const{
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    return _name;
}

int Runway::getAirport() const{
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    return _myAirport;
}

void Runway::setType(const Runway::RunwayType& type) {
    this->runwayType = type;
}
void Runway::setType(const std::string type) {
    std::string buffer = type;
    for(int i=0;buffer[i]!=0;i++)
        if(buffer[i]<='z' && buffer[i]>='a')
            buffer[i]-=32;
    
    if (type == "GRASS") this->runwayType = Runway::GRASS;
    if (type == "ASHPALT") this->runwayType = Runway::ASPHALT;
    if (type == "SAND") this->runwayType = Runway::SAND;
    if (type == "UNKNOWN") this->runwayType = Runway::UNKNOWN;
}

Runway::RunwayType& Runway::getType() {
    return this->runwayType;
}

bool Runway::properlyInitialized() const {
    return _initCheck == this;
}

Runway::Runway(int runwayId, const string &name, const vector<Airplane*> &airplanesOnRunway) :
        _runwayId(runwayId),
        _name(name),
        _airplanesOnRunway(airplanesOnRunway),
        _initCheck(this){

    ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
}
Runway::Runway() {
    _runwayId = 0;
    _initCheck = this;
    _myAirport = 0;
    ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
}
