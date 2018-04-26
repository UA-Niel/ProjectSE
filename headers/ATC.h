#ifndef PROJECTSE_ATC_H
#define PROJECTSE_ATC_H

#include <iostream>
#include "ApTime.h"

class ATC {
private:
    std::string _callsign;
    ATC* _initCheck;
public:

    bool properlyInitialized() const;

    ATC(const std::string &_callsign);

    const std::string &getCallsign() const;

    void setCallsign(const std::string &_callsign);

    /**
     * \brief Generates a message of the air traffic commander
    * @param time ApTime of the message
    * @param source Source of the message
    * @param message Content of the message
    * @return Combination of time, source and content
    *
    * **Preconditions:**
    * - REQUIRE(this->properlyInitalized(), "ATC is not initialized correctly");
    */
    std::string atcMessage(ApTime& time, const std::string& source, const std::string& message);

};


#endif //PROJECTSE_ATC_H
