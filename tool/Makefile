include ../Makefile.conf

all: callf$(BINSUF)

clean:
	if [ -e callf$(BINSUF) ]; then rm callf$(BINSUF); fi;

install: all
	mkdir -p $(PREFIX)/bin
	cp callf$(BINSUF) $(PREFIX)/bin/callf$(ARCH)$(BINSUF)
	ln -s $(PREFIX)/bin/callf$(ARCH)$(BINSUF) $(PREFIX)/bin/callf$(BINSUF)

uninstall:
	rm $(PREFIX)/bin/callf$(ARCH)$(BINSUF)

callf$(BINSUF): callf.c
	$(CROSS)$(CC) callf.c -o callf$(BINSUF) $(FLAG) ../src/libcallf.a -I../src -L../src -lcallf $(LINKFLAG)