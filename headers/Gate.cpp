//Implementation file for Gate-class

#include "Gate.h"
#include "../DesignByContract.h"

Gate::Gate() {}

//Getters and setters
void Gate::setId(const int id) {
    REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
    this->_id = id;
}

int Gate::getId() const {
    return this->_id;
}

bool Gate::properlyInitialized() const {
    return _initCheck == this;
}
