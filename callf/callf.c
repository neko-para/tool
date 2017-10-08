#include "callf.h"
#include <stdarg.h>
#include <stdlib.h>

void* callfva(void* proc, unsigned long cnt, va_list list) {
	void** param;
	void* ret;
	unsigned long i;
	param = (void**)calloc(cnt, sizeof(void*));
	for (i = 0; i < cnt; ++i) {
		param[i] = va_arg(list, void*);
	}
	va_end(list);
	ret = callfv(proc, cnt, param);
	free(param);
	return ret;
}

void* callf(void* proc, unsigned long cnt, ...) {
	va_list list;
	va_start(list, cnt);
	return callfva(proc, cnt, list);
}