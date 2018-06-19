/**
 * \file This file contains the declaration of ATC methods
 */

#ifndef PROJECTSE_ATC_H
#define PROJECTSE_ATC_H

#include <iostream>
#include <vector>
#include "ApTime.h"
#include "Airport.h"


class ATC {
private:
    std::string _callsign; /**<Member to hold the callsign of the ATC*/
    ATC* _initCheck; /**<Member used for properlyInitialized function*/
    std::vector<std::string> _natoAlphabet;
    Airport* _airport;
public:

    /**
     * \brief Checks if the ATC class is initialized correctly
     * @return Returns true if the ATC class is correctly initialized
     */
    bool properlyInitialized() const;

    /**
     * \brief Constructor for ATC
     * @param callsign Callsign for the ATC
     *
     * **Postconditions:**
     * - ENSURE(properlyInitialized(), "ATC is not initialized correctly");
     */
    ATC(const std::string &callsign, Airport* airport);

    /**
     * \brief Getter for Callsign
     * @return Callsign of the ATC
     *
     * **Preconditions:**
     * - REQUIRE(properlyInitialized(), "ATC is not initialized correctly");
     */
    const std::string &getCallsign() const;

    /**
     * \brief Setter for Callsign
     * @param callsign New callsign for ATC
     *
     * **Preconditions:**
     * - REQUIRE(properlyInitialized(), "ATC is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(getCallsign() == callsign, "Error setting new callsign");
     */
    void setCallsign(const std::string &callsign);

    /**
     * \brief Generates a message of the air traffic commander
     * @param time ApTime of the message
     * @param source Source of the message
     * @param message Content of the message
     * @return Combination of time, source and content
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "ATC is not initialized correctly");
     * - REQUIRE(time->properlyInitialized(), "ApTime is not initialized correctly");
     */
    std::string atcMessage(ApTime* time, const std::string& source, const std::string& message);

    /**
     * \brief Operator == for ATC
     * @param atc ATC to compare this atc with
     * @return True if both are the same
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
     */
    bool operator==(ATC& atc);

    /**
     * \brief Generates a vector containing the NATO alphabet
     * @return vector of strings containing the NATO alphabet
     *
     * **Postconditions:**
     * - ENSURE(natoAlphabet.size() == 36, "Incorrect size of NATO alphabet vector");
     */
    static std::vector<std::string> generateNato();

    /**
     * \brief Converts an integer to its equivalent in NATO alphabet
     * @param input Integer to convert
     * @return String containing the NATO equivalent of the integer
     *
     * **Postconditions:**
     * - ENSURE(!result.empty(), "Error converting integer to NATO equivalent");
     */
    static std::string intToNato(int input);

    /**
     * \brief Converts a char to its equivalent in NATO alphabet
     * @param input Char to convert
     * @return String containing the NATO equivalent of the integer
     *
     * **Postconditions:**
     * - ENSURE(pos > 0 && pos < 36, "Incorrect input given");
     */
    static std::string charToNato(char input);

    /**
     * \brief ATC determines if landing procedure can be started
     * @return True if the procedure can be started
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
     */
    bool landingInitial();

    /**
     * \brief ATC determines if the plane can continue after 5000ft
     * @return True if the plane can continue
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
     */
    bool landingAt5000();

    /**
     * \brief ATC determines if a plane can continue after 3000ft.
     * @param plane The plane to check
     * @return True if the plane can continue
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
     */
    bool landingAt3000(Airplane* plane);

    /**
     * \brief ATC determines if the landing procedure can be ended
     * @param plane Plane to check procedure for
     * @return True if the landing procedure can continue
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
     */
    bool landingEnd(Airplane* plane);

    /**
     * \brief ATC determines if the plane can depart of a gate
     * @return True if the plane can depart
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
     */
    bool departureOfGate();

    /**
     * \brief ATC determines if the plane should wait longer at the runway
     * @param plane Plane to check for
     * @return True if plane can move on
     *
     * **Precondtions:**
     * - REQUIRE(this->properlyInitialized(), "ATC is not initialized correctly");
     */
    bool departureWaitingAtRunway(Airplane* plane);

    /**
     * \brief ATC determines if the plane should wait longer on the runway
     * @return True if plane can move on
     */
    bool departureWaitingOnRunway();

    /**
     * \brief Checks for an emergency at 3000ft or lower
     * @param plane Plane to check emergency for
     * @return True if there is an emergency
     */
    bool emergencyHigherThan3000(Airplane* plane);

    /**
     * \brief Checks for an emergency at 5000ft or higher
     * @param plane Plane to check emergency for
     * @return True if there is an emergency
     */
    bool emergencyLowerThan3000(Airplane* plane);

    /**
     * \brief This static function converts numbers in a string to NATO numbers
     * @param str String to convert
     * @return String in nato
     */
    static std::string stringToNato(string& str);
};


#endif //PROJECTSE_ATC_H
