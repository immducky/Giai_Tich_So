# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GiaiTichSo\PPChiaDoi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GiaiTichSo\PPChiaDoi\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PPChiaDoi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PPChiaDoi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PPChiaDoi.dir/flags.make

CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.obj: CMakeFiles/PPChiaDoi.dir/flags.make
CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.obj: ../ChiaDoi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\GiaiTichSo\PPChiaDoi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PPChiaDoi.dir\ChiaDoi.c.obj   -c E:\GiaiTichSo\PPChiaDoi\ChiaDoi.c

CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\GiaiTichSo\PPChiaDoi\ChiaDoi.c > CMakeFiles\PPChiaDoi.dir\ChiaDoi.c.i

CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\GiaiTichSo\PPChiaDoi\ChiaDoi.c -o CMakeFiles\PPChiaDoi.dir\ChiaDoi.c.s

# Object files for target PPChiaDoi
PPChiaDoi_OBJECTS = \
"CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.obj"

# External object files for target PPChiaDoi
PPChiaDoi_EXTERNAL_OBJECTS =

PPChiaDoi.exe: CMakeFiles/PPChiaDoi.dir/ChiaDoi.c.obj
PPChiaDoi.exe: CMakeFiles/PPChiaDoi.dir/build.make
PPChiaDoi.exe: CMakeFiles/PPChiaDoi.dir/linklibs.rsp
PPChiaDoi.exe: CMakeFiles/PPChiaDoi.dir/objects1.rsp
PPChiaDoi.exe: CMakeFiles/PPChiaDoi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\GiaiTichSo\PPChiaDoi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PPChiaDoi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PPChiaDoi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PPChiaDoi.dir/build: PPChiaDoi.exe

.PHONY : CMakeFiles/PPChiaDoi.dir/build

CMakeFiles/PPChiaDoi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PPChiaDoi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PPChiaDoi.dir/clean

CMakeFiles/PPChiaDoi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GiaiTichSo\PPChiaDoi E:\GiaiTichSo\PPChiaDoi E:\GiaiTichSo\PPChiaDoi\cmake-build-debug E:\GiaiTichSo\PPChiaDoi\cmake-build-debug E:\GiaiTichSo\PPChiaDoi\cmake-build-debug\CMakeFiles\PPChiaDoi.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PPChiaDoi.dir/depend

