#ifndef __ZMATRIX_H
#define __ZMATRIX_H 1

#include <iostream>

class Matrix
{
public:
	Matrix(int lines, int cols);
	Matrix(int lines, int cols, int value);
	~Matrix();

	/* Operators */
	void friend operator<< (std::ostream &out, Matrix &m) {
		
		int 	  index = 0
				, i
				, j;

		for (i = 0; i < m._nlines; ++i) {
			for (j = 0; j < m._ncols; ++j) {
				out << m._data[index ++] << " ";
			}
			out << std::endl;
		}
		out << std::endl;
	}

	void friend operator>> (std::istream &in, Matrix &m) {
		
		int 	  index = 0
				, i
				, j;

		for (i = 0; i < m._nlines; ++i) {
			for (j = 0; j < m._ncols; ++j) {
				in >> m._data[index ++];
			}
		}
	}

	Matrix& operator+ (const Matrix &m);
	Matrix& operator+ (const int value);
	Matrix& operator- (const Matrix &m);
	Matrix& operator- (const int value);

private:
	int _nlines;
	int _ncols;
	int _elemCount;

	int * _data;
};

#endif
