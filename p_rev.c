#include "main.h"

/**
 * p_rev - prints string in reverse order
 * @v: argument to get string
 * @prm: struct
 * Return: number of chars
 */
int p_rev(va_list v, params *prm)
{
	char *str = va_arg(v, char *);
	(void)prm;
	int l, count = 0;

	if (str)
	{
		for (l = 0; *str; str++)
			l++;
		str--;
		for (; l > 0; l--, str--)
			count += _putchar(*str);
	}
	return (count);
}

