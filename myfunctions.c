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
/**
 * binaryPrint - Prints an unsigned number
 * @ls: List of arguments
 * @buff: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width.
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int binaryPrint(va_list ls, char buff[],
		int flgs, int width, int prec, int size)
{
	unsigned int x, y, index, sum;
	unsigned int arr[32];
	int counter;

	UNUSED(buff);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	x = va_arg(ls, unsigned int);
	y = 2147483648;
	arr[0] = x / y;
	index = 1;
	while (index < 32)
	{
		y /= 2;
		arr[index] = (x / y) % 2;
		index++;
	}
	for (index = 0, sum = 0, counter = 0; index < 32; index++)
	{
		sum += arr[index];
		if (sum || index == 31)
		{
			char res = '0' + arr[index];

			write(1, &res, 1);
			counter++;
		}
	}
	return (counter);
}


/**
 * unsigned_numb - Prints an unsigned number
 * @typs: List a of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wide: get width
 * @preci: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed.
 */
int unsigned_numb(va_list typs, char buff[],
		int flags, int wide, int preci, int siz)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(typs, unsigned long int);

	num = convert_size_unsigned(num, siz);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned(0, i, buff, flags, wide, preci, siz));
}


/**
 * octalPrinter - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wide: get width
 * @preci: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed
 */
int octalPrinter(va_list types, char buff[],
		int flags, int wide, int preci, int siz)
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
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FLAG_HASH && initialize_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsigned(0, i, buff, flags, wide, preci, siz));
}


/**
 * hex_printer - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wide: get width
 * @preci: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed
 */
int hex_printer(va_list types, char buff[],
		int flags, int wide, int preci, int siz)
{
	return (print_hexa(types, "0123456789abcdef", buff,
				flags, 'x', wide, preci, siz));
}


/**
 * hex_uppercase - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @wide: get width
 * @preci: Precision specification
 * @siz: Size specifier
 * Return: Number of chars printed
 */
int hex_uppercase(va_list types, char buff[],
		int flags, int wide, int preci, int siz)
{
	return (print_hexa(types, "0123456789ABCDEF", buff,
				flags, 'X', wide, preci, siz));
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
 * Return: Number of chars printed */
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
