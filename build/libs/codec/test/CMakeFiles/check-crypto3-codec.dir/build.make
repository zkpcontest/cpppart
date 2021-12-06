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

# Utility rule file for check-crypto3-codec.

# Include any custom commands dependencies for this target.
include libs/codec/test/CMakeFiles/check-crypto3-codec.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/codec/test/CMakeFiles/check-crypto3-codec.dir/progress.make

libs/codec/test/CMakeFiles/check-crypto3-codec:
	/usr/bin/ctest -L crypto3-codec --output-on-failure -C . -j 16

check-crypto3-codec: libs/codec/test/CMakeFiles/check-crypto3-codec
check-crypto3-codec: libs/codec/test/CMakeFiles/check-crypto3-codec.dir/build.make
.PHONY : check-crypto3-codec

# Rule to build all files generated by this target.
libs/codec/test/CMakeFiles/check-crypto3-codec.dir/build: check-crypto3-codec
.PHONY : libs/codec/test/CMakeFiles/check-crypto3-codec.dir/build

libs/codec/test/CMakeFiles/check-crypto3-codec.dir/clean:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/codec/test && $(CMAKE_COMMAND) -P CMakeFiles/check-crypto3-codec.dir/cmake_clean.cmake
.PHONY : libs/codec/test/CMakeFiles/check-crypto3-codec.dir/clean

libs/codec/test/CMakeFiles/check-crypto3-codec.dir/depend:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/repositories/tmp/ton-proof-verification-contest /home/user/repositories/tmp/ton-proof-verification-contest/libs/codec/test /home/user/repositories/tmp/ton-proof-verification-contest/build /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/codec/test /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/codec/test/CMakeFiles/check-crypto3-codec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/codec/test/CMakeFiles/check-crypto3-codec.dir/depend
