#include <stdio.h>

extern "C" void print(unsigned long p) {
	printf("%lu\n", p);
}