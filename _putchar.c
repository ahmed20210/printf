#include <unistd.h>

/**
 * _putchar - print the char to stdout
 * @c: character c
 * Return: 1 or -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
