//Implementation file for Read-parser

#include "Reader.h"
#include "library/tinyxml.h"

#include <fstream>
#include <string>
#include <iostream>
#include <map>

//loadAirportFromFile
Airport loadAirportFromFile(const char* fileName) {
    TiXmlDocument doc;
    
    //Loading file and check if it loaded correct
    if (!doc.LoadFile(fileName)) {
        std::cout<<"error"<<std::endl;
    
    } else { 

        //Create instance of Airport
        Airport myAirport;
        myAirport.setId(1);

        //Getting root element
        TiXmlElement* root = doc.FirstChildElement();

        //Looping over all elements
        for (TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
            //Detecting elementType
            std::string elemType = elem->Value();
            if (elementType(elemType) == AIRPORT) { 
                //Looping over all child elements
                //and adding properties to Airport-class
                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
                   std::string eValue = e->Value();

                    if (eValue == "name") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirport.setName(t);
                    }
                    if (eValue == "iata") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirport.setIATA(t);
                     
                    }
                    if (eValue == "gates") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                       
                        int amountOfGates = std::stoi(t);
                        for (int i = 0; i < amountOfGates; i++) {
                            Gate myGate;
                            myAirport.addGate(myGate);
                        }
                    }
                }
            }
        
            //Adding runway
            if (elementType(elemType) == RUNWAY) {
                Runway myRunway;
                
                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
                   std::string eValue = e->Value();

                    if (eValue == "name") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRunway.setName(t);
                    }
                    if (eValue == "airport") {
                        myRunway.setAirport(myAirport.getId());
                    }
                }
            }
            //Adding airplane
            if (elementType(elemType) == AIRPLANE) {
                Airplane myAirplane;

                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
                   std::string eValue = e->Value();

                    if (eValue == "number") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane.setNumber(t);
                    }
                    if (eValue == "callsign") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane.setNumber(t);    
                    }
                    if (eValue == "model") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myAirplane.setModel(t);    
                    }
                    if (eValue == "status") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                    
                        if (t == "Standing") myAirplane.setStatus(0);
                        if (t == "Taxing") myAirplane.setStatus(1);
                        if (t == "Approaching") myAirplane.setStatus(2);
                        if (t == "Landing") myAirplane.setStatus(3);
                        
                    }
                }
            }
        }



        return myAirport;
    }
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


//////////////////////////////////////
//Loading routes from File
const std::vector<Route>& loadRoutesFromFile(const char* fileName) { 
    TiXmlDocument doc;
    
    //Loading file and check if it loaded correct
    if (!doc.LoadFile(fileName)) {
        std::cout<<"error"<<std::endl;
    
    } else { 
        //Creating vector holding routes
        std::vector<Route> routes;
        
        //Getting root element
        TiXmlElement* root = doc.FirstChildElement();

        //Looping over all elements
        for (TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
                
                //Checking if element is ROUTE
                std::string elemType = elem->Value();
                if (elemType != "ROUTE") return false;  

                //Creating instance of route
                Route myRoute;

                for (TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
             
                   std::string eValue = e->Value();
                   if (eValue = "id") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRoute.setId(t);
                   }
                   if (eValue = "airplane") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRoute.setAirplane(t);
                   }
                   if (eValue = "startingairport") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();

                        int x;
                        std::istringstream ss(t) >> x;

                        myRoute.setStartingAirport(x);
                   }
                   if (eValue = "destinationairport") {
                        TiXmlNode* x = e->FirstChild();
                        TiXmlText* text = x->ToText();
                        std::string t = text->Value();
                        myRoute.setDestinationAirport(t);
                   }
                    
                   //Adding route to vector
                   routes.push_back(myRoute);
            }
        }
    }

    return routes;
}
