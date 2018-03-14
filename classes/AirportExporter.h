#ifndef PROJECTSE_AIRPORTEXPORTER_H
#define PROJECTSE_AIRPORTEXPORTER_H
/**
 * \file
 * This file contains the declaration of the AirportExporter class
 */

#include "Airport.h"

/**
 * \brief this class is the base class for the Airport output
 *
 */
class AirportExporter {
private:
    AirportExporter* _initCheck; /**<Member used to check if the class is initalized correctly in properlyInitalized()*/
    bool _startOutput; /**<Bool to check if the output is started*/
public:
    /**
     * \brief default destructor for AirportExporter
     */
    virtual ~AirportExporter();

    /**
     * \brief default constructor for AirportExporter
     */
    AirportExporter();

    /**
     * \brief Checks if the AirportExporter class is initialized correctly
     * @return Returns true if the AirportExporter is correctly initialized
     */
    bool properlyInitalized();
};


#endif //PROJECTSE_AIRPORTEXPORTER_H
