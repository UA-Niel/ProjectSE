#include "GateTests.h"
#include "../classes/Gate.h"
#include "../classes/Airplane.h"

TEST_F(GateTests, GateGetterTests){

    Gate gate;

    EXPECT_TRUE(gate.getPlaneAtGate() == NULL);
    EXPECT_FALSE(gate.getId() == 0);
    EXPECT_TRUE(gate.getId() == -1);
    EXPECT_FALSE(gate.getId() == 5);
    EXPECT_FALSE(gate.getId() == -10);

}


TEST_F(GateTests, GateSetterTests){

    Gate gate;
    gate.setId(12);
    EXPECT_FALSE(gate.getId() == -1);
    EXPECT_FALSE(gate.getId() == 7);
    EXPECT_TRUE(gate.getId() == 12);

    Airplane* plane = new Airplane();
    plane->setStatus(Airplane::TAXIING_TO_GATE);
    gate.setPlaneAtGate(plane);

    EXPECT_FALSE(gate.getPlaneAtGate() == NULL);
    EXPECT_TRUE(gate.getPlaneAtGate() == plane);

    delete plane;
    plane = NULL;

}


TEST_F(GateTests, GateClearGateTest){

    Gate gate;
    Airplane* plane = new Airplane();
    plane->setStatus(Airplane::TAXIING_TO_GATE);
    gate.setPlaneAtGate(plane);

    EXPECT_FALSE(gate.getPlaneAtGate() == NULL);

    gate.clearGate();

    EXPECT_TRUE(gate.getPlaneAtGate() == NULL);
    EXPECT_FALSE(gate.getPlaneAtGate() == plane);

    delete plane;
    plane = NULL;
}
