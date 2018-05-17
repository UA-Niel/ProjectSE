/**
 * \file
 * This file contains the declaration of the Gate class
 */

#ifndef GATE_H
#define GATE_H

#include <vector>

class Airplane;

/**
 * \brief The Gate class, a gate has an ID and can contain an airplane
 */
class Gate {
    public:
    /**
     * \brief Default construcotr for Gate class
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitialized(), "Gate not properly initialized.");
     */
    Gate();
    
    /**
     * \brief Sets a new id for the Gate class
     * @param id New id for the Gate class
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
     *
     * **Postconditions:**
     * - ENSURE(getId() == id, "Error setting new ID for Gate");
     */
    void setId(int id);

    /**
     * \brief Returns the ID of the Gate class
     * @return ID of the gate class
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
     */
    int getId() const;

    /**
     * \brief Sets Airplane at Gate
     * @param plane Pointer to airplane at Gate
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
     *
     * **Postconditions:**
     * - ENSURE(getPlaneAtGate() == plane, "Error setting new plane at the Gate");
     */
    void setPlaneAtGate(Airplane* plane);

    /**
     * \brief Returns Airplane at Gate
     * @return Pointer to Airplane at Gate
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Gate not properly initialized.");
     */
    Airplane* getPlaneAtGate();

    /**
     * \brief Checks if the Gate class is initialized correctly
     * @return Returns true if the Gate class is correctly initialized
     */
    bool properlyInitialized() const;

    /**
     * \brief Clears the gate
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitialized(), "Gate is not initialized correctly");
     *
     * **Postconditions:**
     * - ENSURE(getPlaneAtGate() == NULL, "Error clearing gate");
     */
    void clearGate();

private:
    int _id; /**<Member containing ID of the Gate*/
    Gate* _initCheck; /**<Member used for properlyInitalized functions*/
    Airplane* _planeAtGate;/**<Member containing pointer to Airplane of runway*/
};


#endif
