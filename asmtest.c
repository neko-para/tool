#define _ASM_USE_GAS_
#if !defined(_ASM_USE_X86_) && !defined(_ASM_USE_X64_)
#define _ASM_USE_X86_
#endif

#include "asmcall.h"
#include <stdio.h>

void func(int t) {
	printf("%d\n", t);
}

int main() {
	void (*p)(int) = func;
	int t = 4;
	callf((void*)func, 1, (void**)&t);
	callf((void*)func, 1, (void**)&t);
	callf((void*)func, 1, (void**)&t);
	callf((void*)func, 1, (void**)&t);
}