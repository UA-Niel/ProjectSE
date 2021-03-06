#include "AirplaneTests.h"
#include "../../headers/Airplane.h"
#include "../../headers/Airport.h"


TEST_F(AirplaneTests, AirplaneGetterTests){

    Airplane airplane;

    EXPECT_FALSE(airplane.getId() == 0);
    EXPECT_FALSE(airplane.getId() == -5);
    EXPECT_FALSE(airplane.getId() == 5);
    EXPECT_TRUE(airplane.getId() == -1);

    EXPECT_FALSE(airplane.getAmountOfPassengers() == 5);
    EXPECT_FALSE(airplane.getAmountOfPassengers() < 0);
    EXPECT_TRUE(airplane.getAmountOfPassengers() == 0);

    EXPECT_FALSE(airplane.getStatus() == Airplane::TAXIING_TO_GATE);
    EXPECT_FALSE(airplane.getStatus() == Airplane::APPROACHING);
    EXPECT_FALSE(airplane.getStatus() == Airplane::LANDED);
    EXPECT_FALSE(airplane.getStatus() == Airplane::IN_AIR);
    EXPECT_FALSE(airplane.getStatus() == Airplane::AT_GATE);
    EXPECT_FALSE(airplane.getStatus() == Airplane::STANDING);
    EXPECT_FALSE(airplane.getStatus() == Airplane::LANDING);
    EXPECT_FALSE(airplane.getStatus() == Airplane::DEPARTING);
    EXPECT_TRUE(airplane.getStatus() == Airplane::UNKNOWN);

    EXPECT_FALSE(airplane.getFuelState() == Airplane::EMPTY);
    EXPECT_FALSE(airplane.getFuelState() == Airplane::WARNING);
    EXPECT_FALSE(airplane.getFuelState() == Airplane::OKAY);
    EXPECT_TRUE(airplane.getFuelState() == Airplane::FULL);

    EXPECT_FALSE(airplane.getHeight() == 10000);
    EXPECT_FALSE(airplane.getHeight() < 0);
    EXPECT_TRUE(airplane.getHeight() == 0);

    EXPECT_FALSE(airplane.getCallsign() == "callsign");
    EXPECT_TRUE(airplane.getCallsign().empty());

    EXPECT_FALSE(airplane.getModel() == "model");
    EXPECT_TRUE(airplane.getModel().empty());

    EXPECT_FALSE(airplane.getNumber() == "number");
    EXPECT_TRUE(airplane.getNumber().empty());

    EXPECT_TRUE(airplane.getType() == Airplane::AIRLINE);
    EXPECT_FALSE(airplane.getType() == Airplane::PRIVATE);

    EXPECT_TRUE(airplane.getEngine() == Airplane::JET);
    EXPECT_FALSE(airplane.getEngine() == Airplane::PROPELLOR);

    Airplane airplane2(3, "callsign", "model", Airplane::IN_AIR, "number");
    airplane2.setEngine("PROPELLOR");
    airplane2.setType("PRIVATE");

    EXPECT_FALSE(airplane2.getId() == -1);
    EXPECT_FALSE(airplane2.getId() == 0);
    EXPECT_FALSE(airplane2.getId() == -5);
    EXPECT_FALSE(airplane2.getId() == 5);
    EXPECT_TRUE(airplane2.getId() == 3);

    EXPECT_FALSE(airplane2.getStatus() == Airplane::TAXIING_TO_GATE);
    EXPECT_FALSE(airplane2.getStatus() == Airplane::APPROACHING);
    EXPECT_FALSE(airplane2.getStatus() == Airplane::LANDED);
    EXPECT_TRUE(airplane2.getStatus() == Airplane::IN_AIR);
    EXPECT_FALSE(airplane2.getStatus() == Airplane::AT_GATE);
    EXPECT_FALSE(airplane2.getStatus() == Airplane::STANDING);
    EXPECT_FALSE(airplane2.getStatus() == Airplane::LANDING);
    EXPECT_FALSE(airplane2.getStatus() == Airplane::DEPARTING);
    EXPECT_FALSE(airplane2.getStatus() == Airplane::UNKNOWN);

    EXPECT_TRUE(airplane2.getCallsign() == "callsign");
    EXPECT_FALSE(airplane2.getCallsign().empty());

    EXPECT_TRUE(airplane2.getModel() == "model");
    EXPECT_FALSE(airplane2.getModel().empty());

    EXPECT_TRUE(airplane2.getNumber() == "number");
    EXPECT_FALSE(airplane2.getNumber().empty());

    EXPECT_TRUE(airplane2.getEngine() == Airplane::PROPELLOR);
    EXPECT_FALSE(airplane2.getEngine() == Airplane::JET);

    EXPECT_TRUE(airplane2.getType() == Airplane::PRIVATE);
    EXPECT_FALSE(airplane2.getType() == Airplane::AIRLINE);
}

