/**
 * \file
 * This file contains the implementation of Gate
 */

#include "../headers/Gate.h"
#include "../headers/DesignByContract.h"
#include "../headers/Airplane.h"

Gate::Gate() {
    _initCheck = this;
    _id = -1;
    _planeAtGate = NULL;
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
    REQUIRE(plane->getStatus() == Airplane::TAXIING_TO_GATE, "Airplane has to be taxiing before it can be assigned to a Gate")
    this->_planeAtGate = plane;
}
Airplane* Gate::getPlaneAtGate() {
    REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
    return this->_planeAtGate;
}

bool Gate::properlyInitialized() const {
    return _initCheck == this;
}

void Gate::clearGate() {
    _planeAtGate = NULL;
}
