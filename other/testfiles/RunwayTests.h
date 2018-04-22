#ifndef PROJECTSE_RUNWAYTESTS_H
#define PROJECTSE_RUNWAYTESTS_H


#include <gtest/gtest.h>
#include "../../headers/Runway.h"

class RunwayTests: public ::testing::Test {

protected:
    friend class Runway;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

};


#endif //PROJECTSE_RUNWAYTESTS_H
