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
    EXPECT_TRUE(airport.getCallsign() == ""); 
    EXPECT_FALSE(airport.getCallsign() == "1");

    EXPECT_TRUE(airport.getName() == "");
    EXPECT_FALSE(airport.getName() == "fwfw");

    EXPECT_TRUE(airport.getCallsign() == "");
    EXPECT_FALSE(airport.getCallsign() == "ee");

    EXPECT_TRUE(airport.getIATA() == "");
    EXPECT_FALSE(airport.getIATA() == "x");

    Airport airport2;
    Runway r;
    r.setId(1);
    Airplane a;
    a.setId(1);
    Gate g;
    g.setId(1);

    EXPECT_TRUE(airport.addRunway(&r) == true);
    EXPECT_TRUE(airport.addGate(&g) == true);
    EXPECT_TRUE(airport.addAirplane(&a) == true);
  
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

    EXPECT_FALSE(airport.removeAirplane(22) == true);
    EXPECT_FALSE(airport.removeAirplane(-1) == true);
    EXPECT_TRUE(airport.removeAirplane(1) == true);

    EXPECT_FALSE(airport.removeRunway(2) == true);
    EXPECT_FALSE(airport.removeRunway(-1) == true);
    EXPECT_TRUE(airport.removeRunway(1) == true);
    
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
    EXPECT_FALSE(airport.getName() == "");
    EXPECT_FALSE(airport.getName() == "1");
    EXPECT_TRUE(airport.getName() == "name");
    
    airport.setIATA("IATA");
    EXPECT_FALSE(airport.getIATA() == "");
    EXPECT_FALSE(airport.getIATA() == "1");
    EXPECT_TRUE(airport.getIATA() == "IATA");
    
    airport.setCallsign("Callsign");
    EXPECT_FALSE(airport.getCallsign() == "");
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

TEST_F(AirportTests, AirportSimApproachTest){
    ofstream myFile;
    Airport ap;
    AirportExporter exporter(&ap, myFile);

    exporter.startOutput();
    Airplane plane;

    myFile.open("testOutput/AirportSimApproachTest1.txt");

    //When there is no free runway
    ap.doSimulationApproach(&exporter, &plane);
    EXPECT_TRUE(FileIsEmpty("testOutput/AirportSimApproachTest1.txt"));

    myFile.close();
    myFile.open("testOutput/AirportSimApproachTest2.txt");

    Runway r1;
    ap.addRunway(&r1);

    ap.doSimulationApproach(&exporter, &plane);
    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate1.txt", "testOutput/AirportSimApproachTest2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimApproachTest2.txt", "testOutput/AirportSimTemplate1.txt"));

    EXPECT_TRUE(plane.getHeight() == 10000);
    EXPECT_TRUE(plane.getStatus() == Airplane::LANDING);

    exporter.stopOutput();
    myFile.close();
}

TEST_F(AirportTests, AirportSimLandingTest){
    ofstream myFile;
    Airport ap;
    AirportExporter exporter(&ap, myFile);


    myFile.open("testOutput/AirportSimLandingTest1.txt");

    exporter.startOutput();
    Airplane plane;

    plane.setHeight(-10);
    ap.doSimulationLanding(&exporter, &plane);

    EXPECT_TRUE(plane.getStatus() == Airplane::LANDED);

    plane.setStatus(Airplane::LANDING);

    plane.setHeight(10000);
    ap.doSimulationLanding(&exporter, &plane);

    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate2.txt", "testOutput/AirportSimLandingTest1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimLandingTest1.txt", "testOutput/AirportSimTemplate2.txt"));

    EXPECT_TRUE(plane.getHeight() == 9000);

    exporter.stopOutput();
    myFile.close();

}

TEST_F(AirportTests, AirportSimLandedTest){
    ofstream myFile;
    Airport ap;
    Airplane plane;
    Gate g;
    Runway r;
    r.setName("Runway 1");


    ap.addRunway(&r);

    r.addAirplane(&plane);

    myFile.open("testOutput/AirportSimLandedTest1.txt");
    AirportExporter exporter(&ap, myFile);

    exporter.startOutput();

    ap.doSimulationLanded(&exporter, &plane);
    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate3.txt", "testOutput/AirportSimLandedTest1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimLandedTest1.txt", "testOutput/AirportSimTemplate3.txt"));

    //No free gate
    EXPECT_FALSE(plane.getStatus() == Airplane::TAXIING_TO_GATE);


    ap.addGate(&g);
    ap.doSimulationLanded(&exporter, &plane);

    //free gate
    EXPECT_TRUE(plane.getStatus() == Airplane::TAXIING_TO_GATE);

    exporter.stopOutput();
    myFile.close();
}

