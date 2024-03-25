#include "test.h"

MyString::MyString(char c) {
	str_content = new char[1];
	capacity = 1;
	str_len = 1;
	str_content[0] = c;
}

MyString::MyString(const char* str) {
	str_len = (int)strlen(str);
	str_content = new char[str_len];
	capacity = str_len;
	for (int i = 0; i < str_len; i++) {
		str_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str) {
	str_len = str.length();
	str_content = new char[str_len];
	capacity = str_len;
	for (int i = 0; i < str_len; i++) {
		str_content[i] = str.str_content[i];
	}
}

MyString::~MyString() {
	if (str_content) { delete[] str_content; }
}

int MyString::length() const {
	return str_len;
}

void MyString::print() const {
	for (int i = 0; i < str_len; i++)
		std::cout << str_content[i];
}

void MyString::println() const {
	for (int i = 0; i < str_len; i++)
		std::cout << str_content[i];
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
	int new_length = str.length();
	if (capacity < new_length) {
		delete[] str_content;
		str_content = new char[new_length];
		capacity = new_length;
	}
	for (int i = 0; i < new_length; i++) {
		str_content[i] = str.str_content[i];
	}
	str_len = new_length;
	return *this;
}

MyString& MyString::assign(const char* str) {
	int new_length = (int)strlen(str);
	if (capacity < new_length) {
		delete[] str_content;
		str_content = new char[new_length];
		capacity = new_length;
	}
	for (int i = 0; i < new_length; i++) {
		str_content[i] = str[i];
	}
	str_len = new_length;
	return *this;
}

int MyString::get_capacity() const {
	return capacity;
}

void MyString::reserve(int size) {
	if (capacity < size) {
		char* cp_str = str_content;

		str_content = new char[size];
		capacity = size;
		for (int i = 0; i < str_len; i++) {
			str_content[i] = cp_str[i];
		}

		delete[] cp_str;
	}
}

char MyString::at(int x) const {
	if (x >= str_len || x < 0) return NULL;

	return str_content[x];
}

MyString& MyString::insert(int loc, const MyString& str) {
	if (loc < 0 || loc > str_len) return *this;

	int total_len = str.length() + str_len;
	if (capacity < total_len) {
		char* cp_str = str_content;
		str_content = new char[total_len];
		capacity = total_len;

		int i = 0;
		for (i; i < loc; i++) {
			str_content[i] = cp_str[i];
		}
		for (int j = 0; j < str.length(); j++) {
			str_content[i + j] = str.str_content[j];
		}
		for (; i < str_len; i++) {
			str_content[str.str_len + i] = cp_str[i];
		}
		str_len = total_len;
		delete[] cp_str;
		return *this;
	}

	for (int i = str_len - 1; loc <= i; i--) {
		str_content[i + str.str_len] = str_content[i];
	}
	for (int i = 0; i < str.str_len; i++)
		str_content[i + loc] = str.str_content[i];

	str_len = total_len;
	return *this;
}

MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) { //abcd erase(1,2) = ad
	if (loc < 0 || loc >= str_len || num < 0) return *this;

	for (int i = loc + num; i < str_len; i++) {
		str_content[i - num] = str_content[i];
	}
	str_len -= num;
}