# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/buils

# Include any dependencies generated for this target.
include CMakeFiles/Lab6.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lab6.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab6.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab6.elf.dir/flags.make

CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj: CMakeFiles/Lab6.elf.dir/flags.make
CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj: ../src/Lab6.c
CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj: CMakeFiles/Lab6.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/buils/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj -MF CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj.d -o CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj -c /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/src/Lab6.c

CMakeFiles/Lab6.elf.dir/src/Lab6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab6.elf.dir/src/Lab6.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/src/Lab6.c > CMakeFiles/Lab6.elf.dir/src/Lab6.c.i

CMakeFiles/Lab6.elf.dir/src/Lab6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab6.elf.dir/src/Lab6.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/src/Lab6.c -o CMakeFiles/Lab6.elf.dir/src/Lab6.c.s

# Object files for target Lab6.elf
Lab6_elf_OBJECTS = \
"CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj"

# External object files for target Lab6.elf
Lab6_elf_EXTERNAL_OBJECTS =

Lab6.elf: CMakeFiles/Lab6.elf.dir/src/Lab6.c.obj
Lab6.elf: CMakeFiles/Lab6.elf.dir/build.make
Lab6.elf: HLED/libHLED.a
Lab6.elf: HSEVENSEG/libHSEVENSEG.a
Lab6.elf: MDIO/libMDIO.a
Lab6.elf: MPORT/libMPORT.a
Lab6.elf: CMakeFiles/Lab6.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/buils/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab6.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab6.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab6.elf.dir/build: Lab6.elf
.PHONY : CMakeFiles/Lab6.elf.dir/build

CMakeFiles/Lab6.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab6.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab6.elf.dir/clean

CMakeFiles/Lab6.elf.dir/depend:
	cd /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/buils && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6 /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6 /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/buils /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/buils /home/mariam/ITI_ES_INTAKE45/APPS/Labs/Lab6/buils/CMakeFiles/Lab6.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab6.elf.dir/depend

