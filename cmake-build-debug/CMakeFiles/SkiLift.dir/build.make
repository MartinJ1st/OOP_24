# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Media\CLionProjects\OOP_24

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SkiLift.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SkiLift.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SkiLift.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SkiLift.dir/flags.make

CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.obj: CMakeFiles/SkiLift.dir/flags.make
CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.obj: C:/Users/Media/CLionProjects/OOP_24/Kolokviumski/SkiLift.cpp
CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.obj: CMakeFiles/SkiLift.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.obj -MF CMakeFiles\SkiLift.dir\Kolokviumski\SkiLift.cpp.obj.d -o CMakeFiles\SkiLift.dir\Kolokviumski\SkiLift.cpp.obj -c C:\Users\Media\CLionProjects\OOP_24\Kolokviumski\SkiLift.cpp

CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Media\CLionProjects\OOP_24\Kolokviumski\SkiLift.cpp > CMakeFiles\SkiLift.dir\Kolokviumski\SkiLift.cpp.i

CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Media\CLionProjects\OOP_24\Kolokviumski\SkiLift.cpp -o CMakeFiles\SkiLift.dir\Kolokviumski\SkiLift.cpp.s

# Object files for target SkiLift
SkiLift_OBJECTS = \
"CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.obj"

# External object files for target SkiLift
SkiLift_EXTERNAL_OBJECTS =

SkiLift.exe: CMakeFiles/SkiLift.dir/Kolokviumski/SkiLift.cpp.obj
SkiLift.exe: CMakeFiles/SkiLift.dir/build.make
SkiLift.exe: CMakeFiles/SkiLift.dir/linkLibs.rsp
SkiLift.exe: CMakeFiles/SkiLift.dir/objects1.rsp
SkiLift.exe: CMakeFiles/SkiLift.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SkiLift.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SkiLift.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SkiLift.dir/build: SkiLift.exe
.PHONY : CMakeFiles/SkiLift.dir/build

CMakeFiles/SkiLift.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SkiLift.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SkiLift.dir/clean

CMakeFiles/SkiLift.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles\SkiLift.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SkiLift.dir/depend

