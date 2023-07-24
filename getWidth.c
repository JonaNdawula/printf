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
	int curr_index;
	int width = 0;

	for (curr_index = *x + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_number(format[curr_index]))
		{
			width *= 10;
			width += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			width = va_arg(ls, int);
			break;
		}
		else
		{
			break;
		}
	}

	*x = curr_index - 1;

	return (width);
}

