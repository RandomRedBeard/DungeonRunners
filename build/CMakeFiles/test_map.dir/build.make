# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/thomas/miniconda3/bin/cmake

# The command to remove a file.
RM = /Users/thomas/miniconda3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/thomas/repository/dungeon_runners

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/thomas/repository/dungeon_runners/build

# Include any dependencies generated for this target.
include CMakeFiles/test_map.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_map.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_map.dir/flags.make

CMakeFiles/test_map.dir/tests/test_map.cpp.o: CMakeFiles/test_map.dir/flags.make
CMakeFiles/test_map.dir/tests/test_map.cpp.o: ../tests/test_map.cpp
CMakeFiles/test_map.dir/tests/test_map.cpp.o: CMakeFiles/test_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_map.dir/tests/test_map.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_map.dir/tests/test_map.cpp.o -MF CMakeFiles/test_map.dir/tests/test_map.cpp.o.d -o CMakeFiles/test_map.dir/tests/test_map.cpp.o -c /Users/thomas/repository/dungeon_runners/tests/test_map.cpp

CMakeFiles/test_map.dir/tests/test_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_map.dir/tests/test_map.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/tests/test_map.cpp > CMakeFiles/test_map.dir/tests/test_map.cpp.i

CMakeFiles/test_map.dir/tests/test_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_map.dir/tests/test_map.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/tests/test_map.cpp -o CMakeFiles/test_map.dir/tests/test_map.cpp.s

# Object files for target test_map
test_map_OBJECTS = \
"CMakeFiles/test_map.dir/tests/test_map.cpp.o"

# External object files for target test_map
test_map_EXTERNAL_OBJECTS =

test_map: CMakeFiles/test_map.dir/tests/test_map.cpp.o
test_map: CMakeFiles/test_map.dir/build.make
test_map: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurses.tbd
test_map: libDR.a
test_map: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurses.tbd
test_map: CMakeFiles/test_map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_map"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_map.dir/build: test_map
.PHONY : CMakeFiles/test_map.dir/build

CMakeFiles/test_map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_map.dir/clean

CMakeFiles/test_map.dir/depend:
	cd /Users/thomas/repository/dungeon_runners/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/thomas/repository/dungeon_runners /Users/thomas/repository/dungeon_runners /Users/thomas/repository/dungeon_runners/build /Users/thomas/repository/dungeon_runners/build /Users/thomas/repository/dungeon_runners/build/CMakeFiles/test_map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_map.dir/depend

