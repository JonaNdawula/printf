#include "main.h"
/**
 *main - test task 0
 *
 * Return: 0
 */

int main(void)
{

	char *str;
	int len;
        int len2;


	str = "This is our string";
	len = _printf("Let's try to printf a simple sentence.\n");
        len2 = printf("Let's try to printf a simple sentence.\n");


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
	 _printf("Negative:[%d]\n", -762534);
         printf("Negative:[%d]\n", -762534);
	 _printf("Length:[%d, %i]\n", len, len);
         printf("Length:[%d, %i]\n", len2, len2);
	
	 return (0);
}
