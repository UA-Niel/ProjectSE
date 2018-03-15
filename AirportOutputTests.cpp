#include <fstream>
#include "AirportOutputTests.h"
#include "utils.h"
#include "classes/AirportExporter.h"


void AirportOutputTests::setupAirport() {
    airport.setName("myAirport");
    airport.setId(12);
    airport.setIATA("MAP");
    airport.setCallsign("this is my Airport");
}


TEST_F(AirportOutputTests, FileCompare){
    ASSERT_TRUE(DirectoryExists("testOutput"));

    ofstream myFile;
    myFile.open("testOutput/fileCompare1.txt");
    myFile.close();
    myFile.open("testOutput/fileCompare2.txt");
    myFile.close();

    EXPECT_TRUE(FileExists("testOutput/fileCompare1.txt"));
    EXPECT_TRUE(FileExists("testOutput/fileCompare2.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/fileCompare1.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/fileCompare2.txt"));

    //Comparison of two empty files
    //EXPECT_TRUE(FileCompare("testOutput/fileCompare1.txt", "testOutput/fileCompare2.txt"));
    //EXPECT_TRUE(FileCompare("testOutput/fileCompare2.txt", "testOutput/fileCompare1.txt"));

    //Comparison of empty with non empty file
    myFile.open("testOutput/fileCompare3.txt");
    myFile << "123456";
    myFile.close();
    EXPECT_TRUE(FileExists("testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileIsEmpty("testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileCompare("testOutput/fileCompare1.txt", "testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileCompare("testOutput/fileCompare3.txt", "testOutput/fileCompare1.txt"));

    //Comparison of two equal files
    myFile.open("testOutput/fileCompare4.txt");
    myFile << "123456";
    myFile.close();
    EXPECT_TRUE(FileExists("testOutput/fileCompare4.txt"));
    EXPECT_FALSE(FileIsEmpty("testOutput/fileCompare3.txt"));
    EXPECT_TRUE(FileCompare("testOutput/fileCompare3.txt", "testOutput/fileCompare4.txt"));

    //Comparison of two non-equal files with content
    myFile.open("testOutput/fileCompare5.txt");
    myFile << "123456" << endl << "abcdfg" << endl;
    myFile.close();
    EXPECT_TRUE(FileExists("testOutput/fileCompare5.txt"));
    EXPECT_FALSE(FileIsEmpty("testOutput/fileCompare5.txt"));
    EXPECT_FALSE(FileCompare("testOutput/fileCompare4.txt", "testOutput/fileCompare5.txt"));

    //Comparison of an existing and non-existing file
    EXPECT_FALSE(FileCompare("testOutput/fileCompare4.txt", "testOutput/nonExisting.txt"));
    EXPECT_FALSE(FileCompare("testOutput/nonExisting.txt", "testOutput/fileCompare4.txt"));
}

TEST_F(AirportOutputTests, OutputStartStopFunctions){
    setupAirport();
    ofstream myFile;

    AirportExporter airportExporter(myFile);
    airportExporter.set_airport(&airport);

    //Try stopping output before starting the output
    EXPECT_DEATH(airportExporter.stopOutput(), "StartOutput has to be true before it can be stopped");

    //Try outputting before start method
    EXPECT_DEATH(airportExporter.outputAirportDetails(), "AirportExporter output is not started, "
            "use the method startOutput first");
}

TEST_F(AirportOutputTests, AirplaneDetailsOutput){
    //Nr of output files: 3
    //Used templates: 1-3

    setupAirport();
    ofstream myFile;

    AirportExporter airportExporter(myFile);

    airportExporter.set_airport(&airport);

    myFile.open("testOutput/AirplaneDetailsOutput1.txt");

    //when there are no planes:
    airportExporter.startOutput();
    airportExporter.outputPlaneDetails();
    //TODO: EXPECT_FALSE(FileIsEmpty("testOutput/AirplaneDetailsOutput1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirplaneDetailsOutput1.txt", "testOutput/outputTemplate1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/outputTemplate1.txt", "testOutput/AirplaneDetailsOutput1.txt"));
    airportExporter.stopOutput();

    //when there is one plane
    Airplane plane1(1, "my callsign 1", "my model 1", 0);
    plane1.setNumber("my number 1");
    airport.addAirplane(&plane1);

    myFile.close();

    myFile.open("testOutput/AirplaneDetailsOutput2.txt");

    airportExporter.startOutput();
    airportExporter.outputPlaneDetails();
    EXPECT_TRUE(FileCompare("testOutput/outputTemplate2.txt",
                            "testOutput/AirplaneDetailsOutput2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirplaneDetailsOutput2.txt",
                            "testOutput/outputTemplate2.txt"));

    myFile.close();

    //when there are 3 planes
    myFile.open("testOutput/AirplaneDetailsOutput3.txt");
    Airplane plane2(2, "my callsign 2", "my model 2", 0); plane1.setNumber("my number 2");
    Airplane plane3(3, "my callsign 3", "my model 3", 0); plane1.setNumber("my number 3");
    airport.addAirplane(&plane2); airport.addAirplane(&plane3);

    airportExporter.outputPlaneDetails();

    EXPECT_TRUE(FileCompare("testOutput/outputTemplate3.txt",
                            "testOutput/AirplaneDetailsOutput3.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirplaneDetailsOutput3.txt",
                            "testOutput/outputTemplate3.txt"));
    airportExporter.stopOutput();
    myFile.close();

}

TEST_F(AirportOutputTests, AirportDetailsOutput){
    setupAirport();
    ofstream myFile;

    myFile.open("testOutput/AirportDetailsOutput1.txt");
    AirportExporter airportExporter(myFile);

    //Try writing while no airport is assigned to output
    airportExporter.startOutput();
    EXPECT_DEATH(airportExporter.outputAirportDetails(), "AirportExporter did not find the airport, "
            "is it initalized correctly?");
    airportExporter.stopOutput();

    //set airport
    airportExporter.set_airport(&airport);

    //Test for Airport details
    airportExporter.startOutput();
    airportExporter.outputAirportDetails();
    //TODO: EXPECT_FALSE(FileIsEmpty("testOutput/AirportDetailsOutput1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/outputTemplate4.txt", "testOutput/AirportDetailsOutput1.txt"));
    EXPECT_TRUE(FileCompare("testOutput/AirportDetailsOutput1.txt", "testOutput/outputTemplate4.txt"));

    airportExporter.stopOutput();
    myFile.close();
}