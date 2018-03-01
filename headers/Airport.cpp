//Declaration file for Airport-class

#include "Airport.h"

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
Airplane& Airport::getAirplane(const int id) {}
//Get Runway&
Runway& Airport::getRunway(const int id) {}
//Get Gate&
Gate& Airport::getGate(const int id) {}

//Set ID
void Airport::setId(const int id) {}
//Set name
void Airport::setName(const std::string name) {}
//Set IATA
void Airport::setIATA(const std::string IATA) {}
//Set callsign
void Airport::setCallsign(const std::string callsign) {}
