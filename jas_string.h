// A c string library.
// Julian Sniffen, October 2021

#include <stdlib.h>

typedef struct {
	int cap;
	int len;
} string_header;

char *make_string(char *s)
{
	int i, len = 0;
	char *c = 0;

	c = s;
	while (*c++ != '\0') ++len;

	string_header *header = malloc(len*sizeof(char) + sizeof(string_header));

	header->cap = len;
	header->len = len;
	++header;

	c = (char *)header;
	for (i = 0; i < len; ++i) {
		*c++ = *s++;
	}

	return (char *)header;
}

int len(char *s)
{
	string_header *h = (string_header *)s;
	--h;
	return h->len;
}

int cap(char *s)
{
	string_header *h = (string_header *)s;
	--h;
	return h->cap;
}

void reverse(char *s)
{
	int i, j;
	char temp;

	for (i = 0; i < len(s)/2; ++i) {
		j = len(s) - i - 1;
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
