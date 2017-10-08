#include "plugin.h"
#include <windows.h>

void* loadplugin(const char* name) {
	return (void*)LoadLibraryA(name);
}
void* loadfunction(void* handle, const char* name) {
	return (void*)GetProcAddress((HINSTANCE)handle, name);
}
void freeplugin(void* handle) {
	FreeLibrary((HINSTANCE)handle);
}