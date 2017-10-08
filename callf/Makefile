ifeq ($(ARCH), x64)
FLAG=-m64
else ifeq ($(ARCH), x86)
FLAG=-m32
endif

all: libcallf.$(ARCH).a

clean:
	for i in x86 x64; do \
		if [ -e callf.$$i.o ]; then rm callf.$$i.o; fi; \
		if [ -e asm.$$i.o ]; then rm asm.$$i.o; fi; \
		if [ -e libcallf.$$i.a ]; then rm libcallf.$$i.a; fi \
	done

rebuild: clean all

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

.PHONY: all clean help rebuild install uninstall uninstallall

callf.$(ARCH).o: callf.c callf.h
	$(CROSS)$(CC) -c callf.c -o callf.$(ARCH).o $(FLAG)

asm.$(ARCH).o: asm.$(ARCH).c callf.h
	$(CROSS)$(CC) -c asm.$(ARCH).c -o asm.$(ARCH).o $(FLAG)

libcallf.$(ARCH).a: callf.$(ARCH).o asm.$(ARCH).o
	$(CROSS)$(AR) r libcallf.$(ARCH).a callf.$(ARCH).o asm.$(ARCH).o
