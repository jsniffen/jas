#include <stdio.h>

#include "jas_slice.h"

int main() {
	int i;

	int *slice = make_slice(int, 10);
	printf("cap: %d\nlen: %d\n", cap(slice), len(slice));

	append(slice, 1);
	append(slice, 2);
	append(slice, 3);
	append(slice, 4);
	append(slice, 5);
	append(slice, 6);
	append(slice, 7);
	append(slice, 8);
	append(slice, 9);
	append(slice, 10);

	for (i = 0; i < len(slice); ++i) {
		printf("%d\n", slice[i]);
	}
	printf("cap: %d\nlen: %d\n", cap(slice), len(slice));

	free_slice(slice);

	printf("%d\n", slice);
	printf("cap: %d\nlen: %d\n", cap(slice), len(slice));

	return 0;
}
