#include "main.h"

/**
 * calculate_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int calculate_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	if (format[*i + 1] == '.')
	{
		(*i)++;

		char c = format[*i + 1];

		if (c == '*')
		{
			precision = va_arg(list, int);
			(*i)++;
		}
		else
		{
			precision = 0;
			while (check_is_digit(c))
			{
				precision = precision * 10 + c - '0';
				c = format[++(*i) + 1];
			}
		}
	}
	return (precision);
}
