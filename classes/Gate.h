/**
 * \file
 * This file contains the declaration of the Gate class
 */

#ifndef GATE_H
#define GATE_H

#include <vector>

class Airplane;

class Gate {
    public:
    //Constructors
    Gate();
    
    //Getters and setters
    void setId(const int id);
    int getId() const;

    void setPlaneAtGate(Airplane* plane);
    Airplane* getPlaneAtGate();

    //Initialized
    bool properlyInitialized() const;

    private:
    int _id;
    Gate* _initCheck; 
    Airplane* _planeAtGate;
};


#endif
