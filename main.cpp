/**
 * \file
 * This is the main file of the project
 */

#include <iostream>
#include <string>

#include "classes/Airplane.h"
#include "classes/Airport.h"
#include "classes/Runway.h"

#include "parsers/Reader.h"

using namespace std;

int main(int argc, char* argv[]) {
    const char* str = "inputs/airport1.xml";
    Airport p = loadAirportFromFile(str);
    cout << "Hello world!" << endl;
    return 0;
}
