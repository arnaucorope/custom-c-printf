# *This project has been created as part of the 42 curriculum by acoromin.*

## Description

`ft_printf` is a custom implementation of the standard C `printf` function.

The goal of this project is to reproduce the core behavior of `printf` while learning how to work with variadic functions, format parsing, low-level output and number formatting.

The project builds a static library named:

```bash
libftprintf.a
```

The mandatory part supports the required conversions:

| Specifier   | Description              |
| ----------- | ------------------------ |
| `%c`        | Character                |
| `%s`        | String                   |
| `%p`        | Pointer address          |
| `%d` / `%i` | Signed decimal integer   |
| `%u`        | Unsigned decimal integer |
| `%x`        | Hexadecimal lowercase    |
| `%X`        | Hexadecimal uppercase    |
| `%%`        | Percent symbol           |

The bonus part adds support for formatting options:

| Feature | Description                                |
| ------- | ------------------------------------------ |
| `width` | Minimum field width                        |
| `-`     | Left alignment                             |
| `0`     | Zero padding when applicable               |
| `.`     | Precision                                  |
| `#`     | Alternative form for hexadecimal values    |
| `+`     | Explicit sign for signed integers          |
| space   | Leading space for positive signed integers |

The bonus implementation uses a dedicated parser and a `t_format` structure to store the detected flags, width, precision and conversion type before printing.

---

## Instructions

### Project structure

```text
.
├── includes/
│   ├── ft_printf.h
│   └── ft_printf_bonus.h
│
├── srcs/
│   ├── ft_printf.c
│   ├── ft_putchar_pf.c
│   ├── ft_putnbr_pf.c
│   └── ft_puthex_pf.c
│
├── srcs_bonus/
│   ├── ft_printf_bonus.c
│   ├── ft_parse_format_bonus.c
│   ├── ft_print_char_bonus.c
│   ├── ft_print_hex_bonus.c
│   ├── ft_print_int_bonus.c
│   ├── ft_print_percent_bonus.c
│   ├── ft_print_ptr_bonus.c
│   ├── ft_print_str_bonus.c
│   ├── ft_print_uint_bonus.c
│   ├── ft_print_utils_bonus.c
│   └── ft_utils_bonus.c
│
├── Makefile
└── README.md
```

### Mandatory compilation

To compile the mandatory version:

```bash
make
```

This creates:

```bash
libftprintf.a
```

using the mandatory sources from:

```text
srcs/
```

### Bonus compilation

To compile the bonus version:

```bash
make bonus
```

This also creates:

```bash
libftprintf.a
```

but using the bonus implementation from:

```text
srcs_bonus/
```

The bonus build reuses common helper functions from `srcs/`, such as `ft_putchar_pf`, `ft_putnbr_pf` and `ft_puthex_pf`, but it does not include the mandatory `ft_printf.c`.

Instead, the bonus build uses:

```text
srcs_bonus/ft_printf_bonus.c
```

which provides the bonus implementation of:

```c
int	ft_printf(char const *str, ...);
```

### Cleaning

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Rebuild from scratch:

```bash
make re
```

### Usage example

Create a `main.c` file:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s!\n", "world");
	ft_printf("Number: %+08d\n", 42);
	return (0);
}
```

Compile it with the library:

```bash
cc main.c -I includes -L. -lftprintf -o program
```

Run it:

```bash
./program
```

---

## Implementation Details

### Mandatory version

The mandatory version parses the format string character by character.

If a regular character is found, it is printed directly using `write`.

If a `%` is found, the next character is used to select the correct conversion function.

### Bonus version

The bonus version stores formatting information in this structure:

```c
typedef struct s_format
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	type;
}	t_format;
```

The parsing flow is:

```text
format string
    ↓
parse flags, width and precision
    ↓
store data in t_format
    ↓
dispatch by conversion type
    ↓
print with padding, precision and flags applied
```

### Formatting strategy

Signed integers follow this order:

```text
[left spaces] [sign] [zero padding] [precision zeros] [number] [right spaces]
```

Unsigned integers follow this order:

```text
[left spaces] [precision zeros] [number] [right spaces]
```

Hexadecimal values follow this order:

```text
[left spaces] [0x / 0X prefix] [zero padding] [precision zeros] [hex number] [right spaces]
```

Strings follow this order:

```text
[left spaces] [string limited by precision] [right spaces]
```

Pointers follow this order:

```text
[left spaces] [0x + address] [right spaces]
```

Null pointers are handled explicitly and printed as:

```text
(nil)
```

with width and left alignment applied when required.

### Return value

Every printing function returns the number of characters written.

This allows `ft_printf` to reproduce the expected return value behavior of the original `printf`.

---

## Design Choices

### Separate mandatory and bonus sources

The project separates mandatory and bonus sources into two folders:

```text
srcs/
srcs_bonus/
```

This keeps the mandatory implementation simple while allowing the bonus version to use a more complete parser and formatting system.

### Shared helper functions

Some helper functions are shared between mandatory and bonus builds.

For example:

```c
ft_putchar_pf
ft_putnbr_pf
ft_puthex_pf
```

These helpers are stored in `srcs/` and reused by the bonus build.

The bonus build does not include the mandatory `ft_printf.c`, because `srcs_bonus/ft_printf_bonus.c` provides its own implementation of `ft_printf`.

### No buffering

The original `printf` uses internal buffering.

This implementation does not reproduce that buffering behavior. Output is written directly using `write`, as allowed by the project subject.

---

## Edge Cases Handled

* `NULL` strings
* `NULL` pointers
* `INT_MIN`
* `UINT_MAX`
* Zero values with precision
* Hexadecimal prefix with `#`
* Width smaller or greater than the printed length
* Left alignment with `-`
* Zero padding with `0`
* Sign handling with `+` and space

---

## Resources

### Documentation

* `man 3 printf`
* `man 2 write`
* `man 3 stdarg`
* The C Programming Language — Brian Kernighan and Dennis Ritchie

### Online references

* https://en.cppreference.com
* https://man7.org/linux/man-pages/

### AI Usage

AI tools were used for:

* Clarifying concepts related to variadic functions and format parsing
* Debugging edge cases
* Reviewing Makefile structure
* Improving project organization
* Refining this README

All code was manually written, tested and reviewed.

