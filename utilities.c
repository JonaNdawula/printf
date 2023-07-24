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