TEST_F(AirplaneTests, AirplaneSetterTests){

    Airplane airplane(3, "callsign", "model", Airplane::IN_AIR, "number");

    airplane.setStatus(Airplane::DEPARTING);
    EXPECT_FALSE(airplane.getStatus() == Airplane::IN_AIR);
    EXPECT_FALSE(airplane.getStatus() == Airplane::UNKNOWN);
    EXPECT_TRUE(airplane.getStatus() == Airplane::DEPARTING);

    airplane.setId(12);
    EXPECT_FALSE(airplane.getId() == 3);
    EXPECT_FALSE(airplane.getId() <= 0);
    EXPECT_FALSE(airplane.getId() == 80);
    EXPECT_TRUE(airplane.getId() == 12);

    airplane.setAmountOfPassengers(80);
    EXPECT_FALSE(airplane.getAmountOfPassengers() <= 0);
    EXPECT_FALSE(airplane.getAmountOfPassengers() == 5);
    EXPECT_TRUE(airplane.getAmountOfPassengers() == 80);

    airplane.setCallsign("sign");
    EXPECT_FALSE(airplane.getCallsign().empty());
    EXPECT_FALSE(airplane.getCallsign() == "callsign");
    EXPECT_TRUE(airplane.getCallsign() == "sign");

    airplane.setFuelState(Airplane::OKAY);
    EXPECT_FALSE(airplane.getFuelState() == Airplane::FULL);
    EXPECT_TRUE(airplane.getFuelState() == Airplane::OKAY);

    airplane.setHeight(10000);
    EXPECT_FALSE(airplane.getHeight() <= 0);
    EXPECT_FALSE(airplane.getHeight() == 5000);
    EXPECT_TRUE(airplane.getHeight() == 10000);

    airplane.setModel("mod");
    EXPECT_FALSE(airplane.getModel().empty());
    EXPECT_FALSE(airplane.getModel() == "model");
    EXPECT_TRUE(airplane.getModel() == "mod");

    airplane.setNumber("num");
    EXPECT_FALSE(airplane.getNumber().empty());
    EXPECT_FALSE(airplane.getNumber() == "number");
    EXPECT_TRUE(airplane.getNumber() == "num");

    airplane.setEngine("jet");
    EXPECT_TRUE(airplane.getEngine() == Airplane::JET);
    EXPECT_FALSE(airplane.getEngine() == Airplane::PROPELLOR);

    airplane.setEngine(Airplane::PROPELLOR);
    EXPECT_FALSE(airplane.getEngine() == Airplane::JET);
    EXPECT_TRUE(airplane.getEngine() == Airplane::PROPELLOR);

    airplane.setType("private");
    EXPECT_TRUE(airplane.getType() == Airplane::PRIVATE);
    EXPECT_FALSE(airplane.getType() == Airplane::AIRLINE);

    airplane.setType(Airplane::AIRLINE);
    EXPECT_FALSE(airplane.getType() == Airplane::PRIVATE);
    EXPECT_TRUE(airplane.getType() == Airplane::AIRLINE);

    airplane.setFlightPlan("DEST", 1, 2, 3);
    EXPECT_TRUE(airplane.getFlightPlan()->destination == "DEST");
    EXPECT_FALSE(airplane.getFlightPlan()->destination == "");
    EXPECT_TRUE(airplane.getFlightPlan()->departure == 1);
    EXPECT_TRUE(airplane.getFlightPlan()->arrival == 2);
    EXPECT_TRUE(airplane.getFlightPlan()->interval == 3);
    EXPECT_FALSE(airplane.getFlightPlan()->departure == 0);
    EXPECT_FALSE(airplane.getFlightPlan()->arrival == 0);
    EXPECT_FALSE(airplane.getFlightPlan()->interval == 0);
}

