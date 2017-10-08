ARCH=x86
PREFIX=/usr/local

all: callf

callf:
	make -C callf ARCH=$(ARCH) CC=$(CC) AR=$(AR) CROSS=$(CROSS)

clean:
	make -C callf clean
	make -C test clean

rebuild: clean all

test: callf
	make -C test ARCH=$(ARCH) CC=$(CC) CROSS=$(CROSS)

install: callf
	make -C callf install ARCH=$(ARCH) PREFIX=$(PREFIX)

uninstall:
	make -C callf uninstall ARCH=$(ARCH) PREFIX=$(PREFIX)

uninstallall:
	make -C callf uninstallall PREFIX=$(PREFIX)

help:
	@echo "Use ARCH to specify arch(x86,x64). default to x86"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Use CC, AR to specify compiler."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall specify arch target."
	@echo "make uninstallall to uninstall all arch target."

.PHONY: all clean help rebuild test install uninstall uninstallall callf