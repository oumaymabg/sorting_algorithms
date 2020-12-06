#include "sort.h"

/**
 * quick_sort -  a function that sorts an array of integers in ascending
 * order using the Quick sort algorithm and Lomuto partion scheme
 *
 * @array: input array of integers to be sorted
 * @size: size of the integer array
 */

void quick_sort(int *array, size_t size)
{
	int lo = 0;
	int hi = size - 1;

	if (size < 2)
		return;

	quick_sorter(array, lo, hi, size);

}

/**
 * quick_sorter - recursive function to sort the list
 * @array: input array of integers to be sorted
 * @size: size of the integer array
 * @lo: lower value
 * @hi: higher value
 *
 * Return: array
 */
int quick_sorter(int *array, int lo, int hi, size_t size)
{
	int p = 0;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sorter(array, lo, p - 1, size);
		quick_sorter(array, p + 1, hi, size);
	}

	return (*array);
}

/**
 * partition - recursive function to sort the list
 * @array: input array of integers to be sorted
 * @size: size of the integer array
 * @lo: lower value
 * @hi: higher value
 *
 * Return: array
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int j = lo;
	int i = lo, tmp;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (array[j] != array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[hi] != array[i])
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}

	return (i);
}
