# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/code/mitprotocol/mitprotocol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/code/mitprotocol/doit/build/android/objfolder

# Include any dependencies generated for this target.
include CMakeFiles/mitprotocol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mitprotocol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mitprotocol.dir/flags.make

CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o: CMakeFiles/mitprotocol.dir/flags.make
CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o: /home/code/mitprotocol/mitprotocol/src/traffic/mitprotocolimpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/mitprotocol/doit/build/android/objfolder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o -c /home/code/mitprotocol/mitprotocol/src/traffic/mitprotocolimpl.cpp

CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.i"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/mitprotocol/mitprotocol/src/traffic/mitprotocolimpl.cpp > CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.i

CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.s"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/mitprotocol/mitprotocol/src/traffic/mitprotocolimpl.cpp -o CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.s

CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.requires:

.PHONY : CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.requires

CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.provides: CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.requires
	$(MAKE) -f CMakeFiles/mitprotocol.dir/build.make CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.provides.build
.PHONY : CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.provides

CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.provides.build: CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o


CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o: CMakeFiles/mitprotocol.dir/flags.make
CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o: /home/code/mitprotocol/mitprotocol/src/wfdb/wfdblocal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/mitprotocol/doit/build/android/objfolder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o -c /home/code/mitprotocol/mitprotocol/src/wfdb/wfdblocal.cpp

CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.i"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/mitprotocol/mitprotocol/src/wfdb/wfdblocal.cpp > CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.i

CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.s"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/mitprotocol/mitprotocol/src/wfdb/wfdblocal.cpp -o CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.s

CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.requires:

.PHONY : CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.requires

CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.provides: CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.requires
	$(MAKE) -f CMakeFiles/mitprotocol.dir/build.make CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.provides.build
.PHONY : CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.provides

CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.provides.build: CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o


CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o: CMakeFiles/mitprotocol.dir/flags.make
CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o: /home/code/mitprotocol/mitprotocol/src/easytar/easytar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/mitprotocol/doit/build/android/objfolder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o -c /home/code/mitprotocol/mitprotocol/src/easytar/easytar.cpp

CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.i"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/mitprotocol/mitprotocol/src/easytar/easytar.cpp > CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.i

CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.s"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/mitprotocol/mitprotocol/src/easytar/easytar.cpp -o CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.s

CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.requires:

.PHONY : CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.requires

CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.provides: CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.requires
	$(MAKE) -f CMakeFiles/mitprotocol.dir/build.make CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.provides.build
.PHONY : CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.provides

CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.provides.build: CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o


CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o: CMakeFiles/mitprotocol.dir/flags.make
CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o: /home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/mitprotocol/doit/build/android/objfolder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o -c /home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx

CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.i"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx > CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.i

CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.s"
	/home/tool/android-ndk-r12b/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ --sysroot=/home/tool/android-ndk-r12b/platforms/android-19/arch-arm $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx -o CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.s

CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.requires:

.PHONY : CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.requires

CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.provides: CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.requires
	$(MAKE) -f CMakeFiles/mitprotocol.dir/build.make CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.provides.build
.PHONY : CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.provides

CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.provides.build: CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o


# Object files for target mitprotocol
mitprotocol_OBJECTS = \
"CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o" \
"CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o" \
"CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o" \
"CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o"

# External object files for target mitprotocol
mitprotocol_EXTERNAL_OBJECTS =

libmitprotocol.so: CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o
libmitprotocol.so: CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o
libmitprotocol.so: CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o
libmitprotocol.so: CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o
libmitprotocol.so: CMakeFiles/mitprotocol.dir/build.make
libmitprotocol.so: CMakeFiles/mitprotocol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/code/mitprotocol/doit/build/android/objfolder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library libmitprotocol.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mitprotocol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mitprotocol.dir/build: libmitprotocol.so

.PHONY : CMakeFiles/mitprotocol.dir/build

CMakeFiles/mitprotocol.dir/requires: CMakeFiles/mitprotocol.dir/src/traffic/mitprotocolimpl.cpp.o.requires
CMakeFiles/mitprotocol.dir/requires: CMakeFiles/mitprotocol.dir/src/wfdb/wfdblocal.cpp.o.requires
CMakeFiles/mitprotocol.dir/requires: CMakeFiles/mitprotocol.dir/src/easytar/easytar.cpp.o.requires
CMakeFiles/mitprotocol.dir/requires: CMakeFiles/mitprotocol.dir/home/code/mitprotocol/doit/build/android/javainterface/mitprotocol_wrap.cxx.o.requires

.PHONY : CMakeFiles/mitprotocol.dir/requires

CMakeFiles/mitprotocol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mitprotocol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mitprotocol.dir/clean

CMakeFiles/mitprotocol.dir/depend:
	cd /home/code/mitprotocol/doit/build/android/objfolder && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/code/mitprotocol/mitprotocol /home/code/mitprotocol/mitprotocol /home/code/mitprotocol/doit/build/android/objfolder /home/code/mitprotocol/doit/build/android/objfolder /home/code/mitprotocol/doit/build/android/objfolder/CMakeFiles/mitprotocol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mitprotocol.dir/depend

