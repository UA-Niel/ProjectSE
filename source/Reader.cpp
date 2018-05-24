/**
 * \file This file contains the implementation for input parser
 */


#include "../headers/IO/Reader.h"
#include "../headers/IO/library/tinyxml.h"
#include "../headers/IO/library/tinystr.h"
#include "../headers/utils.h"
#include "../headers/Exceptions.h"

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <sstream>

unsigned int gAIRPLANE_ID = 0;

//loadAirportFromFile
Airport* loadAirportFromFile(const char* fileName) {
    TiXmlDocument doc;
    
    //Loading file and check if it loaded correct
    if (!doc.LoadFile(fileName)) {
        std::string errorStr = doc.ErrorDesc();
        std::cerr << errorStr << std::endl;
        throw ReaderException(errorStr);
    } else { 

        //Create instance of Airport
        Airport* myAirport = new Airport;
        myAirport->setId(1);

        //Getting root element
        TiXmlElement* root = doc.FirstChildElement();

        //Looping over all elements
        for (TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
            //Detecting elementType
            std::string elemType = elem->Value();
            //std::cout << "xxxx " << elemType << std::endl;
            if (elementType(elemType) == AIRPORT) { 
                //Looping over all child elements
                //and adding properties to Airport-class
                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
                   std::string eValue = e->Value();

                    //std::cout <<"eee " <<  eValue << std::endl;

                    if (eValue == "name") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirport->setName(t);
                    }
                    else if (eValue == "iata") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirport->setIATA(t);
                     
                    }
                    else if (eValue == "gates") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        
                        int amountOfGates;
                        std::istringstream ss(t);
                        ss >> amountOfGates;

                        for (int i = 0; i < amountOfGates; i++) {
                            Gate* myGate = new Gate;
                            myGate->setId(i + 1);
                            myAirport->addGate(myGate);
                        }
                    }
                    else if (eValue == "callsign") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirport->setCallsign(t);
                    } else {
                        std::string errorStr = "Invalid tagname found. Program terminated...";
                        throw ReaderException(errorStr);
                    }
                }
            }
        
            //Adding runway
            if (elementType(elemType) == RUNWAY) {
                Runway* myRunway = new Runway;
                
                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
                   std::string eValue = e->Value();

                    if (eValue == "name") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRunway->setName(t);
                    }
                    else if (eValue == "airport") {
                        myRunway->setAirport(myAirport->getId());
                    }
                    else if (eValue == "type") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRunway->setType(t);
                    }
                    else if (eValue == "length") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRunway->setLength(fromStr<int>(t)); 
                    }

                    //Adding taxiroute
                    else if (eValue == "TAXIROUTE") {
                        for (TiXmlElement* x = e->FirstChildElement(); x != NULL; x = x->NextSiblingElement()) {
                            std::string xValue = x->Value();
                            if (xValue == "taxipoint" ||
                                xValue == "crossing") {
                                
                                TiXmlNode* y = x->FirstChild();
                                TiXmlText* text = y->ToText();
                                std::string t = text->Value();
                                myRunway->addToTaxiRoute(t);
                            } else {
                                std::string errorStr = "Invalid tagname found. Program terminated...";
                                std::cerr << errorStr << std::endl;
                                throw ReaderException(errorStr);
                            }
                        }
                    } else {
                        std::string errorStr = "Invalid tagname found. Program terminated...";
                        std::cerr << errorStr << std::endl;
                        throw ReaderException(errorStr);
                    }
                }

                myAirport->addRunway(myRunway);
            }
            //Adding airplane
            if (elementType(elemType) == AIRPLANE) {
                Airplane* myAirplane = new Airplane;
                std::string type, size, engine;

                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
                   std::string eValue = e->Value();

                    if (eValue == "number") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane->setNumber(t);
                    }
                    else if (eValue == "callsign") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane->setCallsign(t);    
                    }
                    else if (eValue == "model") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane->setModel(t);    
                    }
                    else if (eValue == "status") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();

                        myAirplane->setFuelState(Airplane::FULL);

                        if (t == "Standing") myAirplane->setStatus(Airplane::STANDING);
                        if (t == "Taxing") myAirplane->setStatus(Airplane::TAXIING_TO_GATE);
                        if (t == "Approaching") myAirplane->setStatus(Airplane::APPROACHING);
                        if (t == "Landing") myAirplane->setStatus(Airplane::LANDING);
                        
                    }
                    else if(eValue == "passengers"){
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        int amountOfPassengers;
                        istringstream ss(t);
                        ss >> amountOfPassengers;
                        myAirplane->setAmountOfPassengers(amountOfPassengers);
                    }

                    else if (eValue == "type") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        //myAirplane->setType(t);    
                        type = t;
                    }
                    else if (eValue == "size") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        //myAirplane->setSize(t);    
                        size = t;
                    }
                    else if (eValue == "engine") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        //myAirplane->setEngine(t);
                        engine = t;
                    }
                    
                    //Adding Flightplan
                    else if (eValue == "FLIGHTPLAN") {
                        std::string destination;
                        int departure, 
                            arrival, 
                            interval;

                        for (TiXmlElement* x = e->FirstChildElement(); x != NULL; x = x->NextSiblingElement()) {
                            std::string xValue = x->Value();
                            if (xValue == "destination") {
                                TiXmlNode* y = x->FirstChild();
                                TiXmlText* text = y->ToText();
                                std::string t = text->Value();
                                destination = t;
                            }
                            else if (xValue == "departure") {
                                TiXmlNode* y = x->FirstChild();
                                TiXmlText* text = y->ToText();
                                std::string t = text->Value();
                                departure = fromStr<int>(t);
                            }
                            else if (xValue == "arrival") {
                                TiXmlNode* y = x->FirstChild();
                                TiXmlText* text = y->ToText();
                                std::string t = text->Value();
                                arrival = fromStr<int>(t);
                            }
                            else if (xValue == "interval") {
                                TiXmlNode* y = x->FirstChild();
                                TiXmlText* text = y->ToText();
                                std::string t = text->Value();
                                interval = fromStr<int>(t);
                            } else {
                                std::string errorStr = "Invalid tagname found. Program terminated...";
                                std::cerr << errorStr << std::endl;
                                throw ReaderException(errorStr); 
                            }
                        }

                        myAirplane->setFlightPlan(destination, departure, arrival, interval);
                    } else { 
                        std::string errorStr = "Invalid tagname found. Program terminated...";
                        std::cerr << errorStr << std::endl;
                        throw ReaderException(errorStr);
                    }
                }

                myAirplane->setSize(size);
                myAirplane->setEngine(engine);
                myAirplane->setType(type);
                myAirplane->setId(gAIRPLANE_ID);
                gAIRPLANE_ID++;

                //Add airplane
                myAirport->addAirplane(myAirplane);
            }
        }



        return myAirport;
    }
    return new Airport();
}

//Recognizing elementType
ElementType elementType(const std::string& element) {
    ElementType type;

    if (element == "AIRPORT") {
        type = AIRPORT;
    }
    else if (element == "AIRPLANE") {
        type = AIRPLANE;
    }
    else if (element == "RUNWAY") {
        type = RUNWAY;
    } else {
        std::string errorStr = "Invalid tagname found. Program terminated...";
        std::cerr << errorStr << std::endl;
        throw ReaderException(errorStr); 
    }

    return type;
}
 
