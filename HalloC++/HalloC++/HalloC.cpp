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

double spur(double *a, int size) {
	cout << "size: " << size << endl;
	int n = sqrt(size);
	cout << "n: " << n << endl;
	double sum = 0;
	for (int i = 0; i < size; i+=n+1) {
		sum += *(a + i);
		
		cout << "sum" << i <<": " << sum << endl;
	}
	return sum;
}

void create(int n, double a) {
	double *p = &a;
}

int *fillArr(int arr[], int d1) {
	for (int i = 0; i<d1; ++i) {
		arr[i] = 42;
	}
	return arr;
}

int main()
{
	//cout << "Hello, World!" << endl;
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
	// Arrayuebung
	//int y[10] = { 0, 1, 2, 3, 4 ,5 , 6, 7, 8, 9 };
	//int size = sizeof y / sizeof(int);
	//cout << "size: " << size << endl;
	//int *a = fillArr(y, size);
	//for (int i = 0; i<size; ++i) {
	//	cout << a[i] << endl;
	//}
	
	// Prüfungsbeispiel
	//cout << "Pruefungsbeispiel" << endl;
	//double test[9] = { 1, 2, 3, 1, 2, 3, 1, 2, 3};
	//int size2 = sizeof test / sizeof(double);
	//cout << "size2: " << size2 << endl;
	//spur(test, size2);

	//Fehlersuche
	float f = 17.4f; //kein Problem
	float *const fp = &f;
	--(*fp);
	//fp = new float; //float *const fp muss eine lvalue sein
	//float& fr = new float; // ein Wert vom Typ float* kann nicht zum initilisieren einer entität vom typ float&s verwendet werden
	//float g = *(fp++); //fp ist ja cont, sollte aber veränderbar sein
	//Fraction br(new Fraction(3, 4));

	return 0;
}
