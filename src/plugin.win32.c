#include <callf.h>
#include <windows.h>
#include <stdlib.>
#include <string.h>

void* loadplugin(const char* name) {
	return (void*)LoadLibraryA(name);
}
void* loadfunction(void* handle, const char* name) {
#ifdef _CALLF_EXTRA_PREFIX_
	char* str = (char*)malloc(strlen(name) + 1);
	void* ret;
	strcpy(str, name);
	ret = (void*)GetProcAddress((HINSTANCE)handle, str);
	free(str);
	return ret;
#else
	return (void*)GetProcAddress((HINSTANCE)handle, name);
#endif
}
void freeplugin(void* handle) {
	FreeLibrary((HINSTANCE)handle);
}