#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp, swapped;

	do {
		swapped = 0; /* represents false */
		for (i = 1; i <= size - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
	} while (swapped == 1);
}
