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
include libs/modes/test/CMakeFiles/mode_ecb_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/modes/test/CMakeFiles/mode_ecb_test.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/modes/test/CMakeFiles/mode_ecb_test.dir/progress.make

# Include the compile flags for this target's objects.
include libs/modes/test/CMakeFiles/mode_ecb_test.dir/flags.make

libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.o: libs/modes/test/CMakeFiles/mode_ecb_test.dir/flags.make
libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.o: ../libs/modes/test/ecb.cpp
libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.o: libs/modes/test/CMakeFiles/mode_ecb_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.o"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/modes/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.o -MF CMakeFiles/mode_ecb_test.dir/ecb.cpp.o.d -o CMakeFiles/mode_ecb_test.dir/ecb.cpp.o -c /home/user/repositories/tmp/ton-proof-verification-contest/libs/modes/test/ecb.cpp

libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mode_ecb_test.dir/ecb.cpp.i"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/modes/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/repositories/tmp/ton-proof-verification-contest/libs/modes/test/ecb.cpp > CMakeFiles/mode_ecb_test.dir/ecb.cpp.i

libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mode_ecb_test.dir/ecb.cpp.s"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/modes/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/repositories/tmp/ton-proof-verification-contest/libs/modes/test/ecb.cpp -o CMakeFiles/mode_ecb_test.dir/ecb.cpp.s

# Object files for target mode_ecb_test
mode_ecb_test_OBJECTS = \
"CMakeFiles/mode_ecb_test.dir/ecb.cpp.o"

# External object files for target mode_ecb_test
mode_ecb_test_EXTERNAL_OBJECTS =

libs/modes/test/mode_ecb_test: libs/modes/test/CMakeFiles/mode_ecb_test.dir/ecb.cpp.o
libs/modes/test/mode_ecb_test: libs/modes/test/CMakeFiles/mode_ecb_test.dir/build.make
libs/modes/test/mode_ecb_test: /usr/lib/libboost_unit_test_framework.so.1.76.0
libs/modes/test/mode_ecb_test: /usr/lib/libboost_container.so.1.76.0
libs/modes/test/mode_ecb_test: /usr/lib/libboost_random.so.1.76.0
libs/modes/test/mode_ecb_test: /usr/lib/libboost_program_options.so.1.76.0
libs/modes/test/mode_ecb_test: /usr/lib/libboost_system.so.1.76.0
libs/modes/test/mode_ecb_test: libs/modes/test/CMakeFiles/mode_ecb_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mode_ecb_test"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/modes/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mode_ecb_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/modes/test/CMakeFiles/mode_ecb_test.dir/build: libs/modes/test/mode_ecb_test
.PHONY : libs/modes/test/CMakeFiles/mode_ecb_test.dir/build

libs/modes/test/CMakeFiles/mode_ecb_test.dir/clean:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/modes/test && $(CMAKE_COMMAND) -P CMakeFiles/mode_ecb_test.dir/cmake_clean.cmake
.PHONY : libs/modes/test/CMakeFiles/mode_ecb_test.dir/clean

libs/modes/test/CMakeFiles/mode_ecb_test.dir/depend:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/repositories/tmp/ton-proof-verification-contest /home/user/repositories/tmp/ton-proof-verification-contest/libs/modes/test /home/user/repositories/tmp/ton-proof-verification-contest/build /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/modes/test /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/modes/test/CMakeFiles/mode_ecb_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/modes/test/CMakeFiles/mode_ecb_test.dir/depend

