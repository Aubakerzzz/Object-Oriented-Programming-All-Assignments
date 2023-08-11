#include "pch.h"
#include "CustomerAccount.h"


//----------Question #04----------

TEST(Q4, first) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
		33333333333333, 850000);

	ASSERT_EQ(0, strcmp("FAST-NU", customers[0]->name));
	ASSERT_EQ(0, strcmp("H-11", customers[0]->address.address));
	ASSERT_EQ(0, strcmp("Islamabad", customers[0]->address.city));
	ASSERT_EQ(0, strcmp("Pakistan", customers[0]->address.state));
	ASSERT_EQ(44000, customers[0]->address.zip_code);
	ASSERT_EQ(33333333333333, customers[0]->phoneNum);
	ASSERT_EQ(850000, customers[0]->balance);
}

TEST(Q4, second) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	OpenCustomerAccount(customers, accountsOpen, name, address, city,
		state, 44000, 33333333333333, 850000);

	ASSERT_EQ(850000, customers[0]->balance);

	char account[] = "PK001";
	ASSERT_EQ(0, SearchCustomer(customers, accountsOpen, account));

	char nname[] = "FAST-NU1";
	OpenCustomerAccount(customers, accountsOpen, nname,
		address, city, state, 44100, 33333333333344, 950000);

	char accountID[] = "PK002";
	int index = SearchCustomer(customers, accountsOpen, accountID);

	ASSERT_EQ(0, strcmp("FAST-NU1", customers[index]->name));
	ASSERT_EQ(950000, customers[index]->balance);
	ASSERT_EQ(44100, customers[index]->address.zip_code);

	char fakeaccount[] = "PK101";
	ASSERT_EQ(-1, SearchCustomer(customers, accountsOpen, fakeaccount));
}

TEST(Q4, third) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	for (int i = 0; i < 500; i++)
		OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
			33333333333333, 850000);

	char fakeAccount[] = "PK449";	
	char validAccount[] = "PK001";
	ASSERT_EQ(-1, SearchCustomer(customers, accountsOpen, fakeAccount));
	ASSERT_LT(-1, SearchCustomer(customers, accountsOpen, validAccount));
}

TEST(Q4, fourth) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
		33333333333333, 850000);

	char nname[] = "FAST-NU1";
	OpenCustomerAccount(customers, accountsOpen, nname,
		address, city, state, 44100, 33333333333344, 850000);

	char account[] = "PK001";
	char fakeaccount[] = "PK500";

	int index = SearchCustomer(customers, accountsOpen, account);

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, account, static_cast<long long>(55555555555555)));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, static_cast<long long>(55555555555555)));

	ASSERT_EQ(55555555555555, customers[index]->phoneNum);

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, account, static_cast<float>(550000)));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, static_cast<float>(550000)));

	ASSERT_EQ(static_cast<float>(550000), customers[index]->balance);

	Address add;

	char tempAddress[] = "NUCES";
	add.address = tempAddress;

	char tempCity[] = "Karachi";
	add.city = tempCity;

	char tempState[] = "Pakistan";
	add.state = tempState;

	add.zip_code = 75600;

	char accountID[] = "PK002";

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, accountID, add));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, add));
	
	int newIndex = SearchCustomer(customers, accountsOpen, accountID);
	
	ASSERT_EQ(0, strcmp(add.address, customers[newIndex]->address.address));
	ASSERT_EQ(0, strcmp(add.city, customers[newIndex]->address.city));
	ASSERT_EQ(0, strcmp(add.state, customers[newIndex]->address.state));
	ASSERT_EQ(add.zip_code, customers[newIndex]->address.zip_code);

}
