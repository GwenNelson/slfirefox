# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gareth/slbrowser/linden/indra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gareth/slbrowser/linden/indra/viewer-linux-i686

# Include any dependencies generated for this target.
include llwindow/CMakeFiles/llwindow.dir/depend.make

# Include the progress variables for this target.
include llwindow/CMakeFiles/llwindow.dir/progress.make

# Include the compile flags for this target's objects.
include llwindow/CMakeFiles/llwindow.dir/flags.make

llwindow/CMakeFiles/llwindow.dir/llkeyboard.o: llwindow/CMakeFiles/llwindow.dir/flags.make
llwindow/CMakeFiles/llwindow.dir/llkeyboard.o: ../llwindow/llkeyboard.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gareth/slbrowser/linden/indra/viewer-linux-i686/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object llwindow/CMakeFiles/llwindow.dir/llkeyboard.o"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/llwindow.dir/llkeyboard.o -c /home/gareth/slbrowser/linden/indra/llwindow/llkeyboard.cpp

llwindow/CMakeFiles/llwindow.dir/llkeyboard.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llwindow.dir/llkeyboard.i"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gareth/slbrowser/linden/indra/llwindow/llkeyboard.cpp > CMakeFiles/llwindow.dir/llkeyboard.i

llwindow/CMakeFiles/llwindow.dir/llkeyboard.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llwindow.dir/llkeyboard.s"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gareth/slbrowser/linden/indra/llwindow/llkeyboard.cpp -o CMakeFiles/llwindow.dir/llkeyboard.s

llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.requires:
.PHONY : llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.requires

llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.provides: llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.requires
	$(MAKE) -f llwindow/CMakeFiles/llwindow.dir/build.make llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.provides.build
.PHONY : llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.provides

llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.provides.build: llwindow/CMakeFiles/llwindow.dir/llkeyboard.o
.PHONY : llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.provides.build

llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o: llwindow/CMakeFiles/llwindow.dir/flags.make
llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o: ../llwindow/llwindowheadless.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gareth/slbrowser/linden/indra/viewer-linux-i686/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/llwindow.dir/llwindowheadless.o -c /home/gareth/slbrowser/linden/indra/llwindow/llwindowheadless.cpp

llwindow/CMakeFiles/llwindow.dir/llwindowheadless.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llwindow.dir/llwindowheadless.i"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gareth/slbrowser/linden/indra/llwindow/llwindowheadless.cpp > CMakeFiles/llwindow.dir/llwindowheadless.i

llwindow/CMakeFiles/llwindow.dir/llwindowheadless.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llwindow.dir/llwindowheadless.s"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gareth/slbrowser/linden/indra/llwindow/llwindowheadless.cpp -o CMakeFiles/llwindow.dir/llwindowheadless.s

llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.requires:
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.requires

llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.provides: llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.requires
	$(MAKE) -f llwindow/CMakeFiles/llwindow.dir/build.make llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.provides.build
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.provides

llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.provides.build: llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.provides.build

llwindow/CMakeFiles/llwindow.dir/llwindow.o: llwindow/CMakeFiles/llwindow.dir/flags.make
llwindow/CMakeFiles/llwindow.dir/llwindow.o: ../llwindow/llwindow.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gareth/slbrowser/linden/indra/viewer-linux-i686/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object llwindow/CMakeFiles/llwindow.dir/llwindow.o"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/llwindow.dir/llwindow.o -c /home/gareth/slbrowser/linden/indra/llwindow/llwindow.cpp

llwindow/CMakeFiles/llwindow.dir/llwindow.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llwindow.dir/llwindow.i"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gareth/slbrowser/linden/indra/llwindow/llwindow.cpp > CMakeFiles/llwindow.dir/llwindow.i

llwindow/CMakeFiles/llwindow.dir/llwindow.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llwindow.dir/llwindow.s"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gareth/slbrowser/linden/indra/llwindow/llwindow.cpp -o CMakeFiles/llwindow.dir/llwindow.s

llwindow/CMakeFiles/llwindow.dir/llwindow.o.requires:
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindow.o.requires

llwindow/CMakeFiles/llwindow.dir/llwindow.o.provides: llwindow/CMakeFiles/llwindow.dir/llwindow.o.requires
	$(MAKE) -f llwindow/CMakeFiles/llwindow.dir/build.make llwindow/CMakeFiles/llwindow.dir/llwindow.o.provides.build
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindow.o.provides

llwindow/CMakeFiles/llwindow.dir/llwindow.o.provides.build: llwindow/CMakeFiles/llwindow.dir/llwindow.o
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindow.o.provides.build

llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o: llwindow/CMakeFiles/llwindow.dir/flags.make
llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o: ../llwindow/llkeyboardsdl.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gareth/slbrowser/linden/indra/viewer-linux-i686/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/llwindow.dir/llkeyboardsdl.o -c /home/gareth/slbrowser/linden/indra/llwindow/llkeyboardsdl.cpp

llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llwindow.dir/llkeyboardsdl.i"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gareth/slbrowser/linden/indra/llwindow/llkeyboardsdl.cpp > CMakeFiles/llwindow.dir/llkeyboardsdl.i

llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llwindow.dir/llkeyboardsdl.s"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gareth/slbrowser/linden/indra/llwindow/llkeyboardsdl.cpp -o CMakeFiles/llwindow.dir/llkeyboardsdl.s

llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.requires:
.PHONY : llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.requires

llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.provides: llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.requires
	$(MAKE) -f llwindow/CMakeFiles/llwindow.dir/build.make llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.provides.build
.PHONY : llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.provides

llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.provides.build: llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o
.PHONY : llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.provides.build

llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o: llwindow/CMakeFiles/llwindow.dir/flags.make
llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o: ../llwindow/llwindowsdl.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gareth/slbrowser/linden/indra/viewer-linux-i686/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/llwindow.dir/llwindowsdl.o -c /home/gareth/slbrowser/linden/indra/llwindow/llwindowsdl.cpp

llwindow/CMakeFiles/llwindow.dir/llwindowsdl.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llwindow.dir/llwindowsdl.i"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gareth/slbrowser/linden/indra/llwindow/llwindowsdl.cpp > CMakeFiles/llwindow.dir/llwindowsdl.i

llwindow/CMakeFiles/llwindow.dir/llwindowsdl.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llwindow.dir/llwindowsdl.s"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gareth/slbrowser/linden/indra/llwindow/llwindowsdl.cpp -o CMakeFiles/llwindow.dir/llwindowsdl.s

llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.requires:
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.requires

llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.provides: llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.requires
	$(MAKE) -f llwindow/CMakeFiles/llwindow.dir/build.make llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.provides.build
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.provides

llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.provides.build: llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o
.PHONY : llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.provides.build

# Object files for target llwindow
llwindow_OBJECTS = \
"CMakeFiles/llwindow.dir/llkeyboard.o" \
"CMakeFiles/llwindow.dir/llwindowheadless.o" \
"CMakeFiles/llwindow.dir/llwindow.o" \
"CMakeFiles/llwindow.dir/llkeyboardsdl.o" \
"CMakeFiles/llwindow.dir/llwindowsdl.o"

# External object files for target llwindow
llwindow_EXTERNAL_OBJECTS =

llwindow/libllwindow.a: llwindow/CMakeFiles/llwindow.dir/llkeyboard.o
llwindow/libllwindow.a: llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o
llwindow/libllwindow.a: llwindow/CMakeFiles/llwindow.dir/llwindow.o
llwindow/libllwindow.a: llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o
llwindow/libllwindow.a: llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o
llwindow/libllwindow.a: llwindow/CMakeFiles/llwindow.dir/build.make
llwindow/libllwindow.a: llwindow/CMakeFiles/llwindow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libllwindow.a"
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && $(CMAKE_COMMAND) -P CMakeFiles/llwindow.dir/cmake_clean_target.cmake
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/llwindow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
llwindow/CMakeFiles/llwindow.dir/build: llwindow/libllwindow.a
.PHONY : llwindow/CMakeFiles/llwindow.dir/build

llwindow/CMakeFiles/llwindow.dir/requires: llwindow/CMakeFiles/llwindow.dir/llkeyboard.o.requires
llwindow/CMakeFiles/llwindow.dir/requires: llwindow/CMakeFiles/llwindow.dir/llwindowheadless.o.requires
llwindow/CMakeFiles/llwindow.dir/requires: llwindow/CMakeFiles/llwindow.dir/llwindow.o.requires
llwindow/CMakeFiles/llwindow.dir/requires: llwindow/CMakeFiles/llwindow.dir/llkeyboardsdl.o.requires
llwindow/CMakeFiles/llwindow.dir/requires: llwindow/CMakeFiles/llwindow.dir/llwindowsdl.o.requires
.PHONY : llwindow/CMakeFiles/llwindow.dir/requires

llwindow/CMakeFiles/llwindow.dir/clean:
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow && $(CMAKE_COMMAND) -P CMakeFiles/llwindow.dir/cmake_clean.cmake
.PHONY : llwindow/CMakeFiles/llwindow.dir/clean

llwindow/CMakeFiles/llwindow.dir/depend:
	cd /home/gareth/slbrowser/linden/indra/viewer-linux-i686 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gareth/slbrowser/linden/indra /home/gareth/slbrowser/linden/indra/llwindow /home/gareth/slbrowser/linden/indra/viewer-linux-i686 /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow /home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow/CMakeFiles/llwindow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : llwindow/CMakeFiles/llwindow.dir/depend
