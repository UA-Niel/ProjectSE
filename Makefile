# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe" -E remove -f

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
	"C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe" -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\JetBrains\CLion 2017.3.3\bin\cmake\bin\cmake.exe" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
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

system/Airplane.obj: system/Airplane.cpp.obj

.PHONY : system/Airplane.obj

# target to build an object file
system/Airplane.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Airplane.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Airplane.cpp.obj
.PHONY : system/Airplane.cpp.obj

system/Airplane.i: system/Airplane.cpp.i

.PHONY : system/Airplane.i

# target to preprocess a source file
system/Airplane.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Airplane.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Airplane.cpp.i
.PHONY : system/Airplane.cpp.i

system/Airplane.s: system/Airplane.cpp.s

.PHONY : system/Airplane.s

# target to generate assembly for a file
system/Airplane.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Airplane.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Airplane.cpp.s
.PHONY : system/Airplane.cpp.s

system/Airport.obj: system/Airport.cpp.obj

.PHONY : system/Airport.obj

# target to build an object file
system/Airport.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Airport.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Airport.cpp.obj
.PHONY : system/Airport.cpp.obj

system/Airport.i: system/Airport.cpp.i

.PHONY : system/Airport.i

# target to preprocess a source file
system/Airport.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Airport.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Airport.cpp.i
.PHONY : system/Airport.cpp.i

system/Airport.s: system/Airport.cpp.s

.PHONY : system/Airport.s

# target to generate assembly for a file
system/Airport.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Airport.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Airport.cpp.s
.PHONY : system/Airport.cpp.s

system/AirportExporter.obj: system/AirportExporter.cpp.obj

.PHONY : system/AirportExporter.obj

# target to build an object file
system/AirportExporter.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/AirportExporter.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/AirportExporter.cpp.obj
.PHONY : system/AirportExporter.cpp.obj

system/AirportExporter.i: system/AirportExporter.cpp.i

.PHONY : system/AirportExporter.i

# target to preprocess a source file
system/AirportExporter.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/AirportExporter.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/AirportExporter.cpp.i
.PHONY : system/AirportExporter.cpp.i

system/AirportExporter.s: system/AirportExporter.cpp.s

.PHONY : system/AirportExporter.s

# target to generate assembly for a file
system/AirportExporter.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/AirportExporter.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/AirportExporter.cpp.s
.PHONY : system/AirportExporter.cpp.s

system/Gate.obj: system/Gate.cpp.obj

.PHONY : system/Gate.obj

# target to build an object file
system/Gate.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Gate.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Gate.cpp.obj
.PHONY : system/Gate.cpp.obj

system/Gate.i: system/Gate.cpp.i

.PHONY : system/Gate.i

# target to preprocess a source file
system/Gate.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Gate.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Gate.cpp.i
.PHONY : system/Gate.cpp.i

system/Gate.s: system/Gate.cpp.s

.PHONY : system/Gate.s

# target to generate assembly for a file
system/Gate.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Gate.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Gate.cpp.s
.PHONY : system/Gate.cpp.s

system/Reader.obj: system/Reader.cpp.obj

.PHONY : system/Reader.obj

# target to build an object file
system/Reader.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Reader.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Reader.cpp.obj
.PHONY : system/Reader.cpp.obj

system/Reader.i: system/Reader.cpp.i

.PHONY : system/Reader.i

# target to preprocess a source file
system/Reader.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Reader.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Reader.cpp.i
.PHONY : system/Reader.cpp.i

system/Reader.s: system/Reader.cpp.s

.PHONY : system/Reader.s

# target to generate assembly for a file
system/Reader.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Reader.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Reader.cpp.s
.PHONY : system/Reader.cpp.s

system/Runway.obj: system/Runway.cpp.obj

.PHONY : system/Runway.obj

# target to build an object file
system/Runway.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Runway.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Runway.cpp.obj
.PHONY : system/Runway.cpp.obj

system/Runway.i: system/Runway.cpp.i

