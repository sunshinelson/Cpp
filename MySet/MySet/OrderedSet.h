#pragma once

#include "MySet.h"

class OrderedSet : public Set
{
protected:
	size_t m_start;
	//Konstruktor
	OrderedSet(size_t size) : Set(size), m_start(0) {};

	void sort(); //Sortiert die Elemente des Arrays
	int *begin() const; // gibt einen Zeiger auf das erste Element der Menge zurueck (nullptr falls leer)
	Set merge(const Set& set) const; // gibt als neue Menge die Vereinigungsmenge dieser Menge mit set zurueck

public:
	//Standardconstruktor
	OrderedSet() : Set(), m_start(0) {};
	//Kopierkontruktor
	OrderedSet(const Set& set) : Set(set), m_start(0) { sort(); };
	//Typenconvertierungs-Konstruktor
	OrderedSet(const int* values, size_t size) : Set(size, values), m_start(0) { sort(); };
	virtual ~OrderedSet() {};
	bool containsAll(const OrderedSet& set) const; // testet, ob diese Menge alle Elemente der anderen Menge enthaelt (und somit dessen Supermenge ist)
	// gibt eine neue Menge zurueck, die alle Elemente von this enthaelt, die (strikt) kleiner als x sind
	OrderedSet getSmaller(int x) const;
	// gibt eine neue Menge zurueck, die alle Elemente von this enthaelt, die (strikt) groesser als x sind
	OrderedSet getLarger(int x) const;
};
