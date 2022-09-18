#ifndef MY_STRING_H 
#define MY_STRING_H

/* File Name         : string.h
* Author             : Karol Pisarski
* Email				 : pisek.x@gmail.com
* Version            : v1.2
* Date               : 17/09/2022
* Desciption         : This file contains the functions for the string library			   
********************************************************************************/

/* includes */
#include <iostream>


namespace kp 
{

template<typename T>
class It 
{
	private:
		T* _data;	

	public:
		It(T* data) {
			this->_data = data;
		}

		T& operator*() {
			return *_data;
		}

		It<T>& operator++() {
			_data++;
			return *this;
		}

		It<T>& operator--() {
			_data--;
			return *this;
		}

		bool operator==(const It<T>& a) {
			return _data == a._data;
		}

		bool operator!=(const It<T>& a) {
			return _data != a._data;
		}

	};

/// @brief 
class String 
{
	public:
		/* Public attributes */

	private:
		/* Private attributes */
		char* str_data;		// pointer to string data
		size_t str_size;	// string size

	public:
		/* Public methods */
		/// @brief Creates empty String with size 0 without data
		String();

		// /// @brief 
		// /// @param s_size 
		// String(const size_t s_size);		// TODO

		/// @brief Constructs string with C char array
		/// @param src_data C char array
		String(const char* src_data);	

		/// @brief Copy constructor
		/// @param _str string to be copied from
		String(const String& _str);

		~String();

		/// @brief Adds char into string on specified position
		/// @param _el char to be inserted
		/// @param _index position to be inserted
		void add_char(const char _el, const size_t _index);

		/// @brief Delets chosen element
		/// @param _index number of element to be deleted
		void delete_element(const size_t _index);

		/// @brief 
		/// @param _pos 
		/// @param _len 
		void erase(size_t _pos, size_t _len);

		/// @brief 
		/// @param _first 
		/// @param _last 
		void erase(It<char> _first, It<char> _last);
	
		void to_upper();
		void to_lower();
		void reverse();

		char operator[](const size_t _pos);
		friend std::ostream& operator<<(std::ostream& iostream, const kp::String& _str);
		friend String operator+(const String& string1, const String& string2);

		//iterator
		It<char> begin() {
			It<char> it(str_data);
			return it;
		}

		It<char> end() {
			It<char> it(str_data + str_size);
			return it;
		}
		


	private:
		/* Private methods */
		/// @brief Sets string size
		//	Warning! Method erases data inside object
		/// @param new_size Size of new string
		void set_length( const size_t new_size );

		/// @brief Copies data from one string to another
		/// @param _txt String to be copied from
		void set_data( const String& _txt );

		/// @brief Gets char from provided position
		/// @param _pos Position to String
		/// @return Char or 0 if position is grater than String size		
		char get( size_t _pos ) const;

		/// @brief String concatenate
		/// @param _txt String to be added
		void add( const String& _txt );

}; /* Class String */
} /* namespace kp */


#endif /* MY_STRING_H */