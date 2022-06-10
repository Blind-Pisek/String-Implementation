#pragma once

#include <iostream>


namespace kp {

template<typename T>
class It {
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

class String {
private:
	//dane
	char* str_data;
	//rozmiar
	size_t str_size;

	void set_length(const size_t new_size);
	void set_data(const String& _txt);

	char get(size_t _pos) const;
	void add(const String& _txt);

public:
	// konstruktory
	String();
	String(const size_t s_size);
	String(const char* src_data);
	String(const String& _str);
	~String();


	void add_char(const char _el, const size_t _index);

	void delete_element(const size_t _index);

	void erase(size_t _pos, size_t _len);
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

};
}