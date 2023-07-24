#include "main.h"

/**
 * getFlags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @x: take a parameter.
 * Return: flgs:
 */
int getFlags(const char *format, int *x)
{

	int index, curr_index;
	int flgs = 0;
	const char FLAGS_USED[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {FLAG_MINUS, FLAG_PLUS,
		FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

	for (curr_index = *x + 1; format[curr_index] != '\0'; curr_index++)
	{
		for (index = 0; FLAGS_USED[index] != '\0'; index++)
			if (format[curr_index] == FLAGS_USED[index])
			{
				flgs |= FLAGS_ARRAY[index];
				break;
			}

		if (FLAGS_USED[index] == 0)
			break;
	}

	*x = curr_index - 1;

	return (flgs);
}
