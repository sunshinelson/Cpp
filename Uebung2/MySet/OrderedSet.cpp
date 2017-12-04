#include "OrderedSet.h"
#include <algorithm>

OrderedSet::OrderedSet(size_t size)
    : Set(size),
    m_start(0)
{
}

OrderedSet::OrderedSet()
    : Set(),
    m_start(0)
{
}

OrderedSet::OrderedSet(const Set& set)
    : Set(set),
    m_start(0)
{
    sort();
}

OrderedSet::OrderedSet(const int* values, size_t size)
    : Set(values, size),
    m_start(0)
{
    sort();
}

OrderedSet::~OrderedSet()
{
}

void OrderedSet::sort()
{
    int* beg = begin();

    std::sort(beg, beg + m_size);
}

int* OrderedSet::begin() const
{
    return &__super::begin()[m_start];
}

Set OrderedSet::merge(const Set& set) const
{
    const OrderedSet* pSet = dynamic_cast<const OrderedSet*>(&set);

    if (pSet != nullptr) {
        OrderedSet result(size() + pSet->size());
        int* p1 = begin();
        int* p2 = pSet->begin();
        size_t i = 0, j = 0;

        while(i < size() && j < pSet->size()) {
            const int& val1 = begin()[i];
            const int& val2 = pSet->begin()[j];
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
        } else if (j < pSet->size()) {
            for (; j < pSet->size(); ++j) {
                result[result.m_size++] = pSet->begin()[j];
            }
        }

        return result;
    } else {
        return __super::merge(set);
    }
}

OrderedSet OrderedSet::getSmaller(int x) const
{
    OrderedSet set(*this);
    size_t i = 0;

    for (; i < set.m_size; ++i) {
        if ((*this)[i] >= x) {
            break;
        }
    }

    set.m_size = i;

    return set;
}

OrderedSet OrderedSet::getLarger(int x) const
{
    OrderedSet set(*this);
    size_t i = 0;

    for (; i < set.m_size; ++i) {
        if ((*this)[i] > x) {
            break;
        }
    }

    set.m_start = i;
    set.m_size = set.m_size - i;

    return set;
}