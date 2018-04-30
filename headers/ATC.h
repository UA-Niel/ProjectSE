/**
 * \file This file contains the declaration of ATC methods
 */

#ifndef PROJECTSE_ATC_H
#define PROJECTSE_ATC_H

#include <iostream>
#include "ApTime.h"


class ATC {
private:
    std::string _callsign; /**<Member to hold the callsign of the ATC*/
    ATC* _initCheck; /**<Member used for properlyInitialized function*/
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
    ATC(const std::string &callsign);

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
     * - ENSURE(_callsign == callsign, "Error setting new callsign");
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
};


#endif //PROJECTSE_ATC_H
