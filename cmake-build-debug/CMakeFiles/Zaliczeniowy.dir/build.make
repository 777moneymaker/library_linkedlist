# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/milosz/Desktop/Projekty PP/projekt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/milosz/Desktop/Projekty PP/projekt/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Zaliczeniowy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Zaliczeniowy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Zaliczeniowy.dir/flags.make

CMakeFiles/Zaliczeniowy.dir/main.cpp.o: CMakeFiles/Zaliczeniowy.dir/flags.make
CMakeFiles/Zaliczeniowy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/milosz/Desktop/Projekty PP/projekt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Zaliczeniowy.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Zaliczeniowy.dir/main.cpp.o -c "/Users/milosz/Desktop/Projekty PP/projekt/main.cpp"

CMakeFiles/Zaliczeniowy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Zaliczeniowy.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/milosz/Desktop/Projekty PP/projekt/main.cpp" > CMakeFiles/Zaliczeniowy.dir/main.cpp.i

CMakeFiles/Zaliczeniowy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Zaliczeniowy.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/milosz/Desktop/Projekty PP/projekt/main.cpp" -o CMakeFiles/Zaliczeniowy.dir/main.cpp.s

# Object files for target Zaliczeniowy
Zaliczeniowy_OBJECTS = \
"CMakeFiles/Zaliczeniowy.dir/main.cpp.o"

# External object files for target Zaliczeniowy
Zaliczeniowy_EXTERNAL_OBJECTS =

Zaliczeniowy: CMakeFiles/Zaliczeniowy.dir/main.cpp.o
Zaliczeniowy: CMakeFiles/Zaliczeniowy.dir/build.make
Zaliczeniowy: CMakeFiles/Zaliczeniowy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/milosz/Desktop/Projekty PP/projekt/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Zaliczeniowy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Zaliczeniowy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Zaliczeniowy.dir/build: Zaliczeniowy

.PHONY : CMakeFiles/Zaliczeniowy.dir/build

CMakeFiles/Zaliczeniowy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Zaliczeniowy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Zaliczeniowy.dir/clean

CMakeFiles/Zaliczeniowy.dir/depend:
	cd "/Users/milosz/Desktop/Projekty PP/projekt/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/milosz/Desktop/Projekty PP/projekt" "/Users/milosz/Desktop/Projekty PP/projekt" "/Users/milosz/Desktop/Projekty PP/projekt/cmake-build-debug" "/Users/milosz/Desktop/Projekty PP/projekt/cmake-build-debug" "/Users/milosz/Desktop/Projekty PP/projekt/cmake-build-debug/CMakeFiles/Zaliczeniowy.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Zaliczeniowy.dir/depend

