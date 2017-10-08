# callf & plugin

dynamic call for C.
load library in different platform.
command line tool to call function in library.

This project want to

* hide the stack and registers.
* hide the function about load library.

It gives an easy, dynamic way to call function, especially gotten from shared libraries and load library.

## About build

I test to build it on

* Ubuntu 16.04 64bit, x86_64-linux-gnu, gcc 5.4.0, lib posix
* Ubuntu 16.04 64bit, x86_64-pc-linux-gnu, clang 3.8.0, lib posix
* Ubuntu 16.04 64bit, i686-w64-mingw32, gcc 5.3.1, lib win32
* Ubuntu 16.04 64bit, x86_64-w64-mingw32, gcc 5.3.1, lib win32
* Darwin 16.7.0 64bit, x86_64-apple-darwin16.7.0, clang ???, lib posix
* Windows 7 32bit, i686-w64-mingw32, gcc 7.2.0 (msys2), lib win32
* Windows 7 64bit, x86_64-pc-msys, gcc 6.3.0 (msys2), lib posix

### Steps

* Start a shell.
* Move to the directory.
* Use make help to view help.
* Follow the help, edit the Makefile.conf to suit your platform.
* Use make to build.
* Use make install to install.

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