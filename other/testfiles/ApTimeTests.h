/**
 * \file This file contains the declaration for ApTime tests
 */

#ifndef PROJECTSE_APTIMETESTS_H
#define PROJECTSE_APTIMETESTS_H


#include <gtest/gtest.h>
#include "../../headers/ApTime.h"



class ApTimeTests: public ::testing::Test {
protected:
    friend class ApTime;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};


#endif //PROJECTSE_APTIMETESTS_H
