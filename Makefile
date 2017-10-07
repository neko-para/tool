PLAT=x86
ASM=gas
PREFIX=/usr/local
CC=gcc
AR=ar

VER=$(ASM).$(PLAT)

ifeq ($(PLAT), x64)
FLAG=-m64
MACRO=-D_ASM_USE_X64_
else ifeq ($(PLAT), x86)
FLAG=-m32
MACRO=-D_ASM_USE_X86_
endif

all: libasm.$(VER).a

help:
	@echo "Use PLAT to specify platform(x86,x64). default to x86"
	@echo "Use ASM to specify assembly type(gas,intel). default to gas"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Use CC, AR to specify compiler. default to gcc, ar in path"
	@echo "Now intel is not support."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall specify platform target."
	@echo "make uninstallall to uninstall all platform target."

clean:
	for j in x86 x64; do \
		if [ -e asm.$$j.o ]; then \
			rm asm.$$j.o; \
		fi; \
		for i in gas intel; do \
			if [ -e asmtest.$$i.$$j ]; then \
				rm asmtest.$$i.$$j; \
			fi; \
			if [ -e asm.$$i.$$j.o ]; then \
				rm asm.$$i.$$j.o; \
			fi; \
			if [ -e libasm.$$i.$$j.a ]; then \
				rm libasm.$$i.$$j.a; \
			fi \
		done \
	done

rebuild: clean all

test: test.$(VER)

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install asm.h $(PREFIX)/include/asm.h
	install libasm.$(VER).a $(PREFIX)/lib/libasm.$(VER).a
	if [ -e $(PREFIX)/lib/libasm.a ]; then rm $(PREFIX)/lib/libasm.a; fi
	ln -s $(PREFIX)/lib/libasm.$(VER).a $(PREFIX)/lib/libasm.a

uninstall:
	-rm $(PREFIX)/include/asm.h
	-rm $(PREFIX)/lib/libasm.$(VER).a
	-rm $(PREFIX)/lib/libasm.a

uninstallall:
	-rm $(PREFIX)/include/asm.h
	-rm $(PREFIX)/lib/libasm.a
	for j in x86 x64; do \
		for i in gas intel; do \
			if [ -e $(PREFIX)/lib/libasm.$$i.$$j.a ]; then rm $(PREFIX)/lib/libasm.$$i.$$j.a; fi; \
		done \
	done

test.$(VER): libasm.$(VER).a test.c
	gcc test.c -o test.$(VER) $(FLAG) $(MACRO) libasm.$(VER).a

asm.$(VER).o: asm.$(VER).c asm.h
	$(CC) -c asm.$(VER).c -o asm.$(VER).o $(FLAG)

asm.$(PLAT).o: asm.c asm.h
	$(CC) -c asm.c -o asm.$(PLAT).o $(FLAG)

libasm.$(VER).a: asm.$(VER).o asm.$(PLAT).o
	$(AR) r libasm.$(VER).a asm.$(VER).o asm.$(PLAT).o
