include Makefile.conf

all: src class tool

clean:
	make -C src clean
	make -C class clean
	make -C tool clean
	make -C test clean

rebuild: clean all

src:
	make -C src

class:
	make -C class

tool: src
	make -C tool

test: src class
	make -C test

install: src tool
	make -C src install
	make -C class install
	make -C tool install

uninstall:
	make -C src uninstall
	make -C class uninstall
	make -C tool uninstall

help:
	@echo "Edit Makefile.conf to config."
	@echo "Use ARCH to specify arch(x86,x64). default to x64"
	@echo "Use LIB to specify library type(posix,win32). default to posix"
	@echo "Use BINSUF to specify binary suffix(,.exe). default to "
	@echo "Use LIBSUF to specify library suffix(.so,.dll). default to .so"
	@echo "Use PREFIX to specify install prefix. default to /usr/local"
	@echo "Use CC, CXX, AR to specify compiler. default to gcc, g++, ar"
	@echo "make src to build core library."
	@echo "make class to build class library."
	@echo "make tool to build tool."
	@echo "make test to build test."
	@echo "make install to install, uninstall to uninstall."

.PHONY: all clean help rebuild install uninstall src class tool test