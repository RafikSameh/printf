#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int cnt = 0;

	while (*s != '\0')
	{
		cnt++;
		s++;
	}
	return (cnt);
}
/**
 * handle_print - takes care of printing
 * @format: pointer to format string
 * @i: index of char
 * @list: arguments
 * Return: size of print or -1 if fail
 */
int handle_print(const char *format, int *i, va_list list)
{
	ff function[] = {
		{'c', print_char}, {'s', print_str},
		{'%', print_perc}, {'i', print_int},
		{'d', print_int}, {'b', print_binary}, {'\0', NULL}
	};
	int j;

	for (j = 0; j < 6; ++j)
	{
		if (function[j].c == format[*i])
			return (function[j].print(list));
	}
	return (-1);
}

