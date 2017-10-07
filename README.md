# callf

dynamic call for C.

This project just want to hide the stack and registers.
It gives an easy, dynamic way to call function, especially loaded from shared libraries.

## About build

I only test to build it on Ubuntu 16.04, gcc 5.4.0, clang 3.8.0

It seems to be ok to build it on Windows msys/msys2/cygwin, gcc or clang.

* Start a shell.

* Move to the directory.

* Use  make PLAT=___your arch___  to build.

* Use  make install PLAT=___your arch___ PREFIX=___install prefix___  to install.

## About warning

This library doesn't support floating type.

If you really want to send float data, use float pointer instead.

## About error (Acually it works well)

In x64 mode function will pass first 6 integers parameters to register rdi, rsi, rdx, rcx, r8, r9 and pass others to stack.

In my opinion, when we using a function like printf which has variable number of parameters, the unmarked parameters will direct use stack but not registers.

For example, function printf.

```cpp
printf(const char* format, ...);
```

I think gcc will put 'format' to %rdi, and others to stack, so that va_arg can work.

However, when I really write a similar example error.c and compile in x64 mode, it works.

I believe it will not alwawys work.

So I suggest not using this library with function like that.