CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(Main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(HEADER_DIR "${PROJECT_SOURCE_DIR}/header")

file(GLOB source_files "${SOURCE_DIR}/*.cpp")
add_executable(Main "${source_files}")

target_include_directories(Main PRIVATE "${HEADER_DIR}")
