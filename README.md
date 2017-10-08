# callf & plugin

dynamic call for C.
cross platform load library.

This project want to

* hide the stack and registers.
* hide the function about load library.

It gives an easy, dynamic way to call function, especially gotten from shared libraries and load library.

## About build

I test to build it on

* Ubuntu, gcc 5.4.0
* Ubuntu, clang 3.8.0
* Ubuntu, i686-w64-mingw32-gcc 5.3.1
* Ubuntu, x86_64-w64-mingw32-gcc 5.3.1

It seems to be ok to build it on Windows msys/msys2/cygwin, gcc or clang.

### Steps

* Start a shell.
* Move to the directory.
* Use  make ARCH=___your arch___ LIB=___your library type___  to build.
* Use  make install PREFIX=___install prefix___  to install.

ARCH can be x86 or x64.

LIB can be posix or win32.

## About warning

This library doesn't support floating type.

If you really want to send float data, use float pointer instead.

## About error (Acually it works well)

In x64 mode function will pass first 6 integers parameters to register %rdi, %rsi, %rdx, %rcx, %r8, %r9 and pass others to stack.

~~In my opinion, when we using a function like printf which has variable number of parameters, like printf, the unmarked parameters will directly use stack instead of registers.~~

Gcc put parameters to registers, but in the function gcc put registers to stack.

So this problem can ignore.

But when I build it by x86_64-w64-mingw32-gcc, and then use wine to excute it, it print the undefined number.

I think the undefined behavior is caused by wine.

So I suggest not using this library with function like that.