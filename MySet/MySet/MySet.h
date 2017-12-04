#pragma once
#include <iostream>
#include <memory>
using namespace std;


class Set {
protected:
	size_t m_size;
	shared_ptr<int> m_values;
	//Konstruktor
	Set(size_t size) : m_values(new int[size], default_delete<int[]>()), m_size(0) {
		cout << "private-ctor" << endl;
	};
	// geschützte Instanzmethoden
	int *begin() const; // gibt einen Zeiger auf das erste Element der Menge zurueck (nullptr falls leer)
	int& operator[](const size_t i); // gibt das i-te Element des Mengen-Arrays zurueck
	const int& operator[](const size_t i) const; // gibt das i-te Element des Mengen-Arrays zurueck nur Lesezugriff
	Set merge(const Set& set) const; // gibt als neue Menge die Vereinigungsmenge dieser Menge mit set zurueck
	// gibt als neue Menge die Differenzmenge zwischen set und dieser Menge (set \ this) zurueck
	Set difference(const Set& set) const;
	Set difference(Set&& set) const;
	// gibt als neue Menge die Schnittmenge dieser Menge mit set zurueck
	Set intersection(const Set& set) const; 
	Set intersection(Set&& set) const;
public:
	//Standardconstruktor
	Set() : m_values(nullptr), m_size(0) { cout << "stdrd-ctor" << endl; };
	//Kopierkontruktor
	Set(const Set& s) : m_values(s.m_values), m_size(s.m_size) {
		cout << "copy-ctor " << s << endl;
	};
	//Typenconvertierungs-Konstruktor
	Set(size_t size, const int* values) : Set(size) {
		for (size_t i = 0; i < size; i++){
			if (!contains(values[i])) {
				begin()[m_size++] = values[i];
			}
		}
		cout << "typeconv-ctor " << *this << endl;
	};
	//Destruktor
	virtual ~Set() {
		cout << "destor " << *this << endl;
		default_delete<int[]>(m_values);
	};
	// Instanzmethoden
	bool contains(int e) const; // testet, ob die Menge e enthaelt
	bool containsAll(const Set& set) const; // testet, ob diese Menge alle Elemente der anderen Menge enthaelt (und somit dessen Supermenge ist)
	bool isEmpty() const; // testet, ob die Menge leer ist
	size_t size() const; // gibt Anzahl Elemente in der Menge zurueck
	bool operator==(const Set& set) const { return containsAll(set) && set.containsAll(*this); } // Gleichheitsoperator ('equals' in Java) (Inline - Implementation schon gegeben)
	// Ausgabe-Operator für Output-Streams
	// (Inline-Implementation schon gegeben)
	friend ostream& operator<<(ostream& os, const Set& s) {
		const int* const vptr = s.begin();
		os << "{";
		if (!s.isEmpty()) os << vptr[0];
		for (size_t i = 1; i < s.m_size; ++i) { os << ", " << vptr[i]; }
		os << "}";
		return os;
	}
	// Klassen-Methoden
	// Vereinigungsmenge
	static Set merge(const Set& set1, const Set& set2) { return set1.merge(set2); }

	// Differenzmenge set1\set2
	static Set difference(const Set& set1, const Set& set2) { return set2.difference(set1); }
	static Set difference(Set&& set1, const Set& set2) { return set2.difference(move(set1)); }
	static Set difference(Set&& set1, Set&& set2) { return set2.difference(move(set1)); }

	// Schnittmenge
	static Set intersection(const Set& set1, const Set& set2) { return set1.intersection(set2); }
	static Set intersection(const Set& set1, Set&& set2) { return set1.intersection(move(set2)); }
	static Set intersection(Set&& set1, const Set& set2) { return set2.intersection(move(set1)); }
	static Set intersection(Set&& set1, Set&& set2) { return set1.intersection(move(set2)); }
};
