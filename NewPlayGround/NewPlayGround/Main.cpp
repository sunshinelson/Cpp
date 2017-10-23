#include <iostream>

using namespace std;

// Dreiecksmatrix Variante 2 (Java)
class TriangleMatrix
{
public:
	double getElement(int row, int col);
	TriangleMatrix(int len);  // This is the constructor

private:
	double** mArray; // two dimensional double array
};
TriangleMatrix::TriangleMatrix(int size)
{
	mArray = new double*[size];
	for (int i = 0; i < size; ++i) {
		int xAxeArrayLength = i + 1;
		mArray[i] = new double[xAxeArrayLength];
		{// fill values into array:
			for (int ii = 0; ii < xAxeArrayLength; ii++)
			{
				double value = ii;
				value = value / 10;
				value += i;
				mArray[i][ii] = value;
			}
		}// values filled in
	}
}
double TriangleMatrix::getElement(int row, int col)
{
	return mArray[row][col];
}


// Dreiecksmatrix Variante 1 (C-Stil)
class TriangleMatrix2
{
public:
	double getElement(int row, int col);
	TriangleMatrix2(int len);  // This is the constructor

private:
	double* mArray; // one dimensional double array
};
TriangleMatrix2::TriangleMatrix2(int size)
{
	int arrayLengthCounter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int ii = 0; ii < i + 1; ii++)
		{
			arrayLengthCounter++;
		}
	}
	mArray = new double[arrayLengthCounter];

	{// fill values into array:
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			for (int ii = 0; ii < i + 1; ii++)
			{
				double value = ii;
				value = value / 10;
				value += i;
				mArray[counter] = value;
				counter++;
			}
		}
	}// values filled in
}
double TriangleMatrix2::getElement(int row, int col)
{
	int rowStartIndex = row; // whether start with 0 but loop while "i <= row" or start with row
	for (int i = 0; i < row; i++)
	{
		rowStartIndex += i;
	}
	int index = rowStartIndex + col;
	return mArray[index];
}

// 
int strLen(char* string) {
	int length = 0;
	while (*string != '\0') {
		string++;
		length++;
	}
	return length;
}

class MyString {
public:
	int getIndex(char c);
	MyString& operator--();
	MyString operator--(int);
	MyString(char* content, size_t length, size_t capacity);
private:
	char* m_contents;
	size_t m_length;
	size_t m_capacity;
};
MyString::MyString(char* content, size_t length, size_t capacity) {
	m_contents = content;
	m_length = length;
	m_capacity = capacity;
}
// Return Char Index in String (m_contents)
int MyString::getIndex(char c) {
	int indexCounter = 0;
	char* ptr = m_contents;
	while (indexCounter < m_length) {
		if (*ptr == c) {
			return indexCounter;
		}
		ptr++;
		indexCounter++;
	}
	return -1;
}
MyString& MyString::operator--() {
	m_length--;
	m_capacity--;
	m_contents++;
	return *this;
}
MyString MyString::operator--(int) {
	MyString myString = *this;
	--*this;
	return myString;
}

class Animal {
public:
	virtual void eat();
};
void Animal::eat() {
	cout << "Generic Food" << endl;
}

class Pet : public Animal {
public:
	void eat() override;
};
void Pet::eat() {
	cout << "Pet Food" << endl;
}

class Cat : public Pet {
public:
	void eat();
};
void Cat :: eat() {
	cout << "Wizcas" << endl;
}

void main() {
	Animal* animal;

	Pet pet;
	pet.eat();

	Cat cat;
	cat.eat();


	animal = &pet;
	animal->eat();



	int endVariable;
	cin >> endVariable;
}



// ##################


uint32_t tmp;
memcpy(&tmp, &theFloat, sizeof(float));
bool isNeg = (tmp & 0x10000000);
int  exp = (int)((tmp & 0x7F800000) >> 23);
long mant = (tmp & 0x007FFFFF) | 0x00800000;

cout << (isNeg ? "negativ" : "positiv") << endl;;
cout << exp << endl;
cout << mant << endl;
