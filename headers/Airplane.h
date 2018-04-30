/**
 * \file
 * This file contains the declarations of the Airplane class
 */
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>
#include "Gate.h"
#include "IO/AirportExporter.h"

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
     * \brief Type of the airplane
     */
    enum Type {
        PRIVATE,
        AIRLINE,
        ALASKAN,
        JET_FIGHTER
    };

    /**
     * \brief Engine type of this plane
     */
    enum Engine {
        JET,
        PROPELLOR,
        GLIDER
    };

    /**
     * \brief Size of this plane
     */
    enum Size {
        SMALL,
        MEDIUM,
        LARGE,
        EXTRA_LARGE
    };

    /**
     * \brief FlightPlan of this plane
     */
    struct FlightPlan {
        std::string destination;
        int departure;
        int arrival;
        int interval;
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
     *
     * **Postconditions:**
     * - ENSURE(heightOld == _height+amountOfFeet, "Airplane approached with wrong amount of feet");
     */
    void approach(int amountOfFeet = 1000);
    

    /**
     * \brief Gives the airplane a new ID
     * @param id This is the new ID of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_airplaneId == id, "Error setting new ID for Airplane");
     */
    void setId(int id);

    /**
     * \brief Gives the airplane a new number
     * @param number The new number of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_number == number, "Error setting new number for Airplane");
     */
    void setNumber(const std::string& number);

    /**
     * \brief Gives the airplane a new callsign
     * \n \n
     * @param callsign The new callsign of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_callsign == callsign, "Error setting new callsign for Airplane");
     */
    void setCallsign(const string& callsign);

    /**
     * \brief Gives the airplane a new model
     * @param model The new model of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_model == model, "Error setting new model for Airplane");
     */
    void setModel(const string& model);

    /**
     * \brief Gives the airplane a new status
     * @param status The new status of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_status == status, "Error setting new status of Airplane");
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
     *
     * **Postconditions:**
     * - ENSURE(_height == height, "Error setting height of Airplane");
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
     *
     * **Postconditions:**
     * - ENSURE(_amountOfPassengers = amount, "Error setting new amount of passengers");
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
     * \brief Set type of Airplane
     *
     * @param Type, type of airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->type == type, "Error setting new type for airplane");
     */
    void setType(const Type& type);
    void setType(std::string type);
    
    /**
     * \brief Returns the type
     *
     * @return Type
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    const Type& getType();

    /**
     * \brief Returns the type of engine
     *
     * @return Engine
     *
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    const Engine& getEngine();

    /**
     * \brief Sets the type of engine
     *
     * @param Engine
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->engine == engine, "Error setting new engine for airplane");
     */
    void setEngine(const Engine& engine);
    void setEngine(std::string engine);

    /**
     * \brief Gets the size of airplane
     *
     * @return Size
     *
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    const Size& getSize();


    /**
     * \brief Sets the size of airplane
     *
     * @param Engine
     *
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->size == size, "Error setting new size for airplane");
     */
      void setSize(const Size& size);
      void setSize(std::string size);

    /**
     * \brief Sets the flightplan of airplane
     *
     * @param destination (string)
     * @param departure
     * @param arrival
     * @param interval
     *
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->flightPlan->destination == destination, "Error setting destination for FlightPlan of Airplane");
     * - ENSURE(this->flightPlan->departure == departure, "Error setting departure for FlightPlan of Airplane");
     * - ENSURE(this->flightPlan->arrival == arrival, "Errror setting arrival for FlightPlan of Airplane");
     * - ENSURE(this->flightPlan->interval == interval, "Error setting interval for FlightPlan of Airplane");
     */
     void setFlightPlan(const std::string& destination, const int departure, const int arrival, const int interval);


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
    Type type; /**<Variable to hold type of the airplane*/
    Engine engine; /**<Variable to hold type of engine*/
    Size size; /**<Variable to hold size of airplane*/
    FlightPlan* flightPlan; /**<Variable holding flightPlan of this plane*/
};

#endif
