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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tommilner/CLionProjects/UltraSerial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tommilner/CLionProjects/UltraSerial/build

# Utility rule file for uninstall.

# Include the progress variables for this target.
include lib/portaudio/CMakeFiles/uninstall.dir/progress.make

lib/portaudio/CMakeFiles/uninstall:
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /usr/local/Cellar/cmake/3.17.1/bin/cmake -P /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio/cmake_uninstall.cmake

uninstall: lib/portaudio/CMakeFiles/uninstall
uninstall: lib/portaudio/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
lib/portaudio/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : lib/portaudio/CMakeFiles/uninstall.dir/build

lib/portaudio/CMakeFiles/uninstall.dir/clean:
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : lib/portaudio/CMakeFiles/uninstall.dir/clean

lib/portaudio/CMakeFiles/uninstall.dir/depend:
	cd /Users/tommilner/CLionProjects/UltraSerial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tommilner/CLionProjects/UltraSerial /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio /Users/tommilner/CLionProjects/UltraSerial/build /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/portaudio/CMakeFiles/uninstall.dir/depend

