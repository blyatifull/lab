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
include libs\data_structures\CMakeFiles\data_structures.dir\depend.make
# Include the progress variables for this target.
include libs\data_structures\CMakeFiles\data_structures.dir\progress.make

# Include the compile flags for this target's objects.
include libs\data_structures\CMakeFiles\data_structures.dir\flags.make

libs\data_structures\CMakeFiles\data_structures.dir\bitset\bitset.c.obj: libs\data_structures\CMakeFiles\data_structures.dir\flags.make
libs\data_structures\CMakeFiles\data_structures.dir\bitset\bitset.c.obj: ..\libs\data_structures\bitset\bitset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\data_structures.dir\bitset\bitset.c.obj /FdCMakeFiles\data_structures.dir\data_structures.pdb /FS -c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\bitset\bitset.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\bitset\bitset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/bitset/bitset.c.i"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\data_structures.dir\bitset\bitset.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\libs\data_structures\bitset\bitset.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\bitset\bitset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/bitset/bitset.c.s"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\data_structures.dir\bitset\bitset.c.s /c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\bitset\bitset.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.obj: libs\data_structures\CMakeFiles\data_structures.dir\flags.make
libs\data_structures\CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.obj: ..\libs\data_structures\ordered_array_set\ordered_array_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.obj /FdCMakeFiles\data_structures.dir\data_structures.pdb /FS -c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.i"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.s"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.s /c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.obj: libs\data_structures\CMakeFiles\data_structures.dir\flags.make
libs\data_structures\CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.obj: ..\libs\data_structures\unordered_array_set\unordered_array_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.obj /FdCMakeFiles\data_structures.dir\data_structures.pdb /FS -c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\unordered_array_set\unordered_array_set.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.i"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\libs\data_structures\unordered_array_set\unordered_array_set.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.s"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.s /c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\unordered_array_set\unordered_array_set.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector\vector.c.obj: libs\data_structures\CMakeFiles\data_structures.dir\flags.make
libs\data_structures\CMakeFiles\data_structures.dir\vector\vector.c.obj: ..\libs\data_structures\vector\vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/vector/vector.c.obj"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\data_structures.dir\vector\vector.c.obj /FdCMakeFiles\data_structures.dir\data_structures.pdb /FS -c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector\vector.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector\vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector/vector.c.i"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\data_structures.dir\vector\vector.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector\vector.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector\vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector/vector.c.s"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\data_structures.dir\vector\vector.c.s /c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector\vector.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector_test\vector_test.c.obj: libs\data_structures\CMakeFiles\data_structures.dir\flags.make
libs\data_structures\CMakeFiles\data_structures.dir\vector_test\vector_test.c.obj: ..\libs\data_structures\vector_test\vector_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/vector_test/vector_test.c.obj"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\data_structures.dir\vector_test\vector_test.c.obj /FdCMakeFiles\data_structures.dir\data_structures.pdb /FS -c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector_test\vector_test.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector_test\vector_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector_test/vector_test.c.i"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\data_structures.dir\vector_test\vector_test.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector_test\vector_test.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector_test\vector_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector_test/vector_test.c.s"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\data_structures.dir\vector_test\vector_test.c.s /c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector_test\vector_test.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector_void\vector_void.c.obj: libs\data_structures\CMakeFiles\data_structures.dir\flags.make
libs\data_structures\CMakeFiles\data_structures.dir\vector_void\vector_void.c.obj: ..\libs\data_structures\vector_void\vector_void.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/vector_void/vector_void.c.obj"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\data_structures.dir\vector_void\vector_void.c.obj /FdCMakeFiles\data_structures.dir\data_structures.pdb /FS -c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector_void\vector_void.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector_void\vector_void.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector_void/vector_void.c.i"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\data_structures.dir\vector_void\vector_void.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector_void\vector_void.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

libs\data_structures\CMakeFiles\data_structures.dir\vector_void\vector_void.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector_void/vector_void.c.s"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\data_structures.dir\vector_void\vector_void.c.s /c C:\Users\blyatifull\CLionProjects\course\libs\data_structures\vector_void\vector_void.c
<<
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

# Object files for target data_structures
data_structures_OBJECTS = \
"CMakeFiles\data_structures.dir\bitset\bitset.c.obj" \
"CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.obj" \
"CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.obj" \
"CMakeFiles\data_structures.dir\vector\vector.c.obj" \
"CMakeFiles\data_structures.dir\vector_test\vector_test.c.obj" \
"CMakeFiles\data_structures.dir\vector_void\vector_void.c.obj"

# External object files for target data_structures
data_structures_EXTERNAL_OBJECTS =

libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\bitset\bitset.c.obj
libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.obj
libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.obj
libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\vector\vector.c.obj
libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\vector_test\vector_test.c.obj
libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\vector_void\vector_void.c.obj
libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\build.make
libs\data_structures\data_structures.lib: libs\data_structures\CMakeFiles\data_structures.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library data_structures.lib"
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	$(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean_target.cmake
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	C:\PROGRA~2\MIB055~1\2019\PROFES~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\lib.exe /nologo /machine:X86 /out:data_structures.lib @CMakeFiles\data_structures.dir\objects1.rsp 
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug

# Rule to build all files generated by this target.
libs\data_structures\CMakeFiles\data_structures.dir\build: libs\data_structures\data_structures.lib
.PHONY : libs\data_structures\CMakeFiles\data_structures.dir\build

libs\data_structures\CMakeFiles\data_structures.dir\clean:
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures
	$(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean.cmake
	cd C:\Users\blyatifull\CLionProjects\course\cmake-build-debug
.PHONY : libs\data_structures\CMakeFiles\data_structures.dir\clean

libs\data_structures\CMakeFiles\data_structures.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\blyatifull\CLionProjects\course C:\Users\blyatifull\CLionProjects\course\libs\data_structures C:\Users\blyatifull\CLionProjects\course\cmake-build-debug C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures C:\Users\blyatifull\CLionProjects\course\cmake-build-debug\libs\data_structures\CMakeFiles\data_structures.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs\data_structures\CMakeFiles\data_structures.dir\depend

