# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/wangqing/Desktop/C:C++/Demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangqing/Desktop/C:C++/Demo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/encry.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/encry.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/encry.dir/flags.make

CMakeFiles/encry.dir/encryption/encrypt.c.o: CMakeFiles/encry.dir/flags.make
CMakeFiles/encry.dir/encryption/encrypt.c.o: ../encryption/encrypt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/C:C++/Demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/encry.dir/encryption/encrypt.c.o"
	/usr/local/Cellar/gcc/9.1.0/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/encry.dir/encryption/encrypt.c.o   -c /Users/wangqing/Desktop/C:C++/Demo/encryption/encrypt.c

CMakeFiles/encry.dir/encryption/encrypt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/encry.dir/encryption/encrypt.c.i"
	/usr/local/Cellar/gcc/9.1.0/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wangqing/Desktop/C:C++/Demo/encryption/encrypt.c > CMakeFiles/encry.dir/encryption/encrypt.c.i

CMakeFiles/encry.dir/encryption/encrypt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/encry.dir/encryption/encrypt.c.s"
	/usr/local/Cellar/gcc/9.1.0/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wangqing/Desktop/C:C++/Demo/encryption/encrypt.c -o CMakeFiles/encry.dir/encryption/encrypt.c.s

# Object files for target encry
encry_OBJECTS = \
"CMakeFiles/encry.dir/encryption/encrypt.c.o"

# External object files for target encry
encry_EXTERNAL_OBJECTS =

encry: CMakeFiles/encry.dir/encryption/encrypt.c.o
encry: CMakeFiles/encry.dir/build.make
encry: CMakeFiles/encry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangqing/Desktop/C:C++/Demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable encry"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/encry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/encry.dir/build: encry

.PHONY : CMakeFiles/encry.dir/build

CMakeFiles/encry.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/encry.dir/cmake_clean.cmake
.PHONY : CMakeFiles/encry.dir/clean

CMakeFiles/encry.dir/depend:
	cd /Users/wangqing/Desktop/C:C++/Demo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangqing/Desktop/C:C++/Demo /Users/wangqing/Desktop/C:C++/Demo /Users/wangqing/Desktop/C:C++/Demo/cmake-build-debug /Users/wangqing/Desktop/C:C++/Demo/cmake-build-debug /Users/wangqing/Desktop/C:C++/Demo/cmake-build-debug/CMakeFiles/encry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/encry.dir/depend
