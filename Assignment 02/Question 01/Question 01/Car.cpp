#include "pch.h"
#include "Car.h"

Car::Car() {
	this->petrolLevel = 0;
}

Car::Car(int petrolLevel) {
	this->petrolLevel = petrolLevel;
}

void Car::setPetrolLevel(int petrolLevel) {
	if (petrolLevel >= 0 && petrolLevel <= 45) {
		this->petrolLevel = petrolLevel;
	}
}

int Car::getPetrolLevel() {
	return petrolLevel;
}

bool Car::MoveCar(int distanceKM) {
	if (distanceKM > petrolLevel) {
		return false;
	}
	petrolLevel -= distanceKM;
	return true;
}

void Car::Refill() {
	petrolLevel = 45;
}

bool Car::isEmpty() {
	if (petrolLevel == 0) {
		return true;
	}
	return false;
}
