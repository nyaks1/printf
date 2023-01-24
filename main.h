#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);
int _printf(const char *format, ...);
int (*_printf_selector(char specifier))(va_list);

/**
 * struct specifiers - Struct specifiers and
 * their functions
 * @specifier: The operator
 * @function: The function associated
 */
typedef struct specifiers
{
	char *specifier;
	int (*function)(va_list);
} conversion_specifiers;

/* String and Charachter specifiers */
int _putchar_percent(va_list p);
int _putchar_str(va_list s);
int _putchar_char(va_list c);
int _putchar_string_literal(va_list S);

/* address specifier */
int _printf_address(va_list p);

/* Integer Specifiers */
int _putchar_int(va_list i);
int _putchar_unsigned_int(va_list u);
int _putchar_int_recursive(int n);
int _putchar_unsigned_int_recursive(unsigned int n);

/* Conversion Specifiers */
int _putchar_binary(va_list b);
int _putchar_octal(va_list o);
int _putchar_hexadecimal_upper(va_list X);
int _putchar_hexadecimal_lower(va_list x);
int base_convertor(unsigned long int n, unsigned int base, char numbers[]);

/* Custom Specifiers */
int _printf_reversed(va_list r);
int _printf_reversed_recursive(char *string, unsigned int index);
int _printf_rot13ed(va_list R);

#endif

