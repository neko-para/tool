include ../Makefile.conf

all: libclass$(LIBSUF)

clean:
	if [ -e class.o ]; then rm class.o; fi
	if [ -e libclass$(LIBSUF) ]; then rm libclass$(LIBSUF); fi

rebuild: clean all

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/bin
	install class.h $(PREFIX)/include/class.h
	install libclass$(LIBSUF) $(PREFIX)/lib/libclass$(LIBSUF)

uninstall:
	-rm $(PREFIX)/include/class.h
	-rm $(PREFIX)/lib/libclass$(LIBSUF)

.PHONY: all clean rebuild install uninstall

libclass$(LIBSUF): class.cpp class.h
	$(CROSS)$(CXX) class.cpp -o libclass$(LIBSUF) $(FLAG) -shared -L../src -I../src -lcallf $(LINKFLAG)
