#include "test.h"

int main()
{
	MyString str1("Park ");
	str1.reserve(10);
	//std::cout << str1.get_capacity() << std::endl;
	MyString str2("Ji Yong");

	str1.insert(5, str2);
	str1.println();
	str1.erase(0, 100);
	str1.println();


}