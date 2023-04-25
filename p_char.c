#include "main.h"

/**
 * p_char - print char
 * @c: argument
 * Return: 1
 */

int p_char(va_list c)
{
	char x = va_arg(c, int);

	_putchar(x);
	return (1);
}
