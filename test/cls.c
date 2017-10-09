#include <class.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned long dat;
} Dat;

unsigned long __def_cons_cnt() {
	return 1;
}

void* __def_construct(unsigned long num) {
	Dat* d = (Dat*)malloc(sizeof(Dat));
	d->dat = num;
	return d;
}

void* __copy_construct(Obj* obj) {
	return __def_construct(((Dat*)getdata(obj))->dat);
}

void __destruct(Obj* obj) {
	free(getdata(obj));
}

void* __extend() {
	return 0;
}

void show(Obj* self) {
	printf("%lu\n", ((Dat*)getdata(self))->dat);
}