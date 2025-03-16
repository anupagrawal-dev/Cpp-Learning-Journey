CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(Main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(HEADER_DIR "${PROJECT_SOURCE_DIR}/header")
set(LIB_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/DLLs/Templates")

# Set the bin and lib directories inside the build folder
set(LIB_DIR "${PROJECT_BINARY_DIR}/lib")
set(BIN_DIR "${PROJECT_BINARY_DIR}/bin")

file(MAKE_DIRECTORY "${LIB_DIR}")
file(MAKE_DIRECTORY "${BIN_DIR}")

# To create shared library for source code of templates.
file(GLOB lib_source_files "${LIB_SOURCE_DIR}/*.cpp")
add_library(templates SHARED "${lib_source_files}")
set_target_properties(templates PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${LIB_DIR}")
target_include_directories(templates PRIVATE "${HEADER_DIR}")

# To create .o files for all .cpp code except Library code
file(GLOB source_files "${SOURCE_DIR}/*.cpp")
add_executable(Main "${source_files}")
set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")
target_include_directories(Main PRIVATE "${HEADER_DIR}")

# Link all libraries and .o files. And create final Main executable file
target_link_libraries(Main templates)
