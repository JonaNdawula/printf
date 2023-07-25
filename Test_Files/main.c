#include <limits.h>
#include "main.h"
/**
 *main - test task 0
 *
 * Return: 0
 */

int main(void)
{

	char *str;
	unsigned int ui;
	void *addr;

	str = "This is our string";
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;

	_printf("%c\n", 'l');
	printf("%c\n", 'l');
	_printf("%s\n", str);
	printf("%s\n", str);
	_printf("%%\n");
	printf("%%\n");
	_printf(" Character: %c, String: %s, Percentage: %%", 'X', "Test");
	printf("\n");
	printf(" Character: %c, String: %s, Percentage: %%", 'X', "Test");
	printf("\n");
	_printf("%b\n", 98);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("%S\n", "Best\nSchool");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	printf("Testing _printf with custom conversion specifier 'R':\n");
	_printf("ROT13'ed String: %R\n", str);
	    
	return (0);

}
