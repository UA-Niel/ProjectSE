#include "SimulatorTests.h"
#include "../../headers/utils.h"
#include <iostream>
#include <fstream>

using namespace std;

TEST_F(SimulatorTests, SimulatorGetterTests){

    Airport airport;
    airport.setName("airport");
    ofstream file1, file2;
    AirportExporter exporter(&airport, file1);
    ApTime time(12,00);
    ATC atc("atc");
    Simulator sim(exporter, &airport, &time, &atc);

    EXPECT_TRUE(sim.getAirport() == &airport);
    EXPECT_TRUE(sim.getAtc() == &atc);
    EXPECT_TRUE(sim.getExporter() == exporter);
    EXPECT_TRUE(sim.getTime() == &time);

}

TEST_F(SimulatorTests, SimulatorSetterTests){
    Airport airport;
    Airport airport1;
    airport1.setName("airport");
    airport.setName("ap");

    ofstream file1, file2;
    AirportExporter exporter(&airport, file1);
    ApTime time(12,00);
    ApTime time1(13,00);

    ATC atc("atc");
    ATC atc1("atc1");

    Simulator simulator(exporter, &airport, &time, &atc);
    simulator.setAirport(&airport1);
    simulator.setAtc(&atc1);
    simulator.setTime(&time1);

    EXPECT_FALSE(simulator.getAtc() == &atc);
    EXPECT_FALSE(simulator.getAirport() == &airport);
    EXPECT_FALSE(simulator.getTime() == &time);
    EXPECT_TRUE(simulator.getAtc() == &atc1);
    EXPECT_TRUE(simulator.getAirport() == &airport1);
    EXPECT_TRUE(simulator.getTime() == &time1);
}

TEST_F(SimulatorTests, SimulatorApproachTest){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));

    ofstream myFile("other/testOutput/SimulatorApproach1.txt");
    ofstream commFile("other/testOutput/SimulatorApproachCommunication1.txt");
    Airplane plane;
    plane.setCallsign("plane");
    plane.setStatus(Airplane::APPROACHING);
    Airport ap;
    ap.setName("airport");
    ApTime time(12,00);
    ATC atc("atc");

    AirportExporter exporter(myFile);
    exporter.startOutput();

    Simulator sim(exporter, &ap, &time, &atc);
    sim.set_communicationOutput(true);
    sim.doSimulationApproach(&plane, commFile);
    myFile.close();
    commFile.close();

    EXPECT_FALSE(FileIsEmpty("other/testOutput/SimulatorApproach1.txt"));
    EXPECT_FALSE(FileIsEmpty("other/testOutput/SimulatorApproachCommunication1.txt"));

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorApproach1.txt",
                            "other/testOutput/SimulatorApproachTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorApproachCommunication1.txt",
                            "other/testOutput/SimulatorApproachCommunicationTemplate1.txt"));
}

TEST_F(SimulatorTests, SimulatorLandingTest){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));
    ofstream myFile("other/testOutput/SimulatorLanding1.txt");
    ofstream commFile("other/testOutput/SimulatorLandingCommunication1.txt");
    Airplane plane;
    plane.setHeight(-10);
    plane.setCallsign("plane");
    plane.setStatus(Airplane::LANDING);
    Airport ap;
    ap.setName("airport");
    ApTime time(12,00);
    ATC atc("atc");
    AirportExporter exporter(myFile);
    exporter.startOutput();
    Simulator sim(exporter, &ap, &time, &atc);
    sim.set_communicationOutput(true);
    sim.doSimulationLanding(&plane, commFile);
    EXPECT_TRUE(plane.getStatus() == Airplane::LANDED);
    EXPECT_TRUE(plane.getHeight() == -10);
    time.setHour(12);
    time.setMinutes(0);
    plane.setStatus(Airplane::LANDING);
    plane.setHeight(10000);

    //Approach 10000-5000
    sim.doSimulationLanding(&plane, commFile);
    EXPECT_TRUE(plane.getHeight() == 9000);
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLanding1.txt",
                            "other/testOutput/SimulatorLandingTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandingTemplate1.txt",
                            "other/testOutput/SimulatorLanding1.txt"));
    time.setHour(12);
    time.setMinutes(0);

    //Approach 5000
    myFile.open("other/testOutput/SimulatorLanding2.txt");
    plane.setHeight(5000);
    sim.doSimulationLanding(&plane, commFile);
    EXPECT_TRUE(plane.getHeight() == 4000);
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLanding2.txt",
                            "other/testOutput/SimulatorLandingTemplate2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandingTemplate2.txt",
                            "other/testOutput/SimulatorLanding2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandingCommunication1.txt",
                            "other/testOutput/SimulatorLandingCommunicationTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandingCommunicationTemplate1.txt",
                            "other/testOutput/SimulatorLandingCommunication1.txt"));
    time.setHour(12);
    time.setMinutes(0);

    //Approach 3000 (no runway)
    plane.setHeight(3000);
    EXPECT_TRUE(plane.getHeight() == 3000);
    EXPECT_FALSE(plane.getHeight() == 2000);
    time.setHour(12);
    time.setMinutes(0);

    //Approach 3000 (runway)
    Runway r;
    r.setName("runway");
    ap.addRunway(&r);
    myFile.open("other/testOutput/SimulatorLanding3.txt");
    commFile.open("other/testOutput/SimulatorLandingCommunication2.txt");
    plane.setHeight(3000);

    sim.doSimulationLanding(&plane, commFile);
    EXPECT_TRUE(plane.getHeight() == 2000);
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLanding3.txt",
                            "other/testOutput/SimulatorLandingTemplate3.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandingTemplate3.txt",
                            "other/testOutput/SimulatorLanding3.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandingCommunication2.txt",
                            "other/testOutput/SimulatorLandingCommunicationTemplate2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandingCommunicationTemplate2.txt",
                            "other/testOutput/SimulatorLandingCommunication2.txt"));
    myFile.close();
    commFile.close();
    exporter.stopOutput();
}

