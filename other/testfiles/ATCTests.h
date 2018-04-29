/**
 * \file File used for ATC tests
 */

#ifndef PROJECTSE_ATCTESTS_H
#define PROJECTSE_ATCTESTS_H


#include <gtest/gtest.h>
#include "../../headers/ATC.h"


class ATCTests: public ::testing::Test {
protected:
    friend class ATC;

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};


#endif //PROJECTSE_ATCTESTS_H
