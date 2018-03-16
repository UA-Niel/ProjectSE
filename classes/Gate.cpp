/**
 * \file
 * This file contains the implementation of Gate
 */

#include "Gate.h"
#include "../DesignByContract.h"

Gate::Gate() {
    _initCheck = this;
}

//Getters and setters
void Gate::setId(const int id) {
    REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
    this->_id = id;
}

int Gate::getId() const {
    return this->_id;
}

void Gate::setPlaneAtGate(Airplane* plane) {
    this->_planeAtGate = plane; 
}
Airplane* Gate::getPlaneAtGate() {
    return this->_planeAtGate;
}

bool Gate::properlyInitialized() const {
    return _initCheck == this;
}
