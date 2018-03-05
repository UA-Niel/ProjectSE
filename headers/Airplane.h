//Header file for Airplane-class

#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>

using namespace std;

class Airplane {
public:
    //initialized
    bool properlyInitialized() const;

    //Make the airplane depart, return true if succesful
    bool depart();
    //Let the airplane land, return true if succesful
    bool land();
    //Accessors and mutators
    void setId(int id);
    void setNumber(const std::string& number);
    void setCallsign(const string& callsign);
    void setModel(const string& model);
    void setStatus(int status);

    int getId() const;
    string& getCallsign() const;
    string& getModel() const;
    int getStatus() const;
    std::string& getNumber() const;

    //Constructor
    Airplane(int _airplaneId, const string &callsign, const string &_model, int _status);
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
