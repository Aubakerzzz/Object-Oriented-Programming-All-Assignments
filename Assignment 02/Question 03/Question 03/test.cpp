#include "pch.h"
#include "Sandwich.h"



//----------Question #03----------

TEST(Q3, first) {
	Sandwich S;

	ASSERT_EQ(NULL, S.getName());
	ASSERT_EQ(NULL, S.getFilling());
	ASSERT_EQ(NULL, S.getSize());
	ASSERT_EQ(0.0, S.getPrice());
	ASSERT_FALSE(S.check_status());

	char filling[] = "Sauce";
	char name[] = "Zinger";
	char size[] = "medium";

	Sandwich S2(filling, 800);
	S2.setName(name);
	S2.setSize(size);

	ASSERT_EQ(0, strcmp(name, S2.getName()));
	ASSERT_EQ(0, strcmp(filling, S2.getFilling()));
	ASSERT_EQ(0, strcmp(size, S2.getSize()));
	ASSERT_EQ(800.0, S2.getPrice());
}

TEST(Q3, second) {
	char filling[] = "Sauce";
	char name[] = "Zinger";
	char size[] = "large";
	Sandwich S(filling, 1000, name,
		size, true);

	ASSERT_EQ(0, strcmp("Zinger", S.getName()));
	ASSERT_EQ(0, strcmp("Sauce", S.getFilling()));
	ASSERT_EQ(0, strcmp("large", S.getSize()));
	ASSERT_EQ(1000.0, S.getPrice());
	ASSERT_TRUE(S.check_status());

	Sandwich S2(S);

	char nfilling[] = "Mayonnaise";
	S2.setFilling(nfilling);

	ASSERT_EQ(0, strcmp("Zinger", S2.getName()));
	ASSERT_EQ(0, strcmp("Mayonnaise", S2.getFilling()));
	ASSERT_EQ(0, strcmp("large", S2.getSize()));
	ASSERT_EQ(1000.0, S2.getPrice());
	ASSERT_TRUE(S2.check_status());

	ASSERT_EQ(0, strcmp("Sauce", S.getFilling()));
}

TEST(Q3, third) {
	Sandwich S;

	char filling[] = "sauce";
	char name[] = "zinger";
	char size[] = "big";

	S.setName(name);
	S.setFilling(filling);
	S.setSize(size);
	S.setPrice(1200);

	//because size can only be small, medium or large
	ASSERT_EQ(NULL, S.getSize());

	char nsize[] = "large";
	S.setSize(nsize);

	ASSERT_FALSE(S.check_status());

	S.makeSandwich();

	ASSERT_EQ(0, strcmp("zinger", S.getName()));
	ASSERT_EQ(0, strcmp("sauce", S.getFilling()));
	ASSERT_EQ(0, strcmp("large", S.getSize()));
	ASSERT_EQ(1200.0, S.getPrice());
	ASSERT_TRUE(S.check_status());
}
