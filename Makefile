# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\gebruiker\School\Project software engineering\ProjectSE"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\gebruiker\School\Project software engineering\ProjectSE"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	"C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "C:\Users\gebruiker\School\Project software engineering\ProjectSE\CMakeFiles" "C:\Users\gebruiker\School\Project software engineering\ProjectSE\CMakeFiles\progress.marks"
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "C:\Users\gebruiker\School\Project software engineering\ProjectSE\CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ProjectSE

# Build rule for target.
ProjectSE: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 ProjectSE
.PHONY : ProjectSE

# fast build rule for target.
ProjectSE/fast:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/build
.PHONY : ProjectSE/fast

#=============================================================================
# Target rules for targets named ProjectSE_debug

# Build rule for target.
ProjectSE_debug: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 ProjectSE_debug
.PHONY : ProjectSE_debug

# fast build rule for target.
ProjectSE_debug/fast:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/build
.PHONY : ProjectSE_debug/fast

headers/IO/library/tinystr.obj: headers/IO/library/tinystr.cpp.obj

.PHONY : headers/IO/library/tinystr.obj

# target to build an object file
headers/IO/library/tinystr.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinystr.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinystr.cpp.obj
.PHONY : headers/IO/library/tinystr.cpp.obj

headers/IO/library/tinystr.i: headers/IO/library/tinystr.cpp.i

.PHONY : headers/IO/library/tinystr.i

# target to preprocess a source file
headers/IO/library/tinystr.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinystr.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinystr.cpp.i
.PHONY : headers/IO/library/tinystr.cpp.i

headers/IO/library/tinystr.s: headers/IO/library/tinystr.cpp.s

.PHONY : headers/IO/library/tinystr.s

# target to generate assembly for a file
headers/IO/library/tinystr.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinystr.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinystr.cpp.s
.PHONY : headers/IO/library/tinystr.cpp.s

headers/IO/library/tinyxml.obj: headers/IO/library/tinyxml.cpp.obj

.PHONY : headers/IO/library/tinyxml.obj

# target to build an object file
headers/IO/library/tinyxml.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxml.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxml.cpp.obj
.PHONY : headers/IO/library/tinyxml.cpp.obj

headers/IO/library/tinyxml.i: headers/IO/library/tinyxml.cpp.i

.PHONY : headers/IO/library/tinyxml.i

# target to preprocess a source file
headers/IO/library/tinyxml.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxml.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxml.cpp.i
.PHONY : headers/IO/library/tinyxml.cpp.i

headers/IO/library/tinyxml.s: headers/IO/library/tinyxml.cpp.s

.PHONY : headers/IO/library/tinyxml.s

# target to generate assembly for a file
headers/IO/library/tinyxml.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxml.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxml.cpp.s
.PHONY : headers/IO/library/tinyxml.cpp.s

headers/IO/library/tinyxmlerror.obj: headers/IO/library/tinyxmlerror.cpp.obj

.PHONY : headers/IO/library/tinyxmlerror.obj

# target to build an object file
headers/IO/library/tinyxmlerror.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxmlerror.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxmlerror.cpp.obj
.PHONY : headers/IO/library/tinyxmlerror.cpp.obj

headers/IO/library/tinyxmlerror.i: headers/IO/library/tinyxmlerror.cpp.i

.PHONY : headers/IO/library/tinyxmlerror.i

# target to preprocess a source file
headers/IO/library/tinyxmlerror.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxmlerror.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxmlerror.cpp.i
.PHONY : headers/IO/library/tinyxmlerror.cpp.i

headers/IO/library/tinyxmlerror.s: headers/IO/library/tinyxmlerror.cpp.s

.PHONY : headers/IO/library/tinyxmlerror.s

# target to generate assembly for a file
headers/IO/library/tinyxmlerror.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxmlerror.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxmlerror.cpp.s
.PHONY : headers/IO/library/tinyxmlerror.cpp.s

headers/IO/library/tinyxmlparser.obj: headers/IO/library/tinyxmlparser.cpp.obj

.PHONY : headers/IO/library/tinyxmlparser.obj

