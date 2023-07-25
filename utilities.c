#include "main.h"
/**
 * is_number - Verifies if a char is a digit
 * @ch: Char to be evaluated
 *
 * Return: 1 if ch is a number, 0 otherwise
 */
int is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @n: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of n
 */
long int convert_size_number(long int n, int size)
{
	if (size == SIZE_LONG)
		return (n);
	else if (size == SIZE_SHORT)
		return ((short)n);

	return ((int)n);
}


