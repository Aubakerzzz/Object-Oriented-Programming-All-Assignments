#pragma once

struct Address {
	char* address;
	char* city;
	char* state;
	int zip_code;

	Address();
};
struct CustomerAccount {
	char* name;
	Address address;
	long long phoneNum;
	float balance;
	char* accountNum;

	CustomerAccount();
};

void OpenCustomerAccount(CustomerAccount* customers[], int& accountsOpen,
	char* NameVal, char* addVal, char* cityVal, char* stateVal, int zipcodeVal, long long
	phoneVal, float balanceVal);

int SearchCustomer(CustomerAccount* customers[], int accountsOpen, char*
	accountNum);

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char
	* accountNumVal, Address addressVal);

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen,
	char* accountNumVal, long long phoneVal);

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char*
	accountNumVal, float balanceVal);

void DisplayAllCustomers(CustomerAccount* customers[], int accountsOpen);

