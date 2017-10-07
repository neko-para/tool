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

all: asmtest.$(VER)

asmtest.$(VER): libasmcall.$(VER).a asmtest.c
	gcc asmtest.c -o asmtest.$(VER) $(FLAG) $(MACRO) libasmcall.$(VER).a

libasmcall.$(VER).a: asmcall.$(VER).c asmcall.h
	gcc -c asmcall.$(VER).c -o asmcall.$(VER).o $(FLAG)
	ar r libasmcall.$(VER).a asmcall.$(VER).o
