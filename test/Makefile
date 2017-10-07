ARCH=x86
CROSS=

ifeq ($(ARCH), x64)
FLAG=-m64
MACRO=-D_ASM_USE_X64_
else ifeq ($(ARCH), x86)
FLAG=-m32
MACRO=-D_ASM_USE_X86_
endif

all: test.$(ARCH) error.$(ARCH)

clean:
	for i in x86 x64; do \
		if [ -e test.$$i ]; then rm test.$$i; fi; \
		if [ -e error.$$i ]; then rm error.$$i; fi; \
	done

../libasm.$(ARCH).a:
	make -C .. ARCH=$(ARCH)

test.$(ARCH): ../libasm.$(ARCH).a test.c
	$(CROSS)$(CC) test.c -o test.$(ARCH) $(FLAG) $(MACRO) ../libasm.$(ARCH).a

error.$(ARCH): ../libasm.$(ARCH).a error.c
	$(CROSS)$(CC) error.c -o error.$(ARCH) $(FLAG) $(MACRO) ../libasm.$(ARCH).a
