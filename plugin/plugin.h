#ifndef _PLUGIN_H_
#define _PLUGIN_H_

#include <callf.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

void* loadplugin(const char* name);
void* loadfunction(void* handle, const char* name);
void freeplugin(void* handle);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
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