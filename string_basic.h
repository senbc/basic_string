#pragma once
#pragma warning(disable : 4996)

#include <cstring>
#include <iostream>

constexpr int STRING_BUFFER{256};

class string_basic {
private:
	char m_string[256] = {" "};
public:
	string_basic() {}

	string_basic(const char* str) {
		std::strncpy(m_string, str, sizeof(m_string) - 1);
		m_string[sizeof(m_string) - 1] = '\0'; 
	}

	friend std::ostream& operator<<(std::ostream& out, const string_basic& string);
	friend std::istream& operator>>(std::istream& in, string_basic& string);

	const char* get_string() const {
		return m_string;
	}
};
