#include "sort.h"

void merge_subarray(int *subarr, int *buffer, size_t front, size_t mid,
		size_t back);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *subarr, int *buffer, size_t front, size_t back);

/**
 * merge_subarray - A function that sorts a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarray(int *subarr, int *buffer, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buffer[k++] = subarr[i];
	for (; j < back; j++)
		buffer[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - A function that implements the merge sort
 * algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buffer, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buffer, front, mid);
		merge_sort_recursive(subarr, buffer, mid, back);
		merge_subarray(subarr, buffer, front, mid, back);
	}
}

/**
 * merge_sort - A function that sorts an array of integers in ascending.
 * order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
