/**
 * \file This file contains the implementation of ATC
 */

#include "../headers/ATC.h"
#include "../headers/DesignByContract.h"
#include "../headers/ApTime.h"
#include "../headers/utils.h"

ATC::ATC(const std::string &callsign) : _callsign(callsign) {
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
    natoAlphabet.push_back("Zero");
    natoAlphabet.push_back("One");
    natoAlphabet.push_back("Two");
    natoAlphabet.push_back("Three");
    natoAlphabet.push_back("Four");
    natoAlphabet.push_back("Five");
    natoAlphabet.push_back("Six");
    natoAlphabet.push_back("Seven");
    natoAlphabet.push_back("Eight");
    natoAlphabet.push_back("Nine");
    natoAlphabet.push_back("Alpha");
    natoAlphabet.push_back("Bravo");
    natoAlphabet.push_back("Charlie");
    natoAlphabet.push_back("Delta");
    natoAlphabet.push_back("Echo");
    natoAlphabet.push_back("Foxtrot");
    natoAlphabet.push_back("Golf");
    natoAlphabet.push_back("Hotel");
    natoAlphabet.push_back("India");
    natoAlphabet.push_back("Juliett");
    natoAlphabet.push_back("Kilo");
    natoAlphabet.push_back("Lima");
    natoAlphabet.push_back("Mike");
    natoAlphabet.push_back("November");
    natoAlphabet.push_back("Oscar");
    natoAlphabet.push_back("Papa");
    natoAlphabet.push_back("Quebec");
    natoAlphabet.push_back("Romeo");
    natoAlphabet.push_back("Sierra");
    natoAlphabet.push_back("Tango");
    natoAlphabet.push_back("Uniform");
    natoAlphabet.push_back("Victor");
    natoAlphabet.push_back("Whiskey");
    natoAlphabet.push_back("Xray");
    natoAlphabet.push_back("Yankee");
    natoAlphabet.push_back("Zulu");
    ENSURE(natoAlphabet.size() == 36, "Incorrect size of NATO alphabet vector");
    return natoAlphabet;
}

std::string ATC::intToNato(int input) {
    std::vector<std::string> natoAlphabet = generateNato();
    std::string res;
    std::string num = ToString(input);
    for(auto& ch : num){
        int current = ch - '0';
        res.insert(res.end(), natoAlphabet[current].begin(), natoAlphabet[current].end());
        res.push_back(' ');
    }
    res.erase(res.end()-1);
    ENSURE(!res.empty(), "Error converting integer to NATO equivalent");
    return res;
}

std::string ATC::charToNato(char input) {
    std::vector<std::string> natoAlphabet = generateNato();
    int pos = tolower(input) - 87;
    return natoAlphabet[pos];
}
