#include "search_algos.h"

/**
 * print_array - print the array
 *
 * @array: is a pointer to the first element of the array to search in
 * @first:  First element of array
 * @last: Last element of array
 * Return: Always EXIT_SUCCESS
 */
void print_array(int *array, int first, int last)
{
	int i;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%d, ", array[i]);
	printf("%d", array[i]);
	printf("\n");
}

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 *
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search
 * Return: call rescursive search funtion
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t first;
	size_t last;

	if (!array)
		return (-1);

	first = 0;
	last = size - 1;
	return (recursive_search(array, first, last, value));

}


/**
 * recursive_search - Recursive advanced binary search
 * @array:  is a pointer to the first element of the array to search in
 * @first: First element of array
 * @last: Last element of array
 * @value: is the value to search
 * Return:the index where value is located
 */
int recursive_search(int *array, size_t first, size_t last, int value)
{
	size_t half;

	if (first < last)
	{
		half = first + (last - first) / 2;
		print_array(array, (int)first, (int)last);
		if (array[half] >= value)
			return (recursive_search(array, first, half, value));
		else
			return (recursive_search(array, half + 1, last, value));
		return ((int)(half));
	}
	if (array[first] == value)
		return (first);
	print_array(array, (int)first, (int)last);
	return (-1);
}
