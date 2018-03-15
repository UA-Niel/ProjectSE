#ifndef PROJECTSE_AIRPORTEXPORTER_H
#define PROJECTSE_AIRPORTEXPORTER_H
/**
 * \file
 * This file contains the declaration of the AirportExporter class
 */

#include "Airport.h"
#include "../DesignByContract.h"

using namespace std;

/**
 * \brief This class is used for Airport Exporter Exceptions
 */
class AirportExporterException: public std::exception{
    string _msg; /**<Message for the exception*/
    AirportExporterException* _initCheck;/**<Member used to use properlyInitalized*/
public:
    /**
     * \brief Constructor for AirportExporterException taking message as parameter
     * @param msg Error message for AirportExporterException
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitalized(), "AirportExporterException class is not initalized correctly");
     */
    AirportExporterException(const string &msg) : _msg(msg){
        _msg = "Airport Exporter Exception:\n\t"
                "what(): " + msg + "\n";
        _initCheck = this;
        ENSURE(this->properlyInitalized(), "AirportExporterException class is not initalized correctly");
    }

    /**
     * \brief Checks if AirportExporterException class is initalized properly
     * @return True if the AirportExporterException class is initialized properly
     */
    bool properlyInitalized() const{
        return this == _initCheck;
    }

    /**
     * \brief Throws the error message
     * @return Error message (c_string)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "AirportExporterException class is not initalized correctly");
     */
    const char* what() const throw(){
        REQUIRE(properlyInitalized(), "AirportExporterException class is not initalized correctly")
        return _msg.c_str();
    }

    /**
     * \brief Basic destructor for AirportExporterException class
     */
    virtual ~AirportExporterException() throw() {}

};


/**
 * \brief this class is the base class for the Airport output
 *
 */
class AirportExporter {
private:
    AirportExporter* _initCheck; /**<Member used to check if the class is initalized correctly in properlyInitalized()*/
    bool _startOutput; /**<Bool to check if the output is started*/
    Airport* _airport;
public:
    /**
     * \brief default destructor for AirportExporter
     *
     * **Preconditions:**
     * - ENSURE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    virtual ~AirportExporter();

    /**
     * \brief default constructor for AirportExporter
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    AirportExporter();

    /**
     * \brief Constructor which takes an airport as parameter
     * @param airport Airport which needs to be printed
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    explicit AirportExporter(Airport *airport);

    /**
     * \brief Checks if the AirportExporter class is initialized correctly
     * @return Returns true if the AirportExporter is correctly initialized
     */
    bool properlyInitalized() const;

    /**
     * \brief Getter for member _airport
     * @return Pointer to _airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    Airport *get_airport() const;

    /**
     * \brief Setter for member _airport
     * @param airport Pointer to airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    void set_airport(Airport *airport);

    /**
     * \brief Makes sure the output can be generated
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    void startOutput();

    /**
     * \brief Stops the output form being generated
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(_startOutput, "StartOutput has to be true before it can be stopped");
     */
    void stopOutput();


    /**
     * \brief Exports the details of the airport to the specified stream
     * @param stream Stream where the output needs to go
     *
     * **Preconditions**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initalized correctly?");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputAirportDetails(ostream& stream);

    /**
     * \brief Exports the details of the airplanes to the specified stream
     * @param stream Stream where the output needs to go
     *
     * **Preconditions**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initalized correctly?");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputPlaneDetails(ostream& stream);

    /**
     * \brief Exports basic information of the airport to specified stream
     * @param stream Stream where the output needs to go
     *
     * This method uses @see outputAirportDetails and @see outputPlaneDetails and combines them
     *
     * **Preconditions**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initalized correctly?");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputBasicInfo(ostream& stream);

    /**
     * \brief Exports a given string to the specified stream
     *
     * @param stream Stream where the output needs to go
     * @param outputString String to output to stream
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "AirportExporter is not initalized correctly after constructor");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputString(ostream& stream, std::string outputString);

};

#endif //PROJECTSE_AIRPORTEXPORTER_H
