//Header file for Runway

#ifndef RUNWAY_H
#define RUNWAY_H

#include <string>
#include <vector>

#include "Airport.h"
#include "Airplane.h"

class Runway {
    public:
        //Add airplane to runway, return true on success
        bool addAirplane(Airplane& airplane);
        
        //Accessors and mutators
        void setId(const int id);
        void setName(const std::string& name);
        void setAirport(const int airportId);

        int getId();
        std::string& getName();
        int getAirport();

    private:
        int runwayId = 0;   //PRIMARY_KEY
        std::string _name = "";
        std::vector<int> airplanesOnRunway;
};

#endif
