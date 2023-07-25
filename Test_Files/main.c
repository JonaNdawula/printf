#include "main.h"
/**
 *main - test task 0
 *
 * Return: 0
 */

int main(void)
{

	char *str;


	str = "This is our string";



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
	 return (0);
}
