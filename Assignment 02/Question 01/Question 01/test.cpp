#include "pch.h"
#include "Car.h"

//----------Question #01----------

TEST(Q1, first) {
	Car car;
	car.setPetrolLevel(25);
	car.setPetrolLevel(50);
	car.setPetrolLevel(-5);
	ASSERT_EQ(25, car.getPetrolLevel());
}

TEST(Q1, second) {
	Car car(40);
	ASSERT_EQ(false, car.isEmpty());
}

TEST(Q1, third) {
	Car car;
	car.Refill();
	ASSERT_EQ(45, car.petrolLevel);
}

TEST(Q1, fourth) {
	Car car;
	car.Refill();
	ASSERT_EQ(false, car.MoveCar(50));
	ASSERT_EQ(true, car.MoveCar(33));
	ASSERT_EQ(12, car.petrolLevel);
}
