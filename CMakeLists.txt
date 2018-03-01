cmake_minimum_required(VERSION 3.6)
project(ProjectSE)

set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_FLAGS "-Wall -Werror") TODO: aanzetten
#set(CMAKE_EXE_LINKER_FLAGS -pthread) TODO: aanzetten

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES
        headers/Airplane.cpp
        headers/Airplane.h
        headers/Airport.cpp
        headers/Airport.h
        headers/Runway.cpp
        headers/Runway.h
        main.cpp)

# Set source files for DEBUG target TODO: update with correct files
set(DEBUG_SOURCE_FILES
        headers/Airport.cpp
        main.cpp)

# Create RELEASE target
add_executable(ProjectSE ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(ProjectSE_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ProjectSE_debug gtest)