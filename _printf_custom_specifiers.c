#include "main.h"

/**
 * _printf_reversed - printf the reversed string
 * @r: the va_list to get the string from
 *
 * Return: the number of charachters printed
 */
int _printf_reversed(va_list r)
{
	va_list c;
	char *string;
	int charachters;

	va_copy(c, r);
	string = malloc(strlen(va_arg(r, char *)) + 1);
	if (string == NULL)
	{
		free(string);
		return (0);
	}
	strcpy(string, va_arg(c, char *));
	charachters = _printf_reversed_recursive(string, 0);

	free(string);
	return (charachters);
}


/**
 * _printf_reversed_recursive - prints a string after reversing it
 * @string: the string to be reversed
 * @index: the index to be printed at
 *
 * Return: the number of printed charachters
 */
int _printf_reversed_recursive(char *string, unsigned int index)
{
	int counter = 0;

	if (string[index] == 0)
	{
		return (0);
	}
	else
	{
		counter += 1 + _printf_reversed_recursive(string, index + 1);
		_putchar(string[index]);
	}
	return (counter);
}

/**
 * _printf_rot13ed - prints the given string rot13'ed
 * @R: the va_list to get the string from
 *
 * Return: the number of charachters printed onto the screen
 */
int _printf_rot13ed(va_list R)
{
	int i = 0;
	va_list c;
	char *string;

	va_copy(c, R);
	string = malloc(strlen(va_arg(R, char *)) + 1);
	if (string == NULL)
	{
		free(string);
		return (0);
	}
	strcpy(string, va_arg(c, char *));

	while (string[i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			_putchar((string[i] - 97 + 13) % 26 + 97);
		else if (string[i] >= 'A' && string[i] <= 'Z')
			_putchar((string[i] - 65 + 13) % 26 + 65);
		else
			_putchar(string[i]);
		i += 1;
	}

	free(string);
	return (i);
}
