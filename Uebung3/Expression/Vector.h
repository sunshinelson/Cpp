#pragma once

#include <array>
using namespace std;

template <class T, size_t S> class Vector : public array<T, S>{
private:

public:
	//Standardconstruktor
	Vector(
		size_t s = 0;
	);
	//Konstruktor mit Initialisierungslisten
	Vector(const std::initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	};

	// Ausgabe-Operator für Output-Streams
	friend ostream& operator<<(ostream& os, const Vector& v) {
		auto vptr = v.begin();
		os << "[";
		if (!v.isEmpty()) os << vptr[0];
		for (size_t i = 1; i < S; ++i) { os << ", " << vptr[i]; }
		os << "]";
		return os;
	};

	~Vector();
};