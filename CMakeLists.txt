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
        headers/AirportFunctions.h
        headers/Airplane.h
        headers/IO/AirportExporter.h
        headers/Route.h
        system/Gate.cpp
        system/Runway.cpp
        system/Airport.cpp
        system/AirportFunctions.cpp
        system/Airplane.cpp
        system/AirportExporter.cpp
        system/Route.cpp

        headers/IO/library/tinystr.cpp
        headers/IO/library/tinystr.h
        headers/IO/library/tinyxml.cpp
        headers/IO/library/tinyxml.h
        headers/IO/library/tinyxmlerror.cpp
        headers/IO/library/tinyxmlparser.cpp

        system/Reader.cpp
        headers/IO/Reader.h

        headers/DesignByContract.h
        system/utils.cpp
        headers/utils.h

        other/testfiles/AirportOutputTests.h
        other/testfiles/AirportOutputTests.cpp
        other/testfiles/AirportTests.h
        other/testfiles/AirportTests.cpp
        other/testfiles/ReaderTest.cpp
        other/testfiles/ReaderTest.h
        mainTests.cpp
        other/testfiles/RunwayTests.cpp
        other/testfiles/RunwayTests.h other/testfiles/GateTests.cpp other/testfiles/GateTests.h other/testfiles/AirplaneTests.cpp other/testfiles/AirplaneTests.h)

# Set source files for RELEASE target

set(RELEASE_SOURCE_FILES
        headers/Gate.h
        headers/Runway.h
        headers/Airport.h
        headers/AirportFunctions.h
        headers/Airplane.h
        headers/IO/AirportExporter.h
        headers/Route.h
        system/Gate.cpp
        system/Runway.cpp
        system/Airport.cpp
        system/AirportFunctions.cpp
        system/Airplane.cpp
        system/AirportExporter.cpp
        system/Route.cpp

        headers/IO/library/tinystr.cpp
        headers/IO/library/tinystr.h
        headers/IO/library/tinyxml.cpp
        headers/IO/library/tinyxml.h
        headers/IO/library/tinyxmlerror.cpp
        headers/IO/library/tinyxmlparser.cpp

        system/Reader.cpp
        headers/IO/Reader.h

        headers/DesignByContract.h
        system/utils.cpp
        headers/utils.h

        main.cpp
        )

# Create RELEASE target
add_executable(ProjectSE ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(ProjectSE_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ProjectSE_debug gtest)
