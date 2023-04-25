#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @prm: the parameters struct
 * @v: the argument pointer
 *
 * Return: pointer
 */
char *get_precision(char *p, params *prm, va_list v)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(v, int);
		p++;
	}
	else
	{
		while (*p >= '0' && *p <= '9')
			d = d * 10 + (*p++ - '0');
	}
	prm->prec = d;
	return (p);
}
