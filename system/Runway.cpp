/**
 * \file
 * This file contains the implementation of Runway
 */

#include "../headers/Runway.h"
#include "../headers/DesignByContract.h"
    #include <iostream> 

//Add airplane
bool Runway::addAirplane(Airplane* airplane) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    unsigned int oldSize = _airplanesOnRunway.size();
    _airplanesOnRunway.push_back(airplane);
    ENSURE(oldSize == _airplanesOnRunway.size()-1, "Errror adding plane to Runway");
    return true;
}

//Clear runway
bool Runway::clearRunway() {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    REQUIRE(!_airplanesOnRunway.empty(), "There are no Airplanes at the runway");
    _airplanesOnRunway.clear();
    REQUIRE(_airplanesOnRunway.empty(), "Error clearing Runway");
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
    ENSURE(_runwayId == id, "Error setting new ID for the Runway");
}

void Runway::setName(const std::string& name) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly")
    _name = name;
    ENSURE(_name == name, "Error setting new name for the Runway");
}

void Runway::setAirport(const int id) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly")
    _myAirport = id;
    ENSURE(_myAirport == id, "Error setting new Airport ID for the Runway");
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
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    this->runwayType = type;
    ENSURE(this->runwayType == type, "Error setting new type for the Runway");
}
void Runway::setType(std::string type) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
/*    std::string buffer = type;
    for(int i=0;buffer[i]!=0;i++)
        if(buffer[i]<='z' && buffer[i]>='a')
            buffer[i]-=32;
*/


    for (unsigned int i = 0; i < type.length(); i++) {
        char& c = type[i];
        c = toupper(c);
    }
    if (type == "GRASS") this->runwayType = Runway::GRASS;
    if (type == "ASPHALT") this->runwayType = Runway::ASPHALT;
    if (type == "SAND") this->runwayType = Runway::SAND;
    if (type == "UNKNOWN") this->runwayType = Runway::UNKNOWN;
}

void Runway::setLength(const int length) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    this->length = length;
    ENSURE(this->length == length, "Error setting new length of the Runway");
}

const int Runway::getLength() { 
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    return this->length;
}

void Runway::addToTaxiRoute(const std::string name) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    unsigned int oldSize = taxiRoute.size();
    this->taxiRoute.push_back(name);
    ENSURE(oldSize == taxiRoute.size()-1, "Error adding to Route");
}

const std::string& Runway::getTaxiRoute(const int index) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
    return this->taxiRoute[index];
}
const std::vector<std::string>& Runway::getTaxiRoute() {
    return this->taxiRoute;
}

Runway::RunwayType& Runway::getType() {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
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
    this->runwayType = Runway::UNKNOWN;
    this->length = 0;
    ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
}
