#include "pch.h"
#include "Sandwich.h"

Sandwich::Sandwich() {
	name = NULL;
	filling = NULL;
	size = NULL;
	is_ready = false;
	price = 0.0;
}
Sandwich::Sandwich(char* fillingVal, double priceVal) {
	name = NULL;
	filling = new char[50];
	int count = 0;
	for (int i = 0; fillingVal[i] != '\0'; i++) {
		filling[i] = fillingVal[i];
		count++;
	}
	filling[count] = '\0';
	price = priceVal;
	size = NULL;
	is_ready = false;
}
Sandwich::Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status) {
	int count = 0;
	name = new char[50];
	for (int i = 0; nameVal[i] != '\0'; i++) {
		name[i] = nameVal[i];
		count++;
	}
	name[count] = '\0';
	count = 0;
	filling = new char[50];
	for (int i = 0; fillingVal[i] != '\0'; i++) {
		filling[i] = fillingVal[i];
		count++;
	}
	filling[count] = '\0';
	count = 0;
	size = new char[50];
	for (int i = 0; sizeVal[i] != '\0'; i++) {
		size[i] = sizeVal[i];
		count++;
	}
	size[count] = '\0';
	is_ready = ready_status;
	price = priceVal;
}
Sandwich::Sandwich(const Sandwich& sandwich) {
	int count = 0;
	name = new char[50];
	for (int i = 0; sandwich.name[i] != '\0'; i++) {
		name[i] = sandwich.name[i];
		count++;
	}
	name[count] = '\0';
	count = 0;
	filling = new char[50];
	for (int i = 0; sandwich.filling[i] != '\0'; i++) {
		filling[i] = sandwich.filling[i];
		count++;
	}
	filling[count] = '\0';
	count = 0;
	size = new char[50];
	for (int i = 0; sandwich.size[i] != '\0'; i++) {
		size[i] = sandwich.size[i];
		count++;
	}
	size[count] = '\0';
	is_ready = sandwich.is_ready;
	price = sandwich.price;
}
void Sandwich::setFilling(char* fillingVal) {
	if (filling == NULL) {
		int count = 0;
		filling = new char[50];
		for (int i = 0; fillingVal[i] != '\0'; i++) {
			filling[i] = fillingVal[i];
			count++;
		}
		filling[count] = '\0';
	}
	else {
		delete[] filling;
		int count = 0;
		filling = new char[50];
		for (int i = 0; fillingVal[i] != '\0'; i++) {
			filling[i] = fillingVal[i];
			count++;
		}
		filling[count] = '\0';
	}
}
void Sandwich::setPrice(double priceVal) {
	price = priceVal;
}
void Sandwich::setName(char* nameVal) {
	if (name == NULL) {
		int count = 0;
		name = new char[50];
		for (int i = 0; nameVal[i] != '\0'; i++) {
			name[i] = nameVal[i];
			count++;
		}
		name[count] = '\0';
	}
	else {
		delete[] name;
		int count = 0;
		name = new char[50];
		for (int i = 0; nameVal[i] != '\0'; i++) {
			name[i] = nameVal[i];
			count++;
		}
		name[count] = '\0';
	}
}
bool Sandwich::isSmall(char* str) {
	char size[] = "small";
	for (int i = 0; i < 5; i++) {
		if (str[i] != size[i])
			return false;
	}
	return true;
}

bool Sandwich::isMedium(char* str) {
	char size[] = "medium";
	for (int i = 0; i < 6; i++) {
		if (str[i] != size[i])
			return false;
	}
	return true;
}

bool Sandwich::isLarge(char* str) {
	char size[] = "large";
	for (int i = 0; i < 5; i++) {
		if (str[i] != size[i])
			return false;
	}
	return true;
}

void Sandwich::setSize(char* sizeVal) {

	if (isSmall(sizeVal) || isMedium(sizeVal) || isLarge(sizeVal)) {
		delete[] size;
		size = new char[50];
		int count = 0;
		for (int i = 0; sizeVal[i] != '\0'; i++) {
			size[i] = sizeVal[i];
			count++;
		}
		size[count] = '\0';
	}
}

char* Sandwich::getFilling() {
	return filling;
}

double Sandwich::getPrice() {
	return price;
}

char* Sandwich::getName() {
	return name;
}
char* Sandwich::getSize() {
	return size;
}
void Sandwich::makeSandwich() {
	if (filling != NULL) {
		is_ready = true;
	}
}

bool Sandwich::check_status() {
	return is_ready;
}