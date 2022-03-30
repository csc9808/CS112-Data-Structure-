/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student:Seong Chan Cho (sc77)
 * Date: February 23, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */
 
#include "Vec.h"

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size){
	mySize = size;
	if (size > 0) {
		myArray = new Item[size]();
		for (unsigned i = 0; i < size; ++i) {
			myArray[i] = 0;
		}
	}
	else
	{
		myArray = NULL;
	}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[original.mySize]();
		for (unsigned i = 0; i < original.mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	}
	else
	{
		myArray = NULL;
	}
}


Vec::~Vec() {
	delete[] myArray;
	mySize = 0;
	myArray = NULL;
}

Vec& Vec::operator=(const Vec& original) {
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

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize) {
		throw range_error("Not in valid range");
	} else {
		myArray[index] = it;

	}
}

Item Vec::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("Not in valid range");
	} else {
		return myArray[index];
	}
}
void Vec::setSize(unsigned newSize) {
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

bool Vec::operator==(const Vec& v2) {
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
void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; ++i) {
		out << myArray[i] << '\n' << flush;
	}
}

void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; ++i) {
		in >> myArray[i];
	}
}


