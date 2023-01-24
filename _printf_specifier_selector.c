#include "main.h"

/**
 * _printf_selector - selects the write function to call
 * for printing based on a specifier
 * @specifier: string containing the specifier
 *
 * Return: function pointers taking in a va_list and
 * returning an int
 */
int (*_printf_selector(char specifier))(va_list)
{
	int j = 0;
	conversion_specifiers cp[] = {
		{"c", _putchar_char},
		{"i", _putchar_int},
		{"d", _putchar_int},
		{"u", _putchar_unsigned_int},
		{"b", _putchar_binary},
		{"o", _putchar_octal},
		{"x", _putchar_hexadecimal_lower},
		{"X", _putchar_hexadecimal_upper},
		{"s", _putchar_str},
		{"S", _putchar_string_literal},
		{"%", _putchar_percent},
		{"r", _printf_reversed},
		{"R", _printf_rot13ed},
		{"p", _printf_address},
		{NULL, NULL}
	};

	while (cp[j].specifier != NULL)
	{
		if (cp[j].specifier[0] == specifier)
			break;
		j += 1;
	}
	return (cp[j].function);
}
