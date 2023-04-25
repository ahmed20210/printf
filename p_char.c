#include "main.h"

/**
 * p_char - print char
 * @ap: argument
 * @prm: struct
 * Return: number of chars
 */
int p_char(va_list ap, params *prm)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (prm->minus_f)
		sum += _putchar(ch);
	while (pad++ < prm->width)
		sum += _putchar(pad_char);
	if (!prm->minus_f)
		sum += _putchar(ch);
	return (sum);
}
