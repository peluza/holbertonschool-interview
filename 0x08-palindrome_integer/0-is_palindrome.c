#include "palindrome.h"

/**
 * is_palindrome - unsigned integer is a palindrome.
 *
 * @n: is the number to be checked
 *
 * Return: Return 1 if n is a palindrome, and 0 otherwise
 */


int is_palindrome(unsigned long n)
{
	unsigned long numer_reverse = 0, tmp_1, tmp_2 = n;

	if (n < 10)
		return (0);

	while (tmp_2 != 0)
	{
		tmp_1 = tmp_2 % 10;
		numer_reverse = numer_reverse * 10 + tmp_1;
		tmp_2 /= 10;
	}

	if (n == numer_reverse)
		return  (1);
	else
		return (0);
}
