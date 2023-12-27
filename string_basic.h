#pragma once
#pragma warning(disable : 4996) // disables warning for strncpy on MSVC
#include <cstring>
#include <iostream>

constexpr int STRING_BUFFER{ 256 };

class string_basic {
private:
	char m_string[STRING_BUFFER] = {" "};
public:
	string_basic() {}

	string_basic(const char* str) {
		std::strncpy(m_string, str, sizeof(m_string) - 1);
		m_string[sizeof(m_string) - 1] = '\0'; 
	}

	~string_basic() {}

	friend std::ostream& operator<<(std::ostream& out, const string_basic& string);
	friend std::istream& operator>>(std::istream& in, string_basic& string);

	const char* get_string() const {
		return m_string;
	}
};

std::ostream& operator<<(std::ostream& out, const string_basic& string) {
	out << string.get_string();

	return out;
}

std::istream& operator>>(std::istream& in, string_basic& string) {
	in.getline(string.m_string, sizeof(string.m_string));
	return in;
}
