include ../Makefile.conf

all: test$(BINSUF) error$(BINSUF) loadplugin$(BINSUF)

clean:
	if [ -e test$(BINSUF) ]; then rm test$(BINSUF); fi
	if [ -e error$(BINSUF) ]; then rm error$(BINSUF); fi
	if [ -e plugin$(LIBSUF) ]; then rm plugin$(LIBSUF); fi
	if [ -e loadplugin$(BINSUF) ]; then rm loadplugin$(BINSUF); fi

test$(BINSUF): test.c
	$(CROSS)$(CC) test.c -o test$(BINSUF) $(FLAG) -L../src -I../src -lcallf

error$(BINSUF): error.c
	$(CROSS)$(CC) error.c -o error$(BINSUF) $(FLAG) -L../src -I../src -lcallf

plugin$(LIBSUF): plugin.c
	$(CROSS)$(CC) plugin.c -o plugin$(LIBSUF) $(FLAG) -shared

loadplugin$(BINSUF): plugin$(LIBSUF) loadplugin.cpp
	$(CROSS)$(CXX) loadplugin.cpp -o loadplugin$(BINSUF) $(FLAG) -L../src -I../src -lcallf $(LINKFLAG) -Wl,--rpath=test
