#include "ATCTests.h"
#include <iostream>
using namespace std;

TEST_F(ATCTests, ATC_ConstructorTest){
    Airport* p = new Airport();
    ATC atc("my callsign", p);
    EXPECT_FALSE(atc.getCallsign().empty());
    EXPECT_TRUE(atc.getCallsign() == "my callsign");
    EXPECT_TRUE(atc.properlyInitialized());

    delete p;
}

TEST_F(ATCTests, ATC_GetterTests){
    Airport* p = new Airport();
    ATC atc("my callsign", p);
    EXPECT_FALSE(atc.getCallsign().empty());
    EXPECT_TRUE(atc.getCallsign() == "my callsign");

    delete p;
}

TEST_F(ATCTests, ATC_SetterTests){
    Airport* p = new Airport();
    ATC atc("my callsign", p);
    atc.setCallsign("your callsign");
    EXPECT_FALSE(atc.getCallsign().empty());
    EXPECT_FALSE(atc.getCallsign() == "my callsign");
    EXPECT_TRUE(atc.getCallsign() == "your callsign");

    delete p;
}

TEST_F(ATCTests, ATC_AtcMessageTest){
    Airport* p = new Airport();
    ATC atc("my callsign", p);
    ApTime time(12,0);

    EXPECT_FALSE(atc.atcMessage(&time, "source", "message").empty());
    EXPECT_TRUE(atc.atcMessage(&time, "source", "message") == "[12:00] [source]\n$ message\n");

    delete p;
}

TEST_F(ATCTests, ATC_ComparisonTest){
    Airport* p = new Airport();
    ATC atc1("c", p);
    ATC atc2("c", p);
    ATC atc3("a", p);

    EXPECT_TRUE(atc1 == atc2);
    EXPECT_TRUE(atc2 == atc1);
    EXPECT_FALSE(atc1 == atc3);
    EXPECT_FALSE(atc3 == atc1);
    EXPECT_FALSE(atc2 == atc3);
    EXPECT_FALSE(atc3 == atc2);
    delete p;
}

TEST_F(ATCTests, ATC_GenerateNatoTest){
    vector<string>nato = ATC::generateNato();

    EXPECT_TRUE(nato.size() == 36);
    EXPECT_TRUE(nato[0] == "zero");
    EXPECT_TRUE(nato[9] == "nine");

    EXPECT_TRUE(nato[10] == "alpha");
    EXPECT_TRUE(nato[35] == "zulu");

}

TEST_F(ATCTests, ATC_intToNatoTest){
    EXPECT_TRUE(ATC::intToNato(0) == "zero");
    EXPECT_TRUE(ATC::intToNato(4) == "four");
    EXPECT_TRUE(ATC::intToNato(854) == "eight five four");
    EXPECT_TRUE(ATC::intToNato(15) == "one five");
    EXPECT_TRUE(ATC::intToNato(-5) == "minus five");
    EXPECT_TRUE(ATC::intToNato(-5002) == "minus five zero zero two");

}

TEST_F(ATCTests, ATC_charToNatoTest){
    EXPECT_TRUE(ATC::charToNato('A') == "alpha");
    EXPECT_TRUE(ATC::charToNato('a') == "alpha");
    EXPECT_TRUE(ATC::charToNato('Z') == "zulu");
    EXPECT_TRUE(ATC::charToNato('q') == "quebec");
}

TEST_F(ATCTests, ATC_stringToNatoTest){
    string str = "test 123";
    EXPECT_TRUE(ATC::stringToNato(str) == "test one two three");
}

TEST_F(ATCTests, ATC_landingInitialTest){
    Airport* p = new Airport();
    ATC atc("atc", p);
    EXPECT_FALSE(p->getWaitingPattern5000());
    EXPECT_TRUE(atc.landingInitial());
    EXPECT_TRUE(p->getWaitingPattern5000());
    delete p;
    p = new Airport();
    p->setWaitingPattern5000(false);
    EXPECT_TRUE(atc.landingInitial());
    EXPECT_TRUE(p->getWaitingPattern5000());
    delete p;
    p = new Airport();
    p->setWaitingPattern5000(true);
    EXPECT_FALSE(atc.landingInitial());
    EXPECT_TRUE(p->getWaitingPattern5000());
    delete p;
}

TEST_F(ATCTests, ATC_landingAt5000Test){
    Airport* p = new Airport();
    ATC atc("atc", p);
    EXPECT_FALSE(p->getWaitingPattern3000());
    EXPECT_TRUE(atc.landingAt5000());
    EXPECT_TRUE(p->getWaitingPattern3000());
    delete p;
    p = new Airport();
    p->setWaitingPattern3000(false);
    EXPECT_TRUE(atc.landingAt5000());
    EXPECT_TRUE(p->getWaitingPattern3000());
    delete p;
    p = new Airport();
    p->setWaitingPattern3000(true);
    EXPECT_FALSE(atc.landingAt5000());
    EXPECT_TRUE(p->getWaitingPattern3000());
    EXPECT_FALSE(p->getWaitingPattern5000());
    delete p;
}

TEST_F(ATCTests, ATC_landingAt3000Test){
    Airport p;
    ATC atc("atc", &p);
    Airplane plane;
    p.addAirplane(&plane);
    EXPECT_FALSE(atc.landingAt3000(&plane));

    Runway r;
    p.addRunway(&r);

    EXPECT_TRUE(atc.landingAt3000(&plane));
}

TEST_F(ATCTests, ATC_landingEndTest){
    Airport p;
    ATC atc("atc", &p);
    Airplane plane;
    Runway r;
    r.addAirplane(&plane);
    p.addRunway(&r);

    EXPECT_FALSE(atc.landingEnd(&plane));

    Gate gate;
    p.addGate(&gate);

    EXPECT_TRUE(atc.landingEnd(&plane));
    EXPECT_TRUE(plane.getStatus() == Airplane::TAXIING_TO_GATE);

}

TEST_F(ATCTests, ATC_departureOfGateTest){
    Airport p;
    ATC atc("atc", &p);
    EXPECT_TRUE(atc.departureOfGate());
}

TEST_F(ATCTests, ATC_departureWaitingAtRunway){
    Airport p;
    ATC atc("atc", &p);
    Gate g;
    p.addGate(&g);
    Airplane plane;
    plane.setStatus(Airplane::TAXIING_TO_GATE);
    g.setPlaneAtGate(&plane);

    EXPECT_FALSE(atc.departureWaitingAtRunway(&plane));

    Runway r;
    p.addRunway(&r);

    EXPECT_TRUE(atc.departureWaitingAtRunway(&plane));

}

TEST_F(ATCTests, ATC_departureWaitingOnRunwayTest){
    Airport p;
    ATC atc("atc", &p);
    EXPECT_TRUE(atc.departureWaitingOnRunway());
}

TEST_F(ATCTests, ATC_emergencyHigherThan3000Test){
    Airport p;
    ATC atc("atc", &p);
    Airplane plane;
    EXPECT_FALSE(atc.emergencyHigherThan3000(&plane));
    plane.setFuelState(Airplane::EMPTY);
    EXPECT_TRUE(atc.emergencyHigherThan3000(&plane));
}

TEST_F(ATCTests, ATC_emergencyLowerThan3000Test){
    Airport p;
    ATC atc("atc", &p);
    Airplane plane;
    EXPECT_FALSE(atc.emergencyHigherThan3000(&plane));
    plane.setFuelState(Airplane::EMPTY);
    EXPECT_TRUE(atc.emergencyHigherThan3000(&plane));
}