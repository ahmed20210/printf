#include "main.h"

/**
 * calculate_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int calculate_width(const char *format, int *i, va_list list)
{
	int width = 0;
	char c = format[*i + 1];

	if (c == '*')
	{
		width = va_arg(list, int);
		(*i)++;
	}
	else
	{
		while (check_is_digit(c))
		{
			width = width * 10 + c - '0';
			c = format[++(*i) + 1];
		}
	}
	return (width);
}
