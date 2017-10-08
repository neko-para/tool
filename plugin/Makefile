all: libplugin.a

clean:
	if [ -e plugin.o ]; then rm plugin.o; fi;
	if [ -e libplugin.a ]; then rm libplugin.a; fi;

rebuild: clean all

install: all
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	install plugin.h $(PREFIX)/include/plugin.h
	install libplugin.a $(PREFIX)/lib/libplugin.a

uninstall:
	-rm $(PREFIX)/include/plugin.h
	-rm $(PREFIX)/lib/libplugin.a

.PHONY: all clean help rebuild install uninstall

plugin.o: plugin.$(LIB).c plugin.h
	$(CROSS)$(CC) -c plugin.$(LIB).c -o plugin.o $(FLAG) -I../callf

libplugin.a: plugin.o
	$(CROSS)$(AR) r libplugin.a plugin.o
