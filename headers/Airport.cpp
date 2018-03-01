//Declaration file for Airport-class

#include "Airport.h"
#include "Airplane.h"
#include "Runway.h"
#include "Gate.h"

using namespace std;

//Add Airplane
bool Airport::addAirplane(Airplane& airplane) {return true;}
//Add Runway
bool Airport::addRunway(Runway& runway) {return true;}
//Add Gate
bool Airport::addGate(Gate& gate) {return true;}

//Remove Airplane
bool Airport::removeAirplane(const int id) {return true;}
//Remove Runway
bool Airport::removeRunway(const int id) {return true;}
//Remove Gate
bool Airport::removeGate(const int id) {return true;}

//Get Airplane&
Airplane& Airport::getAirplane(const int id) {
    Airplane a;
    return a;
}
//Get Runway&
Runway& Airport::getRunway(const int id) {
    Runway r;
    return r;
}
//Get Gate&
Gate& Airport::getGate(const int id) {
    Gate g;
    return g;
}

//Set ID
void Airport::setId(const int id) {}
//Set name
void Airport::setName(const std::string name) {}
//Set IATA
void Airport::setIATA(const std::string IATA) {}
//Set callsign
void Airport::setCallsign(const std::string callsign) {}
