#ifndef PROJECTSE_SIMULATOR_H
#define PROJECTSE_SIMULATOR_H


#include "IO/AirportExporter.h"
#include "../headers/Airport.h"

/**
 * \brief Class that handles the simulation of the airport
 *
 * A Simulator has an exporter and an airport as members
 */
class Simulator {
private:
    AirportExporter& _exporter;
    Airport& _airport;
    Simulator* _initCheck;
public:
    /**
     * \brief Returns the Exporter of the Simulator
     * @return Reference to AirportExporter
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
     */
    AirportExporter &getExporter() const;


    /**
     * \brief Returns the Airport of the Simulator
     * @return Reference to Airport
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
     */
    Airport &getAirport() const;

    /**
     * \brief Sets a new Airport for the Simulator
     * @param airport New Airport for the Simulator
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
     * - REQUIRE(airport.properlyInitialized(), "Airport is not initalized correctly");
     */
    void setAirport(Airport &airport);

    /**
     * \brief Checks if the Simulator class is initialized correctly
     * @return Returns true if the Simulator is correctly initialized
     */
    bool properlyInitalized() const;

    /**
     * \brief Constructor for Simulator
     * @param exporter Exporter for the Simulator
     * @param airport Airport for the Simulator
     *
     * **Preconditions:**
     * - REQUIRE(airport.properlyInitialized(), "Airport is not initalized correctly");
     * - REQUIRE(exporter.properlyInitialized(), "AirportExporter is not initalized correctly");
     *
     * **Postconditions:**
     * - ENSURE(this->properlyInitalized(), "Simulator is not initalized correctly");
     */
    Simulator(AirportExporter &exporter, Airport &airport);

    /**
     * \brief Does one tick of the simulation
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
     */
    void doSimulation();

    /**
     * \brief Does the simulation if an Airplane is approaching
     * @param plane Approaching airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
     * - REQUIRE(plane->properlyInitialized(), "Airplane plane is not initalized correctly");
     * - REQUIRE(plane->getStatus() == Airplane::APPROACHING, "Airplane should be APPROACHING");
     *
     * **Postconditions:**
     * - ENSURE(plane->getStatus() == Airplane::LANDING, "Airplane status should be set to LANDING");
     * - ENSURE(plane->getHeight() == 10000, "Height of the airplane should be 10000");
     */
    void doSimulationApproach(Airplane* plane);

    /**
     * \brief Does the simulation if an Airplane is landing
     * @param plane Landing airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initalized correctly");
     * - REQUIRE(plane->properlyInitialized(), "Airplane is not initalized correctly");
     * - REQUIRE(plane->getStatus() == Airplane::LANDING, "Airplane should be in LANDING status");
     *
     * **PostConditions:**
     * - ENSURE(plane->getStatus() == Airplane::LANDED || plane->getStatus() == Airplane::LANDING, "Unexpected status of airplane")
     */
    void doSimulationLanding(Airplane* plane);

    /**
     * \brief Does the simulation for a landed airplane
     * @param plane Landed airplane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
     * - REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly")
     * - REQUIRE(plane->getStatus() == Airplane::LANDED, "Airplane must be in LANDED state");
     *
     * **Postconditions:**
     * - ENSURE(plane->getStatus() == Airplane::LANDED, "Status of airplane should still be LANDED if there are no free Gates");
     * - ENSURE(plane->getStatus() == Airplane::TAXIING_TO_GATE, "Expected status to be TAXIING TO GATE");
     */
    void doSimulationLanded(Airplane* plane);

    /**
     * \brief Does the simulation for a taxiing plane
     * @param plane Taxiing plane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
     * - REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
     * - REQUIRE(plane->getStatus() == Airplane::TAXIING_TO_GATE, "Status of airplane has to be TAXIING TO GATE");
     *
     * **Postconditions:**
     * - ENSURE(plane->getStatus() == Airplane::AT_GATE, "Status of airplane should be AT GATE");
     */
    void doSimulationTaxiing(Airplane* plane);

    /**
     * \brief Does the simulation for a plane at a gate
     * @param plane Plane at a gate
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
     * - REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
     * - REQUIRE(plane->getStatus() == Airplane::AT_GATE, "Status of airplane should be AT GATE");
     *
     * **Postconditions:**
     * - ENSURE(plane->getFuelState() == Airplane::FULL, "Fuel state has to be FULL");
     * - ENSURE(plane->getStatus() == Airplane::STANDING, "Airplane state has to be STANDING");
     */
    void doSimulationAtGate(Airplane* plane);

    /**
     * \brief Does the simulation for a standing plane
     * @param plane Standing plane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
     * - REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
     * - REQUIRE(plane->getStatus() == Airplane::STANDING, "Status of airplane should be STANDING");
     *
     * **Postconditions:**
     * - ENSURE(plane->getStatus() == Airplane::DEPARTING, "Airplane status should be DEPARTING");
     * - ENSURE(currentGate->getPlaneAtGate() == NULL, "Gate should be empty");
     * - ENSURE(!freeRunway->getAirplanesOnRunway().empty(), "The free runway should contain at least one plane");
     */
    void doSimulationStanding(Airplane* plane);

    /**
     * \brief Does the simulation for a departing plane
     * @param plane Departing plane
     *
     * **Preconditions:**
     * - REQUIRE(this->properlyInitalized(), "Simulator is not initialized correctly");
     * - REQUIRE(plane->properlyInitialized(), "Airplane is not initialized correctly");
     * - REQUIRE(plane->getStatus() == Airplane::DEPARTING, "Airplane status should be DEPARTING");
     *
     * **Postconditions:**
     * - ENSURE(plane->getStatus() == Airplane::IN_AIR, "Status should be IN AIR if departed");
     * - ENSURE(plane->getStatus() == Airplane::DEPARTING, "Status should be Departing if plane has not left yet");
     */
    void doSimulationDeparting(Airplane* plane);

};


#endif //PROJECTSE_SIMULATOR_H
