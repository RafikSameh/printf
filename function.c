#include "main.h"
/**
 * print_char - Prints a char
 * Return: number of characters printed
 * @args: argument
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(STDOUT_FILENO, &c, 1);
	return (1);
}
/**
 * print_str - prints a string
 * @args: argument
 * Return: number of character printed
 */
int print_str(va_list args)
{
	int len;
	char *s = va_arg(args, char*);

	if (!s)
		s = "(null)";
	len = _strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}
/**
 * print_int - prints an integer.
 * @args: argument
 * Return: number of chars printed
 */

int print_int(va_list args)
{
	long int n = va_arg(args, int);
	char buffer[BUFF_SIZE];
	int i = 0, count = 0;

	if (n == 0)
		buffer[i++] = '0';

	if (n < 0)
	{
		write(STDOUT_FILENO, &"-", 1);
		n = -n;
		count++;
	}
	for (; n > 0; i++)
	{
		buffer[i] = '0' + (n % 10);
		n /= 10;

	}
	buffer[i] = '\0';
	while (i > 0)
	{
		write(STDOUT_FILENO, &buffer[--i], 1);
		count++;
	}
	return (count);
}
/**
 * print_perc - Prints a percent sign
 * @list: ignored
 * Return: Number of chars printed
 */
int print_perc(va_list list)
{
	(void)list;
	return (_putchar('%'));
}
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * Return: Numbers of char printed.
 */
int print_binary(va_list types)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