TEST_F(AirportTests, AirportSimTaxiingTest){
    ofstream myFile;
    Airport ap;
    ap.setName("my airport");
    Airplane plane;
    plane.setStatus(Airplane::TAXIING_TO_GATE);
    Gate g;
    g.setPlaneAtGate(&plane);
    ap.addGate(&g);
    g.setId(2);


    myFile.open("testOutput/AirportSimTaxiingTest1.txt");
    AirportExporter exporter(&ap, myFile);

    exporter.startOutput();

    ap.doSimulationTaxiing(&exporter, &plane);
    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate4.txt", "testOutput/AirportSimTaxiingTest1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimTaxiingTest1.txt", "testOutput/AirportSimTemplate4.txt"));


    exporter.stopOutput();
    myFile.close();
}

TEST_F(AirportTests, AirportSimAtGateTest){
    ofstream myFile;
    Airport ap;
    ap.setName("my airport");
    Airplane plane;
    plane.setAmountOfPassengers(20);
    plane.setStatus(Airplane::TAXIING_TO_GATE);
    plane.setCallsign("my plane");
    Gate g;
    g.setPlaneAtGate(&plane);
    g.setId(12);
    ap.addGate(&g);
    plane.setStatus(Airplane::AT_GATE);

    AirportExporter exporter(&ap, myFile);
    exporter.startOutput();

    myFile.open("testOutput/AirportSimAtGateTest1.txt");

    ap.doSimulationAtGate(&exporter, &plane);
    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate5.txt", "testOutput/AirportSimAtGateTest1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimAtGateTest1.txt", "testOutput/AirportSimTemplate5.txt"));

    EXPECT_TRUE(plane.getFuelState() == Airplane::FULL);
    EXPECT_TRUE(plane.getStatus() == Airplane::STANDING);

    exporter.stopOutput();
    myFile.close();
}

TEST_F(AirportTests, AirportSimStandingTest){
    ofstream myFile;
    Airport ap;
    ap.setName("my airport");
    Airplane plane;
    plane.setAmountOfPassengers(20);
    plane.setStatus(Airplane::TAXIING_TO_GATE);
    plane.setCallsign("my plane");
    Gate g;
    g.setPlaneAtGate(&plane);
    g.setId(12);
    ap.addGate(&g);
    plane.setStatus(Airplane::STANDING);

    AirportExporter exporter(&ap, myFile);
    exporter.startOutput();

    myFile.open("testOutput/AirportSimStandingTest1.txt");
    ap.doSimulationStanding(&exporter, &plane);

    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate6.txt", "testOutput/AirportSimStandingTest1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimStandingTest1.txt", "testOutput/AirportSimTemplate6.txt"));

    //no free runway
    EXPECT_FALSE(plane.getStatus() == Airplane::DEPARTING);

    Runway r1;
    ap.addRunway(&r1);

    ap.doSimulationStanding(&exporter, &plane);
    EXPECT_TRUE(plane.getStatus() == Airplane::DEPARTING);

    exporter.stopOutput();
    myFile.close();
}

TEST_F(AirportTests, AirportSimDepartingTest){
    ofstream myFile;
    Airport ap;
    ap.setName("my airport");
    Airplane plane;
    plane.setCallsign("my plane");
    Runway r1;
    r1.addAirplane(&plane);
    ap.addRunway(&r1);

    plane.setHeight(80);


    AirportExporter exporter(&ap, myFile);
    myFile.open("testOutput/AirportSimDepartingTest1.txt");
    exporter.startOutput();

    //Airplane is ascending
    ap.doSimulationDeparting(&exporter, &plane);

    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate7.txt", "testOutput/AirportSimDepartingTest1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimDepartingTest1.txt", "testOutput/AirportSimTemplate7.txt"));

    myFile.close();

    //Airplane leave airport
    myFile.open("testOutput/AirportSimDepartingTest2.txt");
    plane.setHeight(8958958);

    ap.doSimulationDeparting(&exporter, &plane);

    EXPECT_TRUE(FileCompare("testOutput/AirportSimTemplate8.txt", "testOutput/AirportSimDepartingTest2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportSimDepartingTest2.txt", "testOutput/AirportSimTemplate8.txt"));

    EXPECT_TRUE(plane.getStatus() == Airplane::IN_AIR);


    exporter.stopOutput();
    myFile.close();
}
