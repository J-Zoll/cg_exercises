# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jonas/Downloads/cg_exercise_01/01_colors

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jonas/Downloads/cg_exercise_01/01_colors/build

# Include any dependencies generated for this target.
include /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.make

# Include the progress variables for this target.
include /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/progress.make

# Include the compile flags for this target's objects.
include /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/context.c
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.o -MF CMakeFiles/glfw.dir/context.c.o.d -o CMakeFiles/glfw.dir/context.c.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/context.c

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/context.c.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/context.c > CMakeFiles/glfw.dir/context.c.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/context.c.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/context.c -o CMakeFiles/glfw.dir/context.c.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/init.c
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.o -MF CMakeFiles/glfw.dir/init.c.o.d -o CMakeFiles/glfw.dir/init.c.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/init.c

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/init.c.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/init.c > CMakeFiles/glfw.dir/init.c.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/init.c.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/init.c -o CMakeFiles/glfw.dir/init.c.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/input.c
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.o -MF CMakeFiles/glfw.dir/input.c.o.d -o CMakeFiles/glfw.dir/input.c.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/input.c

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/input.c.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/input.c > CMakeFiles/glfw.dir/input.c.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/input.c.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/input.c -o CMakeFiles/glfw.dir/input.c.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/monitor.c
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.o -MF CMakeFiles/glfw.dir/monitor.c.o.d -o CMakeFiles/glfw.dir/monitor.c.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/monitor.c

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/monitor.c.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/monitor.c > CMakeFiles/glfw.dir/monitor.c.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/monitor.c.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/monitor.c -o CMakeFiles/glfw.dir/monitor.c.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/window.c
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.o -MF CMakeFiles/glfw.dir/window.c.o.d -o CMakeFiles/glfw.dir/window.c.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/window.c

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/window.c.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/window.c > CMakeFiles/glfw.dir/window.c.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/window.c.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/window.c -o CMakeFiles/glfw.dir/window.c.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_init.m
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o -MF CMakeFiles/glfw.dir/cocoa_init.m.o.d -o CMakeFiles/glfw.dir/cocoa_init.m.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_init.m

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_init.m.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_init.m > CMakeFiles/glfw.dir/cocoa_init.m.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_init.m.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_init.m -o CMakeFiles/glfw.dir/cocoa_init.m.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_monitor.m
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o -MF CMakeFiles/glfw.dir/cocoa_monitor.m.o.d -o CMakeFiles/glfw.dir/cocoa_monitor.m.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_monitor.m

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_monitor.m.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_monitor.m > CMakeFiles/glfw.dir/cocoa_monitor.m.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_monitor.m.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_monitor.m -o CMakeFiles/glfw.dir/cocoa_monitor.m.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_window.m
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o -MF CMakeFiles/glfw.dir/cocoa_window.m.o.d -o CMakeFiles/glfw.dir/cocoa_window.m.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_window.m

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/cocoa_window.m.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_window.m > CMakeFiles/glfw.dir/cocoa_window.m.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/cocoa_window.m.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/cocoa_window.m -o CMakeFiles/glfw.dir/cocoa_window.m.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/iokit_joystick.m
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.o -MF CMakeFiles/glfw.dir/iokit_joystick.m.o.d -o CMakeFiles/glfw.dir/iokit_joystick.m.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/iokit_joystick.m

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/iokit_joystick.m.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/iokit_joystick.m > CMakeFiles/glfw.dir/iokit_joystick.m.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/iokit_joystick.m.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/iokit_joystick.m -o CMakeFiles/glfw.dir/iokit_joystick.m.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/mach_time.c
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.o -MF CMakeFiles/glfw.dir/mach_time.c.o.d -o CMakeFiles/glfw.dir/mach_time.c.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/mach_time.c

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/mach_time.c.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/mach_time.c > CMakeFiles/glfw.dir/mach_time.c.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/mach_time.c.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/mach_time.c -o CMakeFiles/glfw.dir/mach_time.c.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/posix_tls.c
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o -MF CMakeFiles/glfw.dir/posix_tls.c.o.d -o CMakeFiles/glfw.dir/posix_tls.c.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/posix_tls.c

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_tls.c.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/posix_tls.c > CMakeFiles/glfw.dir/posix_tls.c.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_tls.c.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/posix_tls.c -o CMakeFiles/glfw.dir/posix_tls.c.s

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/flags.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/nsgl_context.m
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o -MF CMakeFiles/glfw.dir/nsgl_context.m.o.d -o CMakeFiles/glfw.dir/nsgl_context.m.o -c /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/nsgl_context.m

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glfw.dir/nsgl_context.m.i"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/nsgl_context.m > CMakeFiles/glfw.dir/nsgl_context.m.i

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glfw.dir/nsgl_context.m.s"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src/nsgl_context.m -o CMakeFiles/glfw.dir/nsgl_context.m.s

# Object files for target glfw
glfw_OBJECTS = \
"CMakeFiles/glfw.dir/context.c.o" \
"CMakeFiles/glfw.dir/init.c.o" \
"CMakeFiles/glfw.dir/input.c.o" \
"CMakeFiles/glfw.dir/monitor.c.o" \
"CMakeFiles/glfw.dir/window.c.o" \
"CMakeFiles/glfw.dir/cocoa_init.m.o" \
"CMakeFiles/glfw.dir/cocoa_monitor.m.o" \
"CMakeFiles/glfw.dir/cocoa_window.m.o" \
"CMakeFiles/glfw.dir/iokit_joystick.m.o" \
"CMakeFiles/glfw.dir/mach_time.c.o" \
"CMakeFiles/glfw.dir/posix_tls.c.o" \
"CMakeFiles/glfw.dir/nsgl_context.m.o"

# External object files for target glfw
glfw_EXTERNAL_OBJECTS =

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/context.c.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/init.c.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/input.c.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/monitor.c.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/window.c.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_init.m.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_monitor.m.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/cocoa_window.m.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/iokit_joystick.m.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/mach_time.c.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/nsgl_context.m.o
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/build.make
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jonas/Downloads/cg_exercise_01/01_colors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C static library libglfw3.a"
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean_target.cmake
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/build: /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/libglfw3.a
.PHONY : /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/build

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/clean:
	cd /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean.cmake
.PHONY : /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/clean

/Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/depend:
	cd /Users/jonas/Downloads/cg_exercise_01/01_colors/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jonas/Downloads/cg_exercise_01/01_colors /Users/jonas/Downloads/cg_exercise_01/cglib/lib/glfw/src /Users/jonas/Downloads/cg_exercise_01/01_colors/build /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : /Users/jonas/Downloads/cg_exercise_01/cglib/build/glfw/src/CMakeFiles/glfw.dir/depend
