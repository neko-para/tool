#ifndef _CALLF_H_
#define _CALLF_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

void* callfv(void* proc, unsigned long cnt, void** params);
void* callfva(void* proc, unsigned long cnt, va_list list);

void* loadplugin(const char* name);
void* loadfunction(void* handle, const char* name);
void freeplugin(void* handle);

#ifdef __cplusplus
}
#endif

#ifndef __cplusplus
static void* callf(void* proc, unsigned long cnt, ...) {
	va_list list;
	va_start(list, cnt);
	return callfva(proc, cnt, list);
}
#else
inline void* callf(void* proc, unsigned long cnt, ...) {
	va_list list;
	va_start(list, cnt);
	return callfva(proc, cnt, list);
}
class Plugin {
	void* handle;

	Plugin(Plugin&);
	Plugin& operator=(const Plugin&);
public:
	Plugin(const char* name) {
		handle = loadplugin(name);
	}

	~Plugin() {
		freeplugin(handle);
	}

	void* get(const char* name) const {
		return loadfunction(handle, name);
	}

	void* call(const char* name, unsigned long cnt, ...) const {
		va_list list;
		va_start(list, cnt);
		return callfva(get(name), cnt, list);
	}
};
#endif

#endif