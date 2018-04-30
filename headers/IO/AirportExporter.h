#ifndef PROJECTSE_AIRPORTEXPORTER_H
#define PROJECTSE_AIRPORTEXPORTER_H
/**
 * \file
 * This file contains the declaration of the AirportExporter class
 */

#include "../DesignByContract.h"
#include <string>

using namespace std;

class Airport;

/**
 * \brief this class is the base class for the Airport output
 *
 */
class AirportExporter {
private:
    AirportExporter* _initCheck; /**<Member used to check if the class is initialized correctly in properlyinitialized()*/
    bool _startOutput; /**<Bool to check if the output is started*/
    Airport* _airport; /**<Pointer to airport, the source for the output*/
    std::ostream& _stream;
public:
    /**
     * \brief default destructor for AirportExporter
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    virtual ~AirportExporter();

    /**
     * \brief default constructor for AirportExporter
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    AirportExporter(std::ostream& stream);

    /**
     * \brief Constructor which takes an airport as parameter
     * @param airport Airport which needs to be printed
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    AirportExporter(Airport *airport, std::ostream& stream);

    /**
     * \brief Checks if the AirportExporter class is initialized correctly
     * @return Returns true if the AirportExporter is correctly initialized
     */
    bool properlyInitialized() const;


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
     *
     * **Preconditions**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initialized correctly?");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputAirportDetails();

    /**
     * \brief Exports the details of the airplanes to the specified stream
     *
     * **Preconditions**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initialized correctly?");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputPlaneDetails();

    /**
     * \brief Exports basic information of the airport to specified stream
     *
     * This method uses @see outputAirportDetails and @see outputPlaneDetails and combines them
     *
     * **Preconditions**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(_airport != NULL, "AirportExporter did not find the airport, is it initialized correctly?");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputBasicInfo();

    /**
     * \brief Exports a given string to the specified stream
     *
     * @param outputString String to output to stream
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly after constructor");
     * - REQUIRE(_startOutput, "AirportExporter output is not started, use the method startOutput first");
     */
    void outputString(std::string outputString);

    /**
     * \brief Allows the use of << for strings
     * @param string1 String to stream
     * @return Stream with string1 streamed
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    ostream& operator<<(string string1);

    /**
     * \brief Allows the use of the == operator
     * @param exporter Exporter to compare to
     * @return True if both exporters are the same
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "AirportExporter is not initialized correctly");
     * - REQUIRE(exporter.properlyInitialized(), "AirportExporter is not initialized correctly");
     */
    bool operator==(AirportExporter& exporter);

};

#endif //PROJECTSE_AIRPORTEXPORTER_H
