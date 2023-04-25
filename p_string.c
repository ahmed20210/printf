#include "main.h"

/**
 *  p_string - print string
 *  @s: string
 *  Return: 1
 */

int p_string(va_list s)
{
	int i = 0;
	char *st;

	st = va_arg(s, char *);
	if (st == NULL)
		st = "(null)";
	while (st[i])
	{
		_putchar(st[i]);
		i++;
	}
	return (i);
}
