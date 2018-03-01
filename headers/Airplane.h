//Header file for Airplane-class

#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>
#include "Airport.h"

class Airplane {
    public:
        //Make the airplane depart, return true if succesful
        bool depart();
        //Let the airplane land, return true if succesful
        bool land();

        //Accessors and mutators
        void setId(const int id);
        void setCallsign(const std::string& callsign);
        void setModel(const std::string& model);
        void setStatus(const int status);

        int getId();
        std::string& getCallsign();
        std::string& getModel();
        int getStatus();

    private:
        int _airplaneId; //PRIMARY_KEY
        std::string _callsign;
        std::string _model;
        int _status;
};

#endif
