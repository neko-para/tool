PLAT=x86
ASM=gas

VER=$(ASM).$(PLAT)

ifeq ($(PLAT), x64)
FLAG=-m64
MACRO=-D_ASM_USE_X64_
else ifeq ($(PLAT), x86)
FLAG=-m32
MACRO=-D_ASM_USE_X86_
endif

all: test.$(VER) error.$(VER)

clean:
	for j in x86 x64; do \
		if [ -e asm.$$j.o ]; then rm asm.$$j.o; fi; \
		for i in gas intel; do \
			if [ -e test.$$i.$$j ]; then rm test.$$i.$$j; fi; \
			if [ -e error.$$i.$$j ]; then rm error.$$i.$$j; fi; \
		done \
	done

../libasm.$(VER).a:
	make -C .. PLAT=$(PLAT) ASM=$(ASM)

test.$(VER): ../libasm.$(VER).a test.c
	$(CC) test.c -o test.$(VER) $(FLAG) $(MACRO) ../libasm.$(VER).a

error.$(VER): ../libasm.$(VER).a error.c
	$(CC) error.c -o error.$(VER) $(FLAG) $(MACRO) ../libasm.$(VER).a
