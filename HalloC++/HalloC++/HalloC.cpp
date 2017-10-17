// "HalloC.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <iomanip>  // ::std::setw, ::std::setfill 
#include <ios>      // ::std::left, ::std::right

#define TypeSize(type) setw(12) << left << #type << sizeof(type) << (sizeof(type) == 1 ? " Byte" : " Bytes")





void typesizes() {
	cout << TypeSize(bool) << endl;
	cout << TypeSize(char) << endl;
	cout << TypeSize(short) << endl;
	cout << TypeSize(int) << endl;
	cout << TypeSize(long) << endl;
	cout << TypeSize(long long) << endl;
	cout << TypeSize(float) << endl;
	cout << TypeSize(double) << endl;
	cout << TypeSize(long double) << endl;
}

int main()
{
	cout << "Hello, World!" << endl;
	//int x = 5, y = 10;
	//int z = MAX(++x, ++y);
	//std::cout << "z: " << z << std::endl;
	//std::cout << "x: " << x << std::endl;
	//std::cout << "y: " << y << std::endl;
	//	std::cout << "char: " << sizeof(char) << " Byte" << std::endl;
	//	std::cout << "short: " << sizeof(short) << " Byte" << std::endl;

	typesizes();

	//d)
	char s[] = "Hello World";
	int uppercase = 0;

	//int len = sizeof(s);
	//for (int i = 0; i < len; ++i) {
	//	if (isupper(s[i])) ++uppercase;
	//}
	for (char c : s) {
		if (isupper(c)) ++uppercase;
	}
	cout << uppercase << " uppercase letters in: " << s << endl;
	return 0;
}
