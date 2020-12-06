#include "sort.h"

/**
 * shell_sort - Sort knuth sequence
 * @array: Array to sort
 * @size: size of the array
*/

void shell_sort(int *array, size_t size)
{
	size_t gap, hight, low;
	int valueToInsert;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	while (gap > 0)
	{
		for (hight = gap; hight < size; hight++)
		{
			valueToInsert = array[hight];
			low = hight;
			while (low > gap - 1 && array[low - gap] >= valueToInsert)
			{
				array[low] = array[low - gap];
				low = low - gap;
			}
			array[low] = valueToInsert;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
