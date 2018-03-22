#include "ReaderTest.h"
#include "../classes/Airport.h"
#include "../classes/Runway.h"
#include "../classes/Gate.h"

TEST_F(ReaderTest, testingInput) {
    Airport* testAirport = loadAirportFromFile("testinput.xml");
    
    EXPECT_TRUE(testAirport.getName() == "name");
    EXPECT_FALSE(testAirport.getName() == "");

    EXPECT_TRUE(testAirport.getIATA() == "IATA");
    EXPECT_FALSE(testAirport.getIATA() == "");

    EXPECT_TRUE(testAirport.getCallsign() == "callsign");
    EXPECT_FALSE(testAirport.getCallsign() == "");

    EXPECT_TRUE(testAirport.getNumber() == "number");
    EXPECT_FALSE(testAirport.getNumber() == "");

    Runway* r = airport.getRunway(1);

    EXPECT_TRUE(r.getName() == "name");
    EXPECT_FALSE(r.getName() == "");
    
    EXPECT_TRUE(r.getAirport() == 1);
    EXPECT_FALSE(r.getAirport() == 0);
    EXPECT_FALSE(r.getAirport() == -1);


    Airplane* a = airport.getAirplane(1);

    EXPECT_TRUE(a.getNumber() == "number");
    EXPECT_FALSE(a.getNumber() == "");

    EXPECT_TRUE(a.getCallsign() == "callsign");
    EXPECT_FALSE(a.getCallsign() == "");

    EXPECT_TRUE(a.getModel() == "model");
    EXPECT_FALSE(a.getModel() == "");

    EXPECT_TRUE(a.getStatus() == Airplane::Status::APPROACHING);
    EXPECT_FALSE(a.getStatus() == Airplane::Status::UNKNOWN);
}

