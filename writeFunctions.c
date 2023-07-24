#include "main.h"

/**
 * handle_write_char - Prints a string
 * @ch: char types.
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags.
 * @width: get width.
 * @prec: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char ch, char buff[],int flgs, int width, int prec, int size)
{ 
	int index = 0;
	char padding = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flgs & FLAG_ZERO)
		padding = '0';

	buff[index++] = ch;
	buff[index] = '\0';

	if (width > 1)
	{
		buff[BUFFER_SIZE - 1] = '\0';
		for (index = 0; index < width - 1; index++)
			buff[BUFFER_SIZE - index - 2] = padding;

		if (flgs & FLAG_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFFER_SIZE - index - 1], width - 1));
		else
			return (write(1, &buff[BUFFER_SIZE - index - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

