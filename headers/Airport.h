//Header file for Airport-class

#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>

#include "Airplane.h"
#include "Runway.h"
#include "Gate.h"

using namespace std;

class Airport {
public:

    //properly initialized method
    bool properlyInitialized() const;

    //Adding objects to Airport, return true on success
    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    bool addAirplane(Airplane& airplane);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    bool addRunway(Runway& runway);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    bool addGate(Gate& gate);

    //Removing objects of Airport, return true on success
    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    bool removeAirplane(int id);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    bool removeRunway(int id);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    bool removeGate(int id);

    //Accessors and mutators
    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    Airplane& getAirplane(int id) const;

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    Runway& getRunway(int id) const;

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    Gate& getGate(int id) const;

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    void setId(int id);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    void setName(string name);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    void setIATA(string IATA);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    void setCallsign(string callsign);

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    int getId() const;

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    const string& getName() const;

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    const string& getIATA() const;

    //REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")
    const string& getCallsign() const;

    //Constructors
    //ENSURE(this->properlyInitialized(), "Airport is not initialized correctly")
    Airport();

    //ENSURE(this->properlyInitialized(), "Airport is not initialized correctly")
    Airport(const vector<Runway> &_runways, const vector<Gate> &_gates, int _airportId, const string &_name,
            const string &_IATA, const string &_callsign);


private:
    //All airplanes on the airport
    vector<Airplane> _airplanesOnAirport;
    //Runways of the airport
    vector<Runway> _runways;
    //Gates of the airport
    vector<Gate> _gates;
    //Other properties
    int _airportId; //PRIMARY_KEY
    string _name;
    string _IATA;
    string _callsign;
    //Init check:
    Airport* _initCheck;
};

#endif //AIRPORT_H
