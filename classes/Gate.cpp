/**
 * \file
 * This file contains the implementation of Gate
 */

#include "Gate.h"
#include "../DesignByContract.h"
#include "Airplane.h"

Gate::Gate() {
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Gate not properly initialized.");
}

//Getters and setters
void Gate::setId(const int id) {
    REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
    this->_id = id;
}

int Gate::getId() const {
    REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
    return this->_id;
}

void Gate::setPlaneAtGate(Airplane* plane) {
    REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
    REQUIRE(plane->getStatus() == Airplane::TAXING, "Airplane has to be taxiing before it can be assigned to a Gate")
    this->_planeAtGate = plane;
}
Airplane* Gate::getPlaneAtGate() {
    REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
    return this->_planeAtGate;
}

bool Gate::properlyInitialized() const {
    return _initCheck == this;
}
