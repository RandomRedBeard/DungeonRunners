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
include CMakeFiles/DR.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DR.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DR.dir/flags.make

CMakeFiles/DR.dir/src/arg.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/arg.cpp.o: ../src/arg.cpp
CMakeFiles/DR.dir/src/arg.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DR.dir/src/arg.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/arg.cpp.o -MF CMakeFiles/DR.dir/src/arg.cpp.o.d -o CMakeFiles/DR.dir/src/arg.cpp.o -c /Users/thomas/repository/dungeon_runners/src/arg.cpp

CMakeFiles/DR.dir/src/arg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/arg.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/arg.cpp > CMakeFiles/DR.dir/src/arg.cpp.i

CMakeFiles/DR.dir/src/arg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/arg.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/arg.cpp -o CMakeFiles/DR.dir/src/arg.cpp.s

CMakeFiles/DR.dir/src/c_graphics.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/c_graphics.cpp.o: ../src/c_graphics.cpp
CMakeFiles/DR.dir/src/c_graphics.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DR.dir/src/c_graphics.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/c_graphics.cpp.o -MF CMakeFiles/DR.dir/src/c_graphics.cpp.o.d -o CMakeFiles/DR.dir/src/c_graphics.cpp.o -c /Users/thomas/repository/dungeon_runners/src/c_graphics.cpp

CMakeFiles/DR.dir/src/c_graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/c_graphics.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/c_graphics.cpp > CMakeFiles/DR.dir/src/c_graphics.cpp.i

CMakeFiles/DR.dir/src/c_graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/c_graphics.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/c_graphics.cpp -o CMakeFiles/DR.dir/src/c_graphics.cpp.s

CMakeFiles/DR.dir/src/hallway.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/hallway.cpp.o: ../src/hallway.cpp
CMakeFiles/DR.dir/src/hallway.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DR.dir/src/hallway.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/hallway.cpp.o -MF CMakeFiles/DR.dir/src/hallway.cpp.o.d -o CMakeFiles/DR.dir/src/hallway.cpp.o -c /Users/thomas/repository/dungeon_runners/src/hallway.cpp

CMakeFiles/DR.dir/src/hallway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/hallway.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/hallway.cpp > CMakeFiles/DR.dir/src/hallway.cpp.i

CMakeFiles/DR.dir/src/hallway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/hallway.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/hallway.cpp -o CMakeFiles/DR.dir/src/hallway.cpp.s

CMakeFiles/DR.dir/src/instance.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/instance.cpp.o: ../src/instance.cpp
CMakeFiles/DR.dir/src/instance.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DR.dir/src/instance.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/instance.cpp.o -MF CMakeFiles/DR.dir/src/instance.cpp.o.d -o CMakeFiles/DR.dir/src/instance.cpp.o -c /Users/thomas/repository/dungeon_runners/src/instance.cpp

CMakeFiles/DR.dir/src/instance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/instance.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/instance.cpp > CMakeFiles/DR.dir/src/instance.cpp.i

CMakeFiles/DR.dir/src/instance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/instance.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/instance.cpp -o CMakeFiles/DR.dir/src/instance.cpp.s

CMakeFiles/DR.dir/src/map.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/map.cpp.o: ../src/map.cpp
CMakeFiles/DR.dir/src/map.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DR.dir/src/map.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/map.cpp.o -MF CMakeFiles/DR.dir/src/map.cpp.o.d -o CMakeFiles/DR.dir/src/map.cpp.o -c /Users/thomas/repository/dungeon_runners/src/map.cpp

CMakeFiles/DR.dir/src/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/map.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/map.cpp > CMakeFiles/DR.dir/src/map.cpp.i

CMakeFiles/DR.dir/src/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/map.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/map.cpp -o CMakeFiles/DR.dir/src/map.cpp.s

CMakeFiles/DR.dir/src/map_pathfinder.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/map_pathfinder.cpp.o: ../src/map_pathfinder.cpp
CMakeFiles/DR.dir/src/map_pathfinder.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DR.dir/src/map_pathfinder.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/map_pathfinder.cpp.o -MF CMakeFiles/DR.dir/src/map_pathfinder.cpp.o.d -o CMakeFiles/DR.dir/src/map_pathfinder.cpp.o -c /Users/thomas/repository/dungeon_runners/src/map_pathfinder.cpp

CMakeFiles/DR.dir/src/map_pathfinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/map_pathfinder.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/map_pathfinder.cpp > CMakeFiles/DR.dir/src/map_pathfinder.cpp.i

CMakeFiles/DR.dir/src/map_pathfinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/map_pathfinder.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/map_pathfinder.cpp -o CMakeFiles/DR.dir/src/map_pathfinder.cpp.s

