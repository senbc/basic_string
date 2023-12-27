#include "string_basic.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const string_basic& string) {
	out << string.get_string();

	return out;
}

std::istream& operator>>(std::istream& in, string_basic& string) {
	in.getline(string.m_string, sizeof(string.m_string));
	return in;
}