# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/arminveres/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/arminveres/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arminveres/GitHubFiles/ADCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arminveres/GitHubFiles/ADCPP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ADCPP.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ADCPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ADCPP.dir/flags.make

CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.o: CMakeFiles/ADCPP.dir/flags.make
CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.o: ../Exercise_01/helloWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arminveres/GitHubFiles/ADCPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.o -c /home/arminveres/GitHubFiles/ADCPP/Exercise_01/helloWorld.cpp

CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arminveres/GitHubFiles/ADCPP/Exercise_01/helloWorld.cpp > CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.i

CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arminveres/GitHubFiles/ADCPP/Exercise_01/helloWorld.cpp -o CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.s

CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.o: CMakeFiles/ADCPP.dir/flags.make
CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.o: ../Exercise_01/txtConverter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arminveres/GitHubFiles/ADCPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.o -c /home/arminveres/GitHubFiles/ADCPP/Exercise_01/txtConverter.cpp

CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arminveres/GitHubFiles/ADCPP/Exercise_01/txtConverter.cpp > CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.i

CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arminveres/GitHubFiles/ADCPP/Exercise_01/txtConverter.cpp -o CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.s

# Object files for target ADCPP
ADCPP_OBJECTS = \
"CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.o" \
"CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.o"

# External object files for target ADCPP
ADCPP_EXTERNAL_OBJECTS =

ADCPP: CMakeFiles/ADCPP.dir/Exercise_01/helloWorld.cpp.o
ADCPP: CMakeFiles/ADCPP.dir/Exercise_01/txtConverter.cpp.o
ADCPP: CMakeFiles/ADCPP.dir/build.make
ADCPP: CMakeFiles/ADCPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arminveres/GitHubFiles/ADCPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ADCPP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ADCPP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ADCPP.dir/build: ADCPP
.PHONY : CMakeFiles/ADCPP.dir/build

CMakeFiles/ADCPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ADCPP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ADCPP.dir/clean

CMakeFiles/ADCPP.dir/depend:
	cd /home/arminveres/GitHubFiles/ADCPP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arminveres/GitHubFiles/ADCPP /home/arminveres/GitHubFiles/ADCPP /home/arminveres/GitHubFiles/ADCPP/cmake-build-debug /home/arminveres/GitHubFiles/ADCPP/cmake-build-debug /home/arminveres/GitHubFiles/ADCPP/cmake-build-debug/CMakeFiles/ADCPP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ADCPP.dir/depend

