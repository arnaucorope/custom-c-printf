# Custom C printf

A C implementation of formatted output with variadic arguments, conversion dispatch, and optional width, precision, and flag parsing.

The project builds `libftprintf.a` and exposes:

```c
int ft_printf(char const *str, ...);
```

Output is written directly to standard output through `write()`.

## Build and use

Requires `make`, a C compiler, and the `ar` archiver on a Unix-like system.

| Command | Build |
| --- | --- |
| `make` | Core conversions |
| `make bonus` | Core conversions plus extended formatting |

Both targets produce `libftprintf.a`. Switching targets replaces the archive with the selected implementation.

For the following example, build the extended version:

```bash
make bonus
```

Save as `main.c`:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %+08d\n", 42);
    return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror main.c -I includes -L. -lftprintf -o program
./program
```

Output:

```text
Hello world!
Number: +0000042
```

Use `make clean` to remove object files, `make fclean` to also remove the archive, and `make re` to rebuild the core version.

## Supported formatting

### Conversions

Both builds support:

| Specifier | Value |
| --- | --- |
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x`, `%X` | Lowercase or uppercase hexadecimal integer |
| `%%` | Literal percent sign |

### Extended formatting

The `make bonus` build parses flags, a numeric field width, and a numeric precision before the conversion.

| Option | Behavior |
| --- | --- |
| Width | Minimum field width |
| `-` | Left alignment |
| `0` | Numeric zero padding when neither left alignment nor explicit precision applies |
| `.` | Minimum integer digits or maximum string length |
| `#` | Hexadecimal prefix for nonzero values |
| `+` | Explicit sign for signed integers |
| Space | Leading space for non-negative signed integers when `+` is absent |

Options apply according to the conversion. Characters and pointers support width and alignment; strings also support precision. `%%` prints a single percent sign.

## Implementation

### Parsing and dispatch

The core implementation scans the format string, writes ordinary characters, and dispatches the character after `%` to the corresponding conversion function. Arguments are accessed through `va_list`.

The extended implementation separates parsing from output. For each conversion, it resets a `t_format` structure and records flags, width, whether a precision was specified, the precision value, and the conversion type. A dispatcher then passes the next argument and those settings to a type-specific printer.

This keeps format parsing independent from integer, string, character, and pointer rendering.

### Padding, signs, and precision

Numeric printers calculate the digit count, any sign or prefix, precision zeros, and remaining field padding before writing.

For right-aligned numbers, space padding precedes the sign or hexadecimal prefix, while zero padding follows it. Left-aligned values receive trailing spaces. Explicit integer precision disables field-width zero padding, and zero with a precision of zero emits no digits.

Signed integer formatting converts the value to `long` before taking its magnitude. String formatting computes the visible length before applying width padding.

### Shared helpers and build separation

| Location | Responsibility |
| --- | --- |
| `includes/ft_printf.h` | Public function declaration and shared helpers |
| `includes/ft_printf_bonus.h` | Format state and extended printer declarations |
| `srcs/ft_printf.c` | Core scanner and conversion dispatch |
| `srcs/ft_putchar_pf.c`, `srcs/ft_putnbr_pf.c`, `srcs/ft_puthex_pf.c` | Shared character, string, and numeric output |
| `srcs_bonus/ft_parse_format_bonus.c` | Flags, width, and precision parsing |
| `srcs_bonus/ft_printf_bonus.c` | Extended scanner and dispatch |
| `srcs_bonus/ft_print_*.c` | Type-specific formatting and padding |

Each build includes exactly one implementation of `ft_printf`. The extended build reuses the shared helpers without linking the core entry point.

## Behavior and scope

- On successful output, the return value is the number of characters produced. A null format-string pointer returns `-1`.
- A null string is represented as `(null)`. In the extended build, an explicit string precision below six suppresses that representation.
- A null pointer is printed as `(nil)`; other pointers use hexadecimal with a `0x` prefix.
- The implementation covers the conversions listed above. Floating-point conversions, length modifiers, and dynamic `*` width or precision are not implemented.
- Output is unbuffered. The helpers do not propagate `write()` failures, so the return value is not a reliable error indicator when output fails.

## Project background

Developed by **Arnau Corominas Pérez (acoromin)** as `ft_printf`, part of the 42 curriculum.

Reference material included the manual pages for `printf`, `write`, and variadic argument handling, *The C Programming Language* by Kernighan and Ritchie, and C reference documentation.

AI tools supported concept clarification, debugging, Makefile and organization review, and documentation.