# target to build an object file
headers/IO/library/tinyxmlparser.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxmlparser.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxmlparser.cpp.obj
.PHONY : headers/IO/library/tinyxmlparser.cpp.obj

headers/IO/library/tinyxmlparser.i: headers/IO/library/tinyxmlparser.cpp.i

.PHONY : headers/IO/library/tinyxmlparser.i

# target to preprocess a source file
headers/IO/library/tinyxmlparser.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxmlparser.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxmlparser.cpp.i
.PHONY : headers/IO/library/tinyxmlparser.cpp.i

headers/IO/library/tinyxmlparser.s: headers/IO/library/tinyxmlparser.cpp.s

.PHONY : headers/IO/library/tinyxmlparser.s

# target to generate assembly for a file
headers/IO/library/tinyxmlparser.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/headers/IO/library/tinyxmlparser.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/headers/IO/library/tinyxmlparser.cpp.s
.PHONY : headers/IO/library/tinyxmlparser.cpp.s

main.obj: main.cpp.obj

.PHONY : main.obj

# target to build an object file
main.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/main.cpp.obj
.PHONY : main.cpp.obj

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/main.cpp.s
.PHONY : main.cpp.s

mainTests.obj: mainTests.cpp.obj

.PHONY : mainTests.obj

# target to build an object file
mainTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/mainTests.cpp.obj
.PHONY : mainTests.cpp.obj

mainTests.i: mainTests.cpp.i

.PHONY : mainTests.i

# target to preprocess a source file
mainTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/mainTests.cpp.i
.PHONY : mainTests.cpp.i

mainTests.s: mainTests.cpp.s

.PHONY : mainTests.s

# target to generate assembly for a file
mainTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/mainTests.cpp.s
.PHONY : mainTests.cpp.s

other/testfiles/ATCTests.obj: other/testfiles/ATCTests.cpp.obj

.PHONY : other/testfiles/ATCTests.obj

# target to build an object file
other/testfiles/ATCTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ATCTests.cpp.obj
.PHONY : other/testfiles/ATCTests.cpp.obj

other/testfiles/ATCTests.i: other/testfiles/ATCTests.cpp.i

.PHONY : other/testfiles/ATCTests.i

# target to preprocess a source file
other/testfiles/ATCTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ATCTests.cpp.i
.PHONY : other/testfiles/ATCTests.cpp.i

other/testfiles/ATCTests.s: other/testfiles/ATCTests.cpp.s

.PHONY : other/testfiles/ATCTests.s

# target to generate assembly for a file
other/testfiles/ATCTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ATCTests.cpp.s
.PHONY : other/testfiles/ATCTests.cpp.s

other/testfiles/AirplaneTests.obj: other/testfiles/AirplaneTests.cpp.obj

.PHONY : other/testfiles/AirplaneTests.obj

# target to build an object file
other/testfiles/AirplaneTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirplaneTests.cpp.obj
.PHONY : other/testfiles/AirplaneTests.cpp.obj

other/testfiles/AirplaneTests.i: other/testfiles/AirplaneTests.cpp.i

.PHONY : other/testfiles/AirplaneTests.i

# target to preprocess a source file
other/testfiles/AirplaneTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirplaneTests.cpp.i
.PHONY : other/testfiles/AirplaneTests.cpp.i

other/testfiles/AirplaneTests.s: other/testfiles/AirplaneTests.cpp.s

.PHONY : other/testfiles/AirplaneTests.s

# target to generate assembly for a file
other/testfiles/AirplaneTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirplaneTests.cpp.s
.PHONY : other/testfiles/AirplaneTests.cpp.s

other/testfiles/AirportOutputTests.obj: other/testfiles/AirportOutputTests.cpp.obj

.PHONY : other/testfiles/AirportOutputTests.obj

# target to build an object file
other/testfiles/AirportOutputTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirportOutputTests.cpp.obj
.PHONY : other/testfiles/AirportOutputTests.cpp.obj

other/testfiles/AirportOutputTests.i: other/testfiles/AirportOutputTests.cpp.i

.PHONY : other/testfiles/AirportOutputTests.i

