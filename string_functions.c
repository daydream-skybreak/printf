#include "main.h"


/**
 * print_char - print single char
 * @ap: arg list
 * Return: number of printed char
 */

int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	if (c == '\0')
	{
		return (write(1, &c, 1));
	}
	_putchar(c);
	return (1);
}

/**
 * print_str - print string
 * @ap: arg list
 * Return: number of printed char
 */

int print_str(va_list ap)
{
	char *argument = va_arg(ap, char *);
	int sum = 0;

	if (!argument)
	{
		sum += _puts("(null)", 0);
		return (sum);
	}

	return (_puts(argument, 0));
}

/**
 * print_percent -  print percent character
 * @args: char
 * Return: percent character
 */

int print_percent(va_list args __attribute__((unused)))
{
	return (_putchar('%'));
}

