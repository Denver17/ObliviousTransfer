cmake_minimum_required(VERSION 3.8)

project(SimplestOT C CXX)

include(../cmake/common.cmake)

# Proto file
get_filename_component(hw_proto "../../protos/SimplestOT.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

# Generated sources
set(hw_RWfile_srcs "../../../CryptoTools/RWfile.cc")
set(hw_RWfile_hdrs "../../../CryptoTools/RWfile.h")
set(hw_StringCharArray_srcs "../../../CryptoTools/StringCharArray.cc")
set(hw_StringCharArray_hdrs "../../../CryptoTools/StringCharArray.h")
set(hw_sha256_srcs "../../../CryptoTools/sha256.cc")
set(hw_sha256_hdrs "../../../CryptoTools/sha256.h")
set(hw_aes_srcs "../../../CryptoTools/aes.cc")
set(hw_aes_hdrs "../../../CryptoTools/aes.h")
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/SimplestOT.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/SimplestOT.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/SimplestOT.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/SimplestOT.grpc.pb.h")
add_custom_command(
      OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}" "${hw_aes_srcs}" "${hw_aes_hdrs}" "{hw_sha256_srcs}" "{hw_sha256_hdrs}" "{hw_StringCharArray_srcs}" "{hw_StringCharArray_hdrs}" "{hw_RWfile_srcs}" "{hw_RWfile_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
      DEPENDS "${hw_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# hw_grpc_proto
add_library(hw_grpc_proto
  ${hw_grpc_srcs}
  ${hw_grpc_hdrs}
  ${hw_proto_srcs}
  ${hw_proto_hdrs}
  ${hw_aes_srcs}
  ${hw_aes_hdrs}
  ${hw_sha256_srcs}
  ${hw_sha256_hdrs}
  ${hw_StringCharArray_srcs}
  ${hw_StringCharArray_hdrs}
  ${hw_RWfile_srcs}
  ${hw_RWfile_hdrs})
target_link_libraries(hw_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})


# Targets SimplestOT_[async_](sender|chooser)
foreach(_target
  SimplestOT_sender SimplestOT_chooser)
  add_executable(${_target} "${_target}.cc")
  target_link_libraries(${_target}
    hw_grpc_proto
    absl::flags
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
    ntl
    gmp)
endforeach()
