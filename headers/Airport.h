//Header file for Airport-class

#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>

#include "Airplane.h"
#include "Runway.h"
#include "Gate.h"

using namespace std;

//TODO: add "REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly")" in comments

class Airport {
public:
    //Adding objects to Airport, return true on success
    bool addAirplane(Airplane& airplane);
    bool addRunway(Runway& runway);
    bool addGate(Gate& gate);
    //Removing objects of Airport, return true on success
    bool removeAirplane(int id);
    bool removeRunway(int id);
    bool removeGate(int id);

    bool properlyInitialized() const;

    //Accessors and mutators
    Airplane& getAirplane(int id) const;
    Runway& getRunway(int id) const;
    Gate& getGate(int id) const;
    void setId(int id);
    void setName(string name);
    void setIATA(string IATA);
    void setCallsign(string callsign);
    int getId() const;
    const string& getName() const;
    const string& getIATA() const;
    const string& getCallsign() const;

    //Constructors
    Airport();
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