# target to preprocess a source file
other/testfiles/AirportOutputTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirportOutputTests.cpp.i
.PHONY : other/testfiles/AirportOutputTests.cpp.i

other/testfiles/AirportOutputTests.s: other/testfiles/AirportOutputTests.cpp.s

.PHONY : other/testfiles/AirportOutputTests.s

# target to generate assembly for a file
other/testfiles/AirportOutputTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirportOutputTests.cpp.s
.PHONY : other/testfiles/AirportOutputTests.cpp.s

other/testfiles/AirportTests.obj: other/testfiles/AirportTests.cpp.obj

.PHONY : other/testfiles/AirportTests.obj

# target to build an object file
other/testfiles/AirportTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirportTests.cpp.obj
.PHONY : other/testfiles/AirportTests.cpp.obj

other/testfiles/AirportTests.i: other/testfiles/AirportTests.cpp.i

.PHONY : other/testfiles/AirportTests.i

# target to preprocess a source file
other/testfiles/AirportTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirportTests.cpp.i
.PHONY : other/testfiles/AirportTests.cpp.i

other/testfiles/AirportTests.s: other/testfiles/AirportTests.cpp.s

.PHONY : other/testfiles/AirportTests.s

# target to generate assembly for a file
other/testfiles/AirportTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/AirportTests.cpp.s
.PHONY : other/testfiles/AirportTests.cpp.s

other/testfiles/ApTimeTests.obj: other/testfiles/ApTimeTests.cpp.obj

.PHONY : other/testfiles/ApTimeTests.obj

# target to build an object file
other/testfiles/ApTimeTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ApTimeTests.cpp.obj
.PHONY : other/testfiles/ApTimeTests.cpp.obj

other/testfiles/ApTimeTests.i: other/testfiles/ApTimeTests.cpp.i

.PHONY : other/testfiles/ApTimeTests.i

# target to preprocess a source file
other/testfiles/ApTimeTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ApTimeTests.cpp.i
.PHONY : other/testfiles/ApTimeTests.cpp.i

other/testfiles/ApTimeTests.s: other/testfiles/ApTimeTests.cpp.s

.PHONY : other/testfiles/ApTimeTests.s

# target to generate assembly for a file
other/testfiles/ApTimeTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ApTimeTests.cpp.s
.PHONY : other/testfiles/ApTimeTests.cpp.s

other/testfiles/GateTests.obj: other/testfiles/GateTests.cpp.obj

.PHONY : other/testfiles/GateTests.obj

# target to build an object file
other/testfiles/GateTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/GateTests.cpp.obj
.PHONY : other/testfiles/GateTests.cpp.obj

other/testfiles/GateTests.i: other/testfiles/GateTests.cpp.i

.PHONY : other/testfiles/GateTests.i

# target to preprocess a source file
other/testfiles/GateTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/GateTests.cpp.i
.PHONY : other/testfiles/GateTests.cpp.i

other/testfiles/GateTests.s: other/testfiles/GateTests.cpp.s

.PHONY : other/testfiles/GateTests.s

# target to generate assembly for a file
other/testfiles/GateTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/GateTests.cpp.s
.PHONY : other/testfiles/GateTests.cpp.s

other/testfiles/ReaderTest.obj: other/testfiles/ReaderTest.cpp.obj

.PHONY : other/testfiles/ReaderTest.obj

# target to build an object file
other/testfiles/ReaderTest.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ReaderTest.cpp.obj
.PHONY : other/testfiles/ReaderTest.cpp.obj

other/testfiles/ReaderTest.i: other/testfiles/ReaderTest.cpp.i

.PHONY : other/testfiles/ReaderTest.i

# target to preprocess a source file
other/testfiles/ReaderTest.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ReaderTest.cpp.i
.PHONY : other/testfiles/ReaderTest.cpp.i

other/testfiles/ReaderTest.s: other/testfiles/ReaderTest.cpp.s

.PHONY : other/testfiles/ReaderTest.s

# target to generate assembly for a file
other/testfiles/ReaderTest.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/ReaderTest.cpp.s
.PHONY : other/testfiles/ReaderTest.cpp.s

