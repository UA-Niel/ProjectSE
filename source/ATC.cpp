/**
 * \file This file contains the implementation of ATC
 */

#include "../headers/ATC.h"
#include "../headers/DesignByContract.h"
#include "../headers/ApTime.h"
#include "../headers/utils.h"

ATC::ATC(const std::string &callsign, Airport* airport) : _callsign(callsign), _airport(airport) {
    _initCheck = this;
    _natoAlphabet = generateNato();
    ENSURE(properlyInitialized(), "ATC is not initialized correctly");
}

const std::string &ATC::getCallsign() const {
    REQUIRE(properlyInitialized(), "ATC is not initialized correctly");
    return _callsign;
}

void ATC::setCallsign(const std::string &callsign) {
    REQUIRE(properlyInitialized(), "ATC is not initialized correctly");
    ATC::_callsign = callsign;
    ENSURE(getCallsign() == callsign, "Error setting new callsign");
}

bool ATC::properlyInitialized() const {
    return _initCheck == this;
}

std::string ATC::atcMessage(ApTime* time, const std::string &source, const std::string &message) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    REQUIRE(time->properlyInitialized(), "ApTime is not initialized correctly");
    std::string res = "[" + time->toString() + "] [" + source + "]\n"
            "$ " + message + "\n";
    return res;
}

bool ATC::operator==(ATC &atc) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    return atc.getCallsign() == _callsign;
}

std::vector<std::string> ATC::generateNato() {
    std::vector<std::string> natoAlphabet;
    natoAlphabet.push_back("zero");
    natoAlphabet.push_back("one");
    natoAlphabet.push_back("two");
    natoAlphabet.push_back("three");
    natoAlphabet.push_back("four");
    natoAlphabet.push_back("five");
    natoAlphabet.push_back("six");
    natoAlphabet.push_back("seven");
    natoAlphabet.push_back("eight");
    natoAlphabet.push_back("nine");
    natoAlphabet.push_back("alpha");
    natoAlphabet.push_back("bravo");
    natoAlphabet.push_back("charlie");
    natoAlphabet.push_back("delta");
    natoAlphabet.push_back("echo");
    natoAlphabet.push_back("foxtrot");
    natoAlphabet.push_back("golf");
    natoAlphabet.push_back("hotel");
    natoAlphabet.push_back("india");
    natoAlphabet.push_back("juliett");
    natoAlphabet.push_back("kilo");
    natoAlphabet.push_back("lima");
    natoAlphabet.push_back("mike");
    natoAlphabet.push_back("november");
    natoAlphabet.push_back("oscar");
    natoAlphabet.push_back("papa");
    natoAlphabet.push_back("quebec");
    natoAlphabet.push_back("romeo");
    natoAlphabet.push_back("sierra");
    natoAlphabet.push_back("tango");
    natoAlphabet.push_back("uniform");
    natoAlphabet.push_back("victor");
    natoAlphabet.push_back("whiskey");
    natoAlphabet.push_back("xray");
    natoAlphabet.push_back("yankee");
    natoAlphabet.push_back("zulu");
    ENSURE(natoAlphabet.size() == 36, "Incorrect size of NATO alphabet vector");
    return natoAlphabet;
}

std::string ATC::intToNato(int input) {
    std::vector<std::string> natoAlphabet = generateNato();
    std::string result;
    if(input < 0){
        result += "minus ";
        input = -input;
    }
    std::string num = ToString(input);
    for(unsigned int i = 0; i<num.size(); i++){
        char ch  = num[i];
        int current = ch - '0';
        result.insert(result.end(), natoAlphabet[current].begin(), natoAlphabet[current].end());
        result.push_back(' ');
    }
    result.erase(result.end()-1);
    ENSURE(!result.empty(), "Error converting integer to NATO equivalent");
    return result;
}

std::string ATC::charToNato(char input) {
    std::vector<std::string> natoAlphabet = generateNato();
    int pos = tolower(input) - 87;
    ENSURE(pos > 0 && pos < 36, "Incorrect input given");
    return natoAlphabet[pos];
}

bool ATC::landingInitial() {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    if(!_airport->getWaitingPattern5000()){
        _airport->setWaitingPattern5000(true);
        return true;
    }
    return false;
}

bool ATC::landingAt5000() {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    if(!_airport->getWaitingPattern3000()){
        _airport->setWaitingPattern5000(false);
        _airport->setWaitingPattern3000(true);
        return true;
    }
    return false;
}

bool ATC::landingAt3000(Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    //First check for free runway in the airport
    Runway* freeRunway = plane->checkFreeRunway(_airport);
    if(freeRunway == NULL) return false;

    //If runway found, add plane to runway
    freeRunway->addAirplane(plane);
    _airport->setWaitingPattern3000(false);
    return true;
}

bool ATC::landingEnd(Airplane* plane){
    //Look for free gate, if none found continue
    Gate* freeGate = _airport->getFreeGate();
    if(freeGate == NULL) {
        return false;
    }
    //Clear the runway if the plane is moving to the gate
    Runway* currentRunway = _airport->getRunwayWithPlane(plane);
    currentRunway->clearRunway();
    plane->setStatus(Airplane::TAXIING_TO_GATE);
    freeGate->setPlaneAtGate(plane);
    return true;
}

bool ATC::departureOfGate() {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    return true;
}

bool ATC::departureWaitingAtRunway(Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    Runway* freeRunway = plane->checkFreeRunway(_airport);
    if(freeRunway == NULL) return false;

    Gate* currentGate = _airport->getGateWithPlane(plane);
    //clear current Gate and assign plane to runway
    if(currentGate != NULL)
        currentGate->clearGate();

    freeRunway->addAirplane(plane);
    return true;
}

bool ATC::departureWaitingOnRunway() {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    return true;
}

bool ATC::emergencyHigherThan3000(Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    return plane->getFuelState() == Airplane::EMPTY;
}

bool ATC::emergencyLowerThan3000(Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    return plane->getFuelState() == Airplane::EMPTY;
}

std::string ATC::stringToNato(string &str) {
    string res;
    for(unsigned int i = 0; i<str.size(); i++){
        char ch = str[i];
        if(isdigit(ch)){
            res += ATC::intToNato(ch - '0');
            res.append(" ");
        }else{
            res += ch;
        }
    }
    res.erase(res.end()-1);
    return res;
}
