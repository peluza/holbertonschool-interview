#include "menger.h"


/**
 * menger - Draws a 2D Menger Sponge
 * @level:  is the level of the Menger Sponge to draw
 * Return: None
 */

void menger(int level)
{
	int x, y, d, dim = 1;

	if (level >= 0)
	{
		for (x = 0; x < level; x++)
		{
			dim *= 3;
		}

		for (x = 0; x < dim; x++)
		{
			for (y = 0; y < dim; y++)
			{
				for (d = dim / 3; d > 0; d /= 3)
				{
					if ((x % (d * 3)) / d == 1 && (y % (d * 3)) / d == 1)
						break;
				}
				if (d)
				{
					printf(" ");
				} else
				{
					printf("#");
				}
			}
			printf("\n");
		}
	}

}
