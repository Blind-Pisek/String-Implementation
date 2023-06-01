/* File Name         : string.h
* Author             : Karol Pisarski
* Email				 : karol.pisarski@outlook.com
* Version            : v1.3 Final
* Date               : 17/09/2022
* Desciption         : This file contains the functions for the own stl string library			   
********************************************************************************/
#ifndef MY_STRING_H 
#define MY_STRING_H

#include <iostream>


namespace OwnString {

    /**
     * @brief Iterator class.
     * 
     * @tparam T Type of data.
     */
    template<typename T>
    class It {
    private:
        T* _data;   ///< Iterator data pointer

    public:
        /**
         * @brief Constructs an iterator with a specific data pointer.
         * 
         * @param data Data to point to.
         */
        It(T* data) { this->_data = data; }

        T& operator*() { return *_data; }

        It<T>& operator++() {
            _data++;
            return *this;
        }

        It<T>& operator--() {
            _data--;
            return *this;
        }

        bool operator==(const It<T>& a) { return _data == a._data; }

        bool operator!=(const It<T>& a) { return _data != a._data; }

    };	/* class It */

    /**
     * @brief String implementation.
     */
    class String {
    private:
        char* str_data;     ///< Pointer to string data
        size_t str_size;    ///< String size

    public:
        /**
         * @brief Default constructor. Creates an empty string with size 0.
         */
        String();

        /**
         * @brief Constructs a string from a C-style char array.
         * 
         * @param src_data C-style char array.
         */
        String(const char* src_data);

        /**
         * @brief Copy constructor.
         * 
         * @param _str String to be copied from.
         */
        String(const String& _str);

        /**
         * @brief Destructor.
         */
        ~String();

        /**
         * @brief Adds a character into the string at the specified position.
         * 
         * @param _el Character to be inserted.
         * @param _index Position to insert the character.
         */
        void add_char(const char _el, const size_t _index);

        /**
         * @brief Deletes the element at the specified index.
         * 
         * @param _index Index of the element to be deleted.
         */
        void delete_element(const size_t _index);

        /**
         * @brief Deletes a range of elements in the string.
         * 
         * @param _pos Index to start erasing.
         * @param _len Number of elements to erase.
         */
        void erase(size_t _pos, size_t _len);

        /**
         * @brief Deletes a range of elements specified by iterators.
         * 
         * @param _first Iterator pointing to the first element to erase.
         * @param _last Iterator pointing to the last element to erase.
         */
        void erase(It<char> _first, It<char> _last);

        /**
         * @brief Converts all characters in the string to uppercase.
         */
        void to_upper();

        /**
         * @brief Converts all characters in the string to lowercase.
         */
        void to_lower();

        /**
         * @brief Reverses the entire string.
         */
        void reverse();

        /**
         * @brief Overloaded operator to access a character at the specified position.
         * 
         * @param _pos Position in the string.
         * @return The character at the specified position.
         */
        char operator[](const size_t _pos) const;

        /**
         * @brief Overloaded stream insertion operator to print the string.
         * 
         * @param iostream The output stream.
         * @param _str The string to be printed.
         * @return The modified output stream.
         */
        friend std::ostream& operator<<(std::ostream& iostream, const String& _str);

        /**
         * @brief Concatenates two strings.
         * 
         * @param string1 The first string.
         * @param string2 The second string.
         * @return The concatenated string.
         */
        friend String operator+(const String& string1, const String& string2);

        /**
         * @brief Generates an iterator to the first element of the string.
         * 
         * @return An iterator pointing to the first element.
         */
        It<char> begin() {
            It<char> it(str_data);
            return it;
        }

        /**
         * @brief Generates an iterator to the last element of the string.
         * 
         * @return An iterator pointing to the last element.
         */
        It<char> end() {
            It<char> it(str_data + str_size);
            return it;
        }

    private:
        /**
         * @brief Sets the size of the string.
         * 
         * @param new_size The new size of the string.
         */
        void set_length(const size_t new_size);

        /**
         * @brief Copies data from one string to another.
         * 
         * @param _txt The string to be copied from.
         */
        void set_data(const String& _txt);

        /**
         * @brief Gets the character at the specified position.
         * 
         * @param _pos The position in the string.
         * @return The character at the specified position, or 0 if the position is greater than the string size.
         */
        char get(size_t _pos) const;

        /**
         * @brief Concatenates a string to the current string.
         * 
         * @param _txt The string to be added.
         */
        void add(const String& _txt);

    };	/* class String */

}	/* namespace OwnString */

#endif // MY_STRING_H