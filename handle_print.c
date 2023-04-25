#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 *
/**
 * get_flag - gets the flag
 * @fmt: format string
 * @ind: index of the format string
 * @flags: pointer to flags
 * Return: 1 or 0
 */

int get_flag(const char *fmt, int *ind, int *flags)
{
	*flags = 0;
	while (fmt[*ind] == ' ' || fmt[*ind] == '+' || fmt[*ind] == '-'
	       || fmt[*ind] == '#' || fmt[*ind] == '0')
	{
		if (fmt[*ind] == ' ')
			*flags |= ' ';
		else if (fmt[*ind] == '+')
			*flags |= '+';
		else if (fmt[*ind] == '-')
			*flags |= '-';
		else if (fmt[*ind] == '#')
			*flags |= '#';
		else if (fmt[*ind] == '0')
			*flags |= '0';
		*ind += 1;
	}
	return 1;
}

