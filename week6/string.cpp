#include "string.h"
#include <cstring>
#include <cassert>

String::String()
{
	str = new char[1];
	*str = '\0';
}

String::String(const char* str_param)
{
	int len = strlen(str_param);
	str = new char[len + 1];
	strncpy(str, str_param, len);
}

String::String(String const& other)
{
	int len = strlen(other.str);
	str = new char[len + 1];
	strncpy(str, other.str, len);
}

String& String::operator=(const char* other)
{
	delete[] str;
	int len = strlen(other);
	str = new char[len + 1];
	strncpy(str, other, len);
	return *this;
}

String& String::operator=(String const& other)
{
	if (*this != other) { //bez da iskam sravnih stoinostite vmesto adresite
		delete[] str;
		int len = strlen(other.str);
		str = new char[len + 1];
		strncpy(str, other.str, len);
	}
	return *this;
}

String::~String()
{
	delete[] str;
}

String::String(String&& other)  // move 
{
	str = other.str;
	other.str = nullptr;
}

String& String::operator=(String&& other) // move
{
	str = other.str;
	other.str = nullptr;
	return *this;
}

char String::operator[](int index)
{
	assert(index < length());
	return *(str + index);
}

int String::length()
{	
	int len = 0;
	while (str[len]) {
		len++;
	}
	return len;
}

bool String::empty()
{
	return !(*str);
}

const char* String::c_str()
{
	return nullptr;  //not finished
}

String String::operator+(const char* other)
{	
	int len1 = strlen(str);
	int len2 = strlen(other);
	int len = len1 + len2;
	char* new_str = new char[len + 1];
	strncat(new_str, str, len1);
	strncat(new_str, other, len2);
	strncat(new_str, "\0", 1);
	String s1 = new_str;
	delete[] new_str;
	return s1;
}

String String::operator+(String const& other)
{
	int len1 = strlen(str);
	int len2 = strlen(other.str);
	int len = len1 + len2;
	char* new_str = new char[len + 1];
	strncat(new_str, str, len1);
	strncat(new_str, other.str, len2);
	strncat(new_str, "\0", 1);
	String s1 = new_str;
	delete[] new_str;
	return s1;
}

String operator+(const char* s1, String const& s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2.str);
	int len = len1 + len2;
	char* new_str = new char[len + 1];
	strncat(new_str, s1, len1);
	strncat(new_str, s2.str, len2);
	strncat(new_str, "\0", 1);
	String s = new_str;
	delete[] new_str;
	return s;
}

String String::operator+=(const char* other)
{
	int len1 = strlen(str);
	int len2 = strlen(other);
	int len = len1 + len2;
	char* new_str = new char[len + 1];
	strncat(new_str, str, len1);
	strncat(new_str, other, len2);
	strncat(new_str, "\0", 1);
	*this = new_str;
	delete[] new_str;
	return *this;
}

String String::operator+=(String const& other)
{
	int len1 = strlen(str);
	int len2 = strlen(other.str);
	int len = len1 + len2;
	char* new_str = new char[len + 1];
	strncat(new_str, str, len1);
	strncat(new_str, other.str, len2);
	strncat(new_str, "\0", 1);
	*this = new_str;
	delete[] new_str;
	return *this;
}

bool String::operator==(const char* other)
{
	int i = 0;
	while (other[i] && str[i]) {
		if (other[i] != str[i]) return false;
		i++;
	}
	return other[i] == str[i];
}

bool String::operator==(String const& other)
{
	int i = 0;
	while (other.str[i] && str[i]) {
		if (other.str[i] != str[i]) return false;
		i++;
	}
	return other.str[i] == str[i];
}

bool operator==(const char* s1, String const& s2)
{
	int i = 0;
	while (s2.str[i] && s1[i]) {
		if (s2.str[i] != s1[i]) return false;
		i++;
	}
	return s2.str[i] == s1[i];
}

bool String::operator!=(const char* other)
{
	int i = 0;
	while (other[i] && str[i]) {
		if (other[i] == str[i]) return false;
		i++;
	}
	return other[i] != str[i];
}

bool String::operator!=(String const& other)
{
	int i = 0;
	while (other.str[i] && str[i]) {
		if (other.str[i] == str[i]) return false;
		i++;
	}
	return other.str[i] != str[i];
}

bool operator!=(const char* s1, String const& s2)
{
	int i = 0;
	while (s2.str[i] && s1[i]) {
		if (s2.str[i] == s1[i]) return false;
		i++;
	}
	return s2.str[i] != s1[i];
}

bool String::operator>=(const char* other)
{
	int i = 0;
	while (other[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] >= other[i];
}

bool String::operator>=(String const& other)
{
	int i = 0;
	while (other.str[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] >= other.str[i];
}

bool operator>=(const char* s1, String const& s2)
{
	int i = 0;
	while (s2.str[i] == s1[i] && s1[i]) {
		i++;
	}
	return s1[i] >= s2.str[i];
}

bool String::operator<=(const char* other)
{
	int i = 0;
	while (other[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] <= other[i];
}

bool String::operator<=(String const& other)
{
	int i = 0;
	while (other.str[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] <= other.str[i];
}

bool operator<=(const char* s1, String const& s2)
{
	int i = 0;
	while (s2.str[i] == s1[i] && s1[i]) {
		i++;
	}
	return s1[i] <= s2.str[i];
}

bool String::operator<(const char* other)
{
	int i = 0;
	while (other[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] < other[i];
}

bool String::operator<(String const& other)
{
	int i = 0;
	while (other.str[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] < other.str[i];
}

bool operator<(const char* s1, String const& s2)
{
	int i = 0;
	while (s2.str[i] == s1[i] && s1[i]) {
		i++;
	}
	return s1[i] < s2.str[i];
}

bool String::operator>(const char* other)
{
	int i = 0;
	while (other[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] > other[i];
}

bool String::operator>(String const& other)
{
	int i = 0;
	while (other.str[i] == str[i] && str[i]) {
		i++;
	}
	return str[i] >= other.str[i];
}

bool operator>(const char* s1, String const& s2)
{
	int i = 0;
	while (s2.str[i] == s1[i] && s1[i]) {
		i++;
	}
	return s1[i] > s2.str[i];
}


