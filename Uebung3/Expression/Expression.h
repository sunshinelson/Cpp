#pragma once
#include<iostream>
using namespace std;

struct Add {
	template<typename T> static T apply(T l, T r) {
		return l + r;
	}
};

struct Sub {
	template<typename T> static T apply(T l, T r) {
		return l - r;
	}
};

struct Multiply {
	template<typename T> static T apply(T l, T r) {
		return l * r;
	}
};

struct Div {
	template<typename T> static T apply(T l, T r) {
		return l / r;
	}
};

template <typename Left, typename Op, typename Right>
class Expression {
	const Left& m_left;
	const Right& m_right;

public:
	typedef typename Left::value_type value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}

	size_t size() const { return m_left.size(); }

	// Ausgabe-Operator für Output-Streams	
	friend ostream& operator<<(ostream& os, const Expression& e) {
		size_t s = e.m_left.size();
		os << "e[";
		for (size_t i = 0; i < s; ++i) { os << "  " << e[i]; }
		os << "  ]";
		return os;
	}

	// Indexoperator
	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right[i]);
	}

	//Gleichheitsoperator
	template<typename T>
	bool operator==(const T& t) const {
		for (size_t i = 0; i < m_left.size(); i++){
				if (this->operator[](i) != t[i]) {
					return false;
				}
		}
		return true;
	}

};

template <typename Left, typename Op, typename Right = double>
class Expression {
	const Left& m_left;
	const Right& m_right;

public:
	typedef typename Left::value_type value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}

	size_t size() const { return m_left.size(); }

	// Ausgabe-Operator für Output-Streams	
	friend ostream& operator<<(ostream& os, const Expression& e) {
		size_t s = e.m_left.size();
		os << "e[";
		for (size_t i = 0; i < s; ++i) { os << "  " << e[i]; }
		os << "  ]";
		return os;
	}

	// Indexoperator Spezialisierung 1
	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left[i], m_right);
	}

	//Gleichheitsoperator
	template<typename T>
	bool operator==(const T& t) const {
		for (size_t i = 0; i < m_left.size(); i++) {
			if (this->operator[](i) != t[i]) {
				return false;
			}
		}
		return true;
	}

};

template <typename Left=double, typename Op, typename Right>
class Expression {
	const Left& m_left;
	const Right& m_right;

public:
	typedef typename Right::value_type value_type;

	Expression(const Left& l, const Right& r) : m_left{ l }, m_right{ r } {}

	size_t size() const { return m_right.size(); }

	// Ausgabe-Operator für Output-Streams	
	friend ostream& operator<<(ostream& os, const Expression& e) {
		size_t s = e.m_left.size();
		os << "e[";
		for (size_t i = 0; i < s; ++i) { os << "  " << e[i]; }
		os << "  ]";
		return os;
	}

	// Indexoperator Spezialisierung 2
	value_type operator[](int i) const {
		return Op::apply<value_type>(m_left, m_right[i]);
	}

	//Gleichheitsoperator
	template<typename T>
	bool operator==(const T& t) const {
		for (size_t i = 0; i < m_left.size(); i++) {
			if (this->operator[](i) != t[i]) {
				return false;
			}
		}
		return true;
	}

};

template<typename Left, typename Right>
Expression<Left, Add, Right> operator+(const Left& l, const Right& r) {
	return Expression<Left, Add, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Sub, Right> operator-(const Left& l, const Right& r) {
	return Expression<Left, Sub, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Multiply, Right> operator*(const Left& l, const Right& r) {
	return Expression<Left, Multiply, Right>(l, r);
}

template<typename Left, typename Right>
Expression<Left, Div, Right> operator/(const Left& l, const Right& r) {
	return Expression<Left, Div, Right>(l, r);
}

