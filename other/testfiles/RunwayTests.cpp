#include "RunwayTests.h"

TEST_F(RunwayTests, RunwayGetterTests){

    //Runway constructed with default constructor
    Runway runway;


    EXPECT_TRUE(runway.getId() == 0);
    EXPECT_FALSE(runway.getId() == 158);
    EXPECT_FALSE(runway.getId() == -50);
    EXPECT_TRUE(runway.getName().empty());
    EXPECT_TRUE(runway.getAirplanesOnRunway().empty());
    EXPECT_TRUE(runway.getAirport() == 0);
    EXPECT_FALSE(runway.getAirport() == -7);
    EXPECT_TRUE(runway.getType() == Runway::UNKNOWN);
    EXPECT_FALSE(runway.getType() == Runway::ASPHALT);
    EXPECT_TRUE(runway.getLength() == 0);
    EXPECT_FALSE(runway.getLength() == -1);
    EXPECT_TRUE(runway.getTaxiRoute().size() == 0);
    EXPECT_FALSE(runway.getTaxiRoute().size() == 1);
    

    //Runway constructed with other constructor
    Airplane* testPlane = new Airplane();
    vector<Airplane*>planes;
    planes.push_back(testPlane);
    Runway runway2(5, "My very first runway!", planes);
    runway2.setType(Runway::GRASS);
    runway2.setLength(500);
    runway2.addToTaxiRoute("Alpha");

    EXPECT_TRUE(runway2.getId() == 5);
    EXPECT_FALSE(runway2.getId() == 158);
    EXPECT_FALSE(runway2.getId() == -5);
    EXPECT_FALSE(runway2.getId() == -897);

    EXPECT_FALSE(runway2.getName().empty());
    EXPECT_TRUE(runway2.getName() == "My very first runway!");
    EXPECT_FALSE(runway2.getName() == "A runway somewhere else");

    EXPECT_FALSE(runway2.getAirplanesOnRunway().empty());
    EXPECT_FALSE(runway2.getAirplanesOnRunway().size() == 8);
    EXPECT_TRUE(runway2.getAirplanesOnRunway().size() == 1);

    EXPECT_TRUE(runway2.getType() == Runway::GRASS);
    EXPECT_FALSE(runway2.getType() == Runway::ASPHALT);
    EXPECT_FALSE(runway2.getType() == Runway::UNKNOWN);

    EXPECT_TRUE(runway2.getLength() == 500);
    EXPECT_FALSE(runway2.getLength() == 0);
    
    EXPECT_TRUE(runway2.getTaxiRoute().size() == 1);
    EXPECT_FALSE(runway2.getTaxiRoute().size() == 0);

    EXPECT_TRUE(runway2.getTaxiRoute(0) == "Alpha");
    EXPECT_FALSE(runway2.getTaxiRoute(0) == "");

    //vs memory leaks
    delete testPlane;
    testPlane = NULL;
}


TEST_F(RunwayTests, RunwaySetterTests){

    //Tests with default constructor
    Runway runway;
    runway.setId(7);

    EXPECT_TRUE(runway.getId() == 7);
    EXPECT_FALSE(runway.getId() == 0);

    runway.setName("Runway");

    EXPECT_FALSE(runway.getName().empty());
    EXPECT_FALSE(runway.getName() == "f");
    EXPECT_TRUE(runway.getName() == "Runway");

    runway.setAirport(5);
    EXPECT_TRUE(runway.getAirport() == 5);
    EXPECT_FALSE(runway.getAirport() == 0);

    runway.setLength(750);
    EXPECT_TRUE(runway.getLength() == 750);
    EXPECT_FALSE(runway.getLength() == 0);
    
    runway.setType("asphalt");
    EXPECT_TRUE(runway.getType() == Runway::ASPHALT);
    EXPECT_FALSE(runway.getLength() == Runway::GRASS);

    runway.setType(Runway::GRASS);
    EXPECT_FALSE(runway.getType() == Runway::ASPHALT);
    EXPECT_TRUE(runway.getType() == Runway::GRASS);

    runway.addToTaxiRoute("Alpha");
    runway.addToTaxiRoute("Beta");
    EXPECT_TRUE(runway.getTaxiRoute(0) == "Alpha");
    EXPECT_TRUE(runway.getTaxiRoute(1) == "Beta");
    EXPECT_FALSE(runway.getTaxiRoute(1) == "Alpha");
    EXPECT_FALSE(runway.getTaxiRoute(0) == "Beta");
    EXPECT_TRUE(runway.getTaxiRoute().size() == 2);
    EXPECT_FALSE(runway.getTaxiRoute().size() == 0);
    EXPECT_FALSE(runway.getTaxiRoute().size() == 1);

    //Tests with other constructor
    vector<Airplane*>testVec;
    Runway runway2(10, "A runway out of 1000", testVec);
    runway2.setId(3);

    EXPECT_FALSE(runway2.getId() == 10);
    EXPECT_TRUE(runway2.getId() == 3);

    runway2.setName("Runway!");

    EXPECT_FALSE(runway2.getName() == "A runway out of 1000");
    EXPECT_TRUE(runway2.getName() == "Runway!");

}

TEST_F(RunwayTests, RunwayFunctionTests){

    Runway runway;

    EXPECT_TRUE(runway.getAirplanesOnRunway().empty());
    EXPECT_FALSE(runway.getAirplanesOnRunway().size() == 1);

    Airplane* plane = new Airplane();
    runway.addAirplane(plane);

    EXPECT_FALSE(runway.getAirplanesOnRunway().empty());
    EXPECT_TRUE(runway.getAirplanesOnRunway().size() == 1);

    runway.clearRunway();

    EXPECT_TRUE(runway.getAirplanesOnRunway().empty());
    EXPECT_FALSE(runway.getAirplanesOnRunway().size() == 1);

    delete plane;
    plane = NULL;

}
