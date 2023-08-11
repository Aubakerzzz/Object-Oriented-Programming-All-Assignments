#include "pch.h"
#include "Sequence.h"


//----------Question #02----------

TEST(Q2, first) {
	Sequence sequence;
	ASSERT_EQ(10, sequence.getLength());

	int* pseq = sequence.getSeq();
	for (int i = 0; i < 10; i++)
		ASSERT_EQ(0, *(pseq + i));

	Sequence sequence1(5, 20, 30, 40, 50, 60);
	int* pseq1 = sequence1.getSeq();
	ASSERT_EQ(5, sequence1.getLength());
	ASSERT_EQ(20, *pseq1);
	ASSERT_EQ(40, *(pseq1 + 2));
	ASSERT_EQ(60, *(pseq1 + 4));
}

TEST(Q2, second) {
	Sequence sequence1(5, 20, 30, 40, 50, 60);
	int* pseq1 = sequence1.getSeq();

	Sequence sequence2(sequence1);
	int* pseq2 = sequence2.getSeq();
	ASSERT_NE(pseq2, pseq1);
	ASSERT_EQ(5, sequence2.getLength());
	ASSERT_EQ(30, *(pseq2 + 1));
	ASSERT_EQ(50, *(pseq2 + 3));
}

TEST(Q2, third) {
	Sequence sequence(10, 8, 3, 2, 5, 6, 9, 3, 1, 10, 8);

	sequence.Sort(5);
	int* pseq = sequence.getSeq();
	ASSERT_EQ(2, *pseq);
	ASSERT_EQ(3, *(pseq + 1));
	ASSERT_EQ(6, *(pseq + 3));
	ASSERT_EQ(8, *(pseq + 4));
	ASSERT_EQ(10, *(pseq + 8));
	ASSERT_EQ(3, *(pseq + 6));
}

TEST(Q2, fourth) {
	Sequence sequence(8, 5, 5, 3, 9, 3, 5, 3, 9);

	ASSERT_EQ(3, sequence.RemoveDuplicates());
	int* pseq = sequence.getSeq();
	ASSERT_EQ(8, sequence.getLength());
	ASSERT_EQ(3, *pseq);
	ASSERT_EQ(5, *(pseq + 1));
	ASSERT_EQ(9, *(pseq + 2));
}

TEST(Q2, fifth) {
	Sequence sequence(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	sequence.Rotate(4);
	int* pseq = sequence.getSeq();
	ASSERT_EQ(7, *pseq);
	ASSERT_EQ(8, *(pseq + 1));
	ASSERT_EQ(9, *(pseq + 2));
	ASSERT_EQ(10, *(pseq + 3));
	ASSERT_EQ(1, *(pseq + 4));
	ASSERT_EQ(2, *(pseq + 5));
	ASSERT_EQ(5, *(pseq + 8));
	ASSERT_EQ(6, *(pseq + 9));
}
