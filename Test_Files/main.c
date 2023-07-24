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
	_pritnf("%s",NULL);
	printf("%s", NULL);
	 _printf(" Character: %c, String: %s, Percentage: %%", 'X', "Test");
	 printf("\n");
	 printf (" Character: %c, String: %s, Percentage: %%", 'X', "Test");
	return (0);
}
