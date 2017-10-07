PLAT=x64
ASM=gas

VER=$(ASM).$(PLAT)

ifeq ($(PLAT), x64)
FLAG=-m64
MACRO=-D_ASM_USE_X64_
else
FLAG=-m32
MACRO=-D_ASM_USE_X86_
endif

all: libasmcall.$(VER).a

help:
	@echo "Use PLAT to specify platform(x86,x64) and ASM to specify assembly type(gas,intel)"
	@echo "Now intel is not support."
	@echo "make test to build test."

clean:
	for j in x86 x64; do \
		if [ -e asmcall.$$j.o ]; then \
			rm asmcall.$$j.o; \
		fi; \
		for i in gas intel; do \
			if [ -e asmtest.$$i.$$j ]; then \
				rm asmtest.$$i.$$j; \
			fi; \
			if [ -e asmcall.$$i.$$j.o ]; then \
				rm asmcall.$$i.$$j.o; \
			fi; \
			if [ -e libasmcall.$$i.$$j.a ]; then \
				rm libasmcall.$$i.$$j.a; \
			fi \
		done \
	done

rebuild: clean all

test: asmtest.$(VER)

asmtest.$(VER): libasmcall.$(VER).a asmtest.c
	gcc asmtest.c -o asmtest.$(VER) $(FLAG) $(MACRO) libasmcall.$(VER).a

asmcall.$(VER).o: asmcall.$(VER).c asmcall.h
	gcc -c asmcall.$(VER).c -o asmcall.$(VER).o $(FLAG)

asmcall.$(PLAT).o: asmcall.c asmcall.h
	gcc -c asmcall.c -o asmcall.$(PLAT).o $(FLAG)

libasmcall.$(VER).a: asmcall.$(VER).o asmcall.$(PLAT).o
	ar r libasmcall.$(VER).a asmcall.$(VER).o asmcall.$(PLAT).o
