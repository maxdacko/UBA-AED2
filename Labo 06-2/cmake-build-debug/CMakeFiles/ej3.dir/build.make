# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ej3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej3.dir/flags.make

CMakeFiles/ej3.dir/tests/test_templates.cpp.o: CMakeFiles/ej3.dir/flags.make
CMakeFiles/ej3.dir/tests/test_templates.cpp.o: ../tests/test_templates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej3.dir/tests/test_templates.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej3.dir/tests/test_templates.cpp.o -c "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/tests/test_templates.cpp"

CMakeFiles/ej3.dir/tests/test_templates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej3.dir/tests/test_templates.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/tests/test_templates.cpp" > CMakeFiles/ej3.dir/tests/test_templates.cpp.i

CMakeFiles/ej3.dir/tests/test_templates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej3.dir/tests/test_templates.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/tests/test_templates.cpp" -o CMakeFiles/ej3.dir/tests/test_templates.cpp.s

# Object files for target ej3
ej3_OBJECTS = \
"CMakeFiles/ej3.dir/tests/test_templates.cpp.o"

# External object files for target ej3
ej3_EXTERNAL_OBJECTS =

ej3: CMakeFiles/ej3.dir/tests/test_templates.cpp.o
ej3: CMakeFiles/ej3.dir/build.make
ej3: tests/google-test/libgtest.a
ej3: tests/google-test/libgtest_main.a
ej3: tests/google-test/libgtest.a
ej3: CMakeFiles/ej3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej3.dir/build: ej3

.PHONY : CMakeFiles/ej3.dir/build

CMakeFiles/ej3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej3.dir/clean

CMakeFiles/ej3.dir/depend:
	cd "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2" "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2" "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/cmake-build-debug" "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/cmake-build-debug" "/mnt/c/Users/Max Dacko/OneDrive/Escritorio/1er Cuatri 2022/Ejercicios Labo/Labo 06-2/cmake-build-debug/CMakeFiles/ej3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ej3.dir/depend
