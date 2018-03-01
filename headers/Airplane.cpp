//Implementation file for Airplane-class

#include "Airplane.h"

//Depart
bool Airplane::depart() {return true;}
//Land
bool Airplane::land() {return true;}

//Accessors and mutators
void Airplane::setId(const int id) {}
void Airplane::setCallsign(const std::string& callsign) {}
void Airplane::setModel(const std::string& model) {}
void Airplane::setStatus(const int status) {}

int Airplane::getId() {}
std::string& Airplane::getCallsign() {}
std::string& Airplane::getModel() {}
int Airplane::getStatus() {}
