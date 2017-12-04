#pragma once

#include "MySet.h"

class OrderedSet : public Set {
protected:
    size_t m_start;

protected:
    OrderedSet(size_t size);

    void sort();

    int* begin() const override;
    Set merge(const Set& set) const override;

public:
    OrderedSet();
    OrderedSet(const Set& set);
    OrderedSet(const int* values, size_t size);
    virtual ~OrderedSet();

    // gibt eine neue Menge zurueck, die alle Elemente von this enthaelt, die (strikt) kleiner als x sind 
    OrderedSet getSmaller(int x) const;

    // gibt eine neue Menge zurueck, die alle Elemente von this enthaelt, die (strikt) groesser als x sind 
    OrderedSet getLarger(int x) const;
};