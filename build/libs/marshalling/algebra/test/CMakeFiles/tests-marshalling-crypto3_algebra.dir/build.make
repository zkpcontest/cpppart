# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/repositories/tmp/ton-proof-verification-contest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/repositories/tmp/ton-proof-verification-contest/build

# Utility rule file for tests-marshalling-crypto3_algebra.

# Include any custom commands dependencies for this target.
include libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/progress.make

tests-marshalling-crypto3_algebra: libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/build.make
.PHONY : tests-marshalling-crypto3_algebra

# Rule to build all files generated by this target.
libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/build: tests-marshalling-crypto3_algebra
.PHONY : libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/build

libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/clean:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/marshalling/algebra/test && $(CMAKE_COMMAND) -P CMakeFiles/tests-marshalling-crypto3_algebra.dir/cmake_clean.cmake
.PHONY : libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/clean

libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/depend:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/repositories/tmp/ton-proof-verification-contest /home/user/repositories/tmp/ton-proof-verification-contest/libs/marshalling/algebra/test /home/user/repositories/tmp/ton-proof-verification-contest/build /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/marshalling/algebra/test /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/marshalling/algebra/test/CMakeFiles/tests-marshalling-crypto3_algebra.dir/depend

