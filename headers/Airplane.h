//Header file for Airplane-class

#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>

using namespace std;

class Airplane {
public:

    //properlyInitialized
    bool properlyInitialized() const;

    //Make the airplane depart, return true if succesful
    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    bool depart();

    //Let the airplane land, return true if succesful
    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    bool land();

    //Accessors and mutators
    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    void setId(int id);

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    void setNumber(const std::string& number);

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    void setCallsign(const string& callsign);

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    void setModel(const string& model);

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    void setStatus(int status);

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    int getId() const;

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    string getCallsign() const;

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    string getModel() const;

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    int getStatus() const;

    //REQUIRE(this->properlyInitialized(), "Airplane is not initialized correctly");
    std::string getNumber() const;

    //Constructor
    //ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
    Airplane(int _airplaneId, const string &callsign, const string &_model, int _status);

    //ENSURE(this->properlyInitialized(), "Airplane is not initialized correctly");
    Airplane();

private:
    int _airplaneId; //PRIMARY_KEY
    std::string _number;
    string _callsign;
    string _model;
    int _status;
    Airplane* _initCheck;
};

#endif
