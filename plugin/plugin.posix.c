#include "plugin.h"
#include <dlfcn.h>

void* loadplugin(const char* name) {
	return dlopen(name, RTLD_LAZY);
}
void* loadfunction(void* handle, const char* name) {
	return dlsym(handle, name);
}
void freeplugin(void* handle) {
	dlclose(handle);
}