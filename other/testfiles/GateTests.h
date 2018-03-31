#ifndef PROJECTSE_GATETESTS_H
#define PROJECTSE_GATETESTS_H


#include <gtest/gtest.h>

class GateTests: public ::testing::Test{

protected:
    friend class Gate;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

};


#endif //PROJECTSE_GATETESTS_H
