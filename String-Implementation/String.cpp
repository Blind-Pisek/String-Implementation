#include "string.h"
#include <cstring>

namespace kp 
{ 

String::String() : str_data(nullptr), str_size(0) {}

String::String( const char* src_data ) 
{
	set_length( strlen(src_data) );
	for( int it = 0 ; it < str_size ; it++ )
	{
		str_data[it] = src_data[it];
	}
}

String::String(const String& _str) {
	set_length(_str.str_size);
	for (int i = 0; i < str_size; i++) {
		str_data[i] = _str.str_data[i];
	}
}
String::~String() {
	if (str_data != NULL)
		delete[] str_data;
}

void String::set_length( const size_t new_size ) 
{
	str_size = new_size;
	str_data = new char[new_size+1]();
}

void String::set_data( const String& _txt )
{
	// method doesn't check if size is grater!
	for ( size_t it = 0; _txt.str_data[it] != '\0'; it++ ) 
	{
		str_data[it] = _txt.str_data[it];
	}
}

char String::get( size_t _pos ) const 
{
	if (_pos > str_size) {
		return 0;
	}
	return str_data[_pos];
}

void String::add( const String& _txt ) 
{
	size_t old_str_size = str_size;
	char* old_str_data = str_data;
	set_length( str_size + _txt.str_size );
	set_data( old_str_data );

	for ( size_t it = old_str_size; it < str_size; it++ ) 
	{
		str_data[it] = _txt.str_data[it - old_str_size];
	}

	if( old_str_data != NULL )
		delete[] old_str_data;
}


// indeksowanie od 0
void String::add_char(const char _el, const size_t _index) {
	if (_index < 0 || _index > str_size)
	{
		std::cout << "Index error!!!" << std::endl;
		return;
	}
	size_t old_str_size = str_size;
	char* old_str_data = str_data;
	set_length(str_size + 1);
	
	for (size_t it = 0; it != _index; it++) {
		this->str_data[it] = old_str_data[it];
	}
	this->str_data[_index] = _el;
	for (size_t it = _index + 1; it != this->str_size; it++) {
		this->str_data[it] = old_str_data[it-1];
	}
}
// indeksowanie od 0
void String::delete_element(const size_t _index) {
	if (_index < 0 || _index > str_size) {
		std::cout << "Index error!!!" << std::endl;
		return;
	}

	for (size_t it = _index; it < str_size-1; it++) {
		str_data[it] = str_data[it + 1];
	}
	str_size--;
	str_data[str_size] = '\0';
}
// indeksowanie od 0
void String::erase(size_t _pos, size_t _len) {
	if (_pos<0 || _pos>str_size || _len<0 || _len>str_size || _pos+_len>str_size) {
		std::cout << "Index error!!!" << std::endl;
		return;
	}
	for (size_t it = _pos; it < _len + _pos; it++) {
		this->delete_element(_pos);
	}
}

void String::erase(It<char> _first, It<char> _last) {
	size_t _f=0, _l=0;
	for (size_t it = 0; str_data[it] != *_first; it++)
		_f++;
	for (size_t it = _f; str_data[it] != *_last; it++)
		_l++;
	if (_f > _l) {
		std::cout << "Index error!!!" << std::endl;
		return;
	}
	this->erase(_f, _l - _f);
}

void String::to_upper() {
	char* _el = this->str_data;
	while (*_el != '\0')
	{
		if (int(*_el) >= 97 && int(*_el) <= 122)
			*_el = char(*_el - 32);
		_el++;
	}
}

void String::to_lower() {
	char* _el = this->str_data;
	while (*_el != '\0')
	{
		if (int(*_el) >= 65 && int(*_el) <= 90) 
			*_el = char(*_el + 32);
		_el++;
	}
}

void String::reverse() {
	if (str_data == 0) {
		return;
	}
	char _helper;
	for (size_t it = 0, it2 = str_size - 1; it < it2; it++, it2--) {
		_helper = str_data[it];
		str_data[it] = str_data[it2];
		str_data[it2] = _helper;
	}
}


char String::operator[](const size_t _pos) {
	return this->get(_pos);
}

std::ostream& operator<<(std::ostream& ostream, const kp::String& _str) {
	return (ostream << _str.str_data);
}

String operator+(const String& _str1, const String& _str2) {
	String _string = String(_str1);
	_string.add(_str2);
	return _string;
}

}