CMakeFiles/DR.dir/src/message.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/message.cpp.o: ../src/message.cpp
CMakeFiles/DR.dir/src/message.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DR.dir/src/message.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/message.cpp.o -MF CMakeFiles/DR.dir/src/message.cpp.o.d -o CMakeFiles/DR.dir/src/message.cpp.o -c /Users/thomas/repository/dungeon_runners/src/message.cpp

CMakeFiles/DR.dir/src/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/message.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/message.cpp > CMakeFiles/DR.dir/src/message.cpp.i

CMakeFiles/DR.dir/src/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/message.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/message.cpp -o CMakeFiles/DR.dir/src/message.cpp.s

CMakeFiles/DR.dir/src/monster.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/monster.cpp.o: ../src/monster.cpp
CMakeFiles/DR.dir/src/monster.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/DR.dir/src/monster.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/monster.cpp.o -MF CMakeFiles/DR.dir/src/monster.cpp.o.d -o CMakeFiles/DR.dir/src/monster.cpp.o -c /Users/thomas/repository/dungeon_runners/src/monster.cpp

CMakeFiles/DR.dir/src/monster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/monster.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/monster.cpp > CMakeFiles/DR.dir/src/monster.cpp.i

CMakeFiles/DR.dir/src/monster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/monster.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/monster.cpp -o CMakeFiles/DR.dir/src/monster.cpp.s

CMakeFiles/DR.dir/src/oid.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/oid.cpp.o: ../src/oid.cpp
CMakeFiles/DR.dir/src/oid.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/DR.dir/src/oid.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/oid.cpp.o -MF CMakeFiles/DR.dir/src/oid.cpp.o.d -o CMakeFiles/DR.dir/src/oid.cpp.o -c /Users/thomas/repository/dungeon_runners/src/oid.cpp

CMakeFiles/DR.dir/src/oid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/oid.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/oid.cpp > CMakeFiles/DR.dir/src/oid.cpp.i

CMakeFiles/DR.dir/src/oid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/oid.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/oid.cpp -o CMakeFiles/DR.dir/src/oid.cpp.s

CMakeFiles/DR.dir/src/pathfinder.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/pathfinder.cpp.o: ../src/pathfinder.cpp
CMakeFiles/DR.dir/src/pathfinder.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/DR.dir/src/pathfinder.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/pathfinder.cpp.o -MF CMakeFiles/DR.dir/src/pathfinder.cpp.o.d -o CMakeFiles/DR.dir/src/pathfinder.cpp.o -c /Users/thomas/repository/dungeon_runners/src/pathfinder.cpp

CMakeFiles/DR.dir/src/pathfinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/pathfinder.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/pathfinder.cpp > CMakeFiles/DR.dir/src/pathfinder.cpp.i

CMakeFiles/DR.dir/src/pathfinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/pathfinder.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/pathfinder.cpp -o CMakeFiles/DR.dir/src/pathfinder.cpp.s

CMakeFiles/DR.dir/src/player.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/player.cpp.o: ../src/player.cpp
CMakeFiles/DR.dir/src/player.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/DR.dir/src/player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/player.cpp.o -MF CMakeFiles/DR.dir/src/player.cpp.o.d -o CMakeFiles/DR.dir/src/player.cpp.o -c /Users/thomas/repository/dungeon_runners/src/player.cpp

CMakeFiles/DR.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/player.cpp > CMakeFiles/DR.dir/src/player.cpp.i

CMakeFiles/DR.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/player.cpp -o CMakeFiles/DR.dir/src/player.cpp.s

CMakeFiles/DR.dir/src/point.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/point.cpp.o: ../src/point.cpp
CMakeFiles/DR.dir/src/point.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/DR.dir/src/point.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/point.cpp.o -MF CMakeFiles/DR.dir/src/point.cpp.o.d -o CMakeFiles/DR.dir/src/point.cpp.o -c /Users/thomas/repository/dungeon_runners/src/point.cpp

CMakeFiles/DR.dir/src/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/point.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/point.cpp > CMakeFiles/DR.dir/src/point.cpp.i

CMakeFiles/DR.dir/src/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/point.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/point.cpp -o CMakeFiles/DR.dir/src/point.cpp.s

CMakeFiles/DR.dir/src/pointpath.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/pointpath.cpp.o: ../src/pointpath.cpp
CMakeFiles/DR.dir/src/pointpath.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/DR.dir/src/pointpath.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/pointpath.cpp.o -MF CMakeFiles/DR.dir/src/pointpath.cpp.o.d -o CMakeFiles/DR.dir/src/pointpath.cpp.o -c /Users/thomas/repository/dungeon_runners/src/pointpath.cpp

CMakeFiles/DR.dir/src/pointpath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/pointpath.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/pointpath.cpp > CMakeFiles/DR.dir/src/pointpath.cpp.i

CMakeFiles/DR.dir/src/pointpath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/pointpath.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/pointpath.cpp -o CMakeFiles/DR.dir/src/pointpath.cpp.s

