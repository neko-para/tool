ARCH=x86
PREFIX=/usr/local

ifeq ($(ARCH), x64)
FLAG=-m64
MACRO=-D_ASM_USE_X64_
else ifeq ($(ARCH), x86)
FLAG=-m32
MACRO=-D_ASM_USE_X86_
endif

all: libasm.$(ARCH).a

help:
	@echo "Use ARCH to specify ARCHform(x86,x64). default to x86"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Use CC, AR to specify compiler."
	@echo "Now intel is not support."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall specify ARCHform target."
	@echo "make uninstallall to uninstall all ARCHform target."

clean:
	for i in x86 x64; do \
		if [ -e asmc.$$i.o ]; then rm asmc.$$i.o; fi; \
		if [ -e asm.$$i.o ]; then rm asm.$$i.o; fi; \
		if [ -e libasm.$$i.a ]; then rm libasm.$$i.a; fi \
	done
	make -C test clean

rebuild: clean all

test: libasm.$(ARCH).a
	make -C test ARCH=$(ARCH) CC=$(CC)

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install asm.h $(PREFIX)/include/asm.h
	install libasm.$(ARCH).a $(PREFIX)/lib/libasm.$(ARCH).a
	if [ -e $(PREFIX)/lib/libasm.a ]; then rm $(PREFIX)/lib/libasm.a; fi
	ln -s $(PREFIX)/lib/libasm.$(ARCH).a $(PREFIX)/lib/libasm.a

uninstall:
	-rm $(PREFIX)/include/asm.h
	-rm $(PREFIX)/lib/libasm.$(ARCH).a
	-rm $(PREFIX)/lib/libasm.a

uninstallall:
	-rm $(PREFIX)/include/asm.h
	-rm $(PREFIX)/lib/libasm.a
	for i in x86 x64; do \
			if [ -e $(PREFIX)/lib/libasm.$$i.a ]; then rm $(PREFIX)/lib/libasm.$$i.a; fi; \
		done \
	done

.PHONY: all clean help rebuild test install uninstall uninstallall

asmc.$(ARCH).o: asm.$(ARCH).c asm.h
	$(CC) -c asm.$(ARCH).c -o asmc.$(ARCH).o $(FLAG)

asm.$(ARCH).o: asm.c asm.h
	$(CC) -c asm.c -o asm.$(ARCH).o $(FLAG)

libasm.$(ARCH).a: asmc.$(ARCH).o asm.$(ARCH).o
	$(AR) r libasm.$(ARCH).a asmc.$(ARCH).o asm.$(ARCH).o
