# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/susan/school/csci-366-fall2020/battlebit/googletest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/battleBit_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/battleBit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/battleBit_tests.dir/flags.make

CMakeFiles/battleBit_tests.dir/char_buff.o: CMakeFiles/battleBit_tests.dir/flags.make
CMakeFiles/battleBit_tests.dir/char_buff.o: ../char_buff.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/battleBit_tests.dir/char_buff.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleBit_tests.dir/char_buff.o -c /home/susan/school/csci-366-fall2020/battlebit/googletest/char_buff.cpp

CMakeFiles/battleBit_tests.dir/char_buff.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleBit_tests.dir/char_buff.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susan/school/csci-366-fall2020/battlebit/googletest/char_buff.cpp > CMakeFiles/battleBit_tests.dir/char_buff.i

CMakeFiles/battleBit_tests.dir/char_buff.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleBit_tests.dir/char_buff.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susan/school/csci-366-fall2020/battlebit/googletest/char_buff.cpp -o CMakeFiles/battleBit_tests.dir/char_buff.s

CMakeFiles/battleBit_tests.dir/game.o: CMakeFiles/battleBit_tests.dir/flags.make
CMakeFiles/battleBit_tests.dir/game.o: ../game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/battleBit_tests.dir/game.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleBit_tests.dir/game.o -c /home/susan/school/csci-366-fall2020/battlebit/googletest/game.cpp

CMakeFiles/battleBit_tests.dir/game.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleBit_tests.dir/game.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susan/school/csci-366-fall2020/battlebit/googletest/game.cpp > CMakeFiles/battleBit_tests.dir/game.i

CMakeFiles/battleBit_tests.dir/game.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleBit_tests.dir/game.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susan/school/csci-366-fall2020/battlebit/googletest/game.cpp -o CMakeFiles/battleBit_tests.dir/game.s

CMakeFiles/battleBit_tests.dir/repl.o: CMakeFiles/battleBit_tests.dir/flags.make
CMakeFiles/battleBit_tests.dir/repl.o: ../repl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/battleBit_tests.dir/repl.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleBit_tests.dir/repl.o -c /home/susan/school/csci-366-fall2020/battlebit/googletest/repl.cpp

CMakeFiles/battleBit_tests.dir/repl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleBit_tests.dir/repl.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susan/school/csci-366-fall2020/battlebit/googletest/repl.cpp > CMakeFiles/battleBit_tests.dir/repl.i

CMakeFiles/battleBit_tests.dir/repl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleBit_tests.dir/repl.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susan/school/csci-366-fall2020/battlebit/googletest/repl.cpp -o CMakeFiles/battleBit_tests.dir/repl.s

# Object files for target battleBit_tests
battleBit_tests_OBJECTS = \
"CMakeFiles/battleBit_tests.dir/char_buff.o" \
"CMakeFiles/battleBit_tests.dir/game.o" \
"CMakeFiles/battleBit_tests.dir/repl.o"

# External object files for target battleBit_tests
battleBit_tests_EXTERNAL_OBJECTS =

battleBit_tests: CMakeFiles/battleBit_tests.dir/char_buff.o
battleBit_tests: CMakeFiles/battleBit_tests.dir/game.o
battleBit_tests: CMakeFiles/battleBit_tests.dir/repl.o
battleBit_tests: CMakeFiles/battleBit_tests.dir/build.make
battleBit_tests: lib/libgtestd.a
battleBit_tests: lib/libgtest_maind.a
battleBit_tests: lib/libgtestd.a
battleBit_tests: CMakeFiles/battleBit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable battleBit_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/battleBit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/battleBit_tests.dir/build: battleBit_tests

.PHONY : CMakeFiles/battleBit_tests.dir/build

CMakeFiles/battleBit_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/battleBit_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/battleBit_tests.dir/clean

CMakeFiles/battleBit_tests.dir/depend:
	cd /home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/susan/school/csci-366-fall2020/battlebit/googletest /home/susan/school/csci-366-fall2020/battlebit/googletest /home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug /home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug /home/susan/school/csci-366-fall2020/battlebit/googletest/cmake-build-debug/CMakeFiles/battleBit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/battleBit_tests.dir/depend
