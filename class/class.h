#ifndef _CLASS_H_
#define _CLASS_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Cls Cls;
typedef struct Obj Obj;

Cls* loadclass(const char* name);
void freeclass(Cls* cls);
Obj* createobjectv(Cls* cls, unsigned long cnt, void** param);
Obj* createobjectva(Cls* cls, unsigned long cnt, va_list list);
Obj* createobject(Cls* cls, unsigned long cnt, ...);
Obj* copyobject(Obj* obj);
void destroyobject(Obj* obj);
Cls* getclass(Obj* obj);
void* getdata(Obj* obj);
Cls* getextend(Cls* cls);
void* callfunctionv(Obj* obj, const char* name, unsigned cnt, void** param);
void* callfunctionva(Obj* obj, const char* name, unsigned long cnt, va_list list);
void* callfunction(Obj* obj, const char* name, unsigned long cnt, ...);

#ifdef __cplusplus
}
#endif

#endif