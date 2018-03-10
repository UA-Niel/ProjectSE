#include "AirportExporter.h"
#include "../DesignByContract.h"

AirportExporter::~AirportExporter() {

}

AirportExporter::AirportExporter() : _initCheck(this), _startOutput(false) {
    ENSURE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
}

bool AirportExporter::properlyInitalized() {
    return this == _initCheck;
}
