*This project has been created as part of the 42 curriculum by ankadava.


# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C, that is,
functions that accept a variable number of arguments, and to design code that is
clean, modular and easy to extend.

The result is a static library, `libftprintf.a`, that exposes one function:

```c
int ft_printf(const char *format, ...);
```

Like the original, it writes the formatted output to standard output and returns
the number of characters printed.

### Supported conversions

| Specifier | Prints                                         |
|-----------|------------------------------------------------|
| `%c`      | a single character                             |
| `%s`      | a string (`(null)` if the pointer is `NULL`)   |
| `%p`      | a pointer in hexadecimal, prefixed with `0x` (`(nil)` for `NULL`) |
| `%d`      | a signed decimal number                        |
| `%i`      | a signed integer in base 10                    |
| `%u`      | an unsigned decimal number                     |
| `%x`      | an unsigned number in lowercase hexadecimal    |
| `%X`      | an unsigned number in uppercase hexadecimal    |
| `%%`      | a percent sign                                 |

The original `printf()` buffer management is intentionally **not** implemented,
as required by the subject. Output goes straight to `write()`.

The bonus part (flags `-0.# +` and field width) is **not** implemented.

### Project structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c               # ft_printf() and the conversion dispatcher
└── src/
    ├── ft_putchar_int.c      # prints one character, returns the count
    ├── ft_putstr_int.c       # prints a string, returns the count
    ├── ft_strlen.c           # string length
    ├── ft_putnbr_int.c       # signed numbers (%d, %i)
    ├── ft_putnbr_base_int.c  # generic unsigned number in any base
    └── ft_putptr_int.c       # pointers (%p)
```

## Instructions

### Compilation

Requirements: a C compiler (`cc`), `make` and `ar`.

```sh
make          # builds libftprintf.a at the root of the repository
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean, then rebuild
```

The code is compiled with `cc -Wall -Wextra -Werror`.

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	int	len;

	len = ft_printf("Hello %s, you are number %d (hex: %x)\n", "world", 42, 42);
	ft_printf("%d characters were printed\n", len);
	return (0);
}
```

```sh
cc main.c -I. -L. -lftprintf -o demo
./demo
```

## Algorithm and data structures

No custom data structure is needed. The design relies on three ideas.

### 1. A single pass over the format string, with a dispatcher

`ft_printf` walks the format string one character at a time. Normal characters
are written immediately. When a `%` is found, the next character is the
conversion specifier, and it is handed to a separate function
(`functionIdentifier`) that reads the matching argument with `va_arg` and calls
the right printing helper.

*Why:* separating *parsing* (the loop) from *handling* (the dispatcher) keeps
each function small and makes it easy to add a new conversion: add one branch
and one helper, without touching the loop.

### 2. The `va_list` is shared by pointer

The dispatcher receives a `va_list *` instead of a copy. The C standard says
that after a function takes a `va_list` by value and calls `va_arg` on it, the
caller's list is **indeterminate**. Passing a pointer guarantees that every
`va_arg` call, in any function, advances the same argument cursor.
`va_start` and `va_end` are called once, in `ft_printf`.

### 3. One generic routine for all number conversions

`%u`, `%x`, `%X`, `%p` and the magnitude part of `%d`/`%i` all do the same thing:
print a non-negative number in some base. `ft_putnbr_base_int` takes an
`unsigned long` and a base string (such as `"0123456789abcdef"`), and prints the
number **recursively**:

- if the number is smaller than the base, print one digit;
- otherwise print `number / base` first, then `number % base`.

*Why recursion:* digits are naturally produced from the least significant to the
most significant, but must be printed in the opposite order. The recursion
reverses them with no buffer and no `malloc`, which fits the "no buffer
management" requirement.

*Why `unsigned long`:* it is large enough to hold any `unsigned int` and any
pointer on a 64-bit system, so one function serves every conversion.

*Why a base string:* the base is the string's length, so the same code handles
base 10 and base 16, and the choice of lowercase or uppercase letters is just a
different string.

### Signed numbers

For `%d` and `%i`, `ft_putnbr_int` handles the sign first: it prints `-` for
negative values and converts the value to its unsigned magnitude *before*
negating it. Doing the negation on an unsigned value avoids the signed overflow
that would otherwise happen with `INT_MIN`. The magnitude is then passed to the
generic routine.

### Return value

Every helper returns the number of characters it printed, and `ft_printf` adds
them up. This matches the return value of the real `printf()`.


## Resources

### References

- `man 3 printf`, the behavior ft_printf must mimic
- `man 3 stdarg`, for `va_list`, `va_start`, `va_arg`, `va_copy` and `va_end`
- GeeksforGeeks – C programming concepts, variadic functions
- W3Schools – C programming fundamentals and syntax.
- The 42 subject for ft_printf (version 12.1)

### Use of AI

AI (Claude) was used as a **mentor and code reviewer**, not as a code generator.

- **Code review:** I shared my code in small parts and Claude pointed out bugs
  and edge cases (reading past the end of the format string, `INT_MIN`
  overflow, passing `va_list` by value, a missing `va_end`) and Norm issues,
  without rewriting my code. I made the fixes myself.
- **Concepts:** Claude explained how `va_list` behaves when passed between
  functions, and gave a small illustration of passing a variable by pointer.
  It also asked guiding questions about how to design one generic routine for
  all number conversions.
- **Testing ideas:** Claude suggested edge cases to compare against the real
  `printf()`.
- **Documentation:** this README was drafted with Claude's help from my code,
  and I reviewed it.

All the code in the repository was written and tested by me.