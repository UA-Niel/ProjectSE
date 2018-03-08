#include <iostream>
#include <string>

#include "headers/Airplane.h"
#include "headers/Airport.h"
#include "headers/Runway.h"

#include "parsers/Reader.h"

using namespace std;

int main(int argc, char* argv[]) {
    const char* str = "inputs/airplane1.xml";
    Airport p = loadAirportFromFile(str);
    cout << "Hello world!" << endl;

    return 0;
}
