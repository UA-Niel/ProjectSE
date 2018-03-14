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
set(GLOB DEBUG_SOURCE_FILES
        classes/*.h
        classes/*.cpp
        parsers/*.h
        parsers/*.cpp
        parsers/library/*.cpp
        parsers/library/*.h
        )

list(APPEND DEBUG_SOURCE_FILES
        mainTests.cpp
        AirportOutputTests.cpp
        AirportOutputTests.h
        utils.h
        utils.cpp
        DesignByContract.h
        )

# Set source files for RELEASE target
file(GLOB RELEASE_SOURCE_FILES
        classes/*.h
        classes/*.cpp
        parsers/*.h
        parsers/*.cpp
        parsers/library/*.cpp
        parsers/library/*.h
        )


list(APPEND RELEASE_SOURCE_FILES
        main.cpp
        utils.h
        utils.cpp
        DesignByContract.h
        )

# Create RELEASE target
add_executable(ProjectSE ${RELEASE_SOURCE_FILES} AirportOutputTests.cpp AirportOutputTests.h)

# Create DEBUG target
add_executable(ProjectSE_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ProjectSE_debug gtest)