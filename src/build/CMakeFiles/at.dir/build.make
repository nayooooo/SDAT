# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\embedded\EmbeddedSoftware\SDAT\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\embedded\EmbeddedSoftware\SDAT\src\build

# Include any dependencies generated for this target.
include CMakeFiles/at.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/at.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/at.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/at.dir/flags.make

CMakeFiles/at.dir/at.c.obj: CMakeFiles/at.dir/flags.make
CMakeFiles/at.dir/at.c.obj: CMakeFiles/at.dir/includes_C.rsp
CMakeFiles/at.dir/at.c.obj: D:/embedded/EmbeddedSoftware/SDAT/src/at.c
CMakeFiles/at.dir/at.c.obj: CMakeFiles/at.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\embedded\EmbeddedSoftware\SDAT\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/at.dir/at.c.obj"
	C:\Users\YEWAN\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/at.dir/at.c.obj -MF CMakeFiles\at.dir\at.c.obj.d -o CMakeFiles\at.dir\at.c.obj -c D:\embedded\EmbeddedSoftware\SDAT\src\at.c

CMakeFiles/at.dir/at.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/at.dir/at.c.i"
	C:\Users\YEWAN\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\embedded\EmbeddedSoftware\SDAT\src\at.c > CMakeFiles\at.dir\at.c.i

CMakeFiles/at.dir/at.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/at.dir/at.c.s"
	C:\Users\YEWAN\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\embedded\EmbeddedSoftware\SDAT\src\at.c -o CMakeFiles\at.dir\at.c.s

CMakeFiles/at.dir/at_mem.c.obj: CMakeFiles/at.dir/flags.make
CMakeFiles/at.dir/at_mem.c.obj: CMakeFiles/at.dir/includes_C.rsp
CMakeFiles/at.dir/at_mem.c.obj: D:/embedded/EmbeddedSoftware/SDAT/src/at_mem.c
CMakeFiles/at.dir/at_mem.c.obj: CMakeFiles/at.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\embedded\EmbeddedSoftware\SDAT\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/at.dir/at_mem.c.obj"
	C:\Users\YEWAN\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/at.dir/at_mem.c.obj -MF CMakeFiles\at.dir\at_mem.c.obj.d -o CMakeFiles\at.dir\at_mem.c.obj -c D:\embedded\EmbeddedSoftware\SDAT\src\at_mem.c

CMakeFiles/at.dir/at_mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/at.dir/at_mem.c.i"
	C:\Users\YEWAN\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\embedded\EmbeddedSoftware\SDAT\src\at_mem.c > CMakeFiles\at.dir\at_mem.c.i

CMakeFiles/at.dir/at_mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/at.dir/at_mem.c.s"
	C:\Users\YEWAN\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\embedded\EmbeddedSoftware\SDAT\src\at_mem.c -o CMakeFiles\at.dir\at_mem.c.s

# Object files for target at
at_OBJECTS = \
"CMakeFiles/at.dir/at.c.obj" \
"CMakeFiles/at.dir/at_mem.c.obj"

# External object files for target at
at_EXTERNAL_OBJECTS =

D:/embedded/EmbeddedSoftware/SDAT/lib/at.a: CMakeFiles/at.dir/at.c.obj
D:/embedded/EmbeddedSoftware/SDAT/lib/at.a: CMakeFiles/at.dir/at_mem.c.obj
D:/embedded/EmbeddedSoftware/SDAT/lib/at.a: CMakeFiles/at.dir/build.make
D:/embedded/EmbeddedSoftware/SDAT/lib/at.a: CMakeFiles/at.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\embedded\EmbeddedSoftware\SDAT\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library D:\embedded\EmbeddedSoftware\SDAT\lib\at.a"
	$(CMAKE_COMMAND) -P CMakeFiles\at.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\at.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/at.dir/build: D:/embedded/EmbeddedSoftware/SDAT/lib/at.a
.PHONY : CMakeFiles/at.dir/build

CMakeFiles/at.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\at.dir\cmake_clean.cmake
.PHONY : CMakeFiles/at.dir/clean

CMakeFiles/at.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\embedded\EmbeddedSoftware\SDAT\src D:\embedded\EmbeddedSoftware\SDAT\src D:\embedded\EmbeddedSoftware\SDAT\src\build D:\embedded\EmbeddedSoftware\SDAT\src\build D:\embedded\EmbeddedSoftware\SDAT\src\build\CMakeFiles\at.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/at.dir/depend

