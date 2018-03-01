//Header file for Runway

#ifndef RUNWAY_H
#define RUNWAY_H

#include <string>
#include <vector>

#include "Airport.h"
#include "Airplane.h"
using namespace std;

class Runway {
public:

    bool properlyInitialized() const;

    //Add airplane to runway, return true on success
    bool addAirplane(Airplane& airplane);

    //Accessors and mutators
    void setId(int id);
    void setName(const string& name);
    void setAirport(int airportId);
    int getId() const;
    string& getName() const;
    int getAirport() const;

    //Constructor
    Runway(int runwayId, const string &_name, const vector<int> &airplanesOnRunway);
    Runway();

private:
    int runwayId;   //PRIMARY_KEY
    string _name;
    vector<int> airplanesOnRunway;
    Runway* _initCheck;
};

#endif
