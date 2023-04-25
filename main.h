#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct specifiers_format - struct for format
 * @cf: pointer to format
 * @f: pointer to function for the format
 */ 
typedef struct specifiers_format
{
	char *cf;
	int (*f)(va_list);
} s_format;


int _printf(const char *format, ...);
int p_percentage(va_list m);
int p_char(va_list c);
int p_string(va_list s);

#endif
