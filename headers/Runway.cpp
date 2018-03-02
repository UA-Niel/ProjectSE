//Implementation file for Runway-class

#include "Runway.h"

//Add airplane
bool Runway::addAirplane(Airplane& airplane) {return true;}

//Accessors and mutators
void Runway::setId(const int id) {}
void Runway::setName(const std::string& name) {}
void Runway::setAirport(const int id) {}

int Runway::getId() const{}
std::string& Runway::getName() const{}
int Runway::getAirport() const{}

bool Runway::properlyInitialized() const {
    return _initCheck == this;
}

Runway::Runway(int runwayId, const string &_name, const vector<int> &airplanesOnRunway) : runwayId(runwayId),
                                                                                          _name(_name),
                                                                                          airplanesOnRunway(
                                                                                                  airplanesOnRunway) {
    _initCheck = this;
}
Runway::Runway() {
    _initCheck = this;
}
