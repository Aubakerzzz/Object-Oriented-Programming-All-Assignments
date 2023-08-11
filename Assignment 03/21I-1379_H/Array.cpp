/*Name:Abubaker
 Roll#:21I-1379
 Sec :H */

#include "pch.h"
#include "Array.h"
#include <iostream>
using namespace std;

Array::Array() {

	size = 0;
	str = new int[40];

	for (int i = 0; i < 40; i++) {
		str[i] = 0;
	}

}

Array::Array(int size) {

	this->size = size;
	str = new int[size];
	for (int i = 0; i < size; i++) {
		str[i] = 0;
	}

}

Array::Array(int* arr, int size) {

	this->size = size;
	str = new int[size];

	for (int i = 0; i < size; i++) {
		str[i] = arr[i];
	}

}
Array::Array(const Array& copy) {

	this->size = copy.size;

	str = new int[size];

	for (int i = 0; i < size; i++) {
		this->str[i] = copy.str[i];
	}
}

int& Array::operator[](int i) {

	return str[i];
}

int& Array::operator[](int i) const {

	return str[i];
}

const Array& Array:: operator=(const Array& object) {


	this->size = object.size;

	for (int i = 0; i < size; i++) {
		this->str[i] = object.str[i];
	}
	return *this;

}

Array Array:: operator+(const Array& ob) {

	Array temp;

	temp.size = this->size;
	int counter = this->size;
	temp.str = new int[counter];


	for (int i = 0; i < 3; i++) {
		temp.str[i] = this->str[i] + ob.str[i];
	}
	return temp;

}

Array Array::operator-(const Array& c) {

	Array obj;

	obj.size = this->size;
	obj.str = new int[obj.size];

	for (int i = 0; i < size; i++) {
		obj.str[i] = this->str[i] - c.str[i];
	}
	return obj;

}

Array Array::operator++() {


	Array obj;

	obj.size = this->size;
	obj.str = new int[size];

	for (int i = 0; i < size; i++) {
		obj.str[i] = ++(this->str[i]);
	}
	return obj;

}

Array Array::operator++(int) {

	Array obj;

	obj.size = this->size;
	obj.str = new int[size];

	for (int i = 0; i < size; i++) {
		obj.str[i] = ++(this->str[i]);
	}
	return obj;
}

Array& Array::operator--(int) {

	Array obj;

	obj.size = this->size;
	obj.str = new int[size];

	for (int i = 0; i < size; i++) {
		obj.str[i] = --(this->str[i]);
	}
	return obj;

}

bool Array::operator==(const Array& s)const {

	if (this->size == s.size)
		return true;
	return false;

}

bool Array::operator!() {

	if (size == 0)
		return true;
	return false;


}

void Array::operator+=(const Array& c) {

	this->size = c.size;

	for (int i = 0; i < size; i++) {
		this->str[i] += c.str[i];
	}
}

void Array::operator-=(const Array& obj) {

	this->size = obj.size;

	for (int i = 0; i < size; i++) {
		this->str[i] -= obj.str[i];
	}

}

int Array::operator()(int idx, int val) {
	
	if (idx >= this->size || idx < 0)
		return -1;
	if (this->str[idx] != val)
		return -1;
	this->str[idx] = -1;
	for (int i = idx; i < this->size; i++) {
		int temp = this->str[i];
		this->str[i] = this->str[i + 1];
		this->str[i + 1] = str[i];
	}
	this->size -= 1;
	return 1;

}

Array::~Array() {

	delete[] str;

}

ostream& operator<<(ostream& output, const Array& b) {

	output << b.size << endl;
	for (int i = 0; i < b.size; i++) {
		output << b.str[i] << " ";
	}
	return output;
}

istream& operator>>(istream& cin, const Array& c) {

	cin >> c.size;
	for (int i = 0; i < c.size; i++) {
		cin >> c.str[i];
	}
	return cin;

}


