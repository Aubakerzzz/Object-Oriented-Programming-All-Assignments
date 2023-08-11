#pragma once
class Matrix {

private:
	int** matrix;
	int row;
	int col;

public:
	Matrix();
	Matrix(int n1, int n2, int n3, int n4, int row = 2, int col = 2);
	Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row = 3, int col = 3);
	Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int
		n11, int n12, int n13, int n14, int n15, int n16, int row = 4, int col = 4);
	Matrix(const Matrix& m);
	~Matrix();
	int getRow();
	int getCol();
	int getValue(int row, int col);
	void setValue(int row, int col, int value);
	int Total();
	double Average();
	int RowTotal(int row);
	int ColumnTotal(int col);
	int HighestInRow(int row);
	int LowestInRow(int row);
	Matrix Transpose();
	int LeftDiagonalTotal();
	int RightDiagonalTotal();
	Matrix Add(Matrix m);
	Matrix Subtract(Matrix m);
	Matrix Multiply(Matrix m);
	int FindkSmallest(int k);
	int FindkLargest(int k);
	Matrix merge(Matrix m);

};

