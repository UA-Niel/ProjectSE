#include "ATCTests.h"
#include <iostream>
using namespace std;

TEST_F(ATCTests, ATC_ConstructorTest){
    ATC atc("my callsign");
    EXPECT_FALSE(atc.getCallsign().empty());
    EXPECT_TRUE(atc.getCallsign() == "my callsign");
    EXPECT_TRUE(atc.properlyInitialized());
}

TEST_F(ATCTests, ATC_GetterTests){
    ATC atc("my callsign");
    EXPECT_FALSE(atc.getCallsign().empty());
    EXPECT_TRUE(atc.getCallsign() == "my callsign");
}

TEST_F(ATCTests, ATC_SetterTests){
    ATC atc("my callsign");
    atc.setCallsign("your callsign");
    EXPECT_FALSE(atc.getCallsign().empty());
    EXPECT_FALSE(atc.getCallsign() == "my callsign");
    EXPECT_TRUE(atc.getCallsign() == "your callsign");
}

TEST_F(ATCTests, ATC_AtcMessageTest){
    ATC atc("my callsign");
    ApTime time(12,0);

    EXPECT_FALSE(atc.atcMessage(&time, "source", "message").empty());
    EXPECT_TRUE(atc.atcMessage(&time, "source", "message") == "[12:00] [source]\n$ message\n");
}

TEST_F(ATCTests, ATC_ComparisonTest){
    ATC atc1("c");
    ATC atc2("c");
    ATC atc3("a");

    EXPECT_TRUE(atc1 == atc2);
    EXPECT_TRUE(atc2 == atc1);
    EXPECT_FALSE(atc1 == atc3);
    EXPECT_FALSE(atc3 == atc1);
    EXPECT_FALSE(atc2 == atc3);
    EXPECT_FALSE(atc3 == atc2);
}