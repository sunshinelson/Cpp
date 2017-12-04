#include "stdafx.h"
#include "OrderedSet.h"
#include <algorithm>

//Sortierung des Arrays
void OrderedSet::sort()
{
	int* start = begin();
	std::sort(start, start + m_size);
}

//Override begin aus Set
int* OrderedSet::begin() const
{
	int* begin = m_values.get();
	return &begin[m_start];
}

//Overide containsAll aus Set
bool OrderedSet::containsAll(const OrderedSet & oset) const
{
	if (oset.size() <= size()) {
		//size_t amtEqual = 0;
		for (size_t i = oset.m_start; i < oset.size(); i++)
		{
			if (!contains(oset[i])) {

				return false;
			}

		}
		return true;
	}
	else {
		return false;
	}
}

//Overide merge aus Set
Set OrderedSet::merge(const Set& set) const
{
	const OrderedSet* oset = dynamic_cast<const OrderedSet*>(&set);
	if (oset != nullptr) {
		OrderedSet result(size() + oset->size());
		int* p1 = begin();
		int* p2 = oset->begin();
		size_t i = 0;
		size_t j = 0;

		while (i < size() && j < oset->size()) {
			const int& val1 = begin()[i];
			const int& val2 = oset->begin()[j];
			int val;
			if (val1 <= val2) {
				i++;
				val = val1;
			}
			if (val1 >= val2) {
				j++;
				val = val2;
			}
			result[result.m_size++] = val;
		}

		if (i < size()) {
			for (; i < size(); ++i) {
				result[result.m_size++] = begin()[i];
			}
		}
		else if (j < oset->size()) {
			for (; j < oset->size(); ++j) {
				result[result.m_size++] = oset->begin()[j];
			}
		}
		return result;
	}
	else {
		return __super::merge(set);
	}
}

OrderedSet OrderedSet::getSmaller(int x) const
{
	OrderedSet set(*this);
	size_t s = 0;
	for (size_t i = set.m_start; i < set.m_size; i++) {
		if (set[i] >= x) {
			break;
		}
		s++;
	}
	set.m_size = s;
	return set;
}

OrderedSet OrderedSet::getLarger(int x) const
{
	OrderedSet set(*this);
	size_t s = 0;
	for (size_t i = set.m_start; i < set.m_size; ++i) {
		if (set[i] > x) {
			break;
		}
		s++;
	}

	set.m_size -= s;
	set.m_start = s;
	return set;
}