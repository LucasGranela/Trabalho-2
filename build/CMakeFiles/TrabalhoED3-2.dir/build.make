# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/logranela/ED3/Trabalho-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/logranela/ED3/Trabalho-2/build

# Include any dependencies generated for this target.
include CMakeFiles/TrabalhoED3-2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrabalhoED3-2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrabalhoED3-2.dir/flags.make

CMakeFiles/TrabalhoED3-2.dir/main.c.o: CMakeFiles/TrabalhoED3-2.dir/flags.make
CMakeFiles/TrabalhoED3-2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/Trabalho-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TrabalhoED3-2.dir/main.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabalhoED3-2.dir/main.c.o   -c /home/logranela/ED3/Trabalho-2/main.c

CMakeFiles/TrabalhoED3-2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabalhoED3-2.dir/main.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/Trabalho-2/main.c > CMakeFiles/TrabalhoED3-2.dir/main.c.i

CMakeFiles/TrabalhoED3-2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabalhoED3-2.dir/main.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/Trabalho-2/main.c -o CMakeFiles/TrabalhoED3-2.dir/main.c.s

CMakeFiles/TrabalhoED3-2.dir/fornecido.c.o: CMakeFiles/TrabalhoED3-2.dir/flags.make
CMakeFiles/TrabalhoED3-2.dir/fornecido.c.o: ../fornecido.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/Trabalho-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TrabalhoED3-2.dir/fornecido.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabalhoED3-2.dir/fornecido.c.o   -c /home/logranela/ED3/Trabalho-2/fornecido.c

CMakeFiles/TrabalhoED3-2.dir/fornecido.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabalhoED3-2.dir/fornecido.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/Trabalho-2/fornecido.c > CMakeFiles/TrabalhoED3-2.dir/fornecido.c.i

CMakeFiles/TrabalhoED3-2.dir/fornecido.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabalhoED3-2.dir/fornecido.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/Trabalho-2/fornecido.c -o CMakeFiles/TrabalhoED3-2.dir/fornecido.c.s

CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.o: CMakeFiles/TrabalhoED3-2.dir/flags.make
CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.o: ../Utilizadas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/Trabalho-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.o   -c /home/logranela/ED3/Trabalho-2/Utilizadas.c

CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/Trabalho-2/Utilizadas.c > CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.i

CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/Trabalho-2/Utilizadas.c -o CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.s

# Object files for target TrabalhoED3-2
TrabalhoED3__2_OBJECTS = \
"CMakeFiles/TrabalhoED3-2.dir/main.c.o" \
"CMakeFiles/TrabalhoED3-2.dir/fornecido.c.o" \
"CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.o"

# External object files for target TrabalhoED3-2
TrabalhoED3__2_EXTERNAL_OBJECTS =

TrabalhoED3-2: CMakeFiles/TrabalhoED3-2.dir/main.c.o
TrabalhoED3-2: CMakeFiles/TrabalhoED3-2.dir/fornecido.c.o
TrabalhoED3-2: CMakeFiles/TrabalhoED3-2.dir/Utilizadas.c.o
TrabalhoED3-2: CMakeFiles/TrabalhoED3-2.dir/build.make
TrabalhoED3-2: CMakeFiles/TrabalhoED3-2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/logranela/ED3/Trabalho-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable TrabalhoED3-2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TrabalhoED3-2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrabalhoED3-2.dir/build: TrabalhoED3-2

.PHONY : CMakeFiles/TrabalhoED3-2.dir/build

CMakeFiles/TrabalhoED3-2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TrabalhoED3-2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TrabalhoED3-2.dir/clean

CMakeFiles/TrabalhoED3-2.dir/depend:
	cd /home/logranela/ED3/Trabalho-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/logranela/ED3/Trabalho-2 /home/logranela/ED3/Trabalho-2 /home/logranela/ED3/Trabalho-2/build /home/logranela/ED3/Trabalho-2/build /home/logranela/ED3/Trabalho-2/build/CMakeFiles/TrabalhoED3-2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrabalhoED3-2.dir/depend

