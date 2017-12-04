#include "MySet.h"
#include <string>

Set::Set(size_t size)
    : m_values(new int[size], default_delete<int[]>()),
    m_size(0)
{
}

Set::Set()
    : m_size(0)
{
}

Set::Set(const Set& set)
    : m_values(set.m_values),
    m_size(set.m_size)
{
}

Set::Set(const int* values, size_t size)
    : Set(size)
{
    for (size_t i = 0; i < size; ++i) {
        insert(values[i]);
    }
}

Set::~Set()
{
}

int* Set::begin() const
{
    return m_values.get();
}

bool Set::insert(const int value)
{
    if (contains(value)) {
        return false;
    }

    begin()[m_size++] = value;

    return true;
}

int& Set::operator[](const size_t i)
{
    return begin()[i];
}

const int& Set::operator[](const size_t i) const
{
    return begin()[i];
}

Set Set::merge(const Set& set) const
{
    // erstelle eine neue Menge mit allen Elementen von this 
    Set result(size() + set.size());
    std::memcpy(result.begin(), begin(), size() * sizeof(int));
    result.m_size = size();

    // fuege nur jene Elemente von set dazu, die in this noch nicht enthalten sind 
    for (size_t i = 0; i < set.size(); ++i) {
        result.insert(set[i]);
    }

    return result;
}

Set Set::difference(const Set& set) const
{
    Set result(size() + set.size());

    for (size_t i = 0; i < set.size(); ++i) {
        const int& value = set[i];

        if (!contains(value)) {
            result.insert(value);
        }
    }

    return result;
}

Set Set::difference(Set&& set) const
{
    if (set.m_values.unique()) {
        size_t count = 0;

        for (size_t i = 0; i < set.size(); ++i) {
            const int& value = set[i];

            if (!contains(value)) {
                set.begin()[count++] = value;
            }
        }

        set.m_size = count;

        return set;
    } else {
        return difference(set);
    }
}

Set Set::intersection(const Set& set) const
{
    Set result(size() + set.size());

    for (size_t i = 0; i < set.size(); ++i) {
        const int& value = set[i];

        if (contains(value)) {
            result.insert(value);
        }
    }

    return result;
}

Set Set::intersection(Set&& set) const
{
    if (set.m_values.unique()) {
        size_t count = 0;

        for (size_t i = 0; i < set.size(); ++i) {
            const int& value = set[i];

            if (contains(value)) {
                set.begin()[count++] = value;
            }
        }

        set.m_size = count;

        return set;
    } else {
        return intersection(set);
    }
}

bool Set::contains(const int value) const
{
    bool exist = false;

    for (size_t i = 0; i < size(); ++i) {
        if (begin()[i] == value) {
            exist = true;
            break;
        }
    }

    return exist;
}

bool Set::containsAll(const Set& set) const
{
    bool exist = true;

    for (size_t i = 0; i < set.size(); ++i) {
        if (!contains(set[i])) {
            exist = false;
            break;
        }
    }

    return exist;
}

bool Set::isEmpty() const
{
    return size() == 0;
}

size_t Set::size() const
{
    return m_size;
}

bool Set::operator==(const Set& set) const
{
    return containsAll(set) && set.containsAll(*this);
}

ostream& operator<<(ostream& os, const Set& s)
{
    const int* const vptr = s.begin();
    os << "{";
    if (!s.isEmpty()) os << vptr[0];
    for (size_t i = 1; i < s.m_size; ++i) { os << ", " << vptr[i]; }
    os << "}";
    return os;
}

Set Set::merge(const Set& set1, const Set& set2)
{
    return set1.merge(set2);
}

Set Set::difference(const Set& set1, const Set& set2)
{
    return set2.difference(set1);
}

Set Set::difference(Set&& set1, const Set& set2)
{
    return set2.difference(move(set1));
}

Set Set::difference(Set&& set1, Set&& set2)
{
    return set2.difference(move(set1));
}

Set Set::intersection(const Set& set1, const Set& set2)
{
    return set1.intersection(set2);
}
Set Set::intersection(const Set& set1, Set&& set2)
{
    return set1.intersection(move(set2));
}

Set Set::intersection(Set&& set1, const Set& set2)
{
    return set2.intersection(move(set1));
}

Set Set::intersection(Set&& set1, Set&& set2)
{
    return set1.intersection(move(set2));
}