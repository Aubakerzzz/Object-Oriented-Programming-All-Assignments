#include "pch.h"
#include "CustomerAccount.h"
#include<iostream>
using namespace std;

Address::Address() {
	address = new char[50];
	city = new char[50];
	state = new char[50];
	zip_code = 0;
	for (int i = 0; i < 50; i++) {
		address[i] = '\0';
		city[i] = '\0';
		state[i] = '\0';
	}
}

CustomerAccount::CustomerAccount() {
	name = new char[50];
	accountNum = new char[50];
	phoneNum = 0;
	balance = 0.0;
	for (int i = 0; i < 50; i++) {
		name[i] = '\0';
		accountNum[i] = '\0';
	}
}

void OpenCustomerAccount(CustomerAccount* customers[], int& accountsOpen,
	char* NameVal, char* addVal, char* cityVal, char* stateVal, int zipcodeVal, long long
	phoneVal, float balanceVal) {

	if (accountsOpen >= 100)
		return;

	customers[accountsOpen] = new CustomerAccount();

	for (int i = 0; NameVal[i] != '\0'; i++) {
		customers[accountsOpen]->name[i] = NameVal[i];
	}

	for (int i = 0; addVal[i] != '\0'; i++) {
		customers[accountsOpen]->address.address[i] = addVal[i];
	}

	for (int i = 0; cityVal[i] != '\0'; i++) {
		customers[accountsOpen]->address.city[i] = cityVal[i];
	}

	for (int i = 0; stateVal[i] != '\0'; i++) {
		customers[accountsOpen]->address.state[i] = stateVal[i];
	}

	customers[accountsOpen]->address.zip_code = zipcodeVal;

	customers[accountsOpen]->phoneNum = phoneVal;

	customers[accountsOpen]->balance = balanceVal;

	char acc[100][6] = { "PK001","PK002","PK003","PK004","PK005","PK006","PK007","PK008","PK009","PK010",
						"PK011","PK012","PK013","PK014","PK015","PK016","PK017","PK018","PK019","PK020",
						"PK021","PK022","PK023","PK024","PK025","PK026","PK027","PK028","PK029","PK030",
						"PK031","PK032","PK033","PK034","PK035","PK036","PK037","PK038","PK039","PK040",
						"PK041","PK042","PK043","PK044","PK045","PK046","PK047","PK048","PK049","PK050",
						"PK051","PK052","PK053","PK054","PK055","PK056","PK057","PK058","PK059","PK060",
						"PK061","PK062","PK063","PK064","PK065","PK066","PK067","PK068","PK069","PK070",
						"PK071","PK072","PK073","PK074","PK075","PK076","PK077","PK078","PK079","PK080",
						"PK081","PK082","PK083","PK084","PK085","PK086","PK087","PK088","PK089","PK090",
						"PK091","PK092","PK093","PK094","PK095","PK096","PK097","PK098","PK099","PK100" };

	for (int i = 0; i < 6; i++) {
		customers[accountsOpen]->accountNum[i] = acc[accountsOpen][i];
	}
	accountsOpen++;
}

int SearchCustomer(CustomerAccount* customers[], int accountsOpen, char*
	accountNum) {

	for (int i = 0; i < accountsOpen; i++) {
		bool check = true;
		for (int j = 0; j < 6; j++) {
			if (customers[i]->accountNum[j] != accountNum[j]) {
				check = false;
				break;
			}
		}
		if (check)
			return i;
	}
	return -1;
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char
	* accountNumVal, Address addressVal) {

	int index = SearchCustomer(customers, accountsOpen, accountNumVal);
	if (index != -1) {
		customers[index]->address.zip_code = addressVal.zip_code;
		delete[] customers[index]->address.address;
		delete[] customers[index]->address.city;
		delete[] customers[index]->address.state;

		customers[index]->address.address = new char[50];
		customers[index]->address.city = new char[50];
		customers[index]->address.state = new char[50];

		for (int i = 0; i < 50; i++) {
			customers[index]->address.address[i] = '\0';
			customers[index]->address.city[i] = '\0';
			customers[index]->address.state[i] = '\0';
		}

		for (int i = 0; addressVal.address[i] != '\0'; i++) {
			customers[index]->address.address[i] = addressVal.address[i];
		}

		for (int i = 0; addressVal.city[i] != '\0'; i++) {
			customers[index]->address.city[i] = addressVal.city[i];
		}

		for (int i = 0; addressVal.state[i] != '\0'; i++) {
			customers[index]->address.state[i] = addressVal.state[i];
		}
		return true;
	}
	return false;
}

bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen,
	char* accountNumVal, long long phoneVal) {

	int index = SearchCustomer(customers, accountsOpen, accountNumVal);
	if (index != -1) {
		customers[index]->phoneNum = phoneVal;
		return true;
	}
	return false;
		
}
bool UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char
	* accountNumVal, float balanceVal) {

	int index = SearchCustomer(customers, accountsOpen, accountNumVal);
	if (index != -1) {
		customers[index]->balance = balanceVal;
		return true;
	}
	return false;
}

void DisplayAllCustomers(CustomerAccount* customers[], int accountsOpen) {

	for (int i = 0; i < accountsOpen; i++) {
		cout << customers[i]->accountNum << endl;
		cout << customers[i]->address.address << endl;
		cout << customers[i]->balance << endl;
		cout << customers[i]->name << endl;
		cout << customers[i]->phoneNum << endl;
		cout << customers[i]->address.city << endl;
		cout << customers[i]->address.state << endl;
		cout << customers[i]->address.zip_code << endl;
		
	}

}

