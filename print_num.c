#include "main.h"

/**
 * print_nbr - print number
 * @ap: arg list
 * Return: number of printed char
 */

int print_nbr(va_list ap)
{
	return (print_number(va_arg(ap, int)));
}
/**
 * print_unsigned_number - print unsigned number
 * @n: unsigned int to print
 * Return: number of printed chars
 */

int print_unsigned_number(unsigned int n)
{
	int count = 0;
	unsigned int nb = n;

	if (nb <= 9)
	{
		_putchar(nb + '0');
		return (1);
	}
	if (nb > 9)
	{
		count = print_unsigned_number(nb / 10) + 1;
		_putchar(nb % 10 + '0');
		return (count);
	}
	return (0);
}

/**
 * print_number - display the number contained in an int
 * @n: int to print
 * Return: number of char
 */
int print_number(int n)
{
	unsigned int nb;
	int count = 0;

	nb = n;
	if (n < 0)
	{
		_putchar('-');
		count++;
		nb = -nb;
	}
	if (nb <= 9)
	{
		count += _putchar(nb + '0');
		return (count);
	}
	if (nb > 9)
	{
		count += print_number(nb / 10) + 1;
		_putchar(nb % 10 + '0');
		return (count);
	}
	return (0);
}
/**
 * _nbr_len - length of a number
 * @prmNumber: number

 * Return: length of the number
 */

int _nbr_len(int prmNumber)
{
	int cLoop = 0, number;

	if (prmNumber == 0)
		return (1);

	number = prmNumber;

	if (number < 0)
	{
		number *= -1;
		cLoop++;	/* for the sign char */
	}

	while (number)
	{
		number /= 10;
		cLoop++;
	}

	return (cLoop);
}
/**
 * print_binary - print number binary base
 * @ap: arg list
 * Return: number of printed char
 */

int print_binary(va_list ap)
{
	char *str;
	int sum = 0;
	unsigned int argument = va_arg(ap, unsigned int);

	if (!argument)
	{
		sum += _puts("0", 0);
		return (sum);
	}
	str = convert_base(argument, 2, 0);
	if (!str)
		return (0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

