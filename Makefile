include Makefile.conf

all: callf plugin tool

clean:
	make -C callf clean
	make -C plugin clean
	make -C tool clean
	make -C test clean

rebuild: clean all

callf:
	make -C callf

plugin:
	make -C plugin

tool: callf plugin
	make -C tool

test: callf plugin
	make -C test

install: callf plugin
	make -C callf install
	make -C plugin install
	make -C tool install

uninstall:
	make -C callf uninstall
	make -C plugin uninstall
	make -C tool uninstall

help:
	@echo "Edit Makefile.conf to config."
	@echo "Use ARCH to specify arch(x86,x64). default to x86"
	@echo "Use LIB to specify library type(posix,win32). default to posix"
	@echo "Use BINSUF to specify binary suffix(,.exe). default to "
	@echo "Use LIBSUF to specify library suffix(.so,.dll). default to .so"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Use CC, CXX, AR to specify compiler. default to gcc, g++, ar"
	@echo "make callf to build libcallf."
	@echo "make plugin to build libplugin."
	@echo "make tool to build tool."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall."

.PHONY: all clean help rebuild install uninstall callf plugin tool test