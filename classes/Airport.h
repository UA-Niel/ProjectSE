/**
 * \file
 * This file contains all information about the Airport class
 */

#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>

#include "Airplane.h"
#include "Runway.h"
#include "Gate.h"

using namespace std;
/**
 * \brief Class that represents an airport
 *
 * An airport has airplanes, runways, gates, an ID, a name, IATA and a callsign
 */
class Airport {
public:

    /**
     * \brief Checks if the airport class is initialized correctly
     * @return Returns true if the airport is correctly initialized
     */
    bool properlyInitialized() const;

    /**
     * \brief Adds an airplane to the airport
     *
     * Adds an airplane to the airport and returns true if successful
     *
     * @param airplane A pointer to the airplane which needs to be added
     * @return True if the airplane was added successfully
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    bool addAirplane(Airplane* airplane);

    /**
     * \brief Adds a runway to the airport
     *
     * Adds a runway to the airport and returns true if successful
     *
     * @param runway A pointer to the runway which needs to be added
     * @return True if the runway was added successfully
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    bool addRunway(Runway* runway);

    /**
     * \brief Adds a runway to the airport
     *
     * Adds a runway to the airport and returns true if successful
     *
     * @param gate A pointer to the gate which needs to be added
     * @return True if the gate was added successfully
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    bool addGate(Gate* gate);

    /**
     * \brief Removes an airplane from the airport
     *
     * Removes an airplane from the airport and returns true if successful
     *
     * @param id Id of the airplane which needs to be removed
     * @return True if airplane was removed
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    bool removeAirplane(int id);

    /**
     * \brief Returns vector of all Airplanes on the airport
     *
     * Returns all the airplanes in a vector
     *
     * @return std::vector<Airplane*>
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    std::vector<Airplane*> getAllAirplanes();

    /**
     * \brief Removes a runway from the airport
     *
     * Removes a runway from the airport and returns true if successful
     *
     * @param id Id of the runway which needs to be removed
     * @return True if runway was removed
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    bool removeRunway(int id);


    /**
     * \brief Removes a gate from the airport
     *
     * Removes a gate from the airport and returns true if successful
     *
     * @param id Id of the gate which needs to be removed
     * @return True if gate was removed
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    bool removeGate(int id);

    //Accessors and mutators
    /**
     * \brief Gets a pointer to an airplane from the airport
     * @param id Id of the airplane which needs to be returned
     * @return pointer to an airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    Airplane* getAirplane(int id);

    /**
     * \brief Gets a pointer to a runway from the airport
     * @param id Id of the runway which needs to be returned
     * @return Pointer to a runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    Runway* getRunway(int id);

    /**
     * \brief Gets a pointer to a gate from the airport
     * @param id Id of the gate which needs to be returned
     * @return Pointer to a gate
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    Gate* getGate(int id);

    /**
     * \brief Sets a new ID for the airport
     * @param id New ID for the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    void setId(int id);

    /**
     * \brief Sets a new name for the airport
     * @param name New name for the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    void setName(string name);

    /**
     * \brief Sets a new IATA for the airport
     * @param IATA New IATA for the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    void setIATA(string IATA);

    /**
     * \brief Sets a new callsign for the airport
     * @param id New callsign for the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    void setCallsign(string callsign);

    /**
     * \brief Gets the ID of the airport
     * @return ID of the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    int getId() const;

    /**
     * \brief Gets the name of the airport
     * @return Name of the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    const string& getName() const;

    /**
     * \brief Gets the IATA of the airport
     * @return IATA of the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    const string& getIATA() const;

    /**
     * \brief Gets the callsign of the airport
     * @return Callsign of the airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    const string& getCallsign() const;

    //Constructors
    /**
     * \brief Default constructor for airport
     *
     * **Preconditions:**
     * - ENSURE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    Airport();

    /**
     * \brief Constructor for airport which takes all members
     * @param _runways Vector of pointers to runways
     * @param _gates Vector of pointers to Gates
     * @param _airportId Integer ID of the airport
     * @param _name Std::string name of the airport
     * @param _IATA Std::string IATA of the airport
     * @param _callsign Std::string callsign of the airport
     *
     * **Preconditions:**
     * - ENSURE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    Airport(const vector<Runway*> _runways, const vector<Gate*> _gates, int _airportId, const string &_name,
            const string &_IATA, const string &_callsign);

    /**
     * \brief Check how many gates the Airport has
     * @return Unsigned integer for the number of gates
     *
     * **Preconditions:**
     * - ENSURE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    unsigned int getNrOfGates() const;

    /**
     * \brief Check how many runways the Airport has
     * @return Unsigned integer for the number of runways
     *
     * **Preconditions:**
     * - ENSURE(this->properlyInitialized(), "Airport is not initialized correctly");
     */
    unsigned int getNrOfRunways() const;

    const vector<Airplane *> &getAirplanes() const;

    std::vector<Runway*> *getRunways();


private:
    vector<Airplane*> _airplanesOnAirport; /**<Vector of pointers to airplanes*/
    vector<Runway*> _runways; /**<Vector of pointers to runways*/
    vector<Gate*> _gates; /**<Vector of pointers to Gates*/
    int _airportId; /**<Unique airport integer ID*/
    string _name; /**<Airport name string*/
    string _IATA; /**<Airport IATA string*/
    string _callsign; /**<Airport callsign string*/
    //Init check:
    Airport* _initCheck; /**<member used in @see properlyInitalized to check if the airplane is initalized correctly*/
};

#endif //AIRPORT_H
