//Implementation file for Read-parser

#include "../headers/IO/Reader.h"
#include "../headers/IO/library/tinyxml.h"
#include "../headers/IO/library/tinystr.h"

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
        std::cerr<< "Error: " << doc.ErrorDesc() << std::endl;
    
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
                    if (eValue == "callsign") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirport->setCallsign(t);
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
                    if (eValue == "type") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRunway->setType(t);
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

                        myAirplane->setFuelState(Airplane::FULL);

                        if (t == "Standing") myAirplane->setStatus(Airplane::STANDING);
                        if (t == "Taxing") myAirplane->setStatus(Airplane::TAXIING_TO_GATE);
                        if (t == "Approaching") myAirplane->setStatus(Airplane::APPROACHING);
                        if (t == "Landing") myAirplane->setStatus(Airplane::LANDING);
                        
                    }
                    if(eValue == "passengers"){
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        int amountOfPassengers;
                        std::istringstream ss(t);
                        ss >> amountOfPassengers;
                        myAirplane->setAmountOfPassengers(amountOfPassengers);
                    }
                }

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
    if (element == "AIRPLANE") {
        type = AIRPLANE;
    }
    if (element == "RUNWAY") {
        type = RUNWAY;
    }

    return type;
}
 
