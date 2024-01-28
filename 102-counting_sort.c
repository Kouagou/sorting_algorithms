#include "sort.h"

/**
 * counting_sort - A function that sorts an array of integers in
 * ascending order using the Counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	for (max = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
