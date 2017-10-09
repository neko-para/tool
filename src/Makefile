include ../Makefile.conf

all: libcallf$(LIBSUF)

clean:
	if [ -e callf.o ]; then rm callf.o; fi
	if [ -e asm.o ]; then rm asm.o; fi
	if [ -e plugin.o ]; then rm plugin.o; fi
	if [ -e libcallf$(LIBSUF) ]; then rm libcallf$(LIBSUF); fi

rebuild: clean all

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install callf.h $(PREFIX)/include/callf.h
	install libcallf$(LIBSUF) $(PREFIX)/lib/libcallf$(LIBSUF)

uninstall:
	-rm $(PREFIX)/include/callf.h
	-rm $(PREFIX)/lib/libcallf$(LIBSUF)

.PHONY: all clean rebuild install uninstall

callf.o: callf.c callf.h
	$(CROSS)$(CC) -c callf.c -o callf.o $(FLAG)

asm.o: asm.$(ARCH).c callf.h
	$(CROSS)$(CC) -c asm.$(ARCH).c -o asm.o $(FLAG)

plugin.o: plugin.$(LIB).c callf.h
	$(CROSS)$(CC) -c plugin.$(LIB).c -o plugin.o $(FLAG)

libcallf$(LIBSUF): callf.o asm.o plugin.o
	$(CROSS)$(CXX) callf.o asm.o plugin.o -o libcallf$(LIBSUF) -shared $(FLAG) $(LINKFLAG)
