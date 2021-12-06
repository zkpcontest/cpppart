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
include libs/multiprecision/test/CMakeFiles/no_eh_support.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/multiprecision/test/CMakeFiles/no_eh_support.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/multiprecision/test/CMakeFiles/no_eh_support.dir/progress.make

# Include the compile flags for this target's objects.
include libs/multiprecision/test/CMakeFiles/no_eh_support.dir/flags.make

libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o: libs/multiprecision/test/CMakeFiles/no_eh_support.dir/flags.make
libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o: ../libs/multiprecision/test/no_eh_test_support.cpp
libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o: libs/multiprecision/test/CMakeFiles/no_eh_support.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o -MF CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o.d -o CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o -c /home/user/repositories/tmp/ton-proof-verification-contest/libs/multiprecision/test/no_eh_test_support.cpp

libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.i"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/repositories/tmp/ton-proof-verification-contest/libs/multiprecision/test/no_eh_test_support.cpp > CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.i

libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.s"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/repositories/tmp/ton-proof-verification-contest/libs/multiprecision/test/no_eh_test_support.cpp -o CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.s

# Object files for target no_eh_support
no_eh_support_OBJECTS = \
"CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o"

# External object files for target no_eh_support
no_eh_support_EXTERNAL_OBJECTS =

libs/multiprecision/test/libno_eh_support.so: libs/multiprecision/test/CMakeFiles/no_eh_support.dir/no_eh_test_support.cpp.o
libs/multiprecision/test/libno_eh_support.so: libs/multiprecision/test/CMakeFiles/no_eh_support.dir/build.make
libs/multiprecision/test/libno_eh_support.so: libs/multiprecision/test/CMakeFiles/no_eh_support.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/repositories/tmp/ton-proof-verification-contest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libno_eh_support.so"
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/no_eh_support.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/multiprecision/test/CMakeFiles/no_eh_support.dir/build: libs/multiprecision/test/libno_eh_support.so
.PHONY : libs/multiprecision/test/CMakeFiles/no_eh_support.dir/build

libs/multiprecision/test/CMakeFiles/no_eh_support.dir/clean:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test && $(CMAKE_COMMAND) -P CMakeFiles/no_eh_support.dir/cmake_clean.cmake
.PHONY : libs/multiprecision/test/CMakeFiles/no_eh_support.dir/clean

libs/multiprecision/test/CMakeFiles/no_eh_support.dir/depend:
	cd /home/user/repositories/tmp/ton-proof-verification-contest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/repositories/tmp/ton-proof-verification-contest /home/user/repositories/tmp/ton-proof-verification-contest/libs/multiprecision/test /home/user/repositories/tmp/ton-proof-verification-contest/build /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test /home/user/repositories/tmp/ton-proof-verification-contest/build/libs/multiprecision/test/CMakeFiles/no_eh_support.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/multiprecision/test/CMakeFiles/no_eh_support.dir/depend
