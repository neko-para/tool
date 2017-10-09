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
Obj* copyobject(Obj* obj);
void destroyobject(Obj* obj);
Cls* getclass(Obj* obj);
void* getdata(Obj* obj);
Cls* getextend(Cls* cls);
Obj* getobjas(Obj* obj, Cls* cls);
void* callfunctionv(Obj* obj, const char* name, unsigned long cnt, void** param);
void* callfunctionva(Obj* obj, const char* name, unsigned long cnt, va_list list);
void* callfunctionasv(Cls* cls, Obj* obj, const char* name, unsigned long cnt, void** param);
void* callfunctionasva(Cls* cls, Obj* obj, const char* name, unsigned long cnt, va_list list);
void* callstaticv(Cls* cls, const char* name, unsigned long cnt, void** param);
void* callstaticva(Cls* cls, const char* name, unsigned long cnt, va_list list);

#ifdef __cplusplus
}
#endif

#ifndef __cplusplus
#define _INLINE_ static
#else
#define _INLINE_ inline
#endif

_INLINE_ Obj* createobject(Cls* cls, unsigned long cnt, ...) {
	va_list list;
	va_start(list, cnt);
	return createobjectva(cls, cnt, list);
}
_INLINE_ void* callfunction(Obj* obj, const char* name, unsigned long cnt, ...) {
	va_list list;
	va_start(list, cnt);
	return callfunctionva(obj, name, cnt, list);
}
_INLINE_ void* callfunctionas(Cls* cls, Obj* obj, const char* name, unsigned long cnt, ...) {
	va_list list;
	va_start(list, cnt);
	return callfunctionasva(cls, obj, name, cnt, list);
}
_INLINE_ void* callstatic(Cls* cls, const char* name, unsigned long cnt, ...) {
	va_list list;
	va_start(list, cnt);
	return callstaticva(cls, name, cnt, list);
}

#undef _INLINE_

#endif