//Declaration file for Airport-class

#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"
#include "Gate.h"

using namespace std;

//Add Airplane
bool Airport::addAirplane(Airplane& airplane) {
    return true;
}
//Add Runway
bool Airport::addRunway(Runway& runway) {
    return true;
}
//Add Gate
bool Airport::addGate(Gate& gate) {
    return true;
}

//Remove Airplane
bool Airport::removeAirplane(const int id) {
    return true;
}
//Remove Runway
bool Airport::removeRunway(const int id) {
    return true;
}
//Remove Gate
bool Airport::removeGate(const int id) {
    return true;
}

//Get Airplane&
Airplane& Airport::getAirplane(const int id) const{
    Airplane a;
    return a;
}
//Get Runway&
Runway& Airport::getRunway(const int id) const{
    Runway r;
    return r;
}
//Get Gate&
Gate& Airport::getGate(const int id) const {
    Gate g;
    return g;
}

//Setters:
void Airport::setId(const int id) {
    _airportId = id;
}
void Airport::setName(const std::string name) {
    _name = name;
}
void Airport::setIATA(const std::string IATA) {
    _IATA = IATA;
}
void Airport::setCallsign(const std::string callsign) {
    _callsign = callsign;
}

//Getters:
int Airport::getId() const{
    return _airportId;
}
const std::string &Airport::getName() const{
    return _name;
}
const std::string &Airport::getIATA() const{
    return _IATA;
}
const std::string &Airport::getCallsign() const{
    return _callsign;
}

Airport::Airport(const vector<Runway> &_runways, const vector<Gate> &_gates, int _airportId, const string &_name,
                 const string &_IATA, const string &_callsign) : _runways(_runways), _gates(_gates),
                                                                 _airportId(_airportId), _name(_name), _IATA(_IATA),
                                                                 _callsign(_callsign) {
    _initCheck = this;
}

bool Airport::properlyInitialized() const {
    return _initCheck == this;
}


