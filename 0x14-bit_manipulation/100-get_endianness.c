#include "main.h"
/**
 * get_endianness - func that checks the endianness.
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	/*set the (LSB), 00000001(low order)*/
	unsigned int m = 1;
	char *b = (char *) &m; 
	if (*b)
	{
		return (1); 
	}
	else
	{
		return (0); 
	}
}
