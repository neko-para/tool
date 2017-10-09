#include "callf.h"
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

void* loadplugin(const char* name) {
	return dlopen(name, RTLD_LAZY);
}
void* loadfunction(void* handle, const char* name) {
#ifdef _CALLF_EXTRA_PREFIX_
	char* str = (char*)malloc(strlen(name) + 1);
	void* ret;
	strcpy(str, name);
	ret = dlsym(handle, str);
	free(str);
	return ret;
#else
	return dlsym(handle, name);
#endif
}
void freeplugin(void* handle) {
	dlclose(handle);
}