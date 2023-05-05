#include "main.h"
/**
 * get_bit - func that gets the value of a bit at a given index
 * @n: the integer 
 * @index: the index we are valueing
 * Return: value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask; /*making the index 1 and the rest of the bits 0's*/

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	mask = 1ul << index; 
	return ((n & mask) != 0);
}
