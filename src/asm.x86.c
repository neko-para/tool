#include "callf.h"

void* callfv(void* proc, unsigned long cnt, void** params) {
	void* ret;
	__asm__ volatile (
		"movl %2, %%ecx;"
		"movl %3, %%edx;"
		"movl %%ecx, %%eax;"
		"decl %%eax;"
		"shll $2, %%eax;"
		"addl %%eax, %%edx;"
		"callf_loop:"
		"pushl (%%edx);"
		"subl $4, %%edx;"
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