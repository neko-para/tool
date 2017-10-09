#include <class.h>

int main() {
	Cls* cls = loadclass("ext.so");
	Obj* obj = createobject(cls, 2, 233, 454);
	callfunction(obj, "show", 0);
	destroyobject(obj);
	freeclass(cls);
}