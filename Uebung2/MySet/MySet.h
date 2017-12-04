#pragma once

#include <memory>

using namespace std;

class Set {
protected:
    shared_ptr<int> m_values;
    size_t m_size;

protected:
    Set(size_t size);

    bool insert(const int value);

    // gibt einen Zeiger auf das erste Element der Menge zurueck (nullptr falls leer) 
    virtual int* begin() const;

    // gibt das i-te Element des Mengen-Arrays zurueck 
    int& operator[](const size_t i);
    const int& operator[](const size_t i) const;

    // gibt als neue Menge die Vereinigungsmenge dieser Menge mit set zurueck 
    virtual Set merge(const Set& set) const;

    // gibt als neue Menge die Differenzmenge zwischen set und dieser Menge (set \ this) zurueck 
    Set difference(const Set& set) const;
    Set difference(Set&& set) const;

    // gibt als neue Menge die Schnittmenge dieser Menge mit set zurueck 
    Set intersection(const Set& set) const;
    Set intersection(Set&& set) const;

public:
    Set();
    Set(const Set& set);
    Set(const int* values, size_t size);
    virtual ~Set();

    // testet, ob die Menge e enthaelt 
    bool contains(const int value) const;

    // testet, ob diese Menge alle Elemente der anderen Menge enthaelt (und somit dessen Supermenge ist) 
    bool containsAll(const Set& set) const;

    // testet, ob die Menge leer ist 
    bool isEmpty() const;

    // gibt Anzahl Elemente in der Menge zurueck
    size_t size() const;

    // Gleichheitsoperator ('equals' in Java) (Inline - Implementation schon gegeben) 
    bool operator==(const Set& set) const;

    // Ausgabe-Operator für Output-Streams 
    friend ostream& operator<<(ostream& os, const Set& s);

    // Vereinigungsmenge 
    static Set merge(const Set& set1, const Set& set2);

    // Differenzmenge set1\set2 
    static Set difference(const Set& set1, const Set& set2);
    static Set difference(Set&& set1, const Set& set2);
    static Set Set::difference(Set&& set1, Set&& set2);

    // Schnittmenge 
    static Set intersection(const Set& set1, const Set& set2);
    static Set intersection(const Set& set1, Set&& set2);
    static Set intersection(Set&& set1, const Set& set2);
    static Set intersection(Set&& set1, Set&& set2);
};