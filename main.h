
#ifndef _MAIN_H
#define _MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* SPECIFIERS */
/* FLAGS  */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define 
int calculate_precision(const char *format, int *i, va_list list);
int calculate_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
in#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct type - structure for type specifier
 * @type: type specifier
 * @f: function pointer
 */
struct type
{
	char *type;
	int (*f)(va_list types, char buffer[],
		int flags, int width, int precision, int size);
};

typedef struct type type_t;

/*Function to print a character*/
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string*/
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a percent sign*/
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print an integer*/
int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a decimal*/
int print_decimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a binary*/
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print an unsigned integer*/
int print_unsgnd(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print an octal*/
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a hexadecimal*/
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int write_char(char c, char buffer[],
	int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);

int write_address(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** HELPERS ******************/
int can_print(char);

int add_hexa_code(char, char[], int);

int check_is_digit(char);

long int convert_number_type(long int num, int size);

long int convert_number_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */