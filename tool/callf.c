#include <callf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* help = "\
Call Function(callf).\n\
Usage: callf library function [param1 [param2 ...]]\n\
Each param has a prefix.\n\
prefix d means a singned number.\n\
prefix u means a unsingned number.\n\
prefix s means a string constant.\n\
Returned what function returned.\n\
If load library failed or get function failed, callf will return 0 and print an error message.\n";

int main(int argc, char* argv[]) {
	if (argc < 3) {
		fputs(help, stderr);
		return 0;
	} else {
		const char* lib = argv[1];
		const char* fun = argv[2];
		void* handle = loadplugin(lib);
		void* proc;
		if (!handle) {
			fprintf(stderr, "Load library %s error!\n", lib);
			return 0;
		}
		proc = loadfunction(handle, fun);
		if (!proc) {
			fprintf(stderr, "Load function %s from %s failed!\n", fun, lib);
			freeplugin(handle);
			return 0;
		}
		if (argc == 3) {
			void* ret = callfv(proc, 0, 0);
			freeplugin(handle);
			return (long)ret;
		} else {
			void* ret;
			void** var = (void**)calloc(sizeof(void*), argc - 3);
			int i;
			for (i = 3; i < argc; ++i) {
				switch (argv[i][0]) {
					case 'd':
						sscanf(argv[i] + 1, "%ld", (long*)&var[i - 3]);
						break;
					case 'u':
						sscanf(argv[i] + 1, "%lu", (unsigned long*)&var[i - 3]);
						break;
					case 's':
						var[i - 3] = (void*)(argv[i] + 1);
						break;	
				}
			}
			ret = callfv(proc, argc - 3, var);
			freeplugin(handle);
			return (long)ret;
		}
	}
}