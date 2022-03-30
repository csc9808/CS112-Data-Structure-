/* Matrix.cpp defines Matrix class methods.
 * Student Name: Seong Chan Cho (sc77)
 * Date: March 2nd 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */


#include "Matrix.h"

//Default constructor
Matrix::Matrix() {
	myRows = myColumns = 0;
}

// Returns myRows
unsigned Matrix::getRows() const {
	return myRows;
}

// Returns myColumns
unsigned Matrix::getColumns() const {
	return myColumns;
}

//Explicit Constructor
// Sets the size of each of our rows to the desired number of columns
Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (index >= myRows) {
		throw range_error("Index out of range");
	}
	return myVec[index];
}

Vec<Item>& Matrix::operator[](unsigned index) {
	if (index >= myRows) {
		throw range_error("Index out of range");
	}
	return myVec[index];
}
bool Matrix::operator==(const Matrix& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns()) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

