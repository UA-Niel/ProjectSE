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

    Airplane airplane2(3, "callsign", "model", Airplane::IN_AIR, "number");

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
