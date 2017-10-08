all: test error

clean:
	if [ -e test ]; then rm test; fi;
	if [ -e error ]; then rm error; fi;

test: ../callf/libcallf.a test.c
	$(CROSS)$(CC) test.c -o test $(FLAG) ../callf/libcallf.a -I../callf

error: ../callf/libcallf.a error.c
	$(CROSS)$(CC) error.c -o error $(FLAG) ../callf/libcallf.a -I../callf
