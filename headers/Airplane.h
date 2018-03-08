//Header file for Airplane-class

#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>

using namespace std;

/**\brief class that represents an airplane
 *
 * An airplane has an id, a number, a callsign a model and a status
 */
class Airplane {
public:

    /**
     * \brief checks if the Airplane class is initialized correctly
     * @return returns true if the Airplane is correctly initialized
     */
    bool properlyInitialized() const;

    /**
     * \brief Makes the airplane depart
     * @return true if the airplanes departed successfully
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    bool depart();

    /**
     * \brief Lets the airplane land
     * @return true if the airplane landed successfully
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    bool land();

    /**
     * \brief Gives the airplane a new ID
     * @param id This is the new ID of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setId(int id);

    /**
     * \brief Gives the airplane a new number
     * @param number The new number of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setNumber(const std::string& number);

    /**
     * \brief Gives the airplane a new callsign
     * \n \n
     * @param callsign The new callsign of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setCallsign(const string& callsign);

    /**
     * \brief Gives the airplane a new model
     * @param model The new model of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setModel(const string& model);

    /**
     * \brief Gives the airplane a new status
     * @param status The new status of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    void setStatus(int status);

    /**
     * \brief Gets the ID of the airplane
     * @return The ID of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    int getId() const;

    /**
     * \brief Gets the callsign of the airplane
     * @return The callsign of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    string getCallsign() const;

    /**
     * \brief Gets the model of the airplane
     * @return The model of the airplane
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    string getModel() const;

    /**
     * \brief Gets the status of the airplane
     * @return The ID code of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    int getStatus() const;

    /**
     * \brief Gets the number of the airplane
     * @return The number of the airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    std::string getNumber() const;


    /**
     * \brief constructor of the airplane class
     *
     * This constructor takes an id, callsign, model and status

     * @param _airplaneId The id of the airplane
     * @param callsign The callsign of the airplane
     * @param _model The model of the airplane
     * @param _status The status of the airplane
     *
     * **Postconditons:**
     * - ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
     *
     */
    Airplane(int _airplaneId, const string &callsign, const string &_model, int _status);

    /**
     * \brief constructor of the airplane class
     *
     * This constructor is the default constructor
     *  \n \n
     * **postconditons:**
     * - ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
     */
    Airplane();

private:
    int _airplaneId; /**<The ID of the airplane, this is a unique ID*/
    std::string _number; /**<The number of the airplane*/
    string _callsign; /**<The callsign of the airplane*/
    string _model; /**<The model of the airplane*/
    int _status; /**<The status of the airplane*/
    Airplane* _initCheck; /**<member used in @see properlyInitalized() to check if the airplane is initalized correctly*/
};

#endif