TEST_F(SimulatorTests, SimulatorLandedTest){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));

    Airplane plane;
    plane.setCallsign("plane");
    plane.setStatus(Airplane::LANDED);
    Airport ap;
    Runway r;
    r.addAirplane(&plane);
    r.setName("runway");
    ap.addRunway(&r);
    ap.setName("airport");
    ofstream myFile("other/testOutput/SimulatorLanded1.txt");
    ofstream commFile("other/testOutput/SimulatorLandedCommunication1.txt");
    AirportExporter exporter(myFile);
    exporter.startOutput();
    ApTime time(12,00);
    ATC atc("Dirk");
    Simulator sim(exporter, &ap, &time, &atc);
    sim.set_communicationOutput(true);
    sim.doSimulationLanded(&plane, commFile);

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLanded1.txt",
                            "other/testOutput/SimulatorLandedTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandedTemplate1.txt",
                            "other/testOutput/SimulatorLanded1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandedCommunication1.txt",
                            "other/testOutput/SimulatorLandedCommunicationTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorLandedCommunicationTemplate1.txt",
                            "other/testOutput/SimulatorLandedCommunication1.txt"));

    myFile.close();
    commFile.close();
    exporter.stopOutput();

    EXPECT_TRUE(plane.getStatus() == Airplane::TAXIING_TO_GATE);
}

TEST_F(SimulatorTests, SimulatorTaxiingTest){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));

    ofstream myFile("other/testOutput/SimulatorTaxiing1.txt");
    ofstream commFile("other/testOutput/SimulatorTaxiingCommunication1.txt");

    Airplane plane;
    plane.setCallsign("plane");
    plane.setStatus(Airplane::TAXIING_TO_GATE);
    Airport ap;
    Gate g;
    g.setPlaneAtGate(&plane);
    g.setId(2);
    ap.addGate(&g);
    ap.setName("airport");
    ApTime time(12,00);
    ATC atc("atc");

    AirportExporter exporter(myFile);
    exporter.startOutput();

    Simulator sim(exporter, &ap, &time, &atc);
    sim.set_communicationOutput(true);
    sim.doSimulationTaxiing(&plane, commFile);

    myFile.close();
    commFile.close();
    exporter.stopOutput();

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorTaxiing1.txt",
                            "other/testOutput/SimulatorTaxiingTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorTaxiingTemplate1.txt",
                            "other/testOutput/SimulatorTaxiing1.txt"));

    EXPECT_TRUE(plane.getStatus() == Airplane::AT_GATE);

}

TEST_F(SimulatorTests, SimulatorAtGateTest){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));

    ofstream myFile("other/testOutput/SimulatorAtGate1.txt");
    ofstream commFile("other/testOutput/SimulatorAtGateCommunication1.txt");

    Airplane plane;
    plane.setAmountOfPassengers(21);
    plane.setCallsign("plane");
    plane.setStatus(Airplane::TAXIING_TO_GATE);
    Airport ap;
    Gate g;
    g.setPlaneAtGate(&plane);
    plane.setStatus(Airplane::AT_GATE);
    g.setId(2);
    ap.addGate(&g);
    ap.setName("airport");
    ApTime time(12,00);
    ATC atc("atc");

    AirportExporter exporter(myFile);
    exporter.startOutput();

    Simulator sim(exporter, &ap, &time, &atc);
    sim.set_communicationOutput(true);
    sim.doSimulationAtGate(&plane, commFile);

    myFile.close();
    commFile.close();
    exporter.stopOutput();

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorAtGate1.txt",
                            "other/testOutput/SimulatorAtGateTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorAtGateTemplate1.txt",
                            "other/testOutput/SimulatorAtGate1.txt"));

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorAtGateCommunication1.txt",
                            "other/testOutput/SimulatorAtGateCommunicationTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorAtGateCommunicationTemplate1.txt",
                            "other/testOutput/SimulatorAtGateCommunication1.txt"));

    EXPECT_TRUE(plane.getStatus() == Airplane::STANDING);
}

