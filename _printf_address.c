#include "main.h"

/**
 * _printf_address - handles the 'p' specifier
 * @p: the valist to get the address from
 *
 * Return: the number of charachters printed
 */
int _printf_address(va_list p)
{
	unsigned long int address = va_arg(p, unsigned long int);
	int count = 2;

	_putchar('0');
	_putchar('x');
	count += base_convertor(address, 16, "0123456789abcdef");
	return (count);
}
