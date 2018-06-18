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

    bool landingInitial();

    bool landingAt5000();

    bool landingAt3000(Airplane* plane);

    bool landingEnd(Airplane* plane);

    bool departureOfGate();

    bool departureWaitingAtRunway(Airplane* plane);

    bool departureWaitingOnRunway();

    bool emergencyHigherThan3000(Airplane* plane);

    bool emergencyLowerThan3000(Airplane* plane);
};


#endif //PROJECTSE_ATC_H
