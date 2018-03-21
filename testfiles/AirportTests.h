#ifndef PROJECTSE_AIRPORTTESTS_H
#define PROJECTSE_AIRPORTTESTS_H


#include <gtest/gtest.h>

class AirportTests: public ::testing::Test {

protected:
    friend class Airport;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};


#endif //PROJECTSE_AIRPORTTESTS_H
