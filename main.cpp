#include <iostream>
#include <string>

#include "headers/Airplane.h"
#include "headers/Airport.h"
#include "headers/Runway.h"

#include "parsers/Reader.h"

using namespace std;

int main(int argc, char* argv[]) {
    Airport* p = loadAirportFromFile("inputs/airport1.xml");
    cout << p->getId() << endl;

    return 0;
}
