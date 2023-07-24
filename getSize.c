#include "main.h"

/**
 * getSize - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @x: List of arguments to be printed.
 *
 * Return: size.
 */
int getSize(const char *format, int *x)
{
	int curr_index = *x + 1;
	int sz = 0;

	if (format[curr_index] == 'l')
	{
		sz = SIZE_LONG;
	}
	else if (format[curr_index] == 'h')
	{
		sz = SIZE_SHORT;
	}

	if (sz == 0)
	{
		*x = curr_index - 1;
	}
	else
	{
		*x = curr_index;
	}

	return (sz);
}
