#include "main.h"

/**
 * _putchar_binary - handles the 'b' specifier
 * @b: va_list to get the next item from
 *
 * Return: returnes the number of
 * charachters printed to the screen
 */
int _putchar_binary(va_list b)
{
	return (base_convertor(va_arg(b, unsigned int), 2, "01"));
}

/**
 * _putchar_octal - handles the 'o' specifier
 * @o: va_list to get the next item from
 *
 * Return: returnes the number of
 * charachters printed to the screen
 */
int _putchar_octal(va_list o)
{
	return (base_convertor(va_arg(o, unsigned int), 8, "01234567"));
}

/**
 * _putchar_hexadecimal_lower - handles the 'x' specifier
 * @x: va_list to get the next item from
 *
 * Return: returnes the number of
 * charachters printed to the screen
 */
int _putchar_hexadecimal_lower(va_list x)
{
	return (base_convertor(va_arg(x, unsigned int), 16, "0123456789abcdef"));
}

/**
 * _putchar_hexadecimal_upper - handles the 'X' specifier
 * @X: va_list to get the next item from
 *
 * Return: returnes the number of
 * charachters printed to the screen
 */
int _putchar_hexadecimal_upper(va_list X)
{
	return (base_convertor(va_arg(X, unsigned int), 16, "0123456789ABCDEF"));
}
/**
 * base_convertor - converts a number to any base and prints them
 * @n: the number
 * @base: the base to convert to
 * @numbers: the number set to use for conversion
 *
 * Return: number of charachters printed to the screen
 */
int base_convertor(unsigned long int n, unsigned int base, char numbers[])
{
	int counter = 0;

	if (n < base)
		_putchar(numbers[n]);
	else
	{
		counter += base_convertor(n / base, base, numbers);
		_putchar(numbers[n % base]);
	}
	counter += 1;
	return (counter);
}
