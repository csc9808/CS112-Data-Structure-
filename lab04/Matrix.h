/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Seong Chan Cho (sc77)
 * Date: March 2nd 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {
public:
	Matrix();
	unsigned getRows() const;
	unsigned getColumns() const;
	Matrix(unsigned rows, unsigned columns);
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator==(const Matrix& m2) const;

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;

	friend class MatrixTester;
};

#endif
