#include "main.h"

/**
 * getPrecision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @x: List of arguments to be printed.
 * @ls: list of arguments.
 *
 * Return: Precision.
 */
int getPrecision(const char *format, int *x, va_list ls)
{
	int curr_index = *x + 1;
	int prec = -1;

	if (format[curr_index] != '.')
		return (prec);

	prec = 0;

	for (curr_index += 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_number(format[curr_index]))
		{
			prec *= 10;
			prec += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			prec = va_arg(ls, int);
			break;
		}
		else
		{
			break;
		}
	}

	*x = curr_index - 1;

	return (prec);
}
