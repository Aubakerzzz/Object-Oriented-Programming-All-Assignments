#pragma once

struct Car {

	int petrolLevel;

	Car();
	Car(int petrolLevel);
	void setPetrolLevel(int petrolLevel);
	int getPetrolLevel();
	bool MoveCar(int distanceKM);
	void Refill();
	bool isEmpty();
};


