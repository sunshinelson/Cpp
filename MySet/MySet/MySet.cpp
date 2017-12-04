#include "stdafx.h"
#include "MySet.h"

int * Set::begin() const
{
	return m_values.get();
}

int & Set::operator[](const size_t i)
{
	int *values = begin();
	return values[i];
}

const int& Set::operator[](const size_t i) const
{
	int *values = begin();
	return values[i];
}

Set Set::merge(const Set& set) const
{
	// erstelle eine neue Menge mit allen Elementen von this
	Set result(m_size + set.m_size);
	std::memcpy(result.begin(), begin(), m_size * sizeof(int));
	result.m_size = m_size;
	// fuege nur jene Elemente von set dazu, die in this noch nicht enthalten sind
	for (size_t i = 0; i < set.m_size; ++i) {
		if (!contains(set[i])) result[result.m_size++] = set[i];
	}
	return result;
}

Set Set::difference(const Set& set) const
{
	// Definiere Groesse
	size_t s = 0;
	if (size() > set.size()) {
		s = size();
	}
	else {
		s = set.size();
	}

	Set result(s);

	for (size_t j = 0; j < set.size(); j++)
	{
		if (!contains(set[j])) {
			result.begin()[result.m_size++] = set[j];
		}
	}
	return result;
}

Set Set::difference(Set&& set) const
{
	if (set.m_values.unique()) {
		size_t s = 0;
		for (size_t i = 0; i < set.size(); ++i) {
			const int& value = set[i];
			if (!contains(value)) {
				set.begin()[s++] = value;
			}
		}
		set.m_size = s;

		return set;
	}
	else {
		return difference(set);
	}
}

Set Set::intersection(const Set & set) const
{
	// Definiere Groesse
	size_t s = 0;
	if (size() > set.size()) {
		s = size();
	}
	else {
		s = set.size();
	}

	Set result(s);

	for (size_t j = 0; j < set.size(); j++)
	{
		if (contains(set[j])) {
			result.begin()[result.m_size++] = set[j];
		}
	}
	return result;
}

Set Set::intersection(Set&& set) const
{
	if (set.m_values.unique()) {
		size_t s = 0;
		for (size_t i = 0; i < set.size(); ++i) {
			const int& value = set[i];
			if (contains(value)) {
				set.begin()[s++] = value;
			}
		}
		set.m_size = s;

		return set;
	}
	else {
		return intersection(set);
	}
}

bool Set::contains(int e) const
{
	if (!isEmpty()) {
		const int const *values = begin();
		for (size_t i = 0; i < size(); i++)
		{
			if (values[i] == e) { 
				return true; 
			}
		}
	}
	return false;
}

bool Set::containsAll(const Set & set) const
{
	//int *values = set.begin();

	if (set.size() <= size()) {
		//size_t amtEqual = 0;
		for (size_t i = 0; i < set.size(); i++)
		{
			if (!contains(set[i])) {
				//amtEqual++;
				return false;
			}
			//else {
			//	return false;
			//}
		}
		//if (amtEqual == set.size()) {
		//		return true;
		//}
		//else {
		//	return false;
		//}
		return true;
	}
	else {
		return false;
	}
}

bool Set::isEmpty() const
{
	if (size() <= 0) {
		return true;
	}
	else {
		return false;
	}
}

size_t Set::size() const
{
	return m_size;
}

