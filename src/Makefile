include ../Makefile.conf

all: libcallf.a

clean:
	if [ -e callf.o ]; then rm callf.o; fi
	if [ -e asm.o ]; then rm asm.o; fi
	if [ -e plugin.o ]; then rm plugin.o; fi
	if [ -e libcallf.a ]; then rm libcallf.a; fi

rebuild: clean all

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install callf.h $(PREFIX)/include/callf.h
	install libcallf.a $(PREFIX)/lib/libcallf.a

uninstall:
	-rm $(PREFIX)/include/callf.h
	-rm $(PREFIX)/lib/libcallf.a

.PHONY: all clean help rebuild install uninstall

callf.o: callf.c callf.h
	$(CROSS)$(CC) -c callf.c -o callf.o $(FLAG)

asm.o: asm.$(ARCH).c callf.h
	$(CROSS)$(CC) -c asm.$(ARCH).c -o asm.o $(FLAG)

plugin.o: plugin.$(LIB).c callf.h
	$(CROSS)$(CC) -c plugin.$(LIB).c -o plugin.o $(FLAG)

libcallf.a: callf.o asm.o plugin.o
	$(CROSS)$(AR) r libcallf.a callf.o asm.o plugin.o
