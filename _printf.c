#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _strrev - reverses a string
 * @str: the string to be reversed
 *
 * Return: a pointer to the reversed string
 */
char *_strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}

	return (str);
}

/**
 * _itoa - converts an integer to a string
 * @i: the integer to be converted
 * @strout: the output string
 * @base: the base to use for the conversion
 *
 * Return: a pointer to the output string
 */
char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}

	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}

	if (sign)
	{
		*str++ = '-';
	}

	*str = '\0';
	_strrev(strout);

	return (strout);
}

/**
 * _printf - prints a formatted string to stdout
 * @format: the format string
 *
 * Return: the number of characters written
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char buffer[1024] = {0}, *s = NULL, c = '\0', tmp[20];

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				c = (char)va_arg(args, int);
				buffer[j] = c;
				j++;
				break;
			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				strcpy(&buffer[j], s);
				j += strlen(s);
				break;
			case '%':
				buffer[j] = '%';
				j++;
				break;
			case 'd':
				_itoa(va_arg(args, int), tmp, 10);
				strcpy(&buffer[j], tmp);
				j += strlen(tmp);
				break;
			case 'i':
				_itoa(va_arg(args, int), tmp, 10);
				strcpy(&buffer[j], tmp);
				j += strlen(tmp);
				break;
			default:
				buffer[j] = '%';
				j++;
				buffer[j] = format[i];
				j++;
				break;
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, buffer, j);
	va_end(args);
	return (j);
}
