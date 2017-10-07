#define _ASM_USE_GAS_
#define _ASM_USE_X86_

#include "asmcall.h"

void* callf(void* proc, unsigned long cnt, void** params) {
	void* ret;
	asm volatile (
		"movl %2, %%ecx;"
		"movl %3, %%edx;"
		"callf_loop:"
		"pushl (%%edx);"
		"addl $4, %%edx;"
		"loop callf_loop;"
		"movl %1, %%eax;"
		"call *%%eax;"
		"movl %%eax, %0;"
		"movl %2, %%eax;"
		"shll $2, %%eax;"
		"addl %%eax, %%esp;"
		: "=m" (ret)
		: "m" (proc), "m" (cnt), "m" (params)
		: "%eax", "%ecx", "%edx"
	);
	return ret;
}