/**
 * \file This file contains the implementation of ApTime (Airport Time)
 */

#include <cmath>
#include <iostream>
#include "../headers/ApTime.h"
#include "../headers/DesignByContract.h"
#include "../headers/utils.h"

int ApTime::getHour() const {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    return _hour;
}

void ApTime::setHour(int hour) {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    ApTime::_hour = hour;
    if(hour < 0 || hour > 23) _hour = 0;
    else _hour = hour;
    ENSURE(_hour < 24 && _hour >= 0, "Range of hours has to be [0, 24[");
    ENSURE(_hour == 0 || _hour == hour, "Error setting Hour of ApTime");
}

int ApTime::getMinutes() const {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    return _minutes;
}

void ApTime::setMinutes(int minutes) {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    if(minutes < 0 || minutes > 59) _minutes = 0;
    else ApTime::_minutes = minutes;
    ENSURE(_minutes < 60 && _minutes >= 0, "Range of minutes has to be [0, 60[");
    ENSURE(_minutes == 0 || _minutes == minutes, "Error setting Minutes of ApTime");
}

ApTime::ApTime(int hour, int minutes){
    _initCheck = this;
    if(hour < 0 || hour > 23) _hour = 0;
    else _hour = hour;
    if(minutes < 0 || minutes > 59) _minutes = 0;
    else _minutes = minutes;
    ENSURE(_minutes < 60 && _minutes >= 0, "Range of minutes has to be [0, 60[");
    ENSURE(_hour < 24 && _hour >= 0, "Range of hours has to be [0, 24[");
    ENSURE(_minutes == 0 || _minutes == minutes, "Error setting Minutes of ApTime");
    ENSURE(_hour == 0 || _hour == hour, "Error setting Hour of ApTime");
    ENSURE(this->properlyInitialized(), "ApTime is not initialized correctly");
}

bool ApTime::properlyInitialized() const {
    return _initCheck == this;
}

void ApTime::raiseTime(int minutes) {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    REQUIRE(minutes > 0, "Can't go back in time");
    int hours = (int)floor(minutes/60);
    while(minutes >= 60) minutes -= 60;
    _hour += hours;
    if(_hour > 23){
        _hour = _hour - 24;
    }
    _minutes += minutes;
    if(_minutes > 59){
        _hour++;
        if(_hour > 23) _hour = 0;
        _minutes = _minutes - 60;
    }
    ENSURE(_minutes < 60 && _minutes >= 0, "Range of minutes has to be [0, 60[");
    ENSURE(_hour < 24 && _hour >= 0, "Range of hours has to be [0, 24[");
}


std::string ApTime::toString() const {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    std::string res;
    if(_hour < 10) res+= '0' + ToString(_hour);
    else res += ToString(_hour);
    res += ':';
    if(_minutes < 10) res += '0' + ToString(_minutes);
    else res += ToString(_minutes);
    ENSURE(res.size() == 5, "Incorrect format of ApTime String");
    return res;
}

const ApTime ApTime::operator++(int) {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    ApTime result(*this);
    ++(*this);
    return result;
}

ApTime &ApTime::operator+=(int minutes) {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    REQUIRE(minutes >= 0, "Amount of minutes has to be positive, can't go back in time");
    this->raiseTime(minutes);
    return *this;
}

bool ApTime::operator==(ApTime &time) {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    REQUIRE(time.properlyInitialized(), "ApTime is not initialized correctly");
    return _hour == time.getHour() && _minutes == time.getMinutes();
}

ApTime &ApTime::operator=(const ApTime &time) {
    REQUIRE(time.properlyInitialized(), "ApTime is not initialized correctly");
    _initCheck = this;
    _minutes = time.getMinutes();
    _hour = time.getHour();
    ENSURE(this->properlyInitialized(), "ApTime is not initialized correctly");
    return *this;
}

bool ApTime::operator!=(ApTime &time) {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    REQUIRE(time.properlyInitialized(), "ApTime is not initialized correctly");
    return _hour != time.getHour() || _minutes != time.getMinutes();
}

ApTime &ApTime::operator++() {
    REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
    raiseTime(1);
    return *this;
}