CMakeFiles/DR.dir/src/rect.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/rect.cpp.o: ../src/rect.cpp
CMakeFiles/DR.dir/src/rect.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/DR.dir/src/rect.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/rect.cpp.o -MF CMakeFiles/DR.dir/src/rect.cpp.o.d -o CMakeFiles/DR.dir/src/rect.cpp.o -c /Users/thomas/repository/dungeon_runners/src/rect.cpp

CMakeFiles/DR.dir/src/rect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/rect.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/rect.cpp > CMakeFiles/DR.dir/src/rect.cpp.i

CMakeFiles/DR.dir/src/rect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/rect.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/rect.cpp -o CMakeFiles/DR.dir/src/rect.cpp.s

CMakeFiles/DR.dir/src/room.cpp.o: CMakeFiles/DR.dir/flags.make
CMakeFiles/DR.dir/src/room.cpp.o: ../src/room.cpp
CMakeFiles/DR.dir/src/room.cpp.o: CMakeFiles/DR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/DR.dir/src/room.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DR.dir/src/room.cpp.o -MF CMakeFiles/DR.dir/src/room.cpp.o.d -o CMakeFiles/DR.dir/src/room.cpp.o -c /Users/thomas/repository/dungeon_runners/src/room.cpp

CMakeFiles/DR.dir/src/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DR.dir/src/room.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/thomas/repository/dungeon_runners/src/room.cpp > CMakeFiles/DR.dir/src/room.cpp.i

CMakeFiles/DR.dir/src/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DR.dir/src/room.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/thomas/repository/dungeon_runners/src/room.cpp -o CMakeFiles/DR.dir/src/room.cpp.s

# Object files for target DR
DR_OBJECTS = \
"CMakeFiles/DR.dir/src/arg.cpp.o" \
"CMakeFiles/DR.dir/src/c_graphics.cpp.o" \
"CMakeFiles/DR.dir/src/hallway.cpp.o" \
"CMakeFiles/DR.dir/src/instance.cpp.o" \
"CMakeFiles/DR.dir/src/map.cpp.o" \
"CMakeFiles/DR.dir/src/map_pathfinder.cpp.o" \
"CMakeFiles/DR.dir/src/message.cpp.o" \
"CMakeFiles/DR.dir/src/monster.cpp.o" \
"CMakeFiles/DR.dir/src/oid.cpp.o" \
"CMakeFiles/DR.dir/src/pathfinder.cpp.o" \
"CMakeFiles/DR.dir/src/player.cpp.o" \
"CMakeFiles/DR.dir/src/point.cpp.o" \
"CMakeFiles/DR.dir/src/pointpath.cpp.o" \
"CMakeFiles/DR.dir/src/rect.cpp.o" \
"CMakeFiles/DR.dir/src/room.cpp.o"

# External object files for target DR
DR_EXTERNAL_OBJECTS =

libDR.a: CMakeFiles/DR.dir/src/arg.cpp.o
libDR.a: CMakeFiles/DR.dir/src/c_graphics.cpp.o
libDR.a: CMakeFiles/DR.dir/src/hallway.cpp.o
libDR.a: CMakeFiles/DR.dir/src/instance.cpp.o
libDR.a: CMakeFiles/DR.dir/src/map.cpp.o
libDR.a: CMakeFiles/DR.dir/src/map_pathfinder.cpp.o
libDR.a: CMakeFiles/DR.dir/src/message.cpp.o
libDR.a: CMakeFiles/DR.dir/src/monster.cpp.o
libDR.a: CMakeFiles/DR.dir/src/oid.cpp.o
libDR.a: CMakeFiles/DR.dir/src/pathfinder.cpp.o
libDR.a: CMakeFiles/DR.dir/src/player.cpp.o
libDR.a: CMakeFiles/DR.dir/src/point.cpp.o
libDR.a: CMakeFiles/DR.dir/src/pointpath.cpp.o
libDR.a: CMakeFiles/DR.dir/src/rect.cpp.o
libDR.a: CMakeFiles/DR.dir/src/room.cpp.o
libDR.a: CMakeFiles/DR.dir/build.make
libDR.a: CMakeFiles/DR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/thomas/repository/dungeon_runners/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX static library libDR.a"
	$(CMAKE_COMMAND) -P CMakeFiles/DR.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DR.dir/build: libDR.a
.PHONY : CMakeFiles/DR.dir/build

CMakeFiles/DR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DR.dir/clean

CMakeFiles/DR.dir/depend:
	cd /Users/thomas/repository/dungeon_runners/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/thomas/repository/dungeon_runners /Users/thomas/repository/dungeon_runners /Users/thomas/repository/dungeon_runners/build /Users/thomas/repository/dungeon_runners/build /Users/thomas/repository/dungeon_runners/build/CMakeFiles/DR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DR.dir/depend

