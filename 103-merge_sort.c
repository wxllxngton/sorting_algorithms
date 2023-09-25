#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: Pointer to the original array.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 *
 * Return: Nothing.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((left_size + right_size) * sizeof(int));

	if (temp == NULL)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		}
		else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		temp[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		temp[k] = right[j];
		j++;
		k++;
	}

	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);

	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		size_t left_size = mid;
		size_t right_size = size - mid;
		int *left = array;
		int *right = array + mid;

		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(array, left, left_size, right, right_size);
	}
}
