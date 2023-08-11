#include "pch.h"
#include "CSR.h"

int CSR::totalComplaintsResolved = 0;



CSR::CSR() {
	
	csrlD = 0;
	csrName = new char[100];
	hours = 0;
	complaintsResolved = 0;
	payrate = 0;
	wage = 0;
	for (int i = 0; i < 100; i++) {
		csrName[i] = '\0';
	}
}


void CSR::setCSRID(int ID) {
	if(ID > 0)
		csrlD = ID;
}

void CSR::setName(char* n) {
	for (int i = 0; n[i] != '\0'; i++) {
		csrName[i] = n[i];
	}
}

void CSR::setHours(int hours) {
	if (hours > 0) {
		this->hours = hours;
	}
}

void  CSR::setComplaintsResolved(int cpsResolved) {
	
	if (cpsResolved >= 0) {
		complaintsResolved = cpsResolved;
	}
}

void CSR::setTotalCpsResolved(int totalCpsResolved) {
	
	if (totalCpsResolved >= 0) {
		totalComplaintsResolved = totalCpsResolved;
	}
}

void CSR::calcPayrate() {

	payrate = 25 + 25 * ( complaintsResolved / static_cast<float> ( totalComplaintsResolved ));
}

void CSR::calcWage() {
		
	wage = hours * payrate;

}

int CSR::getTotalCpsResolved() {
	
	return totalComplaintsResolved;
}

int CSR::getCSRID() {
	
	return csrlD;
}

char* CSR::getName() {

	return csrName;
	
}

int CSR::getHours() {
	
	return hours;
}

int CSR::getComplaintsResolved() {

	return complaintsResolved;
}

float CSR::getPayrate() {
	
	return payrate;
}

float CSR::getWage() {
	
	return wage;

}



CSR getCSR_at(CSR employees[7], int index) {
	
	return employees[index];
}

void calcTotalComplaints(CSR employees[7]) {
	
	int total = 0;
	for (int i = 0; i < 7; i++) {
		total += employees[i].getComplaintsResolved();
	}
	CSR::setTotalCpsResolved(total);
}

void calcAllEmployeeWages(CSR employees[7]) {
	
	for (int i = 0; i < 7; i++) {
		employees[i].calcPayrate();
		employees[i].calcWage();	
	}

}

void CSR::temps(const CSR &a) {

	this->hours = a.hours;
	this->complaintsResolved = a.complaintsResolved;
	this->payrate = a.payrate;
	this->wage = a.wage;
	this->csrlD = a.csrlD;

	delete[] csrName;
	csrName = new char[100];
	for (int i = 0; i < 100; i++) {
		csrName[i] = '\0';
	}
	for (int j = 0; a.csrName[j] != '\0'; j++) {
		this->csrName[j] = a.csrName[j];
	}

}

void SortByHours(CSR employees[7]) {

	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (employees[i].getHours() < employees[j].getHours()) {
				CSR temp;
				temp.temps(employees[i]);
				employees[i].temps(employees[j]);
				employees[j].temps(temp);
			}

		}
	}
}

void SortByComplaintsRes(CSR employees[7]) {


	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (employees[i].getComplaintsResolved() < employees[j].getComplaintsResolved()) {
				CSR temp;
				temp.temps(employees[i]);
				employees[i].temps(employees[j]);
				employees[j].temps(temp);
			}

		}
	}


}
void SortByWages(CSR employees[7]) {


	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (employees[i].getWage() < employees[j].getWage()) {
				CSR temp;
				temp.temps(employees[i]);
				employees[i].temps(employees[j]);
				employees[j].temps(temp);
			}

		}
	}


}

