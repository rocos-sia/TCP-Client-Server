# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/abc418/桌面/C++_exsamples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abc418/桌面/C++_exsamples/build

# Include any dependencies generated for this target.
include CMakeFiles/read.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/read.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/read.dir/flags.make

CMakeFiles/read.dir/src/read.cpp.o: CMakeFiles/read.dir/flags.make
CMakeFiles/read.dir/src/read.cpp.o: ../src/read.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abc418/桌面/C++_exsamples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/read.dir/src/read.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/read.dir/src/read.cpp.o -c /home/abc418/桌面/C++_exsamples/src/read.cpp

CMakeFiles/read.dir/src/read.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/read.dir/src/read.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abc418/桌面/C++_exsamples/src/read.cpp > CMakeFiles/read.dir/src/read.cpp.i

CMakeFiles/read.dir/src/read.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/read.dir/src/read.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abc418/桌面/C++_exsamples/src/read.cpp -o CMakeFiles/read.dir/src/read.cpp.s

CMakeFiles/read.dir/src/read.cpp.o.requires:

.PHONY : CMakeFiles/read.dir/src/read.cpp.o.requires

CMakeFiles/read.dir/src/read.cpp.o.provides: CMakeFiles/read.dir/src/read.cpp.o.requires
	$(MAKE) -f CMakeFiles/read.dir/build.make CMakeFiles/read.dir/src/read.cpp.o.provides.build
.PHONY : CMakeFiles/read.dir/src/read.cpp.o.provides

CMakeFiles/read.dir/src/read.cpp.o.provides.build: CMakeFiles/read.dir/src/read.cpp.o


# Object files for target read
read_OBJECTS = \
"CMakeFiles/read.dir/src/read.cpp.o"

# External object files for target read
read_EXTERNAL_OBJECTS =

../bin/read: CMakeFiles/read.dir/src/read.cpp.o
../bin/read: CMakeFiles/read.dir/build.make
../bin/read: /usr/lib/x86_64-linux-gnu/libboost_system.so
../bin/read: CMakeFiles/read.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abc418/桌面/C++_exsamples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/read"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/read.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/read.dir/build: ../bin/read

.PHONY : CMakeFiles/read.dir/build

CMakeFiles/read.dir/requires: CMakeFiles/read.dir/src/read.cpp.o.requires

.PHONY : CMakeFiles/read.dir/requires

CMakeFiles/read.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/read.dir/cmake_clean.cmake
.PHONY : CMakeFiles/read.dir/clean

CMakeFiles/read.dir/depend:
	cd /home/abc418/桌面/C++_exsamples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abc418/桌面/C++_exsamples /home/abc418/桌面/C++_exsamples /home/abc418/桌面/C++_exsamples/build /home/abc418/桌面/C++_exsamples/build /home/abc418/桌面/C++_exsamples/build/CMakeFiles/read.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/read.dir/depend
