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
    Simulator sim(exporter, airport, time, atc);

    EXPECT_TRUE(sim.getAirport() == airport);
    EXPECT_TRUE(sim.getAtc() == atc);
    EXPECT_TRUE(sim.getExporter() == exporter);
    EXPECT_TRUE(sim.getTime() == time);

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

    Simulator simulator(exporter, airport, time, atc);
    simulator.setAirport(airport1);
    //simulator.setAtc(atc1);
    //simulator.setTime(time1);

    /*EXPECT_FALSE(simulator.getAtc() == atc);
    EXPECT_FALSE(simulator.getAirport() == airport);
    EXPECT_FALSE(simulator.getTime() == time);
    EXPECT_TRUE(simulator.getAtc() == atc1);
    EXPECT_TRUE(simulator.getAirport() == airport1);
    EXPECT_TRUE(simulator.getTime() == time1);*/
}

TEST_F(SimulatorTests, SimulatorApproachTest){
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
