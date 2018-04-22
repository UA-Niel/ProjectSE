#include "ReaderTest.h"
#include "../../headers/Airport.h"
#include "../../headers/Runway.h"
#include "../../headers/Gate.h"

TEST_F(ReaderTests, testingInput) {
    Airport* testAirport = loadAirportFromFile("testfiles/testinput.xml");

    EXPECT_TRUE(testAirport->getName() == "name");
    
    EXPECT_TRUE(testAirport->getName() == "name");
    EXPECT_FALSE(testAirport->getName() == "");

    EXPECT_TRUE(testAirport->getIATA() == "IATA");
    EXPECT_FALSE(testAirport->getIATA() == "");

    EXPECT_TRUE(testAirport->getCallsign() == "callsign");
    EXPECT_FALSE(testAirport->getCallsign() == "");

    Runway* r = testAirport->getRunway(0);

    EXPECT_TRUE(r->getName() == "name");
    EXPECT_FALSE(r->getName() == "");
    
    EXPECT_TRUE(r->getAirport() == 1);
    EXPECT_FALSE(r->getAirport() == 0);
    EXPECT_FALSE(r->getAirport() == -1);


    Airplane* a = testAirport->getAirplane(0);

    EXPECT_TRUE(a->getNumber() == "number");
    EXPECT_FALSE(a->getNumber() == "");

    EXPECT_FALSE(a->getAmountOfPassengers() == 0);
    EXPECT_TRUE(a->getAmountOfPassengers() == 20);

    EXPECT_TRUE(a->getCallsign() == "callsign");
    EXPECT_FALSE(a->getCallsign() == "");

    EXPECT_TRUE(a->getModel() == "model");
    EXPECT_FALSE(a->getModel() == "");

    EXPECT_TRUE(a->getStatus() == Airplane::APPROACHING);
    EXPECT_FALSE(a->getStatus() == Airplane::UNKNOWN);
}

