/**
 * \file
 * This file contains the declaration of the Route class
 */

#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <string>

class Route {
    public:
    //Member methods
    //Set all the heights in a vector
    void setHeightVector(const std::vector<int>& v);

    //Returns the whole vector of heights
    const std::vector<int>& getHeightVector() const;

    //Return height of specific index in vector
    //:param i: Index to get height from
    int getHeight(int i) const;

    //Accessors and mutators
    //Set airplane-number of airplane following this route
    void setAirplane(const std::string& airplane);
    //Get airplane-number
    const std::string& getAirplane() const;
    
    //Set startingAirport
    void setStartingAirport(const std::string& startingAirport);
    //Get startingAirport
    const std::string& getStartingAirport() const;
    
    //Set destinationAirport
    void setDestinationAirport(const std::string& destinationAirport);
    //Get destinationAirport
    const std::string& getDestinationAirport() const;



    private:
    int id; //Route-ID, PRIMARY_KEY
    std::vector<int> _height;
    std::string _airplane;   //Airplane following this route
    std::string _startingAirport; //Airport where this airplane departed from
    std::string _destinationAirport; //Airport where airplane intents to land
};

#endif //ROUTE_H
