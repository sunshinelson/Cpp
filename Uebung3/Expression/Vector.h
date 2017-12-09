#pragma once

#include <array>
using namespace std;

template< class T, size_t S> class Vector : public array<T, S>{
private:

public:
	
	Vector(const std::initializer_list<T>& data) {
		size_t s = __min(data.size(), S);
		auto it = data.begin();
		for (size_t i = 0; i < s; i++) this->at(i) = *it++;
	}
};