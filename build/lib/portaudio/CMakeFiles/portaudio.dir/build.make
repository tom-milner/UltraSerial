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

# Include any dependencies generated for this target.
include lib/portaudio/CMakeFiles/portaudio.dir/depend.make

# Include the progress variables for this target.
include lib/portaudio/CMakeFiles/portaudio.dir/progress.make

# Include the compile flags for this target's objects.
include lib/portaudio/CMakeFiles/portaudio.dir/flags.make

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_allocation.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_allocation.c.o: ../lib/portaudio/src/common/pa_allocation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_allocation.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_allocation.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_allocation.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_allocation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_allocation.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_allocation.c > CMakeFiles/portaudio.dir/src/common/pa_allocation.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_allocation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_allocation.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_allocation.c -o CMakeFiles/portaudio.dir/src/common/pa_allocation.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_converters.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_converters.c.o: ../lib/portaudio/src/common/pa_converters.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_converters.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_converters.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_converters.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_converters.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_converters.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_converters.c > CMakeFiles/portaudio.dir/src/common/pa_converters.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_converters.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_converters.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_converters.c -o CMakeFiles/portaudio.dir/src/common/pa_converters.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.o: ../lib/portaudio/src/common/pa_cpuload.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_cpuload.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_cpuload.c > CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_cpuload.c -o CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.o: ../lib/portaudio/src/common/pa_debugprint.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_debugprint.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_debugprint.c > CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_debugprint.c -o CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_dither.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_dither.c.o: ../lib/portaudio/src/common/pa_dither.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_dither.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_dither.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_dither.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_dither.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_dither.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_dither.c > CMakeFiles/portaudio.dir/src/common/pa_dither.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_dither.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_dither.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_dither.c -o CMakeFiles/portaudio.dir/src/common/pa_dither.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_front.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_front.c.o: ../lib/portaudio/src/common/pa_front.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_front.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_front.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_front.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_front.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_front.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_front.c > CMakeFiles/portaudio.dir/src/common/pa_front.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_front.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_front.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_front.c -o CMakeFiles/portaudio.dir/src/common/pa_front.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_process.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_process.c.o: ../lib/portaudio/src/common/pa_process.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_process.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_process.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_process.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_process.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_process.c > CMakeFiles/portaudio.dir/src/common/pa_process.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_process.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_process.c -o CMakeFiles/portaudio.dir/src/common/pa_process.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.o: ../lib/portaudio/src/common/pa_ringbuffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_ringbuffer.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_ringbuffer.c > CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_ringbuffer.c -o CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_stream.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_stream.c.o: ../lib/portaudio/src/common/pa_stream.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_stream.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_stream.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_stream.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_stream.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_stream.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_stream.c > CMakeFiles/portaudio.dir/src/common/pa_stream.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_stream.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_stream.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_stream.c -o CMakeFiles/portaudio.dir/src/common/pa_stream.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_trace.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_trace.c.o: ../lib/portaudio/src/common/pa_trace.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_trace.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/common/pa_trace.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_trace.c

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_trace.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/common/pa_trace.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_trace.c > CMakeFiles/portaudio.dir/src/common/pa_trace.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_trace.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/common/pa_trace.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/common/pa_trace.c -o CMakeFiles/portaudio.dir/src/common/pa_trace.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.o: ../lib/portaudio/src/hostapi/skeleton/pa_hostapi_skeleton.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/skeleton/pa_hostapi_skeleton.c

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/skeleton/pa_hostapi_skeleton.c > CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/skeleton/pa_hostapi_skeleton.c -o CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.o: ../lib/portaudio/src/os/unix/pa_unix_hostapis.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/os/unix/pa_unix_hostapis.c

lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/os/unix/pa_unix_hostapis.c > CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/os/unix/pa_unix_hostapis.c -o CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.o: ../lib/portaudio/src/os/unix/pa_unix_util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/os/unix/pa_unix_util.c

lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/os/unix/pa_unix_util.c > CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/os/unix/pa_unix_util.c -o CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.o: ../lib/portaudio/src/hostapi/coreaudio/pa_mac_core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core.c

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core.c > CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core.c -o CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.o: ../lib/portaudio/src/hostapi/coreaudio/pa_mac_core_blocking.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core_blocking.c

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core_blocking.c > CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core_blocking.c -o CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.s

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.o: lib/portaudio/CMakeFiles/portaudio.dir/flags.make
lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.o: ../lib/portaudio/src/hostapi/coreaudio/pa_mac_core_utilities.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.o"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.o   -c /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core_utilities.c

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.i"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core_utilities.c > CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.i

lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.s"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio/src/hostapi/coreaudio/pa_mac_core_utilities.c -o CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.s

# Object files for target portaudio
portaudio_OBJECTS = \
"CMakeFiles/portaudio.dir/src/common/pa_allocation.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_converters.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_dither.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_front.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_process.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_stream.c.o" \
"CMakeFiles/portaudio.dir/src/common/pa_trace.c.o" \
"CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.o" \
"CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.o" \
"CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.o" \
"CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.o" \
"CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.o" \
"CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.o"

# External object files for target portaudio
portaudio_EXTERNAL_OBJECTS =

lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_allocation.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_converters.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_cpuload.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_debugprint.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_dither.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_front.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_process.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_ringbuffer.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_stream.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/common/pa_trace.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/skeleton/pa_hostapi_skeleton.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_hostapis.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/os/unix/pa_unix_util.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_blocking.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/src/hostapi/coreaudio/pa_mac_core_utilities.c.o
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/build.make
lib/portaudio/libportaudio.dylib: lib/portaudio/CMakeFiles/portaudio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tommilner/CLionProjects/UltraSerial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking C shared library libportaudio.dylib"
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/portaudio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/portaudio/CMakeFiles/portaudio.dir/build: lib/portaudio/libportaudio.dylib

.PHONY : lib/portaudio/CMakeFiles/portaudio.dir/build

lib/portaudio/CMakeFiles/portaudio.dir/clean:
	cd /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio && $(CMAKE_COMMAND) -P CMakeFiles/portaudio.dir/cmake_clean.cmake
.PHONY : lib/portaudio/CMakeFiles/portaudio.dir/clean

lib/portaudio/CMakeFiles/portaudio.dir/depend:
	cd /Users/tommilner/CLionProjects/UltraSerial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tommilner/CLionProjects/UltraSerial /Users/tommilner/CLionProjects/UltraSerial/lib/portaudio /Users/tommilner/CLionProjects/UltraSerial/build /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio /Users/tommilner/CLionProjects/UltraSerial/build/lib/portaudio/CMakeFiles/portaudio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/portaudio/CMakeFiles/portaudio.dir/depend

