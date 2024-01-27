#include "sort.h"

/**
 * swap_ints - A function that swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - A function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = array + i;
		for (j = i + 1; j < size; j++)
			minimum = (array[j] < *minimum) ? (array + j) : minimum;

		if ((array + i) != minimum)
		{
			swap_ints(array + i, minimum);
			print_array(array, size);
		}
	}
}
