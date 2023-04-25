#include "main.h"

/**
 * _printf - function to print
 * @format: format types to be printed
 * Return: length of the text
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list v;
	char *p, *start;
	params prm = PARAMS_INIT;

	if (format == NULL)
		return (-1);
	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&prm);
		if (*p != '%')
		{
			count += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &rm))
		{
			p++;
		}
		p = get_width(p, &prm, v);
		p = get_precision(p, &prm, v);
		if (get_modifier(p, &prm))
			p++;
		if (!get_specifier(p))
			count += print_from_to(start, p,
				prm.l_modifier || prm.h_modifier ? p - 1 : 0);
		else
			count += print_fun(p, v, &prm);
	}
	_putchar(BUF_FLUSH);
	va_end(v);
	return (count);
}
