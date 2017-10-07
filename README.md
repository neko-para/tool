# callf

dynamic call for C.

This project just want to hide the stack and registers.
It gives an easy, dynamic way to call function, especially loaded from shared libraries.

## Warning

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