other/testfiles/RunwayTests.obj: other/testfiles/RunwayTests.cpp.obj

.PHONY : other/testfiles/RunwayTests.obj

# target to build an object file
other/testfiles/RunwayTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/RunwayTests.cpp.obj
.PHONY : other/testfiles/RunwayTests.cpp.obj

other/testfiles/RunwayTests.i: other/testfiles/RunwayTests.cpp.i

.PHONY : other/testfiles/RunwayTests.i

# target to preprocess a source file
other/testfiles/RunwayTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/RunwayTests.cpp.i
.PHONY : other/testfiles/RunwayTests.cpp.i

other/testfiles/RunwayTests.s: other/testfiles/RunwayTests.cpp.s

.PHONY : other/testfiles/RunwayTests.s

# target to generate assembly for a file
other/testfiles/RunwayTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/RunwayTests.cpp.s
.PHONY : other/testfiles/RunwayTests.cpp.s

other/testfiles/SimulatorTests.obj: other/testfiles/SimulatorTests.cpp.obj

.PHONY : other/testfiles/SimulatorTests.obj

# target to build an object file
other/testfiles/SimulatorTests.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/SimulatorTests.cpp.obj
.PHONY : other/testfiles/SimulatorTests.cpp.obj

other/testfiles/SimulatorTests.i: other/testfiles/SimulatorTests.cpp.i

.PHONY : other/testfiles/SimulatorTests.i

# target to preprocess a source file
other/testfiles/SimulatorTests.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/SimulatorTests.cpp.i
.PHONY : other/testfiles/SimulatorTests.cpp.i

other/testfiles/SimulatorTests.s: other/testfiles/SimulatorTests.cpp.s

.PHONY : other/testfiles/SimulatorTests.s

# target to generate assembly for a file
other/testfiles/SimulatorTests.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/other/testfiles/SimulatorTests.cpp.s
.PHONY : other/testfiles/SimulatorTests.cpp.s

source/ATC.obj: source/ATC.cpp.obj

.PHONY : source/ATC.obj

# target to build an object file
source/ATC.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/ATC.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/ATC.cpp.obj
.PHONY : source/ATC.cpp.obj

source/ATC.i: source/ATC.cpp.i

.PHONY : source/ATC.i

# target to preprocess a source file
source/ATC.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/ATC.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/ATC.cpp.i
.PHONY : source/ATC.cpp.i

source/ATC.s: source/ATC.cpp.s

.PHONY : source/ATC.s

# target to generate assembly for a file
source/ATC.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/ATC.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/ATC.cpp.s
.PHONY : source/ATC.cpp.s

source/Airplane.obj: source/Airplane.cpp.obj

.PHONY : source/Airplane.obj

# target to build an object file
source/Airplane.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Airplane.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Airplane.cpp.obj
.PHONY : source/Airplane.cpp.obj

source/Airplane.i: source/Airplane.cpp.i

.PHONY : source/Airplane.i

# target to preprocess a source file
source/Airplane.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Airplane.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Airplane.cpp.i
.PHONY : source/Airplane.cpp.i

source/Airplane.s: source/Airplane.cpp.s

.PHONY : source/Airplane.s

# target to generate assembly for a file
source/Airplane.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Airplane.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Airplane.cpp.s
.PHONY : source/Airplane.cpp.s

source/Airport.obj: source/Airport.cpp.obj

.PHONY : source/Airport.obj

# target to build an object file
source/Airport.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Airport.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Airport.cpp.obj
.PHONY : source/Airport.cpp.obj

source/Airport.i: source/Airport.cpp.i

.PHONY : source/Airport.i

# target to preprocess a source file
source/Airport.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Airport.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Airport.cpp.i
.PHONY : source/Airport.cpp.i

source/Airport.s: source/Airport.cpp.s

.PHONY : source/Airport.s

# target to generate assembly for a file
source/Airport.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Airport.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Airport.cpp.s
.PHONY : source/Airport.cpp.s

source/AirportExporter.obj: source/AirportExporter.cpp.obj

.PHONY : source/AirportExporter.obj

