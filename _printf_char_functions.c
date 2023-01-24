#include "main.h"

/**
 * _putchar_percent - handles the '%' specifier
 * @p: the va_list we will get the next item from
 *
 * Return: the number of charachters printed
 */
int _putchar_percent(va_list p)
{
	(void) p;
	_putchar('%');
	return (1);
}

/**
 * _putchar_str - handles the 's' specifier
 * @s: the va_list we will get the next item from
 *
 * Return: the number of charachters printed
 */
int _putchar_str(va_list s)
{
	va_list p;

	va_copy(p, s);
	if (va_arg(p, char *) == NULL)
		return (0);
	return (_printf(va_arg(s, char *)));
}

/**
 * _putchar_char - handles the 'c' specifier
 * @c: the va_list we will get the next item from
 *
 * Return: the number of charachters printed
 */
int _putchar_char(va_list c)
{
	_putchar((char) va_arg(c, int));
	return (1);
}

/**
 * _putchar_string_literal - handles the 'S' specifier
 * @S: the va_list we will get the next item from
 *
 * Return: the number of charachters printed
 */
int _putchar_string_literal(va_list S)
{
	int count, i = 0;
	va_list string_copy;
	char *string;

	va_copy(string_copy, S);
	string = malloc(strlen(va_arg(S, char *)) + 1);
	if (string == NULL)
	{
		free(string);
		return (0);
	}
	strcpy(string, va_arg(string_copy, char *));
	while (string[i])
	{
		if (string[i] < 32 || string[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (string[i] < 16)
				_putchar('0');
			base_convertor(string[i], 16, "0123456789ABCDEF");
			count += 4;
		}
		else
		{
			_putchar(string[i]);
			count += 1;
		}
		i += 1;
	}
	free(string);
	return (count);
}
