#include "math.h"
#include "jas_test.h"

void test_abs_positive()
{
	int want, got;
	want = 10;
	got = abs(10);
	if (want != got) {
		jas_tfailf("abs(10) = %d, want %d\n", got, want);
	}
}

void test_abs_negative()
{
	int want, got;
	want = 10;
	got = abs(-10);
	if (want != got) {
		jas_tfailf("abs(10) = %d, want %d\n", got, want);
	}
}

jas_tmain(test_abs_positive, test_abs_negative);