# target to build an object file
source/AirportExporter.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/AirportExporter.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/AirportExporter.cpp.obj
.PHONY : source/AirportExporter.cpp.obj

source/AirportExporter.i: source/AirportExporter.cpp.i

.PHONY : source/AirportExporter.i

# target to preprocess a source file
source/AirportExporter.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/AirportExporter.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/AirportExporter.cpp.i
.PHONY : source/AirportExporter.cpp.i

source/AirportExporter.s: source/AirportExporter.cpp.s

.PHONY : source/AirportExporter.s

# target to generate assembly for a file
source/AirportExporter.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/AirportExporter.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/AirportExporter.cpp.s
.PHONY : source/AirportExporter.cpp.s

source/ApTime.obj: source/ApTime.cpp.obj

.PHONY : source/ApTime.obj

# target to build an object file
source/ApTime.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/ApTime.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/ApTime.cpp.obj
.PHONY : source/ApTime.cpp.obj

source/ApTime.i: source/ApTime.cpp.i

.PHONY : source/ApTime.i

# target to preprocess a source file
source/ApTime.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/ApTime.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/ApTime.cpp.i
.PHONY : source/ApTime.cpp.i

source/ApTime.s: source/ApTime.cpp.s

.PHONY : source/ApTime.s

# target to generate assembly for a file
source/ApTime.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/ApTime.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/ApTime.cpp.s
.PHONY : source/ApTime.cpp.s

source/Gate.obj: source/Gate.cpp.obj

.PHONY : source/Gate.obj

# target to build an object file
source/Gate.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Gate.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Gate.cpp.obj
.PHONY : source/Gate.cpp.obj

source/Gate.i: source/Gate.cpp.i

.PHONY : source/Gate.i

# target to preprocess a source file
source/Gate.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Gate.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Gate.cpp.i
.PHONY : source/Gate.cpp.i

source/Gate.s: source/Gate.cpp.s

.PHONY : source/Gate.s

# target to generate assembly for a file
source/Gate.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Gate.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Gate.cpp.s
.PHONY : source/Gate.cpp.s

source/Reader.obj: source/Reader.cpp.obj

.PHONY : source/Reader.obj

# target to build an object file
source/Reader.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Reader.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Reader.cpp.obj
.PHONY : source/Reader.cpp.obj

source/Reader.i: source/Reader.cpp.i

.PHONY : source/Reader.i

# target to preprocess a source file
source/Reader.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Reader.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Reader.cpp.i
.PHONY : source/Reader.cpp.i

source/Reader.s: source/Reader.cpp.s

.PHONY : source/Reader.s

# target to generate assembly for a file
source/Reader.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Reader.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Reader.cpp.s
.PHONY : source/Reader.cpp.s

source/Runway.obj: source/Runway.cpp.obj

.PHONY : source/Runway.obj

# target to build an object file
source/Runway.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Runway.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Runway.cpp.obj
.PHONY : source/Runway.cpp.obj

source/Runway.i: source/Runway.cpp.i

.PHONY : source/Runway.i

# target to preprocess a source file
source/Runway.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Runway.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Runway.cpp.i
.PHONY : source/Runway.cpp.i

source/Runway.s: source/Runway.cpp.s

.PHONY : source/Runway.s

# target to generate assembly for a file
source/Runway.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Runway.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Runway.cpp.s
.PHONY : source/Runway.cpp.s

source/Simulator.obj: source/Simulator.cpp.obj

.PHONY : source/Simulator.obj

# target to build an object file
source/Simulator.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Simulator.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Simulator.cpp.obj
.PHONY : source/Simulator.cpp.obj

source/Simulator.i: source/Simulator.cpp.i

.PHONY : source/Simulator.i

# target to preprocess a source file
source/Simulator.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Simulator.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Simulator.cpp.i
.PHONY : source/Simulator.cpp.i

source/Simulator.s: source/Simulator.cpp.s

.PHONY : source/Simulator.s

# target to generate assembly for a file
source/Simulator.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/Simulator.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/Simulator.cpp.s
.PHONY : source/Simulator.cpp.s

source/utils.obj: source/utils.cpp.obj

.PHONY : source/utils.obj

