#include <fstream>
#include "AirportOutputTests.h"
#include "../../headers/utils.h"


void AirportOutputTests::setupAirport() {
    airport.setName("myAirport");
    airport.setId(12);
    airport.setIATA("MAP");
    airport.setCallsign("this is my Airport");
}


TEST_F(AirportOutputTests, FileCompare){
    ASSERT_TRUE(DirectoryExists("other/testOutput"));

    ofstream myFile;
    myFile.open("other/testOutput/fileCompare1.txt");
    myFile.close();
    myFile.open("other/testOutput/fileCompare2.txt");
    myFile.close();

    EXPECT_TRUE(FileExists("other/testOutput/fileCompare1.txt"));
    EXPECT_TRUE(FileExists("other/testOutput/fileCompare2.txt"));
    EXPECT_TRUE(FileIsEmpty("other/testOutput/fileCompare1.txt"));
    EXPECT_TRUE(FileIsEmpty("other/testOutput/fileCompare2.txt"));

    //Comparison of two empty files
    EXPECT_TRUE(FileCompare("other/testOutput/fileCompare1.txt", "other/testOutput/fileCompare2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/fileCompare2.txt", "other/testOutput/fileCompare1.txt"));

    //Comparison of empty with non empty file
    myFile.open("other/testOutput/fileCompare3.txt");
    myFile << "123456";
    myFile.close();
    EXPECT_TRUE(FileExists("other/testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileIsEmpty("other/testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileCompare("other/testOutput/fileCompare1.txt", "other/testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileCompare("other/testOutput/fileCompare3.txt", "other/testOutput/fileCompare1.txt"));

    //Comparison of two equal files
    myFile.open("other/testOutput/fileCompare4.txt");
    myFile << "123456";
    myFile.close();
    EXPECT_TRUE(FileExists("other/testOutput/fileCompare4.txt"));
    EXPECT_FALSE(FileIsEmpty("other/testOutput/fileCompare3.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/fileCompare3.txt", "other/testOutput/fileCompare4.txt"));

    //Comparison of two non-equal files with content
    myFile.open("other/testOutput/fileCompare5.txt");
    myFile << "123456" << endl << "abcdfg" << endl;
    myFile.close();
    EXPECT_TRUE(FileExists("other/testOutput/fileCompare5.txt"));
    EXPECT_FALSE(FileIsEmpty("other/testOutput/fileCompare5.txt"));
    EXPECT_FALSE(FileCompare("other/testOutput/fileCompare4.txt", "other/testOutput/fileCompare5.txt"));

    //Comparison of an existing and non-existing file
    EXPECT_FALSE(FileCompare("other/testOutput/fileCompare4.txt", "other/testOutput/nonExisting.txt"));
    EXPECT_FALSE(FileCompare("other/testOutput/nonExisting.txt", "other/testOutput/fileCompare4.txt"));
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
    myFile.close();
}

TEST_F(AirportOutputTests, AirplaneDetailsOutput){
    //Nr of output files: 3
    //Used templates: 1-3

    setupAirport();
    ofstream myFile;

    AirportExporter airportExporter(myFile);

    airportExporter.set_airport(&airport);

    myFile.open("other/testOutput/AirplaneDetailsOutput1.txt");

    //when there are no planes:
    airportExporter.startOutput();
    airportExporter.outputPlaneDetails();
    EXPECT_FALSE(FileIsEmpty("other/testOutput/AirplaneDetailsOutput1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/AirplaneDetailsOutput1.txt", "other/testOutput/outputTemplate1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/outputTemplate1.txt", "other/testOutput/AirplaneDetailsOutput1.txt"));
    airportExporter.stopOutput();

    //when there is one plane
    Airplane plane1(1, "my callsign 1", "my model 1", Airplane::STANDING, "my number 1");
    plane1.setEngine(Airplane::PROPELLOR);
    plane1.setSize(Airplane::MEDIUM);
    plane1.setType(Airplane::JET_FIGHTER);
    airport.addAirplane(&plane1);

    myFile.close();

    myFile.open("other/testOutput/AirplaneDetailsOutput2.txt");

    airportExporter.startOutput();
    airportExporter.outputPlaneDetails();
    myFile.close();
    EXPECT_TRUE(FileCompare("other/testOutput/outputTemplate2.txt",
                            "other/testOutput/AirplaneDetailsOutput2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/AirplaneDetailsOutput2.txt",
                            "other/testOutput/outputTemplate2.txt"));



    //when there are 3 planes
    myFile.open("other/testOutput/AirplaneDetailsOutput3.txt");
    Airplane plane2(2, "my callsign 2", "my model 2", Airplane::STANDING, "my number 2");
    Airplane plane3(3, "my callsign 3", "my model 3", Airplane::STANDING, "my number 3");

    plane2.setEngine(Airplane::GLIDER);
    plane2.setSize(Airplane::SMALL);
    plane2.setType(Airplane::ALASKAN);
    plane3.setEngine(Airplane::JET);
    plane3.setSize(Airplane::LARGE);
    plane3.setType(Airplane::PRIVATE);

    airport.addAirplane(&plane2); airport.addAirplane(&plane3);

    airportExporter.outputPlaneDetails();
    myFile.close();

    EXPECT_TRUE(FileCompare("other/testOutput/outputTemplate3.txt",
                            "other/testOutput/AirplaneDetailsOutput3.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/AirplaneDetailsOutput3.txt",
                            "other/testOutput/outputTemplate3.txt"));


    airportExporter.stopOutput();


}

TEST_F(AirportOutputTests, AirportDetailsOutput){
    setupAirport();
    ofstream myFile;

    myFile.open("other/testOutput/AirportDetailsOutput1.txt");
    AirportExporter airportExporter(myFile);

    //Try writing while no airport is assigned to output
    airportExporter.startOutput();
    EXPECT_DEATH(airportExporter.outputAirportDetails(), "AirportExporter did not find the airport, "
            "is it initialized correctly?");
    airportExporter.stopOutput();

    //set airport
    airportExporter.set_airport(&airport);

    //Test for Airport details
    airportExporter.startOutput();
    airportExporter.outputAirportDetails();
    EXPECT_FALSE(FileIsEmpty("other/testOutput/AirportDetailsOutput1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/outputTemplate4.txt", "other/testOutput/AirportDetailsOutput1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/AirportDetailsOutput1.txt", "other/testOutput/outputTemplate4.txt"));

    airportExporter.stopOutput();
    myFile.close();
}

TEST_F(AirportOutputTests, OutputStringTests){
    ofstream myFile;
    myFile.open("other/testOutput/outputString1.txt");
    AirportExporter airportExporter(myFile);

    airportExporter.startOutput();
    airportExporter.outputString("Test, Test \n\t Test");

    EXPECT_FALSE(FileIsEmpty("other/testOutput/outputString1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/outputTemplate5.txt", "other/testOutput/outputString1.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/outputString1.txt", "other/testOutput/outputTemplate5.txt"));

    myFile.close();

    myFile.open("testOutput/outputString2.txt");
    airportExporter.outputString("");
    EXPECT_TRUE(FileIsEmpty("other/testOutput/testOutput/outputString2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/outputTemplate6.txt", "other/testOutput/outputString2.txt"));
    EXPECT_TRUE(FileCompare("other/testOutput/outputString2.txt", "other/testOutput/outputTemplate6.txt"));

    airportExporter.stopOutput();
    myFile.close();
}

TEST_F(AirportOutputTests, ExporterComparisonTest){
    ofstream myFile;
    Airport ap;
    AirportExporter exp(myFile);
    AirportExporter exp2(myFile);
    AirportExporter exp3(&ap, myFile);
    AirportExporter exp4(&ap, myFile);

    EXPECT_TRUE(exp == exp2);
    EXPECT_FALSE(exp == exp3);
    EXPECT_FALSE(exp == exp4);
    EXPECT_TRUE(exp2 == exp);
    EXPECT_FALSE(exp3 == exp);
    EXPECT_FALSE(exp4 == exp);
    EXPECT_TRUE(exp3 == exp4);
    EXPECT_TRUE(exp4 == exp3);

}
