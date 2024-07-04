#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a < b ? b : a)
#define abs(x) ((x < 0) ? (-x) : (x))
#define LENGTH_CHECK_MAX_VALUE 60
#define ALPHABET_CHECK_MAX_VALUE 40
#define TOTAL_ALPHABET_CNT 26

class SimilarityChecker
{
public:
	SimilarityChecker()
	{
		// initialize
		for (int alphabet_index = 0; alphabet_index < TOTAL_ALPHABET_CNT; alphabet_index++)
		{
			alphabetCheck[alphabet_index] = 0;
			alphabetCheck2[alphabet_index] = 0;
		}
	}

	int checkLength(const char *input1, const char *input2)
	{
		int intput1_length = strlen(input1);
		int intput2_length = strlen(input2);

		if (intput1_length == intput2_length) return LENGTH_CHECK_MAX_VALUE;

		int min_length_value = min(intput1_length, intput2_length);
		int max_length_value = max(intput1_length, intput2_length);

		if (max_length_value >= (min_length_value * 2)) return 0;

		double double_value = ((double)(max_length_value - min_length_value) / (double)(min_length_value));

		return (1 - double_value) * LENGTH_CHECK_MAX_VALUE;
	}

	// same alphabet count / used alphabet total count
	int checkAlphabet(const char* input1, const char* input2)
	{
		int intput1_length = strlen(input1);
		int intput2_length = strlen(input2);

		int same_alphabet_cnt = 0;
		int used_alphabet_cnt = 0;
		for (int alphabet_index = 0; alphabet_index < intput1_length; alphabet_index++)
		{
			alphabetCheck[input1[alphabet_index] - 'A']++;
		}

		for (int alphabet_index = 0; alphabet_index < intput2_length; alphabet_index++)
		{
			alphabetCheck2[input2[alphabet_index] - 'A']++;
		}

		for (int alphabet_index = 0; alphabet_index < TOTAL_ALPHABET_CNT; alphabet_index++)
		{
			if (alphabetCheck[alphabet_index] >= 1 || alphabetCheck2[alphabet_index] >= 1) used_alphabet_cnt++;
			if (alphabetCheck[alphabet_index] >= 1 && alphabetCheck2[alphabet_index] >= 1) same_alphabet_cnt++;
		}

		double rate = ((double)same_alphabet_cnt / (double)used_alphabet_cnt);

		return rate * ALPHABET_CHECK_MAX_VALUE;
	}

private:
	int alphabetCheck[TOTAL_ALPHABET_CNT];
	int alphabetCheck2[TOTAL_ALPHABET_CNT];

};