// A C testing library.
// Julian Sniffen, October 2021
//
// void jas_tfail()
// Fail a test with no message.
//
// void jas_tfailf(char *msg, ...);
// Fail a test with a specific message.
//
// void jas_tmain(char *funcs, ...);
// Pass a series of test functions to generate a
// main function that runs each test in order.

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef void(*test_function)(void);
void jas_tfail();
void jas_tfailf_(char *file, int line, char *msg, ...);
void jas_tmain_(int argv, char **args, char *file, char *funcs, ...);

static bool success;
static char error_buffer[512];
static bool error_buffer_clean;

void jas_tfail()
{
	success = false;
}

#define jas_tfailf(msg, ...) jas_tfailf_(__FILE__, __LINE__, msg, __VA_ARGS__)
void jas_tfailf_(char *file, int line, char *msg, ...)
{
	int w; 

	jas_tfail();
	error_buffer_clean = false;

	w = sprintf(error_buffer, "%s:%d: ", file, line);

	va_list ap;
	va_start(ap, msg);
	vsprintf(error_buffer + w, msg, ap);
	va_end(ap);
}

#define jas_tmain(...) void main(int argv, char **args) { jas_tmain_(argv, args, __FILE__, #__VA_ARGS__,  __VA_ARGS__, 0); }
void jas_tmain_(int argv, char **args, char *file, char *funcs, ...)
{
	printf("Running: %s\n", file);

	char buffer[512];
	strcpy(buffer, funcs);
	char *func_name = strtok(buffer, ",");

	va_list ap;
	va_start(ap, funcs);
	test_function func;

	while((func = va_arg(ap, test_function)) != 0) {
		success = true;
		error_buffer_clean = true;

		printf("=== %s: ", func_name);

		func();

		if (success) {
			printf("ok\n");
		} else {
			if (error_buffer_clean) {
				printf("fail\n");
			} else {
				printf("%s\n", error_buffer);
			}
		}

		func_name = strtok(0, " ,");
	}

	va_end(ap);
}
