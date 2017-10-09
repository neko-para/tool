include ../Makefile.conf

all: test$(BINSUF) error$(BINSUF) loadplugin$(BINSUF) loadclass$(BINSUF)

clean:
	if [ -e test$(BINSUF) ]; then rm test$(BINSUF); fi
	if [ -e error$(BINSUF) ]; then rm error$(BINSUF); fi
	if [ -e plugin$(LIBSUF) ]; then rm plugin$(LIBSUF); fi
	if [ -e loadplugin$(BINSUF) ]; then rm loadplugin$(BINSUF); fi
	if [ -e cls$(LIBSUF) ]; then rm cls$(LIBSUF); fi
	if [ -e ext$(LIBSUF) ]; then rm ext$(LIBSUF); fi
	if [ -e loadclass$(BINSUF) ]; then rm loadclass$(BINSUF); fi

test$(BINSUF): test.c
	$(CROSS)$(CXX) test.c -o test$(BINSUF) $(FLAG) -L../src -I../src -lcallf -Wl,--rpath=src

error$(BINSUF): error.c
	$(CROSS)$(CXX) error.c -o error$(BINSUF) $(FLAG) -L../src -I../src -lcallf -Wl,--rpath=src

plugin$(LIBSUF): plugin.c
	$(CROSS)$(CXX) plugin.c -o plugin$(LIBSUF) $(FLAG) -shared

loadplugin$(BINSUF): plugin$(LIBSUF) loadplugin.cpp
	$(CROSS)$(CXX) loadplugin.cpp -o loadplugin$(BINSUF) $(FLAG) -L../src -I../src -lcallf $(LINKFLAG) -Wl,--rpath=src -Wl,--rpath=test

cls$(LIBSUF): cls.c
	$(CROSS)$(CXX) cls.c -o cls$(LIBSUF) $(FLAG) -shared -L../class -I../class -lclass -Wl,--rpath=class

ext$(LIBSUF): ext.c
	$(CROSS)$(CXX) ext.c -o ext$(LIBSUF) $(FLAG) -shared -L../class -I../class -lclass -Wl,--rpath=class

loadclass$(BINSUF): cls$(LIBSUF) ext$(LIBSUF) loadclass.c
	$(CROSS)$(CXX) loadclass.c -o loadclass$(BINSUF) $(FLAG) -L../src -L../class -I../class -lcallf -lclass -Wl,--rpath=src -Wl,--rpath=class -Wl,--rpath=test
