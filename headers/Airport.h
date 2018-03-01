//Header file for Airport-class

#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>

class Airplane;
class Runway;
class Gate;

class Airport {
    public:
        //Adding objects to Airport, return true on success
        bool addAirplane(Airplane& airplane);
        bool addRunway(Runway& runway);
        bool addGate(Gate& gate);

        //Removing objects of Airport, return true on success
        bool removeAirplane(const int id);
        bool removeRunway(const int id);
        bool removeGate(const int id);
        
        //Accessors and mutators
        Airplane& getAirplane(const int id);
        Runway& getRunway(const int id);
        Gate& getGate(const int id);

        void setId(const int id);
        void setName(const std::string name);
        void setIATA(const std::string IATA);
        void setCallsign(const std::string callsign);

        int getId();
        std::string& getName();
        std::string& getIATA();
        std::string& getCallsign();
        

    private:
        //All airplanes on the airport
        std::vector<Airplane> _airplanesOnAirport;
        //Runways of the airport
        std::vector<Runway> _runways;
        //Gates of the airport
        std::vector<Gate> _gates;

        //Other properties
        int _airportId; //PRIMARY_KEY
        std::string _name;
        std::string _IATA;
        std::string _callsign;
};

#endif //AIRPORT_H
