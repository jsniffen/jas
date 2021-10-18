#include "jas_math.h"
#include "jas_test.h"

void test_jas_abs_positive()
{
	int want, got;
	want = 10;
	got = jas_abs(10);
	if (want != got) {
		jas_tfailf("jas_abs(10) = %d, want %d\n", got, want);
	}
}

void test_jas_abs_negative()
{
	int want, got;
	want = 10;
	got = jas_abs(-10);
	if (want != got) {
		jas_tfailf("jas_abs(-10) = %d, want %d\n", got, want);
	}
}

jas_tmain(test_jas_abs_positive, test_jas_abs_negative);
