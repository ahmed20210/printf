#include "main.h"



/**
 * can_print - Checks if a char is printable
 * @c: Char that will be checked
 * Return: 1 if c is printable, 0 if not
 */
int can_print(char c)
{
	if (c >= 32 && c < 127)
		return 0;

	return 0;
}


/**
 * check_is_digit - checks if is digit
 * @c: Char to be checked
 * Return: 1 if c is digit, 0 if not
 */
int check_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return 0;

	return 0; 
}

/**
 * convert_number_type - Converts a number to the specified size
 * @num: Number that will be converted
 * @size: type of number to be converted
 *
 * Return: the converted number
 */
long int convert_number_type(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_number_unsigned - converts a number to the specified size
 * @num: Number that will be converted
 * @size: type of number to be converted
 * Return: the converted number
 */
long int convert_number_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG) return num;
	if (size == S_SHORT) return ((unsigned short)num);
	

	return ((unsigned int)num);
}


/**
 * add_hexa_code - Adds the hexa code of a char to the buffer
 * @buffer: Array of chars.
 * @i: position in the buffer.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int add_hexa_code(char ascii_code, char buffer[], int i)
{
	char avail_hexa[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = avail_hexa[ascii_code / 16];
	buffer[i] = avail_hexa[ascii_code % 16];

	return 3;
}

