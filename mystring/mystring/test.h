#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <vld.h>

class MyString {
	char* str_content;
	int str_len;
	int capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
	int length() const;
	void print() const;
	void println() const;
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	int get_capacity()const;
	void reserve(int);
	char at(int) const;
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);
};



