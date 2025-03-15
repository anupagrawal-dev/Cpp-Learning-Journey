CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

PROJECT(Main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(HEADER_DIR "${PROJECT_SOURCE_DIR}/header")
set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")

file(GLOB source_files "${SOURCE_DIR}/Main.cpp")

add_library(mylib STATIC "${SOURCE_DIR}/Cal.cpp")
set_target_properties(mylib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${LIB_DIR}")

target_include_directories(mylib PRIVATE "${HEADER_DIR}")

add_executable(Main "${source_files}")

target_include_directories(Main PRIVATE "${HEADER_DIR}")

target_link_libraries(Main mylib)
