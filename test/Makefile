ARCH=x86
CROSS=

ifeq ($(ARCH), x64)
FLAG=-m64
else ifeq ($(ARCH), x86)
FLAG=-m32
endif

all: test.$(ARCH) error.$(ARCH)

clean:
	for i in x86 x64; do \
		if [ -e test.$$i ]; then rm test.$$i; fi; \
		if [ -e error.$$i ]; then rm error.$$i; fi; \
	done

../libcallf.$(ARCH).a:
	make -C .. ARCH=$(ARCH)

test.$(ARCH): ../libcallf.$(ARCH).a test.c
	$(CROSS)$(CC) test.c -o test.$(ARCH) $(FLAG) ../libcallf.$(ARCH).a

error.$(ARCH): ../libcallf.$(ARCH).a error.c
	$(CROSS)$(CC) error.c -o error.$(ARCH) $(FLAG) ../libcallf.$(ARCH).a
