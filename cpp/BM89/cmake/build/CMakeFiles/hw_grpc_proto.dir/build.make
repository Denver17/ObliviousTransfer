# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denver/ot/ObliviousTransfer/cpp/BM89

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/hw_grpc_proto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hw_grpc_proto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hw_grpc_proto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw_grpc_proto.dir/flags.make

NonInteractiveOT.pb.cc: /home/denver/ot/ObliviousTransfer/protos/NonInteractiveOT.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating NonInteractiveOT.pb.cc, NonInteractiveOT.pb.h, NonInteractiveOT.grpc.pb.cc, NonInteractiveOT.grpc.pb.h, {hw_StringCharArray_srcs}, {hw_StringCharArray_hdrs}, {hw_RWfile_srcs}, {hw_RWfile_hdrs}, {hw_ZZCal_srcs}, {hw_ZZCal_hdrs}"
	/usr/local/bin/protoc-23.1.0 --grpc_out /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build --cpp_out /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build -I /home/denver/ot/ObliviousTransfer/protos --plugin=protoc-gen-grpc="/usr/local/bin/grpc_cpp_plugin" /home/denver/ot/ObliviousTransfer/protos/NonInteractiveOT.proto

NonInteractiveOT.pb.h: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate NonInteractiveOT.pb.h

NonInteractiveOT.grpc.pb.cc: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate NonInteractiveOT.grpc.pb.cc

NonInteractiveOT.grpc.pb.h: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate NonInteractiveOT.grpc.pb.h

{hw_StringCharArray_srcs}: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate {hw_StringCharArray_srcs}

{hw_StringCharArray_hdrs}: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate {hw_StringCharArray_hdrs}

{hw_RWfile_srcs}: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate {hw_RWfile_srcs}

{hw_RWfile_hdrs}: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate {hw_RWfile_hdrs}

{hw_ZZCal_srcs}: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate {hw_ZZCal_srcs}

{hw_ZZCal_hdrs}: NonInteractiveOT.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate {hw_ZZCal_hdrs}

CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o: CMakeFiles/hw_grpc_proto.dir/flags.make
CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o: NonInteractiveOT.grpc.pb.cc
CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o: CMakeFiles/hw_grpc_proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o -MF CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o.d -o CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o -c /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/NonInteractiveOT.grpc.pb.cc

CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/NonInteractiveOT.grpc.pb.cc > CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.i

CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/NonInteractiveOT.grpc.pb.cc -o CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.s

CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o: CMakeFiles/hw_grpc_proto.dir/flags.make
CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o: NonInteractiveOT.pb.cc
CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o: CMakeFiles/hw_grpc_proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o -MF CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o.d -o CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o -c /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/NonInteractiveOT.pb.cc

CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/NonInteractiveOT.pb.cc > CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.i

CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/NonInteractiveOT.pb.cc -o CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.s

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o: CMakeFiles/hw_grpc_proto.dir/flags.make
CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o: /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc
CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o: CMakeFiles/hw_grpc_proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o -MF CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o.d -o CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o -c /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc > CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.i

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc -o CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.s

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o: CMakeFiles/hw_grpc_proto.dir/flags.make
CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o: /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc
CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o: CMakeFiles/hw_grpc_proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o -MF CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o.d -o CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o -c /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc > CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.i

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc -o CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.s

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o: CMakeFiles/hw_grpc_proto.dir/flags.make
CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o: /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc
CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o: CMakeFiles/hw_grpc_proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o -MF CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o.d -o CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o -c /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc > CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.i

CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc -o CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.s

# Object files for target hw_grpc_proto
hw_grpc_proto_OBJECTS = \
"CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o" \
"CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o" \
"CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o" \
"CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o" \
"CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o"

# External object files for target hw_grpc_proto
hw_grpc_proto_EXTERNAL_OBJECTS =

libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.grpc.pb.cc.o
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/NonInteractiveOT.pb.cc.o
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/StringCharArray.cc.o
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/RWfile.cc.o
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/home/denver/ot/ObliviousTransfer/cpp/CryptoTools/ZZCal.cc.o
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/build.make
libhw_grpc_proto.a: CMakeFiles/hw_grpc_proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libhw_grpc_proto.a"
	$(CMAKE_COMMAND) -P CMakeFiles/hw_grpc_proto.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw_grpc_proto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw_grpc_proto.dir/build: libhw_grpc_proto.a
.PHONY : CMakeFiles/hw_grpc_proto.dir/build

CMakeFiles/hw_grpc_proto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw_grpc_proto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw_grpc_proto.dir/clean

CMakeFiles/hw_grpc_proto.dir/depend: NonInteractiveOT.grpc.pb.cc
CMakeFiles/hw_grpc_proto.dir/depend: NonInteractiveOT.grpc.pb.h
CMakeFiles/hw_grpc_proto.dir/depend: NonInteractiveOT.pb.cc
CMakeFiles/hw_grpc_proto.dir/depend: NonInteractiveOT.pb.h
CMakeFiles/hw_grpc_proto.dir/depend: {hw_RWfile_hdrs}
CMakeFiles/hw_grpc_proto.dir/depend: {hw_RWfile_srcs}
CMakeFiles/hw_grpc_proto.dir/depend: {hw_StringCharArray_hdrs}
CMakeFiles/hw_grpc_proto.dir/depend: {hw_StringCharArray_srcs}
CMakeFiles/hw_grpc_proto.dir/depend: {hw_ZZCal_hdrs}
CMakeFiles/hw_grpc_proto.dir/depend: {hw_ZZCal_srcs}
	cd /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denver/ot/ObliviousTransfer/cpp/BM89 /home/denver/ot/ObliviousTransfer/cpp/BM89 /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build /home/denver/ot/ObliviousTransfer/cpp/BM89/cmake/build/CMakeFiles/hw_grpc_proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw_grpc_proto.dir/depend

