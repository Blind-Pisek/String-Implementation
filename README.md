# String Implementation

This repository contains my own implementation of a string class in C++. I created this project to study C++ concepts and improve my programming skills. Please note that this implementation is a work in progress and may contain bugs and limitations.

## Features

The string class implementation in this repository offers the following features:

- Construction:
  - `String()`: Creates an empty string with a size of 0.
  - `String(const char* src_data)`: Constructs a string from a C-style character array.
  - `String(const String& _str)`: Copy constructor to create a string from another string object.

- Modification:
  - `add_char(const char _el, const size_t _index)`: Adds a character at the specified position in the string.
  - `delete_element(const size_t _index)`: Deletes the element at the specified position in the string.
  - `erase(size_t _pos, size_t _len)`: Deletes a range of elements in the string.
  - `erase(It<char> _first, It<char> _last)`: Deletes a range of elements specified by iterators in the string.
  - `to_upper()`: Converts all characters in the string to uppercase.
  - `to_lower()`: Converts all characters in the string to lowercase.
  - `reverse()`: Reverses the entire string.

- Access:
  - `char operator[](const size_t _pos) const`: Retrieves the character at the specified position in the string.

- Concatenation:
  - `friend String operator+(const String& string1, const String& string2)`: Concatenates two string objects.

- Iteration:
  - `begin()`: Generates an iterator pointing to the first element of the string.
  - `end()`: Generates an iterator pointing to the element after the last element of the string.
.

## Bugs and Limitations

Please be aware that this string implementation is a work in progress and may contain bugs and limitations. Some potential issues you may encounter include:

- Incomplete functionality: Some string operations may be missing or not fully implemented.

## Contribution

You are welcome to contribute to this project by reporting bugs, suggesting improvements, or submitting pull requests. However, please keep in mind that this repository is primarily for personal study purposes, and contributions should align with that objective.

## License

This repository is licensed under the [MIT License](LICENSE). Feel free to use and modify the code for your own purposes, but please attribute the original work to the respective author mentioned in the source code.
