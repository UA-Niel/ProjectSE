cmake_minimum_required(VERSION 3.6)
project(ProjectSE)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)
# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for DEBUG target

set(DEBUG_SOURCE_FILES
        headers/Gate.h
        headers/Runway.h
        headers/Airport.h
        headers/Airplane.h
        headers/IO/AirportExporter.h
        headers/Simulator.h
        headers/Exceptions.h
        headers/ApTime.h
        headers/ATC.h
        source/Gate.cpp
        source/Runway.cpp
        source/Airport.cpp
        source/Airplane.cpp
        source/AirportExporter.cpp
        source/Simulator.cpp
        source/ApTime.cpp
        source/ATC.cpp

        headers/IO/library/tinystr.cpp
        headers/IO/library/tinystr.h
        headers/IO/library/tinyxml.cpp
        headers/IO/library/tinyxml.h
        headers/IO/library/tinyxmlerror.cpp
        headers/IO/library/tinyxmlparser.cpp

        source/Reader.cpp
        headers/IO/Reader.h

        headers/DesignByContract.h
        source/utils.cpp
        headers/utils.h

        other/testfiles/AirportOutputTests.h
        other/testfiles/AirportOutputTests.cpp
        other/testfiles/AirportTests.h
        other/testfiles/AirportTests.cpp
        other/testfiles/ReaderTest.cpp
        other/testfiles/ReaderTest.h
        other/testfiles/ATCTests.h
        other/testfiles/ATCTests.cpp
        other/testfiles/ApTimeTests.h
        other/testfiles/ApTimeTests.cpp
        other/testfiles/SimulatorTests.h
        other/testfiles/SimulatorTests.cpp
        mainTests.cpp
        other/testfiles/RunwayTests.cpp
        other/testfiles/RunwayTests.h other/testfiles/GateTests.cpp other/testfiles/GateTests.h other/testfiles/AirplaneTests.cpp other/testfiles/AirplaneTests.h other/testfiles/SimulatorTests.cpp other/testfiles/SimulatorTests.h other/testfiles/ApTimeTests.cpp other/testfiles/ApTimeTests.h other/testfiles/ATCTests.cpp other/testfiles/ATCTests.h)

# Set source files for RELEASE target

set(RELEASE_SOURCE_FILES
        headers/Gate.h
        headers/Runway.h
        headers/Airport.h
        headers/Airplane.h
        headers/IO/AirportExporter.h
        headers/Simulator.h
        headers/Exceptions.h
        headers/ApTime.h
        headers/ATC.h
        source/Gate.cpp
        source/Runway.cpp
        source/Airport.cpp
        source/Airplane.cpp
        source/AirportExporter.cpp
        source/Simulator.cpp
        source/ApTime.cpp
        source/ATC.cpp

        headers/IO/library/tinystr.cpp
        headers/IO/library/tinystr.h
        headers/IO/library/tinyxml.cpp
        headers/IO/library/tinyxml.h
        headers/IO/library/tinyxmlerror.cpp
        headers/IO/library/tinyxmlparser.cpp

        source/Reader.cpp
        headers/IO/Reader.h

        headers/DesignByContract.h
        source/utils.cpp
        headers/utils.h

        main.cpp
        )

# Create RELEASE target
add_executable(ProjectSE ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(ProjectSE_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ProjectSE_debug gtest)
