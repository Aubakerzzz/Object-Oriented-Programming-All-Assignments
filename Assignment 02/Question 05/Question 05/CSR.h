#pragma once
#include <iostream>
using namespace std;

class CSR {
private:
	int csrlD;
	char* csrName;
	int hours;
	int complaintsResolved;
	float payrate;
	float wage;
	static int totalComplaintsResolved;

public:

	CSR();
	int getCSRID();
	char* getName();
	int getHours();
	int getComplaintsResolved();
	float getPayrate();
	float getWage();
	void setCSRID(int ID);
	void setName(char* n);
	void setHours(int hours);
	void setComplaintsResolved(int cpsResolved);
	static void setTotalCpsResolved(int totalCpsResolved);
	void calcPayrate();
	void calcWage();
	static int getTotalCpsResolved();
	void temps(const CSR& a);
};

CSR getCSR_at(CSR employees[7], int index);
void calcTotalComplaints(CSR employees[7]);
void calcAllEmployeeWages(CSR employees[7]);
void SortByHours(CSR employees[7]);
void SortByComplaintsRes(CSR employees[7]);
void SortByWages(CSR employees[7]);



