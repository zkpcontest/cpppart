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
include test/CMakeFiles/_cm_internal_tests-nil-Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/_cm_internal_tests-nil-Project.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/_cm_internal_tests-nil-Project.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/_cm_internal_tests-nil-Project.dir/flags.make

test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o: test/CMakeFiles/_cm_internal_tests-nil-Project.dir/flags.make
test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o: test/_cm_internal_tests-nil-Project.cpp
test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o: test/CMakeFiles/_cm_internal_tests-nil-Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o -MF CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o.d -o CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o -c /home/user/repositories/tmp/ton-proof-verification-contest/build/test/_cm_internal_tests-nil-Project.cpp

test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.i"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/repositories/tmp/ton-proof-verification-contest/build/test/_cm_internal_tests-nil-Project.cpp > CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.i

test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.s"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/repositories/tmp/ton-proof-verification-contest/build/test/_cm_internal_tests-nil-Project.cpp -o CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.s

# Object files for target _cm_internal_tests-nil-Project
_cm_internal_tests__nil__Project_OBJECTS = \
"CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o"

# External object files for target _cm_internal_tests-nil-Project
_cm_internal_tests__nil__Project_EXTERNAL_OBJECTS =

test/lib_cm_internal_tests-nil-Project.a: test/CMakeFiles/_cm_internal_tests-nil-Project.dir/_cm_internal_tests-nil-Project.cpp.o
test/lib_cm_internal_tests-nil-Project.a: test/CMakeFiles/_cm_internal_tests-nil-Project.dir/build.make
test/lib_cm_internal_tests-nil-Project.a: test/CMakeFiles/_cm_internal_tests-nil-Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library lib_cm_internal_tests-nil-Project.a"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/test && $(CMAKE_COMMAND) -P CMakeFiles/_cm_internal_tests-nil-Project.dir/cmake_clean_target.cmake
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_cm_internal_tests-nil-Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/_cm_internal_tests-nil-Project.dir/build: test/lib_cm_internal_tests-nil-Project.a
.PHONY : test/CMakeFiles/_cm_internal_tests-nil-Project.dir/build

test/CMakeFiles/_cm_internal_tests-nil-Project.dir/clean:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/test && $(CMAKE_COMMAND) -P CMakeFiles/_cm_internal_tests-nil-Project.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/_cm_internal_tests-nil-Project.dir/clean

test/CMakeFiles/_cm_internal_tests-nil-Project.dir/depend:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/repositories/tmp/ton-proof-verification-contest /home/user/repositories/tmp/ton-proof-verification-contest/test /home/user/repositories/tmp/ton-proof-verification-contest/build /home/user/repositories/tmp/ton-proof-verification-contest/build/test /home/user/repositories/tmp/ton-proof-verification-contest/build/test/CMakeFiles/_cm_internal_tests-nil-Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/_cm_internal_tests-nil-Project.dir/depend

