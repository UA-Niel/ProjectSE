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
        classes/Gate.cpp
        classes/Gate.h
        classes/Runway.h
        classes/Runway.cpp
        classes/Airport.h
        classes/Airport.cpp
        classes/AirportFunctions.cpp
        classes/AirportFunctions.h        classes/Airplane.h
        classes/Airplane.cpp
        classes/AirportExporter.cpp
        classes/AirportExporter.h
        classes/Route.cpp
        classes/Route.h

        parsers/library/tinystr.cpp
        parsers/library/tinystr.h
        parsers/library/tinyxml.cpp
        parsers/library/tinyxml.h
        parsers/library/tinyxmlerror.cpp
        parsers/library/tinyxmlparser.cpp

        parsers/Reader.cpp
        parsers/Reader.h

        DesignByContract.h
        utils.cpp
        utils.h

        AirportOutputTests.h
        AirportOutputTests.cpp
        mainTests.cpp
        )

# Set source files for RELEASE target

set(RELEASE_SOURCE_FILES
        classes/Gate.cpp
        classes/Gate.h
        classes/Runway.h
        classes/Runway.cpp
        classes/Airport.h
        classes/Airport.cpp
        classes/AirportFunctions.cpp
        classes/AirportFunctions.h
        classes/Airplane.h
        classes/Airplane.cpp
        classes/AirportExporter.cpp
        classes/AirportExporter.h
        classes/Route.cpp
        classes/Route.h

        parsers/library/tinystr.cpp
        parsers/library/tinystr.h
        parsers/library/tinyxml.cpp
        parsers/library/tinyxml.h
        parsers/library/tinyxmlerror.cpp
        parsers/library/tinyxmlparser.cpp

        parsers/Reader.cpp
        parsers/Reader.h

        DesignByContract.h
        utils.cpp
        utils.h

        main.cpp
        )

# Create RELEASE target
add_executable(ProjectSE ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(ProjectSE_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ProjectSE_debug gtest)