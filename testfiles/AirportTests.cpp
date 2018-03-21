#include "AirportTests.cpp"
#include "../classes/Airport.h"
#include "../classes/Runway.h"
#include "../classes/Gate.h"

TEST_F(AirportTests, AirportGetterTests) {
    Airport airport;

    EXPECT_TRUE(airport.getId() == -1);
    EXPECT_FALSE(airport.getId() == 0);
    EXPECT_FALSE(airport.getId() == -2);
    EXPECT_FALSE(airport.getId() == 2);

    EXPECT_FALSE(airport.getCallsign() == "x");
    EXPECT_TRUE(airport.getCallsign() == ""); 
    EXPECT_FALSE(airport.getCallsign() == "1");

    EXPECT_TRUE(airport.getName() == "")
    EXPECT_FALSE(airport.getName() == "fwfw");

    EXPECT_TRUE(airport.getCallsign() == "");
    EXPECT_FALSE(airport.getCallsign() == "ee");

    EXPECT_TRUE(airport.getIATA() == "");
    EXPECT_FALSE(airport.getIATA() == "");

    Airport airport2;
    Runway r;
    r.setId(1);
    Airplane a;
    a.setId(1);
    Gate g;
    g.setId(1);
    EXPECT_TRUE(airport.addRunway(&r) == true);
    EXPECT_FALSE(airport.addRunway(&g) == true);

    EXPECT_TRUE(airport.addGate(&g) == true);
    
    EXPECT_TRUE(airport.addAirplane(&a) == true);
    EXPECT_FALSE(airport.addAirplane(&g) == true);
  
    EXPECT_TRUE(airport.getNrOfGates() == 1)
    EXPECT_FALSE(airport.getNrOfGates() == -1);
    EXPECT_FALSE(airport.getNrOfGates() == 2);

    EXPECT_TRUE(airport.getNrOfRunways() == 1)
    EXPECT_FALSE(airport.getNrOfRunways() == -1);
    EXPECT_FALSE(airport.getNrOfRunways() == 2); 

    EXPECT_TRUE(airport.getAirplane(1) == &a);
    EXPECT_TRUE(airport.getRunway(1) == &r);
    EXPECT_TRUE(airport.getGate(1) == &g);

    EXPECT_FALSE(airport.removeAirplane(22) == true);
    EXPECT_FALSE(airport.removeAirplane(-1) == true);
    EXPECT_TRUE(airport.removeAirplane(1)) == true;

    EXPECT_FALSE(airport.removeRunway(2) == true);
    EXPECT_FALSE(airport.removeRunway(-1) == true);
    EXPECT_TRUE(airport.removeRunway(1) == true);
    
    EXPECT_TRUE(airport.getNrOfRunways() == 0);
    EXPECT_TRUE(airport.getNrOfGates() == 0);


}

TEST_F(AirportTests, AirportSetterTests) {
    Airport airport;
    airport.setId(2);
    EXPECT_FALSE(airport.getId() == 0);
    EXPECT_FALSE(airport.getId() == 1);
    EXPECT_TRUE(airport.getId() == 2);
    EXPECT_FALSE(airport.getId() == 3);

    airport.setName("name");
    EXPECT_FALSE(airport.getName() == "");
    EXPECT_FALSE(airport.getName() == "1");
    EXPECT_TRUE(airport.getName() == "name");
    
    airport.setIATA("IATA");
    EXPECT_FALSE(airport.getIATA() == "");
    EXPECT_FALSE(airport.getIATA() == "1");
    EXPECT_TRUE(airport.getIATA() == "name");
    
    airport.setCallsign("Callsign");
    EXPECT_FALSE(airport.getCallsign() == "");
    EXPECT_FALSE(airport.getCallsign() == "1");
    EXPECT_TRUE(airport.getCallsign() == "Callsign");
    

}
