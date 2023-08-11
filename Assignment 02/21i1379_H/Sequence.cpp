#include "pch.h"
#include "Sequence.h"


Sequence::Sequence() {

	length = 10;
	pseq = new int[length];

	for (int i = 0; i < length; i++) {
		pseq[i] = 0;
	}
}

Sequence::Sequence(int lengthval, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {

	length = lengthval;
	
	pseq = new int[10];

	pseq[0] = n1;
	pseq[1] = n2;
	pseq[2] = n3;
	pseq[3] = n4;
	pseq[4] = n5;
	pseq[5] = n6;
	pseq[6] = n7;
	pseq[7] = n8;
	pseq[8] = n9;
	pseq[9] = n10;

}

Sequence::Sequence(Sequence& s) {

	length = s.length;
	pseq = new int[length];
	for (int i = 0; i < length; i++) {
		this->pseq[i] = s.pseq[i];
	}
}

int Sequence::getLength() {
	return length;
}

int* Sequence::getSeq() {
	return pseq;
}

void Sequence::Sort(int n) {
	int k, j;
	for (int i = 1; i < n; i++) {
		k = pseq[i];
		j = i - 1;

		while (j >= 0 && pseq[j] > k) {
			pseq[j + 1] = pseq[j];
			j = j - 1;
		}
		pseq[j + 1] = k;
	}
}

int Sequence::RemoveDuplicates() {
	
	this->Sort(this->length);
	int counter = 0;
	for (int i = 1; i < length; i++) {
		if (pseq[i] != pseq[counter]) {
			pseq[++counter] = pseq[i];
		}
	}

	return counter + 1;
}

void Sequence::Rotate(int steps) {

	for (int i = 0; i < steps; i++) {
		int temp = this->pseq[length - 1];
		for (int i = length - 2; i >= 0; i--) {
			pseq[i + 1] = pseq[i];
		}
		pseq[0] = temp;
	}

}

Sequence::~Sequence() {
	delete[] pseq;
}

