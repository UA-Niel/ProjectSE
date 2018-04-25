/**
 * \file
 * This file contains the declaration of the Runway class
 */

#ifndef RUNWAY_H
#define RUNWAY_H

#include <string>
#include <vector>
#include "Airplane.h"

using namespace std;

/**
 * \brief Class that represents a runway
 *
 * A runway has an ID, id of the airport it is part of, a name and eventually airplanes
 */


class Runway {
public:
    
    enum RunwayType {
        ASPHALT,
        GRASS,
        SAND,
        WATER,
        UNKNOWN
    };

    /**
     * \brief Checks if the Runway class is initialized correctly
     * @return Returns true if the Runway is correctly initialized
     */
    bool properlyInitialized() const;

    /**
     * \brief Adds an airplane to the runway
     * @param airplane Airplane which needs to be added
     * @return True if the airplane is added correctly
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(oldSize == _airplanesOnRunway.size()-1, "Errror adding plane to Runway");
     */
    bool addAirplane(Airplane* airplane);

    /**
     * \brief Function to say the whole runway is clear
     *
     * @return True if cleared correctly
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     * - REQUIRE(!_airplanesOnRunway.empty(), "There are no Airplanes at the runway");
     *
     * **Postconditions:**
     * - REQUIRE(_airplanesOnRunway.empty(), "Error clearing Runway");
     */
    bool clearRunway();

    /**
     * \brief Returns the whole vector of all airplanes on runway
     * @return Airplanes
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    std::vector<Airplane*>& getAirplanesOnRunway();

    //Accessors and mutator:
    /**
     * \brief Gives the runway a new ID
     * @param id New ID for the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_runwayId == id, "Error setting new ID for the Runway");
     */
    void setId(int id);

    /**
     * \brief Gives the runway a new name
     * @param name New name for the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_name == name, "Error setting new name for the Runway");
     */
    void setName(const string& name);

    /**
     * \brief Gives the runway a new Airport ID
     * @param airportId New Airport ID for the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_myAirport == id, "Error setting new Airport ID for the Runway");
     */
    void setAirport(int airportId);

    /**
     * \brief Returns the id of the runway
     * @return Id of the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    int getId() const;

    /**
     * \brief Returns the name of the runway
     * @return Name of the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    string getName() const;

    /**
     * \brief Returns the ID of the airport
     * @return ID of the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    int getAirport() const;

    /**
     * \brief Sets type of the runway
     * @return Type of runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->runwayType == type, "Error setting new type for the Runway");
     */
    void setType(const Runway::RunwayType& type);
    void setType(const std::string type);

    /**
     * \brief Returns the type of the runway
     * @return Type of the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    Runway::RunwayType& getType();

    
    /**
     * \brief Gives the runway a new length
     * @param id Length of the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->length == length, "Error setting new length of the Runway");
     */
    void setLength(const int length);
    
    /**
     * \brief Returns the length of the runway
     * @return Length of airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    const int getLength();

    /**
     * \brief Adds name of point to vector
     *
     * @param Name name of point to add to Taxirotue
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(oldSize == taxiRoute.size()-1, "Error adding to Route");
     */
    void addToTaxiRoute(const std::string& name);

    //Constructor
    /**
     * \brief Constructor which initializes all members
     * @param runwayId Id of runway
     * @param _name Name of runway
     * @param airplanesOnRunway Planes on runway
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    Runway(int runwayId, const string &_name, const vector<Airplane*> &airplanesOnRunway);

    /**
     * \brief Default constructor for runway
     *
     * **Postconditons:**
     * - ENSURE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    Runway();

private:
    int _runwayId;  /**<Unique ID of the runway*/
    int _myAirport; /**<ID of the airport*/
    string _name; /**<Name of the runway*/
    vector<Airplane*> _airplanesOnRunway; /**<Planes on the runway*/
    Runway* _initCheck; /**</member used in @see properlyInitalized() to check if the airplane is initalized correctly*/
    RunwayType runwayType; /**<Type of the runway*/
    int length; /**<Length of the runway in meters*/
    std::vector<std::string> taxiRoute; /**Vector holding name of points in taxiroute*/
};

#endif