TEST_F(AirplaneTests, AirportChecks){

    Airport ap;
    Airport ap2;

    Runway r1;
    Runway r2;

    ap.addRunway(&r1);
    ap.addRunway(&r2);

    Gate g1;
    Gate g2;

    ap.addGate(&g1);
    ap.addGate(&g2);

    Airplane airplane;

    EXPECT_TRUE(airplane.checkFreeGate(&ap2) == NULL);
    EXPECT_TRUE(airplane.checkFreeRunway(&ap2) == NULL);

    EXPECT_FALSE(airplane.checkFreeGate(&ap) == NULL);
    EXPECT_FALSE(airplane.checkFreeRunway(&ap) == NULL);


}

TEST_F(AirplaneTests, AirplaneApproach){

    Airplane airplane;

    EXPECT_DEATH(airplane.approach(), "Airplane must be in LANDING status before it can approach");

    airplane.setStatus(Airplane::LANDING);

    EXPECT_DEATH(airplane.approach(-10), "You can only approach by a positive amount of feet");

    EXPECT_TRUE(airplane.getHeight() == 0);

    airplane.setHeight(10000);

    airplane.approach();
    EXPECT_TRUE(airplane.getHeight() == 9000);

    airplane.approach(500);
    EXPECT_TRUE(airplane.getHeight() == 8500);
    EXPECT_FALSE(airplane.getHeight() == 8000);


}

TEST_F(AirplaneTests, AirplaneAscend){

    Airplane airplane;

    EXPECT_TRUE(airplane.getHeight() == 0);

    airplane.ascend();

    EXPECT_FALSE(airplane.getHeight() == 0);
    EXPECT_TRUE(airplane.getHeight() == 1000);

    airplane.ascend(21);

    EXPECT_FALSE(airplane.getHeight() == 2000);
    EXPECT_FALSE(airplane.getHeight() == 1000);
    EXPECT_TRUE(airplane.getHeight() == 1021);


}
TEST_F (AirplaneTests, Validation) {
    Airplane airplane;
    airplane.setType("PRIVATE");
    airplane.setSize("SMALL");
    airplane.setEngine("JET");
    EXPECT_TRUE(airplane.isValid());
    EXPECT_FALSE(!airplane.isValid());

    Airplane airplane2;
    airplane2.setType("PRIVATE");
    airplane2.setSize("LARGE");
    airplane2.setEngine("JET");
    EXPECT_TRUE(!airplane2.isValid());
    EXPECT_FALSE(airplane2.isValid());
    
    Airplane airplane3;
    airplane3.setType("AIRLINE");
    airplane3.setSize("LARGE");
    airplane3.setEngine("JET");
    EXPECT_TRUE(airplane3.isValid());
    EXPECT_FALSE(!airplane3.isValid());
    
    Airplane airplane4;
    airplane4.setType("EMERGENCY");
    airplane4.setSize("SMALL");
    airplane4.setEngine("JET");
    EXPECT_TRUE(!airplane4.isValid());
    EXPECT_FALSE(airplane4.isValid());
    
}
