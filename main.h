#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int print_binary(va_list ap);
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_str(va_list ap);
int print_percent(va_list ap __attribute__((unused)));
int print_nbr(va_list ap);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _nbr_len(int prmNumber);
int print_rot13(va_list ap);
int print_unsigned(va_list ap);

int _putchar(char c);
int _puts(char *str, int ascii);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *_strdup(char *str);
int convert_alpha_numeric(int nb, int upper);
char *convert_base_pointer(unsigned long p);

/**
 * struct flags_printf - struct conversion to function
 * @c: flag string
 * @f: pointer to func
 */

typedef struct flags_printf
{
	char *c;
	int (*f)(va_list);
} flags_p;
#endif
