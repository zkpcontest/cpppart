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

# Include any dependencies generated for this target.
include libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/progress.make

# Include the compile flags for this target's objects.
include libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/flags.make

libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o: libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/flags.make
libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o: libs/mac/test/_cm_internal_tests-crypto3-mac.cpp
libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o: libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o -MF CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o.d -o CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o -c /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test/_cm_internal_tests-crypto3-mac.cpp

libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.i"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test/_cm_internal_tests-crypto3-mac.cpp > CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.i

libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.s"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test/_cm_internal_tests-crypto3-mac.cpp -o CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.s

# Object files for target _cm_internal_tests-crypto3-mac
_cm_internal_tests__crypto3__mac_OBJECTS = \
"CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o"

# External object files for target _cm_internal_tests-crypto3-mac
_cm_internal_tests__crypto3__mac_EXTERNAL_OBJECTS =

libs/mac/test/lib_cm_internal_tests-crypto3-mac.a: libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/_cm_internal_tests-crypto3-mac.cpp.o
libs/mac/test/lib_cm_internal_tests-crypto3-mac.a: libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/build.make
libs/mac/test/lib_cm_internal_tests-crypto3-mac.a: libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library lib_cm_internal_tests-crypto3-mac.a"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test && $(CMAKE_COMMAND) -P CMakeFiles/_cm_internal_tests-crypto3-mac.dir/cmake_clean_target.cmake
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_cm_internal_tests-crypto3-mac.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/build: libs/mac/test/lib_cm_internal_tests-crypto3-mac.a
.PHONY : libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/build

libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/clean:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test && $(CMAKE_COMMAND) -P CMakeFiles/_cm_internal_tests-crypto3-mac.dir/cmake_clean.cmake
.PHONY : libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/clean

libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/depend:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/repositories/tmp/ton-proof-verification-contest /home/user/repositories/tmp/ton-proof-verification-contest/libs/mac/test /home/user/repositories/tmp/ton-proof-verification-contest/build /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/mac/test/CMakeFiles/_cm_internal_tests-crypto3-mac.dir/depend

