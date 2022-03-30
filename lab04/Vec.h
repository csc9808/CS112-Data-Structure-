/* Vec.h provides a simple vector class named Vec.
 * Student Name: Seong Chan Cho (sc77)
 * Date: March 2nd 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;


template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);

	Item& operator[](unsigned index);
	const Item& operator[](unsigned index) const;

	bool operator!=(const Vec& v2);
	Vec operator-(const Vec& v2);
	Vec operator+(const Vec& v2);
	double operator*(const Vec& v2);
	void readFrom(const string& fileName);
	void writeTo(const string& fileName);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;

};

//sets default values
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

//explicit constructor takes size
template<class Item>
Vec<Item>::Vec(unsigned size) {
	Vec<double> v1;
	Vec<int> v2;
	mySize = size;
	if (size > 0) {
		myArray = new Item[size]();
		for (unsigned i = 0; i < size; ++i) {
			myArray[i] = 0;
		}
	} else {
		myArray = NULL;
	}
}
// Copy constructor
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[original.mySize]();
		for (unsigned i = 0; i < original.mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = NULL;
	}
}

//Destructor
template<class Item>
Vec<Item>::~Vec() {
	delete[] myArray;
	mySize = 0;
	myArray = NULL;
}
// assignment operator to check if equal
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize != original.mySize) {
			if (mySize > 0) {
				delete[] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize]();
			}
			mySize = original.mySize;
		}
		for (unsigned i = 0; i < original.mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}
// gets the size
template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

//sets the item
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index >= mySize) {
		throw range_error("Not in valid range");
	} else {
		myArray[index] = it;

	}
}
//gets the item
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("Not in valid range");
	} else {
		return myArray[index];
	}
}

//sets the size
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete[] myArray;
			myArray = NULL;
			mySize = 0;
		} else {
			Item * newArray = new Item[newSize]();
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; ++i) {
					newArray[i] = myArray[i];
				}
			} else {
				for (unsigned i = 0; i < newSize; ++i) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete[] myArray;
			myArray = newArray;
		}
	}
}
//checks if ==
template<class Item>
bool Vec<Item>::operator==(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < mySize; ++i) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}
//writes to from stream
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; ++i) {
		out << myArray[i] << '\n' << flush;
	}
}
//reads from stream
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; ++i) {
		in >> myArray[i];
	}
}
//index operator to change item
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (mySize <= index) {
		throw range_error("Invalid Index");
	} else {
		return myArray[index];
	}

}
//index operator gets the item
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (mySize <= index) {
		throw range_error("Invalid Index");
	} else {
		return myArray[index];
	}

}
//checks if it is inequal
template<class Item>
bool Vec<Item>::operator!=(const Vec& v2) {
	if (mySize != v2.mySize) {
		return true;
	} else {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] != v2.myArray[i]) {
				return true;
			}
		}
	}
	return false;
}
//adds values in vector
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec& v2) {
	if (mySize != v2.mySize) {
		throw invalid_argument("Not in valid range");
	}
	Vec v3;
	v3.mySize = mySize;
	v3.myArray = new Item[mySize];
	for (unsigned i = 0; i < v3.mySize; ++i) {
		v3.myArray[i] = myArray[i] + v2.myArray[i];
	}
	return v3;
}
//subtracts values in vector
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec& v2) {
	if (mySize != v2.mySize) {
		throw invalid_argument("Not in valid range");
	}
	Vec v3;
	v3.mySize = mySize;
	v3.myArray = new Item[mySize];
	for (unsigned i = 0; i < v3.mySize; ++i) {
		v3.myArray[i] = myArray[i] - v2.myArray[i];
	}
	return v3;
}
//multiplies each values in vector
template<class Item>
double Vec<Item>::operator*(const Vec& v2) {
	double dProd = 0;
	if (mySize != v2.mySize) {
		throw invalid_argument("Not in valid range");
	}
	Vec v3;
	v3.mySize = mySize;
	v3.myArray = new Item[mySize];
	for (unsigned i = 0; i < v3.mySize; ++i) {
		v3.myArray[i] = myArray[i] * v2.myArray[i];
	}
	for (unsigned i = 0; i < v3.mySize; ++i) {
		dProd = dProd + v3.myArray[i];
	}
	return dProd;
}
//reads from file
template<class Item>
void Vec<Item>::readFrom(const string &fileName) {
	if (mySize != 0 or myArray != NULL) {
		delete[] myArray;
	}
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	Vec v1(mySize);
	fin >> mySize;
	myArray = new Item[mySize]();
	for (unsigned i = 0; i < mySize; ++i) {
		fin >> myArray[i];
	}
	fin.close();

}
//writes into file
template<class Item>
void Vec<Item>::writeTo(const string& fileName) {
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	fout << mySize << endl;
	writeTo(fout);
	fout.close();
}

#endif /*VEC_H_*/
