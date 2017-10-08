#ifndef _CALLF_H_
#define _CALLF_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

void* callfv(void* proc, unsigned long cnt, void** params);
void* callfva(void* proc, unsigned long cnt, va_list list);
void* callf(void* proc, unsigned long cnt, ...);

#ifdef __cplusplus
}
#endif

#endif