#include "main.h"
/**
 * pointerPrinter - Prints the value of a pointer variable
 * @ls: List a of arguments
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @prec: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed.
 */
int pointerPrinter(va_list ls, char buff[],
		int flgs, int width, int prec, int siz)
{
	char extra_char = 0, padding = ' ';
	int ind = BUFFER_SIZE - 2, length = 2, padding_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(ls, void *);

	UNUSED(width);
	UNUSED(siz);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFFER_SIZE - 1] = '\0';
	UNUSED(prec);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buff[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flgs & FLAG_ZERO) && !(flgs & FLAG_MINUS))
		padding = '0';
	if (flgs & FLAG_PLUS)
		extra_char = '+', length++;
	else if (flgs & FLAG_SPACE)
		extra_char = ' ', length++;

	ind++;


	return (pointerWriter(buff, ind, length,
				width, flgs, padding, extra_char, padding_start));
}


/**
 * nonPrint - Prints ascii codes in hexa of non printable chars
 * @ls: Lists of arguments
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @prec: Precision specification
 * @siz: Size specifier
 * Return: number of chars printed
 */
int nonPrint(va_list ls, char buff[],
		int flgs, int width, int prec, int siz)
{
	int index = 0, x = 0;
	char *st = va_arg(ls, char *);

	UNUSED(flgs);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(siz);

	if (st == NULL)
		return (write(1, "(null)", 6));

	while (st[index] != '\0')
	{
		if (printable(st[index]))
			buff[index + x] = st[index];
		else
			x += appendHex(st[index], buff, index + x);

		index++;
	}

	buff[index + x] = '\0';

	return (write(1, buff, index + x));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_char: Calculates active flags
 * @wide: get width
 * @preci: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buff[],
		int flags, char flag_char, int wide, int preci, int siz)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int initialize_num = num;

	UNUSED(wide);

	num = convert_size_unsigned(num, siz);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FLAG_HASH && initialize_num != 0)
	{
		buff[i--] = flag_char;
		buff[i--] = '0';
	}

	i++;

	return (write_unsigned(0, i, buff, flags, wide, preci, siz));
}
/**
 * reversePr - Prints reverse string.
 * @ls: List of arguments
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @prec: Precision specification
 * @siz: Size specifier
 * Return: Numbers of chars printed
 */

int reversePr(va_list ls, char buff[],
		int flgs, int width, int prec, int siz)
{
	char *st;
	int index, count = 0;

	UNUSED(buff);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(siz);

	st = va_arg(ls, char *);

	if (st == NULL)
	{
		UNUSED(prec);

		st = ")Null(";
	}
	for (index = 0; st[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char x = st[index];

		write(1, &x, 1);
		count++;
	}
	return (count);
}



/**
 * rot13_printer - Print a string in rot13.
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wide: get width
 * @preci: Precision specification
 * @siz: Size specifier
 * Return: Numbers of chars printed
 */
int rot13_printer(va_list types, char buff[],
		int flags, int wide, int preci, int siz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(wide);
	UNUSED(preci);
	UNUSED(siz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
