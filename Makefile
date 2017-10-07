PLAT=x86
ASM=gas
PREFIX=/usr/local

VER=$(ASM).$(PLAT)

ifeq ($(PLAT), x64)
FLAG=-m64
MACRO=-D_ASM_USE_X64_
else ifeq ($(PLAT), x86)
FLAG=-m32
MACRO=-D_ASM_USE_X86_
endif

all: libasmcall.$(VER).a

help:
	@echo "Use PLAT to specify platform(x86,x64). default to x86"
	@echo "Use ASM to specify assembly type(gas,intel). default to gas"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Now intel is not support."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall specify platform target."
	@echo "make uninstallall to uninstall all platform target."

clean:
	for j in x86 x64; do \
		if [ -e asmcall.$$j.o ]; then \
			rm asmcall.$$j.o; \
		fi; \
		for i in gas intel; do \
			if [ -e asmtest.$$i.$$j ]; then \
				rm asmtest.$$i.$$j; \
			fi; \
			if [ -e asmcall.$$i.$$j.o ]; then \
				rm asmcall.$$i.$$j.o; \
			fi; \
			if [ -e libasmcall.$$i.$$j.a ]; then \
				rm libasmcall.$$i.$$j.a; \
			fi \
		done \
	done

rebuild: clean all

test: asmtest.$(VER)

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install asmcall.h $(PREFIX)/include/asmcall.h
	install libasmcall.$(VER).a $(PREFIX)/lib/libasmcall.$(VER).a
	if [ -e $(PREFIX)/lib/libasmcall.a ]; then rm $(PREFIX)/lib/libasmcall.a; fi
	ln -s $(PREFIX)/lib/libasmcall.$(VER).a $(PREFIX)/lib/libasmcall.a

uninstall:
	-rm $(PREFIX)/include/asmcall.h
	-rm $(PREFIX)/lib/libasmcall.$(VER).a
	-rm $(PREFIX)/lib/libasmcall.a

uninstallall:
	-rm $(PREFIX)/include/asmcall.h
	-rm $(PREFIX)/lib/libasmcall.a
	for j in x86 x64; do \
		for i in gas intel; do \
			if [ -e $(PREFIX)/lib/libasmcall.$$i.$$j.a ]; then rm $(PREFIX)/lib/libasmcall.$$i.$$j.a; fi; \
		done \
	done

asmtest.$(VER): libasmcall.$(VER).a asmtest.c
	gcc asmtest.c -o asmtest.$(VER) $(FLAG) $(MACRO) libasmcall.$(VER).a

asmcall.$(VER).o: asmcall.$(VER).c asmcall.h
	gcc -c asmcall.$(VER).c -o asmcall.$(VER).o $(FLAG)

asmcall.$(PLAT).o: asmcall.c asmcall.h
	gcc -c asmcall.c -o asmcall.$(PLAT).o $(FLAG)

libasmcall.$(VER).a: asmcall.$(VER).o asmcall.$(PLAT).o
	ar r libasmcall.$(VER).a asmcall.$(VER).o asmcall.$(PLAT).o
