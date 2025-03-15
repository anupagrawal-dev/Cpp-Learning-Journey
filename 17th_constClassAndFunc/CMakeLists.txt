CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

#Project Name and Language
PROJECT(Main)

# Enable strict Compilation warnings
add_compile_options(-Wall -Werror)

# Set source and header directories
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(HEADER_DIR "${PROJECT_SOURCE_DIR}/header")

# Collect all source files
file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.cpp")

# Define the executable target FIRST
add_executable(Main ${SOURCE_FILES})

# Include the header directory in a target-specific way
target_include_directories(Main PRIVATE "${HEADER_DIR}")

# Set C++ Standard
set_target_properties(Main PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

# Print source files (for debugging)
message(STATUS "Source files : ${SOURCE_FILES}")

# Debugging: Print directory paths
message(STATUS "Project directory: ${PROJECT_DIR}")
message(STATUS "Source directory: ${SOURCE_DIR}")
message(STATUS "Header directory: ${HEADER_DIR}")
