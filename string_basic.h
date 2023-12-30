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

	friend string_basic operator+ (const string_basic& string1, const string_basic& string2);

	string_basic& operator= (const string_basic& string);

	friend std::ostream& operator<<(std::ostream& out, const string_basic& string);
	friend std::istream& operator>>(std::istream& in, string_basic& string);

	const char* get_string() const {
		return m_string;
	}

	void reverse() {
		strrev(m_string);
	}

	void upperCase() {
		for (size_t i = 0; i < sizeof(m_string) && m_string[i] != '\0'; ++i) {
			m_string[i] = std::toupper(static_cast<unsigned char>(m_string[i]));
		}
	}

	void lowerCase() {
		for (size_t i = 0; i < sizeof(m_string) && m_string[i] != '\0'; ++i) {
			m_string[i] = std::tolower(static_cast<unsigned char>(m_string[i]));
		}
	}
};

// overloads

string_basic operator+ (const string_basic & string1, const string_basic& string2) {
	char result[STRING_BUFFER] = " ";

	strncpy(result, string1.m_string, sizeof(string1.m_string) - 1);
	result[sizeof(result) - 1] = '\0';

	strcat(result, string2.m_string);

	return result;
}

string_basic& string_basic::operator= (const string_basic& string) {
	if (this != &string) {
		strncpy(m_string, string.m_string, sizeof(m_string) - 1);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& out, const string_basic& string) {
	out << string.get_string();

	return out;
}

std::istream& operator>>(std::istream& in, string_basic& string) {
	in.getline(string.m_string, sizeof(string.m_string));
	return in;
}
