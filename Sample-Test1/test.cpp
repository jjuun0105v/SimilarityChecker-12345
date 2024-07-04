#include "pch.h"
#include <string>
#include "../Project10/similar.cpp"

using namespace std;

TEST(TestCaseName, TestName) {
	SimilarityChecker checker;
	const char* input1 = "ASD";
	const char* input2 = "DSA";

	int ret = checker.checkLength(input1, input2);
	
	EXPECT_EQ(60, ret);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName2) {

	SimilarityChecker checker;
	const char* input1 = "A";
	const char* input2 = "BB";


	int ret = checker.checkLength(input1, input2);

	EXPECT_EQ(0, ret);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName3) {

	SimilarityChecker checker;
	const char* input1 = "AAABB";
	const char* input2 = "BAA";


	int ret = checker.checkLength(input1, input2);

	EXPECT_EQ(20, ret);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName4) {
	SimilarityChecker checker;
	const char* input1 = "AA";
	const char* input2 = "AAE";

	int ret = checker.checkLength(input1, input2);

	EXPECT_EQ(30, ret);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, AlphabetCheck1) {
	SimilarityChecker checker;
	const char* input1 = "ASD";
	const char* input2 = "DSA";

	int ret = checker.checkAlphabet(input1, input2);

	EXPECT_EQ(40, ret);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, AlphabetCheck2) {
	SimilarityChecker checker;
	const char* input1 = "A";
	const char* input2 = "BB";

	int ret = checker.checkAlphabet(input1, input2);

	EXPECT_EQ(0, ret);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, AlphabetCheck3) {
	SimilarityChecker checker;
	const char* input1 = "AAABB";
	const char* input2 = "BA";

	int ret = checker.checkAlphabet(input1, input2);

	EXPECT_EQ(40, ret);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, AlphabetCheck4) {
	SimilarityChecker checker;
	const char* input1 = "AA";
	const char* input2 = "AAE";

	int ret = checker.checkAlphabet(input1, input2);

	EXPECT_EQ(20, ret);
	EXPECT_TRUE(true);
}
