#include <unistd.h>
#include "main.h"
/**
 * _puts - send string char by char to next fun
 * @str: the string to print with newline
 *
 * Return: length
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - print the char to stdout
 * @c: char
 *
 * Return: 1 or -1
 */
int _putchar(int c)
{
	static int i;
	static char buffer[BUFSIZE];

	if (c == BUF_FLUSH || i >= BUFSIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * print_from_to - prints a range of char addresses
 * @start: start point
 * @stop: stop point
 * @except: except point
 *
 * Return: length
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}
