/* Abubaker
	21I-1379
	Assignment# 03
*/

#include "BinaryStore.h"

// -------------------BinaryStore Class ------------------

BinaryStore::BinaryStore(int size) {
	this->size = size;
	count = 0;
	address = new char* [size];
	for (int i = 0;i < size;i++) {
		address[i] = new char[5];
		address[i][0] = '\0';
	}
	//b = new Byte[size];
}
BinaryStore::BinaryStore(BinaryStore& copy) {
	this->size = size;
	count = copy.count;
	address = new char* [size];
	int i = 0;
	for (i = 0;i < size;i++)
		address[i] = new char[5];
	for (i = 0;i < size;i++)
		for (int k = 0;k < 5;k++) {
			if(copy.address[i][k]!='\0')
			address[i][k] = copy.address[i][k];
			else
				address[i][0] = '\0';
		}
	//b = new Byte[size];
	for (i = 0;i < size;i++)
		for (int k = 0;k < 8;k++) {
			if (copy.b[i].value[0] != '\0')
				b[i].value[k] = copy.b[i].value[k];
			else
				b[i].value[0] = '\0';
		}
}

void BinaryStore::operator+=(const char* str) {
	for (int i = 0;i < 4;i++)
		this->address[count][i] = str[i];
	this->address[count][4] = '\0';
}
void BinaryStore::Add(const char* str, Byte& copy) {
	int i,k;
	bool flag = 1;
	for (i = 0; i < size;i++) {
		flag = 1;
		for (k = 0;k < 4;k++)
			if (address[i][k] != str[k])
				flag = 0;
		if (flag && k == 4)
			break;
	}
	count++;
	for (k = 0;k < 8;k++)
		b[i].value[k] = copy.value[k];
	b[i].value[k] = '\0';
}
Byte& BinaryStore::Get(const char* str) {
	int i, k;
	bool flag = 1;
	for (i = 0; i < size;i++) {
		flag = 1;
		for (k = 0;k < 4;k++)
			if (address[i][k] != str[k])
				flag = 0;
		if (flag && k == 4)
			return b[i];
	}
}
BinaryStore::~BinaryStore() {

}
char* BinaryStore::get(int i) {
	return address[i-1];
}
void BinaryStore::setSize(int i) {
	if (i >= 0) {
		this->size = i;
		count = 0;
		address = new char* [size];
		for (int i = 0;i < size;i++) {
			address[i] = new char[5];
			address[i][0] = '\0';
		}
	}
}

// -------------------Byte Class ------------------

Byte::Byte() {
	value = new char [9];
	/*for(int i=0;i<9;i++)
		value = */
}
Byte::Byte(const char* str) {
	value = new char[9];
	int i;
	for (i = 0;i < 8;i++)
		value[i] = str[i];
	value[i] = '\0';
}
Byte::Byte(const Byte& copy) {
	value = new char[9]{};
	for (int i = 0;i < 8;i++)
		value[i] = copy.value[i];
}

char* Byte::getByte() {
	value[8] = '\0';
	return value;
}
Byte::~Byte() {

}

Byte Byte::operator+(Byte& b) {
	Byte temp;
	int n=0;
	int car=0;

	for (int i = 7;i >= 0;i--) {
		n = (b.value[i] - '0') + (this->value[i] - '0') + car;

		if (n == 1) {
			temp.value[i] = n + '0';
			car = 0;
		}
		else if (n == 2) {
			n = 0;
			car = 1;
			if (n != 0)
				temp.value[i] = n + '0';
			else
				temp.value[i] = '0';
		}
		else if (n == 3) {
			n = 1;
			car = 1;
			if (n != 0)
				temp.value[i] = n + '0';
			else
				temp.value[i] = '0';
		}
		else if (n == 0) {
			temp.value[i] = '0';
			car = 0;
		}
	}
	return temp;
}
Byte Byte::operator-(Byte& b) {
	int i;
	Byte temp, t1;

	for (i = 0;i < 8;i++)
		t1.value[i] = '1' - b.value[i] + '0';
	temp = *this + t1;

	for (i = 0;i < 8;i++)
		t1.value[i] = '0';
	t1.value[7] = '1';

	temp = temp + t1;

	return temp;
}

bool Byte::operator==(Byte& b) {
	for (int i = 0;i < 8;i++)
		if (this->value[i] != b.value[i])
			return false;
	return true;
}
Byte Byte::operator&&(Byte& b) {
	Byte temp;
	int n;
	for (int i = 0;i < 8;i++) {
		n = (b.value[i] - '0') & (this->value[i] - '0');
		temp.value[i] = n + '0';
	}
	return temp;
}
Byte Byte::operator||(Byte& b) {
	Byte temp;
	int n;
	for (int i = 0;i < 8;i++) {
		n = (b.value[i] - '0') | (this->value[i] - '0');
		temp.value[i] = n + '0';
	}
	return temp;
}

ostream& operator<<(ostream& output, const BinaryStore& c) {
	
		for(int i=0;i<c.count;i++)
		cout << c.address[i]<<"  "<<c.b[i].value<<endl;
	
	cout << endl;
	return output;
}