# target to build an object file
source/utils.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/utils.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/utils.cpp.obj
.PHONY : source/utils.cpp.obj

source/utils.i: source/utils.cpp.i

.PHONY : source/utils.i

# target to preprocess a source file
source/utils.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/utils.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/utils.cpp.i
.PHONY : source/utils.cpp.i

source/utils.s: source/utils.cpp.s

.PHONY : source/utils.s

# target to generate assembly for a file
source/utils.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/source/utils.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/source/utils.cpp.s
.PHONY : source/utils.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... ProjectSE
	@echo ... ProjectSE_debug
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... headers/IO/library/tinystr.obj
	@echo ... headers/IO/library/tinystr.i
	@echo ... headers/IO/library/tinystr.s
	@echo ... headers/IO/library/tinyxml.obj
	@echo ... headers/IO/library/tinyxml.i
	@echo ... headers/IO/library/tinyxml.s
	@echo ... headers/IO/library/tinyxmlerror.obj
	@echo ... headers/IO/library/tinyxmlerror.i
	@echo ... headers/IO/library/tinyxmlerror.s
	@echo ... headers/IO/library/tinyxmlparser.obj
	@echo ... headers/IO/library/tinyxmlparser.i
	@echo ... headers/IO/library/tinyxmlparser.s
	@echo ... main.obj
	@echo ... main.i
	@echo ... main.s
	@echo ... mainTests.obj
	@echo ... mainTests.i
	@echo ... mainTests.s
	@echo ... other/testfiles/ATCTests.obj
	@echo ... other/testfiles/ATCTests.i
	@echo ... other/testfiles/ATCTests.s
	@echo ... other/testfiles/AirplaneTests.obj
	@echo ... other/testfiles/AirplaneTests.i
	@echo ... other/testfiles/AirplaneTests.s
	@echo ... other/testfiles/AirportOutputTests.obj
	@echo ... other/testfiles/AirportOutputTests.i
	@echo ... other/testfiles/AirportOutputTests.s
	@echo ... other/testfiles/AirportTests.obj
	@echo ... other/testfiles/AirportTests.i
	@echo ... other/testfiles/AirportTests.s
	@echo ... other/testfiles/ApTimeTests.obj
	@echo ... other/testfiles/ApTimeTests.i
	@echo ... other/testfiles/ApTimeTests.s
	@echo ... other/testfiles/GateTests.obj
	@echo ... other/testfiles/GateTests.i
	@echo ... other/testfiles/GateTests.s
	@echo ... other/testfiles/ReaderTest.obj
	@echo ... other/testfiles/ReaderTest.i
	@echo ... other/testfiles/ReaderTest.s
	@echo ... other/testfiles/RunwayTests.obj
	@echo ... other/testfiles/RunwayTests.i
	@echo ... other/testfiles/RunwayTests.s
	@echo ... other/testfiles/SimulatorTests.obj
	@echo ... other/testfiles/SimulatorTests.i
	@echo ... other/testfiles/SimulatorTests.s
	@echo ... source/ATC.obj
	@echo ... source/ATC.i
	@echo ... source/ATC.s
	@echo ... source/Airplane.obj
	@echo ... source/Airplane.i
	@echo ... source/Airplane.s
	@echo ... source/Airport.obj
	@echo ... source/Airport.i
	@echo ... source/Airport.s
	@echo ... source/AirportExporter.obj
	@echo ... source/AirportExporter.i
	@echo ... source/AirportExporter.s
	@echo ... source/ApTime.obj
	@echo ... source/ApTime.i
	@echo ... source/ApTime.s
	@echo ... source/Gate.obj
	@echo ... source/Gate.i
	@echo ... source/Gate.s
	@echo ... source/Reader.obj
	@echo ... source/Reader.i
	@echo ... source/Reader.s
	@echo ... source/Runway.obj
	@echo ... source/Runway.i
	@echo ... source/Runway.s
	@echo ... source/Simulator.obj
	@echo ... source/Simulator.i
	@echo ... source/Simulator.s
	@echo ... source/utils.obj
	@echo ... source/utils.i
	@echo ... source/utils.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

