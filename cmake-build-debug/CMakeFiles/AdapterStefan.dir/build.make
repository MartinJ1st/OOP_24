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
include CMakeFiles/AdapterStefan.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AdapterStefan.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AdapterStefan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AdapterStefan.dir/flags.make

CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.obj: CMakeFiles/AdapterStefan.dir/flags.make
CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.obj: C:/Users/Media/CLionProjects/OOP_24/Auditoriski/9/AdapterStefan.cpp
CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.obj: CMakeFiles/AdapterStefan.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.obj -MF CMakeFiles\AdapterStefan.dir\Auditoriski\9\AdapterStefan.cpp.obj.d -o CMakeFiles\AdapterStefan.dir\Auditoriski\9\AdapterStefan.cpp.obj -c C:\Users\Media\CLionProjects\OOP_24\Auditoriski\9\AdapterStefan.cpp

CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Media\CLionProjects\OOP_24\Auditoriski\9\AdapterStefan.cpp > CMakeFiles\AdapterStefan.dir\Auditoriski\9\AdapterStefan.cpp.i

CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Media\CLionProjects\OOP_24\Auditoriski\9\AdapterStefan.cpp -o CMakeFiles\AdapterStefan.dir\Auditoriski\9\AdapterStefan.cpp.s

# Object files for target AdapterStefan
AdapterStefan_OBJECTS = \
"CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.obj"

# External object files for target AdapterStefan
AdapterStefan_EXTERNAL_OBJECTS =

AdapterStefan.exe: CMakeFiles/AdapterStefan.dir/Auditoriski/9/AdapterStefan.cpp.obj
AdapterStefan.exe: CMakeFiles/AdapterStefan.dir/build.make
AdapterStefan.exe: CMakeFiles/AdapterStefan.dir/linkLibs.rsp
AdapterStefan.exe: CMakeFiles/AdapterStefan.dir/objects1.rsp
AdapterStefan.exe: CMakeFiles/AdapterStefan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AdapterStefan.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AdapterStefan.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AdapterStefan.dir/build: AdapterStefan.exe
.PHONY : CMakeFiles/AdapterStefan.dir/build

CMakeFiles/AdapterStefan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AdapterStefan.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AdapterStefan.dir/clean

CMakeFiles/AdapterStefan.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24 C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug C:\Users\Media\CLionProjects\OOP_24\cmake-build-debug\CMakeFiles\AdapterStefan.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/AdapterStefan.dir/depend

