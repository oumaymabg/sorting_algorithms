#include "sort.h"
void swap(int **array, int index_a, int index_b);
/**
 * selection_sort - selection sort function
 * @array: array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t low = 0, i = 0, j = 0;

	if (!array || size < 1)
		return;

	while (j < size)
	{
		i = low = j;
		while (i < size)
		{
			if (array[i] < array[low])
				low = i;
			i++;
		}
		if (j - low != 0)
		{
			swap(&array, j, low);
			print_array(array, size);
		}
		j++;
	}
}

/**
 * swap - swaps two position
 * @array: array of elements
 * @i_1: index a to swap
 * @i_2: index b to swap
 */

void swap(int **array, int i_1, int i_2)
{
	int temp;

	temp = (*array)[i_1];
	(*array)[i_1] = (*array)[i_2];
	(*array)[i_2] = temp;
}
