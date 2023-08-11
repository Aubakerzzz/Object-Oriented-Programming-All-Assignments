#include "pch.h"
#include "String.h"


TEST(Q6, first) {

	char st[] = "OOP-A02";
	String str(st);
	char* data = str.getdata();
	ASSERT_EQ(0, strcmp("OOP-A02", data));

	String str1(5);
	ASSERT_EQ(5, str1.strLength());
	ASSERT_EQ(0, strcmp("", str1.getdata()));
	String str2(str);
	ASSERT_EQ(0, strcmp(str2.getdata(), str.getdata()));
	ASSERT_NE(str2.getdata(), str.getdata());

}


TEST(Q6, second) {
	char st[] = "OOP-A02";
	String str(st);
	ASSERT_EQ(7, str.strLength());
	ASSERT_EQ(false, str.empty());
	str.clear();
	ASSERT_EQ(0, str.strLength());
	ASSERT_EQ(true, str.empty());

	//checking for validation in clear function
	str.clear();
	ASSERT_EQ(NULL, str.getdata());
}

TEST(Q6, third) {
	char st[] = "OOP-Assignment02";
	String str(st);
	ASSERT_EQ(0, str.charAt('O'));
	ASSERT_EQ(2, str.charAt('P'));
	ASSERT_EQ(5, str.charAt('s'));
	ASSERT_EQ(14, str.charAt('0'));

	char st1[] = "Spring 2022";
	String str1(st1);
	ASSERT_EQ(3, str1.charAt('i'));
	ASSERT_EQ(1, str1.charAt('p'));
	ASSERT_EQ(5, str1.charAt('g'));
	ASSERT_EQ(6, str1.charAt(' '));
	ASSERT_EQ(7, str1.charAt('2'));
	ASSERT_EQ(8, str1.charAt('0'));
}

TEST(Q6, fourth) {
	char st[] = "OOP-Assignment02";
	String str(st);

	char t1[] = "OOP", t2[] = "Assignment02", t3[] = "oop assignment02", t4[] = "OOP-Assignment02";
	ASSERT_EQ(false, str.equals(t1));
	ASSERT_EQ(false, str.equals(t2));
	ASSERT_EQ(false, str.equals(t3));
	ASSERT_EQ(true, str.equals(t4));

	char st1[] = "Spring 2022";
	String str1(st1);

	char t11[] = "spring 2022", t12[] = "sprIng 2021", t13[] = "Spring 2022";
	ASSERT_EQ(false, str1.equals(t11));
	ASSERT_EQ(false, str1.equals(t12));
	ASSERT_EQ(true, str1.equals(t13));
}

TEST(Q6, fifth) {
	char st[] = "Awesome";
	String str(st);
	char t1[] = "awesome", t2[] = "aweSoMe", t3[] = "aews", t4[] = "AWESOME";
	ASSERT_EQ(true, str.equalsIgnoreCase(t1));
	ASSERT_EQ(true, str.equalsIgnoreCase(t2));
	ASSERT_EQ(false, str.equalsIgnoreCase(t3));
	ASSERT_EQ(true, str.equalsIgnoreCase(t4));
}

TEST(Q6, sixth) {
	char st[] = "OOP-Assignment02";
	String str1(st);
	char t1[] = "oop assignment02", t2[] = "oop-assignment02", t3[] = "oOp-asSignMent02", t4[] = "OOP-AssignmentO2";
	ASSERT_EQ(false, str1.equalsIgnoreCase(t1));
	ASSERT_EQ(true, str1.equalsIgnoreCase(t2));
	ASSERT_EQ(true, str1.equalsIgnoreCase(t3));
	ASSERT_EQ(false, str1.equalsIgnoreCase(t4));

	char st1[] = "SpriNg 2022";
	String str2(st1);
	char t11[] = "spring 2022", t12[] = "sprIng 2021", t13[] = "SprIng 2O22", t14[] = "SPRING 2022";
	ASSERT_EQ(true, str2.equalsIgnoreCase(t11));
	ASSERT_EQ(false, str2.equalsIgnoreCase(t12));
	ASSERT_EQ(false, str2.equalsIgnoreCase(t13));
	ASSERT_EQ(true, str2.equalsIgnoreCase(t14));
}

TEST(Q6, seventh) {
	char st[] = "OOP-Assignment02";
	String str(st);
	char t1[] = "Ass", t2[] = "Ass", t3[] = "nm", t4[] = "-";
	ASSERT_EQ(0, strcmp(str.substring(t1, 2), "Assignment02"));
	ASSERT_EQ(NULL, str.substring(t2, 5));
	ASSERT_EQ(0, strcmp(str.substring(t3, 2), "nment02"));
	ASSERT_EQ(0, strcmp(str.substring(t4, 2), "-Assignment02"));
}

TEST(Q6, eighth) {
	char st[] = "SpriNg 2022";
	String str(st);
	char* originalString = str.getdata();
	char t1[] = "iN";
	char* subString = str.substring(t1, 2);

	ASSERT_EQ(0, strcmp(subString, "iNg 2022"));
	ASSERT_NE(originalString + 3, subString);
}

TEST(Q6, ninth) {
	char st[] = "OOP-Assignment02";
	String str(st);

	char t1[] = "Ass", t2[] = "-", t3[] = "A";
	ASSERT_EQ(0, strcmp(str.substring(t1, 2, 10), "Assignm"));
	ASSERT_EQ(NULL, str.substring(t1, 5, 4));
	ASSERT_EQ(0, strcmp(str.substring(t2, 2, 9), "-Assign"));
	ASSERT_EQ(0, strcmp(str.substring(t3, 2, 30), "Assignment02"));
}

TEST(Q6, tenth) {
	char st[] = "SpriNg 2022";
	String str(st);
	char* originalString = str.getdata();

	char t1[] = "iN";
	char* subString = str.substring(t1, 2, 8);

	ASSERT_EQ(0, strcmp(subString, "iNg 20"));
	ASSERT_NE(originalString + 3, subString);
}


