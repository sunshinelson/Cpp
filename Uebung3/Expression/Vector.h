#pragma once

#include <array>
using namespace std;

template < class T, size_t S > 
class Vector : public array<T, S>{

public:
	//Konstruktor mit Initialisierungslisten
	Vector(const initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	}

	//Standardconstruktor
	Vector() {}

	//Indexoperator 
	T operator[](int i) const {
		return this->at(i);
	}

	// Ausgabe-Operator für Output-Streams	
	friend ostream& operator<<(ostream& os, const Vector& v) {
		os << "v[";
		for (size_t i = 0; i < S; ++i) { os << "  " << v[i]; }
		os << "  ]";
		return os;
	}
	
	// Zuweisungsoperator
	template<typename T>
	Vector& operator = (const T& t) {
		for (size_t i = 0; i < S; ++i) this->at(i) = t[i];
		return *this;
	}

	//Gleichheitsoperator
	template<typename T>
	bool operator==(const T& t) const {
		if (S == t.size()) {
			for (size_t i = 0; i < S; i++){
				if (this->at(i) != t[i]) {
					return false;
				}
			}
		}else {
			return false;
		}
		return true;
	}

};