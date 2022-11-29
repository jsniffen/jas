#include <std_array.h>
#include <stdio.h>

int main() 
{
	int i, count;
	int *array = std_array_make(int, 100);

	for (i = 0; i < 1000; ++i) {
		std_array_push(array, i+1);
	}

	count = 0;
	for (i = 0; i < std_array_len(array); ++i) {
		count += array[i];
	}

	printf("The count is %d\n", count);
}
