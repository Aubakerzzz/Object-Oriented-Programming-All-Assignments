#include "pch.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix() {
	row = 0;
	col = 0;
	matrix = NULL;
}

Matrix::Matrix(int n1, int n2, int n3, int n4, int row, int col) {

	this->row = row;
	this->col = col;
	matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[1][0] = n3;
	matrix[1][1] = n4;

}

Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row,
	int col) {

	this->row = row;
	this->col = col;
	matrix = new int* [row];
	for (int i = 0; i < col; i++) {
		matrix[i] = new int[col];
	}

	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[0][2] = n3;
	matrix[1][0] = n4;
	matrix[1][1] = n5;
	matrix[1][2] = n6;
	matrix[2][0] = n7;
	matrix[2][1] = n8;
	matrix[2][2] = n9;

}
Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int
	n11, int n12, int n13, int n14, int n15, int n16, int row, int col) {


	this->row = row;
	this->col = col;
	matrix = new int* [row];
	for (int i = 0; i < col; i++) {
		matrix[i] = new int[col];
	}

	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[0][2] = n3;
	matrix[0][3] = n4;
	matrix[1][0] = n5;
	matrix[1][1] = n6;
	matrix[1][2] = n7;
	matrix[1][3] = n8;
	matrix[2][0] = n9;
	matrix[2][1] = n10;
	matrix[2][2] = n11;
	matrix[2][3] = n12;
	matrix[3][0] = n13;
	matrix[3][1] = n14;
	matrix[3][2] = n15;
	matrix[3][3] = n16;

}

Matrix::Matrix(const Matrix& m) {

	this->row = m.row;
	this->col = m.col;
	matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
	for (int q = 0; q < row; q++) {
		for (int o = 0; o < col; o++) {
			this->matrix[q][o] = m.matrix[q][o];
		}
	}
}

Matrix::~Matrix() {

	for (int e = 0; e < row; e++) {
		delete[]  matrix[e];
	}
	delete[] matrix;
}

int Matrix::getRow() {


	return row;
}

int Matrix::getCol() {

	return col;
}
int Matrix::getValue(int row, int col) {

	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <= col; j++) {
			if (matrix[i][j] == matrix[row][col]) {
				return matrix[i][j];
			}
		}
	}
	return 0;
}


void Matrix::setValue(int row, int col, int value) {

	matrix[row][col] = value;

}


int Matrix::Total() {

	int temp = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp += matrix[i][j];
		}
	}
	return temp;
}

double Matrix::Average() {

	int temps = 0;
	double average = 0.0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temps += matrix[i][j];
		}
	}
	average = (double)temps / (row * col);
	return average;
}

int Matrix::RowTotal(int row) {

	int sum = 0;
	for (int i = 0; i < col; i++) {
		sum += matrix[row][i];
	}
	return sum;
}

int Matrix::ColumnTotal(int col) {

	int add = 0;
	for (int i = 0; i < row; i++) {
		add += matrix[i][col];
	}
	return add;

}
int Matrix::HighestInRow(int row) {


	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (matrix[row][i] < matrix[row][j]) {
				int temp = matrix[row][i];
				matrix[row][i] = matrix[row][j];
				matrix[row][j] = temp;

			}
		}
	}
	return matrix[row][0];

}

int Matrix::LowestInRow(int row) {


	for (int i = 0; i < col; i++) {
		for (int j = i + 1; j < col; j++) {
			if (matrix[row][i] > matrix[row][j]) {
				int temp = matrix[row][i];
				matrix[row][i] = matrix[row][j];
				matrix[row][j] = temp;
			}
		}
	}
	return matrix[row][0];
}

Matrix Matrix::Transpose() {

	Matrix transpose;
	transpose.row = this->row;
	transpose.col = this->col;
	transpose.matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		transpose.matrix[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			transpose.matrix[i][j] = this->matrix[j][i];
		}
	}

	return transpose;
}

int Matrix::LeftDiagonalTotal() {

	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

int Matrix::RightDiagonalTotal() {

	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (row == (i + j) + 1) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

Matrix Matrix::Add(Matrix m) {

	Matrix add;
	if (this->col != m.row)
		return add;

	add.row = this->row;
	add.col = this->col;
	add.matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		add.matrix[i] = new int[col];
	}


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			add.matrix[i][j] = m.matrix[i][j] + this->matrix[i][j];
		}
	}
	return add;

}

Matrix Matrix::Subtract(Matrix m) {

	Matrix sub;
	if (this->col != m.row)
		return sub;

	sub.row = this->row;
	sub.col = this->col;
	sub.matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		sub.matrix[i] = new int[col];
	}


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sub.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
		}
	}
	return sub;

}

Matrix Matrix::Multiply(Matrix m) {

	Matrix multi;

	if (this->col != m.row)
		return multi;

	multi.row = this->row;
	multi.col = m.col;
	multi.matrix = new int* [multi.row];
	for (int i = 0; i < multi.row; i++) {
		multi.matrix[i] = new int[multi.col];
	}

	for (int i = 0; i < multi.row; i++) {
		for (int j = 0; j < multi.col; j++) {
			multi.matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < m.col; j++) {
			for (int k = 0; k < this->col; k++) {
				multi.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
			}
		}
	}
	return multi;
}

int Matrix::FindkSmallest(int k) {

	if (k == 0)
		return 0;

	int size = col * row;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}

	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[count++] = matrix[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	int counter = 0;
	int* ret = new int[size];
	ret[0] = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > ret[counter]) {
			ret[++counter] = arr[i];
		}
	}

	delete[] arr;

	int returnValue = 0;

	if (k - 1 > counter) {
		returnValue = ret[counter];
		delete[] ret;
		return returnValue;
	}
		
	returnValue = ret[k - 1];
	delete[] ret;
	return returnValue;
}

int Matrix::FindkLargest(int k) {


	if (k == 0)
		return 0;

	int size = col * row;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}

	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[count++] = matrix[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	int counter = 0;
	int* ret = new int[size];
	ret[0] = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < ret[counter]) {
			ret[++counter] = arr[i];
		}
	}

	delete[] arr;

	int returnValue = 0;

	if (k - 1 > counter) {
		returnValue = ret[counter];
		delete[] ret;
		return returnValue;
	}

	returnValue = ret[k - 1];
	delete[] ret;
	return returnValue;

}

Matrix Matrix::merge(Matrix m) {

	Matrix merged;
	if ((this->row != m.row) || (this->col != m.col))
		return merged;

	merged.row = this->row;
	merged.col = this->col * 2;

	merged.matrix = new int* [merged.row];
	for (int i = 0; i < merged.row; i++) {
		merged.matrix[i] = new int[merged.col];
	}

	for (int i = 0; i < merged.row; i++) {
		int counter = 0;
		for (int j = 0; j < merged.col; j++) {
			if (j < this->col) {
				merged.matrix[i][j] = this->matrix[i][j];
			}
			else {
				merged.matrix[i][j] = m.matrix[i][counter++];
			}
		}
	}
	return merged;
}







