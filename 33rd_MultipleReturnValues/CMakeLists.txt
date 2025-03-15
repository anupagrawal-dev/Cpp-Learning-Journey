CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(Main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(HEADER_DIR "${PROJECT_SOURCE_DIR}/header")
set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")
set(LIB_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/DLLs/MultiRet_Ways")
set(BIN_DIR "${PROJECT_SOURCE_DIR}/bin")

file(MAKE_DIRECTORY "${LIB_DIR}")
file(MAKE_DIRECTORY "${BIN_DIR}")

file(GLOB lib_source_files "${LIB_SOURCE_DIR}/*.cpp")

add_library(mulret_ways SHARED "${lib_source_files}")

set_target_properties(mulret_ways PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${LIB_DIR}")
target_include_directories(mulret_ways PRIVATE "${HEADER_DIR}")

file(GLOB source_files "${SOURCE_DIR}/*.cpp")

add_executable(Main "${source_files}")

set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

target_include_directories(Main PRIVATE "${HEADER_DIR}")

target_link_libraries(Main mulret_ways)
