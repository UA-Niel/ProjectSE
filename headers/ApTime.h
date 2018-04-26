/**
 * \file This file contains the declaration of ApTime (Airport Time)
 */
#ifndef PROJECTSE_APTIME_H
#define PROJECTSE_APTIME_H

/**
 * \brief Class that for Airport Time
 */
class ApTime {
private:
    int _hour; /**<Member containing the hour of the time*/
    int _minutes;/**<Member containing the minutes of the time*/
    ApTime* _initCheck;/**<Member used for properlyInitialized*/
public:

    /**
     * \brief Checks if the ApTime class is properly initialized
     * @return True if properly initialized
     */
    bool properlyInitialized() const;

    /**
     * \brief Returns the hour of the ApTime
     * @return Hour (int)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     */
    int getHour() const;

    /**
     * \brief Sets a new hour for ApTime
     * @param hour New hour for ApTime (int)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_hour < 24 && _hour >= 0, "Range of hours has to be [0, 24[");
     * - ENSURE(_hour == 0 || _hour == hour, "Error setting Hour of ApTime");
     */
    void setHour(int hour);

    /**
     * \brief Returns the minutes of ApTime
     * @return Minutes (int)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     */
    int getMinutes() const;

    /**
     * \brief Sets new minutes for ApTime
     * @param minutes New minutes for ApTime
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(_minutes < 60 && _minutes >= 0, "Range of minutes has to be [0, 60[");
     * - ENSURE(_minutes == 0 || _minutes == minutes, "Error setting Minutes of ApTime");
     */
    void setMinutes(int minutes);

    /**
     * \brief Constructor for ApTime
     * @param _hour Hours for ApTime (int) has to be a value in range [0, 24[ else hours is set to 0
     * @param _minutes Minutes for ApTime (int) has to be a value in range [0, 60[ else minutes is set to 0
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "ApTime is not initialized correctly");
     * - ENSURE(_minutes < 60 && _minutes >= 0, "Range of minutes has to be [0, 60[");
     * - ENSURE(_hour < 24 && _hour >= 0, "Range of hours has to be [0, 24[");
     * - ENSURE(_minutes == 0 || _minutes == minutes, "Error setting Minutes of ApTime");
     * - ENSURE(_hour == 0 || _hour == hour, "Error setting Hour of ApTime");
     */
    ApTime(int _hour, int _minutes);

    /**
     * \brief Raises the time with a couple of minutes
     * @param minutes Minutes to raise the time with (can be higher than 60)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     * - REQUIRE(minutes > 0, "Can't go back in time");
     *
     * **Postconditions:**
     * - ENSURE(_minutes < 60 && _minutes >= 0, "Range of minutes has to be [0, 60[");
     * - ENSURE(_hour < 24 && _hour >= 0, "Range of hours has to be [0, 24[");
     */
    void raiseTime(int minutes);

    /**
     * \brief Converts ApTime to string with format HH:MM
     * @return String containing the current time
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(res.size() == 5, "Incorrect format of ApTime String");
     */
    std::string toString() const;


};


#endif //PROJECTSE_APTIME_H
