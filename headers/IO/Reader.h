//Header file for Read-parser

#ifndef READPARSER_H
#define READPARSER_H

#include <string>
#include <map>
#include "../Airport.h"


//Loading the airport from an input-file into memory
//:param fileName => Filename to read from
//:return bool => True on success
Airport* loadAirportFromFile(const char* fileName);

//Describing the possible elements
//(RUNWAY, AIRPLANE, AIRPORT)
enum ElementType {
    RUNWAY,
    AIRPLANE,
    AIRPORT,
    INVALID
};

//Recognizing element type from <Element> string
//:param element => string in format <Element>
//:return ElementType => RUNWAY, AIRPLANE, AIRPORT
ElementType elementType(const std::string& element);

//Adds element to airport
//:param toAdd => Element to add
//:return bool => True if succesfull
bool addToAirport(ElementType& toAdd);

//Makes an Airport
Airport& createAirport();

#endif //READPARSER_H
