#include <callf.h>

int main() {
	Plugin p("plugin.so");
	p.call("print", 1, 233);
}