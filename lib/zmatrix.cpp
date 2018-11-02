#include <iostream>
#include <memory.h>
#include "../include/zmatrix.h"

Matrix::Matrix(int lines, int cols)
: _nlines {lines}
, _ncols {cols}
, _elemCount { lines * cols }
{
	this->_data = new int[this->_elemCount];
}

Matrix::Matrix(int lines, int cols, int value)
: _nlines {lines}
, _ncols {cols}
, _elemCount { lines * cols }
{
	this->_data = new int[this->_elemCount];
	
	for (int i = 0; i < this->_elemCount; ++i) {
		this->_data[i] = value;	
	}
}

Matrix::~Matrix()
{
	delete this->_data;
}


/* Operators */

Matrix& Matrix::operator+ (const Matrix &m)
{
	if (this->_ncols == m._ncols && this->_nlines == m._nlines) {
		
		Matrix *result = new Matrix(this->_nlines, this->_ncols);

		for (int i = 0; i < this->_elemCount; ++i) {
			result->_data[i] = m._data[i] + this->_data[i];
		}

		return *result;
	}

	std::cout << "[ERROR] Matrix dimensions does not match! Cannot perform addition!\n";
	return *(new Matrix(0, 0));
}

Matrix& Matrix::operator+ (const int value)
{
	if (this->_ncols != 0 && this->_nlines != 0) {
		
		Matrix *result = new Matrix(this->_nlines, this->_ncols);

		for (int i = 0; i < this->_elemCount; ++i) {
			result->_data[i] = this->_data[i] + value;
		}

		return *result;
	}

	std::cout << "[ERROR] Cannot add to uninitialized matrix!\n";
	return *(new Matrix(0, 0));
}

Matrix& Matrix::operator- (const Matrix &m)
{
	if (this->_ncols == m._ncols && this->_nlines == m._nlines) {
		
		Matrix *result = new Matrix(this->_nlines, this->_ncols);

		for (int i = 0; i < this->_elemCount; ++i) {
			result->_data[i] = this->_data[i] - m._data[i];
		}

		return *result;
	}

	std::cout << "[ERROR] Matrix dimensions does not match! Cannot perform addition!\n";
	return *(new Matrix(0, 0));
}

Matrix& Matrix::operator- (const int value)
{
	if (this->_ncols != 0 && this->_nlines != 0) {
		
		Matrix *result = new Matrix(this->_nlines, this->_ncols);

		for (int i = 0; i < this->_elemCount; ++i) {
			result->_data[i] = this->_data[i] - value;
		}

		return *result;
	}

	std::cout << "[ERROR] Cannot substract from uninitialized matrix!\n";
	return *(new Matrix(0, 0));
}
