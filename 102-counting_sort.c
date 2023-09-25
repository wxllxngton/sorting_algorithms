#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
    int *output_array;
    int *counting_array;
    int max_value = 0;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array to determine the counting array size */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Create the counting array of size max_value + 1 and initialize with zeros */
    counting_array = malloc((max_value + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    for (i = 0; (int)i <= max_value; i++)
        counting_array[i] = 0;

    /* Populate the counting array by counting occurrences of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    print_array(counting_array, max_value + 1);

    /* Modify the counting array to store the correct positions of each element */
    for (i = 1; (int)i <= max_value; i++)
        counting_array[i] += counting_array[i - 1];

    /* Create a temporary output array to store the sorted elements */
    output_array = malloc(size * sizeof(int));
    if (output_array == NULL)
    {
        free(counting_array);
        return;
    }

    /* Populate the output array using the counting array */
    for (i = size - 1; i < size; i--)
    {
        output_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy the sorted output back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Free the allocated memory */
    free(output_array);
    free(counting_array);
}
