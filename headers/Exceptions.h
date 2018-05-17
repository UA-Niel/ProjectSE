/**
 * \file This file contains the declaration and implementation of some Exception classes
 */
#ifndef PROJECTSE_EXCEPTIONS_H
#define PROJECTSE_EXCEPTIONS_H

#include <iostream>
#include "DesignByContract.h"

using namespace std;


/**
 * \brief This class is used for Simulator Exceptions
 */
class SimulatorException: public std::exception{
    string _msg; /**<Message for the exception*/
    SimulatorException* _initCheck;/**<Member used to use properlyInitialized*/
public:
    /**
     * \brief Constructor for SimulatorException taking message as parameter
     * @param msg Error message for SimulatorException
     *
     * **Postconditions:**
     * - ENSURE(this->properlyinitialized(), "SimulatorException class is not initialized correctly");
     */
    SimulatorException(const string &msg) : _msg(msg){
        _msg = "Simulator Exception:\n\t"
                       "what(): " + msg + "\n";
        _initCheck = this;
        ENSURE(this->properlyInitialized(), "SimulatorException class is not initialized correctly");
    }

    /**
     * \brief Checks if SimulatorException class is initialized properly
     * @return True if the SimulatorException class is initialized properly
     */
    bool properlyInitialized() const{
        return this == _initCheck;
    }

    /**
     * \brief Throws the error message
     * @return Error message (c_string)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyinitialized(), "SimulatorException class is not initialized correctly");
     */
    const char* what() const throw(){
        REQUIRE(properlyInitialized(), "SimulatorException class is not initialized correctly")
        return _msg.c_str();
    }

    /**
     * \brief Basic destructor for SimulatorException
     */
    virtual ~SimulatorException() throw() {

    }

};

class ReaderException: public std::exception{
    string _msg; /**<Message for the exception*/
    ReaderException* _initCheck;/**<Member used to use properlyInitialized*/
public:
    /**
     * \brief Constructor for ReaderException taking message as parameter
     * @param msg Error message for ReaderException
     *
     * **Postconditions:**
     * - ENSURE(this->properlyinitialized(), "ReaderException class is not initialized correctly");
     */
    ReaderException(const string &msg) : _msg(msg){
        _msg = "Reader Exception:\n\t"
                       "what(): " + msg + "\n";
        _initCheck = this;
        ENSURE(this->properlyInitialized(), "ReaderException class is not initialized correctly");
    }

    /**
     * \brief Checks if ReaderException class is initialized properly
     * @return True if the ReaderException class is initialized properly
     */
    bool properlyInitialized() const{
        return this == _initCheck;
    }

    /**
     * \brief Throws the error message
     * @return Error message (c_string)
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyinitialized(), "ReaderException class is not initialized correctly");
     */
    const char* what() const throw(){
        REQUIRE(properlyInitialized(), "ReaderException class is not initialized correctly")
        return _msg.c_str();
    }

    /**
     * \brief Basic destructor for ReaderException
     */
    virtual ~ReaderException() throw() {

    }

};



#endif //PROJECTSE_EXCEPTIONS_H