TEST_F(SimulatorTests, SimulatorStandingTest){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));

    ofstream myFile("other/testOutput/SimulatorStanding1.txt");
    ofstream commFile("other/testOutput/SimulatorStandingCommunication1.txt");

    //When there is no free runway:
    Airplane plane;
    plane.setAmountOfPassengers(21);
    plane.setCallsign("plane");
    plane.setStatus(Airplane::TAXIING_TO_GATE);
    Airport ap;
    Gate g;
    g.setPlaneAtGate(&plane);
    plane.setStatus(Airplane::STANDING);
    g.setId(21);
    ap.addGate(&g);
    ap.setName("airport");
    ApTime time(12,00);
    ATC atc("atc");

    AirportExporter exporter(myFile);
    exporter.startOutput();

    Simulator sim(exporter, &ap, &time, &atc);
    sim.set_communicationOutput(true);
    sim.doSimulationStanding(&plane, commFile);

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStanding1.txt",
                            "other/testOutput/SimulatorStandingTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStandingTemplate1.txt",
                            "other/testOutput/SimulatorStanding1.txt"));

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStandingCommunication1.txt",
                            "other/testOutput/SimulatorStandingCommunicationTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStandingCommunicationTemplate1.txt",
                            "other/testOutput/SimulatorStandingCommunication1.txt"));

    //When there is a free runway:
    commFile.open("other/testOutput/SimulatorStandingCommunication1.txt");
    myFile.open("other/testOutput/SimulatorStanding2.txt");
    Runway r;
    r.setName("runway");
    ap.addRunway(&r);
    ap.setName("airport");

    sim.set_communicationOutput(true);
    sim.doSimulationStanding(&plane, commFile);

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStanding2.txt",
                            "other/testOutput/SimulatorStandingTemplate2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStandingTemplate2.txt",
                            "other/testOutput/SimulatorStanding2.txt"));

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStandingCommunication2.txt",
                            "other/testOutput/SimulatorStandingCommunicationTemplate2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorStandingCommunicationTemplate2.txt",
                            "other/testOutput/SimulatorStandingCommunication2.txt"));

    myFile.close();
    commFile.close();
    exporter.stopOutput();
    EXPECT_TRUE(plane.getStatus() == Airplane::DEPARTING);

}

TEST_F(SimulatorTests, SimulatorDepartingTest){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));

    ofstream myFile("other/testOutput/SimulatorDeparting1.txt");
    ofstream commFile("");

    //Plane height < 5000
    Airplane plane;
    plane.setHeight(0);
    plane.setCallsign("plane");
    plane.setStatus(Airplane::DEPARTING);
    Airport ap;
    Runway r;
    r.setName("runway");
    r.addAirplane(&plane);
    ap.addRunway(&r);
    ap.setName("airport");
    ApTime time(12,00);
    ATC atc("atc");

    AirportExporter exporter(myFile);
    exporter.startOutput();

    Simulator sim(exporter, &ap, &time, &atc);
    sim.doSimulationDeparting(&plane, commFile);
    EXPECT_FALSE(plane.getStatus() == Airplane::IN_AIR);
    EXPECT_TRUE(plane.getStatus() == Airplane::DEPARTING);

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorDeparting1.txt",
                            "other/testOutput/SimulatorDepartingTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorDepartingTemplate1.txt",
                            "other/testOutput/SimulatorDeparting1.txt"));


    //Plane height >= 5000
    myFile.open("other/testOutput/SimulatorDeparting2.txt");
    plane.setHeight(5000);
    sim.doSimulationDeparting(&plane, commFile);

    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorDeparting2.txt",
                            "other/testOutput/SimulatorDepartingTemplate2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/SimulatorDepartingTemplate2.txt",
                            "other/testOutput/SimulatorDeparting2.txt"));

    myFile.close();
    commFile.close();
    exporter.stopOutput();

    EXPECT_TRUE(r.getAirplanesOnRunway().empty());
    EXPECT_TRUE(plane.getStatus() == Airplane::IN_AIR);

}