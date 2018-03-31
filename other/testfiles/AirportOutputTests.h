#ifndef PROJECTSE_AIRPORTOUTPUTTESTS_H
#define PROJECTSE_AIRPORTOUTPUTTESTS_H


#include <gtest/gtest.h>
#include "../classes/Airport.h"

class AirportOutputTests: public ::testing::Test {
protected:
    friend class Airport;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    Airport airport;

    void setupAirport();
};



#endif //PROJECTSE_AIRPORTOUTPUTTESTS_H
