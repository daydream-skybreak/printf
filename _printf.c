#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * get_op - select function for conversion char
 * @c: char to check
 * Return: pointer to function
 */

int (*get_op(const char c))(va_list)
{
	int i = 0;

	flags_p fp[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"i", print_nbr},
		{"b", print_binary},
		{"d", print_nbr},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"o", print_octal},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"R", print_rot13},
		{"p", print_ptr}
	};
	while (i < 14)
	{
		if (c == fp[i].c[0])
		{
			return (fp[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * _printf - Reproduce behavior of printf function
 * @format: format string
 * Return: value of printed chars
 * OA
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = get_op(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				sum++;
				i++;
			}
			else
			{
				sum += func(ap);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			sum++;
			i++;
		}
	}
	va_end(ap);
	return (sum);
}
