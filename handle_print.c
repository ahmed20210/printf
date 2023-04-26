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
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		 int flags, int width, int precision, int size)
{
	int  unknown_size = 0, printed = -1;
	char c = fmt[*ind];

	if (c == 'c')
		return (print_char(list, buffer, flags, width, precision, size));
	else if (c == 's')
		return (print_string(list, buffer, flags, width, precision, size));
	else if (c == '%')
		return (print_percent(list, buffer, flags, width, precision, size));
	else if (c == 'i' || c == 'd')
		return (print_int(list, buffer, flags, width, precision, size));
	else if (c == 'b')
		return (print_binary(list, buffer, flags, width, precision, size));
	else if (c == 'u')
		return (print_unsigned(list, buffer, flags, width, precision, size));
	else if (c == 'o')
		return (print_octal(list, buffer, flags, width, precision, size));
	else if (c == 'x')
		return (print_hexadecimal(list, buffer, flags, width, precision, size));
	else if (c == 'X')
		return (print_hexa_upper(list, buffer, flags, width, precision, size));
	else if (c == 'p')
		return (print_address(list, buffer, flags, width, precision, size));
	else if (c == 'S')
		return (print_unprinted(list, buffer, flags, width, precision, size));
	else if (c == 'r')
		return (print_rev(list, buffer, flags, width, precision, size));
	else if (c == 'R')
		return (print_rot13string(list, buffer, flags, width, precision, size));
	else if (c == '\0')
		return (-1);
	else
	{
		if (fmt[*ind - 1] == ' ')
			unknown_size += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_size += write(1, "%%", 1);
		unknown_size += write(1, &fmt[*ind], 1);
	}
	return (printed);
}
