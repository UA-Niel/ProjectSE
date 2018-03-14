#include <fstream>
#include "AirportOutputTests.h"
#include "utils.h"
#include "classes/AirportExporter.h"

TEST_F(AirportOutputTests, FileCompare){
    ASSERT_TRUE(DirectoryExists("testOutput"));

    ofstream myFile;
    myFile.open("testOutput/fileComparetest1.txt");
    myFile.close();
    myFile.open("testOutput/fileComparetest2.txt");
    myFile.close();

    EXPECT_TRUE(FileExists("testOutput/fileCompare1.txt"));
    EXPECT_TRUE(FileExists("testOutput/fileCompare2.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/fileCompare1.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/fileCompare2.txt"));

    //Comparison of two empty files
    EXPECT_TRUE(FileCompare("testOutput/file1.txt", "testOutput/file2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/file2.txt", "testOutput/file1.txt"));

    //Comparison of empty with non empty file
    myFile.open("testOutput/fileCompare3.txt");
    myFile << "123456" << endl << "abcdefg" << endl;
    myFile.close();
    EXPECT_TRUE(FileExists("testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileIsEmpty("testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileCompare("testOutput/fileCompare1.txt", "testOutput/fileCompare3.txt"));
    EXPECT_FALSE(FileCompare("testOutput/fileCompare3.txt", "testOutput/fileCompare1.txt"));

    //Comparison of two equal files
    myFile.open("testOutput/fileCompare4.txt");
    myFile << "123456" << endl << "abcdefg" << endl;
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

TEST_F(AirportOutputTests, BasicOutputTest){
    airport.setName("myAirport");
    airport.setId(12);
    airport.setIATA("MAP");
    airport.setCallsign("this is my Airport");
    ofstream myFile("testOutput/BasicOutputTest1.txt");
    AirportExporter airportExporter(&airport);
    airportExporter.outputAirportDetails(myFile);
}