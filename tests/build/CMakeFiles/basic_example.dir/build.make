# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/lhb/long/github/smallcv/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/lhb/long/github/smallcv/tests/build

# Include any dependencies generated for this target.
include CMakeFiles/basic_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/basic_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basic_example.dir/flags.make

CMakeFiles/basic_example.dir/example.cpp.o: CMakeFiles/basic_example.dir/flags.make
CMakeFiles/basic_example.dir/example.cpp.o: ../example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/lhb/long/github/smallcv/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/basic_example.dir/example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basic_example.dir/example.cpp.o -c /media/lhb/long/github/smallcv/tests/example.cpp

CMakeFiles/basic_example.dir/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_example.dir/example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/lhb/long/github/smallcv/tests/example.cpp > CMakeFiles/basic_example.dir/example.cpp.i

CMakeFiles/basic_example.dir/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_example.dir/example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/lhb/long/github/smallcv/tests/example.cpp -o CMakeFiles/basic_example.dir/example.cpp.s

# Object files for target basic_example
basic_example_OBJECTS = \
"CMakeFiles/basic_example.dir/example.cpp.o"

# External object files for target basic_example
basic_example_EXTERNAL_OBJECTS =

basic_example: CMakeFiles/basic_example.dir/example.cpp.o
basic_example: CMakeFiles/basic_example.dir/build.make
basic_example: CMakeFiles/basic_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/lhb/long/github/smallcv/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basic_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basic_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basic_example.dir/build: basic_example

.PHONY : CMakeFiles/basic_example.dir/build

CMakeFiles/basic_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/basic_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/basic_example.dir/clean

CMakeFiles/basic_example.dir/depend:
	cd /media/lhb/long/github/smallcv/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/lhb/long/github/smallcv/tests /media/lhb/long/github/smallcv/tests /media/lhb/long/github/smallcv/tests/build /media/lhb/long/github/smallcv/tests/build /media/lhb/long/github/smallcv/tests/build/CMakeFiles/basic_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basic_example.dir/depend
