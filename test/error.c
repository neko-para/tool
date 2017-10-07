#define _ASM_USE_X64_
#define _ASM_USE_GAS_

#include "asm.h"
#include <stdio.h>
#include <stdarg.h>

void print(int i, ...) {
	va_list list;
	va_start(list, i);
	while (i--) {
		unsigned long x = va_arg(list, unsigned long);
		printf("%lu ", x);
	}
	va_end(list);
}

int main() {
	callf((void*)print, 4, 3, 7, 2, 9);
}