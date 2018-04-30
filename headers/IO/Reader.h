/**
 * \file This file contains the declaration of the methods for the input parser
 */

#ifndef READPARSER_H
#define READPARSER_H

#include <string>
#include <map>
#include "../Airport.h"


/**
 * \brief Loads the Airport form an input-file into memory
 * @param fileName Filename tor ead rom
 * @return Pointer to the Airport read from the file
 */
Airport* loadAirportFromFile(const char* fileName);


/**
 * \brief Enum describing the possible elements of the Airport
 */
enum ElementType {
    RUNWAY,
    AIRPLANE,
    AIRPORT,
    INVALID
};

/**
 * \brief Function to recognize an element type from string
 * @param element Element of airport in string format
 * @return ElemenType (RUNWAY, AIRPLANE, AIRPORT)
 */
ElementType elementType(const std::string& element);



#endif //READPARSER_H
