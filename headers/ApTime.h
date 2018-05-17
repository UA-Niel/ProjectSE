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
     * - ENSURE(getHour() < 24 && getHour() >= 0, "Range of hours has to be [0, 24[");
     * - ENSURE(getHour() == 0 || getHour() == hour, "Error setting Hour of ApTime");
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
     * - ENSURE(getMinutes() < 60 && getMinutes() >= 0, "Range of minutes has to be [0, 60[");
     * - ENSURE(getMinutes() == 0 || getMinutes() == minutes, "Error setting Minutes of ApTime");
     */
    void setMinutes(int minutes);

    /**
     * \brief Constructor for ApTime
     * @param _hour Hours for ApTime (int) has to be a value in range [0, 24[ else hours is set to 0
     * @param _minutes Minutes for ApTime (int) has to be a value in range [0, 60[ else minutes is set to 0
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "ApTime is not initialized correctly");
     * - ENSURE(getMinutes() < 60 && getMinutes() >= 0, "Range of minutes has to be [0, 60[");
     * - ENSURE(getHour() < 24 && getHour() >= 0, "Range of hours has to be [0, 24[");
     * - ENSURE(getMinutes() == 0 || getMinutes() == minutes, "Error setting Minutes of ApTime");
     * - ENSURE(getHour() == 0 || getHour() == hour, "Error setting Hour of ApTime");
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
     * - ENSURE(getMinutes() < 60 && getMinutes() >= 0, "Range of minutes has to be [0, 60[");
     * - ENSURE(getHour() < 24 && getHour() >= 0, "Range of hours has to be [0, 24[");
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

    /**
     * \brief Overload for the ++ operation
     * @return Reference to ApTime where ApTime++ is operated on
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     */
    const ApTime operator++(int);

    /**
     * \brief Overload for the += operation
     * @param minutes Minutes to add to time
     * @return Reference to new time
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     * - REQUIRE(minutes >= 0, "Amount of minutes has to be positive, can't go back in time");
     */
    ApTime& operator+=(int minutes);

    /**
     * \brief Overload for the == operation
     * @param time ApTime to compare "this" with
     * @return True if objects are the same
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     * - REQUIRE(time.properlyInitialized(), "ApTime is not initialized correctly");
     */
    bool operator==(ApTime& time);

    /**
     * \brief Overload for the = operator
     * @param time Values of the time we want
     * @return Time containing values of time parameter
     *
     * **Preconditions:**
     * - REQUIRE(time.properlyInitialized(), "ApTime is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "ApTime is not initialized correctly");
     */
    ApTime& operator=(const ApTime& time);

    /**
     * \brief Overload for the != operator
     * @param time Time to compare to
     * @return True if objects are different
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     * - REQUIRE(time.properlyInitialized(), "ApTime is not initialized correctly");
     */
    bool operator!=(ApTime& time);

    /**
     * \brief Infix Operation ++ overload
     * @return Increased time
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "ApTime is not initialized correctly");
     */
    ApTime& operator++();


};


#endif //PROJECTSE_APTIME_H
