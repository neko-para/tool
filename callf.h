#ifndef _CALLF_H_
#define _CALLF_H_

#ifdef __cplusplus
extern "C" {
#endif

void* callfv(void* proc, unsigned long cnt, void** params);
void* callf(void* proc, unsigned long cnt, ...);

#ifdef __cplusplus
}
#endif

#endif