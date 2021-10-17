// A slice library.
// Julian Sniffen, October 2021

#include <stdlib.h>

typedef struct {
	int cap;
	int len;
} slice_header;

#define make_slice(type, cap) (type *)make_slice_(sizeof(type), cap)
void *make_slice_(size_t size, int cap)
{
	slice_header *header = malloc(size*cap + sizeof(slice_header));

	header->cap = cap;
	header->len = 0;
	++header;

	return (void *)header;
}

#define append(slice, data) (slice[len(slice)] = data, setlen(slice, len(slice)+1))
#define free_slice(s) (free_slice_(slice), s=0)
void free_slice_(void *slice)
{
	slice_header *header = (slice_header *)slice;
	--header;
	free(header);
	slice = 0;
}

int setlen(void *slice, int len)
{
	slice_header *header = (slice_header *)slice;
	--header;
	return header->len = len;
}

int len(void *slice)
{
	slice_header *header = (slice_header *)slice;
	--header;
	return header->len;
}

int cap(void *slice)
{
	slice_header *header = (slice_header *)slice;
	--header;
	return header->cap;
}

int setcap(void *slice, int cap)
{
	slice_header *header = (slice_header *)slice;
	--header;
	return header->cap = cap;
}
