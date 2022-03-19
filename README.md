# Deadquote

A C library that prints inspiring life quotes everytime your
software crashes.

```
$ gcc -w dquote.c example.c
$ ./a.out
Segmentation fault
Remember, always be yourself ... unless you suck!
-- Joss Whedon
```

If you're compiling with, `-fsanitize=address`, do:

```
#if __SANITIZE_ADDRESS__ != 1
  register_deadquote();
#endif

```


