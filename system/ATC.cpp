#include "../headers/ATC.h"
#include "../headers/DesignByContract.h"
#include "../headers/ApTime.h"

ATC::ATC(const std::string &callsign) : _callsign(callsign) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "ATC is not initialized correctly");
}

const std::string &ATC::getCallsign() const {
    REQUIRE(properlyInitialized(), "ATC is not initialized correctly");
    return _callsign;
}

void ATC::setCallsign(const std::string &callsign) {
    REQUIRE(properlyInitialized(), "ATC is not initialized correctly");
    ATC::_callsign = callsign;
    ENSURE(_callsign == callsign, "Error setting new callsign");
}

bool ATC::properlyInitialized() const {
    return _initCheck == this;
}

std::string ATC::atcMessage(ApTime &time, const std::string &source, const std::string &message) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    std::string res = "[" + time.toString() + "] [" + source + "]\n"
            "\t$ " + message + "\n";
    return res;
}

bool ATC::operator==(ATC &atc) {
    REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
    REQUIRE(atc.properlyInitialized(), "ATC is not initialized correctly");
    return atc.getCallsign() == _callsign;
}
