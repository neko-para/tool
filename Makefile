ARCH=x86
CROSS=
PREFIX=/usr/local

ifeq ($(ARCH), x64)
FLAG=-m64
else ifeq ($(ARCH), x86)
FLAG=-m32
endif

all: libcallf.$(ARCH).a

help:
	@echo "Use ARCH to specify arch(x86,x64). default to x86"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Use CC, AR to specify compiler."
	@echo "Now intel is not support."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall specify arch target."
	@echo "make uninstallall to uninstall all arch target."

clean:
	for i in x86 x64; do \
		if [ -e callf.$$i.o ]; then rm callf.$$i.o; fi; \
		if [ -e asm.$$i.o ]; then rm asm.$$i.o; fi; \
		if [ -e libcallf.$$i.a ]; then rm libcallf.$$i.a; fi \
	done
	make -C test clean

rebuild: clean all

test: libcallf.$(ARCH).a
	make -C test ARCH=$(ARCH) CROSS=$(CROSS) CC=$(CC)

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install callf.h $(PREFIX)/include/callf.h
	install libcallf.$(ARCH).a $(PREFIX)/lib/libcallf.$(ARCH).a
	if [ -e $(PREFIX)/lib/libcallf.a ]; then rm $(PREFIX)/lib/libcallf.a; fi
	ln -s $(PREFIX)/lib/libcallf.$(ARCH).a $(PREFIX)/lib/libcallf.a

uninstall:
	-rm $(PREFIX)/include/callf.h
	-rm $(PREFIX)/lib/libcallf.$(ARCH).a
	-rm $(PREFIX)/lib/libcallf.a

uninstallall:
	-rm $(PREFIX)/include/callf.h
	-rm $(PREFIX)/lib/libcallf.a
	for i in x86 x64; do \
			if [ -e $(PREFIX)/lib/libcallf.$$i.a ]; then rm $(PREFIX)/lib/libcallf.$$i.a; fi; \
		done \
	done

.PHONY: all clean help rebuild test install uninstall uninstallall

callf.$(ARCH).o: callf.c callf.h
	$(CROSS)$(CC) -c callf.c -o callf.$(ARCH).o $(FLAG)

asm.$(ARCH).o: asm.$(ARCH).c asm.h
	$(CROSS)$(CC) -c asm.$(ARCH).c -o asm.$(ARCH).o $(FLAG)

libcallf.$(ARCH).a: callf.$(ARCH).o asm.$(ARCH).o
	$(CROSS)$(AR) r libcallf.$(ARCH).a callf.$(ARCH).o asm.$(ARCH).o
