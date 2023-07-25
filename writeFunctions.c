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
int handle_write_char(char ch, char buff[],
		int flgs, int width, int prec, int size)
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

/**
 * write_number - Prints a string
 * @negativeNumb: List of arguments
 * @index: char types.
 * @buff: Buffer array to handle print
 * @flgs:  Calculates the  active flags
 * @width: gets the width.
 * @prec: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_numb(int negativeNumb, int index, char buff[],
		int flgs, int width, int prec, int size)
{
	int length = BUFFER_SIZE - index - 1;
	char padding = ' ', extra_char = 0;

	UNUSED(size);

	if ((flgs & FLAG_ZERO) && !(flgs & FLAG_MINUS))
		padding = '0';
	if (negativeNumb)
		extra_char = '-';
	else if (flgs & FLAG_PLUS)
		extra_char = '+';
	else if (flgs & FLAG_SPACE)
		extra_char = ' ';

	return (write_num(index, buff, flgs, width, prec,
				length, padding, extra_char));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flgs: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padding: Pading char
 * @extra_char: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buff[], int flgs,
		int width, int prec, int length, int padding, char extra_char)
{
	int index, padding_start = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buff[ind] == '0' && width == 0)
		return (0);
	if (prec > 0 && prec < length)
		padding = ' ';
	while (prec > length)
		buff[--ind] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (index = 1; index < width - length + 1; index++)
			buff[index] = padding;
		buff[index] = '\0';
		if (flgs & FLAG_MINUS && padding == ' ')
		{
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[index], length) + write(1, &buff[1], index - 1));
		}
		else if (!(flgs & FLAG_MINUS) && padding == ' ')
		{
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[1], index - 1) + write(1, &buff[ind], length));
		}
		else if (!(flgs & FLAG_MINUS) && padding == '0')
		{
			if (extra_char)
				buff[--padding_start] = extra_char;
			return (write(1, &buff[padding_start], index - padding_start) +
					write(1, &buff[ind], length - (1 - padding_start)));
		}
	}
	if (extra_char)
		buff[--ind] = extra_char;
	return (write(1, &buff[ind], length));
}


/**
 * write_unsigned - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @wide: Width specifier
 * @preci: Precision specifier
 * @siz: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsigned(int is_negative, int ind,
		char buff[], int flags, int wide, int preci, int siz)
{
	int length = BUFFER_SIZE - ind - 1, i = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(siz);

	if (preci == 0 && ind == BUFFER_SIZE - 2 && buff[ind] == '0')
		return (0);

	if (preci > 0 && preci < length)
		padding = ' ';

	while (preci > length)
	{
		buff[--ind] = '0';
		length++;
	}

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		padding = '0';

	if (wide > length)
	{
		for (i = 0; i < wide - length; i++)
			buff[i] = padding;

		buff[i] = '\0';

		if (flags & FLAG_MINUS)
		{
			return (write(1, &buff[ind], length) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], length));
		}
	}

	return (write(1, &buff[ind], length));
}

/**
 * pointerWriter - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flgs: Flags specifier
 * @padding: Char representing the padding
 * @extra_char: Char representing extra char
 * @padding_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int pointerWriter(char buff[], int ind, int length,
		int width, int flgs, char padding, char extra_char, int padding_start)
{
	int index;

	if (width > length)
	{
		for (index = 3; index < width - length + 3; index++)
			buff[index] = padding;
		buff[index] = '\0';
		if (flgs & FLAG_MINUS && padding == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_char)
				buff[--ind] = extra_char;
			return (write(1, &buff[ind], length) + write(1, &buff[3], index - 3));
		}
		else if (!(flgs & FLAG_MINUS) && padding == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_char)
				buff[--ind] = extra_char;
			return (write(1, &buff[3], index - 3) + write(1, &buff[ind], length));
		}
		else if (!(flgs & FLAG_MINUS) && padding == '0')
		{
			if (extra_char)
				buff[--padding_start] = extra_char;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padding_start], index - padding_start) +
					write(1, &buff[ind], length - (1 - padding_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_char)
		buff[--ind] = extra_char;
	return (write(1, &buff[ind], BUFFER_SIZE - ind - 1));
}

