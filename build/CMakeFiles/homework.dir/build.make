# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/Casper/Desktop/md5-cplusplus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/Casper/Desktop/md5-cplusplus/build

# Include any dependencies generated for this target.
include CMakeFiles/homework.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homework.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework.dir/flags.make

CMakeFiles/homework.dir/src/main.cpp.obj: CMakeFiles/homework.dir/flags.make
CMakeFiles/homework.dir/src/main.cpp.obj: CMakeFiles/homework.dir/includes_CXX.rsp
CMakeFiles/homework.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/Casper/Desktop/md5-cplusplus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homework.dir/src/main.cpp.obj"
	C:/MinGW/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/homework.dir/src/main.cpp.obj -c C:/Users/Casper/Desktop/md5-cplusplus/src/main.cpp

CMakeFiles/homework.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework.dir/src/main.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/Casper/Desktop/md5-cplusplus/src/main.cpp > CMakeFiles/homework.dir/src/main.cpp.i

CMakeFiles/homework.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework.dir/src/main.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/Casper/Desktop/md5-cplusplus/src/main.cpp -o CMakeFiles/homework.dir/src/main.cpp.s

CMakeFiles/homework.dir/src/cipher.cpp.obj: CMakeFiles/homework.dir/flags.make
CMakeFiles/homework.dir/src/cipher.cpp.obj: CMakeFiles/homework.dir/includes_CXX.rsp
CMakeFiles/homework.dir/src/cipher.cpp.obj: ../src/cipher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/Casper/Desktop/md5-cplusplus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/homework.dir/src/cipher.cpp.obj"
	C:/MinGW/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/homework.dir/src/cipher.cpp.obj -c C:/Users/Casper/Desktop/md5-cplusplus/src/cipher.cpp

CMakeFiles/homework.dir/src/cipher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework.dir/src/cipher.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/Casper/Desktop/md5-cplusplus/src/cipher.cpp > CMakeFiles/homework.dir/src/cipher.cpp.i

CMakeFiles/homework.dir/src/cipher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework.dir/src/cipher.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/Casper/Desktop/md5-cplusplus/src/cipher.cpp -o CMakeFiles/homework.dir/src/cipher.cpp.s

# Object files for target homework
homework_OBJECTS = \
"CMakeFiles/homework.dir/src/main.cpp.obj" \
"CMakeFiles/homework.dir/src/cipher.cpp.obj"

# External object files for target homework
homework_EXTERNAL_OBJECTS =

homework.exe: CMakeFiles/homework.dir/src/main.cpp.obj
homework.exe: CMakeFiles/homework.dir/src/cipher.cpp.obj
homework.exe: CMakeFiles/homework.dir/build.make
homework.exe: CMakeFiles/homework.dir/linklibs.rsp
homework.exe: CMakeFiles/homework.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/Casper/Desktop/md5-cplusplus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable homework.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E remove -f CMakeFiles/homework.dir/objects.a
	C:/MinGW/x86_64-w64-mingw32/bin/ar.exe cr CMakeFiles/homework.dir/objects.a @CMakeFiles/homework.dir/objects1.rsp
	C:/MinGW/bin/g++.exe -g   -Wl,--whole-archive CMakeFiles/homework.dir/objects.a -Wl,--no-whole-archive  -o homework.exe -Wl,--out-implib,libhomework.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/homework.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/homework.dir/build: homework.exe

.PHONY : CMakeFiles/homework.dir/build

CMakeFiles/homework.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homework.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homework.dir/clean

CMakeFiles/homework.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/Casper/Desktop/md5-cplusplus C:/Users/Casper/Desktop/md5-cplusplus C:/Users/Casper/Desktop/md5-cplusplus/build C:/Users/Casper/Desktop/md5-cplusplus/build C:/Users/Casper/Desktop/md5-cplusplus/build/CMakeFiles/homework.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework.dir/depend

