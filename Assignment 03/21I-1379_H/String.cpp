/*
Name :Abubaker
Roll # 21I-1379
Sec:H
*/
#include "pch.h"
#include "String.h"


String::String() {

	arr = NULL;
	length = 0;
}

String::String(const char* str) {

	this->length = 0;
	for (int i = 0; str[i] != '\0'; i++)
		this->length++;
	this->arr = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = str[i];
	this->arr[this->length] = '\0';
}

String::String(const String& c) {

	int counter = 0;
	for (int i = 0; c.arr[i] != '\0'; i++) {
		counter++;
	}
	this->length = counter;
	arr = new char[length + 1];

	for (int i = 0; i <= length; i++) {
		this->arr[i] = '\0';
	}
	for (int i = 0; c.arr[i] != 0; i++) {
		this->arr[i] = c.arr[i];
	}
}

String::String(const string& obj) {

	this->length = 0;
	for (int i = 0; obj[i] != '\0'; i++)
		this->length++;
	this->arr = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = obj[i];
	this->arr[this->length] = '\0';

}

String::String(int x) {

	length = x;
	arr = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->arr[i] = '\0';
	}
}

char& String::operator[](int i) {

	return arr[i];
}

const char String::operator[](int i) const {

	return arr[i];
}

String String:: operator+(const String& str) {

	String obj;
	obj.length = this->length + str.length;
	obj.arr = new char[obj.length + 1];
	for (int i = 0; i < obj.length + 1; i++) {
		obj.arr[i] = '\0';
	}
	for (int i = 0; i <= obj.length - 1; i++) {
		if (i < this->length)
			obj.arr[i] += this->arr[i];
		else
			obj.arr[i] += str.arr[i - length];

	}

	return obj;
}

String String::operator+(const char& str) {

	String obj;
	obj.length = this->length + 2;
	obj = new char[obj.length];
	for (int i = 0; i < this->length; i++)
		obj.arr[i] = this->arr[i];
	obj[this->length] = str;
	obj[this->length + 1] = '\0';
	return obj;
}

String String::operator+(char*& str) {

	String obj;
	int temp = 0;
	//getting the length of str
	for (int i = 0; str[i] != '\0'; i++)
		temp++;
	obj.length += temp;
	//getting the length of the object calling this operator
	obj.length += this->length;
	//incrementing the space for null char
	obj.length += 1;
	obj.arr = new char[obj.length];
	int counter = 0;
	for (int i = 0; i < this->length; i++)
		obj.arr[counter++] = this->arr[i];
	for (int i = 0; i < temp; i++)
		obj.arr[counter++] = str[i];
	obj.arr[obj.length - 1] = '\0';
	return obj;

}

String String:: operator-(const String& substr)  {

	String obj;
	int startIndex = 0;
	int endIndex = 0;
	for (int i = 0; i < this->length; i++) {
		bool check = true;
		if (substr.arr[0] == this->arr[i]) {
			for (int j = 0; substr.arr[j] != '\0'; j++) {
				if (substr.arr[j] != this->arr[i + j]) {
					check = false;
					break;
				}
			}
			if (check) {
				startIndex = i;
				break;
			}
		}
	}

	int size_of_substr = 0;
	//getting the size of sub string
	for (int i = 0; substr.arr[i] != '\0'; i++)
		size_of_substr++;

	//getting the ending index of substring in main string
	endIndex = startIndex + size_of_substr;
	
	//length of new string
	obj.length = this->length - size_of_substr;
	//decalring the new char array
	obj.arr = new char[obj.length + 1];
	 
	int counter = 0;

	//getting the first half of the string
	for (int i = 0; i < startIndex; i++) {
		obj.arr[counter++] = this->arr[i];
	}

	//getting the second half of the string
	for (int i = endIndex; i < this->length; i++) {
		obj.arr[counter++] = this->arr[i];
	}

	obj.arr[obj.length] = '\0';
	return obj;
}

