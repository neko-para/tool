#include "asmcall.h"
#include <stdarg.h>
#include <stdlib.h>

void* callf(void* proc, unsigned long cnt, ...) {
	va_list list;
	void** param;
	void* ret;
	unsigned long i;
	va_start(list, cnt);
	param = (void**)calloc(cnt, sizeof(void*));
	for (i = 0; i < cnt; ++i) {
		param[i] = va_arg(list, void*);
	}
	ret = callfv(proc, cnt, param);
	free(param);
	return ret;
}