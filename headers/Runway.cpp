//Implementation file for Runway-class

#include "Runway.h"
#include "../DesignByContract.h"

//Add airplane
bool Runway::addAirplane(Airplane* airplane) {
    REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly")
    _airplanesOnRunway.push_back(airplane);
    return true;
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
    return 0;
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
    ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
}
