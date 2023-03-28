#ifndef STRING_H
#define STRING_H


class String {
private:
	char* str;
public:
	String();
	String(const char* str_param);
	String(String const& other);
	String& operator=(const char* other);
	String& operator=(String const& other);
	~String();
	String(String && other);
	String& operator=(String && other);
	char operator[](int index);

	int length();
	bool empty();
	const char* c_str();

	String operator+(const char* other);
	String operator+(String const& other);
	friend String operator+(const char* s1, String const& s2);
	String operator+=(const char* other);
	String operator+=(String const& other);
	bool operator==(const char* other);
	bool operator==(String const& other);
	friend bool operator==(const char* s1, String const& s2);
	bool operator!=(const char* other);
	bool operator!=(String const& other);
	friend bool operator!=(const char* s1, String const& s2);
	bool operator>=(const char* other);
	bool operator>=(String const& other);
	friend bool operator>=(const char* s1, String const& s2);
	bool operator<=(const char* other);
	bool operator<=(String const& other);
	friend bool operator<=(const char* s1, String const& s2);
	bool operator<(const char* other);
	bool operator<(String const& other);
	friend bool operator<(const char* s1, String const& s2);
	bool operator>(const char* other);
	bool operator>(String const& other);
	friend bool operator>(const char* s1, String const& s2);
};


#endif
