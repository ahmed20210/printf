#include "main.h"

/**
 * get_spec - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */

int (*get_spec(char *s))(va_list ap, params *prm)
{
	int i = 0;
	s_format specifier[] = {
		{"c", p_char},
		{"d", p_int},
		{"i", p_int},
		{"s", p_string},
		{"%", p_percent},
		{"b", p_bin},
		{"o", p_octal},
		{"u", p_unsign},
		{"x", p_hex},
		{"X", p_HEX},
		{"p", p_address},
		{"S", p_S},
		{"r", p_rev},
		{"R", p_rot13},
		{NULL, NULL}
	};

	while (specifier[i].spec)
	{
		if (*s == specifiers[i].spec[0])
			return (specifiers[i].f);
		i++;
	}
	return (NULL);
}

/**
 * print_fun - get the fun for format and print it
 * @s: the format string
 * @ap: argument pointer
 * @prm: the parameters struct
 *
 * Return: the number of bytes printed
 */
int print_fun(char *s, va_list ap, params *prm)
{
	int (*f)(va_list, params *) = get_spec(s);

	if (f)
		return (f(ap, prm));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @prm: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params *prm)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = prm->plus_f = 1;
			break;
		case ' ':
			i = prm->space_f = 1;
			break;
		case '#':
			i = prm->hash_f = 1;
			break;
		case '-':
			i = prm->minus_f = 1;
			break;
		case '0':
			i = prm->zero_f = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @prm: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params *prm)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = prm->h_modifier = 1;
		break;
	case 'l':
		i = prm->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @prm: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params *prm, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (*s >= '0' && *s <= '9')
			d = d * 10 + (*s++ - '0');
	}
	prm->width = d;
	return (s);
}
