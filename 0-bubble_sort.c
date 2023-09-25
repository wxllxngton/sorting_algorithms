#include "sort.h"

/**
 * swap - Swaps two input integer values.
 *
 * @first: Pointer to the first integer parameter.
 * @second: Pointer to the second integer parameter.
 */
void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 *
 * @array: Array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	int i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		for (j = 0; j < (int)size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
