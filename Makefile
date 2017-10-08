ARCH=x86
PREFIX=/usr/local
LIB=posix
CC=gcc
AR=ar

ifeq ($(ARCH), x64)
FLAG+=-m64
else ifeq ($(ARCH), x86)
FLAG+=-m32
endif

all: callf plugin

clean:
	make -C callf clean
	make -C test clean
	make -C plugin clean

rebuild: clean all

callf:
	make -C callf ARCH=$(ARCH) CC=$(CC) AR=$(AR) CROSS=$(CROSS) FLAG=$(FLAG)

plugin:
	make -C plugin CC=$(CC) LIB=$(LIB) CROSS=$(CROSS) FLAG=$(FLAG)

test: callf plugin
	make -C test CC=$(CC) CROSS=$(CROSS) FLAG=$(FLAG)

install: callf plugin
	make -C callf install PREFIX=$(PREFIX)
	make -C plugin install PREFIX=$(PREFIX)

uninstall:
	make -C callf uninstall PREFIX=$(PREFIX)
	make -C plugin uninstall PREFIX=$(PREFIX)

help:
	@echo "Use ARCH to specify arch(x86,x64). default to x86"
	@echo "Use LIB to specify library type(posix,win32). default to posix"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Use CC, AR to specify compiler. default to gcc, ar"
	@echo "make callf to build libcallf."
	@echo "make plugin to build libplugin."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall."

.PHONY: all clean help rebuild install uninstall callf plugin test