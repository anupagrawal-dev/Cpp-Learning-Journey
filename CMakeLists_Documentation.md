# CMakeLists.txt Documentation

This document explains the **functions, variables, and configurations** used in the `CMakeLists.txt` files across this project. It follows the exact structure used in the repository and includes explanations for commonly used built-in variables.

---

## **1. Basic Executable Setup**

### **CMake Minimum Required Version**
```cmake
CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
```
- Sets the minimum required CMake version to **3.2** to ensure compatibility with required features.

### **Project Definition**
```cmake
PROJECT(Main)
```
- Defines the project name as `Main`. This is used internally by CMake to manage build settings.

### **Compiler Flags**
```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
```
- Adds the compiler flags `-Wall` (show all warnings) and `-Werror` (treat warnings as errors) to ensure strict code quality.

### **Source and Include Directories**
```cmake
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
include_directories("${PROJECT_SOURCE_DIR}/header")
```
- `PROJECT_SOURCE_DIR` is a built-in variable that represents the root directory of the project.
- `include_directories` adds the `header` directory to the project for header file accessibility.

### **File Search and Executable Creation**
```cmake
file(GLOB source_files "${source_dir}/*.cpp")
add_executable(Main ${source_files})
```
- `file(GLOB ...)` finds all `.cpp` source files in the given directory.
- `add_executable(Main ...)` creates an executable named `Main` from the source files.

---

## **2. Alternative Executable Setup**

### **Adding Compile Options Instead of CXX Flags**
```cmake
add_compile_options(-Wall -Werror)
```
- This is an alternative way to add compiler flags, keeping them separate from `CMAKE_CXX_FLAGS`.

### **Using Different Variables for Organization**
```cmake
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(HEADER_DIR "${PROJECT_SOURCE_DIR}/header")
```
- Uses more descriptive variable names for better readability.

### **Target-Specific Include Directories**
```cmake
target_include_directories(Main PRIVATE "${HEADER_DIR}")
```
- Specifies that `Main` should include the `HEADER_DIR` headers, but they remain private to this target.

---

## **3. Static Library Setup**

### **Library Creation**
```cmake
add_library(mylib STATIC "${SOURCE_DIR}/Cal.cpp")
```
- Creates a **static library** called `mylib` using `Cal.cpp`.

### **Setting Archive Output Directory**
```cmake
set_target_properties(mylib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${LIB_DIR}")
```
- Ensures the static library `.a` file is stored in the `lib` directory.

### **Linking the Static Library to an Executable**
```cmake
target_link_libraries(Main mylib)
```
- Links the `mylib` static library to the `Main` executable.

---

## **4. Shared Library Setup**

### **Shared Library Creation**
```cmake
set(LIB_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/DLLs/MultiRet_Ways")
set(BIN_DIR "${PROJECT_SOURCE_DIR}/bin")

file(MAKE_DIRECTORY "${LIB_DIR}")
file(MAKE_DIRECTORY "${BIN_DIR}")

file(GLOB lib_source_files "${LIB_SOURCE_DIR}/*.cpp")

add_library(mylib SHARED "${lib_source_files}")
```
- `file(MAKE_DIRECTORY ...)` ensures that necessary directories exist for shared libraries and binaries **before compilation**.
- If the directory does not exist, CMake **automatically creates it**.
- `file(GLOB lib_source_files ...)` gathers all `.cpp` source files in the shared library directory.
- `add_library(mylib SHARED ...)` creates a shared library named `mylib`.

### **Setting Output Directory for Shared Library**
```cmake
set_target_properties(mylib PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${LIB_DIR}")
```
- Ensures that the shared library `.so` or `.dll` file is stored in the `lib` directory.

### **Linking the Shared Library to an Executable**
```cmake
set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

target_include_directories(Main PRIVATE "${HEADER_DIR}")
target_link_libraries(Main PRIVATE mylib)
```
- `set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")` ensures that the `Main` executable is stored in the `bin` directory.
- `target_include_directories(Main PRIVATE "${HEADER_DIR}")` includes necessary headers.
- `target_link_libraries(Main PRIVATE mylib)` links the shared library `mylib` to the `Main` executable.

---

## **Common Built-in CMake Variables**
### **PROJECT_SOURCE_DIR**
- Represents the root directory of the project.
- Used to define paths for source, headers, and libraries.

### **CMAKE_CURRENT_SOURCE_DIR**
- Represents the directory where the current `CMakeLists.txt` is located.
- Useful for defining relative paths inside subdirectories.

### **CMAKE_BINARY_DIR**
- Represents the directory where the build output is generated.
- Can be used to set output directories for compiled binaries.

### **CMAKE_CXX_FLAGS**
- Contains default compiler flags for C++.
- Can be modified to include additional flags like `-Wall` and `-Werror`.

---

## **Example from This Project**
Here’s an example taken directly from one of the `CMakeLists.txt` files in this repository:
```cmake
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
```

---

## **Conclusion**
This document explains the **three different formats** of `CMakeLists.txt` used in this project, covering:
1. **Basic Executable Setup**
2. **Alternative Executable Setup with `add_compile_options`**
3. **Static and Shared Library Setup**

Additionally, built-in CMake variables like `PROJECT_SOURCE_DIR`, `CMAKE_CURRENT_SOURCE_DIR`, and `CMAKE_CXX_FLAGS` are documented for reference.

🚀 Happy Coding!
