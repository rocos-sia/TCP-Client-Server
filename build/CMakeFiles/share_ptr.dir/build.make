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
CMAKE_SOURCE_DIR = /home/abc418/cpp_examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abc418/cpp_examples/build

# Include any dependencies generated for this target.
include CMakeFiles/share_ptr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/share_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/share_ptr.dir/flags.make

CMakeFiles/share_ptr.dir/src/share_ptr.cpp.o: CMakeFiles/share_ptr.dir/flags.make
CMakeFiles/share_ptr.dir/src/share_ptr.cpp.o: ../src/share_ptr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc418/cpp_examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/share_ptr.dir/src/share_ptr.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/share_ptr.dir/src/share_ptr.cpp.o -c /home/abc418/cpp_examples/src/share_ptr.cpp

CMakeFiles/share_ptr.dir/src/share_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/share_ptr.dir/src/share_ptr.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc418/cpp_examples/src/share_ptr.cpp > CMakeFiles/share_ptr.dir/src/share_ptr.cpp.i

CMakeFiles/share_ptr.dir/src/share_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/share_ptr.dir/src/share_ptr.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc418/cpp_examples/src/share_ptr.cpp -o CMakeFiles/share_ptr.dir/src/share_ptr.cpp.s

# Object files for target share_ptr
share_ptr_OBJECTS = \
"CMakeFiles/share_ptr.dir/src/share_ptr.cpp.o"

# External object files for target share_ptr
share_ptr_EXTERNAL_OBJECTS =

../bin/share_ptr: CMakeFiles/share_ptr.dir/src/share_ptr.cpp.o
../bin/share_ptr: CMakeFiles/share_ptr.dir/build.make
../bin/share_ptr: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
../bin/share_ptr: CMakeFiles/share_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abc418/cpp_examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/share_ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/share_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/share_ptr.dir/build: ../bin/share_ptr

.PHONY : CMakeFiles/share_ptr.dir/build

CMakeFiles/share_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/share_ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/share_ptr.dir/clean

CMakeFiles/share_ptr.dir/depend:
	cd /home/abc418/cpp_examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abc418/cpp_examples /home/abc418/cpp_examples /home/abc418/cpp_examples/build /home/abc418/cpp_examples/build /home/abc418/cpp_examples/build/CMakeFiles/share_ptr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/share_ptr.dir/depend
