#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define BUFSIZE 1024
#define BUF_FLUSH -1
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
/**
 * struct parameters - struct for parameters
 * @unsign_f: flag for unsigned value
 * @plus_f: flag for plus
 * @space_f: flag if space is specified
 * @hash_f: flag if hashtag is specified
 * @zero_f: flag if zero is specified
 * @minus_f: flag if minus is specified
 * @width: field width specified
 * @precision: field precision specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 */
typedef struct parameters
{
	unsigned int unsign_f		: 1;
	unsigned int plus_f		: 1;
	unsigned int space_f		: 1;
	unsigned int hash_f		: 1;
	unsigned int zero_f		: 1;
	unsigned int minus_f		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params;

/**
 * struct specifiers_format - struct for format
 * @cf: pointer to format
 * @f: pointer to function for the format
 */ 
typedef struct specifiers_format
{
	char *spec;
	int (*f)(va_list, params *);
} s_format;

/* to print to stdout functions */
int _puts(char *str);
int _putchar(int c);
int print_from_to(char *start, char *stop, char *except);

/* set parameter to initial values */
void init_params(params *prm);

/* define specifiers, function, and other parameters*/
int (*get_spec(char *s))(va_list ap, params *prm);
int print_fun(char *s, va_list ap, params *prm);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params *prm);
char *get_width(char *s, params *prm, va_list ap);

/* print functions */
int p_percent(va_list m, params *prm);
int p_char(va_list ap, params *prm);
int p_string(va_list v, params *prm);
int _strlen(char *s);
int p_rev(va_list v, params *prm);

/* precision */
char *get_precision(char *p, params *prm, va_list v);

/* main function */
int _printf(const char *format, ...);

/* rot 13 */
int p_rot13(va_list v);

#endif
