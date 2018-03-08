//Header file for Runway

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

    /**
     * \brief Checks if the airport class is initialized correctly
     * @return Returns true if the airport is correctly initialized
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    bool properlyInitialized() const;

    /**
     * \brief Adds an airplane to the runway
     * @param airplane Airplane which needs to be added
     * @return True if the airplane is added correctly
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    bool addAirplane(Airplane* airplane);

    //Accessors and mutator:
    /**
     * \brief Gives the runway a new ID
     * @param id New ID for the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    void setId(int id);

    /**
     * \brief Gives the runway a new name
     * @param name New name for the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
     */
    void setName(const string& name);

    /**
     * \brief Gives the runway a new Airport ID
     * @param airportId New Airport ID for the runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Runway is not initialized correctly");
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
    Runway* _initCheck; /**<member used in @see properlyInitalized() to check if the airplane is initalized correctly*/
};

#endif
