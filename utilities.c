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

/**
 * convert_size_unsigned - Casts a number to the specified size
 * @num: Number to be casted
 * @siz: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsigned(unsigned long int num, int siz)
{
	if (siz == SIZE_LONG)
		return (num);
	else if (siz == SIZE_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}


/**
 * hex_append - Append ascci in hexadecimal code to buffer
 * @buff: Array of chars.
 * @i: Index at which to start appending.
 * @ascii: ASSCI CODE.
 * Return: Always 3
 */
int hex_append(char ascii, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii < 0)
		ascii *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = map_to[ascii / 16];
	buff[i] = map_to[ascii % 16];

	return (3);
}

