#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of array
 *
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i = 1, j = 0;

	if (array == NULL || size == 0)
		return;

	while (i < size)
	{
		while (j < (size - i))
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j++;
		}
		j = 0;
		i++;
	}
}