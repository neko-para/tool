#if !defined(_ASM_USE_X86_) && !defined(_ASM_USE_X64_)
#define _ASM_USE_X86_
#endif

#include "../callf/callf.h"
#include <stdio.h>

void func(int t, int x) {
	printf("%d %d\n", t, x);
}

int main() {
	unsigned long val[] = {2, 3};
	callf((void*)func, 2, 4, 6);
	callfv((void*)func, 2, (void**)val);
}