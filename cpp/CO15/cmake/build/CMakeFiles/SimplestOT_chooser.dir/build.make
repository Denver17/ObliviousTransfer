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
CMAKE_SOURCE_DIR = /home/denver/ot/Oblivious_Transfer/cpp/CO15

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denver/ot/Oblivious_Transfer/cpp/CO15/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/SimplestOT_chooser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SimplestOT_chooser.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SimplestOT_chooser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimplestOT_chooser.dir/flags.make

CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o: CMakeFiles/SimplestOT_chooser.dir/flags.make
CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o: ../../SimplestOT_chooser.cc
CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o: CMakeFiles/SimplestOT_chooser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denver/ot/Oblivious_Transfer/cpp/CO15/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o -MF CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o.d -o CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o -c /home/denver/ot/Oblivious_Transfer/cpp/CO15/SimplestOT_chooser.cc

CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denver/ot/Oblivious_Transfer/cpp/CO15/SimplestOT_chooser.cc > CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.i

CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denver/ot/Oblivious_Transfer/cpp/CO15/SimplestOT_chooser.cc -o CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.s

# Object files for target SimplestOT_chooser
SimplestOT_chooser_OBJECTS = \
"CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o"

# External object files for target SimplestOT_chooser
SimplestOT_chooser_EXTERNAL_OBJECTS =

SimplestOT_chooser: CMakeFiles/SimplestOT_chooser.dir/SimplestOT_chooser.cc.o
SimplestOT_chooser: CMakeFiles/SimplestOT_chooser.dir/build.make
SimplestOT_chooser: libhw_grpc_proto.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_parse.a
SimplestOT_chooser: /usr/local/lib/libgrpc++_reflection.a
SimplestOT_chooser: /usr/local/lib/libgrpc++.a
SimplestOT_chooser: /usr/local/lib/libprotobuf.a
SimplestOT_chooser: /usr/local/lib/libgrpc.a
SimplestOT_chooser: /usr/local/lib/libcares.a
SimplestOT_chooser: /usr/local/lib/libaddress_sorting.a
SimplestOT_chooser: /usr/local/lib/libre2.a
SimplestOT_chooser: /usr/local/lib/libupb.a
SimplestOT_chooser: /usr/local/lib/libgpr.a
SimplestOT_chooser: /usr/local/lib/libz.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_distributions.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_seed_sequences.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_internal_pool_urbg.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_internal_randen.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_internal_randen_hwaes.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_internal_randen_hwaes_impl.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_internal_randen_slow.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_internal_platform.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_internal_seed_material.a
SimplestOT_chooser: /usr/local/lib/libabsl_random_seed_gen_exception.a
SimplestOT_chooser: /usr/local/lib/libssl.a
SimplestOT_chooser: /usr/local/lib/libcrypto.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_check_op.a
SimplestOT_chooser: /usr/local/lib/libabsl_leak_check.a
SimplestOT_chooser: /usr/local/lib/libabsl_die_if_null.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_conditions.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_message.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_nullguard.a
SimplestOT_chooser: /usr/local/lib/libabsl_examine_stack.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_format.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_proto.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_log_sink_set.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_sink.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_entry.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_initialize.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_globals.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_internal_globals.a
SimplestOT_chooser: /usr/local/lib/libabsl_statusor.a
SimplestOT_chooser: /usr/local/lib/libabsl_status.a
SimplestOT_chooser: /usr/local/lib/libabsl_strerror.a
SimplestOT_chooser: /usr/local/lib/libutf8_validity.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_usage.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_usage_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_marshalling.a
SimplestOT_chooser: /usr/local/lib/libabsl_str_format_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_reflection.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_config.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_private_handle_accessor.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_commandlineflag.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_commandlineflag_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_flags_program_name.a
SimplestOT_chooser: /usr/local/lib/libabsl_cord.a
SimplestOT_chooser: /usr/local/lib/libabsl_cordz_info.a
SimplestOT_chooser: /usr/local/lib/libabsl_cord_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_cordz_functions.a
SimplestOT_chooser: /usr/local/lib/libabsl_cordz_handle.a
SimplestOT_chooser: /usr/local/lib/libabsl_crc_cord_state.a
SimplestOT_chooser: /usr/local/lib/libabsl_crc32c.a
SimplestOT_chooser: /usr/local/lib/libabsl_crc_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_crc_cpu_detect.a
SimplestOT_chooser: /usr/local/lib/libabsl_hash.a
SimplestOT_chooser: /usr/local/lib/libabsl_bad_variant_access.a
SimplestOT_chooser: /usr/local/lib/libabsl_city.a
SimplestOT_chooser: /usr/local/lib/libabsl_low_level_hash.a
SimplestOT_chooser: /usr/local/lib/libabsl_raw_hash_set.a
SimplestOT_chooser: /usr/local/lib/libabsl_bad_optional_access.a
SimplestOT_chooser: /usr/local/lib/libabsl_hashtablez_sampler.a
SimplestOT_chooser: /usr/local/lib/libabsl_exponential_biased.a
SimplestOT_chooser: /usr/local/lib/libabsl_synchronization.a
SimplestOT_chooser: /usr/local/lib/libabsl_graphcycles_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_time.a
SimplestOT_chooser: /usr/local/lib/libabsl_civil_time.a
SimplestOT_chooser: /usr/local/lib/libabsl_time_zone.a
SimplestOT_chooser: /usr/local/lib/libabsl_stacktrace.a
SimplestOT_chooser: /usr/local/lib/libabsl_symbolize.a
SimplestOT_chooser: /usr/local/lib/libabsl_strings.a
SimplestOT_chooser: /usr/local/lib/libabsl_strings_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_int128.a
SimplestOT_chooser: /usr/local/lib/libabsl_throw_delegate.a
SimplestOT_chooser: /usr/local/lib/libabsl_malloc_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_debugging_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_demangle_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_base.a
SimplestOT_chooser: /usr/local/lib/libabsl_raw_logging_internal.a
SimplestOT_chooser: /usr/local/lib/libabsl_log_severity.a
SimplestOT_chooser: /usr/local/lib/libabsl_spinlock_wait.a
SimplestOT_chooser: CMakeFiles/SimplestOT_chooser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denver/ot/Oblivious_Transfer/cpp/CO15/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SimplestOT_chooser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimplestOT_chooser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimplestOT_chooser.dir/build: SimplestOT_chooser
.PHONY : CMakeFiles/SimplestOT_chooser.dir/build

CMakeFiles/SimplestOT_chooser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimplestOT_chooser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimplestOT_chooser.dir/clean

CMakeFiles/SimplestOT_chooser.dir/depend:
	cd /home/denver/ot/Oblivious_Transfer/cpp/CO15/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denver/ot/Oblivious_Transfer/cpp/CO15 /home/denver/ot/Oblivious_Transfer/cpp/CO15 /home/denver/ot/Oblivious_Transfer/cpp/CO15/cmake/build /home/denver/ot/Oblivious_Transfer/cpp/CO15/cmake/build /home/denver/ot/Oblivious_Transfer/cpp/CO15/cmake/build/CMakeFiles/SimplestOT_chooser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimplestOT_chooser.dir/depend
