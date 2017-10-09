#include <class.h>

int main() {
	Cls* cls = loadclass("cls.so");
	Obj* obj = createobject(cls, 1, 233);
	callfunction(obj, "show", 0);
	destroyobject(obj);
	freeclass(cls);
}