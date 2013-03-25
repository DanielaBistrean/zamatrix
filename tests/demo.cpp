#include <iostream>
#include <fstream>
#include "../include/zmatrix.h"

int main(int argc, char const *argv[])
{
	std::cout << "TODO! Create tests for all features!\n";

	Matrix m1 = Matrix(3, 3, 58);
	Matrix m2 = Matrix(2, 3);
	Matrix m3 = Matrix(3, 3, 18);
	Matrix m4 = Matrix(3, 3);

	std::fstream f("sample_matrix.mat");
	f >> m2;

	std::cout << m1;
	std::cout << m2;

	m4 = m1 - m3;

	std::cout << m1 + m2;
	std::cout << m4;

	std::cout << m4 - 1;

	m2 = m2 + 1;

	std::cout << m2;

	return 0;
}