String String::operator-(const string& substr) {
	String obj;
	int startIndex = 0;
	int endIndex = 0;
	for (int i = 0; i < this->length; i++) {
		bool check = true;
		if (substr[0] == this->arr[i]) {
			for (int j = 0; substr[j] != '\0'; j++) {
				if (substr[j] != this->arr[i + j]) {
					check = false;
					break;
				}
			}
			if (check) {
				startIndex = i;
				break;
			}
		}
	}

	int size_of_substr = 0;
	//getting the size of sub string
	for (int i = 0; substr[i] != '\0'; i++)
		size_of_substr++;

	//getting the ending index of substring in main string
	endIndex = startIndex + size_of_substr;

	//length of new string
	obj.length = this->length - size_of_substr;
	//decalring the new char array
	obj.arr = new char[obj.length + 1];


	int counter = 0;

	//getting the first half of the string
	for (int i = 0; i < startIndex; i++) {
		obj.arr[counter++] = this->arr[i];
	}

	//getting the second half of the string
	for (int i = endIndex; i < this->length; i++) {
		obj.arr[counter++] = this->arr[i];
	}

	obj.arr[obj.length] = '\0';
	return obj;
}


String String::operator=(const String& b) {

	if (this->arr != NULL)
		delete[] this->arr;
	this->length = b.length;
	this->arr = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = b.arr[i];
	this->arr[this->length] = '\0';
	return *this;
}

String String::operator=(char* str) {

	if (this->arr != NULL)
		delete[] this->arr;
	this->length = 0;
	for (int i = 0; str[i] != '\0'; i++)
		this->length++;
	this->arr = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = str[i];
	this->arr[this->length] = '\0';
	return *this;
}

String String::operator=(const string& str) {

	if (this->arr != NULL)
		delete[] this->arr;
	this->length = 0;
	for (int i = 0; str[i] != '\0'; i++)
		this->length++;
	this->arr = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
		this->arr[i] = str[i];
	this->arr[this->length] = '\0';
	return *this;
}

bool  String::operator==(const String& b) const {

	if (this->length == b.length)
		return true;
	return false;

}

bool String::operator==(const string& c) const {

	int counter = 0;
	for (int i = 0; c[i] != '\0'; i++) {
		counter++;
	}
	if (this->length == counter)
		return true;
	return false;
}

bool String::operator==(char* c) const {

	int counter = 0;
	for (int i = 0; c[i] != '\0'; i++) {
		counter++;
	}
	if (this->length == counter)
		return true;
	return false;

}

bool String::operator!() {

	if (length == 0)
		return true;
	return false;
}

int String:: operator()(char c) const {

	for (int i = 0; i <= length; i++) {
		if (this->arr[i] == c)
			return i;
	}

}

int String::operator()(const String& str) const {

	for (int i = 0; i < this->length; i++) {
		bool check = true;
		if (str.arr[0] == this->arr[i]) {
			for (int j = 0; str.arr[j] != '\0'; j++) {
				if (str.arr[j] != this->arr[i + j]) {
					check = false;
					break;
				}
			}
			if (check) {
				return i;
			}
		}
	}
	return -1;
	
}


int String::operator()(const string& str) const {

	for (int i = 0; i < this->length; i++) {
		bool check = true;
		if (str[0] == this->arr[i]) {
			for (int j = 0; str[j] != '\0'; j++) {
				if (str[j] != this->arr[i + j]) {
					check = false;
					break;
				}
			}
			if (check) {
				return i;
			}
		}
	}
	return -1;
	
}

int String::operator()(char* str) const {

	for (int i = 0; i < this->length; i++) {
		bool check = true;
		if (str[0] == this->arr[i]) {
			for (int j = 0; str[j] != '\0'; j++) {
				if (str[j] != this->arr[i + j]) {
					check = false;
					break;
				}
			}
			if (check) {
				return i;
			}	
		}
	}
	return -1;

}

String::operator int()const {

	return this->length;

}


String::~String() {

	delete[] arr;
}

ostream& operator<<(ostream& output, const String& b) {

	output << "Length : " << b.length << endl;
	for (int i = 0; i <= b.length; i++) {
		output << b.arr[i];
	}
	return output;
}

istream& operator>>(istream& input, String& c) {

	input >> c.length;
	for (int i = 0; i <= c.length; i++) {
		input >> c.arr[i];
	}
	return input;
}

