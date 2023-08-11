#include "pch.h"
#include "String.h"
#include<iostream>
using namespace std;


String::String() {

	data = new char[30];
	for (int o = 0; o < 30; o++) {
		data[o] = '\0';
	}
	length = 0;

}

String::String(int size) {

	length = size;
	data = new char[size];

	for (int z = 0; z < size; z++) {
		data[z] = '\0';
	}

}

String::String(char* str) {

	int counter = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		counter++;
	}

	length = counter;

	data = new char[length + 1];

	for (int w = 0; w < length + 1; w++) {
		data[w] = '\0';
	}

	for (int h = 0; str[h] != '\0'; h++) {
		data[h] = str[h];
	}

}

String::String(const String& str) {

	int counter = 0;
	for (int e = 0; str.data[e] != '\0'; e++) {
		counter++;
	}
	this->length = counter;
	data = new char[length + 1];

	for (int s = 0; s <= length; s++) {
		this->data[s] = '\0';
	}

	for (int f = 0; str.data[f] != '\0'; f++) {
		this->data[f] = str.data[f];
	}
}

String::~String() {

	delete[] data;
}

int String::strLength() {

	return length;
}
void String::clear() {

	if (length != 0) {
		length = 0;
		delete[] data;
		data = NULL;
	}
}

bool String::empty() {

	if (length == 0)
		return true;
	return false;
}

int String::charAt(char c) {

	for (int u = 0; u <= length; u++) {
		if (data[u] == c) {
			return u;
		}
	}

}
char* String::getdata() {

	return data;
}

bool String::equals(char* str) {

	int count = 0;

	for (int o = 0; str[o] != 0; o++) {
		count++;
	}

	if (length == count) {
		for (int v = 0; v < length; v++) {
			if (data[v] != str[v])
				return false;
		}
		return true;
	}
	return false;
}

bool String::equalsIgnoreCase(char* str) {
	
	int count = 0;

	for (int o = 0; str[o] != 0; o++) {
		count++;
	}

	if (length == count) {

		for (int y = 0; y < length; y++) {

			if (data[y] >= 65 && data[y] <= 90) {
				if (str[y] >= 65 && str[y] <= 90) {
					if (data[y] != str[y])
						return false;
				}
				else {
					if (data[y] + 32 != str[y]) {
						return false;
					}
				}
			}
			else {
				if (str[y] >= 65 && str[y] <= 90) {
					if (data[y] != str[y] + 32)
						return false;
				}
				else {
					if (data[y] != str[y]) {
						return false;
					}
				}
			}
		}
		return true;
	}
	return false;

}
char* String::substring(char* substr, int startIndex) {
	
	if (startIndex >= this->length)
		return NULL;

	char* arr1 = new char[length + 1];
	for (int i = 0; i <= length; i++) {
		arr1[i] = '\0';
	}
	
	bool check = false;
	int index = 0;
	for (int i = startIndex; i < length; i++) {
		if (data[i] == substr[0]) {
			for (int j = 0; substr[j] != '\0'; j++) {
				if (substr[j] != data[i + j]) {
					break;
				}
			}
			check = true;
			index = i;
			break;
		}
	}

	if (check) {
		int counter = 0;
		for (int i = index; i < length; i++) {
			arr1[counter++] = data[i];
		}
		return arr1;
	}

	return NULL;
}

char*String:: substring(char* substr, int startIndex, int endIndex) {

	if (startIndex >= this->length)
		return NULL;

	if (startIndex > endIndex)
		return NULL;

	char* arr1 = new char[length + 1];
	for (int i = 0; i <= length; i++) {
		arr1[i] = '\0';
	}

	if (endIndex >= length)
		endIndex = length - 1;

	bool check = false;
	int index = 0;
	for (int i = startIndex; i <= endIndex; i++){
		if (data[i] == substr[0]) {
			for (int j = 0; substr[j] != '\0'; j++) {
				if (substr[j] != data[i + j]) {
					break;
				}
			}
			check = true;
			index = i;
			break;
		}
	}

	if (check) {
		int counter = 0;
		for (int i = index; i <= endIndex; i++) {
			arr1[counter++] = data[i];
		}
		return arr1;
	}
	return NULL;
}

void String::print()const {

	if (length == 0)
		cout << "NULL" << endl;

	for (int t = 0; data[t] != '\0'; t++) {
		cout << data[t] << endl;
	}
		
}

