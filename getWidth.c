#include "main.h"

/**
 * getWidth - gets width for printing
 * @format: Formatted string in which to print the arguments.
 * @x: List of arguments to be printed.
 * @ls: list of arguments.
 *
 * Return: width.
 */
int getWidth(const char *format, int *x, va_list ls)
{
	int width = 0;

	(void)*x;

	if (*format == '*')
	{

		width = va_arg(ls, int);
		format++;
	}
	else
	{

		while (is_number(*format)
			width = width * 10 +  (*format - '0');
	}




		return (width);
	}

