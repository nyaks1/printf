#include "main.h"

/**
 * _putchar_int - handles the 'i' and 'd' specifiers
 * @i: the va_list we will get the next item from
 *
 * Return: the number of charachters printed
 */
int _putchar_int(va_list i)
{
	return (_putchar_int_recursive(va_arg(i, int)));
}

/**
 * _putchar_unsigned_int - handles the 'u' specifier
 * @u: the va_list we will get the next item from
 *
 * Return: the number of charachters printed
 */
int _putchar_unsigned_int(va_list u)
{
	return (_putchar_unsigned_int_recursive(va_arg(u, unsigned int)));
}

/**
 * _putchar_int_recursive - prints an int onto the screen using _putchar
 * @n: a signed integer
 *
 * Return: the number of charachters printed
 */
int _putchar_int_recursive(int n)
{
	int counter = 0;

	if (n >= 0 && n <= 9)
		_putchar('0' + n);
	else if (n < 0)
	{
		_putchar('-');
		counter += _putchar_int_recursive(-1 * n);
	}
	else
	{
		counter += _putchar_int_recursive(n / 10);
		_putchar('0' + n % 10);
	}
	counter += 1;
	return (counter);
}

/**
 * _putchar_unsigned_int_recursive - prints an unsigned int
 * onto the screen using _putchar
 * @n: an unsigned integer
 *
 * Return: the number of charachters printed
 */
int _putchar_unsigned_int_recursive(unsigned int n)
{
	int counter = 0;

	if (n < 10)
		_putchar('0' + n);
	else
	{
		counter += _putchar_int_recursive(n / 10);
		_putchar('0' + n % 10);
	}
	counter += 1;
	return (counter);
}
