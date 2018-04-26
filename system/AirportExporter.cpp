#include <iostream>
#include "../headers/IO/AirportExporter.h"
#include "../headers/Airport.h"


AirportExporter::~AirportExporter() {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
}

AirportExporter::AirportExporter(ostream& stream) : _initCheck(this), _startOutput(false), _airport(NULL),
                                                          _stream(stream)  {
    ENSURE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
}

bool AirportExporter::properlyInitialized() const{
    return this == _initCheck;
}

AirportExporter::AirportExporter(Airport *airport, ostream& stream) : _airport(airport), _stream(stream) {
    _initCheck = this;
    _startOutput = false;
    ENSURE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
}

Airport *AirportExporter::get_airport() const {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    return _airport;
}

void AirportExporter::set_airport(Airport *airport) {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    AirportExporter::_airport = airport;
}

void AirportExporter::startOutput() {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    _startOutput = true;
}

void AirportExporter::outputAirportDetails() {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initialized correctly?");
    REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
    _stream << "Airport: " << _airport->getName() << " (" << _airport->getIATA() << ")" << endl;
    _stream << "\t-> gates: " << _airport->getNrOfGates() << endl;
    _stream << "\t-> runways: " << _airport->getNrOfRunways() << endl << endl;
}

void AirportExporter::outputPlaneDetails() {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initialized correctly?");
    REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");

    if(_airport->getAirplanes().empty()){
        _stream << "There are currently no airplanes" << endl;
        return;
    }

    for(unsigned int i = 0; i<_airport->getAirplanes().size(); i++){
        Airplane* airplane = _airport->getAirplanes()[i];
        _stream << "Airplane: " << airplane->getNumber() << " (" << airplane->getCallsign() << ")" << endl;
        _stream << "\t-> model: " << airplane->getModel() << endl << endl;
    }
}

void AirportExporter::outputBasicInfo() {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initialized correctly?");
    REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput() first");
    outputAirportDetails();
    outputPlaneDetails();
}

void AirportExporter::stopOutput() {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    REQUIRE(_startOutput, "StartOutput has to be true before it can be stopped");
    _startOutput = false;
}

void AirportExporter::outputString(std::string outputString) {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
    REQUIRE(_startOutput, "StartOutput has to be true before it can be stopped");
    _stream << outputString << endl;
}

ostream &AirportExporter::operator<<(string string1) {
    REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
    _stream << string1;
    return _stream;
}


