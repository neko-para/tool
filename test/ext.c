#include <class.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned long dat;
	unsigned long dat2;
} Dat;

void* __def_construct(unsigned long num1, unsigned long num2) {
	Dat* d = (Dat*)malloc(sizeof(Dat));
	d->dat = num1;
	d->dat2 = num2;
	return d;
}

void* __copy_construct(Obj* obj) {
	return __def_construct(((Dat*)getdata(obj))->dat, ((Dat*)getdata(obj))->dat2);
}

void __destruct(Obj* obj) {
	free(getdata(obj));
}

void* __extend() {
	return loadclass("cls.so");
}

void show(Obj* self) {
	printf("Ext:%lu\nCalling Cls:", ((Dat*)getdata(self))->dat2);
	callfunctionas(loadclass("cls.so"), self, "show", 0);
}