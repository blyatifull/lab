# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\blyatifull\CLionProjects\course

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\course.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\course.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\course.dir\flags.make

CMakeFiles\course.dir\main.c.obj: CMakeFiles\course.dir\flags.make
CMakeFiles\course.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/course.dir/main.c.obj"
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\course.dir\main.c.obj /FdCMakeFiles\course.dir\ /FS -c C:\Users\blyatifull\CLionProjects\course\main.c
<<

CMakeFiles\course.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/course.dir/main.c.i"
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\course.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\main.c
<<

CMakeFiles\course.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/course.dir/main.c.s"
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\course.dir\main.c.s /c C:\Users\blyatifull\CLionProjects\course\main.c
<<

CMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.obj: CMakeFiles\course.dir\flags.make
CMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.obj: ..\libs\data_structures\ordered_array_set\ordered_array_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/course.dir/libs/data_structures/ordered_array_set/ordered_array_set.c.obj"
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.obj /FdCMakeFiles\course.dir\ /FS -c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c
<<

CMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/course.dir/libs/data_structures/ordered_array_set/ordered_array_set.c.i"
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c
<<

CMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/course.dir/libs/data_structures/ordered_array_set/ordered_array_set.c.s"
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.s /c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c
<<

# Object files for target course
course_OBJECTS = \
"CMakeFiles\course.dir\main.c.obj" \
"CMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.obj"

# External object files for target course
course_EXTERNAL_OBJECTS =

course.exe: CMakeFiles\course.dir\main.c.obj
course.exe: CMakeFiles\course.dir\libs\data_structures\ordered_array_set\ordered_array_set.c.obj
course.exe: CMakeFiles\course.dir\build.make
course.exe: libs\data_structures\data_structures.lib
course.exe: libs\algorithms\algorithms.lib
course.exe: CMakeFiles\course.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable course.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\course.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\course.dir\objects1.rsp @<<
 /out:course.exe /implib:course.lib /pdb:C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\course.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  libs\data_structures\data_structures.lib libs\algorithms\algorithms.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\course.dir\build: course.exe
.PHONY : CMakeFiles\course.dir\build

CMakeFiles\course.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\course.dir\cmake_clean.cmake
.PHONY : CMakeFiles\course.dir\clean

CMakeFiles\course.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\blyatifull\CLionProjects\course C:\Users\blyatifull\CLionProjects\course C:\Users\blyatifull\CLionProjects\course\cmake-build-debug C:\Users\blyatifull\CLionProjects\course\cmake-build-debug C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles\course.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\course.dir\depend