.PHONY : system/Runway.i

# target to preprocess a source file
system/Runway.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Runway.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Runway.cpp.i
.PHONY : system/Runway.cpp.i

system/Runway.s: system/Runway.cpp.s

.PHONY : system/Runway.s

# target to generate assembly for a file
system/Runway.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Runway.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Runway.cpp.s
.PHONY : system/Runway.cpp.s

system/Simulator.obj: system/Simulator.cpp.obj

.PHONY : system/Simulator.obj

# target to build an object file
system/Simulator.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Simulator.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Simulator.cpp.obj
.PHONY : system/Simulator.cpp.obj

system/Simulator.i: system/Simulator.cpp.i

.PHONY : system/Simulator.i

# target to preprocess a source file
system/Simulator.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Simulator.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Simulator.cpp.i
.PHONY : system/Simulator.cpp.i

system/Simulator.s: system/Simulator.cpp.s

.PHONY : system/Simulator.s

# target to generate assembly for a file
system/Simulator.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/Simulator.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/Simulator.cpp.s
.PHONY : system/Simulator.cpp.s

system/utils.obj: system/utils.cpp.obj

.PHONY : system/utils.obj

# target to build an object file
system/utils.cpp.obj:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/utils.cpp.obj
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/utils.cpp.obj
.PHONY : system/utils.cpp.obj

system/utils.i: system/utils.cpp.i

.PHONY : system/utils.i

# target to preprocess a source file
system/utils.cpp.i:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/utils.cpp.i
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/utils.cpp.i
.PHONY : system/utils.cpp.i

system/utils.s: system/utils.cpp.s

.PHONY : system/utils.s

# target to generate assembly for a file
system/utils.cpp.s:
	$(MAKE) -f CMakeFiles\ProjectSE.dir\build.make CMakeFiles/ProjectSE.dir/system/utils.cpp.s
	$(MAKE) -f CMakeFiles\ProjectSE_debug.dir\build.make CMakeFiles/ProjectSE_debug.dir/system/utils.cpp.s
.PHONY : system/utils.cpp.s

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
	@echo ... other/testfiles/AirplaneTests.obj
	@echo ... other/testfiles/AirplaneTests.i
	@echo ... other/testfiles/AirplaneTests.s
	@echo ... other/testfiles/AirportOutputTests.obj
	@echo ... other/testfiles/AirportOutputTests.i
	@echo ... other/testfiles/AirportOutputTests.s
	@echo ... other/testfiles/AirportTests.obj
	@echo ... other/testfiles/AirportTests.i
	@echo ... other/testfiles/AirportTests.s
	@echo ... other/testfiles/GateTests.obj
	@echo ... other/testfiles/GateTests.i
	@echo ... other/testfiles/GateTests.s
	@echo ... other/testfiles/ReaderTest.obj
	@echo ... other/testfiles/ReaderTest.i
	@echo ... other/testfiles/ReaderTest.s
	@echo ... other/testfiles/RunwayTests.obj
	@echo ... other/testfiles/RunwayTests.i
	@echo ... other/testfiles/RunwayTests.s
	@echo ... system/Airplane.obj
	@echo ... system/Airplane.i
	@echo ... system/Airplane.s
	@echo ... system/Airport.obj
	@echo ... system/Airport.i
	@echo ... system/Airport.s
	@echo ... system/AirportExporter.obj
	@echo ... system/AirportExporter.i
	@echo ... system/AirportExporter.s
	@echo ... system/Gate.obj
	@echo ... system/Gate.i
	@echo ... system/Gate.s
	@echo ... system/Reader.obj
	@echo ... system/Reader.i
	@echo ... system/Reader.s
	@echo ... system/Runway.obj
	@echo ... system/Runway.i
	@echo ... system/Runway.s
	@echo ... system/Simulator.obj
	@echo ... system/Simulator.i
	@echo ... system/Simulator.s
	@echo ... system/utils.obj
	@echo ... system/utils.i
	@echo ... system/utils.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

