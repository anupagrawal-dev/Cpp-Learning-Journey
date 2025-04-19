cmake_minimum_required(VERSION 3.24)

# Project Name & Language Standard
project(FunctionPointers LANGUAGES CXX)

# Enforce Modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Warnings (Best Practices)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# Directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_BINARY_DIR}/lib")
set(BIN_DIR "${CMAKE_BINARY_DIR}/bin")

# Create Library
add_library(FunctionPointers SHARED
	${SRC_DIR}/DLLs/FunctionPointers/FunctionPointers.cpp
)
target_include_directories(FunctionPointers PRIVATE ${INCLUDE_DIR})
set_target_properties(FunctionPointers PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})

# Create Executable
add_executable(Main
	${SRC_DIR}/Main.cpp
)
target_include_directories(Main PRIVATE ${INCLUDE_DIR})
target_link_libraries(Main PRIVATE FunctionPointers)
set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
