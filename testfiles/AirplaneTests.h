#ifndef PROJECTSE_AIRPLANETESTS_H
#define PROJECTSE_AIRPLANETESTS_H


#include <gtest/gtest.h>

class AirplaneTests: public ::testing::Test {

protected:
    friend class Runway;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

};


#endif //PROJECTSE_AIRPLANETESTS_H
