#pragma once

class Sequence {
private:

	int length;
	int* pseq;

public:

	Sequence();
	Sequence(int lengthval, int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0,
		int n5 = 0, int n6 = 0, int n7 = 0, int n8 = 0, int n9 = 0, int n10 = 0);
	Sequence(Sequence& s);
	int getLength();
	int* getSeq();
	void Sort(int n);
	int RemoveDuplicates();
	void Rotate(int steps);
	~Sequence();

};





