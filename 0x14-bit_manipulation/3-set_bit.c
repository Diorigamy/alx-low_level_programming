#include "main.h"
/**
 * set_bit -func that sets the value of a given bit to 1
 * @n: pointer to the integers
 * @index: position of the bit to set
 * Return: 1 if success, else 0
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n = ((1ul << index) | *n);
	return (1);
}
