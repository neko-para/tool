include ../Makefile.conf

all: callf$(BINSUF)

clean:
	if [ -e callf$(BINSUF) ]; then rm callf$(BINSUF); fi;

install: all
	mkdir -p $(PREFIX)/bin
	cp callf$(BINSUF) $(PREFIX)/bin/callf$(ARCH)$(BINSUF)

uninstall:
	rm $(PREFIX)/bin/callf$(ARCH)$(BINSUF)

callf$(BINSUF): callf.c
	$(CROSS)$(CC) callf.c -o callf$(BINSUF) $(FLAG) ../callf/libcallf.a -I../callf -L../callf -I../plugin -L../plugin -lcallf -lplugin $(LINKFLAG)