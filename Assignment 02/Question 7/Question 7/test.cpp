#include "pch.h"
#include "Matrix.h"


TEST(Q7, first) {
	Matrix M(3, 4, 5, 6);

	ASSERT_EQ(2, M.getRow());
	ASSERT_EQ(2, M.getCol());

	ASSERT_EQ(3, M.getValue(0, 0));
	ASSERT_EQ(4, M.getValue(0, 1));
	ASSERT_EQ(5, M.getValue(1, 0));
	ASSERT_EQ(6, M.getValue(1, 1));
}

TEST(Q7, second) {
	Matrix M(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16


	ASSERT_EQ(4, M.getRow());
	ASSERT_EQ(4, M.getCol());

	ASSERT_EQ(4, M.getValue(0, 3));
	ASSERT_EQ(6, M.getValue(1, 1));
	ASSERT_EQ(11, M.getValue(2, 2));
	ASSERT_EQ(13, M.getValue(3, 0));
}

TEST(Q7, third) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(1, 1, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(6, M1.getValue(1, 1));
	ASSERT_EQ(60, M2.getValue(1, 1));
}

TEST(Q7, fourth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(136, M1.Total());
	ASSERT_EQ(8.5, M1.Average());
}

TEST(Q7, fifth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(2, 1, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(42, M1.RowTotal(2));
	ASSERT_EQ(92, M2.RowTotal(2));
}

TEST(Q7, sixth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(1, 2, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(32, M1.ColumnTotal(1));
	ASSERT_EQ(89, M2.ColumnTotal(2));
}

TEST(Q7, seventh) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(2, 1, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(12, M1.HighestInRow(2));
	ASSERT_EQ(60, M2.HighestInRow(2));
}

TEST(Q7, eighth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(0, 1, 0);
	M1.setValue(3, 2, 5);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(0, M2.LowestInRow(0));
	ASSERT_EQ(5, M1.LowestInRow(3));
}


TEST(Q7, ninth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2 = M1.Transpose();
	//M1			 //M2
	// 1  2  3  4    1  5  9  13
	// 5  6  7  8    2	6  10 14
	// 9  10 11 12   3  7  11 15
	// 13 14 15 16   4  8  12 16

	ASSERT_EQ(2, M2.getValue(1, 0));
	ASSERT_EQ(15, M2.getValue(2, 3));
	ASSERT_EQ(7, M2.getValue(2, 1));
	ASSERT_EQ(8, M2.getValue(3, 1));
	ASSERT_EQ(10, M2.getValue(1, 2));
	ASSERT_EQ(9, M2.getValue(0, 2));

}
TEST(Q7, tenth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(34, M1.LeftDiagonalTotal());

	M1.setValue(2, 2, 34);

	ASSERT_EQ(57, M1.LeftDiagonalTotal());
}

TEST(Q7, eleventh) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(34, M1.RightDiagonalTotal());

	M1.setValue(1, 2, 34);

	ASSERT_EQ(61, M1.RightDiagonalTotal());
}

TEST(Q7, twelfth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix M(1, 2, 3, 4);

	Matrix faulty = M1.Add(M);

	ASSERT_EQ(0, faulty.getRow());
	ASSERT_EQ(0, faulty.getCol());

	Matrix M2(M1);
	Matrix M3 = M1.Add(M2);

	// M1			M3
	// 1  2  3  4   2  4  6  8
	// 5  6  7  8	10 12 14 16
	// 9  10 11 12  18 20 22 24
	// 13 14 15 16  26 28 30 32

	ASSERT_EQ(12, M3.getValue(1, 1));
	ASSERT_EQ(8, M3.getValue(0, 3));
	ASSERT_EQ(28, M3.getValue(3, 1));
	ASSERT_EQ(18, M3.getValue(2, 0));
}


TEST(Q7, thirteenth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix M(1, 2, 3, 4);

	Matrix faulty = M1.Subtract(M);

	ASSERT_EQ(0, faulty.getRow());
	ASSERT_EQ(0, faulty.getCol());

	Matrix M2(M1);
	M2.setValue(0, 0, 2);
	M2.setValue(1, 1, 8);
	M2.setValue(2, 2, 14);
	M2.setValue(3, 3, 20);

	Matrix M3 = M2.Subtract(M1);
	//M1			//M3
	//1  2  3  4   1  0  0  0
	//5  6  7  8   0  2  0  0
	//9  10 11 12  0  0  3  0
	//13 14 15 16  0  0  0  4

	ASSERT_EQ(0, M3.getValue(0, 1));
	ASSERT_EQ(2, M3.getValue(1, 1));
	ASSERT_EQ(4, M3.getValue(3, 3));
	ASSERT_EQ(0, M3.getValue(2, 3));
}


TEST(Q7, fourteenth) {
	Matrix M(2, 3, 4, 5, 6, 7, 8, 9, 10);

	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix FM = M.Multiply(M1);

	ASSERT_EQ(0, FM.getCol());
	ASSERT_EQ(0, FM.getRow());

	Matrix N(6, 7, 8, 9, 10, 11, 12, 13, 14);

	Matrix X = M.Multiply(N);

	// 2  3  4       6  7  8        87  96  105
	// 5  6  7   *   9  10 11   =   168 186 204
	// 8  9  10      12 13 14		249 276 303		

	ASSERT_EQ(87, X.getValue(0, 0));
	ASSERT_EQ(96, X.getValue(0, 1));
	ASSERT_EQ(105, X.getValue(0, 2));
	ASSERT_EQ(168, X.getValue(1, 0));
	ASSERT_EQ(186, X.getValue(1, 1));
	ASSERT_EQ(204, X.getValue(1, 2));
	ASSERT_EQ(249, X.getValue(2, 0));
	ASSERT_EQ(276, X.getValue(2, 1));
	ASSERT_EQ(303, X.getValue(2, 2));
}

TEST(Q7, fifteenth) {
	Matrix X(9, 2, 3, 0, -5, 2, 3, 4, 100);

	ASSERT_EQ(-5, X.FindkSmallest(1));
	ASSERT_EQ(2, X.FindkSmallest(3));
	ASSERT_EQ(3, X.FindkSmallest(4));
	ASSERT_EQ(100, X.FindkSmallest(7));

	// return largest value if k is greater than the indexes of the matrix 
	// or due to duplicates in matrix, k becomes greater than all the unique values

	// return 0 if k is less than 1

	ASSERT_EQ(100, X.FindkSmallest(9));
	ASSERT_EQ(100, X.FindkSmallest(12));
	ASSERT_EQ(0, X.FindkSmallest(0));
}

TEST(Q7, sixteenth) {
	Matrix X(9, 2, 3, 0, -5, 2, 3, 4, 100);

	ASSERT_EQ(100, X.FindkLargest(1));
	ASSERT_EQ(-5, X.FindkLargest(7));
	ASSERT_EQ(3, X.FindkLargest(4));
	ASSERT_EQ(4, X.FindkLargest(3));
	ASSERT_EQ(0, X.FindkLargest(6));

	// return smallest value if k is greater than the indexes of the matrix 
	// or due to duplicates in matrix, k becomes greater than all the unique values

	// return 0 if k is less than 1

	ASSERT_EQ(-5, X.FindkLargest(9));
	ASSERT_EQ(-5, X.FindkLargest(12));
	ASSERT_EQ(0, X.FindkLargest(0));
}

TEST(Q7, seventeenth) {
	Matrix M(2, 3, 4, 5, 6, 7, 8, 9, 10);

	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix FM = M.merge(M1);

	ASSERT_EQ(0, FM.getCol());
	ASSERT_EQ(0, FM.getRow());

	Matrix N(6, 7, 8, 9, 10, 11, 12, 13, 14);

	Matrix X = M.merge(N);


	// 2  3  4           6  7  8        2  3  4  6  7  8
	// 5  6  7   merge   9  10 11   =   5  6  7  9  10 11
	// 8  9  10          12 13 14		8  9  10 12 13 14 

	ASSERT_EQ(6, X.getValue(1, 1));
	ASSERT_EQ(10, X.getValue(2, 2));
	ASSERT_EQ(9, X.getValue(1, 3));
	ASSERT_EQ(12, X.getValue(2, 3));
	ASSERT_EQ(7, X.getValue(0, 4));
	ASSERT_EQ(11, X.getValue(1, 5));
	ASSERT_EQ(6, X.getValue(0, 3));
	ASSERT_EQ(10, X.getValue(1, 4));
}



