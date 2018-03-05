//Header file for Runway

#ifndef RUNWAY_H
#define RUNWAY_H

#include <string>
#include <vector>
#include "Airplane.h"
using namespace std;

class Runway {
public:
    bool properlyInitialized() const;

    //Add airplane to runway, return true on success
    /**
     * REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @param airplane: Airplane which needs to be added
     * @return: true on success
     */
    bool addAirplane(Airplane* airplane);

    //Accessors and mutator:
    /**
     * REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @param id: new runway ID
     */
    void setId(int id);

    /**
     * REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @param name: new name
     */
    void setName(const string& name);

    /**
     * REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @param airportId: new Airport ID
     */
    void setAirport(int airportId);

    /**
     * REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @return id
     */
    int getId() const;

    /**
     * REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @return name of the runway
     */
    string& getName() const;

    /**
     * REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @return
     */
    int getAirport() const;

    //Constructor
    /**
     * ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
     * @param runwayId: id of runway
     * @param _name: name of runway
     * @param airplanesOnRunway: planes on runway
     */
    Runway(int runwayId, const string &_name, const vector<Airplane*> &airplanesOnRunway);

    /**
     * ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    Runway();

private:
    int _runwayId;   //PRIMARY_KEY
    string _name;
    vector<Airplane*> _airplanesOnRunway;
    Runway* _initCheck;
};

#endif
