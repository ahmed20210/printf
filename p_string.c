#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * p_string - print string
 * @v: argument
 * @prm: struct
 * Return: number of chars
 */

int p_string(va_list v, params *prm)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)prm;
	switch ((int)(!str))
		case 1:
			str = "(null)";

	j = pad = _strlen(str);
	if (prm->prec < pad)
		j = pad = prm->prec;

	if (prm->minus_f)
	{
		if (prm->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < prm->width)
		sum += _putchar(pad_char);
	if (!prm->minus_f)
	{
		if (prm->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}
