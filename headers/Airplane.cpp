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

int Airplane::getId() const{}
std::string& Airplane::getCallsign() const{}
std::string& Airplane::getModel() const{}
int Airplane::getStatus() const{}

bool Airplane::properlyInitialized() const {
    return _initCheck == this;
}

Airplane::Airplane(int _airplaneId, const string &_callsign, const string &_model, int _status)
        : _airplaneId(_airplaneId), _callsign(_callsign), _model(_model), _status(_status){
    _initCheck = this;
}
