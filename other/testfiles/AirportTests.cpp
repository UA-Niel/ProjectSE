#include <fstream>
#include "AirportTests.h"
#include "../../headers/Airport.h"
#include "../../headers/Runway.h"
#include "../../headers/Gate.h"
#include "../../headers/utils.h"

TEST_F(AirportTests, AirportGetterTests) {
    Airport airport;

    EXPECT_TRUE(airport.getId() == -1);
    EXPECT_FALSE(airport.getId() == 0);
    EXPECT_FALSE(airport.getId() == -2);
    EXPECT_FALSE(airport.getId() == 2);

    EXPECT_FALSE(airport.getCallsign() == "x");
    EXPECT_TRUE(airport.getCallsign().empty());
    EXPECT_FALSE(airport.getCallsign() == "1");

    EXPECT_TRUE(airport.getName().empty());
    EXPECT_FALSE(airport.getName() == "fwfw");

    EXPECT_TRUE(airport.getCallsign().empty());
    EXPECT_FALSE(airport.getCallsign() == "ee");

    EXPECT_TRUE(airport.getIATA().empty());
    EXPECT_FALSE(airport.getIATA() == "x");

    Airport airport2;
    Runway r;
    r.setId(1);
    Airplane a;
    a.setId(1);
    Gate g;
    g.setId(1);

    EXPECT_TRUE(airport.addRunway(&r));
    EXPECT_TRUE(airport.addGate(&g));
    EXPECT_TRUE(airport.addAirplane(&a));
  
    EXPECT_TRUE(airport.getNrOfGates() == 1);
    EXPECT_FALSE(airport.getNrOfGates() == 0);
    EXPECT_FALSE(airport.getNrOfGates() == 2);

    EXPECT_TRUE(airport.getNrOfRunways() == 1);
    EXPECT_FALSE(airport.getNrOfRunways() == 0);
    EXPECT_FALSE(airport.getNrOfRunways() == 2); 

    EXPECT_TRUE(airport.getAirplane(1) == &a);
    EXPECT_TRUE(airport.getRunway(1) == &r);
    EXPECT_TRUE(airport.getGate(1) == &g);

    EXPECT_TRUE(airport.getAirplanes().size() == 1);
    EXPECT_FALSE(airport.getAirplanes().empty());

    EXPECT_FALSE(airport.removeAirplane(22));
    EXPECT_FALSE(airport.removeAirplane(-1));
    EXPECT_TRUE(airport.removeAirplane(1));

    EXPECT_FALSE(airport.removeRunway(2));
    EXPECT_FALSE(airport.removeRunway(-1));
    EXPECT_TRUE(airport.removeRunway(1));
    
    EXPECT_TRUE(airport.getNrOfRunways() == 0);
    EXPECT_TRUE(airport.getNrOfGates() == 1);
    EXPECT_TRUE(airport.getAllGates().size() == 1);

    EXPECT_FALSE(airport.removeGate(12));
    EXPECT_TRUE(airport.removeGate(1));


}

TEST_F(AirportTests, AirportSetterTests) {
    Airport airport;
    airport.setId(2);
    EXPECT_FALSE(airport.getId() == 0);
    EXPECT_FALSE(airport.getId() == 1);
    EXPECT_TRUE(airport.getId() == 2);
    EXPECT_FALSE(airport.getId() == 3);

    airport.setName("name");
    EXPECT_FALSE(airport.getName().empty());
    EXPECT_FALSE(airport.getName() == "1");
    EXPECT_TRUE(airport.getName() == "name");
    
    airport.setIATA("IATA");
    EXPECT_FALSE(airport.getIATA().empty());
    EXPECT_FALSE(airport.getIATA() == "1");
    EXPECT_TRUE(airport.getIATA() == "IATA");
    
    airport.setCallsign("Callsign");
    EXPECT_FALSE(airport.getCallsign().empty());
    EXPECT_FALSE(airport.getCallsign() == "1");
    EXPECT_TRUE(airport.getCallsign() == "Callsign");

}

TEST_F(AirportTests, AirportGetWithPlaneTests){
    Airplane plane1;
    Airplane plane2;
    plane1.setId(1);
    plane2.setId(2);
    plane1.setStatus(Airplane::TAXIING_TO_GATE);
    plane2.setStatus(Airplane::TAXIING_TO_GATE);

    Gate g1;
    g1.setId(1);
    Gate g2;
    g2.setId(2);

    Runway r1;
    r1.setId(1);
    Runway r2;
    r2.setId(2);

    Airport ap;

    EXPECT_TRUE(ap.getFreeGate() == NULL);
    EXPECT_TRUE(ap.getGateWithPlane(&plane1) == NULL);
    EXPECT_TRUE(ap.getRunwayWithPlane(&plane1) == NULL);

    ap.addGate(&g1);
    ap.addGate(&g2);
    ap.addRunway(&r1);
    ap.addRunway(&r2);

    EXPECT_TRUE(ap.getFreeGate() != NULL);

    g1.setPlaneAtGate(&plane1);
    g2.setPlaneAtGate(&plane2);

    EXPECT_TRUE(ap.getGateWithPlane(&plane1) == &g1);
    EXPECT_TRUE(ap.getGateWithPlane(&plane2) == &g2);

    EXPECT_TRUE(ap.getFreeGate() == NULL);

    r1.addAirplane(&plane1);
    r2.addAirplane(&plane2);

    EXPECT_TRUE(ap.getRunwayWithPlane(&plane1) == &r1);
    EXPECT_TRUE(ap.getRunwayWithPlane(&plane2) == &r2);

    r1.clearRunway();
    g1.clearGate();

    EXPECT_FALSE(ap.getFreeGate() == NULL);
    EXPECT_TRUE(ap.getGateWithPlane(&plane1) == NULL);
    EXPECT_TRUE(ap.getFreeGate() == &g1);
}
