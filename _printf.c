#include "main.h"

/**
 * _printf - prints formatted strings
 * @format: a string containing formats
 *
 * Return: int (the total number of charachters printed)
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list valist;
	int (*_printf_function)(va_list);

	va_start(valist, format);
	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			_printf_function = _printf_selector(format[i + 1]);
			if (_printf_function != NULL)
				count += _printf_function(valist);
			else
			{
				_putchar('%');
				_putchar(format[i + 1]);
				count += 2;
			}
			i += 1;
		}
		else
		{
			_putchar(format[i]);
			count += 1;
		}
		i += 1;
	}
	va_end(valist);
	return (count);
}
