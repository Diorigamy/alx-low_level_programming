#include "main.h"
/**
 * binary_to_uint -func to convert binary no. to an unsigned int
 *  * @b: pointer to string that has the binary number
 * Return: 0 if NULL else 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int deci = 0; /*last added decimal no*/

	if (b == NULL)
	{
		return (0);
	}

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1') 
		{
			return (0);
		}
		else
		{
			deci = deci * 2 + (*b - '0'); /*left shift*/
			b++;
		}
	}
	return (deci);
}
