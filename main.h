#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
#define SIZE_LONG 2
#define SIZE_SHORT 1

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16
#define UNUSED(y) (void)(y)
int printString(va_list ls, char buff[], int flgs,
int width, int prec, int size);
int printPercent(va_list ls, char buff[], int flgs,
int width, int prec, int size);

int printInt(va_list ls, char buff[],
int flgs, int width, int prec, int size);

int printUnsignedInt(va_list ls, char buff[],
int flgs, int width, int prec, int size);
int write_numb(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);

int write_num(int ind, char buff[], int flgs,
int width, int prec, int length, int padding, char extra_char);

long int convert_size_number(long int n, int size);

int print_char(va_list ls, char buff[],
int flgs, int width, int prec, int size);
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *s);
void buffPrinter(char buff[], int *buffIndex);
int getFlags(const char *format, int *x);
int getWidth(const char *format, int *x, va_list ls);
int getPrecision(const char *format, int *x, va_list ls);
int getSize(const char *format, int *x);
int is_number(char ch);

int handle_write_char(char ch, char buff[],
int flgs, int width, int prec, int size);

int handlePrint(const char *fmt, int *ind, va_list list,
char buffer[], int flags, int width, int precision, int size);

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
int print_handler(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size);


#endif /*MAIN.H*/
