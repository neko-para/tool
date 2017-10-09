#include <callf.h>
#include "class.h"
#include <cstring>
#include <string>
#include <map>

using std::map;
using std::string;

struct Cls {
	void* cls;
	char* name;
	void* def_construct;
	void* copy_construct;
	void* destruct;
	Cls* extend;
};

struct Obj {
	Cls* cls;
	void* dat;
};

static map<string, Cls*> classes;

extern "C" {

	Cls* loadclass(const char* name) {
		Cls*& cls = classes[name];
		if (cls) {
			return cls;
		} else {
			cls = new Cls;
			cls->cls = loadplugin(name);
			if (!cls->cls) {
				delete cls;
				cls = 0;
				return 0;
			} else {
				cls->name = new char[strlen(name) + 1];
				strcpy(cls->name, name);
				cls->def_construct = loadfunction(cls->cls, "__def_construct");
				cls->copy_construct = loadfunction(cls->cls, "__copy_construct");
				cls->destruct = loadfunction(cls->cls, "__destruct");
				cls->extend = (Cls*)callf(loadfunction(cls->cls, "__extend"), 0);
				return cls;
			}
		}
	}
	void freeclass(Cls* cls) {
		classes.erase(cls->name);
		freeplugin(cls->cls);
		delete cls->name;
	}
	Obj* createobjectv(Cls* cls, unsigned long cnt, void** param) {
		Obj* obj = new Obj;
		obj->cls = cls;
		obj->dat = callfv(cls->def_construct, cnt, param);
		return obj;
	}
	Obj* createobjectva(Cls* cls, unsigned long cnt, va_list list) {
		Obj* obj = new Obj;
		obj->cls = cls;
		obj->dat = callfva(cls->def_construct, cnt, list);
		return obj;
	}
	Obj* createobject(Cls* cls, unsigned long cnt, ...) {
		va_list list;
		va_start(list, cnt);
		return createobjectva(cls, cnt, list);
	}
	Obj* copyobject(Obj* obj) {
		Obj* o = new Obj;
		o->cls = obj->cls;
		o->dat = callf(obj->cls->copy_construct, 1, obj);
		return o;
	}
	void destroyobject(Obj* obj) {
		callf(obj->cls->destruct, 1, obj);
		delete obj;
	}
	Cls* getclass(Obj* obj) {
		return obj->cls;
	}
	void* getdata(Obj* obj) {
		return obj->dat;
	}
	Cls* getextend(Cls* cls) {
		return cls->extend;
	}
	void* callfunctionv(Obj* obj, const char* name, unsigned cnt, void** param) {
		Cls* cls = obj->cls;
		void* proc = 0;
		while (cls) {
			proc = loadfunction(cls->cls, name);
			if (proc) {
				break;
			}
			cls = cls->extend;
		}
		if (!proc) {
			return 0;
		}
		return callfv(proc, cnt, param);
	}
	void* callfunctionva(Obj* obj, const char* name, unsigned long cnt, va_list list) {
		Cls* cls = obj->cls;
		void* proc = 0;
		while (cls) {
			proc = loadfunction(cls->cls, name);
			if (proc) {
				break;
			}
			cls = cls->extend;
		}
		if (!proc) {
			return 0;
		}
		return callfva(proc, cnt, list);
	}
	void* callfunction(Obj* obj, const char* name, unsigned long cnt, ...) {
		va_list list;
		va_start(list, cnt);
		return callfunctionva(obj, name, cnt, list);
	}

}