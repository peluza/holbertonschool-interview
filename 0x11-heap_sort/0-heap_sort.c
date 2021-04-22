#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending orde
 * @array: array
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{

	size_t i;

	if (array == NULL)
		return;

	for (i = size / 2 ; i > 0; i--)
		heap(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heap(array, i, 0, size);
	}
}

/**
 * heap - look for the longest arrangement and organize it
 * @array: array
 * @size: size of the array real
 * @i: position
 * @n: size the array
 */

void heap(int *array, int n, int i, size_t size)
{
	int Long = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;


	if (right < n && array[right] > array[Long])
		Long = right;
	if (left < n && array[left] > array[Long])
		Long = left;
	if (Long != i)
	{
		swap(&array[i], &array[Long], array, size);
		heap(array, n, Long, size);
	}
}

/**
 * swap - swap the position
 * @array: array
 * @a: first
 * @b: second
 * @n: size the array
 */

void swap(int *a, int *b, int *array, size_t n)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, n);
}
