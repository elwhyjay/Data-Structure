#include <string>
#include <iomanip>
#include <vector>
#include <iostream>
#include<sstream>
// binary to string
template <typename iter>
std::string bytes2hexstr(iter begin, iter end, bool const is_uppercase = false) {
	std::ostringstream oss;
	if (is_uppercase) oss.setf(std::ios_base::uppercase);
	for (; begin != end; ++begin) {
		oss << std::hex <<
			std::setw(2) <<
			std::setfill('0') << 
			static_cast<int>(*begin);
	}
	return oss.str();
}

template <typename T>
std::string bytes2hexstr(T const& c, bool const is_uppercase = false) {
	return bytes2hexstr(std::cbegin(c), std::cend(c), is_uppercase);
}

// string to binary data
unsigned char hexchar2int(char const ch) {
	if ('0' <= ch && ch <= '9') return ch - '0';
	else if ('a' <= ch && ch <= 'f') return ch - 'a' + 10;
	else if ('A' <= ch && ch <= 'F') return ch - 'A' + 10;
	else throw std::invalid_argument("invalid hexadecimal character");
}

std::vector<unsigned char> hexstr2bytes(std::string &str) {
	std::vector<unsigned char> result;
	for (size_t i = 0; i < str.size(); i += 2) {
		result.push_back(
			(hexchar2int(str[i]) << 4) | hexchar2int(str[i + 1])
		);
	}
	return result;
}

