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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\cmake-build-debug-visual-studio

# Include any dependencies generated for this target.
include CMakeFiles\designPrinciples.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\designPrinciples.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\designPrinciples.dir\flags.make

CMakeFiles\designPrinciples.dir\main.cpp.obj: CMakeFiles\designPrinciples.dir\flags.make
CMakeFiles\designPrinciples.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/designPrinciples.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\designPrinciples.dir\main.cpp.obj /FdCMakeFiles\designPrinciples.dir\ /FS -c C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\main.cpp
<<

CMakeFiles\designPrinciples.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/designPrinciples.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\designPrinciples.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\main.cpp
<<

CMakeFiles\designPrinciples.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/designPrinciples.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\designPrinciples.dir\main.cpp.s /c C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\main.cpp
<<

# Object files for target designPrinciples
designPrinciples_OBJECTS = \
"CMakeFiles\designPrinciples.dir\main.cpp.obj"

# External object files for target designPrinciples
designPrinciples_EXTERNAL_OBJECTS =

designPrinciples.exe: CMakeFiles\designPrinciples.dir\main.cpp.obj
designPrinciples.exe: CMakeFiles\designPrinciples.dir\build.make
designPrinciples.exe: CMakeFiles\designPrinciples.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable designPrinciples.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\designPrinciples.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\designPrinciples.dir\objects1.rsp @<<
 /out:designPrinciples.exe /implib:designPrinciples.lib /pdb:C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\cmake-build-debug-visual-studio\designPrinciples.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\designPrinciples.dir\build: designPrinciples.exe
.PHONY : CMakeFiles\designPrinciples.dir\build

CMakeFiles\designPrinciples.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\designPrinciples.dir\cmake_clean.cmake
.PHONY : CMakeFiles\designPrinciples.dir\clean

CMakeFiles\designPrinciples.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\cmake-build-debug-visual-studio C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\cmake-build-debug-visual-studio C:\Users\David\Work\cygwin64\home\David\Docs\clion\designPrinciples\cmake-build-debug-visual-studio\CMakeFiles\designPrinciples.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\designPrinciples.dir\depend

