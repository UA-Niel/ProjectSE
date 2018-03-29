/**
 * \file
 * This file contains the declarations of the Airplane class
 */
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>
#include "Gate.h"
#include "AirportExporter.h"

class Runway;
class Airport;


using namespace std;

/**\brief class that represents an airplane
 *
 * An airplane has an id, a number, a callsign a model and a status
 */
class Airplane {
public:
    /**
     * \brief Enum containing different states of the Airplane
     */
    enum Status {
        APPROACHING,
        LANDED,
        IN_AIR,
        AT_GATE,
        STANDING,
        TAXIING_TO_GATE,
        LANDING,
        DEPARTING,
        UNKNOWN
    };

    /**
     * \brief Enum containing the different fuel states of the Airplane
     */
    enum FuelState {
        EMPTY,
        WARNING,
        OKAY,
        FULL
    };


    /**
     * \brief checks if the Airplane class is initialized correctly
     * @return returns true if the Airplane is correctly initialized
     */
    bool properlyInitialized() const;

    /**
     * \brief Lets the plane ascend by amountOfFeet (default = 1000)
     * @param amountOfFeet Amount of feet the plane has to ascend (default = 1000)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */

    void ascend(unsigned int amountOfFeet = 1000);

    /**
     * \brief Lets the airplane approach by amountOfFeet (default = 1000)
     * @param amountOfFeet Amount of feet the plane needs to approach
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     * - REQUIRE(this->getStatus() == LANDING, "Airplane must be in LANDING status before it can approach");
     * - REQUIRE(amountOfFeet > 0, "You can only approach by a positive amount of feet");
     */
    void approach(int amountOfFeet = 1000);
    

    /**
     * \brief Gives the airplane a new ID
     * @param id This is the new ID of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setId(int id);

    /**
     * \brief Gives the airplane a new number
     * @param number The new number of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setNumber(const std::string& number);

    /**
     * \brief Gives the airplane a new callsign
     * \n \n
     * @param callsign The new callsign of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setCallsign(const string& callsign);

    /**
     * \brief Gives the airplane a new model
     * @param model The new model of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setModel(const string& model);

    /**
     * \brief Gives the airplane a new status
     * @param status The new status of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setStatus(Status status);

    /**
     * \brief Gets the ID of the airplane
     * @return The ID of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    int getId() const;

    /**
     * \brief Gets the callsign of the airplane
     * @return The callsign of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    string getCallsign() const;

    /**
     * \brief Gets the model of the airplane
     * @return The model of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    string getModel() const;

    /**
     * \brief Gets the status of the airplane
     * @return The ID code of the airplane
     *
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    Status getStatus() const;

    /**
     * \brief Gets the number of the airplane
     * @return The number of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    std::string getNumber() const;

    /**
     * \brief Returns the free runway
     * @return The free runway
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    Runway* checkFreeRunway(Airport* ap);
    
       /**
     * \brief Returns the free gate
     * @return The free gate
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    Gate* checkFreeGate(Airport* ap);


    /**
     * \brief Seths the height
     *
     * @param int height
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setHeight(const int height);

    /**
     * \brief Returns the height
     *
     * @return int height
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    int getHeight();

    /**
     * \brief Sets amount of passengers
     *
     * @param int amount
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setAmountOfPassengers(const int amount); 

    /**
     * \brief Returns the amount of passengers
     *
     * @return int amount
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    int getAmountOfPassengers();

    /**
     * \brief Sets the fuel state
     *
     * @param FuelState state
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setFuelState(const FuelState state);
    
    /**
     * \brief Returns the fuel state
     *
     * @return FuelState state
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    FuelState& getFuelState();

    /**
     * \brief constructor of the airplane class
     *
     * This constructor takes an id, callsign, model and status

     * @param _airplaneId The id of the airplane
     * @param callsign The callsign of the airplane
     * @param _model The model of the airplane
     * @param _status The status of the airplane
     * @param number The number of the airplane
     *
     * **Postconditons:**
     * - ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     */
    Airplane(int _airplaneId, const string &callsign, const string &_model, Airplane::Status status, const std::string& number);

    /**
     * \brief constructor of the airplane class
     *
     * This constructor is the default constructor
     *
     * **Postconditons:**
     * - ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    Airplane();

private:
    int _airplaneId; /**<The ID of the airplane, this is a unique ID*/
    string _callsign; /**<The callsign of the airplane*/
    string _model; /**<The model of the airplane*/
    Status _status; /**<The status of the airplane*/
    string _number; /**<The number of the airplane*/
    Airplane* _initCheck; /**<member used in @see properlyInitalized() to check if the airplane is initalized correctly*/

    int _height; /**<Variable to hold current height of the airplane>*/

    int _amountOfPassengers; /**<Variable to hold current amount of passengers on this plane*/
    FuelState _fuelState; /**<Variable to hold the current fuel state*/
};

#endif
