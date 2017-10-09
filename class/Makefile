include ../Makefile.conf

all: class$(LIBSUF)

clean:
	if [ -e class.o ]; then rm class.o; fi
	if [ -e class$(LIBSUF) ]; then rm class$(LIBSUF); fi

rebuild: clean all

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/bin
	install class.h $(PREFIX)/include/class.h
	install class$(LIBSUF) $(PREFIX)/bin/class$(LIBSUF)

uninstall:
	-rm $(PREFIX)/include/class.h
	-rm $(PREFIX)/bin/class$(LIBSUF)

.PHONY: all clean rebuild install uninstall

class$(LIBSUF): class.cpp class.h
	$(CROSS)$(CXX) class.cpp -o class$(LIBSUF) $(FLAG) -shared -L../src -I../src -lcallf $(LINKFLAG)
