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
CMAKE_SOURCE_DIR = /home/nina/учеба/технопарк/HomeWork2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nina/учеба/технопарк/HomeWork2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parallel_dynamic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parallel_dynamic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parallel_dynamic.dir/flags.make

CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.o: CMakeFiles/parallel_dynamic.dir/flags.make
CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.o: ../parallel_dynamic/logic_parallel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/учеба/технопарк/HomeWork2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.o   -c /home/nina/учеба/технопарк/HomeWork2/parallel_dynamic/logic_parallel.c

CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nina/учеба/технопарк/HomeWork2/parallel_dynamic/logic_parallel.c > CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.i

CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nina/учеба/технопарк/HomeWork2/parallel_dynamic/logic_parallel.c -o CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.s

# Object files for target parallel_dynamic
parallel_dynamic_OBJECTS = \
"CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.o"

# External object files for target parallel_dynamic
parallel_dynamic_EXTERNAL_OBJECTS =

libparallel_dynamic.so: CMakeFiles/parallel_dynamic.dir/parallel_dynamic/logic_parallel.c.o
libparallel_dynamic.so: CMakeFiles/parallel_dynamic.dir/build.make
libparallel_dynamic.so: CMakeFiles/parallel_dynamic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nina/учеба/технопарк/HomeWork2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libparallel_dynamic.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parallel_dynamic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parallel_dynamic.dir/build: libparallel_dynamic.so

.PHONY : CMakeFiles/parallel_dynamic.dir/build

CMakeFiles/parallel_dynamic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parallel_dynamic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parallel_dynamic.dir/clean

CMakeFiles/parallel_dynamic.dir/depend:
	cd /home/nina/учеба/технопарк/HomeWork2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nina/учеба/технопарк/HomeWork2 /home/nina/учеба/технопарк/HomeWork2 /home/nina/учеба/технопарк/HomeWork2/cmake-build-debug /home/nina/учеба/технопарк/HomeWork2/cmake-build-debug /home/nina/учеба/технопарк/HomeWork2/cmake-build-debug/CMakeFiles/parallel_dynamic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parallel_dynamic.dir/depend

