# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build

# Include any dependencies generated for this target.
include test/CMakeFiles/basic_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/basic_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/basic_test.dir/flags.make

test/CMakeFiles/basic_test.dir/basic_test.cc.o: test/CMakeFiles/basic_test.dir/flags.make
test/CMakeFiles/basic_test.dir/basic_test.cc.o: /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/basic_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/basic_test.dir/basic_test.cc.o"
	cd /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basic_test.dir/basic_test.cc.o -c /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/basic_test.cc

test/CMakeFiles/basic_test.dir/basic_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_test.dir/basic_test.cc.i"
	cd /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/basic_test.cc > CMakeFiles/basic_test.dir/basic_test.cc.i

test/CMakeFiles/basic_test.dir/basic_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_test.dir/basic_test.cc.s"
	cd /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/basic_test.cc -o CMakeFiles/basic_test.dir/basic_test.cc.s

# Object files for target basic_test
basic_test_OBJECTS = \
"CMakeFiles/basic_test.dir/basic_test.cc.o"

# External object files for target basic_test
basic_test_EXTERNAL_OBJECTS =

test/basic_test: test/CMakeFiles/basic_test.dir/basic_test.cc.o
test/basic_test: test/CMakeFiles/basic_test.dir/build.make
test/basic_test: src/libbenchmark.a
test/basic_test: /usr/lib/x86_64-linux-gnu/librt.so
test/basic_test: test/CMakeFiles/basic_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basic_test"
	cd /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basic_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/basic_test.dir/build: test/basic_test

.PHONY : test/CMakeFiles/basic_test.dir/build

test/CMakeFiles/basic_test.dir/clean:
	cd /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && $(CMAKE_COMMAND) -P CMakeFiles/basic_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/basic_test.dir/clean

test/CMakeFiles/basic_test.dir/depend:
	cd /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test /home/ah2719/Advanced_Databases/Coursework1/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test/CMakeFiles/basic_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/basic_test.dir/depend

