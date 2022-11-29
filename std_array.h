#include <stdlib.h>

typedef struct {
	int len;
	int cap;
} std_array_header;

#define std_array_make(type, cap) (type *)std_array_make_(sizeof(type), cap)
void *std_array_make_(size_t size, int cap)
{
	std_array_header *header = malloc(size*cap + sizeof(std_array_header));

	header->cap = cap;
	header->len = 0;

	++header;

	return (void *)header;
}

#define std_array_push(array, data) \
	if (std_array_resize(array, sizeof(data))) { \
		array[std_array_len(array)] = data; \
		std_array_set_len(array, std_array_len(array)+1); \
	}

int std_array_cap(void *array)
{
	std_array_header *header = (std_array_header *)array;
	--header;
	return header->cap;
}

int std_array_len(void *array)
{
	std_array_header *header = (std_array_header *)array;
	--header;
	return header->len;
}

void std_array_set_len(void *array, int len)
{
	std_array_header *header = (std_array_header *)array;
	--header;
	header->len = len;
}

void *std_array_resize(void *array, size_t size)
{
	std_array_header *header = (std_array_header *)array;
	--header;
	if (header->len == header->cap) {
		void *result = (void *)realloc(header, header->cap*2*size + sizeof(std_array_header));
		if (result) {
			header->cap *= 2;
		}
		return result;
	}
	return (void *)header;
}

