#include "main.h"
/**
 * appendHex - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @index: Index at which to start appending.
 * @ascii: ASSCI CODE.
 * Return: Always 3
 */
int appendHex(char ascii, char buff[], int index)
{
        char map_to[] = "0123456789ABCDEF";

        if (ascii < 0)
                ascii *= -1;

        buff[index++] = '\\';
        buff[index++] = 'x';

        buff[index++] = map_to[ascii / 16];
        buff[index] = map_to[ascii % 16];

        return (3);
}

