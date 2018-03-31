/**
 * \file
 * This file contains the implementation of Route
 */

#include "../headers/Route.h"
#include <vector>
#include <string>

//Sets all the heights of this route in a vector
void Route::setHeightVector(const std::vector<int>& v) {
    this->_height = v; 
}

//Returns the whole vector of heights
const std::vector<int>& Route::getHeightVector() const {
    return this->_height;
}


//Return height of specific index in vector
//:param i: Index to get height from
int Route::getHeight(int i) const {
    return this->_height[i];
}

//Set airplane-number
void Route::setAirplane(const std::string& airplane) {
    this->_airplane = airplane;
}
//Get airplane-number
const std::string& Route::getAirplane() const {
    return this->_airplane;
}

//Set startingAirport
void Route::setStartingAirport(const std::string& startingAirport) {
    this->_startingAirport = startingAirport;
}
//Get startingAirport
const std::string& Route::getStartingAirport() const {
    return this->_startingAirport;
}

//Set destinationAirport
void Route::setDestinationAirport(const std::string& destinationAirport) {
    this->_destinationAirport = destinationAirport;
}
//Get destinationAirport
const std::string& Route::getDestinationAirport() const {
    return this->_destinationAirport;
}
