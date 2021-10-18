#include <stdio.h>

#include "jas_string.h"

int main()
{
	char *s = make_string("hello, world\n");
	printf(s);
	printf("cap: %d\nlen: %d\n", cap(s), len(s));

	reverse(s);

	printf(s);
	return 0;
}
