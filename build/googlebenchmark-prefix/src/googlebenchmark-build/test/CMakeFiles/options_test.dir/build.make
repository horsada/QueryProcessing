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
CMAKE_SOURCE_DIR = /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build

# Include any dependencies generated for this target.
include test/CMakeFiles/options_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/options_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/options_test.dir/flags.make

test/CMakeFiles/options_test.dir/options_test.cc.o: test/CMakeFiles/options_test.dir/flags.make
test/CMakeFiles/options_test.dir/options_test.cc.o: /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/options_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/options_test.dir/options_test.cc.o"
	cd /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/options_test.dir/options_test.cc.o -c /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/options_test.cc

test/CMakeFiles/options_test.dir/options_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/options_test.dir/options_test.cc.i"
	cd /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/options_test.cc > CMakeFiles/options_test.dir/options_test.cc.i

test/CMakeFiles/options_test.dir/options_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/options_test.dir/options_test.cc.s"
	cd /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test/options_test.cc -o CMakeFiles/options_test.dir/options_test.cc.s

# Object files for target options_test
options_test_OBJECTS = \
"CMakeFiles/options_test.dir/options_test.cc.o"

# External object files for target options_test
options_test_EXTERNAL_OBJECTS =

test/options_test: test/CMakeFiles/options_test.dir/options_test.cc.o
test/options_test: test/CMakeFiles/options_test.dir/build.make
test/options_test: src/libbenchmark.a
test/options_test: /usr/lib/x86_64-linux-gnu/librt.so
test/options_test: test/CMakeFiles/options_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable options_test"
	cd /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/options_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/options_test.dir/build: test/options_test

.PHONY : test/CMakeFiles/options_test.dir/build

test/CMakeFiles/options_test.dir/clean:
	cd /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test && $(CMAKE_COMMAND) -P CMakeFiles/options_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/options_test.dir/clean

test/CMakeFiles/options_test.dir/depend:
	cd /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark/test /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test /homes/ah2719/Advanced_Databases/Query_Processing_ah2719/build/googlebenchmark-prefix/src/googlebenchmark-build/test/CMakeFiles/options_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/options_test.dir/depend
