#include "main.h"
/**
* _printf - prints out string and arguments
* @format: string to print
* Return: size of string -1 if fail
*/

int _printf(const char *format, ...)
{
	int i, pc = 0, p = 0;
	va_list list;


	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			pc++;
		}
		else
		{
			i++;
			if (format[i])
				p = handle_print(format, &i, list);
			else
				p = -1;
			if (p == -1 && format[i])
			{
				print_perc(list);
				pc++;
				i--;
			}
			else if (p == -1)
				return (-1);
			else if (p != -1)
				pc += p;
		}
	}
	va_end(list);
	return (pc);
}
