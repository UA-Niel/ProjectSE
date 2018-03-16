//Implementation file for Read-parser

#include "Reader.h"
#include "library/tinyxml.h"
#include "library/tinystr.h"

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <sstream>

//loadAirportFromFile
Airport* loadAirportFromFile(const char* fileName) {
    TiXmlDocument doc;
    
    //Loading file and check if it loaded correct
    if (!doc.LoadFile(fileName)) {
        std::cout<< "Error: " << doc.ErrorDesc() << std::endl;
    
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
                    if (eValue == "iata") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirport->setIATA(t);
                     
                    }
                    if (eValue == "gates") {
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
                    if (eValue == "airport") {
                        myRunway->setAirport(myAirport->getId());
                    }
                }

                myAirport->addRunway(myRunway);
            }
            //Adding airplane
            if (elementType(elemType) == AIRPLANE) {
                Airplane* myAirplane = new Airplane;

                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
                   std::string eValue = e->Value();

                    if (eValue == "number") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane->setNumber(t);
                    }
                    if (eValue == "callsign") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane->setCallsign(t);    
                    }
                    if (eValue == "model") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane->setModel(t);    
                    }
                    if (eValue == "status") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                    
                        if (t == "Standing") myAirplane->setStatus(Airplane::Status::STANDING);
                        if (t == "Taxing") myAirplane->setStatus(Airplane::Status::TAXING);
                        if (t == "Approaching") myAirplane->setStatus(Airplane::Status::APPROACHING);
                        if (t == "Landing") myAirplane->setStatus(Airplane::Status::LANDING);
                        
                    }
                }

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
    if (element == "AIRPLANE") {
        type = AIRPLANE;
    }
    if (element == "RUNWAY") {
        type = RUNWAY;
    }

    return type;
}
