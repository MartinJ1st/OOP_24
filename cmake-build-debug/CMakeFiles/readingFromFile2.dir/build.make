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
include CMakeFiles/readingFromFile2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/readingFromFile2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/readingFromFile2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/readingFromFile2.dir/flags.make

CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.obj: CMakeFiles/readingFromFile2.dir/flags.make
CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.obj: C:/Users/Media/CLionProjects/OOP_24/Kolokviumski/readingFromFile2.cpp
CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.obj: CMakeFiles/readingFromFile2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.obj -MF CMakeFiles\readingFromFile2.dir\Kolokviumski\readingFromFile2.cpp.obj.d -o CMakeFiles\readingFromFile2.dir\Kolokviumski\readingFromFile2.cpp.obj -c C:\Users\Media\CLionProjects\OOP_24\Kolokviumski\readingFromFile2.cpp

CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Media\CLionProjects\OOP_24\Kolokviumski\readingFromFile2.cpp > CMakeFiles\readingFromFile2.dir\Kolokviumski\readingFromFile2.cpp.i

CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Media\CLionProjects\OOP_24\Kolokviumski\readingFromFile2.cpp -o CMakeFiles\readingFromFile2.dir\Kolokviumski\readingFromFile2.cpp.s

# Object files for target readingFromFile2
readingFromFile2_OBJECTS = \
"CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.obj"

# External object files for target readingFromFile2
readingFromFile2_EXTERNAL_OBJECTS =

readingFromFile2.exe: CMakeFiles/readingFromFile2.dir/Kolokviumski/readingFromFile2.cpp.obj
readingFromFile2.exe: CMakeFiles/readingFromFile2.dir/build.make
readingFromFile2.exe: CMakeFiles/readingFromFile2.dir/linkLibs.rsp
readingFromFile2.exe: CMakeFiles/readingFromFile2.dir/objects1.rsp
readingFromFile2.exe: CMakeFiles/readingFromFile2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable readingFromFile2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\readingFromFile2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/readingFromFile2.dir/build: readingFromFile2.exe
.PHONY : CMakeFiles/readingFromFile2.dir/build

CMakeFiles/readingFromFile2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\readingFromFile2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/readingFromFile2.dir/clean

CMakeFiles/readingFromFile2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles\readingFromFile2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/readingFromFile2.dir/depend

