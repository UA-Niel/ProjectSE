#include <iostream>
#include "AirportExporter.h"


AirportExporter::~AirportExporter() {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
}

AirportExporter::AirportExporter() : _initCheck(this), _startOutput(false), _airport(NULL) {
    ENSURE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
}

bool AirportExporter::properlyInitalized() const{
    return this == _initCheck;
}

AirportExporter::AirportExporter(Airport *airport) : _airport(airport) {
    _initCheck = this;
    _startOutput = false;
    ENSURE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
}

Airport *AirportExporter::get_airport() const {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    return _airport;
}

void AirportExporter::set_airport(Airport *airport) {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    AirportExporter::_airport = airport;
}

void AirportExporter::startOutput() {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    _startOutput = true;
}

void AirportExporter::outputAirportDetails(ostream &stream) {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initalized correctly?");
    REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
    stream << "Airport: " << _airport->getName() << " (" << _airport->getIATA() << ")" << endl;
    stream << "\t-> gates: " << _airport->getNrOfGates() << endl;
    stream << "\t-> runways: " << _airport->getNrOfRunways() << endl << endl;
}

void AirportExporter::outputPlaneDetails(ostream &stream) {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initalized correctly?");
    REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");

    for(unsigned int i = 0; i<_airport->getAirplanes().size(); i++){
        Airplane* airplane = _airport->getAirplanes()[i];
        stream << "Airplane: " << airplane->getNumber() << " (" << airplane->getCallsign() << ")" << endl;
        stream << "\t-> model: " << airplane->getModel() << endl << endl;
    }
}

void AirportExporter::outputBasicInfo(ostream &stream) {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initalized correctly?");
    REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput() first");
    outputAirportDetails(stream);
    outputPlaneDetails(stream);
}

void AirportExporter::stopOutput() {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    REQUIRE(_startOutput, "StartOutput has to be true before it can be stopped");
    _startOutput = false;
}

void AirportExporter::outputString(ostream &stream, std::string outputString) {
    REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
    REQUIRE(_startOutput, "StartOutput has to be true before it can be stopped");
    stream << outputString << endl;
}


