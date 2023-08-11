#include "pch.h"
#include "CSR.h"
//----------Question #05----------

TEST(Q5, first) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	employees[0].setCSRID(-5);
	employees[2].setHours(-8);
	employees[4].setComplaintsResolved(-100);

	for (int i = 0; i < 7; i++)
	{
		ASSERT_EQ(i + 1, employees[i].getCSRID());
		char name[] = { 'E', 'M', 'P', char(i + 49), '\0' };
		ASSERT_EQ(0, strcmp(name, employees[i].getName()));
		ASSERT_EQ((i + 1) * 5, employees[i].getHours());
		ASSERT_EQ((i + 1) * 2, employees[i].getComplaintsResolved());
	}

}

TEST(Q5, second) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	ASSERT_EQ(employees[3].getCSRID(), getCSR_at(employees, 3).getCSRID());
	ASSERT_EQ(0, strcmp(employees[2].getName(), getCSR_at(employees, 2).getName()));

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	ASSERT_EQ(56, CSR::getTotalCpsResolved());

	ASSERT_EQ(28, static_cast<int>(employees[3].getPayrate()));
	ASSERT_EQ(30, static_cast<int>(employees[5].getPayrate()));
	ASSERT_EQ(26, static_cast<int>(employees[1].getPayrate()));

	ASSERT_EQ(415, static_cast<int>(employees[2].getWage()));
	ASSERT_EQ(736, static_cast<int>(employees[4].getWage()));
	ASSERT_EQ(1093, static_cast<int>(employees[6].getWage()));
}

TEST(Q5, third) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	employees[3].setHours(45);
	employees[5].setHours(90);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByHours(employees);

	ASSERT_EQ(6, employees[0].getCSRID());
	ASSERT_EQ(4, employees[1].getCSRID());
	ASSERT_EQ(7, employees[2].getCSRID());
	ASSERT_EQ(3, employees[4].getCSRID());
	ASSERT_EQ(1, employees[6].getCSRID());

	ASSERT_EQ(90, employees[0].getHours());
	ASSERT_EQ(45, employees[1].getHours());
	ASSERT_EQ(35, employees[2].getHours());
	ASSERT_EQ(15, employees[4].getHours());
	ASSERT_EQ(5, employees[6].getHours());
}

TEST(Q5, fourth) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	employees[3].setComplaintsResolved(145);
	employees[5].setComplaintsResolved(90);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByComplaintsRes(employees);

	ASSERT_EQ(4, employees[0].getCSRID());
	ASSERT_EQ(6, employees[1].getCSRID());
	ASSERT_EQ(7, employees[2].getCSRID());
	ASSERT_EQ(3, employees[4].getCSRID());
	ASSERT_EQ(1, employees[6].getCSRID());

	ASSERT_EQ(145, employees[0].getComplaintsResolved());
	ASSERT_EQ(90, employees[1].getComplaintsResolved());
	ASSERT_EQ(14, employees[2].getComplaintsResolved());
	ASSERT_EQ(6, employees[4].getComplaintsResolved());
	ASSERT_EQ(2, employees[6].getComplaintsResolved());
}

TEST(Q5, fifth) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		char name[] = { 'E', 'M', 'P', char(i + 49), '\0' };
		employees[i].setCSRID(i + 1);
		employees[i].setName(name);
		employees[i].setHours((i + 1) * 3);
		employees[i].setComplaintsResolved((i + 1) * 5);
	}

	employees[2].setHours(45);
	employees[4].setHours(90);
	employees[0].setHours(25);
	employees[3].setHours(70);
	employees[3].setComplaintsResolved(145);
	employees[5].setComplaintsResolved(90);
	employees[1].setComplaintsResolved(115);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByWages(employees);

	ASSERT_EQ(5, employees[0].getCSRID());
	ASSERT_EQ(4, employees[1].getCSRID());
	ASSERT_EQ(3, employees[2].getCSRID());
	ASSERT_EQ(1, employees[3].getCSRID());
	ASSERT_EQ(2, employees[6].getCSRID());

	ASSERT_EQ(2380, static_cast<int>(employees[0].getWage()));
	ASSERT_EQ(2340, static_cast<int>(employees[1].getWage()));
	ASSERT_EQ(1164, static_cast<int>(employees[2].getWage()));
	ASSERT_EQ(567, static_cast<int>(employees[4].getWage()));
	ASSERT_EQ(190, static_cast<int>(employees[6].getWage()));
}






