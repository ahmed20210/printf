#include "main.h"
/**
 * p_rot13 - translates string to ROT13 and writes to stdout
 * @v: argument
 * Return: string after conversion of ROT13
 */
int p_rot13(va_list v)
{
	int i, j, count = 0;
	char *alpha, *rot13, *str;

	alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	str = va_arg(v, char *);

	while (str[i])
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alpha[j])
			{
				count += _putchar(rot13[j]);
				break;
			}
		}
		if (j == 52)
			count += _putchar(str[i]);
		i++;
	}

	return (count);
}
