#include "ReaderTest.h"
#include "../../headers/Airport.h"
#include "../../headers/Runway.h"
#include "../../headers/Gate.h"
#include "../../headers/Exceptions.h"

TEST_F(ReaderTests, testingInput) {
    ////////////////////////////////////////////
    Airport* testAirport = loadAirportFromFile("other/testfiles/testinput2.xml");

    EXPECT_TRUE(testAirport->getName() == "name");
    
    EXPECT_TRUE(testAirport->getName() == "name");
    EXPECT_FALSE(testAirport->getName() == "");

    EXPECT_TRUE(testAirport->getIATA() == "IATA");
    EXPECT_FALSE(testAirport->getIATA() == "");

    EXPECT_TRUE(testAirport->getCallsign() == "callsign");
    EXPECT_FALSE(testAirport->getCallsign() == "");

    ////////////////////////////////////////////
    Runway* r = testAirport->getRunway(0);

    EXPECT_TRUE(r->getName() == "name");
    EXPECT_FALSE(r->getName() == "");
    
    EXPECT_TRUE(r->getAirport() == 1);
    EXPECT_FALSE(r->getAirport() == 0);
    EXPECT_FALSE(r->getAirport() == -1);

    EXPECT_TRUE(r->getType() == Runway::ASPHALT);
    EXPECT_FALSE(r->getType() == Runway::UNKNOWN);
    
    EXPECT_TRUE(r->getLength() == 1000);
    EXPECT_FALSE(r->getLength() == 0);

    EXPECT_TRUE(r->getTaxiRoute(0) == "Alpha");
    EXPECT_FALSE(r->getTaxiRoute(0) == "");

    ////////////////////////////////////////////
    Airplane* a = testAirport->getAirplane(0);

    EXPECT_TRUE(a->getNumber() == "number");
    EXPECT_FALSE(a->getNumber() == "");

    EXPECT_FALSE(a->getAmountOfPassengers() == 0);
    EXPECT_TRUE(a->getAmountOfPassengers() == 20);

    EXPECT_TRUE(a->getCallsign() == "callsign");
    EXPECT_FALSE(a->getCallsign() == "");

    EXPECT_TRUE(a->getModel() == "model");
    EXPECT_FALSE(a->getModel() == "");

    EXPECT_TRUE(a->getType() == Airplane::AIRLINE);
    EXPECT_FALSE(a->getType() == Airplane::PRIVATE);

    EXPECT_TRUE(a->getSize() == Airplane::LARGE);
    EXPECT_FALSE(a->getSize() == Airplane::SMALL);
 
    EXPECT_TRUE(a->getEngine() == Airplane::JET);
    EXPECT_FALSE(a->getEngine() == Airplane::PROPELLOR);

    EXPECT_TRUE(a->getStatus() == Airplane::APPROACHING);
    EXPECT_FALSE(a->getStatus() == Airplane::UNKNOWN);

    EXPECT_TRUE(a->getFlightPlan()->destination == "LCY");    
    EXPECT_FALSE(a->getFlightPlan()->destination == "");
 
    EXPECT_TRUE(a->getFlightPlan()->departure == 15);    
    EXPECT_FALSE(a->getFlightPlan()->departure == 0);

    EXPECT_TRUE(a->getFlightPlan()->arrival == 45);    
    EXPECT_FALSE(a->getFlightPlan()->arrival == 0);
    
    EXPECT_TRUE(a->getFlightPlan()->interval == 1);    
    EXPECT_FALSE(a->getFlightPlan()->interval == 0);

}

TEST_F(ReaderTests, what) {
    try {
        loadAirportFromFile("other/testfiles/testinput3.xml");
    } catch(ReaderException& e) {
        EXPECT_STREQ(e.what(), "Reader Exception:\n\twhat(): Error reading end tag.\n");
    }
}
