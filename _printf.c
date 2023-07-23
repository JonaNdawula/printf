#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 *_printf - a function that produces output according to a format.
 *@format: it is a character string
 *
 *Return: count
 */
int _printf(const char *format, ...)
{
	char *str;
	int i, count = 0;
	va_list ls;

	if (format == NULL)
		return (-1);
	va_start(ls, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[++i] != '\0')
		{
			if (format[i] == 'c')
			{
				_putchar(va_arg(ls, int));
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(ls, char *);
				count += (!str) ? write(1, "(null)", 6) : write(1, str, _strlen(str));
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i++;
			}
			else
			{
				_putchar('%');
				count++;
			}
		}
		else
			_putchar(format[i]);
		count++;
	}
	va_end(ls);
	return (count);
}
