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

# Utility rule file for check-crypto3-multiprecision.

# Include any custom commands dependencies for this target.
include libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/progress.make

libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision:
	/usr/bin/ctest -L crypto3-multiprecision --output-on-failure -C . -j 16

check-crypto3-multiprecision: libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision
check-crypto3-multiprecision: libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/build.make
.PHONY : check-crypto3-multiprecision

# Rule to build all files generated by this target.
libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/build: check-crypto3-multiprecision
.PHONY : libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/build

libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/clean:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test && $(CMAKE_COMMAND) -P CMakeFiles/check-crypto3-multiprecision.dir/cmake_clean.cmake
.PHONY : libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/clean

libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/depend:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/repositories/tmp/ton-proof-verification-contest /home/user/repositories/tmp/ton-proof-verification-contest/libs/multiprecision/test /home/user/repositories/tmp/ton-proof-verification-contest/build /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/multiprecision/test/CMakeFiles/check-crypto3-multiprecision.dir/depend

