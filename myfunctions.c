#include "main.h"

/**
 *printString - print a string
 *@ls: argument list
 *@buff: buffer array to print
 *@flgs: calculate flags
 *@width: get width
 *@prec: precision
 *@size: size specifier
 *Return:Number of chars printed
 *
 */
int printString(va_list ls, char buff[],
		int flgs, int width, int prec, int size)
{
	int len = 0, index;
	char *st = va_arg(ls, char *);

	UNUSED(buff);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	if (st == NULL)
	{
		st = "(null)";
		if (prec >= 6)
			st = "      ";
	}

	while (st[len] != '\0')
		len++;

	if (prec >= 0 && prec < len)
		len = prec;

	if (width > len)
	{
		if (flgs & FLAG_MINUS)
		{
			write(1, &st[0], len);
			for (index = width - len; index > 0; index--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (index = width - len; index > 0; index--)
				write(1, " ", 1);
			write(1, &st[0], len);
			return (width);
		}
	}

	return (write(1, st, len));
}


/**
 * printPercent - Prints a percent sign
 * @ls: List of arguments
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width.
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printPercent(va_list ls, char buff[], int flgs,
		int width, int prec, int size)
{
	UNUSED(ls);
	UNUSED(buff);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_char - Prints a char
 * @ls: List a of arguments
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: Width
 * @prec: Precision specification
 * @size:Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list ls, char buff[], int flgs,
		int width, int prec, int size)
{
	char ch = va_arg(ls, int);

	return (handle_write_char(ch, buff, flgs, width, prec, size));
}

/**
 * printInt - Prints an int
 * @ls: List of arguments
 * @buff: Buffer array for printing
 * @flgs:  Calculates active flags
 * @width: get width.
 * @prec: Precision
 * @size: Size specifier
 * Return: output
 */

int printInt(va_list ls, char buff[], int flgs, int width, int prec, int size)
{

	int index  = BUFFER_SIZE - 2;
	int negativeNumb  = 0;
	long int n = va_arg(ls, long int);
	unsigned long int numb;

	n = convert_size_number(n, size);

	if (n == 0)
		buff[index--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsigned long int)((-1) * n);
		negativeNumb = 1;
	}

	while (numb > 0)
	{
		buff[index--] = (numb % 10) + '0';
		numb /= 10;
	}

	index++;

	return (write_numb(negativeNumb, index, buff, flgs, width, prec, size));

}

int printUnsignedInt(va_list ls, char buff[], int flgs,
int width, int prec, int size);
