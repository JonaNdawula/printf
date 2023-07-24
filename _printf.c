#include "main.h"
/**
 *_printf - a function that produces output according to a format.
 *@format: it is a character string
 *
 *Return: count
 */
int _printf(const char *format, ...)
{
	int index = 0, print = 0,  printChars = 0;
	int flgs, width, prec, sz, bufferI = 0;

	va_list ls;
	char buff[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ls, format);

	while (format && format[index] != '\0')
	{
		if (format[index] != '%')
		{
			buff[bufferI++] = format[index];

			if (bufferI == BUFFER_SIZE)
				buffPrinter(buff, &bufferI);

			printChars++;
		}
		else
		{
			buffPrinter(buff, &bufferI);
			flgs = getFlags(format, &index);
			prec = getPrecision(format, &index, ls);
			width = getWidth(format, &index, ls);
			sz = getSize(format, &index);
			++index;
			print = handlePrint(format, &index, ls, buff, flgs, width, prec, sz);
			if (print == -1)
				return (-1);
			printChars += print;
		}
		index++;
	}
	buffPrinter(buff, &bufferI);

	va_end(ls);
	return (printChars);
}

/**
 *buffPrinter - prints buffer contents
 *@buff: Array of characters
 *@buffIndex: index to add a char
 */

void buffPrinter(char buff[], int *buffIndex)
{
	if (*buffIndex > 0)
		write(1, &buff[0], *buffIndex);

	*buffIndex = 0;

}
