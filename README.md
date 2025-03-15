# C++ Learning Journey 🚀

This repository contains my structured C++ learning journey inspired by Cherno’s YouTube tutorials. 
Each topic has a dedicated folder, following a structured format with `src/`, `header/`, and `CMakeLists.txt` files.

---

## 📂 Folder Structure

Each section contains multiple topic folders. To navigate:
```
cd <section_folder>/<topic_folder>
```

### 🔹 **Fundamentals**
- `fundamentals/logger_debugging/` - Implementing logging and debugging techniques.
- `fundamentals/class_basics/` - Introduction to classes and objects in C++.
- `fundamentals/advanced_classes/` - Deep dive into class features.
- `fundamentals/static_classes/` - Understanding static members and classes.
- `fundamentals/enums_basics/` - Basics of enumerations.
- `fundamentals/enums_with_logs/` - Using enums in logging mechanisms.

### 🔹 **OOP Concepts**
- `oop_concepts/constructors_destructors/` - Understanding constructors and destructors.
- `oop_concepts/destructor_basics/` - Detailed behavior of destructors.
- `oop_concepts/inheritance_oop/` - Implementing inheritance in C++.
- `oop_concepts/setters_getters/` - Using setter and getter functions.
- `oop_concepts/this_pointer_usage/` - Understanding the `this` pointer.
- `oop_concepts/object_lifetime_memory/` - Object creation and destruction lifecycle.
- `oop_concepts/copy_constructor/` - Deep vs. shallow copy concepts.

### 🔹 **Memory Management**
- `memory_management/arrays_basics/` - Introduction to arrays.
- `memory_management/arrays_advanced/` - Advanced array concepts.
- `memory_management/dynamic_arrays_vectors/` - Using dynamic arrays.
- `memory_management/smart_pointers/` - Using unique, shared, and weak pointers.
- `memory_management/custom_string_class/` - Implementing a custom string class.

### 🔹 **Advanced Topics**
- `advanced_topics/virtual_functions_pointers/` - Understanding virtual functions and pointers.
- `advanced_topics/interfaces_abstract_classes/` - Interfaces and abstract classes.
- `advanced_topics/operator_overloading/` - Overloading operators.
- `advanced_topics/arrow_operator/` - Using the arrow operator with pointers.
- `advanced_topics/ternary_operator/` - Working with the ternary operator.
- `advanced_topics/sizeof_operator_usage/` - Using the `sizeof` operator.
- `advanced_topics/const_basics/` - Using `const` in different contexts.
- `advanced_topics/const_class_and_functions/` - Applying `const` to classes and functions.
- `advanced_topics/constructor_initializer_list/` - Using initializer lists in constructors.
- `advanced_topics/implicit_explicit_keywords/` - Understanding implicit and explicit keyword behavior.
- `advanced_topics/multiple_return_values/` - Methods for returning multiple values.
- `advanced_topics/local_static_variables/` - Local static variables and scope.

### 🔹 **C++ Libraries and Compilation**
- `libraries_and_compilation/static_libraries/` - Creating and using static libraries.
- `libraries_and_compilation/shared_libraries/` - Implementing shared libraries.

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
cd fundamentals/class_basics
mkdir build && cd build
cmake ..
make
./ClassBasicsExecutable  # Replace with the actual executable name
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
