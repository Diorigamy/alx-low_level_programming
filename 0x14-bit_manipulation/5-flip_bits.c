#include "main.h"
/**
 * flip_bits - returns no of bits required to flip a number to another
 * @n: integer to be flipped
 * @m: integer to flip n to
 * Return: number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int store_fb = 0; /*stores count of flipped bits*/
	unsigned long int store; /*result of XOR*/

	store = n ^ m;

	while (store > 0)
	{
		if (store & 1)
		{
			store_fb++;
		}
		store >>= 1;
	}
	return (store_fb);
}
