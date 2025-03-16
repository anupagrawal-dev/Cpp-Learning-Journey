# C++ Learning Journey 🚀

This repository contains my structured C++ learning journey inspired by Cherno’s YouTube tutorials. 
Each topic has a dedicated folder, following a structured format with `src/`, `header/`, and `CMakeLists.txt` files.

---

## 📂 Folder Structure

The topics are arranged sequentially from basic to advanced.

### 🔹 **1_Basics/** (Fundamental Concepts)
- `logger_debugging/` - Implementing logging and debugging techniques.
- `class_basics/` - Introduction to classes and objects in C++.
- `advanced_classes/` - Deep dive into class features.
- `static_classes/` - Understanding static members and classes.
- `enums_basics/` - Basics of enumerations.
- `enums_with_logs/` - Using enums in logging mechanisms.
- `arrow_operator/` - Using the arrow operator with pointers.
- `sizeof_operator_usage/` - Using the `sizeof` operator.
- `ternary_operator/` - Working with the ternary operator.

### 🔹 **2_OOP_Fundamentals/** (Core Object-Oriented Programming)
- `constructors_destructors/` - Understanding constructors and destructors.
- `setters_getters/` - Using setter and getter functions.
- `copy_constructor/` - Deep vs. shallow copy concepts.
- `const_basics/` - Using `const` in different contexts.
- `const_class_and_functions/` - Applying `const` to classes and functions.
- `constructor_initializer_list/` - Using initializer lists in constructors.

### 🔹 **3_Advanced_OOP/** (Advanced Object-Oriented Concepts)
- `virtual_functions_pointers/` - Understanding virtual functions and pointers.
- `interfaces_abstract_classes/` - Interfaces and abstract classes.
- `operator_overloading/` - Overloading operators.
- `multiple_return_values/` - Methods for returning multiple values.
- `inheritance_oop/` - Implementing inheritance in C++.
- `destructor_basics/` - Detailed behavior of destructors.
- `object_lifetime_memory/` - Object creation and destruction lifecycle.

### 🔹 **4_Memory_Management/** (Efficient Memory Handling)
- `arrays_basics/` - Introduction to arrays.
- `arrays_advanced/` - Advanced array concepts.
- `dynamic_arrays_vectors/` - Using dynamic arrays.
- `smart_pointers/` - Using unique, shared, and weak pointers.
- `custom_string_class/` - Implementing a custom string class.
- `local_static_variables/` - Local static variables and scope.
- `strings_manipulation/` - Working with C++ string operations.

### 🔹 **5_Advanced_Topics/** (Advanced Programming)
- `Templates/` - Working with templates, exploring function and class templates.


### 🔹 **6_Libraries_and_Compilation/** (Building and Linking)
- `static_libraries/` - Creating and using static libraries.
- `shared_libraries/` - Implementing shared libraries.

---

## 🛠️ How to Build

Each topic has its own `CMakeLists.txt`, so you need to navigate to the specific folder before building.

To build a specific topic, follow these steps:
```sh
cd <section_folder>/<topic_folder>
mkdir build && cd build
cmake ..
make
```
For example:
```sh
cd 1_Basics/class_basics
mkdir build && cd build
cmake ..
make
./Main # Replace with the actual executable name

Or

./bin/Main # At initial i have created binary file directly where we do compilation. Later on started putting Executable files inside bin folder.Replace Main with the actual executable name.
```

---

## 📌 Key Learnings
- Mastering C++ fundamentals and object-oriented programming.
- Understanding pointers, memory management, and smart pointers.
- Using CMake to structure and build projects efficiently.
- Implementing advanced C++ features like operator overloading, virtual functions, and custom libraries.

---

## 🔗 Useful Links
- [Cherno's C++ Playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)
- [C++ Reference](https://en.cppreference.com/w/)
- [Modern C++ Features](https://cppfeatures.com/)

---

## 🤝 Contributing
This is a personal learning repository, but feel free to share suggestions or improvements via pull requests.

---

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
