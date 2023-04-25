#include "main.h"
/**
 * get_fun - call functions for each format
 * @format: format
 * Return: the function or NULL
 */
int (*get_fun(const char *format))(va_list)
{
	unsigned int i = 0;
	s_format fun[] = {
		{'%', p_percentage},
		{'s', p_string},
		{'c', p_char},
		{0, NULL}
	};

	while (fun[i].cf)
	{
		if (fun[i].cf[0] == *format)
			return (fun[i].f);
		i++;
	}
	return (NULL);
}
/**
 * _printf - function to print
 * @format: format types to be printed
 * Return: length of the text
 */

int _printf(const char *format, ...)
{
	int (*p)(va_list);
	va_list v;
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(v, format);

	while (format[i++])
	{
		while (format[i] && format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			i++;
		}
		if (format[i] == '\0')
			return (count);
		p = get_fun(&format[i + 1]);
		if (p != NULL)
		{
			count += p(v);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
	}
	va_end(v);
	return (count);
}
