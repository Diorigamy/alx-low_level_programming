#include "main.h"
/**
 * clear_bit -func that sets a given bit to zero
 * @n: pointer to the integer
 * @index: the position of the bit
 * Return: 1 if success, 0 if fail
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = ~(1ul << index);

	*n = mask & *n;
	return (1);
}
