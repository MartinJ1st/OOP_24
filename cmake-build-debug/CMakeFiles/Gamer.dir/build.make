# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Media\CLionProjects\OOP_24

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Gamer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Gamer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Gamer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gamer.dir/flags.make

CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.obj: CMakeFiles/Gamer.dir/flags.make
CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.obj: C:/Users/Media/CLionProjects/OOP_24/Labs/3_nedela/Gamer.cpp
CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.obj: CMakeFiles/Gamer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.obj -MF CMakeFiles\Gamer.dir\Labs\3_nedela\Gamer.cpp.obj.d -o CMakeFiles\Gamer.dir\Labs\3_nedela\Gamer.cpp.obj -c C:\Users\Media\CLionProjects\OOP_24\Labs\3_nedela\Gamer.cpp

CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Media\CLionProjects\OOP_24\Labs\3_nedela\Gamer.cpp > CMakeFiles\Gamer.dir\Labs\3_nedela\Gamer.cpp.i

CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Media\CLionProjects\OOP_24\Labs\3_nedela\Gamer.cpp -o CMakeFiles\Gamer.dir\Labs\3_nedela\Gamer.cpp.s

# Object files for target Gamer
Gamer_OBJECTS = \
"CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.obj"

# External object files for target Gamer
Gamer_EXTERNAL_OBJECTS =

Gamer.exe: CMakeFiles/Gamer.dir/Labs/3_nedela/Gamer.cpp.obj
Gamer.exe: CMakeFiles/Gamer.dir/build.make
Gamer.exe: CMakeFiles/Gamer.dir/linkLibs.rsp
Gamer.exe: CMakeFiles/Gamer.dir/objects1.rsp
Gamer.exe: CMakeFiles/Gamer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Gamer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Gamer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gamer.dir/build: Gamer.exe
.PHONY : CMakeFiles/Gamer.dir/build

CMakeFiles/Gamer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Gamer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Gamer.dir/clean

CMakeFiles/Gamer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles\Gamer.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Gamer.dir/depend

