/**
 * \file File used for Simulator tests
 */

#ifndef PROJECTSE_SIMULATORTESTS_H
#define PROJECTSE_SIMULATORTESTS_H


#include <gtest/gtest.h>
#include "../../headers/Simulator.h"

class SimulatorTests: public ::testing::Test {
protected:
    friend class Simulator;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};


#endif //PROJECTSE_SIMULATORTESTS_H
